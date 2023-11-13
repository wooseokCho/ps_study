#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (int i=0; i < arr.size(); i++){
        if (arr[i] % divisor == 0){
            answer.push_back(arr[i]);}
}
    if (answer.size() == 0) {
        answer.push_back(-1);
        return answer;}
    // 혹은 아래와 같이 벡터 선언할 수 있음
    // return answer.empty() ? vector<int>(1, -1) : answer;
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

// ㅊㅏㅈㄱㅗ ㅈㅓㅇㄹㅕㄹㅎㅏㄴㅡㄴㄱㅔ ㅁㅏㅈㅈㅣ