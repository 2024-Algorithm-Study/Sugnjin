#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std; 

int main(void) {
	int N, M, R;
	cin >> N >> M >> R;

	//N x M 짜리 배열 vector 이용해서 동적할당
	vector<vector<int>> arr(N, vector<int>(M));
	vector<vector<int>> tmp_arr(N, vector<int>(M));


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	//R번 회전
	for (int k = 0; k < R; k++) {

		//N, M 중 작은 값의 절반만큼 회전
		int spin = min(N, M) / 2;
		int x1 = 0, y1 = 0; // 최초 좌상단 꼭짓점 좌표
		int x2 = N - 1, y2 = M - 1; // 최초 우하단 꼭짓점 좌표

		for (int i = 0; i < spin; i++) {

			//왼쪽
			for (int j = x1; j < x2; j++)
				tmp_arr[j + 1][y1] = arr[j][y1];


			//아래
			for (int j = y1; j < y2; j++)
				tmp_arr[x2][j + 1] = arr[x2][j];

			//오른쪽
			for (int j = x2; j > x1; j--)
				tmp_arr[j - 1][y2] = arr[j][y2];

			//위
			for (int j = y2; j > y1; j--)
				tmp_arr[x1][j - 1] = arr[x1][j];

			x1++, y1++;
			x2--, y2--;
		}

		copy(tmp_arr.begin(), tmp_arr.end(), arr.begin());
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}

	
	return 0;
}