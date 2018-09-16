#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct ctoc{
	int comp;
	double noise;
	bool operator < (const ctoc& p) const{
		if (abs(noise - p.noise) < 1e-9) return comp < p.comp;
		return noise > p.noise;
	}
};
vector <ctoc> route[10000];
int visit[10000];
int main(){
	int n, i, j, com, hs, a, b;
	double noise;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &com, &hs);
		for (j = 0; j < com; j++){
			route[j].clear();
			visit[j] = 0;
		}
		for (j = 0; j < hs; j++){
			scanf("%d %d %lf", &a, &b, &noise);
			route[a].push_back({ b, noise });
			route[b].push_back({ a, noise });
		}
		priority_queue<ctoc> pq;
		double cost[10000] = {};
		pq.push({ 0, 1 });
		cost[0] = 1;
		visit[0] = 1;
		while (!pq.empty()){
			int cur = pq.top().comp;
			double curn = pq.top().noise;
			pq.pop();
			if (cur == com - 1) break;
			for (j = 0; j < route[cur].size(); ++j){
				int next = route[cur][j].comp;
				double nextn = cost[cur] * route[cur][j].noise;
				if (visit[next] == 0 || cost[next] > nextn){
					visit[next] = 1;
					cost[next] = nextn;
					pq.push({ next, nextn });
				}
			}
		}
		printf("%.10f\n", cost[com - 1]);
	}
}