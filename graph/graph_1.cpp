#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> graph(n+1);

    for (int i=0;i<edge.size();i++){
        int from=edge[i][0];
        int to=edge[i][1];

        graph[from].push_back(to);
        graph[to].push_back(from);//이차원벡터로 그래프 구현
    }
    vector<int> dist(n+1, -1); //1번 노드부터 i노드까지의 최단 거리를 저장하기 위한 벡터
    queue<int> q;
    
    dist[1]=0;
    q.push(1);//현재 1번

    while(!q.empty()){
        int current=q.front();
        q.pop();//현재 위치 복사 후 pop

        for (int next : graph[current]){
            //현재 위치와 연결된 노드들에 대해서
            if (dist[next]==-1){
                //아직 거리 안구한 노드라면(간 적 없는 노드)
                //이미 거리 구해진 노드는 그게 최단거리니까 패스
                dist[next]=dist[current]+1;
                q.push(next); //다음에 갈 노드들 큐에 넣어두기
            }
        }
    }//모든 노드 탐색

    int far=*max_element(dist.begin(), dist.end());//제일 먼 노드

    //제일 먼 노드 개수 구하기
    for (int i=0;i<dist.size();i++){
        if (dist[i]==far)
            answer++;
    }



    return answer;
}