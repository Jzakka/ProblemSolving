#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>

#define CHECKED 2
#define FRINGE 1
#define UNCHECKED 0

using namespace std;

vector<int> status(1001);
vector<int> dist(1001, INT32_MAX);
vector<int> parent(1001);

unordered_map<int, vector<int>> map;

int getShortest(int src, int dest, int acc) {
    if (src == -1) return -1;
    // else if (src == dest) return acc;

    status[src] = CHECKED;
    dist[src] = acc;

    for (auto e : map[src]) {
        if (status[e] == FRINGE && dist[e] > acc + 1)
        {
            parent[e] = src;
            dist[e] = acc + 1;
        }
        else if (status[e] == UNCHECKED) {
            status[e] = FRINGE;
            parent[e] = src;
            dist[e] = acc + 1;
        }
    }

    int minNext = -1;
    int minDist = INT32_MAX;
    for (int i = 0; i < 1001; i++) {
        if (status[i] == FRINGE && dist[i]< minDist) {
            minNext = i;
            minDist = dist[i];
        }
    }

    return getShortest(minNext, dest, minDist);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        int hanyang = -1;
        int hanyangAlt = INT32_MAX;
        for (int i = 0; i < n; i++) {
            int alt;
            cin >> alt;

            if (alt < hanyangAlt) {
                hanyang = i;
                hanyangAlt = alt;
            }
        }

        for (int i = 0; i < m; i++) {
            int src, dest;
            cin >> src >> dest;

            map[src].push_back(dest);
            map[dest].push_back(src);
        }

        for (int i = 0; i < k; i++) {
            int dest;
            cin >> dest;

           
            getShortest(hanyang, dest, 0);
            cout << (dist[dest] == INT32_MAX ? -1 : dist[dest]) << "\n";
        }

        status = vector<int>(1001, 0);
        parent = vector<int>(1001, 0);
        dist = vector<int>(1001, INT32_MAX);

        map.clear();
    }
}