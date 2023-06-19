#include <bits/stdc++.h>
using namespace std;

map<string, int> m;    // {players, rank}

vector<string> solution(vector<string> players, vector<string> callings) {

	for (int i = 0; i < players.size(); i++) {
		m[players[i]] = i;
	}

	for (int i = 0; i < callings.size(); i++) {
		int nowIdx = m[callings[i]];
		string now = callings[i];

		int prevIdx = nowIdx - 1;
		string prev = players[prevIdx];

		swap(players[nowIdx], players[prevIdx]);

		m[now] = prevIdx;
		m[prev] = nowIdx;
	}

	return players;
}