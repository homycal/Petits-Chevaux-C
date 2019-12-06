#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "joueur.h"

void InitJoueur(int *nombreJoueur,int whitelist[], Pion jeu[],int joueurDuTour, int scoreDes, int joueurIA[]){
  int couleurPick[4]={0,0,0,0};// On s'en sert pour savoir si la couleur est prise (la couleur sera défine par l'indice)
  do{
    printf("Combien de joueurs êtes vous ? \n");
    *nombreJoueur = LireEntier(whitelist, jeu, 0, joueurDuTour, scoreDes, joueurIA);
  }while(*nombreJoueur<2 || *nombreJoueur>4);
  for(int i=0; i<*nombreJoueur; i++){
    whitelist[i]=ChoixCouleur(*nombreJoueur, whitelist, i, jeu, couleurPick, joueurDuTour, scoreDes, joueurIA);
    couleurPick[whitelist[i]]= 1; // On déclare cette couleur comme prise
    printf("\n");
  }
}

int ChoixCouleur(int nombreJoueur, int whitelist[], int i, Pion jeu[], int couleurPick[], int joueurDuTour, int scoreDes, int joueurIA[]){
  int choix, temp;
  printf("Joueur n°%d, quelle couleur choisissez vous ?\n",i);
  /*On affiche la couleur seulement si elle est disponible*/
  if(couleurPick[0]==0){
    printf("0. Vert\n");
  }
  if(couleurPick[1]==0){
    printf("1. Jaune\n");
  }
  if(couleurPick[2]==0){
    printf("2. Bleu\n");
  }
  if(couleurPick[3]==0){
    printf("3. Rouge\n");
  }
  
  do{
    do{
      choix=LireEntier(whitelist, jeu, 0, joueurDuTour, scoreDes, joueurIA);
      temp=0;
      }while((choix<0||choix>3));

      if(couleurPick[choix]==1){
        printf("Cette couleur est déjè prise !\n");
        temp=1;
      }
  }while(temp==1);
  return(choix);
}
