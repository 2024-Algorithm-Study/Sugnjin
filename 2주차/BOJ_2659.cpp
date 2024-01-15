#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main(void) {
	int arr[4];
	for (int i = 0; i < 4; i++)
		cin >> arr[i];

	//시계수 구하기

	int tmp1 = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	int tmp2 = arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[0];
	int tmp3 = arr[2] * 1000 + arr[3] * 100 + arr[0] * 10 + arr[1];
	int tmp4 = arr[3] * 1000 + arr[0] * 100 + arr[1] * 10 + arr[2];

	int time_num = min({ tmp1, tmp2, tmp3, tmp4 });

	//몇 번째로 작은 시계수인지..


	int visited[10000] = { 0 };

	int a, b, c, d;

	for (int i = 1111; i <= 9999; i++) {
		a = i / 1000;
		b = (i % 1000) / 100;
		c = (i % 100) / 10;
		d = (i % 10) / 1;

		int temp1 = a * 1000 + b * 100 + c * 10 + d;
		int temp2 = b * 1000 + c * 100 + d * 10 + a;
		int temp3 = c * 1000 + d * 100 + a * 10 + b;
		int temp4 = d * 1000 + a * 100 + b * 10 + c;

		int real = min({ temp1, temp2, temp3, temp4 });
		visited[real] = 1;
	}

	int cnt = 0;

	for (int i = 1111; i <= 9999; i++) {
		if (visited[i] == 1) cnt++;
		if (i == time_num) {
			break;
		}
	}



	cout << cnt;


	return 0;
}