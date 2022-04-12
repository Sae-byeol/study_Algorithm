#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//parametric search: 이진탐색을 활용한 문제 풀이 기법으로 답이 될 수 있는 범위를 구하고 그 안에서 이진탐색으로 정답 찾기

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    //답의 범위 구하기 :1 ~ 제일 오래걸리는데에서만 심사받기
    //예제에서는 1 ~ 60
    long long start=0;
    long long end=(long long)times[times.size()-1] * n;
    long long mid=1;
    answer=end; // 일단 최대값으로 초기화
    while(start<=end){
        long long people=0;
        mid=(start+end)/2;
        
        for (long long i=0;i<times.size();i++){
            people+=mid/times[i]; // 시간 / 각 심사대 당 소요 시간 = 해당 심사대가 맡을 수 있는 사람 수
        };//이 부분을 생각하기 힘들었음...


        if (people >= n ){
            // 7명을 받을 수 있는 시간? -> 최소값이 아닌거임. 더 줄여도 됨
            // 6명(답) 받을 수 있는 시간? -> 6명 받을 수 있는 더 최소값 있는지 확실히 찾아봐야함
            if (answer> mid){
                // 똑같은 6명에 더 최소값이 나타났다면 answer 갱신
                answer=mid;
            }
            end=mid-1;
        }
        else if(people < n){
            //5명만 받을 수 있는 시간이라면 -> 더 뒤에서 찾자
            start=mid+1;
        }

    }
    return answer;
}