#include <string>
#include <vector>

using namespace std;
//h를 하나씩 늘려가며 최댓값 구해보기
int solution(vector<int> citations) {
    int answer = 0;
    int h=0;
    while(1){
        int cnt=0;
        for (int i=0;i<citations.size();i++){
            if(citations[i] >= h){
                cnt++;
            }
        }
        if (cnt >=h){
            h++; //다음으로 넘어가기
        }
        
        else{
           answer=h-1;
           break;
        }
    }

    return answer;
}