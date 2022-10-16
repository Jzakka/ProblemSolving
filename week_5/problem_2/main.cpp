#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

struct Edge{
    string city;
    int time;

    Edge(const string &city, int time) : city(city), time(time) {}

    bool operator < (Edge e) const{
        return this->time < e.time;
    }
};

unordered_map<string, int> cityYear;
unordered_map<string, multiset<Edge>> busTable;
unordered_map<string, int> DP;  //다음 최장거리를 결정하는 노드는 사실상 기정적

int DFS(string startCity, int acc){
    if (DP.find(startCity) != DP.end()) {
        return acc + DP[startCity];
    }

    int result=acc;
    for (auto &edges: busTable[startCity]) {
        int sum=DFS(edges.city, acc + edges.time);
        if(result < sum) result = sum;
    }
    DP[startCity] = result-acc;
    return result;
}

void init(){
    cityYear.clear();
    busTable.clear();
    DP.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {

        int n,m;
        cin >> n >> m;
        while (n--) {
            string cityName;
            int year;
            cin >> cityName >> year;
            cityYear[cityName] = year;
        }
        while (m--) {
            string city1, city2;
            int time;
            cin >> city1 >> city2 >> time;

            if(cityYear[city1] == cityYear[city2]) continue;                //같은 년도는 어차피 가질 못함
            if(cityYear[city1] > cityYear[city2]) swap(city1, city2);//어차피 년도 순서대로만 갈 수 있음(단방향 설정해도됨)

            busTable[city1].insert(Edge(city2, time));
        }

        int result = 0;

        for(auto it = cityYear.begin();it!=cityYear.end();it++){
            auto start = *it;
            int temp = DFS(start.first, 0);
            if(result < temp) result = temp;
        }

        cout << result << "\n";
        init();
    }
}

//2
//7 9
//Incheon 2011
//Seoul 2012
//Daegu 2012
//Jeju 2017
//Daejeon 2015
//Busan 2016
//Suwon 2014
//Daegu Seoul 20
//Seoul Suwon 60
//Suwon Incheon 20
//Incheon Seoul 10
//Daegu Busan 125
//Suwon Busan 30
//Busan Jeju 45
//Busan Daejeon 70
//Daejeon Jeju 120
//10 15
//Ava 2001
//Akyab 2002
//Bagan 2002
//Bago 2003
//Mandalay 2004
//Mrawk 2005
//Naypyidaw 2005
//Prome 2006
//Toungoo 2007
//Yangon 2008
//Ava Akyab 15
//Ava Yangon 80
//Akyab Bagan 10
//Akyab Bago 20
//Bagan Mandalay 20 Bagan Mrawk 60
//Bago Mrawk 20
//Bago Yangon 50 Mandalay Prome 65 Naypyidaw Prome 70 Naypyidaw Toungoo 120 Prome Toungoo 45 Akyab Mrawk 20
//Bago Prome 80 Mrawk Prome 30
