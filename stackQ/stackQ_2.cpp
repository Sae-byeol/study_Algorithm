#include <string>
#include <vector>
#include <queue>

using namespace std;
//구조체로 큐 우선순위 정렬 함수 직접 작성
struct cmp
{
    bool operator()(int a, int b){
    //내림차순 정렬 
    if ( a>b )
        return true;
}
};
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt=0;
    priority_queue<int, vector<int>, cmp > q;
    for (int i=0;i<priorities.size();i++){
        q.push(priorities[i]);
    }
    for (int i=0;i<priorities.size();i++){
        //우선순위 큐는 프론트, 레어 없음. top만 있음
        if (q.top() == priorities[location]){
            ++cnt;
            answer=cnt;
            return answer;
        }
        ++cnt;
        q.pop();
            
    }
    return answer;
}