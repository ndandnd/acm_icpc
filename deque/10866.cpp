#include<iostream>
#include<deque>
#include<string>
using namespace std;

void command_pop_front(deque<int> &dq){
    if(dq.empty()){
        cout << "-1" << '\n';
    }
    else{
        cout << dq.front()<<'\n';
        dq.pop_front();
    }

}
void command_pop_back(deque<int> &dq){
    if(dq.empty()){
        cout << "-1" << '\n';
    }
    else{
        cout << dq.back()<<'\n';
        dq.pop_back();
    }

}

void command_empty(deque<int> dq){
    if(dq.empty()){
        cout << '1' << '\n';
    }
    else{
        cout << '0' << '\n';
    }
}

void command_front(deque<int> dq){
    if(dq.empty()){
        cout << "-1" << '\n';
    }
    else{
        cout << dq.front() << '\n';
    }
}
void command_back(deque<int> dq){
    if(dq.empty()){
        cout << "-1" << '\n';
    }
    else{
        cout << dq.back() << '\n';
    }
}

int main(){
    //for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_commands;
    cin >> num_commands;
    deque<int> dq;
    for(int i=0; i<num_commands; i++){
        string command;
        cin >> command;
        if(command=="push_back"){
            int input;
            cin >> input;
            dq.push_back(input);
        }
        else if(command=="push_front"){
            int input;
            cin >> input;
            dq.push_front(input);
        }
        else if(command=="pop_back"){
            command_pop_back(dq);
        }
        else if(command=="pop_front"){
            command_pop_front(dq);
        }
        else if(command=="size"){
            cout << dq.size() <<'\n';
        }
        else if(command=="empty"){
            command_empty(dq);
        }
        else if(command=="front"){
            command_front(dq);
        }
        else if(command=="back"){
            command_back(dq);
        }
    }
    
    return 0;
}