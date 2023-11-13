#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int b_num=-1;

    for (int i=0; i<arr.size(); i++) {
        if (b_num != arr[i]) {
            answer.push_back(arr[i]);
        }
        b_num=arr[i];
    }
    // unique 함수를 통해 중복 숫자 제거, erase를 통해 뒤에 남는 영역 제거할 수 있음
    // arr.erase(unique(arr.begin(), arr.end()),arr.end());
    return answer;
}