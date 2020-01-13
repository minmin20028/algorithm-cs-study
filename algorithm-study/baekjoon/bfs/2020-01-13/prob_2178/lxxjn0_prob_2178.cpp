/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: BFS
* @prob_name: 미로 탐색
* @prob_number: 2178
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define WALL 0
#define SPACE 1
#define VISIT 2
#define INIT_COORD make_pair(0, 0)
#define N make_pair(-1, 0)
#define E make_pair(0, 1)
#define S make_pair(1, 0)
#define W make_pair(0, -1)

using namespace std;

typedef pair<int, int> coord;
typedef pair<coord, int> path;
vector<vector<int>> maze;
vector<coord> direction = {N, E, S, W};
coord target;

// bool operator==(coord& c1, coord& c2) {
//     return (c1.first == c2.first) && (c1.second == c2.second);
// }

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

bool IsRange(coord pos) {
    if (pos.first < 0 || pos.first > target.first) {
        return false;
    }
    if (pos.second < 0 || pos.second > target.second) {
        return false;
    }
    return true;
}

bool IsSpace(coord pos) {
    return maze[pos.first][pos.second] == SPACE;
}

void SetMazeStatus(int status, coord pos) {
    maze[pos.first][pos.second] = status;
}

void MakeMazeMap(int n, int m) {
    maze.assign(n, vector<int>(m, WALL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
}

void PushAllDirection(queue<path>& q, path cur_path) {
    for (auto dir : direction) {
        coord next_pos = cur_path.first + dir;
        if (IsRange(next_pos) && IsSpace(next_pos)) {
            q.push(make_pair(next_pos, cur_path.second + 1));
            SetMazeStatus(VISIT, next_pos);
        }
    }
}

int CountPathNumber() {
    queue<path> q;
    path cur_path;

    q.push(make_pair(INIT_COORD, 1));
    SetMazeStatus(VISIT, INIT_COORD);

    while (!q.empty()) {
        cur_path = q.front();
        q.pop();

        if (cur_path.first == target) {
            return cur_path.second;
        }
        PushAllDirection(q, cur_path);
    }
    return cur_path.second;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    target = make_pair(n - 1, m - 1);

    MakeMazeMap(n, m);

    cout << CountPathNumber() << endl;
}