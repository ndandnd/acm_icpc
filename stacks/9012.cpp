#include <iostream>
#include <stack>
using namespace std;

int main(){
    int iter;
    cin >> iter;
    
    
    
    string parentheses;
    for(int i=0; i<iter; i++){
        bool isWellDefined = true;
        stack<int> st;
        cin >> parentheses;
        int len = parentheses.length();
        if(len%2 == 0){
            for(int j=0; j<len; j++){
                if (parentheses[j] == '('){
                    st.push(1);
                }
                else{// ')'
                    if(st.empty()){ //stack cannot be empty when ')' is typed
                        isWellDefined = false;
                        break;
                    }
                    st.pop();
                }
            }
        }
        else{
            isWellDefined = false;
        }
        if(!st.empty()){ // At the end of the loop, stack should be empty
            isWellDefined = false;
        }

        if(isWellDefined){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }



return 0;
}