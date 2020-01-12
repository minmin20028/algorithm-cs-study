/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Math
* @prob_name: 소수 찾기
* @prob_number: 1978
*/

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define UPPER_BOUND 1000

using namespace std;

vector<bool> is_prime(UPPER_BOUND + 1, true);

void SetPrimeCheck(int num) {
    for (int i = num * 2; i <= UPPER_BOUND; i += num) {
        is_prime[i] = false;
    }
}

void Eratos() {
    is_prime[1] = false;
    for (int i = 2; i <= sqrt(UPPER_BOUND); i++) {
        if (is_prime[i]) {
            SetPrimeCheck(i);
        }
    }
}

int CountPrimeNum(int n) {
    int count_prime = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (is_prime[num]) {
            count_prime++;
        }
    }
    return count_prime;
}

int main() {
    int n;
    cin >> n;

    Eratos();
    cout << CountPrimeNum(n) << endl;
}