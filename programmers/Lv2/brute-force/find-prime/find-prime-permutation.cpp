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
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, bool> prime_map;
int prime_count = 0;

bool find_prime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    string tmp = numbers;
    int num_len = numbers.length();
    sort(tmp.begin(), tmp.end());

    do {
        string s;
        for (int i = 1; i <= num_len; i++) {
            s = tmp.substr(0, i);
            int s_num = stoi(s);
            if (prime_map.end() == prime_map.find(s_num)) {
                bool prime_check = find_prime(s_num);
                prime_map.insert(make_pair(s_num, prime_check));
                if (prime_check) ++prime_count;
            }
        }
    } while (next_permutation(tmp.begin(), tmp.end()));

    answer = prime_count;
    return answer;
}

int main() {
    string numbers = "011";
    cout << solution(numbers) << endl;
}