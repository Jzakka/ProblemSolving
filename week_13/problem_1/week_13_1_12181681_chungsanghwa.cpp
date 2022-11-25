#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

vector<int> altitude(1001);
vector<bool> checked(1001);
vector<vector<int>> road(1001);
vector<int> result;
unordered_map<int, int> alt_reg;
unordered_map<int, int> reg_alt;

void dfs(int region) {
	if (checked[region] == true) return;

	checked[region] = true;
	result.push_back(region);

	for (auto incident : road[region]) {
		dfs(incident);
	}
}

void search() {
	for (auto alt : altitude) {
		dfs(alt_reg[alt]);
	}
}

void init() {
	altitude = vector<int>(1001);
	checked = vector<bool> (1001);
	road = vector<vector<int>> (1001);
	result.clear();
	alt_reg.clear();
	reg_alt.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		for (int i=0;i<n;i++)
		{
			int alt;
			cin >> alt;
			altitude[i] = alt;
			alt_reg[alt] = i;
			reg_alt[i] = alt;
			checked[i] = false;
		}
		while (m--)
		{
			int src, dest;
			cin >> src >> dest;

			road[src].push_back(dest);
			road[dest].push_back(src);
		}
		sort(altitude.begin(), altitude.begin()+n);
		for (auto& e : road) {
			sort(e.begin(), e.end(), [](int a, int b) {
				return reg_alt[b] > reg_alt[a];
				});
		}

		search();

		for (auto r : result) {
			cout << r << "\n";
		}

		init();
	}
}