#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
int get_Ns(int N, int idx){
    int result= N;
    for (int i=1;i<=idx;i++){
        result=result*10+N;
    }
    return result;
}
int solution(int N, int number) {
    if (N==number){
        //주어진 N과 number가 같다면 N 한번 사용하면 끝
        return 1;
    }
    vector <unordered_set<int>> DP(8);
    //DP에 저장할 것: DP[i]: i+1개의 N으로 만들 수 있는 숫자들을 저장하는 set

    DP[0].insert(N);//1개의 N => N만 가능

    for (int k=1; k<8; k++){
        //DP[k]=일단 NNN...(K+1번 반복)
        DP[k].insert(get_Ns(N, k));

        //DP[k]에 사칙연산 결과도 넣기
        for (int i=0;i<k;i++){
            for (int j=0;j<k;j++){
                if (i+j+1 !=k){
                    continue;
                }
                //i+j+1==k일때 => i의 내용 k의 내용을 연산해서 넣으면 됨
                for (int a : DP[i]){
                    for (int b: DP[j]){
                        DP[k].insert(a+b);

                        if (a-b>0){
                            DP[k].insert(a-b);
                        }
                        DP[k].insert(a*b);

                        if(a/b >0){
                            DP[k].insert(a/b);
                        }
                    }
                }
            }
        }
        if (DP[k].find(number)!= DP[k].end()){
            //DP[k]에서 number 찾았으면 문제 해결!
            return k+1;
        }
    }
    return -1;
}