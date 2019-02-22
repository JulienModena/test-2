#include <stdio.h>
#include <stdlib.h>



eleve renvoi (eleve *TCP,int *i,eleve *TCE1,eleve *TCE2,eleve *TCM1,eleve *TCM2)
{
    printf("entrée supprimer pour confirmer que  vous voulez supprimer\n");
    char saisi[10]={'\0'};
    scanf("%s",saisi);
    char nomprenom[30]={"\0"};
    int compteur=0;
    char tampon[30];
    char renvoye='r';
    char renvoyeespace=' ';
    int j=0;
    char classe[5];
    int k;
    FILE *ptrfile = NULL;
    if(strcmp(saisi,"supprimer")==0)
    {
        printf("entrez le nom de la classe\n");
        scanf("%s",classe);
        printf("entrez le nom et prenom de l'eleve\n");
        scanf("%s",nomprenom);
         if (strcmp(classe,"CP")==0)
         {
             ptrfile = fopen("CP.txt","r");
         }
         else if (strcmp(classe,"CE1")==0)
         {
             ptrfile = fopen("CE1.txt","r");
         }
         else if (strcmp(classe,"CE2")==0)
         {
             ptrfile = fopen("CE2.txt","r");
         }
         else if (strcmp(classe,"CM1")==0)
         {
             ptrfile = fopen("CM1.txt","r");
         }
         else if (strcmp(classe,"CM2")==0)
         {
             ptrfile = fopen("CM2.txt","r");
         }
        int nb_eleve=0;
        char c='\0';
        while(c != EOF )
        {
            c = fgetc(ptrfile);

            if (c=='\n')
            {
                nb_eleve=nb_eleve+1;
            }
        }
        fseek(ptrfile,0,SEEK_SET);
        while(j!=MAX)
        {
            if (strcmp(classe,"CP")==0)
            {
                    for (int i = 1; i <= nb_eleve; ++i)
                    {
                        //pour le retour a la ligne
                        int positondeutligne=ftell(ptrfile);
                        //on met le nom et prenom du ficher dans une variables tampon
                        fscanf(ptrfile,"%[^;]s",tampon);
                        //comparaison
                        if( strcmp(tampon,nomprenom)==0)
                        {
                            //on position le curseur au debut de ligne
                            fseek(ptrfile,positondeutligne,SEEK_CUR);
                            //on ecrit la lettre r
                            fputs(renvoye,ptrfile);
                            //on met les espace avec le nombre lettre du nom dans le tampon
                            for (int k=0;k!=strlen(tampon);k++)
                            {
                                fputs(renvoyeespace,ptrfile);
                            }
                            compteur=0;
                        }
                        else{
                        fseek(ptrfile,10,SEEK_CUR);
                        }
                        compteur++;
                    }
                    j=0;
                    break;
                }
                else {j++;}
            if (strcmp(classe,"CE1")==0)
            {
                for (int i = 1; i <= nb_eleve; ++i)
                {
                   int positondeutligne=ftell(ptrfile);
                        fscanf(ptrfile,"%[^;]s",tampon);
                        if( strcmp(tampon,nomprenom)==0)
                        {
                            int strlen(tampon);
                            fseek(ptrfile,positondeutligne,SEEK_CUR);
                            fputs(renvoye,ptrfile);

                            for (int k=0;k!=strlen(tampon);k++)
                            {
                                fputs(renvoyeespace,ptrfile);
                            }
                            compteur=0;
                        }
                        else{
                        fseek(ptrfile,10,SEEK_CUR);
                        }
                        compteur++;
                    }
                    j=0;
                    break;
                }
                else {j++;}

            if (strcmp(classe,"CE2")==0)
            {
               for (int i = 1; i <= nb_eleve; ++i)
                    {
                        int positondeutligne=ftell(ptrfile);
                        fscanf(ptrfile,"%[^;]s",tampon);
                        if( strcmp(tampon,nomprenom)==0)
                        {
                            int strlen(tampon);
                            fseek(ptrfile,positondeutligne,SEEK_CUR);
                            fputs(renvoye,ptrfile);

                            for (int k=0;k!=strlen(tampon);k++)
                            {
                                fputs(renvoyeespace,ptrfile);
                            }
                            compteur=0;
                        }
                        else{
                        fseek(ptrfile,10,SEEK_CUR);
                        }
                        compteur++;
                    }
                    j=0;
                    break;
                }
                else {j++;}
            if (strcmp(classe,"CM2")==0)
            {
                for (int i = 1; i <= nb_eleve; ++i)
                    {
                    int positondeutligne=ftell(ptrfile);
                        fscanf(ptrfile,"%[^;]s",tampon);
                        if( strcmp(tampon,nomprenom)==0)
                        {
                            int strlen(tampon);
                            fseek(ptrfile,positondeutligne,SEEK_CUR);
                            fputs(renvoye,ptrfile);

                            for (int k=0;k!=strlen(tampon);k++)
                            {
                                fputs(renvoyeespace,ptrfile);
                            }
                            compteur=0;
                        }
                        else{
                        fseek(ptrfile,10,SEEK_CUR);
                        }
                        compteur++;
                    }
                            compteur=0;
                        }


                    j=0;
                    break;
                }
                else {j++;}
                fclose(ptrfile);
    }



