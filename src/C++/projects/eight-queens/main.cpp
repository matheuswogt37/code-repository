#include <iostream>
#include <memory>

class Queen {
    public:
        int x;
        int y;
        void setCoords(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

void showMatrix(std::unique_ptr<std::unique_ptr<int[]>[]>& matrix, std::unique_ptr<Queen[]>& queens) {
    // put the Queens on matrix positions like 9 char
    for (int i = 0; i < 8; i++) {
        matrix[queens[i].y][queens[i].x] = 9;
    }
    
    std::cout << "\n*when appear '9' it's a queen position";
    
    std::cout << "\nMATRIX POSITIIONS\n";
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            std::cout << " " << matrix[j][i];
        }
        std::cout << "\n";
    }
    std::cout << "-----------------\n";
    
    std::cout << "Queen's positions:\n";
    for (int i = 0; i < 8; i++) {
        std::cout << (i + 1) << " queen -> " << queens[i].x + 1 << ", " << queens[i].y + 1 << "\n";
    }

    std::cout << "-----------------\n";
}

void addQueen(std::unique_ptr<std::unique_ptr<int []>[]>& matrix, int x, int y) {
    int i, j;
    
    // make the cords add
    // horizontal
    for (i = 0; i < 8; i++) {
        matrix[y][i]++;
    }

    // vertical
    for (j = 0; j < 8; j++) {
        matrix[j][x]++;
    }

    // diagonal right up
    j = y - 1;
    i = x + 1;
    while(j > -1 && i < 8) {
        matrix[j][i]++;
        j--;
        i++;
    }

    // diagonal right down
    j = y + 1;
    i = x + 1;
    while(j < 8 && i < 8) {
        matrix[j][i]++;
        j++;
        i++;
    }

    // diagonal left up
    j = y - 1;
    i = x - 1;
    while(j > -1 && i > -1) {
        matrix[j][i]++;
        j--;
        i--;
    }

    // diagonal left down
    j = y + 1;
    i = x - 1;
    while(j < 8 && i > -1) {
        matrix[j][i]++;
        j++;
        i--;
    }
}

void remQueen(std::unique_ptr<std::unique_ptr<int []>[]>& matrix, int x, int y) {
    int i, j;
    
    // make the cords add
    // horizontal
    for (i = 0; i < 8; i++) {
        matrix[y][i]--;
    }

    // vertical
    for (j = 0; j < 8; j++) {
        matrix[j][x]--;
    }

    // diagonal right up
    j = y - 1;
    i = x + 1;
    while(j > -1 && i < 8) {
        matrix[j][i]--;
        j--;
        i++;
    }

    // diagonal right down
    j = y + 1;
    i = x + 1;
    while(j < 8 && i < 8) {
        matrix[j][i]--;
        j++;
        i++;
    }

    // diagonal left up
    j = y - 1;
    i = x - 1;
    while(j > -1 && i > -1) {
        matrix[j][i]--;
        j--;
        i--;
    }

    // diagonal left down
    j = y + 1;
    i = x - 1;
    while(j < 8 && i > -1) {
        matrix[j][i]--;
        j++;
        i--;
    }
}

bool backtrackingRecursive (std::unique_ptr<std::unique_ptr<int []>[]>& matrix, std::unique_ptr<Queen[]>& queens, int actQueen, int initX, int initY){
    int x = initX;
    int y = initY;

    while(y < 8) {
        while (x < 8) {
            // check if this position are available, if then put one queen on this and try put another on other position, if gets wrong then put this queen on another position
            if (matrix[y][x] == 0) { // position available
                queens[actQueen].setCoords(x, y);
                addQueen(matrix, x, y);
                actQueen++;
                if (8 == actQueen) {
                    return true;
                }
                if (backtrackingRecursive(matrix, queens, actQueen, 1, 1)) { // if backtracking is activated //DEV check if i can use x and y instead 1, 1
                    return true;
                }
                remQueen(matrix, x, y);
                actQueen--;
            }
            x++;
        }
        x = 0;
        y++;
    }
    return false;
}

bool backtracking(std::unique_ptr<std::unique_ptr<int []>[]>& matrix, std::unique_ptr<Queen[]>& queens, int allQueens) {
    int initX = 1;
    int initY = 1;
    int actQueen = 1;

    return backtrackingRecursive(matrix, queens, (actQueen - 1), (initX - 1), (initY - 1));
}

int main() {
    bool res;
    // table 
    std::unique_ptr<std::unique_ptr<int[]>[]> matrixPos(new std::unique_ptr<int[]>[8]);
    for (int i = 0; i < 8; i++) {
        matrixPos[i] = std::unique_ptr<int[]>(new int[8]);
    }
    // queen's
    std::unique_ptr<Queen[]> queens(new Queen[8]);

    // populate with 0's
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            matrixPos[j][i] = 0;
        }
    }

    res = backtracking(matrixPos, queens, 8);
    if (res) {
        std::cout << "SUCCESSFULL\n";
        showMatrix(matrixPos, queens);
    } else {
        std::cout << "FAILED\n";
    }
    
    // free matrixPos
    for (int i = 0; i < 8; i++) {
        matrixPos[i].reset();
    }
    matrixPos.reset();

    // free queen
    queens.reset();


    return 0;
}