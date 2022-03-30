#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//실패율 = 스테이지에 도달했으나 아직 클리어 못한 선수 수/ 스테이지 도달한 선수 수

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> tmpanswer;
    sort(stages.rbegin(), stages.rend());//6,4,3,3,2,2,2,1
    for (int i=1;i<=N;i++){
        //1번 스테이지에 대하여 
        double child=0;
        double parent=0;
        double tmp=0;
        for (int j=0;j<stages.size();j++){
            if (stages[j]<i){
                break;
            }
            parent++;
        }//도달한 선수 
        for (int j=0;j<stages.size();j++){
            if (stages[j]<=i){
                break;
            }
            child++;
        }
        if (parent !=0){
            tmp=child/parent;
        }
        tmpanswer.push_back(make_pair(tmp, i)); //실패율들 저장
    }
    sort(tmpanswer.begin(), tmpanswer.end()); //실패율 정렬
    for (int i=0;i<tmpanswer.size();i++){
        answer.push_back(tmpanswer[i].second);
    }
    
    return answer;
}