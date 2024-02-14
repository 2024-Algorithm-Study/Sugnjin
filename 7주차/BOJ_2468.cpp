#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>    
using namespace std;
int n;

int dx[] = {0,0,-1,+1};
int dy[] = {+1,-1,0,0};

void dfs(int y, int x, vector<vector<int>>  &drown, vector<vector<bool>> &isVisited) {
    if (isVisited[y][x] == true) {
        return;
    }
    else {
        isVisited[y][x] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (drown[ny][nx] == 0) {
                    dfs(ny, nx, drown, isVisited);
                }
            }
        }
    }

}

void safe_zone(vector<vector<int>> &map, int max) {
    int safe_max = 0;
    for (int height = 1; height <= max; height++) {             //높이를 변경해가며 탐색

        vector<vector<int>> drown(n, vector<int>(n, 0));            //잠겼는지 안잠겼는지 판별해주는 벡터
        vector<vector<bool>>isVisited(n, vector<bool>(n, false));   //방문 벡터

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] <= height) {
                    drown[i][j] = 1;       //높이보다 낮은 경우 1로 처리
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (drown[i][j] ==  0 && isVisited[i][j] == false) {     //아직 방문 안했고 잠긴 경우에 dfs 수행
                    dfs(i, j, drown, isVisited);
                    cnt++;
                }
            }
        }

        if (safe_max < cnt) safe_max = cnt;

    }
    cout << safe_max;
}

int main() {

    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] > max) max = map[i][j];
        }
    }

    safe_zone(map, max);

    return 0;
}
