#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dictionary;
    string alphabet = "";
    
    for (int i = 0; i < 26; i++) {
        alphabet = 'A' + i;
        dictionary[alphabet] = i + 1;
    }
    
    for (int i = 0; i < msg.size();) {
        int length = 1;
        int index = dictionary[msg.substr(i, length)];
        
        while (index > 0 && i + 1 + length <= msg.size()) {
            if (dictionary[msg.substr(i, length + 1)] > 0) {
                length++;
                index = dictionary[msg.substr(i, length)];
            } else {
                break;
            }
        }
        
        answer.push_back(index);
        dictionary[msg.substr(i, length + 1)] = dictionary.size();
        i += length;
    }
    
    return answer;
}