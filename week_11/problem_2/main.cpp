#include<iostream>
#include<cmath>
#include<vector>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m;
vector<bool> played(1000'000);
vector<int> inhaTeam;
vector<int> team(100'000);
vector<int> teamScore(100'000);
int matchCount = 0;

int getTeamScore(int teamNumber) {
    return teamScore[teamNumber];
}

void match(vector<int>::iterator inhaMember){
    int opponent_team = team[(*inhaMember) - 1];
    if(opponent_team == 1 || (played[*inhaMember] || played[*inhaMember - 1])) return;

    /**
     * Rank Change
     */

    played[*inhaMember] = true;
    played[(*inhaMember) - 1] = true;

    team[*inhaMember] = opponent_team;
    team[(*inhaMember) - 1] = 1;

    /**
     * update teamScore
     */
    teamScore[opponent_team]--;
    teamScore[1]++;

    matchCount++;
}

bool isInhaWinner(){
    int inha_teamscore = getTeamScore(1);
    for (int i = 2; i <= m; i++) {
        int score = getTeamScore(i);
        if(inha_teamscore <= score) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) { // O(n)
            int s;
            cin >> s;

            if(s==1){
                inhaTeam.push_back(i);
            }
            team[i] = s;
            teamScore[s] += n - (i - 1);
        }

        //O(nlogn)
        std::sort(inhaTeam.begin()+1, inhaTeam.end(), [](int a, int b) {
            int a_opponent_team = team[a - 1];
            int b_opponent_team = team[b - 1];
            return getTeamScore(b_opponent_team) < getTeamScore(a_opponent_team);
        });

        auto inha_it = inhaTeam.begin() + 1;
        while (!isInhaWinner() && inha_it != inhaTeam.end()) {
            match(inha_it);
            inha_it++;
        }

        cout <<  (isInhaWinner() ? matchCount : -1) << "\n";

        played = vector<bool>(100'000, false);
        inhaTeam.clear();
        team = vector<int>(100'000);
        teamScore = vector<int>(100'000);
        matchCount = 0;
    }
}


