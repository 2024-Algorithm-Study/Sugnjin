#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>	
#include <queue>
using namespace std;
vector<vector <int>> graph;
vector < bool>  isVisited;
int cnt = 0;

void DFS(int curr_node) {

	if (isVisited[curr_node] == true) return;
	else{
		isVisited[curr_node] = true;
		cnt++;
		for (int i = 0; i < graph[curr_node].size(); i++) {
				DFS(graph[curr_node][i]);
		}
	}


}

int main(void) {
	int total_num;
	cin >> total_num;
	int pair_num;
	cin >> pair_num;

	 graph.resize(total_num + 1);
	 isVisited.assign(total_num + 1, false);
	for (int i = 1; i <= pair_num; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}
	
	DFS(1);
	cout << cnt;
	return 0;
}