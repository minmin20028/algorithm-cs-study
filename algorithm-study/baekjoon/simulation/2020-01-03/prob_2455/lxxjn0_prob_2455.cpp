/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Simulation
* @prob_name: 지능형 기차
* @prob_number: 2455
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define STATION_NUMBER 4

using namespace std;

int CalculateMaxTrainUser() {
    int total_user = 0;
    vector<int> train_user_log;

    for (int i = 0; i < STATION_NUMBER; i++) {
        int get_off_number = 0;
        int get_on_number = 0;

        cin >> get_off_number >> get_on_number;
        total_user += (get_on_number - get_off_number);
        train_user_log.push_back(total_user);
    }
    return *max_element(train_user_log.begin(), train_user_log.end());
}

int main() {
    cout << CalculateMaxTrainUser() << endl;
}