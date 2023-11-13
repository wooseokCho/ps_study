#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long num_l = num;
    
    while (num_l != 1 && answer <= 500) {
        // cout<<num_l<<" ";
        if (num_l % 2) {
            num_l = (num_l * 3 + 1) / 2;
            answer += 2;
        }
        else if (num_l % 2 == 0) {
            num_l /= 2;
            answer += 1;
        }
    }
    if (answer > 500) {
        return -1;
    }
    return answer;
}



/* 
// 다른 사람 풀이.. 문제 범위 변경으로 인한 long long 변환은 필수적인듯
// if문 대신 3항 연산자를 사용하면 더 깔끔히 쓸 수 있음 

// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include<iostream>
using namespace std;

int collatz(int num)
{
    int answer = 0;
  cout<< num <<"\n";
  while(answer++ <= 500){
    num = num%2 ==0 ? num/2 : num*3+1;
    if(num == 1) break;
  }

    return answer > 500 ? -1 : answer;
}

int main()
{
    int testCase = 6;
    int testAnswer = collatz(testCase);

    cout<<testAnswer;
}
*/