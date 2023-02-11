#include <stdio.h>

void display_board(char board[][3]);
int if_full(char board[][3]);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    display_board(board);
    return 0;
}

void display_board(char board[][3]) {
    int i, j;
    printf("     1   2   3\n");
    for(i = 0; i < 3; i++) {
        printf("   +---+---+---+\n%d  ", i+1);
        for(j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   +---+---+---+\n");
}

int if_full(char board[][3]) {
    
}