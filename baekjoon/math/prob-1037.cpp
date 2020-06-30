/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Math
 * @prob_name: 약수
 * @prob_number: 1037
 * @prob_url: https://www.acmicpc.net/problem/1037
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getN(int n) {
    vector<int> nums(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    
    return nums[0] * nums[n - 1];
}

int main() {
    int n;
    cin >> n;

    cout << getN(n);
}