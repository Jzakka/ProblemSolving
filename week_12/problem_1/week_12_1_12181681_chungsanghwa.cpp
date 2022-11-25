#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int b, a, x;
        cin >> x >> a >> b;

        int t;

        int rabbit_dist = 2 * a;
        int biryong_dist = a + b;

        int rabbit_pos = 0;
        int biryong_pos = x;
        int time_delta = a + b;
        int time = 0;

        while (rabbit_pos + rabbit_dist < biryong_pos + a) {
            rabbit_pos += rabbit_dist;
            biryong_pos += biryong_dist;
            time += time_delta;
        }

        rabbit_pos += 2 * (biryong_pos - rabbit_pos);

        cout << rabbit_pos << "\n";
    }
}