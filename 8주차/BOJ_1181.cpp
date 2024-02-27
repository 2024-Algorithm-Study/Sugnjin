#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(string a, string b) {
    if (a.length() == b.length()) {     //두 단어의 길이가 같을 때, 사전순 정렬
        return a < b;
    }
    else {                              //길이가 다르다면, 길이가 짧은 것이 앞으로 오도록..
        return a.length() < b.length();
    }
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

    sort(word.begin(), word.end(), compare);

    cout << word[0] << "\n";

    for (int i = 1; i < N; i++) {
        if (word[i] != word[i - 1]) {
            cout << word[i] << "\n";
        }
    }


    return 0;
}
