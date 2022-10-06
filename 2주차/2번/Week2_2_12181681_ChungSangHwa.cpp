#include <iostream>
#include <set>

void doCommand(std::string basicString, std::multiset<int>& multiset1);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int m, n;
        std::cin >> m >> n;
        std::multiset<int> multiset;

        while (m--) {
            unsigned int d;
            std::cin >> d;
            multiset.insert(d);
        }
        while (n--) {
            std::string command;
            std::cin >> command;
            doCommand(command, multiset); //logM
        }

        std::cout << *multiset.begin() << " " << *multiset.rbegin() << "\n";
    }
}

//각 명령마다 O(longN)에 수행되야함
//멀티셋은 우선순위 큐와 같은 성질을 가지면서 끝 원소도 참조할 수 있는 개사기 stl
void doCommand(std::string command, std::multiset<int>& multiset1) {
    if (std::equal(command.begin(), command.end(), "Delete")) {
        std::string minOrMax;
        std::cin >> minOrMax;
        if (std::equal(minOrMax.begin(), minOrMax.end(), "min")) {
            multiset1.erase(multiset1.begin());
        } else {
            multiset1.erase(std::prev(multiset1.end())); //multiset의 반복자는 +, - 정수가 안됨, 그래서 std::prev써야함
        }
    } else {
        int num;
        std::cin >> num;
        multiset1.insert(num);
    }
}


