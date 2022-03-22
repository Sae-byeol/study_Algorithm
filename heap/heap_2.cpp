#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//시간 순으로 먼저 정렬하되 현재 작업이 끝나기 전 들어온 작업이 있다면 (대기 발생)
//그 때 길이로 대기큐에 줄 세우기
//현재 작업 종료 되면 대기큐에 있는 순서대로 실행


struct cmp{ //pair 사용 안하고 cmp 따로 지정해서 함 
    bool operator()(vector<int> a, vector<int> b){
        return a.at(1)> b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sum=0;
    int time=0;//현재 시간 
    //일단 시간 순 정렬
    sort(jobs.begin(), jobs.end());
    int start=jobs[0][0];
    //대기 큐 생성
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    /*sum+=start+jobs[0][1]-jobs[0][0];//첫 작업은 바로 수행 
    time=jobs[0][1]+jobs[0][0];//첫 작업 완료한 현재 시간 (3초)*/
    //첫 작업 따로 계산 하니까 시간초과 뜸 

    int i=0;
   while (i<jobs.size() || !q.empty())
   {
       if (i<jobs.size() && time >= jobs[i][0]){
           //대기큐 삽입
           q.push(jobs[i]);
           i++;
           continue;
       }
       if (!q.empty()){
           //위의 if문에 안걸린 경우 (대기 안해도 되는 경우 , 컨트롤러가 쉬고 있는 경우)
           //바로 pop 갸능
            time+=q.top()[1];// 현재 시간 증가
            sum+=time-q.top()[0];
            q.pop();
       }
        else //맨 처음 or 대기하는 큐도 없고 대기가 필요한 큐도 없는 경우 시간은 jobs의 요청시간으로 초기화 
            time=jobs[i][0];
       
   }

    answer=sum/jobs.size();
    return answer;
}