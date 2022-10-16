#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//LCA 알고리즘
//두 노드의 공통조상을 찾는 알고리즘

vector<int> adjMatrix[100001];
//parent[x][y] 는 노드x의 2^y번째 조상
int parent[100001][18];
int level[100001];
const int MAX_LEVEL = (int) floor(log2(100001));

int lcaAlgorithm(int a, int b) {
    if (a == 1 || b == 1)return 1;

    int target = a, compare = b;// target이 움직일놈, compare가 고정된 놈
    if(level[a] < level[b]) swap(target, compare);

    if (level[target] != level[compare]) {//비교노드의 레벨이 같아질 때까지 반복
        for (int i = MAX_LEVEL; i >= 0; i--) {//레벨 차이를 최대부터 비교시작
            if (level[parent[target][i]] >= level[compare]) { // 레벨이 더 크다 == 리프노드에 더 가깝다
                target = parent[target][i];
            }
        }
        //최대한 target을 위로 끌어 올림
        //한 번 올릴 때 2의 승수만큼 올라가므로 레벨 맞추기는 logN에 수행될 수 있다.
    }

    int ret = target;
    if (target != compare) {
        for (int i = MAX_LEVEL; i >= 0; i--) {
            if (parent[target][i] != parent[compare][i]) {
                target = parent[target][i];
                compare = parent[compare][i];
            }
            ret = parent[target][i];
        }
    }
    return ret;
}

void setTree(int node, int pnode, int lv) {
    level[node] = lv;
    parent[node][0] = pnode;

    //parent[node][i] 는 parent[parent[node][i-1]][i-1] 과 같음
    // 노드를 하나 추가할 때마다 루트를 바라보며 parent배열을 업데이트
    for (int i = 1; i <= MAX_LEVEL; i++) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (int i = 0; i < adjMatrix[node].size(); i++) {
        int childnode = adjMatrix[node][i];
        if (childnode == pnode) continue;
        setTree(childnode, node, lv + 1);
    }
}

void init(){
    for (int i = 0; i < 100001; i++) {
        adjMatrix[i] = vector<int>();
        for (int j = 0; j < 18; j++) {
            parent[i][j] = 0;
        }
        level[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> n >> m;

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;

            adjMatrix[u].push_back(v);
            adjMatrix[v].push_back(u);
        }

        setTree(1, 0, 1);

        vector<int> viruses;
        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;
            viruses.push_back(v);
        }

        int lca = viruses.front();
        for (auto it = viruses.begin(); it != viruses.end(); it++) {
            if (next(it) != viruses.end()) {
                lca = lcaAlgorithm(lca, *next(it));
            }
        }

        if (lca == 1) cout << -1 << "\n";
        else {
            int lcaParent = parent[lca][0];
            if (lca < lcaParent) swap(lca, lcaParent);
            cout << lcaParent << " " << lca << "\n";
        }

        init();
    }
}