#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int DP[1001][1001];
int xLen;
int yLen;
string x;
string y;

int edit(){
    for (int i = 1; i <= xLen; ++i) {
        for (int j = 1; j <= yLen; ++j) {
            if(x.at(i-1) == y.at(j-1))
                DP[i][j] = DP[i - 1][j - 1];
            else
                DP[i][j] = min(DP[i - 1][j], min(DP[i][j - 1], DP[i - 1][j - 1])) + 1;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < 1001; i++) {
        DP[0][i] = i;
        DP[i][0] = i;
    }

    while (t--) {
        cin >> x >> y;

        xLen = x.length();
        yLen = y.length();

        edit();

        cout << DP[xLen][yLen] << "\n";
    }
}