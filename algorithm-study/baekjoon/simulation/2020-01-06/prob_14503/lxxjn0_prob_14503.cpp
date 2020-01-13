/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Simulation
* @prob_name: 로봇 청소기
* @prob_number: 14503
*/

#include <iostream>
#include <string>
#include <vector>

#define SPACE 0
#define WALL 1
#define CLEAN 2
#define ALL_DIR 4
#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;

typedef pair<int, int> coord;
vector<vector<int>> clean_up_map;
vector<coord> direction = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};

coord operator+(coord c1, coord c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

// 처음 청소 map을 만드는 함수, 청소가 가능한 공간을 반환
int GenerateCleanUpMap(int n, int m) {
    int count_space = 0;
    clean_up_map.assign(n, vector<int>(m, SPACE));

    for (auto& map_row : clean_up_map) {
        for (auto& map_elem : map_row) {
            cin >> map_elem;

            if (map_elem == SPACE) {
                count_space++;
            }
        }
    }
    return count_space;
}

// 다음에 확인해야 할 방향을 반환 (현재 방향에서 왼쪽 방향)
int NextDir(int dir) {
    return (dir + 3) % ALL_DIR;
}

// 후진할 위치를 반환
int ReverseDir(int dir) {
    return (dir + 2) % ALL_DIR;
}

// 해당 장소가 청소가 안된 공간인지 확인하여 반환
bool IsSpace(coord position) {
    return clean_up_map[position.first][position.second] == SPACE;
}

// 해당 장소가 벽인지 확인하여 반환
bool IsWall(coord position) {
    return clean_up_map[position.first][position.second] == WALL;
}

// 다음 청소할 위치를 반환하는 함수
coord NextPosition(coord dir, coord position) {
    return dir + position;
}

// 방의 상태를 바꾸는 함수
void SetCleanUpStatus(int status, coord position) {
    clean_up_map[position.first][position.second] = status;
}

// 4방향 모두를 확인하고 확인한 횟수를 반환
int CleanUpAllDir(int& dir, coord& position, int& answer) {
    coord cur_position;
    int search_dir_idx;

    for (search_dir_idx = 0; search_dir_idx < ALL_DIR; search_dir_idx++) {
        dir = NextDir(dir);
        cur_position = NextPosition(direction[dir], position);

        if (IsSpace(cur_position)) {
            position = cur_position;
            SetCleanUpStatus(CLEAN, position);
            answer++;
            break;
        }
    }
    return search_dir_idx;
}

// 청소를 한 개수를 계산하여 반환
int CountCleanUpSpace(int dir, int count_space, coord position) {
    int answer = 0;

    SetCleanUpStatus(CLEAN, position);
    answer++;

    while (answer != count_space) {
        int search_dir_idx = CleanUpAllDir(dir, position, answer);

        if (search_dir_idx == ALL_DIR) {
            int reverse_dir = ReverseDir(dir);
            position = NextPosition(direction[reverse_dir], position);

            if (IsWall(position)) {
                break;
            }
        }
    }
    return answer;
}

int main() {
    int n;  // row
    int m;  // column
    cin >> n >> m;

    int row;     // 청소기의 시작 row 위치
    int column;  // 청소기의 시작 column 위치
    int dir;     // 청소기의 시작 방향
    cin >> row >> column >> dir;

    int count_space = GenerateCleanUpMap(n, m);
    coord position = make_pair(row, column);

    cout << CountCleanUpSpace(dir, count_space, position) << endl;
}