#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //노란색의 약수들을 구하기
    vector<pair<int , int>> yellowNum; //세로, 가로 순

    int i=1;
    while(1){
        if (yellow%i ==0){
            //나누어떨어지면 약수 맞음
            yellowNum.push_back(make_pair(i, yellow/i));
        }
        //9와 같은 경우는 <1,9>, <3,3> 후 break
        if (i==yellow/i){
            break;
        }
        i++; //예를 들어 24의 경우 <4,6>하고 i가 6되었을때 더이상 push_back 안하고 break
        if (yellowNum.back().second == i){
            break;
        }
    }
   
    //후보들 중 brown수와 비교하여 정답 고르기
    for (int i=0;i<yellowNum.size();i++){
        if((yellowNum[i].first+2)*2 + (yellowNum[i].second+2)*2==brown+4){
            answer.push_back(yellowNum[i].second+2);
            answer.push_back(yellowNum[i].first+2);
        }
    }
    return answer;
}