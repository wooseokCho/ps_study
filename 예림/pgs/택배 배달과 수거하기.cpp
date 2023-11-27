#include <bits/stdc++.h>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> D, P;

    for(int i = 0; i < n; i++) {
        if(deliveries[i]) {
            D.push(i);
        }
        if(pickups[i]) {
            P.push(i);
        }
    }

    while(!D.empty() && !P.empty()) {
        answer += (max(D.top(), P.top()) + 1) * 2;

        int truck = 0;
        while(!D.empty() && truck < cap) {
            if(truck + deliveries[D.top()] <= cap) {
                truck += deliveries[D.top()];
                D.pop();
            } else {
                deliveries[D.top()] -= cap - truck;
                break;
            } 
        }

        truck = 0;
        while(!P.empty() && truck < cap) {
            if(truck + pickups[P.top()] <= cap) {
                truck += pickups[P.top()];
                P.pop();
            } else {
                pickups[P.top()] -= cap - truck;
                break;
            }
        }
    }

    while(!D.empty()) {
        answer += (D.top() + 1) * 2;
        int truck = 0;
        while(!D.empty() && truck < cap) {
            if(truck + deliveries[D.top()] <= cap) {
                truck += deliveries[D.top()];
                D.pop();
            } else {
                deliveries[D.top()] -= cap - truck;
                break;
            }
        }
    }

    while(!P.empty()) {
        answer += (P.top() + 1) * 2;
        int truck = 0;
        while(!P.empty() && truck < cap) {
            if(truck + pickups[P.top()] <= cap) {
                truck += pickups[P.top()];
                P.pop();
            } else {
                pickups[P.top()] -= cap - truck;
                break;
            }
        }
    }

    return answer;
}