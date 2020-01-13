/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: dynamic programming
* @prob_name: 계단 오르기
* @prob_number: 2579
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define INIT_SCORE -1

using namespace std;

vector<int> stairs;

void MakeStairs(int n) {
    stairs.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }
}

int RecurMaxStairs(vector<int>& dp, int n) {
    if (dp[n] != INIT_SCORE) {
        return dp[n];
    }

    dp[n] = max(RecurMaxStairs(dp, n - 2) + stairs[n],
                RecurMaxStairs(dp, n - 3) + stairs[n - 1] + stairs[n]);
    return dp[n];
}

int GetMaxStairsTopDown(int n) {
    if (n == 1) {
        return stairs[1];
    }
    if (n == 2) {
        return stairs[2] + stairs[1];
    }

    vector<int> dp(n + 1, INIT_SCORE);

    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[2] + dp[1];

    dp[n] = RecurMaxStairs(dp, n);
    return dp[n];
}

int GetMaxStairsBottomUp(int n) {
    if (n == 1) {
        return stairs[1];
    }
    if (n == 2) {
        return stairs[2] + stairs[1];
    }

    vector<int> dp(n + 1, INIT_SCORE);

    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[2] + dp[1];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    MakeStairs(n);
    // cout << GetMaxStairsBottomUp(n) << endl;
    cout << GetMaxStairsTopDown(n) << endl;
}