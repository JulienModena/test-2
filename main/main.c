#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAX 500

typedef struct date{
    int jour,mois,annee;
}date_naissance;

typedef struct eleve{
    char nomprenom[MAX];
    date_naissance naissance;
}eleve;

typedef struct classe{
char grade[MAX];
int age_classe;
int nb_eleve;
struct eleve mon_eleve;
}classe;

typedef struct ecole {
char nom_ecole[MAX];
char adresse_ecole[MAX];
char nom_academie[MAX];
char nom_directrice[MAX];
struct classe classe;

}ecole;
eleve FicheEleve(eleve T, FILE *fic);

int main(int argc, char ** argv)
{
	//switch Julien MO
	int mot_de_passe;
	int choix_menu;
    eleve *tab_eleve=NULL;
    printf("Saisir le mot de passe = ");
    scanf("%d",&mot_de_passe);

    if(mot_de_passe==1234)
    {

        printf("bonjour madame la directrice\n");
        printf("Pour afficher les détails de l'école taper 1\nPour afficher les détails de la classe taper 2\nPour afficher les détails de l'éleve taper 3\nPour rechercher un éleve taper 4\nPour inscrire un éleve taper 5\nPour exclure un éleve taper 6\nPour affecter un éleve à une classe taper 7\n");
        scanf("%d",&choix_menu);

        if(choix_menu==1)
        {
        	
        printf("afficher les détails de l'école\n");
       		
            FILE* ficho = NULL;

             ficho = fopen("ficheecole.txt","r");

                if(ficho==NULL)
            {
                 printf("erreur sur le pointeur");
            }
                 char c='\0';

            // on lit le fichier caractère à caracère puis on le printf dans le terminal

                 while(c!=EOF)
                    {
                        c = fgetc(ficho);
                        printf("%c",c );
    

                    }
        fclose(ficho);
          
        }
        else if(choix_menu==2)
        {
            
            printf("afficher les détails de la classe\n");
            int choixClasse;
  
  printf("=== GOD SCHOOL ===\n\n");
  printf("1. CP\n");
  printf("2. CE1\n");
  printf("3. CE2\n");
  printf("4. CM1\n");
  printf("5. CM2\n");
  printf("\nVotre choix ? ");
  scanf("%d", &choixClasse);
  
  printf("\n");
  
  switch (choixClasse)
  {
case 1:
    printf("=== CLASSE CP ===\n\n");
    FILE* fic = fopen("CP.txt","r");
    char c='\0';
    // on lit le fichier caractère à caracère puis on le printf dans le terminal
        while(c != EOF)
    {
      c = fgetc(fic);
      printf("%c", c);
    }
    fclose(fic);
    break;
case 2:
    printf("=== CLASSE CE1 ===\n\n");
    fic = fopen("CE1.txt","r");
    // on lit le fichier caractère à caracère puis on le printf dans le terminal
    while(c != EOF)
    {
      c = fgetc(fic);
      printf("%c", c);
    }
    fclose(fic);
    break;
case 3:
    printf("=== CLASSE CE2 ===\n\n");
    fic = fopen("CE2.txt","r");
    // on lit le fichier caractère à caracère puis on le printf dans le terminal
    while(c != EOF)
    {
      c = fgetc(fic);
      printf("%c", c);
    }
    fclose(fic);
    break;
case 4:
    printf("=== CLASSE CM1 ===\n\n");
    fic = fopen("CM1.txt","r");
    // on lit le fichier caractère à caracère puis on le printf dans le terminal
    while(c != EOF)
    {
      c = fgetc(fic);
      printf("%c", c);
    }
    fclose(fic);
    break;
case 5:
    printf("=== CLASSE CM2 ===\n\n");
    fic = fopen("CM2.txt","r");
    // on lit le fichier caractère à caracère puis on le printf dans le terminal
    while(c != EOF)
    {
      c = fgetc(fic);
      printf("%c", c);
    }
    fclose(fic);
    break;
    default:
    printf("Votre saisie est incorrecte");
    break;
    }
  
      printf("\n\n");
      
        }
        else if(choix_menu==3)
        {
        	
            printf("afficher les détails de l'éleve\n");

            int i;

            scanf("%d",&i);
            //on affiche les détails de l'eleve au rang i
            printf("Nom  Prenom   : %s\n" ,(tab_eleve+i)->nomprenom);
            printf("date de naissance = %d/%d/%d",(tab_eleve+i)->naissance.jour,(tab_eleve+i)->naissance.mois,(tab_eleve+i)->naissance.annee);
        }

        else if(choix_menu==4)
        {
        	
            printf("rechercher un éleve");
            char saisie[MAX];
            //on saisie un numéro d'eleve a rechercher dans la liste des eleves
            scanf(" %s",saisie);
            int i=0;
            //tant que la saisie du nom est prenom n'est pas correspondante alors on bouge notre tete lecture pour trouver le bon nom 
            while(saisie==(tab_eleve+i)->nomprenom)
            {
                i=i+1;
            }
            printf("Nom  Prenom   : %s\n" ,(tab_eleve+i)->nomprenom);
            printf("date de naissance = %d/%d/%d",(tab_eleve+i)->naissance.jour,(tab_eleve+i)->naissance.mois,(tab_eleve+i)->naissance.annee);
        }
         else if(choix_menu==5)
        {
        	
            //pour l'ajout d'un eleve dans la grande liste générale des élèves
			printf("inscrire un éleve\n");
            int n=0;
         
                 	eleve T;
                 	// nombre d'élèves a ajouter 
                    printf("Donnez le nombre d'élèves a ajouter = ");
                    scanf("%d",&n);
                    printf("%d",n);

                    printf("Saisir les élèves\n");
                    FILE *fic = NULL;
                    // ajout a la suite de la liste des élèves grace au "a"
                    fic = fopen("jul.txt","a");
                    if(fic == NULL)
                    {
                        printf("erreur de pointeur");
                    }

                    for(int i=0;i<n;i++)
                    {
                    	//répétitions de la fonction par rapport au nombre d'élèves a ajouter
                        T=FicheEleve(T,fic);

                    }

                    fclose(fic);

        }
         else if(choix_menu==6)
        {
        	
            printf("exclure un éleve");
        }
         else if(choix_menu==7)
        {
        	
            printf("affecter un éleve à une classe");
            FILE *ptrfile = NULL;

    ptrfile = fopen("jul.txt","r");
    
    

if (ptrfile!=NULL)
{
    int nb_eleve=0;
    char c='\0';
    
//on compte le nombre de ligne dans le fichier texte donc on a 
    while(c != EOF )
    {
        c = fgetc(ptrfile);

        if (c=='\n')
        {
            nb_eleve=nb_eleve+1;
            
        }

    }
    // on remet la tete de lecture au début du fichier
    fseek(ptrfile,0,SEEK_SET);

//tab_eleve pointe vers la structure eleve
    eleve *tab_eleve=NULL;
    
//attribue la taille mémoire en fonction de notre nombre d'eleves
    tab_eleve=malloc(sizeof (nb_eleve)*(sizeof(eleve)));
    char tampon[8];
    for (int i = 0; i < nb_eleve; ++i)
    {
        //pour récuperer la string nomprenom
        fscanf(ptrfile,"%[^;]s",(tab_eleve+i)->nomprenom);
        printf("juste apres le scan : %s\n",(tab_eleve+i)->nomprenom);
        //pour actualiser la tete de lecture et ce décaller d'une case
        fseek(ptrfile,1,SEEK_CUR);
        fscanf(ptrfile,"%d",&(tab_eleve+i)->naissance.jour);
        fseek(ptrfile,1,SEEK_CUR);
        fscanf(ptrfile,"%d",&(tab_eleve+i)->naissance.mois);
        fseek(ptrfile,1,SEEK_CUR);
        fscanf(ptrfile,"%d",&(tab_eleve+i)->naissance.annee);
        fscanf(ptrfile,"%[^\n]s",tampon);
        //printf("%d",(int)strlen(tampon));
        fseek(ptrfile,1,SEEK_CUR);
    }
            FILE * pointeur_vers_cp = NULL;
            FILE * pointeur_vers_ce1 = NULL;
            FILE * pointeur_vers_ce2 = NULL;
            FILE * pointeur_vers_cm1 = NULL;
            FILE * pointeur_vers_cm2 = NULL;
            

for (int i = 0; i <nb_eleve-1; ++i)

{

    
    if ((tab_eleve+i)->naissance.annee==2008)
    {
        pointeur_vers_cm2 = fopen("CM2.txt","a");
        char textz[MAX]={'\0'};
        sprintf(textz,"%s:%d/%d/%d\n",(tab_eleve+i)->nomprenom,(tab_eleve+i)->naissance.jour,(tab_eleve+i)->naissance.mois,(tab_eleve+i)->naissance.annee);
        //printf("%s",textz);
        fputs(textz,pointeur_vers_cm2);
        fclose(pointeur_vers_cm2);      
    }
    if ((tab_eleve+i)->naissance.annee==2009)
    {
        pointeur_vers_cm1 = fopen("CM1.txt","a");
        char textz[MAX]={'\0'};
        sprintf(textz,"%s:%d/%d/%d\n",(tab_eleve+i)->nomprenom,(tab_eleve+i)->naissance.jour,(tab_eleve+i)->naissance.mois,(tab_eleve+i)->naissance.annee);
        //printf("%s",textz);
        fputs(textz,pointeur_vers_cm1);
        fclose(pointeur_vers_cm1);      
    }
    if ((tab_eleve+i)->naissance.annee==2010)
    {
        pointeur_vers_ce2 = fopen("CE2.txt","a");
        char textz[MAX]={'\0'};
        sprintf(textz,"%s:%d/%d/%d\n",(tab_eleve+i)->nomprenom,(tab_eleve+i)->naissance.jour,(tab_eleve+i)->naissance.mois,(tab_eleve+i)->naissance.annee);
        //printf("%s",textz);
        fputs(textz,pointeur_vers_ce2);
        fclose(pointeur_vers_ce2);      
    }
    if ((tab_eleve+i)->naissance.annee==2011)
    {
        pointeur_vers_ce1 = fopen("CE1.txt","a");
        char textz[MAX]={'\0'};
        sprintf(textz,"%s:%d/%d/%d\n",(tab_eleve+i)->nomprenom,(tab_eleve+i)->naissance.jour,(tab_eleve+i)->naissance.mois,(tab_eleve+i)->naissance.annee);
        //printf("%s",textz);
        fputs(textz,pointeur_vers_ce1);
        fclose(pointeur_vers_ce1);      
        
    }
    if ((tab_eleve+i)->naissance.annee==2012)
    {
        pointeur_vers_cp = fopen("CP.txt","a");
        char textz[MAX]={'\0'};
        sprintf(textz,"%s:%d/%d/%d\n",(tab_eleve+i)->nomprenom,(tab_eleve+i)->naissance.jour,(tab_eleve+i)->naissance.mois,(tab_eleve+i)->naissance.annee);
        //printf("%s",textz);
        fputs(textz,pointeur_vers_cp);
        fclose(pointeur_vers_cp);       
    }

    
 
    
}
    
}
else
{
    printf("probleme d'assignation ");
}
        
        }

    }


	return EXIT_SUCCESS;
}
eleve FicheEleve(eleve T, FILE *fic)
{
        // variable pour stocker l'ensemble des valeurs de la structures
        char text[MAX];

        printf("eleves = ");

        printf("Nom prenom : ");
        scanf(" %s",T.nomprenom);

        printf("date de naissance : \n");
        printf("Jour : ");
        scanf("%d", &T.naissance.jour);
        printf("Mois : ");
        scanf("%d", &T.naissance.mois);
        printf("Année : ");
        scanf("%d", &T.naissance.annee);
      
        sprintf(text,"%s;%d/%d/%d\n ",T.nomprenom,T.naissance.jour,T.naissance.mois,T.naissance.annee);

        fputs(text,fic);

    return T;

}

