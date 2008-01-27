/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */

/*
 *  Copyright (C) 2004-2008 Red Hat, Inc.
 *
 *  Nautilus is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of the
 *  License, or (at your option) any later version.
 *
 *  Nautilus is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Authors: Alexander Larsson <alexl@redhat.com>
 *
 */

#define FILE_SHARING_DIR "/desktop/gnome/file_sharing"
#define FILE_SHARING_ENABLED "/desktop/gnome/file_sharing/enabled"
#define FILE_SHARING_BLUETOOTH_ENABLED "/desktop/gnome/file_sharing/bluetooth_enabled"
#define FILE_SHARING_REQUIRE_PASSWORD "/desktop/gnome/file_sharing/require_password"
#define FILE_SHARING_BLUETOOTH_ALLOW_WRITE "/desktop/gnome/file_sharing/bluetooth_allow_write"

char *lookup_public_dir (void);
