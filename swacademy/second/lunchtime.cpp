#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, answer, pnum;
	int lmap[10][10];
	vector<pair<int, int> >people;
	vector<pair<int, int> >stair;
	vector<pair<int ,int> >s1, s2;

	scanf("%d", &T);
	for (int x = 1; x <= T; x++){
		answer = 987654321;
		people.clear();
		stair.clear();
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++){
				scanf("%d", &lmap[j][k]);
				if (lmap[j][k] == 1){
					people.push_back(make_pair(j, k));
				}
				else if (lmap[j][k] > 1){
					stair.push_back(make_pair(j, k));
				}
			}

		pnum = people.size();
		int upper_bound = 1 << pnum;
		int s1_num, s2_num;
		int ti = 987654321;
		for (int i = 0; i < upper_bound; i++){
			s1.clear();
			s2.clear();
			s1_num = s2_num = 0;
			for (int j = 0; j < pnum; j++){
				if (i & 1 << j){
					int tmp = abs(people[j].first - stair[1].first);
					tmp += abs(people[j].second - stair[1].second);
					if (tmp < ti) ti = tmp;
					s2.push_back(make_pair(tmp + 1, -2));
				}
				else{
					int tmp = abs(people[j].first - stair[0].first);
					tmp += abs(people[j].second - stair[0].second);
					if (tmp < ti) ti = tmp;
					s1.push_back(make_pair(tmp + 1, -2));
				}
			}

			sort(s1.begin(), s1.end());
			sort(s2.begin(), s2.end());

			int cnt = 0;
			while (cnt < pnum){
				if (ti >= answer) break;

				int len1 = s1.size();
				int len2 = s2.size();

				if (s1_num){
					for (int j = 0; j < len1; j++){
						if (s1[j].second > 0){
							s1[j].second--;
							if (s1[j].second == 0){
								s1_num--;
								s1[j].second = -1;
								cnt++;
							}
						}
					}
				}
				if (s2_num){
					for (int j = 0; j < len2; j++){
						if (s2[j].second > 0){
							s2[j].second--;
							if (s2[j].second == 0){
								s2_num--;
								s2[j].second = -1;
								cnt++;
							}
						}
					}
				}

				for (int j = 0; j < len1; j++){
					if (s1[j].second == -2 && s1[j].first <= ti && s1_num < 3){
						s1_num++;
						s1[j].second = lmap[stair[0].first][stair[0].second];
					}
				}

				for (int j = 0; j < len2; j++){
					if (s2[j].second == -2 && s2[j].first <= ti && s2_num < 3){
						s2_num++;
						s2[j].second = lmap[stair[1].first][stair[1].second];
					}
				}

				ti++;
			}

			if (ti < answer){
				answer = ti;
			}
		}

		printf("#%d %d\n", x, answer - 1);
	}
}