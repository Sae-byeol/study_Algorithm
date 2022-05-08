#include <string>
#include <vector>

using namespace std;
//dfs
//깊이우선으로 탐색하다가 간선이 없으면 네트워크 개수 +1
//재귀 종료: 더이상 연결된 컴퓨터 없을 경우
bool check[200];

void dfs(int start, int n, vector<vector<int>> computers ){
    //방문 표시
    check[start]=true;

    //현재 컴퓨터와 연결된 컴퓨터들 탐색
    for (int i=0;i<n;i++){
        //방문하지 않았고, 연결되어 있다면 재귀함수 호출
        if (check[i]!=true && computers[start][i]==1){
            dfs(i, n, computers);
        } 
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i=0;i<n;i++){
        //아직 검사하지 않은 컴퓨터라면 탐색 시작
        if (check[i]!=true){
            dfs(i, n, computers);
             //더이상 연결된 거 없어서 재귀 끝나면 네트워크 수 증가
            answer++;
        }
       
    }
    return answer;
}