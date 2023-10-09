#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s(nums.begin(), nums.end());
    int n = nums.size() / 2;
    
    if (s.size() < n)
        answer = s.size();
    else
        answer = n;
    
    return answer;
}