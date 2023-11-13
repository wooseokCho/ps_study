#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            return "김서방은 " + to_string(i) + "에 있다";
        }
    }
}

// 아래와 같이 find 함수로 찾을 수도 있음 이때, 메모리위치 -> 0부터 시작하는 int로 변경하기 위해 begin 값 빼줘야 하는 것 주의 
// int pos=find(seoul.begin(),seoul.end(),"Kim")-seoul.begin();