#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct Info{
	int prot;
	int fat;
	int car;
	int vit;
	int cost;
}Info;

int N, answer = INF;
int prot, fat, car, vit;
bool visited[15 + 1];
vector<Info> infos;
vector<vector<int>> ret;

void input(){
	cin >> N;
	cin >> prot >> fat >> car >> vit;
	infos = vector<Info>(N+1);
	for(int i=0;i<N;i++){
		cin >> infos[i].prot >> infos[i].fat >> infos[i].car >> infos[i].vit >> infos[i].cost;
	}
}

bool isValid(vector<Info> &temp){
	int s1=0, s2=0, s3=0, s4=0;
	for(auto &t : temp){
		s1 += t.prot;
		s2 += t.fat;
		s3 += t.car;
		s4 += t.vit;
	}
	return (s1 >= prot && s2 >= fat && s3 >= car && s4 >= vit);
}

int getCost(vector<Info> &temp){
	int cst = 0;
	for(auto &t : temp) {
		cst += t.cost;
	}
	return cst;
}

vector<int> getIndexVector(){
	vector<int> r;
	for(int i=0;i<N;i++){
		if(visited[i]){
			r.push_back(i+1);
		}
	}
	return r;
}

void solution(int index, vector<Info> &temp){
	if(isValid(temp)){
		int tempCost = getCost(temp);
		if(tempCost <= answer){
			if(tempCost == answer){
				ret.push_back(getIndexVector());
			} else{
				answer = tempCost;
				ret.clear();

				ret.push_back(getIndexVector());
			}
		}
		return;
	}
	if(index == N) return;

	for(int i=index;i<N;i++){
		if(!visited[i]){
			visited[i] = true;
			temp.push_back(infos[i]);

			solution(i+1, temp);

			visited[i] = false;
			temp.pop_back();
		}
	}
}

void output(){
	if(answer == INF) {
		cout << -1 << endl;
		return;
	}
	cout << answer << endl;
	sort(ret.begin(), ret.end());
	for(int i=0;i<1;i++){
		for(auto &r : ret[i]){
			cout << r << " ";
		}
		cout << endl;
	}
}

int main(){
	fastio;	
	input();
	vector<Info> ps;
	solution(0, ps);
	output();

	return 0;
}