/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 2
 * @prob_name: 소수 만들기
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12977
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX_NUM 3000

using namespace std;

bool isPrime[MAX_NUM] = {false};

void eratos() {
    for (int i = 2; i < MAX_NUM; i++) {
        if (!isPrime[i]) {
            for (int j = i * i; j < MAX_NUM; j += i) {
                if (!isPrime[j]) {
                    isPrime[j] = true;
                }
            }
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    int numsSize = nums.size();
    vector<int> permutation(numsSize, 1);
    set<int> sumSet;
    permutation[0] = 0;
    permutation[1] = 0;
    permutation[2] = 0;

    eratos();

    do {
        int sum = 0;
        for (int i = 0; i < numsSize; i++) {
            if (!permutation[i]) sum += nums[i];
        }
        if (!isPrime[sum]) answer++;
    } while (next_permutation(permutation.begin(), permutation.end()));

    return answer;
}

int main() {
    vector<int> nums = {1, 2, 7, 6, 4};
    cout << solution(nums) << endl;
}
