/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2005 William Jon McCann <mccann@jhu.edu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Authors: William Jon McCann <mccann@jhu.edu>
 *
 */

#include "config.h"

#include <glib/gi18n-lib.h>
#include <gtk/gtk.h>

#include "nautilus-share-bar.h"

#define NAUTILUS_SHARE_BAR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), NAUTILUS_TYPE_SHARE_BAR, NautilusShareBarPrivate))

struct NautilusShareBarPrivate
{
        GtkWidget   *label;
};

enum {
	PROP_0,
	PROP_LABEL
};

G_DEFINE_TYPE (NautilusShareBar, nautilus_share_bar, GTK_TYPE_INFO_BAR)

static void
nautilus_share_bar_set_property (GObject            *object,
                                guint               prop_id,
                                const GValue       *value,
                                GParamSpec         *pspec)
{
        NautilusShareBar *self;

        self = NAUTILUS_SHARE_BAR (object);

        switch (prop_id) {
	case PROP_LABEL: {
		char *str;
		str = g_strdup_printf ("<i>%s</i>", g_value_get_string (value));
		gtk_label_set_markup (GTK_LABEL (self->priv->label), str);
                g_free (str);
		break;
	}
        default:
                G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
                break;
        }
}

static void
nautilus_share_bar_class_init (NautilusShareBarClass *klass)
{
        GObjectClass   *object_class = G_OBJECT_CLASS (klass);

        object_class->set_property = nautilus_share_bar_set_property;

        g_type_class_add_private (klass, sizeof (NautilusShareBarPrivate));

        g_object_class_install_property (G_OBJECT_CLASS(klass), PROP_LABEL,
                                         g_param_spec_string ("label", "label", 
                                                              "The widget's main label",
                                                              NULL, 
                                                              G_PARAM_WRITABLE));
}

static void
nautilus_share_bar_init (NautilusShareBar *bar)
{
        GtkWidget *content_area;
        GtkWidget *action_area;
	GtkWidget *label;
        GtkWidget *vbox;
        GtkWidget *image;
        GtkWidget *button;
        char      *hint;
        PangoAttrList *attrs;

        bar->priv = NAUTILUS_SHARE_BAR_GET_PRIVATE (bar);

	content_area = gtk_info_bar_get_content_area (GTK_INFO_BAR (bar));
	action_area = gtk_info_bar_get_action_area (GTK_INFO_BAR (bar));
        gtk_button_box_set_layout (GTK_BUTTON_BOX (action_area), GTK_BUTTONBOX_CENTER);

        vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 3);
        gtk_container_add (GTK_CONTAINER (content_area), vbox);

	attrs = pango_attr_list_new ();
	pango_attr_list_insert (attrs, pango_attr_weight_new (PANGO_WEIGHT_BOLD));
        label = gtk_label_new (_("Personal File Sharing"));
	gtk_label_set_attributes (GTK_LABEL (label), attrs);
	pango_attr_list_unref (attrs);

        gtk_widget_set_halign (label, GTK_ALIGN_START);
        gtk_widget_show (label);
        gtk_container_add (GTK_CONTAINER (vbox), label);

        bar->priv->label = gtk_label_new ("");
        gtk_widget_set_halign (bar->priv->label, GTK_ALIGN_START);
        hint = g_strdup_printf ("<i>%s</i>", "");
        gtk_label_set_markup (GTK_LABEL (bar->priv->label), hint);
        gtk_widget_show (bar->priv->label);
        gtk_container_add (GTK_CONTAINER (vbox), bar->priv->label);

        button = gtk_info_bar_add_button (GTK_INFO_BAR (bar),
                                          _("Launch Preferences"),
                                          NAUTILUS_SHARE_BAR_RESPONSE_PREFERENCES);

        image = gtk_image_new_from_icon_name ("folder-remote", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image);
        gtk_button_set_image (GTK_BUTTON (button), image);

        gtk_widget_set_tooltip_text (button,
                                     _("Launch Personal File Sharing Preferences"));

        gtk_widget_show_all (vbox);
}

GtkWidget *
nautilus_share_bar_new (const char *label)
{
        return g_object_new (NAUTILUS_TYPE_SHARE_BAR,
                             "message-type", GTK_MESSAGE_QUESTION,
                             "label", label,
                             NULL);
}
