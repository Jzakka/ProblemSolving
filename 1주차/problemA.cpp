#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int euclidean(int a, int b)
{
    // std::cout << "a: " << a << " b: " << b << "\n";
    int remainder;
    while((remainder = b%a)!=0){
        b= a;
        a = remainder;
    }
    return a;
}

int gongyaksu(std::vector<int> &v)
{
    std::sort(v.begin(), v.end());
    auto it = v.begin();

    int result = *it;
    while (it+1!=v.end())
    {
        // std::cout << "it: " << *it << "\n";
        result = euclidean( result, *(++it));
        // std::cout << "result: " << result << "\n";
    }
    // std::cout << "endFunc\n" ;
    return result;
}



int calcYong(std::vector<int> &v1, std::vector<int> &v2)
{
    int counterYongOfV2 = gongyaksu(v2);
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1.at(i) % counterYongOfV2 == 0)
        {
            return -1;
        }
    }

    return counterYongOfV2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    /* std::vector<int> test;
    test.push_back(30);
    test.push_back(25);
    test.push_back(10);
    test.push_back(90);
    test.push_back(120);
    std::cout << gongyaksu(test); */


    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::vector<int> inha;
        std::vector<int> biryong;

        int a, b;
        std::cin >> a >> b;
        for (int s = 0; s < a; s++)
        {
            int soldier;
            std::cin >> soldier;
            inha.push_back(soldier);
        }

        for (int s = 0; s < b; s++)
        {
            int soldier;
            std::cin >> soldier;
            biryong.push_back(soldier);
        }

        std::cout << calcYong(inha, biryong) << " " << calcYong(biryong, inha) << "\n";
    }
}