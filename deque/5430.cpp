#include<iostream>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
int main(){
    //speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //speed

    int num_test;
    cin>>num_test;
    for(int i=0;i<num_test;i++){
        bool err = false;
        string command;
        int len;
        string arr;
        cin >> command;
        cin >> len;
        cin >> arr;
        deque<int> dq;

        //int temp1;
        //temp1 = stoi(arr);
        string temp;
        for (int i = 1; i < arr.length(); i++){
            if ('0' <= arr[i] && arr[i] <= '9')
                    temp += arr[i]; //because we can get two digit numbers
            
            else if (arr[i] == ',' || arr[i] == ']') //we have reached the end of a number
            {
                if(!temp.empty())
                {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }

        
        //count d's in the code
        int d_count(0);
        for(int i=0;i<command.length();i++){
            if(command[i] == 'D'){
                d_count++;
            }
        }

        //check if array command has too many D's
        if(d_count>len){
            err = true;
        }
        //execute the command
        
        if(!err){
            bool flipped = false;
            for(int i=0;i<command.length();i++){
                if(command[i] == 'R'){
                    flipped = !flipped;
                }
                else{// 'D'
                    if(flipped){
                        dq.pop_back();
                    }
                    else{
                        dq.pop_front();
                    }
                }
            }

            //Print what's remaining
            string ans = "[";
            int final_size = dq.size();
            if(flipped){
                for(int i=0; i<final_size; i++){
                    ans += to_string(dq.back()) + ',';
                    dq.pop_back();
                }
            }
            else{
                for(int i=0; i<final_size; i++){
                    ans += to_string(dq.front()) + ',';
                    dq.pop_front();
                }
            }

        ans.back() = ']'; //the last value of the string ans was a comma, turned into a ].

        if (final_size == 0|| len==0){//Dirty way to fix
            ans = "[]";
        }

        cout << ans << '\n';
        }
        else{
        cout << "error" << '\n';
        }
    }//end of each test case
    return 0;
}