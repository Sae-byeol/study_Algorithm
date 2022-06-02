#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//최대 두명까지만 태울 수 있음!
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); //40,50,50,60=> 2
    
    int idx=0;
    while(idx <people.size()){
        int back=people.back();//60
        people.pop_back();//40,50,50 //맨 뒤에 있는 애 빼기(맨 앞에 있는 제일 가벼운 애랑 같이 태우거나 혼자 타거나)
        if (people[idx]+ back <=limit){
            //40, 60 한 배 가능
            answer++;
            idx++; //다음으로 넘어가기
        }
        else{
            //맨 뒤에 60 혼자 태우기
            answer++;
        }

    }
    return answer;
}