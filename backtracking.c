#include <stdio.h>
#include <stdlib.h>

#define TOTALWITHBORDER 10*10
#define BOARD_N 10

int board[TOTALWITHBORDER];
 // What are the rules for lines and diagonals?

int printboard(int board[]){
    size_t pos = 0;
    for (size_t i = 0; i < 10; ++i){
        for (size_t j = 0; j < 10; ++j){
            if (board[pos] != 0 && board[pos] != -1)
                printf(" Q ");
            else if (board[pos] == -1){
                printf(".  ");
            }
            else{
                printf("| |");
            }
            pos+=1;
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

int addedges(int* board){
    size_t pos = 0;
    for (size_t i = 0; i < 10; ++i){
        *(board+(i-1)) = -1;
        *(board+pos) = -1;
        *(board+(pos+9)) = -1;
        *(board+((TOTALWITHBORDER)-i-1)) = -1;
        for (size_t j = 0; j < 10; ++j){
            pos+=1;
        }
    }
    return EXIT_SUCCESS;
}


// Add a queen to the board in the n position.
// Add another one in n1, not haning to the n0 queen, 
// not in the n0 queen moves

enum Moves {
    KMoves, 
    QMoves
};

int addqueen(int* board, int pos){

    if (*(board+pos) == -1 || *(board+pos) == 1){
        return EXIT_FAILURE; // can´t insert in the edge or somewhere hanging
    }


    // Lines
    // top
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i-BOARD_N){

        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }
    // bottom
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i+BOARD_N){
        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }
    // right
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i+1){
        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }
    // left
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i-1){
        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }

    // Diagonals
    // top right
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i-(BOARD_N-1)){
        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }
    // top left
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i-(BOARD_N+1)){
        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }
    // bottom right
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i+(BOARD_N-1)){
        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }
    // bottom left
    for (int pos_i = pos; (pos_i < TOTALWITHBORDER && *(board+pos_i) != -1); pos_i=pos_i+(BOARD_N+1)){
        if (*(board+pos_i) != -1) // Don't change the -1 edges
            *(board+pos_i) = QMoves;
    }
    return EXIT_SUCCESS;
}




// Store the positions of the last queens inserted
// The number of queens, (if no movement is possible and the Qn < 9, then it is not a solution
// Remove the last, insert (Qn - 1) in, and now the Qn position is position(n-1) + 1, if then not solution is found
// Remove the two lasts, insert (Qn -2) in the new positions position(n-2) + 1 ....
int main(void){
    addedges(&board[0]);

    addqueen(&board[0], 45);

    printboard(&board[0]);

    return EXIT_SUCCESS;
}