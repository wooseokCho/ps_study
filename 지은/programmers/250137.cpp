#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int straight = 0;
    int curHealth = health;
    int endIdx = attacks.size() - 1;
    int idx = 0;
    
    for (int time = 1; time <= attacks[endIdx][0]; time++) {
        if (time == attacks[idx][0]) {
            curHealth -= attacks[idx++][1];
            straight = 0;
            if (curHealth <= 0)
                break;
            continue;
        }
        curHealth = min(health, curHealth + bandage[1]);
        
        if (++straight == bandage[0]) {
            curHealth = min(health, curHealth + bandage[2]); 
            straight = 0;
        }
    }
    
    answer = (curHealth <= 0) ? -1 : curHealth;
    
    return answer;
}