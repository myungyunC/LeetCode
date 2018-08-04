/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3


*/

#include <iostream>
#include <vector>

using namespace std;

int numIslands(vector<vector<char>>& grid);
int findIsland(vector<vector<char>> &grid, int row, int col);
bool invalid(vector<vector<char>> &grid, int row, int col);

int main() {
    vector<vector<char>> map1 = {{'1','1','1','1','0'},
                               {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                               {'0','0','0','0','0'}};
    cout << "Map:\n";
    for (int row = 0; row < map1.size(); row++) {
        cout << "     ";
        for (int col = 0; col < map1[row].size(); col++) {
            cout << map1[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "Number of Islands: " << numIslands(map1) << endl;


    vector<vector<char>> map2 = {{'1','1','0','0','0'},
                               {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                               {'0','0','0','1','1'}};
    cout << "\n\nMap:\n";
    for (int row = 0; row < map2.size(); row++) {
        cout << "     ";
        for (int col = 0; col < map2[row].size(); col++) {
            cout << map2[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "Number of Islands: " << numIslands(map2) << endl;


    return 0;
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
        return 0;


    int width = grid[0].size();
    int height = grid.size();
    
    vector<int> islands;
    
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int island = findIsland(grid, row, col);
            if (island > 0) {
                islands.push_back(island);
            }
                
        }
    }
    
    return islands.size();
}

int findIsland(vector<vector<char>> &grid, int row, int col) {
    if (invalid(grid, row, col))
        return 0;
    

    int size = 1; //the current cell
    grid[row][col] = 'v'; //visited
    
    //top
    size += findIsland(grid, row - 1, col);
    //right
    size += findIsland(grid, row, col + 1);
    //bottom
    size += findIsland(grid, row + 1, col);
    //left
    size += findIsland(grid, row, col - 1);

    return size;
}

bool invalid(vector<vector<char>> &grid, int row, int col) {
    if (row < 0 || 
        col < 0 || 
        row >= grid.size() || 
        col >= grid[0].size() ||
        grid[row][col] != '1')        //checks for edges, if it's not an island (0), or if it's visited (-1)
        return true;
    return false;
} 
