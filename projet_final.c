#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 20
#define M 20

#define ROUGE "\033[5;1;31m"
#define NORMAL "\033[0m"
#define GRIS "\033[1;1;37m"
#define BLEU "\033[1;1;34m"
#define JAUNE "\033[1;1;33m"
#define VERT "\\033[1;32m"

int piece = 0;
int vies = 3;
int tab[2];
int C[N][M]  =  {{0}};

int intro()
{
    int digit = 0;

    system("clear");
    printf ("\n\n\n\n\t\t\t************************************\n");
    printf ("\t\t\t*  %sBienvenue dans le labyrinthe%s    *\n", ROUGE, NORMAL);
    printf ("\t\t\t*                                  *\n");
    printf ("\t\t\t*    Les regles sont simple:       *\n");
    printf ("\t\t\t* -les mur sont representés par 8  *\n");
    printf ("\t\t\t* -les pièces par 6                *\n");
    printf ("\t\t\t* -la clef par un 5                *\n");
    printf ("\t\t\t* -et le tresors par un 2          *\n");
    printf ("\t\t\t* pour gagner il vous faudra       *\n");
    printf ("\t\t\t* collecter 5 pièces. le tresor    *\n");
    printf ("\t\t\t* represente 3 pieces toutefois il *\n");
    printf ("\t\t\t* vous faudra une clé pour y       *\n");
    printf ("\t\t\t* acceder.Attention aux pieges     *\n");
    printf ("\t\t\t*      GOOD LUCK AND ENJOY         *\n");
    printf ("\t\t\t*  (appuyez sur 5 pour continuer)  *\n");
    printf ("\t\t\t*      (ou sur 0 pour quitter)     *\n");
    printf ("\t\t\t************************************\n\n\n\n");
    scanf("%d", &digit);
    return digit;
}


void def_tableau()
{
    int i = 0;

    // C[xtmp][ytmp] = 1;//attribution des valeurs 1, 8, 6 equivalent respectivement au joueur, piege et piece.
    tab[0] = 0;
    tab[1] = 0;
    C[tab[0]][tab[1]] = 120;
    C[1][4] = 0;
    C[1][18] = 0;
    C[3][6] = 0;
    C[4][5] = 8;
    C[4][7] = 8;
    C[5][8] = 8;
    C[9][8] = 8;
    C[9][10] = 8;
    C[10][8] = 8;
    C[10][9] = 8;
    C[10][10] = 8;
    C[19][19] = 8;
    C[14][17] = 4;
    C[7][11] = 4;
    C[8][11] = 4;
    C[17][16] = 8;
    C[18][16] = 5;
    C[0][19] = 6;
    C[4][6] = 6;
    C[9][9] = 2;
    C[7][6] = 0;
    C[7][12] = 8;
    C[7][13] = 8;
    C[9][3] = 0;
    C[9][15] = 8;
    C[9][12] = 8;
    C[9][13] = 8;
    C[10][15] = 8;
    C[10][1] = 6;
    C[10][5] = 6;
    C[14][18] = 8;
    C[18][6] = 8;
    C[8][11] = 0;
    C[8][14] = 0;
    C[6][8] = 0;

    for(i = 0; i <= 19; i++)
        C[1][i] = 8;
    for(i = 2; i <= 13; i++)
        C[i][17] = 8;
    for(i = 2; i <= 12; i++)
        C[i][19] = 8;
    for(i = 1; i <= 19; i++)
        C[i][0] = 8;
    for(i = 15; i <= 19; i++)
        C[i][18] = 8;
    for(i = 1; i <= 19; i++)
        C[19][i] = 8;
    for(i = 2; i <= 15; i++)
        C[3][i] = 8;
    for(i = 1; i <= 16; i++)
        C[5][i] = 8;
    for(i = 7; i <= 16; i++)
        C[6][i] = 8;
    for(i = 2; i <= 7; i++)
        C[7][i] = 8;
    for(i = 8; i <= 15; i++)
        C[8][i] = 8;
    for(i = 1; i <= 7; i++)
        C[9][i] = 8;
    for(i = 10; i <= 17; i++)
    {
        C[i][2] = 8;
        C[i][4] = 8;
        C[i][6] = 8;
    }
    for(i = 11; i <= 15; i++)
        C[11][i] = 8;   //J'suis pas sûr de l'emplacement du i et du 15
    for(i = 12; i <= 18; i++)
        C[i][15] = 8;
    C[1][18] = 0;
    C[1][5] = 0;
}


void affiche_tableau() //affichage de la carte (tableau)
{
  int i, j;

  system("clear");	//Effacement de l'écran avant nouvel affichage
  printf("\t vous avez ramasse %d piece,  %d vies restante \n\tVous etes en (%d;%d)\n\t\t", piece, vies, tab[0], tab[1]);

  for (i  =  0; i  <  N; i++)
    {
      for (j  =  0; j  <  M; j++)
        {
	  switch(C[i][j]) {
	  case 120:
	    printf("%sx ", BLEU);
	    break;
	  case 8:
	    printf("%s8 ", ROUGE);
	    break;
	  case 6:
	    printf("%s6 ", JAUNE);
	    break;
	  default:
	    printf("%s0 ", GRIS);
	    break;
	  }
        }
      printf("\n\t\t");
    }
  putchar('\n');

}

