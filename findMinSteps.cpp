#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void BFS(vector<vector<int>> maze, int rows, int columns,
         int startX, int startY,
         int exitX, int exitY,
         int *ret)
{
    queue<pair<int, int>> q;
    q.push(make_pair(-1, -1));
    const int kMOVES = 4; //size of moves
    int moves[kMOVES][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int level = -1;

    if(maze[startX][startY]==1)   {
        q.push(make_pair(startX, startY));
        maze[startX][startY] = -1;
    }

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i == -1 && j == -1) {
            // trick 1: terminate if queue just contain <-1, -1>
            if(q.empty()) return;
            ++level;
            q.push(make_pair(-1, -1));
            continue;
        }
        if(i == exitX && j == exitY) {
            *ret = level;
            return;
        }
        for (int l = 0;l < kMOVES;++l){
            int ti = i + moves[l][0];
            int tj = j + moves[l][1];
            if (ti >= 0 && ti < rows && tj >= 0 && tj < columns &&
                maze[ti][tj]==1)
            {
                q.push(make_pair(ti, tj));
            }
        }
        maze[i][j] = -1;
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


