#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// bool first_largest(deque<int> v){
//     bool largest = true;
//     for(int i=1; i<v.size(); i++){
//         if (v[0]<v[i]){
//             largest = false;
//             break;
//         }
//     }
//     return largest;
// }

int arg_largest(deque<int> q){
    int place = 0;
    for(int i=1; i<q.size(); i++){
        if(q[place]<q[i]){
            place = i;
        }
    }
    return place;
}

void send_k_back(deque<int> &q, int k){ //must call by reference
    //sends k integers to the back
    for(int i=0; i<k; i++){
        int temp = q.front();
        q.pop_front();
        q.emplace_back(temp);
    }
}

int main(){
    //speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //speed

    
    int num_tests;
    cin>>num_tests;
    
    for(int i=0; i<num_tests; i++){//for that many test cases
        int num_docs, position, num_prints(0); //num_prints is what we want to cout
        cin >> num_docs >> position;
        
        //cin next line: values of importance
        deque<int> importance(num_docs);
        deque<int> arg_importance(num_docs);
        //queue<int> q;
        for(int j=0; j<num_docs; j++){
            cin >> importance[j];
            arg_importance[j] = j;
            //q.push(importance[j]);
        }

        //We have queue q, and deque importance, and its deque arguments
        
        int out(-1);
        //we want to continue until we get position out
        while(out!=position){
            //find arg_largest
            int k = arg_largest(importance);
            //send it to the front and pop it out.
            send_k_back(importance, k);
            send_k_back(arg_importance, k);
            importance.pop_front();
            out = arg_importance.front();
            arg_importance.pop_front();
            num_prints++;
        }
        cout << num_prints <<'\n';
        
    }
    

    return 0;
}