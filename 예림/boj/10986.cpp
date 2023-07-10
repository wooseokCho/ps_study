#include <bits/stdc++.h>
using namespace std;

int N, M;
long long C[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	long long answer = 0;
	long long sum = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		sum += a;	// 1. 구간 합 구하기

		int remainder = sum % M;	// 2. M으로 나눈 나머지 구하기

		if (remainder == 0) {	// 구간 0 ~ i을 M으로 나눈 나머지가 0인 경우 
			answer++;
		}

		C[remainder]++;	// 3. 각 나머지의 개수 구하기
	}

	for (int i = 0; i < M; i++) {	// 4. 나머지의 개수 별로 2개를 뽑는 (구간 시작과 끝) 경우의 수 구하기 = 조합
		answer += C[i] * (C[i] - 1) / 2;
	}

	cout << answer;

	return 0;
}
