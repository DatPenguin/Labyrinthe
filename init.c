#include <stdio.h>
#include <stdlib.h>
#include "header.h"

extern int piece;
extern int vies;
extern int tab[2];
extern int C[N][M];

char intro()
{
    char digit = 0;

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
    scanf("%c", &digit);
    return digit;
}


void def_tableau()
{
    int i = 0;

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
        C[11][i] = 8;
    for(i = 12; i <= 18; i++)
        C[i][15] = 8;
    C[1][18] = 0;
    C[1][5] = 0;
    C[11][17] = 0;
    C[5][6] = 8;
    C[9][7] = 8;
    //Ouvertes par la clef
    C[3][6] = 9;
    C[15][15] = 9;
    C[5][1] = 9;
    C[9][3] = 9;

    //Pieces

    C[13][8] = 6;
    C[15][8] = 6;
    C[17][8] = 6;
    C[13][10] = 6;
    C[15][10] = 6;
    C[17][10] = 6;
    C[11][6] = 0;
    C[10][9] = 0;
    C[19][19] = 3;

    //Pieges
    C[12][8] = 4;
    C[14][8] = 4;
    C[16][8] = 4;
    C[12][10] = 4;
    C[14][10] = 4;
    C[16][10] = 4;
    C[12][12] = 4;
    C[14][12] = 4;
    C[16][12] = 4;
    C[13][9] = 1;
}
