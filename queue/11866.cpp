#include<iostream>
#include<queue>
using namespace std;


void send_k_back(queue<int> &q, int k){ //must call by reference
    //sends k integers to the back
    for(int i=0; i<k; i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

queue<int> n_queue(int n){
    //creates a queue {front: 1, ..., back:n} 
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    return q;
}

// void print_queue(queue<int> &q){
//     int n = q.size();
//     cout<< '<';
//     for(int i=0; i<n-1; i++){
//         cout<<q.front() << ", ";
//         q.pop();
//     }
//     cout<<q.front()<<'>';
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    //queue<int> ans;
    queue<int> que;
    que = n_queue(n);
    
    cout<<'<';
    while(que.size()>1){
        send_k_back(que, k-1);
        cout<<que.front()<<", ";
        que.pop();
    }
    cout<<que.front()<<'>';

}