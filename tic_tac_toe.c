#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include"tic_tac_toe.h"


char player=First_player;

char bb[3][3]=
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

bool isCellFree(int cell)
{

    int row = cell / 3;
    int column = cell % 3;

    bool is_free= (bb[row][column] != First_player && bb[row][column] != Second_player);

    return is_free;
}

void place(int cell)
{

    int row = cell / 3;
    int column = cell % 3;

    bb[row][column] = player;
}

void change_player()
{
    if(player == First_player)
        player = Second_player;
    else player = First_player;

}

void board()
{

    printf("\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",bb[0][0],bb[0][1],bb[0][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",bb[1][0],bb[1][1],bb[1][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",bb[2][0],bb[2][1],bb[2][2]);
    printf("   |   |   \n");
}

int chartoint( int choice)
{
    return choice-48;
}

bool row_win()
{
    for(int i=0; i< 3; i++)
    {
        if( bb[i][0] == bb[i][1] && bb[i][1] == bb[i][2])
        {
            printf(" *** %c , you won on row %d! *** ", player, i+1);
            return true;
        }
    }
    return false;
}

bool column_win()
{
    for(int i=0; i<3; i++)
    {
        if (bb[0][i] == bb[1][i] && bb[1][i] == bb[2][i])
        {
            printf(" *** %c , you won on column %d! *** ", player, i+1);
            return true;
        }
    }
    return false;
}

bool diagonal_win()
{
    if(bb[0][0] == bb[1][1] && bb[1][1] == bb[2][2])
    {
        printf(" *** %c , you won on the main diagonal! *** ", player);
        return true;
    }
    if(bb[0][2] == bb[1][1] && bb[1][1] == bb[2][0])
    {
        printf(" *** %c , you won on the secondary diagonal! *** ",player);
        return true;
    }
    return false;
}

bool full()
{
    for(int i=0; i<3 ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (bb[i][j] != First_player && bb[i][j]!= Second_player )
                return false;
        }
    }
    printf(" *** You both lost! *** ");
    return true;

}

int check()
{
    bool over = row_win() || column_win() || diagonal_win() || full();
    return over;
}
void play(){
    int game_over=0;
    char choice;
    int integer_choice;

    do
    {
        ///we draw the board
        board();
        ///let the current payer choose the cell
        printf("%c choose the cell: \n",player);

        choice=getch();
        integer_choice = chartoint(choice)-1;
        system("cls");
        if(isCellFree(integer_choice))
        {
            place(integer_choice);

            game_over = check();
            change_player();
        }

    }
    while(!game_over);
    board();
}