int deplace_personnage()
{
    int a;
    printf("Veuillez saisir une direction:\n");
    scanf("%d", &a);

/////////////////////pour le haut//////////////////////

    if (a == 8)
    {
        C[tab[0]][tab[1]] = 0;                //la valeur de la case ou se situe le joueur devient 0.

        if(C[tab[0]-1][tab[1]] == 8)           //dans le cas ou un piege se trouve en haut...
            C[tab[0]][tab[1]] = 120;             //la case situé en haut prend la valeur 1
        else if(C[tab[0]-1][tab[1]] == 4)      //dans le cas ou une pièce se trouve en haut...
        {
            vies--;
            tab[0] = tab[0]-1;
            C[tab[0]][tab[1]] = 120;             //la case situé en haut prend la valeur 1
        }
        else if(C[tab[0]-1][tab[1]] == 6)      //dans le cas ou une pièce se trouve en haut...
        {
            piece++;    //le joueur gagne une piece
            tab[0]--;
            C[tab[0]][tab[1]] = 120;             //la case situé en haut prend la valeur 1
        }
        else if(C[tab[0]-1][tab[1]] == 5)
        {
            //tab[0] = tab[0]-1;
            tab[0]--;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 0;
        }
        else if(C[tab[0]-1][tab[1]] == 2)
        {
            piece += 3;
            tab[0] = tab[0]-1;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 8;
        }
        else if(C[tab[0]-1][tab[1]] == C[tab[0]][0])
            C[tab[0]][tab[1]] = 120;
        else
        {
            tab[0]--;
            C[tab[0]][tab[1]] = 120;             //la case situé en haut prend la valeur 1
        }

    }
/////////////////////pour la gauche////////////////////

    else  if (a == 4)
    {
        C[tab[0]][tab[1]] = 0;                 //la valeur de la case ou se situe le joueur devient 0.

        if(C[tab[0]][tab[1]-1] == 8)           //dans le cas ou un piege se trouve à gauche...
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1
        else if(C[tab[0]][tab[1]-1] == 4)      //dans le cas ou une pièce se trouve à gauche...
        {
            vies--;
            tab[1]--;
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1
        }
        else if(C[tab[0]][tab[1]-1] == 6)      //dans le cas ou une pièce se trouve à gauche...
        {
            piece++;               //le joueur gagne une piece
            tab[1]--;
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1
        }
        else if(C[tab[0]][tab[1]-1] == 5)
        {
            tab[1]--;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 0;
        }
        else if(C[tab[0]][tab[1]-1] == 2)
        {
            piece += 3;
            tab[1]--;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 8;
        }
        else
        {
            tab[1]--;
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1
            printf(" vous avez perdu %d vies \n", vies);//debug
            printf(" vous avez ramasse %d piece \n", piece);
        }
    }

/////////////////////pour la droite ////////////////////

    else  if (a == 6)
    {
        C[tab[0]][tab[1]] = 0;                //la valeur de la case ou se situe le joueur devient 0.
        if(C[tab[0]][tab[1]+1] == 8)          //dans le cas ou un piege se trouve à droite...
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1
        else if(C[tab[0]][tab[1]+1] == 4)     //dans le cas ou une pièce se trouve à droite...
        {
            vies--;
            tab[1]++;
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1
        }
        else if(C[tab[0]][tab[1]+1] == 6)     //dans le cas ou une pièce se trouve à droite...
        {
            piece++;               //le joueur gagne une piece
            tab[1]++;
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1
        }
        else if(C[tab[0]][tab[1]+1] == 5)
        {
            tab[1]++;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 0;
        }
        else if(C[tab[0]][tab[1]+1] == 2)
        {
            piece += 3;
            tab[1]++;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 8;
        }
        else if(C[tab[0]][tab[1]+1] == C[19][tab[1]])
            C[tab[0]][tab[1]] = 120;
        else
        {
            tab[1]++;
            C[tab[0]][tab[1]] = 120;             //la case situé à droite prend la valeur 1

            printf(" vous avez perdu %d vies \n", vies); //debug
            printf(" vous avez ramasse %d piece \n", piece);
        }
    }

/////////////////////pour le bas////////////////////
    else  if (a == 2)
    {
        C[tab[0]][tab[1]] = 0;                //la valeur de la case ou se situe le joueur devient 0.
        if(C[tab[0]+1][tab[1]] == 8)          //dans le cas ou un piege se trouve en bas...
            C[tab[0]][tab[1]] = 120;             //la case situé en bas prend la valeur 1
        else  if(C[tab[0]+1][tab[1]] == 4)    //dans le cas ou une pièce se trouve en bas...
        {
            vies--;
            tab[0]++;
            C[tab[0]][tab[1]] = 120;             //la case situé en bas prend la valeur 1
        }
        else  if(C[tab[0]+1][tab[1]] == 6)    //dans le cas ou une pièce se trouve en bas...
        {
            piece++;
            tab[0]++;
            C[tab[0]][tab[1]] = 120;             //la case situé en bas prend la valeur 1
        }
        else if(C[tab[0]+1][tab[1]] == 5)
        {
            tab[0]++;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 0;
        }
        else if(C[tab[0]+1][tab[1]] == 2)
        {
            piece += 3;
            tab[0]++;
            C[tab[0]][tab[1]] = 120;
            C[9][10] = 8;
        }
        else
        {
            tab[0]++;
            C[tab[0]][tab[1]] = 120;             //la case situé en bas prend la valeur 1
            printf(" vous avez perdu %d vies \n", vies); //debug
            printf(" vous avez ramasse %d piece \n", piece);
        }
    }

    else if (a == 0)
      return 42;
    else
        printf("error,  veuillez saisir une direction correcte.");
    return 0;
}

