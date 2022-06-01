#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int cnt=0;
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int help=0;//도움 받은 사람
    //여벌 있는 애가 도난 당한경우: 남을 도와줄 수 없고 자기만 도우면 됨
    for (int i=0;i<reserve.size();i++){
        for (int j=0;j<lost.size();j++){
            if (reserve[i] == lost[j]){
                reserve.erase(reserve.begin() + i--); //i--가 중요했음!!
                lost.erase(lost.begin()+j);
                break;
            }
        }
    }
    
    //reserve를 하나씩 탐색
    for (int i=0;i<reserve.size();i++){
        //reserve[i]-1 또는 reserve[i]+1이 lost에 존재하는 지 확인
        for (int j=cnt;j<lost.size();j++){
            if (reserve[i]+1==lost[j] || reserve[i]-1==lost[j]){
                help++;
                cnt=j+1;//이미 체육복 받은애는 다시 또 못받도록
                break; //3이 2,4 둘 다에게 빌려주진 못하도록
            }
        }
    }
    answer=n-lost.size()+help;
    return answer;
}