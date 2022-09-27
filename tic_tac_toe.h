#pragma once

#define First_player 'X'
#define Second_player 'O'

bool isCellFree(int cell);
void place(int cell);
void change_player();
void board();
int chartoint( int choice);
bool row_win();
bool column_win();
bool diagonal_win();
bool full();
int check();
void play();

