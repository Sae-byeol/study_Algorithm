#include <string>
#include <vector>

using namespace std;
int dp[101][101];//dp: 길의 가짓수

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1]=1; //집의 위치
    for (int i=0;i<puddles.size();i++){
        //물 웅덩이는 -1
        dp[puddles[i][1]][puddles[i][0]]=-1;
    }
    for (int i=1; i<=n;i++){
        for (int j=1;j<=m;j++){
            if (dp[i][j]==-1){
                //물 웅덩이라면
                continue; //건너뛰기, 표 채울 필요 없음
            }
            else if (i==1 && j==1){
                continue;
            }
            else if (i!=1 && dp[i-1][j]!=-1){
                //위쪽이 웅덩이 아니라면
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=1000000007;//효율성테스트를 위해..(테스트값 중에 int 범위 넘는게 있는것같음)
            }
            if(j!=1 && dp[i][j-1]!=-1){
                //왼쪽이 웅덩이 아니라면
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=1000000007;
            }
        }
    }
    answer=dp[n][m];
    return answer;
}