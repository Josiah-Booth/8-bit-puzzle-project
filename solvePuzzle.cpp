// test executions
// solvePuzzle 182043765 
// solvePuzzle 812043765

#include <iostream>
#include <stdlib.h>
#include <string>

#include "board.h"

int main(int argc, char* argv[]) {
 
    if (argc < 2) {
        std::cout << "Usage: solvePuzzle initalBoard " << std::endl;
        return -1;
    }

    boardType initialBoard(argv[1]);
    boardType goalBoard("123456780");

    std::cout << "initial: " << std::endl;
    std::cout << initialBoard << std::endl;

    std::cout << "goal: " << std::endl;
    std::cout << goalBoard << std::endl;

    //convert commmand line argument to an integer and create an empty array
    long int arg = strtol(argv[1], NULL, 0);
    int solvable[8];

    //separate the integer into individual digits and add them to the array
    fillTestBoard(solvable, arg);

    std::cout << "solvable: " << std::endl;
    std::cout << testBoard(solvable) << std::endl;

    return 0;
}
