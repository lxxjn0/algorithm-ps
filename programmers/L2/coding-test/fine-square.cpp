/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2019)
 * @level: 2
 * @prob_name: 멀쩡한 사각형
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/62048
 */

#include <iostream>

using namespace std;

long long gcd(long long m, long long n) {
    if (n == 0) {
        return m;
    } else {
        return gcd(n, m % n);
    }
}

long long solution(int w, int h) {
    long long answer = 0;
    long long w_ = w;
    long long h_ = h;
    answer = w_ * h_;
    long long gcd_num = gcd(w_, h_);
    w_ /= gcd_num;
    h_ /= gcd_num;

    long long cnt_empty = 0;
    long long tmp_prev, tmp_next;
    for (long long i = 0; i < w_; i++) {
        tmp_prev = i * h_ / w_;
        tmp_next = (i + 1) * h_ / w_;
        cnt_empty += ((tmp_next - tmp_prev) + 1);
    }
    cnt_empty -= 1;

    cnt_empty *= gcd_num;
    answer -= cnt_empty;
    return answer;
}

int main() {
    long long w = 8;
    long long h = 12;
    cout << solution(8, 12) << endl;
}