#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// https://www.acmicpc.net/problem/9935

string str, op;

void input(){
	cin >> str >> op;
}

string solution(){
	string ret = "";
	for(auto &c : str){
		if(ret.length() >= op.length()){
			if(ret.substr(ret.size()-op.size(), op.size()) == op){
				ret.erase(ret.size()-op.size(), op.length());
			}
		}
		ret += c;
	}
	if(ret.length() >= op.length()){
		if(ret.substr(ret.size()-op.size(), op.size()) == op){
			ret.erase(ret.size()-op.size(), op.length());
		}
	}
	
	return ret.length() == 0 ? "FRULA" : ret;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}