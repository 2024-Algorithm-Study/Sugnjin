#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> isVisited;
int answer = -1;

void chonsu_DFS(int curr, int cnt, int y) {
    isVisited[curr] = true;
    if (curr == y) {
        answer = cnt;
        return;
    }
    for (int i = 0; i < graph[curr].size(); i++) {
        if (!isVisited[graph[curr][i]]) {
            chonsu_DFS(graph[curr][i], cnt + 1, y);
        }
    }
}

int main() {
    int n, x, y;
    cin >> n;
    cin >> x >> y;

    int m;
    cin >> m;

    graph.resize(n + 1);
    isVisited.resize(n + 1, false);

    int parent, child;
    for (int i = 0; i < m; i++) {
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    chonsu_DFS(x, 0, y);

    cout << answer;

    return 0;
}
