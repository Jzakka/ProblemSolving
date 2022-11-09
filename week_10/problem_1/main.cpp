#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int answer = 0;

void getFx(vector<int> &gs, int p, int q, int x) {
    do {
        unsigned i = 0;
        long long res = 0;

        for (auto it = gs.begin(); it != gs.end(); i++, it++, res %=1013) {
            res += (*it * ((long long) pow(x, i) % 1013) % 1013);
        }

        if (res >= p && res <= q) {
            answer++;
        }
    } while (next_permutation(gs.begin(), gs.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> gaesu;
        while (n--) {
            int num;
            cin >> num;
            gaesu.push_back(num);
        }

        int p, q, x;
        cin >> p >> q >> x;

        sort(gaesu.begin(), gaesu.end());
        getFx(gaesu, p, q, x);

        cout << answer << "\n";
        answer = 0;
    }
}