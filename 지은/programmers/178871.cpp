#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players);
    map<string, int> m;
    
    for (int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); i++) {
        int tmp = m[callings[i]];
        m[callings[i]] = tmp - 1;
        m[answer[tmp - 1]] = tmp;
        
        string player = answer[tmp - 1];
        answer[tmp - 1] =  answer[tmp];
        answer[tmp] = player;
    }
   
    return answer;
}