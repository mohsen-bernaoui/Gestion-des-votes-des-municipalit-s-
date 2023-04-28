#include <gtk/gtk.h>
#include <string.h>

typedef struct bureau_vote{
	char ID_bureau_vote [30];    
	char municipalite[30];
   	char ecole[30];
   	char num_salle[30];
   	char cap_bureau_vote [30];
   	char observateur[30];
}bureau_vote;

int ajout_bv(bureau_vote b_v);

int affiche_bureau(GtkWidget *liste);

int supprimer_bv(char id[]);

int vider (GtkWidget *liste);

int chercher(char id[]);

int modifier(char id[], bureau_vote nouv);
