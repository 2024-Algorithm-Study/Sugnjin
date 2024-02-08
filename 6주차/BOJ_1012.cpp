#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int M, N, K;       //가로 M 세로 N 배추 위치 개수 K
int dx[] = {0,0,-1,+1};
int dy[] = { +1,-1,0,0 };

void DFS(vector<vector<int>> &map, vector<vector<bool>> &isVisited, int y, int x) {
    if (isVisited[y][x] == true) return;
    else {
        isVisited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            else if (isVisited[ny][nx] == false && map[ny][nx] == 1) {
                DFS(map, isVisited, ny, nx);
            }
        }
    }

}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {

        cin >> M >> N >> K;
        vector<vector<int>> map(N, vector<int>(M, 0));        //N x M 행렬 0으로 초기화
        vector<vector<bool>> isVisited(N, vector<bool>(M, false));      //N x M 행렬에 대응하는 방문벡터 false로 초기화
        int cnt = 0;        //cnt 0으로 초기화
        for (int j = 0; j < K; j++) {
            int X, Y;
            cin >> X >> Y;
            map[Y][X] = 1;
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (map[j][k] == 1 && isVisited[j][k] == false) {
                    DFS(map, isVisited, j, k);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";

    }

    return 0;
}
