#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int len;
    cin >> len;
    bool possible = true;
    stack<int> seq;
    queue<char> plusminus;
    //char array [len*2];
    int last_input = 1;
    for(int i = 0; i<len; i++){
        
        int input;
        cin >> input;
        if(possible){ //do not perform any of this if impossible

            while(last_input <= input){ //push numbers in, starting from 1
                seq.push(last_input);
                plusminus.push('+');
                last_input++;
            } 

            if(seq.top() > input){ //impossible case
                possible = false; // do not break, since we need to get all inputs
            }

            //else if(seq.top() == input){
            else{
                seq.pop();
                plusminus.push('-');
            }
        }
        

    }

    if(!possible){
        cout << "NO\n";
    }
    else{
        int size = plusminus.size();
        for(int i = 0; i<size; i++){
            cout << plusminus.front() << '\n';
            plusminus.pop();
        }
    }
return 0;  
}
