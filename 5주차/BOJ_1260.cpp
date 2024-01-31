#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
#include <queue>
using namespace std;

int vertex, edge, start_vertex;			// 정점, 간선, 시작 정점
vector<vector<int>> adjacent_list;		//인접리스트			를 전역적으로 선언.
vector <bool> visited;				//방문여부 확인 vector

void DFS(int current_vertex) {		//DFS는 재귀적으로
	if (visited[current_vertex] == true) return;
	else {
		visited[current_vertex] = true;
		cout << current_vertex << " ";

		for (int i = 0; i < adjacent_list[current_vertex].size(); i++) {
			DFS(adjacent_list[current_vertex][i]);
	}
		}

		
}

void BFS(int current_vertex) {			//BFS는 큐를 활용하여 

	queue <int> q;
	q.push(current_vertex);
	visited[current_vertex] = true;

	while (q.empty() == false) {		//큐에 아무것도 없을 때까지 반복.
		int curr = q.front();
		cout << curr <<" ";

		q.pop();

		for (int i = 0; i < adjacent_list[curr].size(); i++) {
			int next = adjacent_list[curr][i];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}

	}
	
}

int main(void) {

	cin >> vertex >> edge >> start_vertex;
	adjacent_list.resize(vertex + 1);				//인접리스트와 방문 vector 크기 resize()를 통해 재조정.
	visited.resize(vertex+1, false);
	for (int i = 0; i < edge; i++) {		//간선을 연결하는 정점 정보를 edge개만큼 입력 받기.
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		adjacent_list[tmp1].push_back(tmp2);
		adjacent_list[tmp2].push_back(tmp1);

	}

	for (int i = 0; i <= vertex; i++) {
		sort(adjacent_list[i].begin(), adjacent_list[i].end());		//작은 번호부터 방문하기 위해서
	}

	DFS(start_vertex);
	cout << "\n";

	visited.assign(vertex + 1, false);//다시 방문 vector 초기화 시켜줌	
	BFS(start_vertex);

	return 0;
}