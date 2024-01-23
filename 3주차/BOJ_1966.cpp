#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
using namespace std;
#include <queue>

int main(void) {
	int T;
	cin >> T;

	int N, M;

	vector <int> result(T);


	for (int i = 0; i < T; i++) {		// 테스트 케이스 개수만큼 반복
		cin >> N >> M;

		priority_queue <int> pq;			//우선순위 큐 선언
		queue <pair <int, int>> q;						// 큐 선언
		for (int j = 0; j < N; j++) {		
			int tmp;
			cin >> tmp;

			pq.push(tmp);				//중요도를 우선순위 큐에 push
			q.push({ tmp, j });			//중요도와 인덱스를 큐에 push
		}

		int cnt = 0;			//cnt는 출력될 때마다 +1
		while (!q.empty()) {
			int priority = q.front().first;
			int indx = q.front().second;
			q.pop();

			if (pq.top() == priority) {		//우선순위 큐 맨 위의 값과 큐의 첫번째 노드의 첫 원소가 같을 때
				pq.pop();
				cnt++;
				if (indx == M) 	break;
			
			}		
			else {		//맨 뒤로 보내기
				q.push({ priority, indx });
			}
					
		}

		result[i] = cnt;			//result에 몇 번째로 출력되었는지 저장.

	}

	for (int i = 0; i < T; i++)
		cout << result[i] << "\n";


	return 0;
}