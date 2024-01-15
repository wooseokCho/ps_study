#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int calculateFee(string in, string out) {
    int in_time = 60 * stoi(in.substr(0, 2)) + stoi(in.substr(3, 2));
    int out_time = 60 * stoi(out.substr(0, 2)) + stoi(out.substr(3, 2));
    
    return out_time - in_time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> parking;

    stringstream ss;
    string time, car_num, in_out;
    
    for (const auto& record: records) {
        ss.str(record);
        ss >> time >> car_num >> in_out;
        parking[car_num].push_back(time);
        ss.clear();
    }
    
    for (auto& item: parking) {
        if (item.second.size() % 2 == 1) {
            item.second.push_back("23:59");
        }
        
        int all_time = 0;
        for (int i = 0; i < item.second.size() - 1; i += 2) {
            all_time += calculateFee(item.second[i], item.second[i + 1]);
        }
        
        if (all_time > fees[0]) {
            int fee = fees[1] + (ceil((double)(all_time - fees[0]) / fees[2])) * fees[3];
            answer.push_back(fee);
        } else {
            answer.push_back(fees[1]);
        }
    }
    
    return answer;
}