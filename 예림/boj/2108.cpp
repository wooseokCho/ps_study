#include <bits/stdc++.h>
using namespace std;

int N;
int A[500000];
map<int, int> m;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	double avg = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		avg += A[i];
		m[A[i]]++;
	}

	sort(A, A + N);

	int freqCnt = max_element(m.begin(), m.end(), compare)->second;
	vector<int> freq;
	
	for (auto p : m) {
		if (p.second == freqCnt) {
			freq.push_back(p.first);
		}
	}

	cout << int(round(avg / N)) << "\n";
	cout << A[N / 2] << "\n";
	cout << (freq.size() > 1 ? freq[1] : freq[0]) << "\n";
	cout << A[N - 1] - A[0] << "\n";
	
	return 0;
}