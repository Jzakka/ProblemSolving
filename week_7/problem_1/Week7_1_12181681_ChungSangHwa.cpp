#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		stack<int> stk;
		string s;
		cin >> s;
		for (auto it = s.begin(); it != s.end(); it++) {
			if(*it!='+' && *it!='*' && *it!='-')
				stk.push(*it-'0');
			else
			{
				int op1 = stk.top(); stk.pop();
				int op2 = stk.top(); stk.pop();
				int result;
				if (*it == '+') {
					result = op1 + op2;
				}
				else if (*it == '-') {
					result = op2 - op1;
				}
				else {
					result = op1 * op2;
				}
				stk.push(result);
			}
		}
		cout << stk.top() << "\n";
	}
}