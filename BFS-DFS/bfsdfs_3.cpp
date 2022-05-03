#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//dfs 
int answer=50;
bool check[50];

bool checkword(string w, string s){
    //한 글자만 다른지 체크
    int cnt=0;
    for (int i=0;i<w.size();i++){
        if (w[i]!=s[i])
            cnt++;
    }
    if (cnt==1){
        return true;
    }
    else
        return false;
}
void dfs(string begin, string target,vector<string> words, int step){
    //현재의 answer값보다 step이 크면 더 탐색 안해도 됨(종료조건)
    if (answer<= step)
        return;
    //종료조건 : target 발견
    if(begin==target){
        answer = min(answer,step);
        return ;
    }
    
    //그때그때 방문 안한 애들 중 한 글자만 다른 애들로 재귀
    for (int i=0;i<words.size();i++){
        //단어 탐색
        if (!check[i]&& checkword(begin, words[i])){
            //아직 방문안했고 변환가능한 단어가 있다면 => 재귀 호출
            check[i]=true;
            dfs(words[i], target, words,step+1);
            check[i]=false;//백트래킹: 이 부분을 생각하기 힘들었음. 
        }
    }
    
    return; 
}
int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, words,0);
    if(answer == 50)
        return 0;

    return answer;
}