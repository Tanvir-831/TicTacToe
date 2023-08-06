#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void drawBoard() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2)
                printf("|");
        }
        printf("\n");
        if(i < 2)
            printf("---+---+---\n");
    }
}

int checkWin() {
    int i;
    for(i = 0; i < 3; i++) {
        if((board[i][0] == board[i][1] && board[i][0] == board[i][2]) && board[i][0] != ' ')
            return 1;
        if((board[0][i] == board[1][i] && board[0][i] == board[2][i]) && board[0][i] != ' ')
            return 1;
    }
    if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) && board[0][0] != ' ')
        return 1;
    if((board[0][2] == board[1][1] && board[0][2] == board[2][0]) && board[0][2] != ' ')
        return 1;
    return 0;
}

void initBoard() {
    int i, j;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            board[i][j] = ' ';
}

int main() {
    int player = 0;
    int i, row, col;
    char mark;
    initBoard();
    do {
        drawBoard();
        player = player % 2 + 1;
        mark = (player == 1) ? 'X' : 'O';
        do {
            printf("Player %d, enter a row and column number: ", player);
            scanf("%d %d", &row, &col);
            row--; col--;
            if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                printf("Invalid move! Try again.\n");
            } else {
                break;
            }
        } while(1);
        board[row][col] = mark;
        i = checkWin();
    } while(i == 0);
    drawBoard();
    printf("Player %d wins!\n", player);
    return 0;
}
