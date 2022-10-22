#include <iostream>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;

int getMax(string s) {
    int strLen = s.length();
    int window = strLen - 1;

    int maxLen = 0;
    for (int i = 0; i < strLen; i++) {
        int sum = 0;
        int tempLen = 0;
        for (int j = i; j < strLen; j++) {
            if (s.at(j) == '1') sum++;
            else sum--;
            if (sum == 0 && j - i + 1 > tempLen) tempLen = j - i + 1;
        }
        if (maxLen < tempLen) maxLen = tempLen;
    }
    return maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << getMax(s) << "\n";
    }
}

