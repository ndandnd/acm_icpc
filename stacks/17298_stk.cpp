#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int main(){
    stack<int> todo;
    stack<int> todo_arg;
    
    int last_success = -1; //the last number that worked

    int len;
    cin >> len;
    vector<int> seq(len);
    for(int k=0; k<len; k++){
        cin >> seq[k];
    }
    

    vector<int> ans(len);
    
    for(int k=0; k<len-1; k++){
        if(seq[k]<seq[k+1]){
            ans[k] = seq[k+1]; //the num on right is bigger. assign it to the answer.
            last_success = seq[k+1];
            if(!todo.empty()){//since there was a success, try it on the stack
                int n = todo.size();
                for(int j = 0; j<n; j++){
                    if(todo.top() < last_success){
                        ans[todo_arg.top()] = last_success;
                        todo_arg.pop();
                        todo.pop();
                    }
                    else{break;} //the stack is a decreasing sequence.
                }
            }
        }
        else{
            todo.push(seq[k]); //Place it in the todo list
            todo_arg.push(k); //store its place of the vector
            
        }
    }

    //empty the todo stack
    last_success = seq[len-1];
    while(!todo.empty()){
        if(todo.top()<last_success){
            ans[todo_arg.top()] = last_success;
            todo.pop();
            todo_arg.pop();
        }
        else{
            last_success = todo.top();
            ans[todo_arg.top()] = -1;
            todo.pop();
            todo_arg.pop();
        }
    }
    for(int i=0; i<len-1; i++){
    cout<< ans[i] << ' ';
    }
    cout << -1; //rightmost is always -1
return 0;
}