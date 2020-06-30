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
    int phone_book_size = phone_book.size();

    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book_size; i++) {
        int prev_phone_number_length = phone_book[i - 1].length();
        
        if (phone_book[i - 1] == phone_book[i].substr(0, prev_phone_number_length)) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<string>> phone_books = {
        {"119", "97674223", "1195524421"},
        {"123", "456", "789"},
        {"12", "123", "1235", "567", "88"}};

    for (auto phone_book : phone_books) {
        cout << boolalpha << solution(phone_book) << endl;
    }
}