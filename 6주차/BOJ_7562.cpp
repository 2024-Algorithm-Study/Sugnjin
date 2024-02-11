#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>    
using namespace std;

int dx[] = {+1, +2, +2, +1, -1, -2, -2, -1};
int dy[] = {+2, +1, -1, -2, -2, -1, +1, +2};

int knight(int l, int x, int y, int target_x, int target_y) {
    vector <vector <int>> chess(l, vector<int>(l, -1));     // l x l 체스판 선언 및 모든 값 -1로 초기화
    

    queue <pair <int, int>> q;
    q.push(make_pair(x, y));        // 초기위치 (x,y) 큐에 삽입
    chess[y][x] = 0;                // 초기위치 값 0으로 초기화

    while (!q.empty()) {

        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if (nx >= 0 && nx < l && ny >= 0 && ny < l) {       // (nx, ny)가 l x l 내부에 존재할 때
                if (chess[ny][nx] == -1) {
                    chess[ny][nx] = chess[curr_y][curr_x] + 1;
                    q.push(make_pair(nx, ny));  
                }

            }
        }
    }

    return chess[target_y][target_x];
}

int main() {
    int T;
    cin >> T;
    vector<int> tmp;

    for (int i = 0; i < T; i++) {
        int l;
        cin >> l;

        int x, y;
        cin >> x >> y;
        int target_x, target_y;
        cin >> target_x >> target_y;

        tmp.push_back(knight(l, x,y, target_x, target_y));
    }

    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i] << "\n";
    }

    return 0;
}
