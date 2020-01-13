/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Math
* @prob_name: 설탕 배달
* @prob_number: 2839
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define BIG_BAG 5
#define SMALL_BAG 3

using namespace std;

int CalculateMinSugarBag(int n) {
    if ((n % BIG_BAG) == 0) {
        return n / BIG_BAG;
    }

    int big_bag_count = n / BIG_BAG;

    while (big_bag_count >= 0) {
        int remain_sugar = n;
        remain_sugar -= (big_bag_count * BIG_BAG);

        if ((remain_sugar % SMALL_BAG) == 0) {
            return (big_bag_count + (remain_sugar / SMALL_BAG));
        }

        big_bag_count--;
    };
    return -1;
}

int DpSugarBag(int n) {
    vector<int> d(n + 1, -1);

    d[0] = 0;
    d[3] = 1;

    for (int i = 5; i <= n; i++) {
        if ((d[i - 3] == -1) && (d[i - 5] == -1)) {
            d[i] = -1;
        } else {
            if (d[i - 3] == -1) {
                d[i] = d[i - 5] + 1;
            } else if (d[i - 5] == -1) {
                d[i] = d[i - 3] + 1;
            } else {
                d[i] = min(d[i - 3], d[i - 5]) + 1;
            }
        }
    }

    return d[n];
}

int main() {
    int n;
    cin >> n;

    // cout << CalculateMinSugarBag(n) << endl;
    cout << DpSugarBag(n) << endl;
}