#include<iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Comparator {
    bool operator()(pair<int, int> s1, pair<int, int> s2) const {
        return s1.first < s2.second;
    }
};

vector<pair<int, int>> sharks;
vector<int> aquarium;

void match(int& res) {
    auto ramda = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(ramda)> minHeap(ramda);

    auto it_shark = sharks.begin();
    for (auto it_aqua = aquarium.begin(); it_aqua != aquarium.end(); it_aqua++) {
        for (; it_shark != sharks.end() && (*it_shark).first <= *it_aqua; it_shark++) {
            minHeap.push(*it_shark);
        }

        while (!minHeap.empty()) {
            auto minimum = minHeap.top();
            if (minimum.second >= *it_aqua) {
                res++;
                minHeap.pop();
                break;
            } else {
                minHeap.pop();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            sharks.push_back({a, b});
        }

        while (m--) {
            int c;
            cin >> c;

            aquarium.push_back(c);
        }

        sort(aquarium.begin(), aquarium.end());
        sort(sharks.begin(), sharks.end());

        int res = 0;

        match(res);

        cout << res << "\n";
        aquarium.clear();
        sharks.clear();
    }
}


