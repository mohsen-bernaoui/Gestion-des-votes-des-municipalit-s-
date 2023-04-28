#include <gtk/gtk.h>


void
on_retour_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajout_gestoin_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_liste_gestion_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_to_gestion_from_ajout_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_liste_to_liste_from_ajout_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajout_bv_clicked                    (GtkButton      *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_from_liste_to_gestion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche_bv_liste_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_modif_bv_to_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajout_from_liste_ajout_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_sup_bv_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_from_modif_to_liste_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_modif_bv_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_aff_from_modif_to_liste_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_erreur_bv_clicked            (GtkButton       *button,
                                        gpointer         user_data);
