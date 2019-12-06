#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"function.h"
#include <string.h>


void
on_buttonAjoutervol_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gvol ,*ajout ;

gvol=lookup_widget(objet_graphique,"gestionvol");
ajout=create_ajoutervol();
gtk_widget_show(ajout);
gtk_widget_hide(gvol);
}

char ref[50]; 
void
on_buttonModifiervol_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gvol ,*modif ,*recherche;

recherche=lookup_widget(objet_graphique,"entryrecherchevol");

gvol=lookup_widget(objet_graphique,"gestionvol");
modif=create_Modifervol();
gtk_widget_show(modif);
gtk_widget_hide(gvol);

strcpy(ref,gtk_entry_get_text(GTK_ENTRY(recherche)));
}


void
on_buttonSupprimervol_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char ref[200];
GtkWidget *recherche ;

recherche=lookup_widget(objet_graphique,"entryrecherchevol");


strcpy(ref,gtk_entry_get_text(GTK_ENTRY(recherche)));

supprimervol(ref);
}


void
on_buttonvalider_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ; 
vol v ; 
GtkWidget *dep , *dest ,*ref ,*compagnie ,*jj ,*mm ,*yy ,*heu ,*class ,*prix  ;
GtkWidget *gvol ,*ajout ;

ajout=lookup_widget(objet_graphique,"ajoutervol");
gvol=create_gestionvol();
gtk_widget_show(gvol);
gtk_widget_hide(ajout); 

dep=lookup_widget(objet_graphique,"entrydepart"); 
dest=lookup_widget(objet_graphique,"entrydestination");
ref=lookup_widget(objet_graphique,"entryreff"); 
compagnie=lookup_widget(objet_graphique,"entrycompagnie");
jj=lookup_widget(objet_graphique,"spinbuttonj"); 
mm=lookup_widget(objet_graphique,"spinbuttonm");
yy=lookup_widget(objet_graphique,"spinbuttony"); 
heu=lookup_widget(objet_graphique,"entryheuredepart");
class=lookup_widget(objet_graphique,"comboboxclass"); 
prix=lookup_widget(objet_graphique,"entryprixvol"); 

strcpy(v.depart,gtk_entry_get_text(GTK_ENTRY(dep)));
strcpy(v.destination,gtk_entry_get_text(GTK_ENTRY(dest)));
strcpy(v.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(v.compagnie,gtk_entry_get_text(GTK_ENTRY(compagnie)));
v.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
v.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
v.y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
strcpy(v.heure,gtk_entry_get_text(GTK_ENTRY(heu)));
strcpy(v.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(class)));;
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(prix)));
ajoutervol(v) ; 
}


void
on_buttonvalidermodi_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
vole vv ;
GtkWidget *nprix ,*heure ,*date;
GtkWidget *gvol ,*modif ;

modif=lookup_widget(objet_graphique,"Modifervol");
gvol=create_gestionvol();
gtk_widget_show(gvol);
gtk_widget_hide(modif);

date=lookup_widget(objet_graphique,"entrynouveldate");
heure=lookup_widget(objet_graphique,"entrynheure");
nprix=lookup_widget(objet_graphique,"entrynprix");

strcpy(vv.nouveldate,gtk_entry_get_text(GTK_ENTRY(date)));
strcpy(vv.nheure,gtk_entry_get_text(GTK_ENTRY(heure)));
strcpy(vv.newprix,gtk_entry_get_text(GTK_ENTRY(nprix)));
modifiervol(ref,vv);
}


void
on_buttonafficher_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gvol,*treeview;

gvol=lookup_widget(objet_graphique,"gestionvol");



treeview=lookup_widget(gvol,"treeviewvol");
affichervol(treeview) ; 
}


void
on_buttonretour_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gvol ,*modif ;

modif=lookup_widget(objet_graphique,"Modifervol");
gvol=create_gestionvol();
gtk_widget_show(gvol);
gtk_widget_hide(modif);
}

