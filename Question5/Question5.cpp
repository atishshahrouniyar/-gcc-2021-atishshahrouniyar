using namespace std;
#include <string>
#include <iostream>

string solution(string n) {
    int previous = -1, prev = 0, cur = 0;
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == '0') {
            if (i - previous == cur)
                prev = cur;
            cur = max(cur, i - previous);
        }
        else
            previous = i;
    }
    if (prev != cur && cur & 1)
        return "A";
    else
        return "B";
}

/*  Do not edit below code */
int main() {
    string  n;
    cin >> n;
    string answer = solution(n);
    cout << answer << endl;
}
