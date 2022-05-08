#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool check[1000];
vector <string> res;

bool DFS(string start, vector<vector<string>> tickets, int cnt ){
    if (cnt==tickets.size()) return true; // 항공권 모두 사용했으면 true 리턴

    for (int i=0;i<tickets.size();i++){
        //아직 방문 안했고 우리가 찾는 해당 출발지인 경우만
        if (check[i]!=true && tickets[i][0]==start){
            check[i]=true;
            res.push_back(tickets[i][1]); //해당 도착지를 경로에 추가 
            bool resbool=DFS(tickets[i][1], tickets, cnt+1);
            if (resbool){
                //항공권 모두 사용
                return true;
            }
            check[i]=0;
        }
    }
    res.pop_back(); //<- ?? 이 부분이 어려움
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    //알파벳 순으로 정렬
    sort(tickets.begin(), tickets.end());
    string start="ICN";
    res.push_back(start);//무조건 경로의 시작은 인천
    DFS(start, tickets, 0);

    answer=res;
    return answer;
}