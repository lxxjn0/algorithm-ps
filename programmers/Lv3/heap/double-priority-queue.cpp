/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: heap
 * @level: 3
 * @prob_name: 이중우선순위큐
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42628
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int>, less<int>> max_heap;

void queue_insert(string op) {
    int op_size = op.size();
    int num = stoi(op.substr(2, op_size - 2));
    min_heap.push(num);
    max_heap.push(num);
}

void remove_elem(string op, int& sync_min, int& sync_max) {
    int op_size = op.size();
    int num = stoi(op.substr(2, op_size - 2));
    int min_size = min_heap.size();
    int max_size = max_heap.size();

    if ((min_size - sync_max != 0) && (max_size - sync_min != 0)) {
        if (num == 1) {
            max_heap.pop();
            sync_max++;
        } else if (num == -1) {
            min_heap.pop();
            sync_min++;
        } else
            cout << "get_elem error detected!" << '\n';
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    // sync_min은 min_heap에서 최소값을 뺐을 경우 max-heap에서 알기 위한 값, sync_max도 마찬가지.
    int sync_min = 0, sync_max = 0;
    int oper_size = operations.size();

    for (int i = 0; i < oper_size; i++) {
        string op = operations[i];
        if (op[0] == 'I')
            queue_insert(op);
        else if (op[0] == 'D')
            remove_elem(op, sync_min, sync_max);
        else
            continue;
        
        int min_size = min_heap.size();
        int max_size = max_heap.size();
        if ((min_size - sync_max == 0) && (max_size - sync_min == 0)) {
            priority_queue<int, vector<int>, greater<int>> min_empty;
            priority_queue<int, vector<int>, less<int>> max_empty;
            sync_max = 0, sync_min = 0;
            min_heap = min_empty;
            max_heap = max_empty;
        }
    }

    int min_size = min_heap.size();
    int max_size = max_heap.size();
    if ((min_size - sync_max != 0) && (max_size - sync_min != 0)) {
        answer.push_back(max_heap.top());
        answer.push_back(min_heap.top());
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main() {
    vector<string> operations = {"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"};
    vector<int> answer = solution(operations);
    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}