#include <stdio.h>
#include <stdlib.h>
#include <time.h> // pour le srand()

int main(int argc, char *argv[])
{
    int nombreMystere, reponse, modeDeJeu, niveau,MAX,MIN = 1;
    char rejouer,reponseCoop;

    printf("Voulez-vous jouer tout seul ? y/n\n");
    scanf("%c",&reponseCoop);


    do
    {
        int nombreCoups = 0;

        if (reponseCoop == 'y')
        {
            printf("---Choisissez le niveau de difficulté---\n1. Débutant\n2. Chanceux\n3. Dieu\n");
            scanf("%d",&niveau);

            if (niveau == 1)
            {
             MAX = 100;  
            }
            else if (niveau == 2)
            {
                MAX = 1000;
            }
            else 
            {
                MAX = 10000;
            }

            srand(time(NULL)); // Initialise le générateur de nombre aléatoire
            nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
        }
        else 
        {
            printf("Quel est le nombre à faire deviner ?\n");
            scanf("%d",&nombreMystere);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        }

        printf("Uhmmm...\n");
        printf("Je réfléchis à un nombre entre 0 et %d.\n",MAX);
        printf("Quel est-il ?\n");
        scanf("%d",&reponse);
        nombreCoups++;

        while (reponse != nombreMystere) //tant que la réponse est différentes du nombre mystère alors
        {    
            if (reponse < nombreMystere) 
            // Si la reponse est infèrieur au nombre mystère alors le programme indique "c'est plus" et redemande une réponse
            {
                printf("C'est plus !\n");
                scanf("%d",&reponse);
                nombreCoups++;
            }
            else
            //Sinon c'est que la réponse est inferieur, le programme inque alors "c'est moins" et redemande une réponse
            {
                printf("C'est moins !\n");
                scanf("%d",&reponse);
                nombreCoups++;

            }
        }
         // Si l'on sort de la boucle c'est que la réponse est égale au nombre mystère
        
        printf("Bravo, vous avez trouve le nombre mystere !!!\nEn %d coups\n\n", nombreCoups);  /* code */
        printf("Voulez vous que je devinne un autre nombre ? y/n \n");
        while(getchar() != '\n');
        /* 
        permet de nettoyer le buffer sinon le scanf %c ne marche pas
        sans ça le scanf %c recuperera le \n dans le buffer (tapper lors de la validation des nombre)
        
        Il n'y a pas d'instruction dans cette boucle, mais getchar() a un impact sur le programme a chaque fois 
        qu'elle est évalué
        Attention cette boucle peut etre infini si on avait pas validé de nombre avant
        
        la fonction getchar() consomme les caractère dans le buffer jusqu'a ce qu'il arrive a une nouvelle ligne
        getchar () lit le caractère suivant le flux stdin et le renvoie sous forme de unsigned char,
        transformé en int ou EOF en cas d'erreur ou de fin de fichier
        */
       
        scanf("%c", &rejouer);

    } while (rejouer == 'y');
    

  return 0;
}