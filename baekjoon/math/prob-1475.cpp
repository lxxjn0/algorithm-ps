/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Math
 * @prob_name: 방 번호
 * @prob_number: 1475
 * @prob_url: https://www.acmicpc.net/problem/1475
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define SIX 6
#define NINE 9

using namespace std;

map<int, int> count_num;

bool IsSixOrNine(int num) {
    return (num == SIX || num == NINE);
}

void MakeCountNumList() {
    string room_number;
    cin >> room_number;

    int room_number_length = room_number.length();

    for (int i = 0; i < room_number_length; i++) {
        int num = room_number[i] - '0';

        if (IsSixOrNine(num)) {
            count_num[SIX]++;
        } else {
            count_num[num]++;
        }
    }
}

int GetSelectedNumCount(int num, int count) {
    if (IsSixOrNine(num)) {
        if (count % 2 == 0) {
            return count / 2;
        }
        return (count / 2) + 1;
    }
    return count;
}

int GetRequireSetNum() {
    vector<int> count_num_list;

    for (auto& elem : count_num) {
        count_num_list.push_back(GetSelectedNumCount(elem.first, elem.second));
    }
    return *max_element(count_num_list.begin(), count_num_list.end());
}

int main() {
    MakeCountNumList();

    cout << GetRequireSetNum();
}