#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string temp;
ll cache[30 + 1][30 + 1];

ll solution(int day, int cnt, int n_cnt, string temp){
	if(day == 2*n && temp.length() == 2*n) return 1;
	ll &ret = cache[cnt][n_cnt];
	if(ret != -1) return ret;
	ret = 0;
	if(cnt > 0) ret += solution(day+1, cnt-1, n_cnt+1, temp + "W");
	if(n_cnt > 0) ret += solution(day+1, cnt, n_cnt-1, temp + "H");
	return ret;
}

void input(){
	while(1){
		cin >> n;
		if(!n) break;
		memset(cache, -1, sizeof(cache));
		temp.clear();
		temp += "W";
		cout << solution(1, n-1, 1, temp) << endl;
	}
}


int main(){
	fastio;	
	input();

	return 0;
}