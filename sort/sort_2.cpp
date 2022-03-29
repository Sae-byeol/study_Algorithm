#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//시도1. 각 숫자의 첫 자릿수로 정렬 -> 31, 384 의 경우 나머지 비교 시 1과 84? 부적절
//시도2. 벡터에 수 하나씩 넣어갈 때마다 수 뒤집어가며 뭐가 더 큰 지 비교
//예) 3,30 => 330 vs 303

bool cmp(string a, string b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for (int i=0;i<numbers.size();i++){
        str.push_back(to_string(numbers[i]));  
    }
    sort(str.begin(), str.end(), cmp);
    for (int i=0;i<str.size();i++){
        answer+=str[i];
    }
    if (answer[0] == '0') return "0";
    return answer;
}