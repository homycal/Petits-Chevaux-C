void SortieEcurie(Pion jeu[], int joueurDuTour,int pionDuTour, char couleur[][6]){
  Manger(jeu, pionDuTour, 0, joueurDuTour, joueurDuTour*14, couleur);
  jeu[pionDuTour].plateau=1;
  jeu[pionDuTour].numCase=joueurDuTour*14;
}

int DeplacementPlateau(Pion jeu[], int pionDuTour, int scoreDes,char couleur[][6], int joueurDuTour){
  if(jeu[pionDuTour].decompteCase-scoreDes<0){
    printf("Vous allez dépasser l'entrée de votre zone, c'est impossible dommage ! \n");
    return(0);
  }
  if(DetectionBlocage(jeu,pionDuTour, scoreDes)!=-1){
    printf("Impossible, le pion %d bloque le passage, une autre fois ! \n",DetectionBlocage(jeu,pionDuTour, scoreDes) );
    return(0);
  }
  Manger(jeu, pionDuTour, scoreDes, joueurDuTour, jeu[pionDuTour].numCase, couleur);

  jeu[pionDuTour].numCase = (scoreDes +jeu[pionDuTour].numCase)%56;
  jeu[pionDuTour].decompteCase -= scoreDes;
  return(0);
}

int EntreeCentre(Pion jeu[], int pionDuTour, int scoreDes, int joueurDuTour){
  if(scoreDes != 1){
    printf("Vous ne pouvez pas entrez avec ce score !\n");
  }else if(scoreDes ==1 && CaseLibre(jeu, scoreDes, pionDuTour, 0)!=-1){
    printf("Le pion %d bloque le passage !\n", CaseLibre(jeu, scoreDes, pionDuTour, 0) );
  }else if(scoreDes ==1 && CaseLibre(jeu, scoreDes, pionDuTour, 0)==-1){ // Si tout est bon
    jeu[pionDuTour].plateau=CENTRE;
    jeu[pionDuTour].numCase=1;
  }else{
    printf("ERREUR CAS NOM PRIS EN COMPTE\n"); // On ne sait jamais
  }
return(0);

}
