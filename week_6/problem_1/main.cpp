#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> towers(3);

void debug(int k);

void mv(int n, int &k, int curr, int dest) {
    if (k == 0) return;

    if (n == 1) {
        towers[curr].pop_back();
        towers[dest].push_back(1);
        k--;
        return;
    }

    unsigned subDest;
    for (subDest = 0; subDest < 3; subDest++) {
        if (subDest != curr && subDest != dest)
            break;
    }
    mv(n - 1, k, curr, subDest);
    if (k == 0) return;

    towers[curr].pop_back();
    towers[dest].push_back(n);
    k--;

    mv(n - 1, k, subDest, dest);
}

void printTower2() {
    if (towers[1].empty()) {
        cout << 0;
    } else {
        for (auto it = towers[1].end() - 1; it != towers[1].begin() - 1; it--) {
            cout << *it << " ";
        }
    }

    cout << "\n";
}

void init() {
    int tSz = towers.size();
    for (int i = 0; i < tSz; i++) {
        towers[i].clear();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = n; i >= 1; i--) {
            towers[0].push_back(i);
        }

        mv(n, k, 0, 2);

        printTower2();

        init();
    }
}

void debug(int k){
    cout << "==========\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "번째 탑 k=" << k << "\n";
        for (auto it = towers[i].begin(); it != towers[i].end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
    }
    cout << "===========\n";
}