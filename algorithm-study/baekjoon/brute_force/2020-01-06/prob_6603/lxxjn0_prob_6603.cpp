/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Brute force
* @prob_name: 로또
* @prob_number: 6603
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LOTTO_NUMBER_SIZE 6

using namespace std;

void GetLottoNumbers() {
    int n;

    while (true) {
        vector<int> lotto_numbers;
        vector<int> combination;
        cin >> n;
        
        if (!n) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            lotto_numbers.push_back(num);
            combination.push_back(i < LOTTO_NUMBER_SIZE ? 0 : 1);
        }

        sort(lotto_numbers.begin(), lotto_numbers.end());

        do {
            for (int i = 0; i < n; i++) {
                if (combination[i] == 0) {
                    cout << lotto_numbers[i] << " ";
                }
            }
            cout << "\n";
        } while (next_permutation(combination.begin(), combination.end()));
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    GetLottoNumbers();
}