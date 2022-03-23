#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    vector<int> q;

    for (string word : operations){
        //연산 하나씩 실행
        string operation=word.substr(0,1);
        int num=stoi(word.substr(2));

        if (operation=="I"){
            //삽입
            q.push_back(num);
            sort(q.begin(), q.end());//삽입 후 꼭 오름차순 정렬하기
        }
        else{
            //삭제
            if (q.empty())
                continue;
            if (num==1){
                //최댓값(벡터의 맨 끝) 삭제
                q.erase(q.begin()+q.size()-1);
            }
            else{
                //최솟값
                q.erase(q.begin());
            }
        }
    }

    //값 만들기
    if (!q.empty()){
        answer.clear();//초기값으로 넣어둔 0,0 삭제
        answer.push_back(q.back());
        answer.push_back(q.front());
    }
    return answer;
}