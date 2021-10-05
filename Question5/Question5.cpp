using namespace std;
#include <string>
#include <iostream>

string solution(string n) {
    int previous = -1, prev = 0, cur = 0, i;
    for (i = 0; i < n.length()-1; ++i) {
        if (n[i] == '0' && n[i+1] == '1') {
            if (i - previous > cur) {
                prev = cur;
                cur = i - previous;
            }
            else if (i - previous < cur)
                prev = max(prev, i - previous);
            else
                prev = cur;
        }
        else if(n[i]=='1')
            previous = i;
    }
    if (n[i] == '0') {
        if (i - previous > cur) {
            prev = cur;
            cur = i - previous;
        }
        else if (i - previous < cur)
            prev = max(prev, i - previous);
        else
            prev = cur;
    }
    if (prev != cur && cur & 1 && prev <= cur / 2)
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
