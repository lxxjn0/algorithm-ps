/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/원터코딩(2018)
 * @level: 2
 * @prob_name: 영어 끝말잇기
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12981
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int words_size = words.size();
    set<string> words_book;

    answer.push_back(0);
    answer.push_back(0);

    int cnt = 1;
    string tmp = "";
    words_book.insert(words[0]);
    for (int i = 1; i < words_size; i++) {
        if ((i % n) == 0) cnt++;
        tmp = words[i];
        if (tmp.size() == 1) {
            answer[0] = (i % n) + 1;
            answer[1] = cnt;
            break;
        }
        if (words_book.end() == words_book.find(tmp))
            words_book.insert(tmp);
        else {
            answer[0] = (i % n) + 1;
            answer[1] = cnt;
            break;
        }
        
        char prev = words[i - 1][words[i - 1].size() - 1];
        char next = tmp[0];
        if (prev != next) {
            answer[0] = (i % n) + 1;
            answer[1] = cnt;
            break;
        }
    }

    return answer;
}

int main() {
    int n = 5;
    vector<string> words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};

    vector<int> answer = solution(n, words);
    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}