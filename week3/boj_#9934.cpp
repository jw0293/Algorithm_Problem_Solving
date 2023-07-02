#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int K;
vector<int> tree[10 + 1];

vector<int> input(){
	cin >> K;
	vector<int> temp;
	for(int i=0;i<(int)pow(2, K) - 1;i++){
		int x;
		cin >> x;
		temp.push_back(x);
	}
	return temp;
}

vector<int> getLeft(vector<int> &temp){
	vector<int> ret;
	for(int i=0;i<temp.size()/2;i++){
		ret.push_back(temp[i]);
	}
	return ret;
}

vector<int> getRight(vector<int> &temp){
	vector<int> ret;
	for(int i=temp.size()/2+1;i<temp.size();i++){
		ret.push_back(temp[i]);
	}
	return ret;
}

void go(int d, vector<int> temp){
	if(temp.size() == 1){
		tree[d].push_back(temp[0]);
		return;
	}

	go(d+1, getLeft(temp));
	tree[d].push_back(temp[temp.size()/2]);
	go(d+1, getRight(temp));
}

void output(){
	for(int i=1;i<=K;i++){
		for(auto &nxt : tree[i]){
			cout << nxt << " ";
		}
		cout << '\n';
	}
}

int main(){
	fastio;	
	vector<int> ps = input();
	go(1, ps);
	output();

	return 0;
}