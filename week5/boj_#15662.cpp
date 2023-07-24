#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t, k;
deque<int> dq[1000 + 1];

void init(){
	for(int i=1;i<=t;i++){
		dq[i] = deque<int>(8, 0);
	}
}

void input(){
	cin >> t;
	init();
	for(int i=1;i<=t;i++){
		string str;
		cin >> str;
		for(int j=0;j<str.size();j++){
			dq[i][j] = str[j] - '0';
		}
	}
}

void rotateRight(int number){
	int x = dq[number][7];
	dq[number].pop_back();
	dq[number].push_front(x);
}

void rotateLeft(int number){
	int x = dq[number][0];
	dq[number].pop_front();
	dq[number].push_back(x);
}

int checkRight(int number){
	if(number == t) return 0;
	if(dq[number][2] == dq[number+1][6]) return 0;

	return checkRight(number+1) + 1;
}

int checkLeft(int number){
	if(number == 1) return 0;
	if(dq[number][6] == dq[number-1][2]) return 0;

	return checkLeft(number-1) + 1;
}

int countS(){
	int cnt = 0;
	for(int i=1;i<=t;i++){
		if(dq[i][0] == 1) cnt++;
	}
	return cnt;
}

int solution(){
	cin >> k;
	while(k--){
		int number, direct, chk = 0;
		cin >> number >> direct;
		int seq_1 = checkRight(number);
		int seq_2 = checkLeft(number);

		if(direct == 1){
			for(int i=number;i<=number+seq_1;i++){
				if(chk & 1) rotateLeft(i);
				else rotateRight(i);
				chk++;
			}

			chk = 0;
			for(int i=number-1;i>=number-seq_2;i--){
				if(chk & 1) rotateRight(i);
				else rotateLeft(i);
				chk++;
			}
		} else{	
			for(int i=number;i<=number+seq_1;i++){
				if(chk & 1) rotateRight(i);
				else rotateLeft(i);
				chk++;
			}

			chk = 0;
			for(int i=number-1;i>=number-seq_2;i--){
				if(chk & 1) rotateLeft(i);
				else rotateRight(i);
				chk++;
			}
		}
	}

	return countS();
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}
