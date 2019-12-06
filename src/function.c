#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"function.h"
#include <gtk/gtk.h>
#include <string.h> 

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

enum 
{
DEPART,
DESTINATION,
REFERENCE,
COMPAGNIE,
DATEDEDEPART,
HEURE,
CLASS, 
PRIX,
COLUMNS
}; 


void ajoutervol(vol v) 
{
FILE *f;

f=fopen("/home/hosni/myprojectvol/vols/src/vol.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s %s %s %d/%d/%d %s %s %s \n",v.depart,v.destination,v.ref,v.compagnie,v.j,v.m,v.y,v.heure,v.classe,v.prix);
}
fclose(f);
}

void affichervol(GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

volaff va;

store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Depart",render,"text",DEPART,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Destination",render,"text",DESTINATION,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Reference",render,"text",REFERENCE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Compagnie",render,"text",COMPAGNIE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Date",render,"text",DATEDEDEPART,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Heurededepart",render,"text",HEURE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Class",render,"text",CLASS,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Prix",render,"text",PRIX,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("/home/hosni/myprojectvol/vols/src/vol.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("/home/hosni/myprojectvol/vols/src/vol.txt","a+") ;
 while(fscanf(f,"%s %s %s %s %s %s %s %s \n" ,va.depart,va.destination,va.ref,va.compagnie,va.date,va.heure,va.classe,va.prix)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,DEPART,va.depart,DESTINATION,va.destination,REFERENCE,va.ref,COMPAGNIE,va.compagnie,DATEDEDEPART,va.date,HEURE,va.heure,CLASS,va.classe,PRIX,va.prix,-1) ; 
}
fclose(f) ; 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 
}
}
}






void supprimervol(char ref[]) 
{
FILE *f_h;
FILE *f_h1;
volaff va ;  
int r;
int n;
f_h=fopen("/home/hosni/myprojectvol/vols/src/vol.txt","r");
f_h1=fopen("/home/hosni/myprojectvol/vols/src/vol1.txt","w");
if (f_h!=NULL){
    if(f_h1!=NULL){
while(fscanf(f_h,"%s %s %s %s %s %s %s %s \n",va.depart,va.destination,va.ref,va.compagnie,va.date,va.heure,va.classe,va.prix)!=EOF ) {
    if(strcmp(ref,va.ref)!=0){
        fprintf(f_h1,"%s %s %s %s %s %s %s %s \n",va.depart,va.destination,va.ref,va.compagnie,va.date,va.heure,va.classe,va.prix);
        r=1;
    }
}
    }
    fclose(f_h1);
}

fclose(f_h);
if (r){
	remove ("/home/hosni/myprojectvol/vols/src/vol.txt");
	rename ("/home/hosni/myprojectvol/vols/src/vol1.txt","/home/hosni/myprojectvol/vols/src/vol.txt");
	}
}



void modifiervol(char ref[] ,vole vv ){
int n=0;
volaff va ;




FILE *f_h;
FILE *f_h1;
 
int r;

f_h=fopen("/home/hosni/myprojectvol/vols/src/vol.txt","r");
f_h1=fopen("/home/hosni/myprojectvol/vols/src/vol1.txt","w");
if (f_h!=NULL)
{
    if(f_h1!=NULL)
     {
while(fscanf(f_h,"%s %s %s %s %s %s %s %s \n",va.depart,va.destination,va.ref,va.compagnie,va.date,va.heure,va.classe,va.prix)!=EOF ) 
{
    if(strcmp(ref,va.ref)==0)
            {
        fprintf(f_h1,"%s %s %s %s %s %s %s %s \n",va.depart,va.destination,va.ref,va.compagnie,vv.nouveldate,vv.nheure,va.classe,vv.newprix);
            }
     else 
          {fprintf(f_h1,"%s %s %s %s %s %s %s %s \n",va.depart,va.destination,va.ref,va.compagnie,va.date,va.heure,va.classe,va.prix);} 
}
}
}
fclose(f_h1);
fclose(f_h);

	remove ("/home/hosni/myprojectvol/vols/src/vol.txt");
	rename ("/home/hosni/myprojectvol/vols/src/vol1.txt","/home/hosni/myprojectvol/vols/src/vol.txt");
	
}

