#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, K;
	char crypt[29];
	vector<int> m;
	
    scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %d", &N, &K);
		scanf("%s", crypt);
		m.clear();
		int rot = N / 4;
		for (int j = 0; j < rot; j++){
			int index = j;
			int h = 0;
			int cindex = 0;
			char tmp[8];
			while (h < N){
				tmp[cindex] = crypt[index];
				cindex++;
				if (cindex == rot){
					tmp[cindex] = '\0';
					cindex--;
					int pow = 1;
					int sum = 0;
					for (cindex; cindex >= 0; cindex--){
						if (tmp[cindex] - '0' >= 0 && tmp[cindex] - '0' <= 9){
							sum += (pow * (tmp[cindex] - '0'));
						}
						else{
							sum += (pow * (tmp[cindex] - 'A' + 10));
						}
						pow *= 16;
					}
					cindex++;
					int len = m.size();
					int chk = 0;
					for (int k = 0; k < len; k++) if (m[k] == sum) chk++;
					if(!chk) m.push_back(sum);
				}
				h++;
				index++;
				if (index == N) index = 0;
			}
		}
		sort(m.begin(), m.end(), greater<int>());
		
		printf("#%d %d\n", i, m[K - 1]);
	}
}