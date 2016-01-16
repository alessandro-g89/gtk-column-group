/*
 * gtk-column-taglib-group.c
 *
 * Copyright (C) 2016 Alessandro Grassi <alessandro.g89@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <grp.h>
#include <libfm/fm.h>
#include <libfm/fm-gtk.h>

FM_DEFINE_MODULE(gtk_folder_col, group)

GType get_type() { return G_TYPE_STRING; };

void get_value(FmFileInfo *fi, GValue *value){
	g_value_set_string( value, getgrgid( fm_file_info_get_gid( fi ) ) -> gr_name );
};

FmFolderModelColumnInit fm_module_init_gtk_folder_col = {
	"Group",
	0, 
	&get_type,
	&get_value,
	NULL
};
