/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: hash
 * @level: 2
 * @prob_name: 전화번호 목록
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42577
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    unordered_map<string, int> hash;

    for (auto elem : phone_book) {
        int len = elem.length();

        if (hash.end() == hash.find(elem)) {
            hash.insert(make_pair(elem, len));
        } else {
            answer = false;
            return answer;
        }

        for (auto pair : hash) {
            string hash_string = pair.first;
            string elem_string = elem;
            elem_string = elem_string.substr(0, hash_string.length());
            if ((hash_string == elem_string) && (hash_string != elem)) {
                answer = false;
                return answer;
            }
        }
    }
    answer = true;
    return answer;
}

int main() {
    vector<string> phone_book = {"119", "97674223", "1195524421"};

    cout << solution(phone_book) << endl;
}