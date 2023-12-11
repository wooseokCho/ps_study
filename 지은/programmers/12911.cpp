using namespace std;

int countOne(int n) {
    int count = 0 ;
    while (n != 0) {
        if (n % 2 == 1)
            count++;
        n /= 2;
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    int num = countOne(n);
    int count = 0;
    
    while (true) {
        if (countOne(++n) == num) {
            answer = n;
            break;
        }
    }
    
    return answer;
}