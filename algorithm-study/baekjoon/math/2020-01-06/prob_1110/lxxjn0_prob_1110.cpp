/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Math
* @prob_name: 더하기 사이클
* @prob_number: 1110
*/

#include <iostream>
#include <string>

#define SINGLE_DIGIT_UPPER 9

using namespace std;

int CalculateNextCycleNum(int num) {
    int right_digit = num % 10; // 두자리 수의 오른쪽 자리 수
    int left_digit = num / 10; // 두자리 수의 왼쪽 자리 수
    int sum_digit = right_digit + left_digit;
    return (right_digit * 10) + (sum_digit % 10);
}

int CalculateAddCycleLength(int num) {
    int answer = 0;
    int next_cycle_num = num;

    if (num == 0) {
        return ++answer;
    }

    do {
        next_cycle_num = CalculateNextCycleNum(next_cycle_num);
        answer++;
    } while (num != next_cycle_num);
    return answer;
}

int main() {
    int num;
    cin >> num;

    cout << CalculateAddCycleLength(num) << endl;
}