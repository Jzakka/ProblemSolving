#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<deque<int>> towers(3);

void debug(int k);

void mv(int n, int &k, int curr, int dest) {
    if (k == 0) return;

    if (n == 1) {
        while (!towers[curr].empty() && towers[curr].front()==1){
            towers[curr].pop_front();
            towers[dest].push_front(1);
            k--;
            if (k == 0) return;
        }
        return;
    }

    unsigned subDest;
    for (subDest = 0; subDest < 3; subDest++) {
        if (subDest != curr && subDest != dest)
            break;
    }
    mv(n - 1, k, curr, subDest);
    if (k == 0) return;

    while (!towers[curr].empty() && towers[curr].front()==n){
        towers[curr].pop_front();
        towers[dest].push_front(n);
        k--;
        if (k == 0) return;
    }

    mv(n - 1, k, subDest, dest);
}


void printTower2() {
    if (towers[1].empty()) {
        cout << 0;
    } else {
        for (auto it = towers[1].begin(); it != towers[1].end(); it++) {
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
        int n, m, k;
        cin >> n;
        for (int i = 1; i <=n; i++) {
            cin >> m;
            while (m--) {
                towers[0].push_back(i);
            }
        }
        cin >> k;

        mv(n, k, 0, 2);

        printTower2();

        init();
    }
}

void debug(int k) {
    cout << "==========\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "번째 탑 k=" << k << "\n";
        if(towers[i].empty()) continue;
        for (auto it = towers[i].end()-1; it != towers[i].begin()-1; it--) {
            cout << *it << " ";
        }
        cout << "\n";
    }
    cout << "===========\n";
}