#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std; 

void rotate(vector <vector <int> >& arr, vector <vector <int> >& tmp_arr, int n, int d) {
	if (d == 0 || d == 360 || d == -360) return;
	else if (d > 0 && d < 360) {
		for (int i = 0; i < d / 45; i++) {
			for (int j = 0; j < n; j++) {
				// step1 주대각선
				tmp_arr[j][(n + 1) / 2 - 1] = arr[j][j];
				// step2 가운데열
				tmp_arr[j][n - 1 - j] = arr[j][(n + 1) / 2 - 1];
				// step3 부대각선
				tmp_arr[(n + 1) / 2 - 1][n - 1 - j] = arr[j][n - 1 - j];
				// step 4 가운데행
				tmp_arr[j][j] = arr[(n + 1) / 2 - 1][j];
			}
			copy(tmp_arr.begin(), tmp_arr.end(), arr.begin());
		}
	}
	else if (d<0 && d>-360) {

		for (int i = 0; i > d / 45; i--) {
			for (int j = 0; j < n; j++) {
				// step1 주대각선
				tmp_arr[(n + 1) / 2 - 1][j] = arr[j][j];
				// step2 가운데 열
				tmp_arr[j][j] = arr[j][(n + 1) / 2 - 1];
				// step3 부대각선
				tmp_arr[j][(n + 1) / 2 - 1] = arr[j][n - 1 - j];
				// step 4 가운데 행
				tmp_arr[n - 1 - j][j] = arr[(n + 1) / 2 - 1][j];
			}
			copy(tmp_arr.begin(), tmp_arr.end(), arr.begin());
		}
	}
	else return;
	}



int main(void) {
		int T;
		cin >> T;

		for (int i = 0; i < T; i++) {
			int n, d;
			cin >> n >> d;

			// n x n  배열
			vector <vector <int> > arr(n, vector <int>(n));
			vector <vector <int> > tmp_arr(n, vector <int>(n));

			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					cin >> arr[j][k];

			copy(arr.begin(), arr.end(), tmp_arr.begin());
		
			rotate(arr, tmp_arr, n, d);

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					cout << tmp_arr[j][k] << ' ';
				}
				cout << '\n';
			}

		}
	return 0;
}