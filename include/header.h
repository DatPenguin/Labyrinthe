#ifndef MY_HEADER_H_
#define MY_HEADER_H_

 #define ROUGE "\033[5;1;31m"
 #define NORMAL "\033[0m"
 #define BLEU "\033[1;1;34m"
 #define JAUNE "\033[1;1;33m"
 #define LIGHT_VERT "\e[1;32m"
 #define NOIR "\e[0;30m"
 #define LIGHT_BLEU "\e[1;34m"
 #define VERT "\e[0;32m"
 #define CYAN "\e[0;36m"
 #define LIGHT_CYAN "\e[1;36m"
 #define LIGHT_ROUGE "\e[1;31m"
 #define VIOLET "\e[0;35m"
 #define LIGHT_VIOLET "\e[1;35m"
 #define MARRON "\e[0;33m"
 #define GRIS "\e[0;30m"
 #define LIGHT_GRIS "\e[0;37m"

 #define N 20
 #define M 20

 #define DEBUG 0

 #define FLEUR	"%s1 "
 #define ARBRE	"%s2 "
 #define ROCHER "%s3 "
 #define CLEF	"%s4 "
 #define PIECE	"%s5 "
 #define LOCK	"%s6 "
 #define PIEGE	"%s7 "
 #define MOB	"%s8 "
 #define TRESOR	"%s9 "
 #define CROIX	120

 char intro();
 void def_tableau();
 void affiche_tableau(int);
 int deplace_personnage();
 void print_status();
 void game_win();
 void game_over();
 void tty_raw();
 void ff(int);

#endif
