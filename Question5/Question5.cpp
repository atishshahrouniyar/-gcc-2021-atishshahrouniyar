using namespace std;
#include <string>
#include <iostream>

string solution(string n) {
    int previous = -1, max0 = 0;
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == '0')
            max0 = max(max0, i - previous);
        else
            previous = i;
    }
    if (max0 & 1)
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
