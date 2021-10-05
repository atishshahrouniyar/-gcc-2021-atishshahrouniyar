
using namespace std;
#include <string>
#include <iostream>

int solution(int n){
    n <<=1;
    ++n;
    return n/3;
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}
