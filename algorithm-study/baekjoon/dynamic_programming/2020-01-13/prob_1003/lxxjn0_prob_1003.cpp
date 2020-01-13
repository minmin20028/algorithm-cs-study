/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: dynamic programming
* @prob_name: 피보나치 함수
* @prob_number: 1003
*/

#include <iostream>
#include <string>
#include <vector>

#define INIT make_pair(0, 0)
#define ZERO make_pair(1, 0)
#define ONE make_pair(0, 1)

using namespace std;

typedef pair<int, int> call_count;

call_count operator+(call_count c1, call_count c2) {
    call_count tmp;

    tmp.first = c1.first + c2.first;
    tmp.second = c1.second + c2.second;
    return tmp;
}

call_count RecurCallCount(vector<call_count>& dp, int n) {
    if (n == 0) {
        return ZERO;
    }
    if (n == 1) {
        return ONE;
    }
    if (dp[n] != INIT) {
        return dp[n];
    }

    dp[n] = RecurCallCount(dp, n - 1) + RecurCallCount(dp, n - 2);
    return dp[n];
}

call_count CountCallTopDown(int n) {
    if (n == 0) {
        return ZERO;
    }
    if (n == 1) {
        return ONE;
    }

    vector<call_count> dp(n + 1, INIT);

    dp[0] = ZERO;
    dp[1] = ONE;
    dp[n] = RecurCallCount(dp, n);
    return dp[n];
}

call_count CountCallBottomUp(int n) {
    if (n == 0) {
        return ZERO;
    }
    if (n == 1) {
        return ONE;
    }

    vector<call_count> dp(n + 1, INIT);

    dp[0] = ZERO;
    dp[1] = ONE;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        // call_count answer = CountCallBottomUp(n);
        call_count answer = CountCallTopDown(n);
        cout << answer.first << " " << answer.second << endl;
    }
}