/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: DFS
* @prob_name: 유기농 배추
* @prob_number: 1012
*/

#include <iostream>
#include <string>
#include <vector>

#define GROUND 0
#define CABBAGE 1
#define VISIT 2
#define N make_pair(-1, 0)
#define E make_pair(0, 1)
#define S make_pair(1, 0)
#define W make_pair(0, -1)

using namespace std;

typedef pair<int, int> coord;
vector<vector<int>> cabbage_map;
vector<coord> direction = {N, E, S, W};
int n = 0;
int m = 0;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

void MakeCabbageMap(int n, int m, int k) {
    cabbage_map.assign(n, vector<int>(m, GROUND));

    int row;
    int column;
    for (int i = 0; i < k; i++) {
        cin >> row >> column;

        cabbage_map[row][column] = CABBAGE;
    }
}

void SetCabbageMapStatus(int status, coord pos) {
    cabbage_map[pos.first][pos.second] = status;
}

bool IsRange(coord pos) {
    if (pos.first < 0 || pos.first >= n) {
        return false;
    }
    if (pos.second < 0 || pos.second >= m) {
        return false;
    }
    return true;
}

bool IsCabbage(coord pos) {
    return cabbage_map[pos.first][pos.second] == CABBAGE;
}

void DFS(coord pos) {
    SetCabbageMapStatus(VISIT, pos);

    for (auto dir : direction) {
        coord next_pos = pos + dir;

        if (IsRange(next_pos) && IsCabbage(next_pos)) {
            DFS(next_pos);
        }
    }
}

int CountWormNumber() {
    int answer = 0;
    int k;
    cin >> n >> m >> k;

    MakeCabbageMap(n, m, k);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            coord pos = make_pair(i, j);
            if (IsCabbage(pos)) {
                DFS(pos);
                answer++;
            }
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << CountWormNumber() << endl;
    }
}