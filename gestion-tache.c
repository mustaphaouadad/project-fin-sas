#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    int jours;
    int mois;
    int annee;
} date;
typedef enum {
    Faible,
    Importante
} PrioriteEnum;
typedef struct {
    PrioriteEnum Priorite;
    char titre[100];
    char Description[100];
    date Date;
} Tache;
Tache ListeTaches[MAX_TACHES];
int countTaches = 0;
void AjouterTache() {
    if (countTaches < MAX_TACHES) {
        Tache nouvelleTache;
         printf("Donner le titre de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.titre);

        printf("Donner la description de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.Description);

        printf("Donner la date de la tache (Format: jour-mois-annee) : ");
        scanf("%d-%d-%d", &nouvelleTache.Date.jours, &nouvelleTache.Date.mois, &nouvelleTache.Date.annee);

        printf("Donner la prioritee de la tache (0: Faible, 1: Importante) : ");
        scanf("%d", (int*)&nouvelleTache.Priorite);

        ListeTaches[countTaches++] = nouvelleTache;
        printf("Tache ajoutee avec succes!\n");
    } else {
        printf("La liste de taches est pleine. Impossible d'ajouter plus de taches.\n");
    }
}
void AfficherListeTaches() {
    int i;
	if(countTaches > 0){
    printf("----------------Liste des taches :------------------\n");
    for (i = 0; i < countTaches; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Titre : %s\n", ListeTaches[i].titre);
        printf("Description : %s\n", ListeTaches[i].Description);
        printf("Date : %d-%d-%d\n", ListeTaches[i].Date.jours, ListeTaches[i].Date.mois, ListeTaches[i].Date.annee);

       
        switch (ListeTaches[i].Priorite) {
            case Faible:
                printf("Priorite : Faible\n");
                break;
            
            case Importante:
                printf("Priorite : Importante\n");
                break;
           
            default:
                printf("Priorite inconnue\n");
        }
        printf("\n");
    }
    }else{
    	printf("Aucune tache a afficher!\n");
	 
}
}
void ModifierTache() {
    if (countTaches > 0) {
        int numeroTache;
        printf("Donner le numero de la tache a modifier: ");
        scanf("%d", &numeroTache);
        if (numeroTache > 0 && numeroTache <= countTaches) {
            Tache *modifierTache = &ListeTaches[numeroTache - 1];
             printf("Entrez la nouvelle tittre de la tache : ");
            scanf(" %[^\n]s", modifierTache->titre);

            printf("Entrez la nouvelle description de la tache : ");
            scanf(" %[^\n]s", modifierTache->Description);

            printf("Entrez la nouvelle date de la tache (Format: jour-mois-annee) : ");
            scanf("%d-%d-%d", &modifierTache->Date.jours, &modifierTache->Date.mois, &modifierTache->Date.annee);

            printf("Entrez la nouvelle prioritee de la tache (0: Faible, 1:  Importante) : ");
            scanf("%d", (int*)&modifierTache->Priorite);

            printf("Tache modifiee avec succes!\n");
        } else {
            printf("Aucune tache a modifier!\n");
        }
    } else {
        printf("Aucune tache a modifier!\n");
    }
}
int main() {
    int choix;

    do {
        printf("\n-----------------------Menu:---------------------\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher la liste des taches\n");
        printf("3. Modifier une tache\n");
        
        printf("0. Quitter\n");

        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                AjouterTache();
                break;
            case 2:
                AfficherListeTaches();
                break;
            case 3:
                ModifierTache();
                break;
            
            case 0:
                printf("Programme termine!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 8.\n");
        }
    } while (choix != 0);

    return 0;
}