#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;

void cannto(int N) {
	int len = pow(3, N);
	if (len ==1) {
		cout << "-";
		return;
	}
	else {
		cannto(N - 1);

		for (int i = 0; i < len / 3; i++)
			cout << " ";

		cannto(N - 1);
	}

}

int main(void) {
	int N;
	
	while (cin >> N) {

		cannto( N);
		cout << "\n";
	}

		return 0;
}