/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Brute force
* @prob_name: 퇴사
* @prob_number: 14501
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

bool CheckValidDay(int day) {
    return day <= N;
}

int CalculateProfit() {
    vector<int> dp(N + 1, 0);

    for (int i = 0; i < N; i++) {
        int term;
        int profit;
        cin >> term >> profit;

        int set_day = i + term;
        if (i > 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }

        if (CheckValidDay(set_day)) {
            dp[set_day] = max(dp[set_day], dp[i] + profit);
        }
    }
    dp[N] = max(dp[N], dp[N - 1]);
    return dp[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    cout << CalculateProfit() << "\n";
}