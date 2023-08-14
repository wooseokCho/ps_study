#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> divisor(int n) {
    int d = 2;
    vector<int> divisors;
    divisors.push_back(1);
    
    while (n != 1) {
        if ((n % d) == 0) {
            n = n / d;    
            divisors.push_back(d);
        }   
        else {
            d += 1;
        }
    }
    return divisors;
}
    
vector<int> solution(int n, int m) {
    vector<int> answer;

    vector<int> n_divisors, m_divisors;
    vector<int>::iterator iter;
    
    n_divisors = divisor(n);
    m_divisors = divisor(m);
    
    // 벡터 크기 정의 중요, n_divisors.size()
    // 공약수가 1, 2 / 1, 5 인 경우 union 1, 2, 5까지 저장해야함으로 아래와 같이 저장 필요
    vector<int> nm_union(n_divisors.size() + m_divisors.size());
    vector<int> nm_inter(std::min(n_divisors.size(), m_divisors.size())); 
    
    iter = set_union(n_divisors.begin(), n_divisors.end(), m_divisors.begin(), m_divisors.end(), nm_union.begin());
    nm_union.resize(iter - nm_union.begin());
    
    iter = set_intersection(n_divisors.begin(), n_divisors.end(), m_divisors.begin(), m_divisors.end(), nm_inter.begin());
    nm_inter.resize(iter - nm_inter.begin());
    
    int tmp = 1;
    
    for (int i=0; i < nm_inter.size(); i++) {
        tmp *= nm_inter[i];
    }
    answer.push_back(tmp);
    tmp = 1;
    
    for (int i=0; i < nm_union.size(); i++) {
        cout<<nm_union[i]<<" ";
        tmp *= nm_union[i];
    }
    answer.push_back(tmp);

    return answer;
}

// 아래와 같이 간단하게 작성도 가능
// for문 두번 돌리게 하지말고, 비슷한 일을 하면 함께 수행할 수 있는지 생각해보기
// if(((a%i) == 0) && ((b%i) == 0)){
//   answer.push_back(i);
//   answer.push_back((a*b)/i);
//   break;
// }