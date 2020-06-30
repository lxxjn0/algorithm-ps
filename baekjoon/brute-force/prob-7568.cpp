/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Brute force
 * @prob_name: 덩치
 * @prob_number: 7589
 * @prob_url: https://www.acmicpc.net/problem/7589
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define BIG 1
#define EQUAL 2

using namespace std;

typedef pair<int, int> bigSize;
vector<bigSize> bigSizes;
int n;

bool compare(bigSize& s1, bigSize& s2) {
    return s1.first > s2.first && s1.second > s2.second;
}

void makeBigSizes() {
    for (int i = 0; i < n; i++) {
        int weight;
        int height;
        cin >> weight >> height;

        bigSizes.push_back(make_pair(weight, height));
    }
}

vector<int> getBigSizeRank() {
    vector<int> answer;
    for (auto& sizeCur : bigSizes) {
        int rank = 1;
        for (auto& sizeCmp : bigSizes) {
            if (compare(sizeCmp, sizeCur)) {
                rank++;
            }
        }
        answer.push_back(rank);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    makeBigSizes();

    vector<int> answer = getBigSizeRank();
    for (auto& elem : answer) {
        cout << elem << endl;
    }
}