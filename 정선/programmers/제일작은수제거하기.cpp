#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int min_idx, min_value;
    min_idx = 0;
    min_value = arr[0];
    
    if (arr.size() == 1) {
        return vector<int>(1,-1);
    }
    
    for (int i=1; i<arr.size(); i++) {
        if (min_value > arr[i]) {
            min_value = arr[i];
            min_idx = i;
        }
    }

    // 아래와 같이 algorithm 함수의 min_element와 find 함수를 사용해 찾을 수도 있음
    // int nMin = *min_element(arr.begin(), arr.end());
    // int pos = find(answer.begin(), answer.end(), nMin) - answer.begin();


    arr.erase(arr.begin() + min_idx);
    
    return arr;
}