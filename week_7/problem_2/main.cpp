#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

int getMax(string s) {
    vector<int> prefixSum(s.length()+1);
    unordered_map<int, int> first;
    first[0] = 0;
    int strLen = s.length();
    int sum = 0;
    for (int i = 0; i < strLen; i++) {
        if(s.at(i)=='1')
            sum++;
        else
            sum--;

        if(first.find(sum)==first.end())
            first[sum] = i + 1;
        prefixSum[i + 1] = sum;
    }

    int maxLen = 0;
    for (int i=1;i<=strLen;i++) {
        int tmp = i - first[prefixSum[i]];
        maxLen = max(maxLen, tmp);
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

