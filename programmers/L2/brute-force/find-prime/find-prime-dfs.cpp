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
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char component[7];
bool select_comp[7];
vector<char> permutation;
unordered_map<int, bool> prime_map;
int prime_count = 0;

bool find_prime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int char_to_int() {
    int permu_size = permutation.size();
    char tmp[8];
    int i = 0;
    for (i = 0; i < permu_size; i++) {
        tmp[i] = permutation[i];
    }
    tmp[i] = '\0';

    return atoi(tmp);
}

void DFS(int length, int num_len) {
    if (length == 0) {
        int result = char_to_int();
        if (prime_map.end() == prime_map.find(result)) {
            bool prime_ck = find_prime(result);
            if (prime_ck == true) ++prime_count;
            prime_map.insert(make_pair(result, prime_ck));
        }
        return;
    }
    for (int i = 0; i < num_len; i++) {
        if (select_comp[i] == false) {
            select_comp[i] = true;
            permutation.push_back(component[i]);
            DFS(length - 1, num_len);
            permutation.pop_back();
            select_comp[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    int num_len = numbers.length();

    for (int i = 0; i < num_len; i++) {
        component[i] = numbers[i];
        select_comp[i] = false;
    }

    for (int i = 1; i <= num_len; i++) {
        DFS(i, num_len);
    }

    answer = prime_count;
    return answer;
}

int main() {
    string numbers = "011";
    cout << solution(numbers) << endl;
}