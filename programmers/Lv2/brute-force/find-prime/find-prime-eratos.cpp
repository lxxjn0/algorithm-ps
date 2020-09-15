/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: brute_force
 * @level: 2
 * @prob_name: 소수 찾기
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42839
 */

#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> num_count;
bool check[9999999];
int prime_count = 0;

bool compare(char a, char b) {
    return a > b;
}

int solution(string numbers) {
    int answer = 0;
    int num_len = numbers.size();

    for (int i = 0; i < 10; i++) {
        num_count.push_back(0);
    }

    int num = stoi(numbers);
    for (int i = 0; i < num_len; i++) {
        int n = num % 10;
        num = num / 10;
        num_count[n]++;
    }

    sort(numbers.begin(), numbers.end(), compare);
    num = stoi(numbers);

    for (int i = 0; i <= num; i++) {
        check[i] = false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (check[i] == false) {
            check[i] == true;
            for (int j = i * i; j <= num; j += i) check[j] = true;
        }
    }

    vector<int> v;
    bool out_bound = true;
    for (int i = 2; i <= num; i++) {
        if (check[i] == false) {
            v = num_count;
            int tmp = i;
            while (tmp != 0) {
                int n = tmp % 10;
                v[n]--;
                if (v[n] < 0) {
                    out_bound = false;
                    break;
                }
                tmp /= 10;
            }
            if (out_bound == true) prime_count++;
            out_bound = true;
        }
    }

    answer = prime_count;
    return answer;
}

int main() {
    string numbers = "011";
    cout << solution(numbers) << endl;
}