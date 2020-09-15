/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 2
 * @prob_name: 큰 수 만들기
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42883
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string get_max_string(string number, int k) {
    string cur_string = "";
    string sub_string = number;
    while (1) {                           // 1
        int num_len = sub_string.size();  // 4

        if (k == num_len)
            break;
        else if (k == 0) {
            cur_string += sub_string;
            break;
        } else {
            int max_pos = 0;                // 1
            char max_char = sub_string[0];  // 8
            if (max_char < '9') {
                for (int i = 0; i < k; i++) {  // number에서 가장 큰 숫자의 index 구할 수 있음
                    if (max_char < sub_string[i + 1]) {
                        max_pos = i + 1;                 // 1
                        max_char = sub_string[max_pos];  // 8
                        if (max_char == '9') break;
                    }
                }
            }

            cur_string += sub_string.substr(max_pos, 1);                           // 7758
            sub_string = sub_string.substr(max_pos + 1, num_len - (max_pos + 1));  // 41
            k = k - max_pos;                                                       // 0
        }
    }

    return cur_string;
}

string solution(string number, int k) {
    string answer = "";

    answer = get_max_string(number, k);
    return answer;
}

int main() {
    string number = "4177252841";
    int k = 4;
    cout << solution(number, k) << endl;
}