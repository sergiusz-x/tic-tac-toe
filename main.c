#include <stdio.h>

struct position {
    int x, y;
};

void display_board(char board[][3]);
int if_full(char board[][3]);
void ask_for_position(struct position *pos, char board[][3], char player);
char if_end(char board[][3]);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    // display_board(board);
    //
    int row, column;
    char player = 'X';
    struct position pos;
    //
    while(!if_full(board)) {
        display_board(board);
        ask_for_position(&pos, board, player);
        board[pos.x-1][pos.y-1] = player;
        //
        if(if_end(board) != ' ') {
            printf("Koniec");
            return 0;
        }
        //
        if(player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    //
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
    int counter = 0, i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] != ' ') {
                counter++;
            }
        }
    }
    //
    return counter == 9;
}

void ask_for_position(struct position *pos, char board[][3], char player) {
    int x, y;
    printf("Player %c select row: ", player);
    scanf("%d", &x);
    //
    printf("Player %c select column: ", player);
    scanf("%d", &y);
    //
    if(x < 1 || x > 3 || y < 1 || y > 3) {
        printf("Invalid numbers, please try again...\n");
        return ask_for_position(pos, board, player);
    }
    //
    if(board[x-1][y-1] != ' ') {
        printf("This position is already taken, please try again...\n");
        return ask_for_position(pos, board, player);
    }
    //
    pos -> x = x;
    pos -> y = y;
}

char if_end(char board[][3]) {
    int i;
    //
    // Rows
    for(i = 0; i < 3; i++) {
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) return board[i][0];
    }
    //
    // Columns
    for(i = 0; i < 3; i++) {
        if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) return board[0][i];
    }
    //
    // Diagonal
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) return board[0][0];
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) return board[0][2];
    //
    //
    return ' ';
}

