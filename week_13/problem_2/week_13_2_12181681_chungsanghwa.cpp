#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

int graph[251][251];

void fluid_warshall(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] != INT32_MAX) {
				for (int k = 0; k < N; k++) {
					if (graph[k][i] != INT32_MAX && graph[k][i] + graph[i][j] < graph[k][j]) {
						graph[k][j] = graph[k][i] + graph[i][j];
					}
				}
			}
		}
	}
}

void init() {
	for (int i = 0; i < 251; i++) {
		for (int j = 0; j < 251; j++) {
			graph[i][j] = INT32_MAX;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		init();
		int n, m, q;
		cin >> n >> m >> q;
		int N = n;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u][v] = w;
			graph[v][u] = w;
		}

		fluid_warshall(N);

		while (q--) {
			int u, v;
			cin >> u >> v;
			cout << graph[u][v] << "\n";
		}
	}
}

/*
2
4 4 4
0 2 20
2 3 10
1 2 30
3 0 5
0 3
2 3
1 2
0 2
5 7 5
0 4 100
1 4 20
2 0 3
2 1 17
4 2 50
2 3 40
1 3 10
4 2
1 2
2 0
4 1
0 3
*/