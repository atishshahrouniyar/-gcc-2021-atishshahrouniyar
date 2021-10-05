#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z, int security_value[], int n)
{
    int no_of_stocks = 0;
    map<int, int> frequency;
    for (int i = 0; i < n; ++i) {
        frequency[security_value[i]] += i + 1;
    }
    for (auto& x : frequency) {
        z -= x.first * x.second;
        no_of_stocks += x.second;
        if (z < 0) {
            no_of_stocks -= (abs(z) - 1) / x.first + 1;
            break;
        }
    }
    return no_of_stocks;
}

int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z,security_value,n);
cout << no_of_stocks_purchased;
 
 
 
}
 
 
