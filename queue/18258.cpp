#include<iostream>
#include<queue>
#include<string>

using namespace std;


void command_pop(queue<int> &qu){ //make sure that we call by reference
    if(qu.empty()){
        cout<<-1<<'\n';
    }
    else{
    cout<<qu.front()<<'\n';
    qu.pop();
    }
}
void command_front(queue<int> &qu){ //make sure that we call by reference
    if(qu.empty()){
        cout<<-1<<'\n';
    }
    else{
    cout<<qu.front()<<'\n';
    }
}
void command_back(queue<int> &qu){ //make sure that we call by reference
    if(qu.empty()){
        cout<<-1<<'\n';
    }
    else{
    cout<<qu.back()<<'\n';
    }
}

int main(){
    //for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> que;
    int num_commands;
    cin>>num_commands;
    for(int i=0; i<num_commands; i++){
        string command;
        cin>>command;
        if(command == "front"){
            command_front(que);
        }
        else if(command == "back"){
            command_back(que);
        }
        else if(command == "size"){
            cout<<que.size()<<'\n';
        }
        else if(command == "empty"){
            cout<<que.empty()<<'\n';
        }
        else if(command == "pop"){
            command_pop(que);
        }
        else{ //push
            int input;
            cin >> input;
            que.push(input);
        }
    }
}