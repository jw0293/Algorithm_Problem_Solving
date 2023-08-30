#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isFind(string &temp, string &str){
	int idx = 0;
	for(auto &c : temp){
		if(c == str[idx]) idx++;
	}
	return idx == str.size();
}

int input(){
	string str;
	cin >> str;

	int val = 1;
	string temp = "";
	while(1){
		if(isFind(temp, str)) break;
		temp += to_string(val);
		val++;
	}
	return val-1;
}

int main(){
	fastio;	
	cout << input() << endl;

	return 0;
}