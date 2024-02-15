#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> v;
vector<vector<bool>> isVisited;


void func(int i, int j) {
    isVisited[i][j] = true;
    if (j < m - 1 && v[i][j + 1] == '-') {
        func(i, j + 1); // 가로 방향으로 더 이상 '-'이 나오지 않을 때까지 이동
    }
    if (i < n - 1 && v[i + 1][j] == '|') {
        func(i + 1, j); // 세로 방향으로 더 이상 '|'이 나오지 않을 때까지 이동
    }
}

void namu() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isVisited[i][j] == false) {
                func(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main() {
    cin >> n >> m; //n은 세로 m은 가로
    v.assign(n, vector<char>(m));
    isVisited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            v[i][j] = tmp[j]; // 문자 그대로 저장
        }
    }

    namu();

    return 0;
}
