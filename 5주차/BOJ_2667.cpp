#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
#include <queue>
using namespace std;

int N;
vector<vector<int>> graph;
vector<vector<bool>> isVisited;
vector <int> tmp;

void BFS(int start_x, int start_y) {
	queue < pair <int, int>> q;
	q.push(make_pair(start_x, start_y));
	isVisited[start_x][start_y] = true;

	int dx[] = {-1, +1, 0, 0 };		//상 하 좌 우
	int dy[] = {0, 0, -1, +1};
	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		int cnt = 0;
		cnt++;
		q.pop();

			for (int i = 0; i < 4; i++) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;

				else if (isVisited[next_x][next_y] == false && graph[next_x][next_y] == 1) {
					isVisited[next_x][next_y] = true;
					cnt++;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	tmp.push_back(cnt);

}


int main(void) {

	cin >> N;
	graph.assign(N, vector<int>(N));
	isVisited.assign(N, vector<bool>(N, false));



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
		
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisited[i][j] == false && graph[i][j] == 1) {
				BFS(i , j);
			}
		}
	}

	cout << tmp.size() << "\n";
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << "\n";
	}

	return 0;
}