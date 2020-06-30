/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: brute_force
 * @level: 2
 * @prob_name: 숫자 야구
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42841
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> num_list;
int pred_count = 0;

int solution(vector<vector<int>> baseball) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 0;
    int baseball_size = baseball.size();  // 2차원 vector 행 개수

    for (int i = 1; i < 10; i++) {
        num_list.insert(make_pair(i, i));  // 1부터 9까지 차례로 삽입
    }

    for (auto question : baseball) {                     // out일때 포함되어 있는 숫자들 제거
        if ((question[1] == 0) && (question[2] == 0)) {  // out인 경우
            int tmp = question[0];                       // 해당 입력 세 자리수
            for (int i = 0; i < 3; i++) {
                int n = tmp % 10;
                if (num_list.end() != num_list.find(n)) num_list.erase(n);
                tmp /= 10;
            }
        }
    }

    int num_arr[9];  // 가능한 숫자들만 저장할 배열
    int arr_count = 0;

    for (auto num : num_list) {  // unordered_map의 숫자를 배열에 저장
        num_arr[arr_count++] = num.first;
    }

    int num_size = num_list.size();  // 적어도 가능성이 있는 수들의 개수
    int select_num[9];

    for (int i = 0; i < num_size; i++) {
        if (i < 3)
            select_num[i] = i + 1;
        else
            select_num[i] = 0;
    }  // 순열로 선택할 숫자만 0

    sort(select_num, select_num + num_size);  // 00..0123으로 정렬

    int play_ball[3];  // 선택한 가능성 check 세자리 숫자
    int ques, strike, ball, pred_strike, pred_ball;
    int ques_arr[3] = {0};  // 질문을 한 세자리 숫자

    do {
        for (int i = 0; i < num_size; i++) {
            if (select_num[i] == 1)
                play_ball[0] = num_arr[i];
            else if (select_num[i] == 2)
                play_ball[1] = num_arr[i];
            else if (select_num[i] == 3)
                play_ball[2] = num_arr[i];
        }  // play_ball에 세자리 수 저장

        int case_count = 0;  // 몇 개의 case를 만족했는지 여부

        for (int i = 0; i < baseball_size; i++) {
            ques = baseball[i][0];
            strike = baseball[i][1];
            ball = baseball[i][2];

            for (int j = 2; j >= 0; j--) {
                int n = ques % 10;
                ques_arr[j] = n;
                ques /= 10;
            }

            pred_strike = 0;
            pred_ball = 0;

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (ques_arr[j] == play_ball[k]) {
                        if (j == k)
                            ++pred_strike;
                        else
                            ++pred_ball;
                    }
                }
            }
            if ((pred_strike == strike) && (pred_ball == ball)) ++case_count;
        }

        if (case_count == baseball_size)
            ++pred_count;
    } while (next_permutation(select_num, select_num + num_size));

    answer = pred_count;
    return answer;
}

int main() {
    vector<vector<int>> baseball = {{123, 1, 1},
                                    {356, 1, 0},
                                    {327, 2, 0},
                                    {489, 0, 1}};
    cout << solution(baseball) << endl;
}