#include <iostream>
#include <stack>
using namespace std;

void command_top(stack<int> theStack){
    if(theStack.empty()){
        cout<< -1<< endl;;
    }
    else{
        cout << theStack.top()<< endl;;
    }
}

void command_empty(stack<int> theStack){
    if(theStack.empty()){
        cout<< 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}
void command_pop(stack<int> &theStack){
    if(theStack.empty()){
        cout<< -1 << endl;
    }
    else{
        cout << theStack.top() << endl;
        theStack.pop();
    }
}


int main()
{
    stack<int> myStack;
    int n;
    string command;
    
    cin >> n;
    while(n>0){
        cin >> command;
        if(command == "top"){
            command_top(myStack);
        }
        else if(command == "empty"){
            command_empty(myStack);
        }
        else if(command == "size"){
            cout << myStack.size()<< endl;
        }
        else if(command == "pop"){
            command_pop(myStack);
        }
        else{ //command == push
            int num;
            cin >> num;
            myStack.push(num);
        }
        n--;
        }
    return 0;
}
