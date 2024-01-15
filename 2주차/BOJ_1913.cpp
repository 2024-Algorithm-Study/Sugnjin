#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


int main(void) {

	int N, target;
	cin >> N >> target;

	vector<vector <int>> v(N, vector <int>(N));

	int num = N * N;
	int cnt = 0;
	while (num >= 1) {

		v[cnt][cnt] = num;

		for (int row = cnt; row < N - cnt; row++)
			v[row][cnt] = num--;

		for (int col = cnt + 1; col < N - cnt; col++)
			v[N - cnt - 1][col] = num--;

		for (int row = N - cnt - 2; row >= cnt; row--)
			v[row][N - cnt - 1] = num--;

		for (int col = N - cnt - 2; col > cnt; col--)
			v[cnt][col] = num--;

		cnt++;

	}

	int indx1 = 0, indx2 = 0;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (v[row][col] == target)
				indx1 = row, indx2 = col;
			cout << v[row][col] << ' ';
		}
		cout << '\n';
	}

	cout << indx1 + 1 << ' ' << indx2 + 1;




	return 0;
}