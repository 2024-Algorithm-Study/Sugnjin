#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>    
using namespace std;
int start, target;


int isVisited[100002];          // 몇 초후에 방문했는지 나태내는 배열.
int pos[100002];                //  현재 위치와 다음 위치 사이의 관계를 나타내는 배열.
vector <int> path;              //경로 출력을 위한 벡터

void BFS(){ 
        
    queue <int> q;
    q.push(start);
    
    isVisited[start] = 0;


    while (!q.empty()) {

        int curr = q.front();
        
        q.pop();

        if (curr == target) {
            int idx = curr;
            while (idx != start) {
                path.push_back(idx);
                idx = pos[idx];
            }
            return;
        }

        //뒤로 한칸 이동
        int tmp1 = curr - 1;
        if (tmp1 >= 0 && tmp1 <= 100000) {
            if (isVisited[tmp1] == 0) {
                isVisited[tmp1] = isVisited[curr] + 1;      // 날자 업데이트
                pos[tmp1] = curr;                           // 위치 업데이트 : pos[다음 좌표] = 현재 좌표;
                q.push(tmp1);
            }
        }
        //앞으로 한칸 이동
        int tmp2 = curr + 1;
        if (tmp2 >= 0 && tmp2 <= 100000) {
            if (isVisited[tmp2] == 0) {
                isVisited[tmp2] = isVisited[curr] + 1;
                pos[tmp2] = curr;
                q.push(tmp2);
            }
        }

        //2*X만큼 순간이동
        int tmp3 = curr * 2;
        if (tmp3 >= 0 && tmp3 <= 100000) {
            if (isVisited[tmp3] == 0) {
                isVisited[tmp3] = isVisited[curr]+1;
                pos[tmp3] = curr;
                q.push(tmp3);
            }
        }

    }
}

int main() {

    cin >> start >> target;

    BFS();

    if (start == target) { 
        cout << 0 << "\n";
        cout << start;
    }
    else {
        cout << isVisited[target] << "\n";
        cout << start << " ";
        for (int i = path.size()-1; i >=0; i--) {
            cout << path[i] << " ";
        }
          }

    return 0;
}
