#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*
 * O(nlogn)에 풀기
 * 중앙값을 가리키는 반복자를 관리하는 것이 포인트
 * 지난 d일 기록의 중앙값과 그 다음날을 비교해서 반복자의 위치를 하나씩 옮긴다
 *
 * 멀티셋의 크기는 항상 d가 되도록 유지해야하고 원소의 삭제에 lower_bound()를 이용하라.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;


        vector<int> history;
        int cnt = 0;
        while (n--) {
            int c;
            cin >> c;

            history.push_back(c);
        }
        multiset<int> last(history.begin(), history.begin() + d);
        auto mid = next(last.begin(), d / 2);

        for (int i = d;; i++) {
            if(i!=history.size() && (*mid + *prev(mid, 1 - d % 2)) <= history[i])
                cnt++;

            if (i == history.size()) {
                break;
            }

            last.insert(history[i]);
            if(history[i] < *mid)
                mid--;

            if (history[i - d] <= *mid)
                mid++;

            last.erase(last.lower_bound(history[i - d]));
        }

        cout << cnt << "\n";
    }
}