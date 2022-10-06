#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		vector<bool> thereIs(26, false);
		vector<bool> checked(26, false);
		string origin, emped;

		cin >> origin >> emped;

		for (auto it = origin.begin(); it != origin.end(); it++) {
			thereIs[(*it) - 'A'] = true;
		}

		for (auto it = emped.begin(); it != emped.end(); it++) {
			checked[(*it) - 'A'] = true;
		}

		int i = 0;
		

		while (i<26)
		{
			if (thereIs[i] != checked[i]) break;
			i++;
		}

		cout << (i == 26 ? "YES\n" : "NO\n");
	}
}