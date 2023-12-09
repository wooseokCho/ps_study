#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getGCD(int a, int b) {
    int maxV = max(a, b);
    int minV = min(a, b);
    
   while (minV != 0) {
        int temp = minV;
        minV = maxV % minV;
        maxV = temp;
    }
    
    return maxV;
}

int getLCM(int a, int b) {
    return a * b / getGCD(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        answer = getLCM(answer, arr[i]);
    }
    
    return answer;
}