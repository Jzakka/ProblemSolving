#include<iostream>
#include<cmath>
#include <set>
#include <map>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        set<int> monsters;
        map<int, int> ability_floor;
        vector<int> result;

        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int monster;
            cin >> monster;

            auto found = monsters.lower_bound(-monster);
            if(found == monsters.end()) {
                result.push_back(-1);
            }else{
                result.push_back(ability_floor[-(*found)]);
            }
            monsters.insert(-monster);
            ability_floor[monster] = i;
        }

        for (auto r:result) {
            cout << r << " ";
        }
        cout << "\n";
    }
}


