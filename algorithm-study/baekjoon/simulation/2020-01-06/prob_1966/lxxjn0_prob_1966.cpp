/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: Simulation
* @prob_name: 프린터 큐
* @prob_number: 1966
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool IsPriorityTask(vector<int>& task_vec, int cur_task_idx) {
    return task_vec[cur_task_idx] != *max_element(task_vec.begin(), task_vec.end());
}

int RunPriorityPrinter() {
    int task_number;
    int target_index;
    cin >> task_number >> target_index;

    queue<int> task_queue;
    vector<int> task_vec;

    for (int i = 0; i < task_number; i++) {
        int priority;
        cin >> priority;

        task_queue.push(i);
        task_vec.push_back(priority);
    }

    int count_order = 1;

    while (!task_queue.empty()) {
        int cur_task_idx = task_queue.front();
        task_queue.pop();

        if (IsPriorityTask(task_vec, cur_task_idx)) {
            task_queue.push(cur_task_idx);
        } else {
            if (cur_task_idx == target_index) {
                return count_order;
            }

            count_order++;
            task_vec[cur_task_idx] = 0;
        }
    }
    return count_order;
}

int main() {
    int test_case_num;
    cin >> test_case_num;

    for (int i = 0; i < test_case_num; i++) {
        cout << RunPriorityPrinter() << endl;
    }
}