#include <stdio.h>

void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---------\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}
int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
int makeMove(char board[3][3], int player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = (player == 1) ? 'X' : 'O';
        return 1;
    }
    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    int player = 1; 
    int gameOver = 0;

    printf("Welcome to Tic Tac Toe!\n");

    while (!gameOver) {
        displayBoard(board);

        printf("Player %d (%c), enter your move (row and column): ", player, (player == 1) ? 'X' : 'O');
        scanf("%d %d", &row, &col);

        row--; col--;

        if (!makeMove(board, player, row, col)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (checkWinner(board)) {
            displayBoard(board);
            printf("Player %d (%c) wins!\n", player, (player == 1) ? 'X' : 'O');
            gameOver = 1;
        }
        else if (isBoardFull(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            gameOver = 1;
        }
        
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
