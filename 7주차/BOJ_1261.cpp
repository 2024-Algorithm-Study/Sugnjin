#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, M;
int map[101][101];
int isVisited[101][101];

int dx[] = {0,0,-1,+1};
int dy[] = {-1,+1,0,0};

int algo_spot() {      // 0-1 BFS
    deque <pair<int, int>> dq;      //덱 선언
    dq.push_front(make_pair(0, 0));     // 시작위치 (0,0) 삽입
    isVisited[0][0] = 1;

    while (!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();             //덱의 맨 앞에서 꺼냄..

        if (y == N - 1 && x == M - 1) return  isVisited[N - 1][M - 1]-1;       //목적지에 도달하면 while문 종료;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {   //내부에 있는지 확인

                if (map[ny][nx] == 0 && isVisited[ny][nx] == 0) {   //해당 위치의 값이 0이고 방문한적 없으면
                    isVisited[ny][nx] = isVisited[y][x];
                    dq.push_front(make_pair(ny, nx));       //덱의 앞쪽에 삽입
                }

                if (map[ny][nx] == 1 && isVisited[ny][nx] == 0) {  //해당 위치의 값이 1이고 방문한적 없으면
                    isVisited[ny][nx] = isVisited[y][x] + 1;    //isVisited 값 + 1
                    dq.push_back(make_pair(ny, nx));        //덱의 뒤쪽에 삽입

                }

            }
        }


    }

}

int main() {
    cin >> M >> N;


    for (int i = 0; i < N; i++) {       //0은 빈방 1이 벽.
    string tmp;
    cin >> tmp;
    for (int j = 0; j < M; j++) {
        map[i][j] = tmp[j] - '0';
        }
    }

   cout << algo_spot();

    return 0;
}
