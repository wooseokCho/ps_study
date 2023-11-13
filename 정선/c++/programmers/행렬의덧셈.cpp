#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> tmp;
    
    int r, c;
    r = arr1.size();
    c = arr1[0].size();

    for (int i=0; i < r; i++) {
        for (int j=0; j < c; j++){
            tmp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(tmp);
        tmp.clear();
    }
    
    return answer;
}