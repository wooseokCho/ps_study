#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> stk;
    
    for (int i = 0; i < prices.size(); i++) {
        while (!stk.empty() && (prices[stk.top()] > prices[i])) {
            answer[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    
    while (!stk.empty()) {
        answer[stk.top()] = prices.size() - 1 - stk.top();
        stk.pop();
    }
    
    return answer;
}