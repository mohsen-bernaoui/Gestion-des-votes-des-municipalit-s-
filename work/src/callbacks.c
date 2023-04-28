#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "bureau.h"
#include <string.h>

void
on_retour_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajout_gestoin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_ajout_bv;
	GtkWidget *fenetre_gestion;
	
	fenetre_gestion=lookup_widget(button,"fenetre_gestion");
	gtk_widget_destroy(fenetre_gestion);

	fenetre_ajout_bv=create_fenetre_ajout_bv();
	gtk_widget_show(fenetre_ajout_bv);
}


void
on_liste_gestion_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_liste_bv;
	GtkWidget *fenetre_gestion;
	
	fenetre_gestion=lookup_widget(button,"fenetre_gestion");
	gtk_widget_destroy(fenetre_gestion);

	fenetre_liste_bv=create_fenetre_liste_bv();
	gtk_widget_show(fenetre_liste_bv);
}


void
on_retour_to_gestion_from_ajout_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_ajout_bv;
	GtkWidget *fenetre_gestion;
	
	fenetre_ajout_bv=lookup_widget(button,"fenetre_ajout_bv");
	gtk_widget_destroy(fenetre_ajout_bv);

	fenetre_gestion=create_fenetre_gestion();
	gtk_widget_show(fenetre_gestion);
}


void
on_liste_to_liste_from_ajout_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_ajout_bv;
	GtkWidget *fenetre_liste_bv;
	
	fenetre_ajout_bv=lookup_widget(button,"fenetre_ajout_bv");
	gtk_widget_destroy(fenetre_ajout_bv);

	fenetre_liste_bv=create_fenetre_liste_bv();
	gtk_widget_show(fenetre_liste_bv);
}


void
on_ajout_bv_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    bureau_vote b_v;

	int x;
	
	GtkWidget *id_b_v,*municipalite,*ecole,*salle,*cap_bureau,*cap_obs;

	GtkWidget *fenetre_ajout_bv;
	GtkWidget  *fenetre_liste_bv;
	GtkWidget *treeview1;
    GtkWidget *erreur_bv;


	
	

	
	fenetre_ajout_bv=lookup_widget(button,"fenetre_ajout_bv");


	id_b_v=lookup_widget(button,"ajout_id_bv");

	municipalite=lookup_widget(button,"combo_ajout_muni");

	ecole=lookup_widget(button,"combo_ajout_ecole");

	salle=lookup_widget(button,"combo_ajout_salle");

	cap_bureau=lookup_widget(button,"ajout_cap_bv");

	cap_obs=lookup_widget(button,"ajout_num_obs_bv");


	strcpy(b_v.ID_bureau_vote,gtk_entry_get_text(GTK_ENTRY(id_b_v)));
	
	strcpy(b_v.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));

	strcpy(b_v.ecole,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ecole)));

	strcpy(b_v.num_salle,gtk_combo_box_get_active_text(GTK_COMBO_BOX(salle)));

	strcpy( b_v.cap_bureau_vote,gtk_entry_get_text(GTK_ENTRY(cap_bureau))) ;

	strcpy(b_v.observateur,gtk_entry_get_text(GTK_ENTRY(cap_obs))) ;

	x=chercher(b_v.ID_bureau_vote);

	if ( (strlen(b_v.ID_bureau_vote)==0) ||  (strlen(b_v.cap_bureau_vote)==0) || (strlen(b_v.observateur)==0) ) 
	{

	GtkWidget *erreur_bv;

    erreur_bv=lookup_widget(button,"erreur_bv");

	erreur_bv=create_erreur_bv();

	gtk_widget_show(erreur_bv);

	}
	else{
		
		x=ajout_bv(b_v);
									if (x==1)
									printf("\n ajout de bureau avec succes 1\n");

									else 
									{

									printf("\n echec ajout 1 \n");
									
									erreur_bv=lookup_widget(button,"erreur_bv");

									erreur_bv=create_erreur_bv();

									gtk_widget_show(erreur_bv);
									}


	x=affiche_bureau(treeview1);

	if (x==1)
					printf("\n afficher de bureau avec succes \n");
			else 	
					printf("\n echec affiche \n");


      

		fenetre_ajout_bv=lookup_widget(button,"fenetre_ajout_bv");
		
		gtk_widget_destroy(fenetre_ajout_bv);
		
		fenetre_liste_bv=create_fenetre_liste_bv();

		gtk_widget_show(fenetre_liste_bv);
	

	}

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retour_from_liste_to_gestion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_gestion;
	GtkWidget *fenetre_liste_bv;
	
	fenetre_liste_bv=lookup_widget(button,"fenetre_liste_bv");
	gtk_widget_destroy(fenetre_liste_bv);

	fenetre_gestion=create_fenetre_gestion();
	gtk_widget_show(fenetre_gestion);
}


