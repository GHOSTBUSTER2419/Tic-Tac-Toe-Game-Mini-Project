
/*
-----------------------------------------
Akshat Charde: Program Overview & Global Setup
-----------------------------------------
*/
#include <stdio.h>


char board[3][3];        
char currentPlayer;     


void initializeBoard();
void printBoard();
int checkWin();
int checkDraw();
void switchPlayer();


  /*
    -----------------------------------------
    Akshat Charde: Main Function & Game Flow
    -----------------------------------------
    */
int main() 
{

    int row, col;
    int status = 0; // 0 = continue, 1 = win, 2 = draw

    initializeBoard();
    currentPlayer = 'X';

    printf("--- Tic Tac Toe Game ---\n");

    while (status == 0) {

        printBoard();

        /*
        -----------------------------------------
        Achyut Bhaskar: Input Handling & Validation
        -----------------------------------------
        */

        printf("Player %c's turn. Enter row (1-3) and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {

            board[row][col] = currentPlayer;

            /*
            -----------------------------------------
            Namish Sreshth: Win & Draw Logic
            -----------------------------------------
            */

            if (checkWin()) {
                status = 1;
            }
            else if (checkDraw()) {
                status = 2;
            }
            else {


                switchPlayer();
            }
        }
        else {
            printf("Invalid move! Try again.\n");
        }
    }

    printBoard();

    if (status == 1) {
        printf("Congratulations! Player %c wins!\n", currentPlayer);
    }
    else {
        printf("It's a Draw!\n");
    }

    return 0;
}

/*
-----------------------------------------
Dhruv Singh: Board Initialization
-----------------------------------------
*/

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

/*
-----------------------------------------
Dhruv Singh: Board Display
-----------------------------------------
*/

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/*
-----------------------------------------
Namish Sreshth: Win Checking Logic
-----------------------------------------
*/
int checkWin() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return 1;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return 1;
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return 1;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return 1;

    return 0;
}

/*
-----------------------------------------
Namish Sreshth: Draw Checking
-----------------------------------------
*/

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

/*
-----------------------------------------
Krrish Purabiya: Player Switching + Testing
-----------------------------------------
*/

void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}
