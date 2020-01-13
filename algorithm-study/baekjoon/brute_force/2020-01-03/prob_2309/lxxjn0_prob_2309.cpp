/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Brute force
* @prob_name: 일곱 난쟁이
* @prob_number: 2309
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define FAKE_DWARF_NUMBER 9
#define REAL_DWARF_NUMBER 7
#define TOTAL_HEIGHT 100

using namespace std;

// 난쟁이의 키를 입력받아서 vector로 반환하는 함수
vector<int> ReceiveDwarfHeight() {
    vector<int> dwarf_height;

    for (int i = 0; i < FAKE_DWARF_NUMBER; i++) {
        int height;
        cin >> height;
        dwarf_height.push_back(height);
    }
    return dwarf_height;
}

// 난쟁이의 키를 조합으로 뽑을 때 필요한 조합 vector를 만드는 함수
vector<int> MakeCombinationVector() {
    vector<int> comb_vec;

    for (int i = 0; i < FAKE_DWARF_NUMBER; i++) {
        comb_vec.push_back(i < REAL_DWARF_NUMBER ? 0 : 1);
    }
    return comb_vec;
}

// 정답인 난쟁이를 찾아서 반환하는 함수
vector<int> FindRealDwarf(vector<int> dwarf_height, vector<int> comb_vec) {
    do {
        int sum_height = 0;
        vector<int> answer;

        for (int i = 0; i < FAKE_DWARF_NUMBER; i++) {
            if (comb_vec[i] == 0) {
                sum_height += dwarf_height[i];
                answer.push_back(dwarf_height[i]);
            }
        }
        if (sum_height == TOTAL_HEIGHT) {
            return answer;
        }
    } while (next_permutation(comb_vec.begin(), comb_vec.end()));

    vector<int> empty;
    return empty;
}

int main() {
    vector<int> dwarf_height = ReceiveDwarfHeight();

    sort(dwarf_height.begin(), dwarf_height.end());
    vector<int> comb_vec = MakeCombinationVector();
    vector<int> answer = FindRealDwarf(dwarf_height, comb_vec);

    for (auto elem : answer) {
        cout << elem << endl;
    }
}