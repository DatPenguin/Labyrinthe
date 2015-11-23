#ifndef MY_HEADER_H_
#define MY_HEADER_H_

 #define ROUGE "\033[5;1;31m"
 #define NORMAL "\033[0m"
 #define GRIS "\033[1;1;37m"
 #define BLEU "\033[1;1;34m"
 #define JAUNE "\033[1;1;33m"
 #define VERT "\\033[1;32m"

 #define N 20
 #define M 20

 int intro();
 void def_tableau();
 void affiche_tableau();
 int deplace_personnage();
 void game_win();
 void game_over();

#endif
