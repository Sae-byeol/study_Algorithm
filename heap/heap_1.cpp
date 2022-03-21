#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //오름차순 우선순위큐 생성
    priority_queue<int,vector<int>, greater<int>> q;
    for (int i=0;i<scoville.size();i++){
        q.push(scoville[i]);
    }
    //빈 큐가 아니고 큐의 최솟값이 K보다 작은 경우 시작
    while(!q.empty() && q.top() < K){
        int a=0; int b=0;
        a=q.top();
        q.pop();
        //모든 음식의 스코빌 지수를 K이상으로 만들 수 없는 경우->안끝났는데 하나만 남아있던 경우
        //-1 리턴
        if (q.empty()){
            return -1;
        }
        b=q.top();
        q.pop();
        answer++;
        if (K<=a+b*2){
            //다음 원소가 남아있는 경우 / 이게 마지막 원소인 경우
            if (!q.empty() && q.top()>=K ){
                break;
            }
           else if (q.empty()){
               break;
           }
        }
        
        q.push(a+b*2);
    }
    return answer;
}