#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        
        dq.emplace_back(num);
    }
    dq=dq-1;
    return 0;
}