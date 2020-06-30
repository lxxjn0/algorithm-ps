/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dfs/bfs
 * @level: 3
 * @prob_name: 단어 변환
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43163
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define COST_START 99999999

using namespace std;

vector<string> words;
int word_len = 0, words_size = 0, answer_ = 0, cost = COST_START;
string target = "";
bool visited[51] = {false};

void convert_word(int index, string begin) {
    if (index == words_size) return;

    for (int i = 0; i < words_size; i++) {
        if (!visited[i]) {
            int count_same = 0;
            for (int j = 0; j < word_len; j++) {
                if (begin[j] == words[i][j]) count_same++;
            }

            if (count_same == word_len - 1) {
                visited[i] = true;
                if (words[i] == target) {
                    cost = min(cost, index + 1);
                } else
                    convert_word(index + 1, words[i]);

                visited[i] = false;
            }
        }
    }
}

int solution(string begin, string target_, vector<string> words_) {
    int answer = 0;
    words = words_;
    target = target_;
    word_len = begin.size();
    words_size = words.size();

    convert_word(0, begin);

    if (cost != COST_START) answer = cost;
    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << solution(begin, target, words) << endl;
}