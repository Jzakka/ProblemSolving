//
// Created by 정상화 on 2022/09/09.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <deque>

std::unordered_map<std::string, char> table;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        std::deque<char> result;
        std::unordered_map<std::string, int> distance;//비트 거리를 담는 해쉬맵

        char c = 'A';
        int n, m;//n = 알파벳 개수, m = 문자당 비트 길이
        std::cin >> n >> m;
        for (int i = 0; i < n; i++) {
            std::string alphabet;
            std::cin >> alphabet;

            table[alphabet] = c++;
            distance[alphabet] = 0;
        }

        int bitsLen;
        std::cin >> bitsLen;

        for (int i = 0; i < bitsLen; i++) {
            char input;
            std::cin >> input;

            for (auto &e: table) {
                if (e.first.at(i % m) != input)
                    distance[e.first]++;
            }

            /*if (i % m == m - 1) {
                for (auto &e: distance) {
                    std::cout << e.first << ": " << e.second << "\n";
                }
            }*/

            if (i % m == m - 1) {
                std::string minBit = "";
                int min = INT32_MAX;

                for (auto &e: distance) {
                    if (e.second < min) {
                        min = e.second;
                        minBit = e.first;
                    }
                }

                //결과에 minBit 추기
                result.push_back(table[minBit]);
                distance.clear();
            }
        }

        for (const auto &item: result) {
            std::cout << item;
        }
        std::cout << "\n";

        table.clear();
    }
}
