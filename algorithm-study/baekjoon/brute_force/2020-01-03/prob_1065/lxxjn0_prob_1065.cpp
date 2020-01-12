/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Brute force
* @prob_name: 한수
* @prob_number: 1065
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsHanNumber(int num) {
    string num_string = to_string(num);
    int num_string_len = num_string.length();

    if (num_string_len == 1 || num_string_len == 2) {
        return true;
    } else if ((num_string[2] - num_string[1]) == (num_string[1] - num_string[0])) {
        return true;
    }
    return false;
}

int CountHanNumber(int num) {
    int answer = 0;

    while (num > 0) {
        if (IsHanNumber(num--)) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int num;
    cin >> num;

    cout << CountHanNumber(num) << endl;
}