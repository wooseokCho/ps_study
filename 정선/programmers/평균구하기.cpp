#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

	for(int n : arr) {
        answer += n;
    }
    
    answer /= arr.size();

    // 또는 배열의 합을 구하는 accumlate()를 이용해 더 간단히 해결 가능
    // answer = accumulate(arr.begin(), arr.end(), 0);
		
    return answer;
}