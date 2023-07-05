#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const char basic[] = {'a', 'n', 't', 'i', 'c'};

int N, K;
int words[50 + 1];

void input(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		string str;
		cin >> str;
		for(char c : str){
			words[i] |= (1 << (c - 'a'));
		}
	}
}

int count(int mask){
	int cnt = 0;
	for(int word : words){
		if(word && (word & mask) == word) {
			cnt++;
		} 
	}
	return cnt;
}

int bitmasking(int index, int k, int mask){
	if(k < 0) return 0;
	if(index == 26) return count(mask);
	int ret = bitmasking(index+1, k-1, mask | (1 << index));  
	if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
		ret = max(ret, bitmasking(index+1, k, mask));
	}
	return ret;
}

int main(){
	fastio;	
	input();
	cout << bitmasking(0, K, 0) << endl;

	return 0;
}