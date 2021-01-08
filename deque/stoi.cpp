#include<iostream>
#include<deque>
#include<string>
#include <sstream>
using namespace std;
int main(){
    string arr;
    cin >>arr;
    arr.back() = 'p';
    cout << arr;

    return 0;
}