/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Dynamic Programming
* @prob_name: 1, 2, 3 더하기
* @prob_number: 9095
*/

#include <iostream>
#include <string>
#include <vector>

#define INIT_VALUE -1

using namespace std;

vector<int> dp;

int RecurTopDown(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else if (num == 2) {
        return 2;
    }

    dp[num] = RecurTopDown(num - 1) + RecurTopDown(num - 2) + RecurTopDown(num - 3);
    return dp[num];
}

int CountAddCaseTopDown(int num) {
    if (num == 1) {
        return 1;
    } else if (num == 2) {
        return 2;
    }

    dp.assign(num + 1, INIT_VALUE);
    return RecurTopDown(num);
}

int CountAddCaseBottomUp(int num) {
    if (num == 1) {
        return 1;
    } else if (num == 2) {
        return 2;
    }

    dp.assign(num + 1, INIT_VALUE);
    dp[0] = 1;
    dp[1] = dp[0];
    dp[2] = dp[1] + dp[0];

    for (int i = 3; i <= num; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    return dp[num];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        // cout << CountAddCaseBottomUp(n) << endl;
        cout << CountAddCaseTopDown(n) << endl;
    }
}