#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i=0;i<phone_book.size()-1;i++){
        //뒤에 있는 애를 앞에 있는 애 길이만큼 잘라서 내용 비교
        if (phone_book[i+1].substr(0, phone_book[i].length())==phone_book[i]){
            answer=false;
            return answer;
        }
        
    }
    return answer;
}
