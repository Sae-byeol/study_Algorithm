#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
//소수: 2,3,5,7,11, ...
bool isPrime(int n){
    //소수 판별은 에라토스테네스의 체를 사용하는 것이 간편
    if (n<2) return false;
    for (int i=2; i<= sqrt(n); i++){
        if (n%i ==0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector <int> v;
    vector <int> nums;
    for (int i=0;i<numbers.size();i++){
        v.push_back(numbers[i]);
    }//"012"=> v에 0, 1, 2로 각각 저장
    sort(v.begin(), v.end()); // 0,1,2로 오름차순 정렬

    //만들 수 있는 모든 수 nums에 저장
    do{
        string temp="";
        for (int i=0;i<v.size();i++){//i=0,1,2
            temp.push_back(v[i]);
            nums.push_back(stoi(temp));//i=0일때 0, i=1일때 01, i=2일때 012
        }
    }while(next_permutation(v.begin(), v.end()));//next_permutation: 다음 순열이 존재하면 true(012, 021, 102, 120, 201, 210) 총 6번 true 반환
    
    //nums 안에 있는 중복값들 지우기
    sort(nums.begin(), nums.end());
    //unique(): 중복된 쓰레기값들 뒤에 모아두고 쓰레기값의 첫 원소를 반환 ex)12233->12323
    nums.erase(unique(nums.begin(), nums.end()),nums.end());

    for (int i=0;i<nums.size();i++){
        if (isPrime(nums[i])){
            answer++;
        }
    }
    return answer;
}