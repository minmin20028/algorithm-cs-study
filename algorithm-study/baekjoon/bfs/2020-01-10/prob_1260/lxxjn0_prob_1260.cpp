/**
* @author: junyoung lee - lxxjn0
* @site: baekjoon online judge
* @classification: BFS
* @prob_name: DFS와 BFS
* @prob_number: 1260
*/

#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define LINKED 1

using namespace std;

vector<vector<int>> adjust_vec;
set<int> visited;
int node_num;
int edge_num;
int start_node;
bool find_all = false;

bool IsNodeVisited(int node) {
    return visited.find(node) != visited.end();
}

void MakeAdjustArray() {
    adjust_vec.assign(node_num, vector<int>(node_num, 0));

    for (int i = 0; i < edge_num; i++) {
        int first;
        int second;
        cin >> first >> second;

        adjust_vec[first - 1][second - 1] = LINKED;
        adjust_vec[second - 1][first - 1] = LINKED;
    }
}

void VisitDFS(int node) {
    if (visited.size() == node_num) {
        find_all = true;
        return;
    }

    cout << node + 1 << " ";
    visited.insert(node);

    for (int i = 0; i < node_num; i++) {
        if (adjust_vec[node][i] == LINKED && !IsNodeVisited(i)) {
            VisitDFS(i);
            if (find_all) {
                break;
            }
        }
    }
}

void VisitBFS() {
    visited.clear();
    queue<int> q;
    q.push(start_node);
    visited.insert(start_node);

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();
        cout << cur_node + 1 << " ";

        for (int i = 0; i < node_num; i++) {
            if (adjust_vec[cur_node][i] == LINKED && !IsNodeVisited(i)) {
                q.push(i);
                visited.insert(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> node_num >> edge_num >> start_node;

    start_node--;

    MakeAdjustArray();
    VisitDFS(start_node);
    cout << endl;
    VisitBFS();
}