void
on_recherche_bv_liste_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    int x;

    char id[100];
    
    GtkWidget *choix;

	bureau_vote b_v;
    

    choix=lookup_widget(button,"choix_id_bv");

    strcpy(id,gtk_entry_get_text(GTK_ENTRY(choix)));
    
	

    x=chercher(id);
    
    if (x==1){ 
		    
					printf("\n recherche de bureau avec succes \n");

           			}

				else {
						
					printf("\n echec recherche \n");

                    GtkWidget *erreur_bv;

                    erreur_bv=lookup_widget(button,"erreur_bv");

	                erreur_bv=create_erreur_bv();

	                gtk_widget_show(erreur_bv);

                    }
}


void
on_modif_bv_to_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_modfi_bv;
	GtkWidget *fenetre_liste_bv;
	
	fenetre_liste_bv=lookup_widget(button,"fenetre_liste_bv");
	gtk_widget_destroy(fenetre_liste_bv);

	fenetre_modfi_bv=create_fenetre_modfi_bv();
	gtk_widget_show(fenetre_modfi_bv);
}


void
on_ajout_from_liste_ajout_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_ajout_bv;
	GtkWidget *fenetre_liste_bv;
	
	fenetre_liste_bv=lookup_widget(button,"fenetre_liste_bv");
	gtk_widget_destroy(fenetre_liste_bv);

	fenetre_ajout_bv=create_fenetre_ajout_bv();
	gtk_widget_show(fenetre_ajout_bv);
}


void
on_sup_bv_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{   
    int x;

    char id[100];
    
    GtkWidget *choix;
	GtkWidget *fenetre_liste_bv;
    
	fenetre_liste_bv=lookup_widget(button,"fenetre_liste_bv");
	
    choix=lookup_widget(button,"choix_id_bv");

    strcpy(id,gtk_entry_get_text(GTK_ENTRY(choix)));
    
	

    x=supprimer_bv(id);
    
    if (x==1){
			printf("\n supp de bureau avec succes \n");
            }
				else {
                    printf("\n echec supp \n");

                    	GtkWidget *erreur_bv;

                        erreur_bv=lookup_widget(button,"erreur_bv");

	                    erreur_bv=create_erreur_bv();

	                    gtk_widget_show(erreur_bv);

                    }


}


void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_liste_bv,*w;
	GtkWidget *treeview1;

	int x;

	w=lookup_widget(button,"fenetre_liste_bv");
	fenetre_liste_bv=create_fenetre_liste_bv();

	gtk_widget_show(fenetre_liste_bv);

	gtk_widget_hide(w);
	treeview1=lookup_widget(fenetre_liste_bv,"treeview1");

	x=vider(treeview1);

	if (x==1)
					printf("\n vidage de bureau avec succes \n");
			else 	
					printf("\n echec vidage \n");

	x=0;

	x=affiche_bureau(treeview1);

	if (x==1)
					printf("\n afficher de bureau avec succes \n");
			else 	
					printf("\n echec affiche \n");
}


void
on_retour_from_modif_to_liste_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_modfi_bv;
	GtkWidget *fenetre_liste_bv;
	
	fenetre_modfi_bv=lookup_widget(button,"fenetre_modfi_bv");
	gtk_widget_destroy(fenetre_modfi_bv);

	fenetre_liste_bv=create_fenetre_liste_bv();
	gtk_widget_show(fenetre_liste_bv);
}


