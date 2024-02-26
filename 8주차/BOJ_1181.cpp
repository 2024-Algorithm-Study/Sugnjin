#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void sort(vector<string> &word) {
    //길이 짧은 순, 길이 같을 때는 사전 순 정렬.


}

int main() {
    int N;
    cin >> N;
    vector<string> word;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        word.push_back(tmp);
    }

    sort(word);


    return 0;
}
