#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    //4177252841
    //k개 제거 : number의 앞부터 k+1개의 수 중에서 하나만 선택하여 총 k개를 제거한다고 생각
    //처음에 4,1,7,7,2 중에서 7선택하면 뒤에 바로 5,2,8,4,1 붙여서 6자리 가능
    //다음에 7,2,5 중에서 7 선택하면 뒤에 바로 2,8,4,1 붙여서 6자리 가능
    //이런 과정 반복
    int n=number.length()-k; //n=6
    for (int i=0, idx=-1; i<n;i++){
        //i=0,1,2,3,4,5 즉 6번반복하며 6자리 만들어내기
        char max='0';
        for (int j=idx+1; j<=k+i;j++){
            //인덱스 0부터 5까지 
            if(max < number[j]){
                max=number[j];
                idx=j;//최댓값 다음부터 다시 탐색
            }
        }
        answer+=max;
    }

    return answer;
}