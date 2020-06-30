/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: brute_force
 * @level: 2
 * @prob_name: 카펫
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42842
 */

#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool compare(int a, int b) {
    return a > b;
};

vector<int> find_size(int brown, int red) {
    vector<int> size;

    int width = 0, height = 0;
    for (int i = 1; i <= sqrt(red); i++) {
        if (red % i == 0) {
            width = i;
            height = red / width;
            if (brown == (width + height) * 2 + 4) {
                size.push_back(width + 2);
                size.push_back(height + 2);
            }
        }
    }
    sort(size.begin(), size.end(), compare);

    return size;
}

vector<int> solution(int brown, int red) {
    vector<int> answer;

    answer = find_size(brown, red);
    return answer;
}

int main() {
    int brown = 24;
    int red = 24;
    vector<int> size = solution(brown, red);

    for (auto elem : size) {
        cout << elem << " ";
    }
    cout << endl;
}