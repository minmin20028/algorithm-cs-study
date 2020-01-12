/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Dynamic Programming
* @prob_name: 1로 만들기
* @prob_number: 1463
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INIT_VALUE -1

using namespace std;
vector<int> dp;
int N;

int RecurTopDown(int num) {
    if (num == 1) {
        return 0;
    } else if (dp[num] != INIT_VALUE) {
        return dp[num];
    }

    dp[num] = RecurTopDown(num - 1) + 1;
    if (num % 2 == 0) {
        dp[num] = min(RecurTopDown(num / 2) + 1, dp[num]);
    }
    if (num % 3 == 0) {
        dp[num] = min(RecurTopDown(num / 3) + 1, dp[num]);
    }

    return dp[num];
}

int MakeToOneTopDown() {
    dp.assign(N + 1, INIT_VALUE);

    return RecurTopDown(N);
}

int MakeToOneBottomUp() {
    dp.assign(N + 1, INIT_VALUE);
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
    }
    return dp[N];
}

int main() {
    cin >> N;

    // cout << MakeToOneBottomUp() << endl;
    cout << MakeToOneTopDown() << endl;
}