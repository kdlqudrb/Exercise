#include <bits/stdc++.h>
using namespace std;

struct desk{
	int avail;
	int lastTime;
	int cusnum;
};

struct customer{
	int num;
	int A;
	int arrive;
};

int N, M, K, A, B, answer;
int aj[10], bj[10];
struct desk reception[10];
struct desk repair[10];
queue<struct customer> wait_reception;
queue<struct customer> wait_repair;

int chk(){
	for (int i = 1; i <= N; i++) if (!reception[i].avail) return 1;
	for (int i = 1; i <= M; i++) if (!repair[i].avail) return 1;
	return 0;
}

int main(){
	int T, tmp;
    
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		answer = 0;

		for (int j = 1; j <= N; j++){
			scanf("%d", &aj[j]);
			reception[j].avail = 1;
		}
		for (int j = 1; j <= M; j++){
			scanf("%d", &bj[j]);
			repair[j].avail = 1;
		}
		for (int j = 0; j < K; j++){
			scanf("%d", &tmp);
			struct customer p;
			p.num = j + 1;
			p.arrive = tmp;
			wait_reception.push(p);
		}

		int ti = 0;
		while (!wait_reception.empty() || !wait_repair.empty() || chk()){
			for (int j = 1; j <= N; j++){
				if (!reception[j].avail){
					reception[j].lastTime--;
					if (reception[j].lastTime == 0){
						reception[j].avail = 1;
						struct customer temp;
						temp.A = j;
						temp.arrive = ti;
						temp.num = reception[j].cusnum;
						wait_repair.push(temp);
					}
				}
			}

			if (!wait_reception.empty()){
				struct customer p = wait_reception.front();
				while (p.arrive <= ti){
					int chk = 0;
					for (int j = 1; j <= N; j++){
						if (reception[j].avail){
							chk++;
							reception[j].avail = 0;
							reception[j].lastTime = aj[j];
							reception[j].cusnum = p.num;
							break;
						}
					}
					if (!chk) break;
					wait_reception.pop();
					if(!wait_reception.empty()) p = wait_reception.front();
					else break;
				}
			}

			for (int j = 1; j <= M; j++){
				if (!repair[j].avail){
					repair[j].lastTime--;
					if (repair[j].lastTime == 0) repair[j].avail = 1;
				}
			}

			if (!wait_repair.empty()){
				struct customer p = wait_repair.front();
				while (p.arrive <= ti){
					int chk = 0;
					for (int j = 1; j <= M; j++){
						if (repair[j].avail){
							chk++;
							repair[j].avail = 0;
							repair[j].lastTime = bj[j];
							if (p.A == A && j == B) answer += p.num;
							break;
						}
					}
					if (!chk) break;
					wait_repair.pop();
					if (!wait_repair.empty()) p = wait_repair.front();
					else break;
				}
			}

			ti++;
		}

		if (!answer) answer = -1;
		printf("#%d %d\n", i, answer);
	}
}