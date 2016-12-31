/** 
 * Find the shortest path from (0, 0) to exit (x, y) in  a maze 
 */  
#include <iostream>  
#include <vector>  
#include <queue>  
using namespace std;  
using Maze = vector<vector<int>>;  
  
struct Cell {  
    bool can_through;  
    bool is_visited;  
    int level;  
    void init(bool x, bool y, int j){  
        can_through = x;  
        is_visited = y;  
        level = j;  
    }  
};  
/** 
 * Traverse the graph with Breadth-First-Search 
 * @param[in]   maze input maze 
 * @param[in]   start_x, start_y start point of current BFS 
 * @param[in]   exit_x, exit_y exit of maze 
 * @return      shortest path steps number from start to exit 
 */  
int BreadFirstSearch(const Maze &maze,  
                     const int start_x, const int start_y,  
                     const int exit_x,  const int exit_y)  
{  
    const size_t rows    = maze.size();  
    const size_t columns = maze[0].size();  
    const int kMOVES = 4; //size of moves  
    //Trick 2: Use moves matrix to indicate move up, down, left, right  
    const int moves[kMOVES][2] = {{0,1},{1,0},{0,-1},{-1,0}};  
    vector<vector<Cell>> maze_copy(rows, vector<Cell>(columns));  
    for (int i = 0; i < rows; ++i){  
        for (int j = 0; j < columns; ++j){  
            maze_copy[i][j].init(maze[i][j] ? true : false, false, 0);  
        }  
    }  
  
    queue<pair<int, int>> q;  
    if (maze_copy[start_x][start_y].can_through)   {  
        q.push(make_pair(start_x, start_y));  
        maze_copy[start_x][start_y].is_visited = true;  
        maze_copy[start_x][start_y].level = 0;  
    }  
  
    while(!q.empty()){  
        // current location <x, y> in maze  
        int x = q.front().first;  
        int y = q.front().second;  
        q.pop();  
  
        if (x == exit_x && y == exit_y) {  
            return maze_copy[x][y].level;  
        }  
        for (int move = 0; move < kMOVES; ++move){  
            int nx = x + moves[move][0];  
            int ny = y + moves[move][1];  
            if (nx >= 0 && nx < rows && ny >= 0 && ny < columns &&  
                maze_copy[nx][ny].can_through &&  
                !maze_copy[nx][ny].is_visited)  
            {  
                q.push(make_pair(nx, ny));  
                maze_copy[nx][ny].level = maze_copy[x][y].level + 1;  
                maze_copy[nx][ny].is_visited = true;  
            }  
        }  
    }  
    return -1;  
}  
  
int FindMinNumSteps(const Maze &maze,  
                    const int exit_x,  
                    const int exit_y)  
{  
    if (maze.empty()) {  
        return -1;  
    }  
    return BreadFirstSearch(maze, 0, 0, exit_x, exit_y);  
}  
  
int main() {  
    Maze maze1 = {  
            {1, 1, 1, 1, 1},  
            {1, 1, 0, 0, 0},  
            {0, 1, 1, 1, 0},  
            {1, 0, 1, 1, 0},  
            {1, 0, 1, 1, 0},  
            {1, 0, 1, 0, 0}  
    };  
    cout << FindMinNumSteps(maze1, 4, 3) << endl; //7  
    cout << FindMinNumSteps(maze1, 1, 1) << endl; //2  
    cout << FindMinNumSteps(maze1, 0, 0) << endl; //0  
    cout << FindMinNumSteps(maze1, 2, 0) << endl; //-1  
    cout << FindMinNumSteps(maze1, 5, 2) << endl; //7  
    Maze maze2;  
    cout << FindMinNumSteps(maze2, 5, 2) << endl; //-1  
  
    return 0;  
}  
