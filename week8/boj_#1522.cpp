#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;

int solve(int idx, int len){
	int ret = 0;
	for(int i=idx;i<idx+len;i++){
		if(str[(i+1)%str.length()] == 'a') ret++;
	}
	return ret;
}

int solution(){
	cin >> str;
	int cnt = 0, ans = INF;
	for(int i=0;i<str.length();i++){
		if(str[i]=='b') cnt++;
	}
	for(int i=0;i<str.length();i++){
		ans = min(ans, solve(i, cnt));
	}
	return ans;
}

int main(){
	fastio;	
	cout << solution() << endl;

	return 0;
}