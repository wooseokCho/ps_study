#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    if (cacheSize == 0) {
        answer = 5 * cities.size();
        return answer;
    }
    
    for (auto& city: cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) {
            cache.erase(it);
            answer++;
        } else {
            if (cache.size() >= cacheSize) {
                cache.pop_front();
            }
            answer += 5;
        }
        cache.push_back(city);
    }
    
    return answer;
}