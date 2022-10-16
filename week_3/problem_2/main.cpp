#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        long long m;
        cin >> m;

        unordered_map<long long, long long> cnt;
        queue<long long> Q;
        Q.push(m);
        cnt.insert({m, 0});

        int ptr = 0;
        while (!Q.empty()) {
            int qSz = Q.size();

            for (int i = 0; i < qSz; i++) {
                long long num = Q.front();
                Q.pop();
                if(num==0)
                    continue;

                double delta;
                double nextNum;

                int digit = num % (long long) pow(10, ptr + 1) / pow(10, ptr);

                if (digit < 5) {
                    delta = digit * pow(10, ptr);
                    nextNum = num - delta;

                    if (cnt.find(nextNum) == cnt.end() ||
                        cnt[nextNum] >= cnt[num] + digit) {
                        cnt[nextNum] = cnt[num] + digit;
                        Q.push(nextNum);
                    }
                } else if (digit == 5) {
                    delta = digit * pow(10, ptr);
                    nextNum = num - delta;

                    if (cnt.find(nextNum) == cnt.end() ||
                        cnt[nextNum] > cnt[num] + digit) {
                        cnt[nextNum] = cnt[num] + digit;
                        Q.push(nextNum);
                    }

                    delta = (10 - digit) * pow(10, ptr);
                    nextNum = num + delta;

                    if (cnt.find(nextNum) == cnt.end() ||
                        cnt[nextNum] > cnt[num] + (10 - digit)) {
                        cnt[nextNum] = cnt[num] + (10 - digit);
                        Q.push(nextNum);
                    }
                } else {
                    delta = (10 - digit) * pow(10, ptr);
                    nextNum = num + delta;

                    if (cnt.find(nextNum) == cnt.end() ||
                        cnt[nextNum] > cnt[num] + (10 - digit)) {
                        cnt[nextNum] = cnt[num] + (10 - digit);
                        Q.push(nextNum);
                    }
                }
            }
            ptr++;
        }
        cout << cnt[0] << "\n";
    }
}