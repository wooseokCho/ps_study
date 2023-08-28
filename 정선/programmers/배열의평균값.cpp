#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int n_size = numbers.size();
    for (int i=0; i<n_size; i++){
        answer += numbers[i];
    }
    return answer / double(n_size);
}