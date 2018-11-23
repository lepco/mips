# mips
  Structure du projet
  
  Lire fichier
  déchiffrer les instructions
    lecture première partie
    En fonction, choisir la séparation des autres éléments
    Traduction binaire -> hexa
    
    TAB[1]=ADD
    
    TAB2[1][0]='00000100000'
    
    Resultat=<<TAB2[1][0]>>
    
    Resultat=00000100000
    
    TAB2[1][1]=22
    
    if 2 ==> rd
    elsif 3 ==> rs
    
    rd = '01000'
    
    Resultat= Resulat + rd
    
    Resultat=0100000000100000
    
    ///////
  Variables :
    {0}int rd
    {1}int rs
    {2}int rt
    {3}int im
    {4}int of
    char inst[100]
    char fichierLecture[100] //nom du fichier qui contient les instructions assembleur
    char fichierEcriture[100] //nom du fichier où on écrit les instructions en binaire
    char robert[15] //Instuction assembleur(ADD, NOP, BGTZ,...)
    int instBin; 00000000000000
  Fonctions :
  
    lecture(nomFichier)
      >> Ecrire dans un tableau l'instruction entière, ATTENTION ! Ne pas écrire les commentaire
      
    separation(une instruction)
      >> Sépare et affecte Rd, Rs,...
      
    ecritureBinaire()
      >> Prend les variables et compose l'instruction en binaire
      retourne resultat
     
    ecritureFichier(nomFichier, instruction binaire)
      >> Ecrit dans nomFichier l'instruction en binaire
      
    Réinitialisation des variable
      >> all=0
    
