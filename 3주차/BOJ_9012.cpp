#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;
#include <stack>

int main(void) {
	int T;
	cin >> T; 

	vector <string> result(T);
	for(int i=0; i<T; i++){
		string word;
		cin >> word;

		stack <char> stack;
		for (int j = 0; j <word.size(); j++) {
			if (!stack.empty()) {
				if (stack.top() == '(' && word[j] == ')')		// () 쌍을 이룰 수 있으면 스택에서 꺼낸다.
					stack.pop();
				else stack.push(word[j]);
			}

			else stack.push(word[j]);
		}

		if (stack.empty() == true)	result[i] = "YES";
		else result[i] = "NO";

	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << "\n";

	}

	return 0;
}