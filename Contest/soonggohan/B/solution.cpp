#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string t;
    cin >> n >> t;

    int len = t.size();
    int cntO = 0;
    for (char c : t) {
        if (c == 'O') cntO++;
    }

    if (cntO == len || (cntO == 0 && len == 4)) {
        cout << "hi\n";
    } else {
        cout << "bye\n";
    }
    return 0;
}