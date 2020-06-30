/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Brute force
 * @prob_name: 스타트와 링크
 * @prob_number: 14889
 * @prob_url: https://www.acmicpc.net/problem/14889
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define START_TEAM 0
#define LINK_TEAM 1

using namespace std;

vector<vector<int>> abilityMap;
vector<int> teamStart;
vector<int> teamLink;
int n = 0;

void makeAbilityMap() {
    abilityMap.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> abilityMap[i][j];
        }
    }
}

int calcTeamAbility(int teamInfo) {
    vector<int> team;

    if (teamInfo == START_TEAM) {
        team = teamStart;
    } else if (teamInfo == LINK_TEAM) {
        team = teamLink;
    }

    int teamSize = team.size();
    int teamTotalAbility = 0;
    for (int i = 0; i < teamSize; i++) {
        for (int j = 0; j < teamSize; j++) {
            teamTotalAbility += abilityMap[team[i]][team[j]];
        }
    }
    return teamTotalAbility;
}

int getMinGapTwoTeam() {
    vector<int> comb;
    vector<int> gaps;

    for (int i = 0; i < n; i++) {
        comb.push_back(i < n / 2 ? START_TEAM : LINK_TEAM);
    }

    do {
        teamStart.clear();
        teamLink.clear();

        for (int i = 0; i < n; i++) {
            if (comb[i] == START_TEAM) {
                teamStart.push_back(i);
            } else if (comb[i] == LINK_TEAM) {
                teamLink.push_back(i);
            }
        }

        int curGap = abs(calcTeamAbility(START_TEAM) - calcTeamAbility(LINK_TEAM));
        gaps.push_back(curGap);

        if (curGap == 0) {
            break;
        }
    } while (next_permutation(comb.begin(), comb.end()));
    return *min_element(gaps.begin(), gaps.end());
}

int main() {
    cin >> n;
    makeAbilityMap();

    cout << getMinGapTwoTeam();
}