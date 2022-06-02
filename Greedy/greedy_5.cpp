#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//크루스칼 알고리즘 사용
vector <int> parent(101);
bool cmp(vector <int> a, vector<int> b){
    //비용 적은것부터 정렬하도록
    return a[2]<b[2];
}

int findParent(int i){
    if (parent[i]==i)
        return i;
    return parent[i]=findParent(parent[i]);//최상위 부모 찾아 재귀
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //비용 적은것부터 정렬
    sort(costs.begin(), costs.end(), cmp);
    //parent 초기화
    for (int i=0;i<n;i++){
        parent[i]=i;
    }
    for (int i=0; i< costs.size();i++){
        int start=findParent(costs[i][0]);
        int end=findParent(costs[i][1]);
        int cost=costs[i][2];
        if (start!=end){
            //사이클이 안생기면 다리 추가
            answer+=cost;
            parent[end]=start; //부모노드 업뎃
        }
    }
    return answer;
}