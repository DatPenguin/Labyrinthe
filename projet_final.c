#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

#define M 20
#define N 20

int piece = 0;
int vies = 3;
int tab[2];
int C[N][M]  =  {{0}};

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

/* #include <termios.h> */

/* static struct termios   save_termios; */
/* static int              term_saved; */

/* int tty_raw(int fd) {       // RAW! mode */
/*     struct termios  buf; */

/*     if (tcgetattr(fd, &save_termios) < 0) // get the original state */
/*         return -1; */

/*     buf = save_termios; */

/*     buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG); */
/*                     // echo off, canonical mode off, extended input */
/*     //                       processing off, signal chars off */

/*     buf.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON); */
/*                     // No SIGINT on BREAK, CR-toNL off, input parity */
/*     //                    check off, don't strip the 8th bit on input, */
/*     //                 ouput flow control off */

/*     //buf.c_cflag &= ~(CSIZE | PARENB); */
/*                     // clear size bits, parity checking off */

/*     //    buf.c_cflag |= CS8; */
/*                     // set 8 bits/char */

/*     //    buf.c_oflag &= ~(OPOST); */
/*                     //output processing off */

/*     buf.c_cc[VMIN] = 1;  // 1 byte at a time */
/*     buf.c_cc[VTIME] = 0; // no timer on input */

/*     if (tcsetattr(fd, TCSAFLUSH, &buf) < 0) */
/*         return -1; */

/*     term_saved = 1; */

/*     return 0; */
/* } */


/* int tty_reset(int fd) { // set it to normal! */
/*     if (term_saved) */
/*         if (tcsetattr(fd, TCSAFLUSH, &save_termios) < 0) */
/*             return -1; */

/*     return 0; */
/* } */

int main()
{
    if (intro() != 0)
    {
      /* tty_raw(1); */

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

    /* tty_reset(1); */

    game_over();
    game_win();
    printf("%s", NORMAL);
    system("clear");

    return 0;
}
