#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1=0; int cnt2=0; int cnt3=0;
    vector<int> v1, v2, v3,cnts;
    v1={1,2,3,4,5};
    v2={2,1,2,3,2,4,2,5};
    v3={3,1,2,4,5};
    
    //1번 수포자 정답수 카운트
    for (int i=0;i<answers.size();i++){
        if (answers[i] == v1[i%5]){//[0,1,2,3,4] 반복
            cnt1++;
        }
    }
    //2번 수포자 정답수 카운트
    for (int i=0;i<answers.size();i++){
        if (answers[i] == v2[i%8]){//[0,1,2,3,4,5,6,7] 반복
            cnt2++;
        }
    }
    //3번 수포자 정답수 카운트
    for (int i=0;i<answers.size();i++){
        if (i%2!=0){
            //홀수라면
            if (answers[i] == v3[((i-1)/2)%5]){//[0,1,2,3,4] 반복
            cnt3++;
        }
        }
        else if (answers[i] == v3[(i/2)%5]){//[0,1,2,3,4] 반복
            cnt3++;
        }

    }
    //최다득점자 구하기
    if (cnt1>=cnt2 && cnt1>=cnt3){
        answer.push_back(1);
    }
    if (cnt2>=cnt1 && cnt2>=cnt3){
        answer.push_back(2);
    }
    if (cnt3>=cnt2 && cnt3>=cnt1){
        answer.push_back(3);
    }
    
   
    return answer;
}