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

#include <stdlib.h>
#include <string.h>
#include <grp.h>
#include <libfm/fm.h>
#include <libfm/fm-gtk.h>

FM_DEFINE_MODULE(gtk_folder_col, group)

GType get_type() { return G_TYPE_STRING; };

void get_value(FmFileInfo *fi, GValue *value){
	int gid = fm_file_info_get_gid(fi);
	struct group *group_struct = getgrgid(gid);
	if(group_struct != NULL){
		g_value_set_string( value, group_struct->gr_name );
	} else {
		GValue g_gid = G_VALUE_INIT;
		g_value_init (&g_gid, G_TYPE_INT);
		g_value_set_int( &g_gid, gid );
		g_value_transform( &g_gid, value ); 
	}
};

gint sort(FmFileInfo *fi1, FmFileInfo *fi2){
	int result;

	int gid1 = fm_file_info_get_gid( fi1 );
	struct group *group1 = getgrgid( gid1 );
	char* gid_string_1;
	if(group1 != NULL){
		gid_string_1 = malloc( strlen( group1 -> gr_name ) + 1 );
		strcpy(gid_string_1, group1->gr_name);
	} else {
		gid_string_1 = malloc( sizeof(int) * 8 + 1 );
		sprintf(gid_string_1, "%d", gid1);
	}

	int gid2 = fm_file_info_get_gid( fi2 );
	struct group *group2 = getgrgid( gid2 );
	char* gid_string_2;
	if(group2 != NULL){
		gid_string_2 = malloc( strlen( group2 -> gr_name ) + 1 );
		strcpy(gid_string_2, group2->gr_name);
	} else {
		gid_string_2 = malloc( sizeof(int) * 8 + 1 );
		sprintf(gid_string_2, "%d", gid2);
	}
	
	result = strcmp( gid_string_1, gid_string_2 );
	free( gid_string_1 );
	free( gid_string_2 );
	
	return result;
}

FmFolderModelColumnInit fm_module_init_gtk_folder_col = {
	"Group",
	0, 
	&get_type,
	&get_value,
	&sort
};
