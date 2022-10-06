#include <iostream>

std::string map;

bool const IS_STRAIGHT = true;
bool const IS_REVERSE = false;

/**
 * @brief 
 * 루프마다 수행될 함수
 * hp를 계산하고 hp가 0일 때마다 maxLen을 변경
 * @param hp 
 * @param end 
 * @param start 
 * @param maxLen 
 */
void hpCalc(int& hp, int& end, int& start, int& maxLen, bool straight){
    if(map.at(straight ? end: start)=='C') hp++;
    else hp--;
    if(hp==0){
        int temp = end - start + 1;
        maxLen = maxLen < temp ? temp : maxLen;
    }
}


/**
 * @brief 
 * 순방향 계산
 * 가시에 멈추면 여태까지 탐색한걸 넘어간다
 * 바로 다음 당근으로 이동하면 중복 탐색될 수도 있음
 * @return int 
 */
int straightCalc(){
    int start = 0;
    int maxLen = 0;
    int hp = 0;
    int end = start;
    const int mapLen = map.length();

    while(start<mapLen){
        for(;hp>=0 && end<mapLen;end++){
            hpCalc(hp, end, start, maxLen, IS_STRAIGHT);
        }
        hp=0;
        //start는 for문이 끝났을 때의 end로 이동한다.->구간 탐색후 다음 구간의 시작점으로 이동
        start = end;
        end = start;
    }

    return maxLen;
}

/**
 * @brief 
 * 순방향계산과 완전히 같은로직
 * 순방향과 반대로 start가 end를 끌고 간다고 생각하면 된다.
 * hp가 0일 때에만 maxLen을 수정하기 때문에 
 * 불가능한 경우에서 잘못된 값이 나올 걱정은 없다.(직접 그려보면 안전하다는 것을 알 수있음)
 * @return int 
 */
int reverseCalc(){
    int maxLen = 0;
    int hp = 0;
    const int mapLen = map.length();
    int end;
    int start = end = mapLen-1;

    while(end>=0){
        for(;hp<=0 && start>=0;start--){
            hpCalc(hp, end, start, maxLen, IS_REVERSE);
        }
        hp=0;
        end = start;
        start = end;
    }

    return maxLen;
}

int calcMaxLen(const std::string &map)
{
    int maxLen;
    /**
     * @brief 
     * straightCalc와 reverseCalc는 모두 O(n)의 시간복잡도를 가진다.
     * 두 함수 모두 start와 end가 끝에서 끝으로 가는대 2n의 시간이 소요되기 때문
     */
    int straightResult = straightCalc();
    int reverseResult = reverseCalc();
    maxLen = straightResult > reverseResult ? straightResult : reverseResult;

    return maxLen;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t-- > 0)
    {
        std::cin >> map;

        std::cout << calcMaxLen(map) << "\n";
    }
}