void
on_modif_bv_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

    

    char id[100];
    

	bureau_vote b_v;
	bureau_vote nouv;
    



	int x,y;
	
	GtkWidget *id_b_v,*municipalite,*ecole,*salle,*cap_bureau,*cap_obs;


	GtkWidget *fenetre_modfi_bv;
	GtkWidget  *fenetre_liste_bv;
    GtkWidget *erreur_bv;

	
    
	fenetre_liste_bv=lookup_widget(button,"fenetre_liste_bv");

	
	fenetre_modfi_bv=lookup_widget(button,"fenetre_modfi_bv");

	id_b_v=lookup_widget(button,"modif_id_bv");    

	municipalite=lookup_widget(button,"combo_modif_muni_bv");

	ecole=lookup_widget(button,"combo_modif_ecole_bv");

	salle=lookup_widget(button,"combo_modif_salle_bv");

	cap_bureau=lookup_widget(button,"modif_cap_bv_modif");

	cap_obs=lookup_widget(button,"modif_obs_bv");


	strcpy(nouv.ID_bureau_vote,gtk_entry_get_text(GTK_ENTRY(id_b_v)));
	
	strcpy(nouv.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));

	strcpy(nouv.ecole,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ecole)));

	strcpy(nouv.num_salle,gtk_combo_box_get_active_text(GTK_COMBO_BOX(salle)));

	strcpy(nouv.cap_bureau_vote,gtk_entry_get_text(GTK_ENTRY(cap_bureau))) ;

	strcpy(nouv.observateur,gtk_entry_get_text(GTK_ENTRY(cap_obs))) ;

	
	y=chercher(nouv.ID_bureau_vote);
	

	if ( (strlen(nouv.ID_bureau_vote)==0) ||  (strlen(nouv.cap_bureau_vote)==0) || (strlen(nouv.observateur)==0) ) 
	{
    erreur_bv=lookup_widget(button,"erreur_bv");

	erreur_bv=create_erreur_bv();

	gtk_widget_show(erreur_bv);

	}
	else{
		   /*

		///////////
		x=supprimer_bv(id);
    
    if (x==1){
			printf("\n supp de bureau avec succes \n");
            }
		else {
            printf("\n echec supp \n");

                    	GtkWidget *erreur_bv;

                        erreur_bv=lookup_widget(button,"erreur_bv");

	                    erreur_bv=create_erreur_bv();

	                    gtk_widget_show(erreur_bv);

                    }
		////////////
		x=ajout_bv(b_v);
					if (x==1)
						printf("\n ajout de bureau avec succes \n");
					else 
						printf("\n echec ajout \n");

      		
		gtk_widget_destroy(fenetre_modfi_bv);
		
		fenetre_liste_bv=create_fenetre_liste_bv();

		gtk_widget_show(fenetre_liste_bv);
		*/
	x=modifier(nouv.ID_bureau_vote,nouv);
					if (x==1){
								
								
								printf("\n modif de bureau avec succes \n");
								
								gtk_widget_destroy(fenetre_modfi_bv);
		
								fenetre_liste_bv=create_fenetre_liste_bv();

								gtk_widget_show(fenetre_liste_bv);

								}
								
					else {
						printf("\n echec modif \n");

                        erreur_bv=lookup_widget(button,"erreur_bv");

	                    erreur_bv=create_erreur_bv();

	                    gtk_widget_show(erreur_bv);

						}
	
	}

}


void
on_aff_from_modif_to_liste_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_modfi_bv;
	GtkWidget *fenetre_liste_bv;
	
	fenetre_modfi_bv=lookup_widget(button,"fenetre_modfi_bv");
	gtk_widget_destroy(fenetre_modfi_bv);

	fenetre_liste_bv=create_fenetre_liste_bv();
	gtk_widget_show(fenetre_liste_bv);
}


void
on_retour_erreur_bv_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *erreur_bv;

    erreur_bv=lookup_widget(button,"erreur_bv");
	gtk_widget_destroy(erreur_bv);
}

