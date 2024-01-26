#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;

int team_balance(vector <vector <int>> &v) {
	int total_num = v.size();			// total_num :  두 팀 합친 플레이어 수

	vector <int> temp_v(total_num, 1);

	for (int i = 0; i < total_num / 2; i++)		//전체 플레이어의 절반을 0으로 초기화
		temp_v[i] = 0;
	
	sort(temp_v.begin(), temp_v.end());			// 오름차순 정렬을 위해.. 사실 여기서는 생략되어도 무방

	int min = 100 * total_num;

	do {
		int cnt1 = 0;
		int cnt2 = 0;
		vector <int> start_team;
		vector <int> link_team;

		for (int i = 0; i < total_num; i++) {			//스타트팀, 링크팀에 들어갈 선수의 번호 뽑기.
			if (temp_v[i] == 0) {
				start_team.push_back(i + 1);
				cnt1++;
			}
			else if (temp_v[i] == 1) {
				link_team.push_back(i + 1);
				cnt2++;
			}
			if (cnt1 == total_num / 2 && cnt2 == total_num/2) {
				break;

			}
		}

		vector <int> temp_start(total_num/2, 0);	//스타트팀의 점수 총합 구하기.
		for (int i = 0; i < 2; i++)				// 2개만 뽑는다.
			temp_start[i] = 1;
		sort(temp_start.begin(), temp_start.end());
		int sum1 = 0;
		do {
			int cnt = 0;
			int tmp[2] = {};
			for (int i = 0; i < total_num / 2; i++) {
				if (temp_start[i] == 1) {
					tmp[cnt++] = start_team[i];
				}
				if (cnt == 2) break;
			}
			sum1 += v[tmp[0]-1][tmp[1]-1];
			sum1 += v[tmp[1]-1][tmp[0]-1];

		} while (next_permutation(temp_start.begin(), temp_start.end()));
		

		vector <int> temp_link(total_num/2, 0);
		for (int i = 0; i < 2; i++)				// 2개만 뽑는다.
			temp_link[i] = 1;
		sort(temp_link.begin(), temp_link.end());
		int sum2 = 0;
		do {
			int cnt = 0;
			int tmp[2] = {};
			for (int i = 0; i < total_num / 2; i++) {
				if (temp_link[i] == 1) {
					tmp[cnt++] = link_team[i];
				}
				if (cnt == 2) break;
			}
			sum2 += v[tmp[0]-1][tmp[1]-1];
			sum2 += v[tmp[1]-1][tmp[0]-1];

		} while (next_permutation(temp_link.begin(), temp_link.end()));

		int diff = abs(sum1 - sum2);
		if (diff < min) min = diff;

	} while (next_permutation(temp_v.begin(), temp_v.end()));


	return min;
}

int main(void) {
	int N;
	cin >> N;
	vector <vector <int> > v(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	cout << team_balance(v);

		return 0;
}