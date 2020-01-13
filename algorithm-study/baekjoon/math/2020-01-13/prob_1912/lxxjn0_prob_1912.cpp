/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: math
* @prob_name: 연속합
* @prob_number: 1912
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sequence;

void MakeSequencs(int n) {
    sequence.assign(n, 0);

    for (auto& elem : sequence) {
        cin >> elem;
    }
}

int GetMaxSumOfSequence(int n) {
    vector<int> dp(n, 0);

    dp[0] = sequence[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + sequence[i], sequence[i]);
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    MakeSequencs(n);
    cout << GetMaxSumOfSequence(n) << endl;
}