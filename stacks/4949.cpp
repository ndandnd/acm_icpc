#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isBracket(char c){
    if (c =='(' || c ==')' ||c =='[' ||c ==']'){
        return true;
    }
    else{
        return false;
    }
}

bool isRoClosed(char c){
    if (c == ')')
        {return true;}
    else
    {
        return false;
    }
}
bool isRoOpen(char c){
    if (c == '(')
        {return true;}
    else
    {
        return false;
    }
}
bool isSqOpen(char c){
    if (c == '[')
        {return true;}
    else
    {
        return false;
    }
}


bool isSqClosed(char c){
    if (c == ']')
        {return true;}
    else
    {
        return false;
    }
}





int main()
{
    
    while(1){
        stack<int> bracket_stack; //round brackets, ()
        
        bool balanced = true;
        string problem;

        getline(cin, problem);
        
        /*while (problem != "\n"){ //complete the sentence
            string next_word;
            cin>>next_word;
            problem += next_word;
        }*/

        if(problem[0] == '.'){//Break if the input is a single dot
            break;
        }

        for(int i = 0; i<problem.length(); i++){
            char c = problem[i];
            if(isBracket(c)){ // We only care about brackets
                if((isSqClosed(c)|| isRoClosed(c)) && bracket_stack.empty() ){
                    balanced = false;
                    break;
                }
                else if(isSqOpen(c)){
                    bracket_stack.push(1);
                }
                else if(isRoOpen(c)){
                    bracket_stack.push(2);
                }
                else if(isRoClosed(c)){
                    if(bracket_stack.top() == 1){
                        balanced = false;
                        break;
                    }
                    bracket_stack.pop();
                }
                else if(isSqClosed(c)){

                    if(bracket_stack.top() == 2){
                        balanced = false;
                        break;
                    }
                    bracket_stack.pop();
                }

            }
        }
        //End of for loop
        if(!(bracket_stack.empty() )){
            balanced = false;
        }
    //print answer
    if(balanced == true){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }


        
    }


return 0;
}