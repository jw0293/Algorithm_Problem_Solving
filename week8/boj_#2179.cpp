#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 20000 * 100 + 5;
int nxt[MX][26];
int unused = 2, n;
const int ROOT = 1;

int c2i(char c){
	return c - 'a';
}

int insert(string &s){
	int cnt = 0, ret = -1;
	int cur = ROOT;
	for(auto c : s){
		if(nxt[cur][c2i(c)] == -1){
			if(ret == -1) ret = cnt;
			nxt[cur][c2i(c)] = unused++;
		}
		cnt++;
		cur = nxt[cur][c2i(c)];
	}
	return ret == -1 ? cnt : ret;
}

bool find(string &s){
	int cur = ROOT;
	for(auto c : s){
		if(nxt[cur][c2i(c)] == -1) return false;
		cur = nxt[cur][c2i(c)];
	}
	return true;
}

void init(){
	for(int i=0;i<MX;i++){
		fill(nxt[i], nxt[i]+26, -1);
	}
}

void input(){
	cin >> n;
	int ret = -1, len;
	string str, temp;
	vector<string> pos;
	for(int i=0;i<n;i++){
		cin >> str;
		pos.push_back(str);

		int len = insert(str);
		if(ret < len){
			ret = len;
			temp = str;	
		}
	}

	for(auto s : pos){
		if(s.size() < ret) continue;
		if(s.substr(0, ret) == temp.substr(0, ret)){
			cout << s << endl << temp << endl;
			break;
		}
	}
}

int main(){
	fastio;	
	init();
	input();

	return 0;
}