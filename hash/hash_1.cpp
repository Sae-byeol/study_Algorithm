#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //벡터 정렬하기
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    //중간에 다른 원소를 발견하거나
    //다 똑같은 경우에는 마지막 원소 하나가 미완주자
    bool result=false;
    for (int i=0;i<completion.size();i++){
        if(participant[i]!=completion[i]){
            answer=participant[i];
            result=true;
            break;
        }
    }
    if (result==false){
        answer=participant[completion.size()];
    }
    return answer;
}