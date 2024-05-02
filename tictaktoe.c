#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMP = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char Winner = ' ';

    resetBoard();

    while (Winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();

        playerMove();
        Winner = checkWinner();
        if (Winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }

        computerMove();
        Winner = checkWinner();
        if (Winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();
    printWinner(Winner);

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void computerMove()
{
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMP;
    }
    else
    {
        printWinner(' ');
    }
}
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("wprowadz kolumne #(1-3): ");
        scanf("%d", &x);
        printf("wprowadz rzad #(1-3): ");
        scanf("%d", &y);

        x--;
        y--;

        if (x < 0 || x > 2 || y < 0 || y > 2)
        {
            printf("Nieprawidlowe koordynaty! Wprowadz ponownie.\n");
            continue;
        }

        if (board[x][y] != ' ')
        {
            printf("To pole jest juz zajete! Wprowadz ponownie.\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }

    } while (1);
}


char checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][0] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}
void printWinner(char Winner)
{
    if (Winner == PLAYER)
    {
        printf("gracz wygral!");
    }
    else if (Winner == COMP)
    {
        printf("komputer wygral!");
    }
    else
    {
        printf("jest remis!");
    }
}
