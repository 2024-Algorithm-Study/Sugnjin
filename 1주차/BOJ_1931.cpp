#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;



bool cmp(vector<int>& v1, vector <int>& v2) {
	if (v1[1] == v2[1]) return v1[0] < v2[0]; //두번째 인자를 기준으로 오름차순 정렬
	else return v1[1] < v2[1];

}

int main(void) {

	int num;
	cin >> num;

	//2차원 배열 vector로 동적할당

	vector<vector<int>> v(num, vector<int>(2));


	for (int i = 0; i < num; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	//두 번째 인자(즉, 회의 종료 시간) 기준으로 오름차순 정렬
	sort(v.begin(), v.end(), cmp);

	//회의 종료시간이 회의 시작시간보다 빠를 때 count. 
	int last = 0;
	int cnt = 0;
	for (int i = 0; i < num; i++) {
		if (last <= v[i][0]) {
			last = v[i][1];
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}