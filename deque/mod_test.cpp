#include<iostream>
#include<deque>
#include<queue>
using namespace std;
void new_arg(int &arg, int cell_size){ // call by ref.
    if(arg>cell_size){
        arg -= cell_size;
    }
    else if(arg<1){
        arg += cell_size;
    }
} 
int main(){
    cout << -1 % 10 << '\n';
    cout << 10 % 10 << '\n';
    int arg1(2);
    arg1 += -2;
    new_arg(arg1, 10);
    cout << arg1 << '\n';

    int arg2(9);
    arg2 += 2;
    new_arg(arg2, 10);
    cout << arg2 << '\n';
    return 0;
}