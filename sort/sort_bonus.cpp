#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//실패율 = 스테이지에 도달했으나 아직 클리어 못한 선수 수/ 스테이지 도달한 선수 수
bool cmp(pair<double, int> p1, pair<double, int> p2){
    //내림차순 정렬인데 값이 같은경우엔 인덱스 작은 순대로
    if(p1.first== p2.first){
       return p1.second< p2.second;
    }
    else {
        return p1.first > p2.first;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> tmpanswer;
    sort(stages.rbegin(), stages.rend());//6,4,3,3,2,2,2,1
    for (int i=1;i<=N;i++){
        double child=0;
        double parent=0;
        double tmp=0;
        //도달한 선수
        for (int j=0;j<stages.size();j++){
            if (stages[j]<i){
                break;
            }
            parent++;
        }
        //도달했지만 성공 못한 선수
        for (int j=0;j<stages.size();j++){
            if (stages[j]==i){
               child++;
            }
        }
        if (parent!=0){
            tmp=child/parent;
        }
        tmpanswer.push_back(make_pair(tmp, i)); //실패율들 저장
    }
    
    sort(tmpanswer.begin(), tmpanswer.end(),cmp); //실패율 내림차순정렬
    for (int i=0;i<tmpanswer.size();i++){
        answer.push_back(tmpanswer[i].second);
    }
    
    return answer;
}