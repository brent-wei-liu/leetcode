/**
 * Find the shortest path from (0, 0) to exit (x, y) in 
 * a maze
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Bread First Search
 * @param[in]   maze copy of input maze
 * @param[in]   rows, columns  size of maze
 * @param[in]   startX, startY start point of current BFS
 * @param[in]   exitX, exitY exit of maze
 * @param[out]  shortest shortest path steps number from start to exit
 */
void BFS(vector<vector<int>> maze, int rows, int columns,
         int startX, int startY,
         int exitX, int exitY,
         int *shortest)
{
    queue<pair<int, int>> q;
    q.push(make_pair(-1, -1));
    const int kMOVES = 4; //size of moves
    //Trick 2: Use moves matrix to indicate move up, down, left, right
    int moves[kMOVES][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int level = -1;

    if(maze[startX][startY]==1)   {
        q.push(make_pair(startX, startY));
        maze[startX][startY] = -1;
    }

    while(!q.empty()){
        // current location <x, y> in maze
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //Trick 1: Use a “Sentinel: <-1,-1> ” to mark levels boudary.
        if(x == -1 && y == -1) {
            // Trick 1: terminate if queue contain <-1, -1> only
            if(q.empty()) return;
            ++level;
            q.push(make_pair(-1, -1));
            continue;
        }
        if(x == exitX && y == exitY) {
            *shortest = level;
            return;
        }
        for (int move = 0; move < kMOVES; ++move){
            int ti = x + moves[move][0];
            int tj = y + moves[move][1];
            if (ti >= 0 && ti < rows && tj >= 0 && tj < columns &&
                maze[ti][tj] == 1)
            {
                q.push(make_pair(ti, tj));
            }
        }
        maze[x][y] = -1;
    }
}

int findMinNumSteps(vector<vector<int>> &maze,
                    int exitRow, int exitCol)
{
    int ret = -1;
    int rows = maze.size();
    if (rows <= 0) return -1;
    int columns = maze[0].size();
    BFS(maze, rows, columns, 0, 0, exitRow, exitCol, &ret);
    return ret;
}

int main() {
    vector<vector<int>> matrix = {
            {1, 1, 1, 1, 1},
            {1, 1, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {1, 0, 0, 1, 0},
            {1, 0, 0, 1, 0},
            {1, 0, 1, 0, 0}
    };
    cout << findMinNumSteps(matrix, 4, 3) << endl; //7
    cout << findMinNumSteps(matrix, 1, 1) << endl; //2
    cout << findMinNumSteps(matrix, 0, 0) << endl; //0
    cout << findMinNumSteps(matrix, 2, 0) << endl; //-1
    cout << findMinNumSteps(matrix, 5, 2) << endl; //-1
    return 0;
}

