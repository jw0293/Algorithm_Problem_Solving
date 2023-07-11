#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

// https://www.acmicpc.net/problem/1912

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<int> num;
int psum[100000 + 1];

void input(){
	cin >> n;
	num = vector<int>(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> num[i];
		psum[i] = psum[i-1] + num[i];
	}
}

int solution(){
	int answer = -INF, ret = -INF;
	for(int i=1;i<=n;i++){
		ret = max(0, ret);
		ret = max(num[i], ret + num[i]);
		answer = max(answer, ret);
	}
	return answer;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}