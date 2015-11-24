#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include <signal.h>
#include <termios.h>

int piece = 0;
int vies = 3;
int tab[2];
int C[N][M]  =  {{0}};

void affiche_tableau(int status) //affichage de la carte (tableau)
{
  int i, j;

  system("clear");	//Effacement de l'écran avant nouvel affichage
  if (status == 0)
    print_status();
  if(DEBUG)
    printf("\n%sDEBUG: Vous etes en (%d,%d)%s\n", LIGHT_VERT, tab[0], tab[1], NORMAL);

  for (i  =  0; i  <  N; i++)
    {
      for (j  =  0; j  <  M; j++)
        {
	  switch(C[i][j]) {
	  case 120:
	    printf("%sx ", BLEU);
	    break;
	  case 8:
	    printf("%s8 ", LIGHT_ROUGE);
	    break;
	  case 6:
	    printf("%s6 ", JAUNE);
	    break;
	  case 5:
	    printf("%s5 ", LIGHT_VERT);
	    break;
	  case 42:
	    printf("%s9 ", VERT);
	    break;
	  default:
	    printf("%s0 ", LIGHT_GRIS);
	    break;
	  }
        }
      printf("\n");
    }
  putchar('\n');

}

int deplace_personnage(int a)
{
  //int a;
  //printf("%sVeuillez saisir une direction:\n", NORMAL);
    //scanf("%d", &a);

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
        }
    }

    else if (a == 0)
      return 42;
    else
      {
        printf("Veuillez saisir une direction correcte (2, 4, 6, 8)\n");
	return -1;
      }
    return 0;
}

void print_status()
{
  printf("\tVous avez perdu %d vies\n", vies);
  printf("\tVous avez ramasse %d pieces", piece);
  return;
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

struct termios oldtermios;

int tty_raw(int fd)
{
  struct termios newtermios;
  if (tcgetattr(fd, &oldtermios) < 0)
    return -1;
  newtermios = oldtermios;

  newtermios.c_lflag &= ~(ECHO | ICANON | IEXTEN);

  newtermios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

  newtermios.c_cflag &= ~(CSIZE | PARENB);

  newtermios.c_cflag |= CS8;
  newtermios.c_oflag &= ~(OPOST);

  newtermios.c_cc[VMIN] = 1;
  newtermios.c_cc[VTIME] = 0;

  if (tcsetattr(fd, TCSAFLUSH, &newtermios) < 0)
    return -1;
  return 0;

}

int tty_reset(int fd)
{
  if (tcsetattr(fd, TCSAFLUSH, &oldtermios) < 0)
    return -1;
  return 0;
}

void sigcatch(int sig)
{
  tty_reset(0);
  exit(0);
}

int main()
{
    if (intro() != 0)
    {
      if (tty_raw(0) < 0)
	{
	  fprintf(stderr, "BUG\n");
	  exit(1);
	}

      int status = 0;
      char a;
      int i = 0;

      def_tableau();
      affiche_tableau(0);

      while((vies > 0) && (piece < 4) && (i = read(0, &a, 1) == 1))
	{
	  status = deplace_personnage(a);
	  if (status == 42)
	    break;
	  else if (status == -1)
	    printf("Veuillez saisir une direction correcte");
	  affiche_tableau(status);
	  usleep(100);
	}
    
    tty_reset(0);

    game_over();
    game_win();
    printf("%s", NORMAL);
    system("clear");
    }
    return 0;
}
