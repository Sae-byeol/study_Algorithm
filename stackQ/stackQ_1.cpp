#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <int> q;
    //소요 일 수 계산하여 큐에 삽입
    for (int i=0;i<progresses.size();i++){
        //ex)2.5일 소요 => 3일 뒤 배포 가능 
        //따라서 +1 해주는 과정 필요함 
        if((100-progresses[i])%speeds[i] !=0){
            q.push(((100-progresses[i])/speeds[i])+1);
        }
        else{
             q.push(((100-progresses[i])/speeds[i]));
        }
       
    }
    
    while(!q.empty()){
        int cnt=0;
        int front =q.front();
        while(!q.empty() && q.front()<=front){
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}