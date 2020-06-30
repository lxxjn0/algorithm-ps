/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: hash
 * @level: 3
 * @prob_name: 베스트앨범
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42579
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pair_;

// 재생횟수에 따른 장르의 정렬을 위한 함수
bool compare(pair_ a, pair_ b) {
    if (a.second > b.second) {  // 재생횟수가 많은 장르순으로 정렬
        return true;
    } else if (a.second == b.second) {  // 재생횟수가 같을 경우는 인덱스가 작은 순으로 정렬
        if (a.first < b.first) return true;
        return false;
    } else {
        return false;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;                 // 정답을 저장할 vector
    unordered_map<int, int> genre_count;  // 장르별 재생 횟수를 count하기 위한 map <장르의 index, 재생횟수>
    unordered_map<string, int> genre;   // 장르를 index로 접근하기 위한 map <장르, index>
    vector<vector<pair_>> s;            // 장르별 노래의 재생횟수 관리 <노래 번호, 노래 재생횟수>

    int genre_idx = 0;  // genre에 저장할 index
    int genres_size = genres.size();

    for (int i = 0; i < genres_size; i++) {
        int cur_idx = 0;  // 현재 선택한 genres의 genre index
        int cur_plays = plays[i];
        string cur_genre = genres[i];

        if (genre.end() == genre.find(cur_genre)) {
            genre.insert(make_pair(cur_genre, genre_idx));

            vector<pair_> v; // 새로운 장르별 노래 재생횟수 관리 vector 생성
            s.push_back(v);
            cur_idx = genre_idx++;
        } else {
            cur_idx = genre[cur_genre];
        }
        genre_count[cur_idx] += cur_plays;
        s[cur_idx].push_back(make_pair(i, cur_plays));
    }

    vector<pair_> sort_genre;

    // 장르의 노래가 많은 순으로 정렬하기 위해 vector로 추출
    for (auto elem : genre_count) {
        sort_genre.push_back(elem);
    }

    sort(sort_genre.begin(), sort_genre.end(), compare); // 장르의 노래가 많은 순으로 정렬

    int sort_genre_size = sort_genre.size();

    for (int i = 0; i < sort_genre_size; i++) {
        int cur_genre_idx = sort_genre[i].first;
        int s_size = s[cur_genre_idx].size();

        sort(s[cur_genre_idx].begin(), s[cur_genre_idx].end(), compare);

        if (s_size < 2) {
            answer.push_back(s[cur_genre_idx][0].first);
        } else {
            answer.push_back(s[cur_genre_idx][0].first);
            answer.push_back(s[cur_genre_idx][1].first);
        }
    }

    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    vector<int> answer = solution(genres, plays);

    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}