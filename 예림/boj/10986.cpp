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

		sum += a;	// 1. ���� �� ���ϱ�

		int remainder = sum % M;	// 2. M���� ���� ������ ���ϱ�

		if (remainder == 0) {	// ���� 0 ~ i�� M���� ���� �������� 0�� ��� 
			answer++;
		}

		C[remainder]++;	// 3. �� �������� ���� ���ϱ�
	}

	for (int i = 0; i < M; i++) {	// 4. �������� ���� ���� 2���� �̴� (���� ���۰� ��) ����� �� ���ϱ� = ����
		answer += C[i] * (C[i] - 1) / 2;
	}

	cout << answer;

	return 0;
}
