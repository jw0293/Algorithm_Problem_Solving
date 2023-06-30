#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, ret = -INF;
string str;
vector<int> num;
vector<char> op;

void input(){
	cin >> N;
	cin >> str;
}

int getValue(char x, int a, int b){
	if(x == '+') return a + b;
	if(x == '*') return a * b;
	if(x == '-') return a - b;
	return 0;
}

void init(){
	for(int i=0;i<str.size();i++){
		if(i & 1) op.push_back(str[i]);
		else num.push_back(str[i] - '0');
	}
}

void go(int index, int sum){
	if(index == num.size()-1){
		ret = max(ret, sum);
		return;
	}

	go(index + 1, getValue(op[index], sum, num[index+1]));
	if(index + 2 <= num.size()-1) {
		int next = getValue(op[index+1], num[index+1], num[index+2]);
		go(index+2, getValue(op[index], sum, next));
	}
}

void solution(){
	init();
	go(0, num[0]);
	cout << ret << endl;
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}