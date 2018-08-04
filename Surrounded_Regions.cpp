/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/



#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char>>& board);
void DFS_changeBorders(vector<vector<char> >&board, int &height, int &width);
void changeInnerO(vector<vector<char> >&board, int &height, int &width);
void changeOuterO(vector<vector<char> >&board, int &height, int &width);
void flip(vector<vector<char> >&board, int row, int col, int &height, int &width);

int main() {
    vector<vector<char>> map1 = {{'X','X','X','X'},
                               {'X','O','O','X'},
                                {'X','X','O','X'},
                               {'X','O','X','X'}};
    cout << "Region:\n";
    for (int row = 0; row < map1.size(); row++) {
        cout << "     ";
        for (int col = 0; col < map1[row].size(); col++) {
            cout << map1[row][col] << " ";
        }
        cout << "\n";
    }
    solve(map1);
    cout << "Post Flip:\n";
    for (int row = 0; row < map1.size(); row++) {
        cout << "     ";
        for (int col = 0; col < map1[row].size(); col++) {
            cout << map1[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n\n";


    vector<vector<char>> map2 = {{'O','O','O','O'},
                               {'O','O','O','X'},
                                {'O','O','O','X'},
                               {'O','O', 'O','X'}};
    cout << "Region:\n";
    for (int row = 0; row < map2.size(); row++) {
        cout << "     ";
        for (int col = 0; col <map2[row].size(); col++) {
            cout << map2[row][col] << " ";
        }
        cout << "\n";
    }
    solve(map2);
    cout << "Post Flip:\n";
    for (int row = 0; row < map2.size(); row++) {
        cout << "     ";
        for (int col = 0; col < map2[row].size(); col++) {
            cout << map2[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n\n";



    return 0;
}


//step 1: if any O's are connected to border as an island, change to '-'
//step 2: change every existing O in the board to X
//step 3: change all '-' back to 'O'
void solve(vector<vector<char>> &board) {
    if (board.empty())
        return;
    
    int height = board.size();
    int width = board[0].size();

    DFS_changeBorders(board, height, width); //step 1
    changeInnerO(board, height, width); //step 2
    changeOuterO(board, height, width); //step 3
    
}

void DFS_changeBorders(vector<vector<char> >&board, int &height, int &width) {
    for (int row = 0; row < height; row++) {
        flip(board, row, 0, height, width);     //left border
        if (width > 1)
            flip(board, row, width - 1, height, width);  //right border
    }

    for (int col = 1; col < width; col++) {
        flip(board, 0, col, width, height);         //top border
        if (height > 1)
            flip(board, height - 1, col, height, width);        //bottom border
    }
}

void changeInnerO(vector<vector<char> >&board, int &height, int &width) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (board[row][col] == 'O')
                board[row][col] = 'X';
        }
    }
}

void changeOuterO(vector<vector<char> >&board, int &height, int &width) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (board[row][col] == '-')
                board[row][col] = 'O';
        }
    }
}



//Depth-first search to flip as needed
void flip(vector<vector<char> >&board, int row, int col, int &height, int &width) {
    if (board[row][col] == 'O') {
        board[row][col] = '-';
        if (row > 1)
            flip(board, row - 1, col, height, width);
        if (col > 1)
            flip(board, row, col - 1, height, width);
        if (row + 1 < height)
            flip(board, row + 1, col, height, width);
        if (col + 1 < width)
            flip(board, row, col + 1, height, width);
        
    }
}