#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<long long, pair<long long, long long>> DP;

void calc(long long n) {
    long long copiedN = n;

    int k = 0;
    long long invalid;
    long long dist;

    long long remain;

    long long oneGrpCnt;
    long long zeroGrpCnt;
    long long remainremain;
    long long quot;
    while (copiedN != 0)
    {
        invalid = pow(2, k) - 1;
        dist = pow(2, k);

        remain = n - invalid;

        remainremain = remain % dist;
        
        quot = remain / dist;

        if (quot & 1) {
            oneGrpCnt = quot / 2 + 1;
            zeroGrpCnt = quot - oneGrpCnt;

            DP[n].first += dist * zeroGrpCnt + remainremain;
            DP[n].second += dist * oneGrpCnt;
        }
        else {
            oneGrpCnt = quot / 2;
            zeroGrpCnt = oneGrpCnt;

            DP[n].first += dist * zeroGrpCnt;
            DP[n].second += dist * oneGrpCnt + remainremain;
        }

        k++;
        copiedN >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        DP[n].first = 0;
        DP[n].second = 0;

        calc(n);

        cout << DP[n].first << " " << DP[n].second << "\n";
    }
}