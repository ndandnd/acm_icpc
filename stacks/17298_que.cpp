#include<iostream>
#include<queue>
#include<vector>
/*This algorithm is O(n^2), fails in time complexity.
Think of 1 1 1 1 1, ..., 1, 2*/

using namespace std;
int main(){
    queue<int> soln;
    int len;
    cin >> len;
    vector<int> seq(len);
    for(int k=0; k<len; k++){
        cin >> seq[k];
    }
    
    for(int place=0; place<len; place++)
    {
        bool isLargest = true;
        int current = seq[place];
        for(int j = place+1; j<len; j++){
            int val = seq[j];
            if( val > current ){
                soln.push(val); //add it to the queue
                isLargest = false;
                break;
            }
        }
        if(isLargest){
            soln.push(-1);
        }
    }

for(int i=0; i<len; i++){
    cout<< soln.front() << ' ';
    soln.pop();
}
return 0;
}