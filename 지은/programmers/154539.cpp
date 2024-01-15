#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int len = numbers.size();
    vector<int> answer(len, -1);
    stack<int> stk;
    
    for (int i = 0; i < len; i++) {
        while (!stk.empty() && numbers[stk.top()] < numbers[i]) {
            answer[stk.top()] = numbers[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    return answer;
}