#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool first_largest(vector<int> v){
    bool largest = true;
    for(int i=1; i<v.size(); i++){
        if (v[0]<v[i]){
            largest = false;
            break;
        }
    }
    return largest;
}

int arg_largest(vector<int> v){
    int place = 0;
    for(int i=1; i<v.size(); i++){
        if(v[place]<v[i]){
            place = i;
        }
    }
    return place;
}

int arg_max(queue<int> q){
    int place = 0;
    for()
    return place;
}

void send_k_back(queue<int> &q, int k){ //must call by reference
    //sends k integers to the back
    for(int i=0; i<k; i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main(){
    //speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //speed


    int tests;
    cin>>tests;
    
    for(int i=0; i<tests; i++){//for that many test cases
        int num_docs, position, num_prints(0);
        cin >> num_docs >> position;
        
        //cin next line: values of importance
        vector<int> importance(num_docs);
        queue<int> q;
        for(int j=0; j<num_docs; j++){
            cin >> importance[j];
            q.push(importance[j]);
        }

        //We have queue q, and vector importance
        
        //find arg_largest
        int k = arg_largest(importance);
        //send it to the front and pop it out.
        
    }
    

    return 0;
}