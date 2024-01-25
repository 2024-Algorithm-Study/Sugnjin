#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;

void print_Comb(vector <int> &v) {		//조합 출력 함수

	int k = v.size();					//매개변수 v의 인덱스 사이즈 (즉, 집합의 원소 개수)

	vector <int> temp_v(k);				// 조합을 판별해줄 임시 벡터 선언.

	for (int i = 0; i < 6; i++)			// 로또는 6개를 추첨하므로 6개를 0으로 초기화
		temp_v[i] = 0;				

	for (int i = 6; i < k; i++)			// 전체 원소 k 개 중 6개를 제외한 k-6개를 1로 초기화
		temp_v[i] = 1;

	sort(temp_v.begin(), temp_v.end());			// 오름차순 정렬 되어있는 경우에만 next_permutation() 이용가능.

	do {
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (temp_v[i] == 0) {
				cout << v[i] << " ";
				cnt++;
			}
			if (cnt == 6) {
				cout << "\n";
				break;
			}
		}
	} while (next_permutation(v.begin(), v.end() ));		//next_permutation() 자체는 순열 메소드


}

int main(void) {
	int test;
	cin >> test;

	while (test != 0) {				//입력 0이면 종료
		int k;
		cin >> k;
		vector <int> set_S(k);	//원소를 k개 가지는 집합 S
		for (int i = 0; i < k; i++)
			cin >> set_S[i];

		print_Comb(set_S);
	
	}


		return 0;
}