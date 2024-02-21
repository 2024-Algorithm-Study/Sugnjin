#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {


    int arr[10]={0};

    string num;
    cin >> num;
    for (int i = 0; i < num.size(); i++) {
        int tmp = num[i] - '0';
        arr[tmp] += 1;
    }

    for (int i = 9; i >= 0; i--) {
        int temp= arr[i];
        for (int j = temp; j > 0; j--) {
            cout << i;
        }
    }

    return 0;
}
