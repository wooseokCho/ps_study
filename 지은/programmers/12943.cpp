#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    long long number = num;
    
    while (number != 1) {
        if (answer == 500) {
            answer = -1;
            break;
        } else {
            if(number % 2 == 0) {
                number = number / 2;
                answer++;
            } else {
                number = (number * 3) + 1;
                answer++;
            }
        }
    }
    return answer;
}