void game_win()
{
    if(piece > 3)
    {
        system("clear");

        printf ("%s ________  _______  __   __  _______ \n", JAUNE );
        printf ("%s|        ||   _   ||  |_|  ||       |\n", JAUNE );
        printf ("%s|    ____||  | |  ||       ||    ___|\n", JAUNE );
        printf ("%s|   |  __ |  |_|  ||       ||   |___ \n", JAUNE );
        printf ("%s|   | |  ||       ||       ||    ___|\n", JAUNE );
        printf ("%s|   |__| ||   _   || ||_|| ||   |___ \n", JAUNE );
        printf ("%s|________||__| |__||_|   |_||_______|\n", JAUNE );
        printf ("%s ___           ___   ___   ___    __ \n", JAUNE );
        printf ("%s|   |   ___   |   | |___| |   |  |  |\n", JAUNE );
        printf ("%s|    |_|   |_|    |  ___  |    | |  |\n", JAUNE );
        printf ("%s |               |  |   | |     ||  |\n", JAUNE );
        printf ("%s  |      _      |   |   | |  ||  |  |\n", JAUNE );
        printf ("%s   |    | |    |    |   | |  | |    |\n", JAUNE );
        printf ("%s    |__|   |__|     |___| |__|  |___|%s\n", JAUNE,  NORMAL );
    }
}
void game_over()
{
    if (vies < 1)
    {
        system("clear");

        printf ("%s _______  _______  __   __  _______ \n", ROUGE );
        printf ("%s|       ||   _   ||  |_|  ||       |\n", ROUGE );
        printf ("%s|    ___||  |_|  ||       ||    ___|\n", ROUGE );
        printf ("%s|   | __ |       ||       ||   |___\n", ROUGE );
        printf ("%s|   ||  ||       ||       ||    ___|\n", ROUGE );
        printf ("%s|   |_| ||   _   || ||_|| ||   |___ \n", ROUGE );
        printf ("%s|_______||__| |__||_|   |_||_______|\n", ROUGE );
        printf ("%s _______  __   __  _______  ______  \n", ROUGE );
        printf ("%s|       ||  | |  ||       ||    _ | \n", ROUGE );
        printf ("%s|   _   ||  |_|  ||    ___||   | || \n", ROUGE );
        printf ("%s|  | |  ||       ||   |___ |   |_|| \n", ROUGE );
        printf ("%s|  |_|  ||       ||    ___||    __ |\n", ROUGE );
        printf ("%s|       | |     | |   |___ |   |  ||\n", ROUGE );
        printf ("%s|_______|  |___|  |_______||___|  ||%s\n", ROUGE,  NORMAL);
    }
}

#include <termios.h>

static struct termios   save_termios;
static int              term_saved;

int tty_raw(int fd) {       // RAW! mode
    struct termios  buf;

    if (tcgetattr(fd, &save_termios) < 0) // get the original state
        return -1;

    buf = save_termios;

    buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
                    // echo off, canonical mode off, extended input
    //                       processing off, signal chars off

    buf.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON);
                    // No SIGINT on BREAK, CR-toNL off, input parity
    //                    check off, don't strip the 8th bit on input,
    //                 ouput flow control off

    //buf.c_cflag &= ~(CSIZE | PARENB);
                    // clear size bits, parity checking off

    //    buf.c_cflag |= CS8;
                    // set 8 bits/char

    //    buf.c_oflag &= ~(OPOST);
                    //output processing off

    buf.c_cc[VMIN] = 1;  // 1 byte at a time
    buf.c_cc[VTIME] = 0; // no timer on input

    if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
        return -1;

    term_saved = 1;

    return 0;
}


int tty_reset(int fd) { // set it to normal!
    if (term_saved)
        if (tcsetattr(fd, TCSAFLUSH, &save_termios) < 0)
            return -1;

    return 0;
}

int main()
{
    if (intro() != 0)
    {
      tty_raw(1);

        def_tableau();
        affiche_tableau();

        while((vies > 0) && (piece < 4))
	  {
	    if (deplace_personnage() == 42)
	      break;
            affiche_tableau();
	    usleep(100);
	  }
    }

    tty_reset(1);

    game_over();
    game_win();
    printf("%s", NORMAL);
    system("clear");

    return 0;
}
