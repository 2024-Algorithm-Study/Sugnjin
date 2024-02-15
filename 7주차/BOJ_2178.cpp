#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
vector<vector<int>> v;

int dx[] = {0,0,-1,+1};
int dy[] = {-1,+1,0,0};
void miro(vector<vector<int>>& v) {
    queue <pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        if (y == N - 1 && x == M - 1) break;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (v[ny][nx] == 1) {
                    v[ny][nx] = v[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    cout << v[N - 1][M - 1];
}

int main() {
    int N, M;
    cin >> N >> M;

    v.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            v[i][j] = tmp[j] = '0';
        }
    }

    miro(v);

    return 0;
}
