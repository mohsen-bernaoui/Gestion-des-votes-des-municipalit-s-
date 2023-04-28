#ifdef HAVE_CONFIG.H
#include <config.h>
#endif

#include "bureau.h"
#include "stdio.h"
#include "string.h" 
#include <gtk/gtk.h>
#include <string.h>
//////////////////////////
enum{
	E_ID_BUREAU,
	E_MUNI,
	E_ECOLE,
	E_SALLE,
	E_CAP_BUREAU,
	E_CAP_OBS,
	COLUMNS
};
////////////////////////////

int ajout_bv(bureau_vote b_v){
	   FILE * f=fopen("bureau.txt", "a+");
    if	(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s \n",b_v.ID_bureau_vote, b_v.municipalite, b_v.ecole,b_v.num_salle,b_v.cap_bureau_vote,b_v.observateur);
        fclose(f);
		return 1;
    }else 
	return 0;
}

////////////////////////////
int affiche_bureau(GtkWidget *liste){

		GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;

	bureau_vote b_v;	

	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	
	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID_bureau_vote",renderer,"text",E_ID_BUREAU,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",E_MUNI,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ecole",renderer,"text",E_ECOLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("num_salle",renderer,"text",E_SALLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cap_bureau_vote",renderer,"text",E_CAP_BUREAU,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("observateur",renderer,"text",E_CAP_OBS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


	f=fopen("bureau.txt","r");
if (f==NULL){
	return 0;
		}

	else
		{
	f=fopen("bureau.txt","a+");
	while	(fscanf(f,"%s %s %s %s %s %s \n",b_v.ID_bureau_vote, b_v.municipalite, b_v.ecole,b_v.num_salle,b_v.cap_bureau_vote,b_v.observateur)!=EOF)
	{	

	gtk_list_store_append(store,&iter);

	/*enum{
	E_ID_BUREAU,
	E_MUNI,
	E_ECOLE,
	E_SALLE,
	E_CAP_BUREAU,
	E_CAP_OBS,
	COLUMNS
	};*/

	gtk_list_store_set(store,&iter,E_ID_BUREAU,b_v.ID_bureau_vote,E_MUNI, b_v.municipalite,E_ECOLE, b_v.ecole,E_SALLE,b_v.num_salle,E_CAP_BUREAU,b_v.cap_bureau_vote,E_CAP_OBS,b_v.observateur,-1);
	
	}
	fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));

	g_object_unref(store);

	return 1;

}
}




////////////////////////
int supprimer_bv(char id[] )
{	
	int tr=0;
	bureau_vote b_v;
	int x=0;

    FILE * f=fopen("bureau.txt", "r");
    FILE * f2=fopen("dump.txt", "w");



	while	(fscanf(f,"%s %s %s %s %s %s \n",b_v.ID_bureau_vote, b_v.municipalite, b_v.ecole,b_v.num_salle,b_v.cap_bureau_vote,b_v.observateur)!=EOF)
	{
		if	(strcmp(b_v.ID_bureau_vote,id)!=0 ) {
        fprintf(f2,"%s %s %s %s %s %s \n",b_v.ID_bureau_vote, b_v.municipalite, b_v.ecole,b_v.num_salle,b_v.cap_bureau_vote,b_v.observateur);
		x=1;
			}
	}



        fclose(f);
        fclose(f2);
		remove("bureau.txt");
		rename("dump.txt","bureau.txt");
        return x;	
    }


/////////////////////////////////////
int vider(GtkWidget *liste){

	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;

	bureau_vote b_v;	

	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	
	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID_bureau_vote",renderer,"text",E_ID_BUREAU,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",E_MUNI,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ecole",renderer,"text",E_ECOLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("num_salle",renderer,"text",E_SALLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cap_bureau_vote",renderer,"text",E_CAP_BUREAU,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("observateur",renderer,"text",E_CAP_OBS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	

	gtk_list_store_append (store,&iter);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
	
	return 1;
	}
	
	

/////////////////////////////
int chercher(char id[])
{
	bureau_vote b_v;

	int tr=0;
	int	x=0;
	

	FILE * f=fopen("bureau.txt", "r");

	
	while(fscanf(f,"%s %s  %s %s %s %s ",b_v.ID_bureau_vote, b_v.municipalite, b_v.ecole,b_v.num_salle,b_v.cap_bureau_vote,b_v.observateur)!=EOF)
		{
			if(strcmp(b_v.ID_bureau_vote,id)==0){
				tr=1;
				}

		}

	

	fclose(f);
			


	return tr;

	}

//////////////////////////////////////
int modifier(char id[], bureau_vote nouv)
{
	bureau_vote b_v;
	int x=0;
	
    FILE * f=fopen("bureau.txt", "r");
    FILE * f2=fopen("dump.txt", "a");


	while	((fscanf(f,"%s %s %s %s %s %s \n",b_v.ID_bureau_vote, b_v.municipalite, b_v.ecole,b_v.num_salle,b_v.cap_bureau_vote,b_v.observateur)!=EOF))
{
	if(	strcmp(b_v.ID_bureau_vote,id)!=0){
        fprintf(f2,"%s %s %s %s %s %s \n",b_v.ID_bureau_vote, b_v.municipalite, b_v.ecole,b_v.num_salle,b_v.cap_bureau_vote,b_v.observateur);
		x=1;
		}

	else
		fprintf(f2,"%s %s %s %s %s %s \n",nouv.ID_bureau_vote, nouv.municipalite, nouv.ecole,nouv.num_salle,nouv.cap_bureau_vote,nouv.observateur);
} 
    
	    fclose(f);
        fclose(f2);
remove("bureau.txt");
rename("dump.txt","bureau.txt");
	return x;
}