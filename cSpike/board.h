#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H

#include <iostream>
#include <string>

using namespace std;

class boardType {
   public:
   
    // constructor
    boardType(std::string);

    // overload the stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const boardType& dt);
 
    //private:
        int board[3][3];

};

boardType::boardType(std::string argv) {

    // fill initial board from argv
    // assumes valid array of integers
    int iPos = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = argv[iPos++] - '0' ;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const boardType& thisBoard) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            os << thisBoard.board[r][c] << ' ';
        }
        std::cout << std::endl;
    }
    return os;
}

void fillTestBoard(int solvable[], int arg){
    //separate the board into individual integers in an array

    int a = arg / 100000000 % 10;
    int b = arg / 10000000 % 10;
    int c = arg / 1000000 % 10;
    int d = arg / 100000 % 10;
    int e = arg / 10000 % 10;
    int f = arg / 1000 % 10;
    int g = arg / 100 % 10;
    int h = arg / 10 % 10;
    int i = arg % 10;

    solvable[0] = a;
    solvable[1] = b;
    solvable[2] = c;
    solvable[3] = d;
    solvable[4] = e;
    solvable[5] = f;
    solvable[6] = g;
    solvable[7] = h;
    solvable[8] = i;
}

std::string testBoard(int solvable[]){
    std::string isSolvable;
    int inversionCount = 0;

    //nested loop that starts with an element of the array, goes through each element after it, and if there is an inversion it increases the inversion count
    for (int i = 0; i <= 8; i++){
        for(int j = (i+1); j <= 8; j++){
            if(solvable[i] > solvable[j] && solvable[j] != 0){
                inversionCount++;
            }
        }
    }

    //if inversions are even, it is solvable, if they are odd, it isn't
    if (inversionCount % 2 == 0){
        isSolvable = "True";
    }
    else{
        isSolvable = "False";
    }
    return isSolvable;
    }

void findMoves(boardType thisBoard){
    
    int row;
    int col;

    //find position of the zero
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if(thisBoard.board[r][c] == 0){
                row = r;
                col = c;
            }
        }
    }

    cout << endl;
    cout << "Valid Moves:" << endl;

    //up
    if(row + 1 != 3){
        cout << "(" << row + 1 << "," << col << ")" << "->" << "(" << row << "," << col << ")" << endl;
    }

    //down
    if(row - 1 != -1){
        cout << "(" << row - 1 << "," << col << ")" << "->" << "(" << row << "," << col << ")" << endl;
    }

    //left
    if(col + 1 != 3){
        cout << "(" << row << "," << col + 1 << ")" << "->" << "(" << row << "," << col << ")" << endl;
    }
    
    //right
    if(col - 1 != -1){
        cout << "(" << row << "," << col - 1 << ")" << "->" << "(" << row << "," << col << ")" << endl;
    }
}

#endif