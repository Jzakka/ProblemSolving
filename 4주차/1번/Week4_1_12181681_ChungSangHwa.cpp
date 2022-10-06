#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct item {
	int weight, price;

	item(int w, int p):weight(w), price(p) {}

	bool operator < (const item i) const {
		return this->price / this->weight < i.price / i.weight;
	}
};

int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		priority_queue<item> items;

		vector<int> pepper(n);
		for(int i = 0; i < n; i++) {
			int w;
			cin >> w;
			pepper[i] = w;
		}

		vector<int> price(n);
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			price[i] = p;
		}

		for (int i = 0; i < n; i++) {
			items.push(item( pepper[i], price[i] ));
		}

		int totalW = 0;
		int priceSum = 0;
		while (!items.empty() && totalW<k)
		{
			auto biggest = items.top();
			items.pop();
			if (biggest.weight < k - totalW) {
				totalW += biggest.weight;
				priceSum += biggest.price;
			}
			else {
				priceSum += biggest.price / biggest.weight * (k - totalW);
				totalW = k;
			}
		}

		cout << priceSum << "\n";
	}
	
}