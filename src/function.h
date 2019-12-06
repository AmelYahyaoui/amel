#include <gtk/gtk.h>

typedef struct 
{
char depart[50]; 
char destination[50]; 
char ref[50]; 
char compagnie[50]; 
int j ;
int m ;
int y; 
char heure[50]; 
char classe[50]; 
char prix[50]; 
}vol ; 

typedef struct 
{
char depart[50]; 
char destination[50]; 
char ref[50]; 
char compagnie[50]; 
char date[50]; 
char heure[50]; 
char classe[50]; 
char prix[50]; 
}volaff; 

typedef struct 
{
char nouveldate[50];
char nheure[50];
char newprix[20000] 
}vole ;
void ajoutervol(vol v); 
void affichervol(GtkTreeView *liste); 
void supprimervol(char ref[]) ;
void modifiervol(char ref[] ,vole vv ) ;


