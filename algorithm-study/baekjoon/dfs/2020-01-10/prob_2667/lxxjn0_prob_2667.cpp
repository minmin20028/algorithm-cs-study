/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: DFS
* @prob_name: 단지번호 붙이기
* @prob_number: 2667
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define SPACE 0
#define EXIST 1
#define N make_pair(-1, 0)
#define E make_pair(0, 1)
#define S make_pair(1, 0)
#define W make_pair(0, -1)

using namespace std;

vector<vector<int>> complex_map;
typedef pair<int, int> coord;
vector<coord> direction = {N, E, S, W};
int n;

coord operator+(coord c1, coord c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

int GetStatus(coord pos) {
    return complex_map[pos.first][pos.second];
}

bool IsExist(coord pos) {
    return GetStatus(pos) == EXIST;
}

bool IsRange(coord pos) {
    if (pos.first >= n || pos.first < 0) {
        return false;
    }
    if (pos.second >= n || pos.second < 0) {
        return false;
    }
    return true;
}

void MakeComplexMap() {
    complex_map.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &complex_map[i][j]);
        }
    }
}

int CountCurComplexNumber(coord pos, int comp_idx) {
    int count = 1;
    complex_map[pos.first][pos.second] = comp_idx;

    for (auto dir : direction) {
        coord next_pos = pos + dir;
        if (IsRange(next_pos) && IsExist(next_pos)) {
            count += CountCurComplexNumber(next_pos, comp_idx);
        }
    }
    return count;
}

vector<int> GetTotalComplexNumber() {
    vector<int> complex_num_vec;
    int comp_idx = 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            coord pos = make_pair(i, j);

            if (IsExist(pos)) {
                complex_num_vec.push_back(CountCurComplexNumber(pos, comp_idx));
                comp_idx++;
            }
        }
    }
    return complex_num_vec;
}

int main() {
    cin >> n;

    MakeComplexMap();

    vector<int> answer = GetTotalComplexNumber();
    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for (auto elem : answer) {
        cout << elem << endl;
    }
}