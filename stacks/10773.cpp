#include <iostream>
#include <stack>
using namespace std;
int main(){
    int input, iter;
    stack<int> st;

    cin >> iter;

    for(int i=0; i<iter; i++){
        cin >> input;
        if(input == 0){
            st.pop();
        }
        else{
            st.push(input);
        }
    }
    
    int until = st.size(), sum=0;
    for(int i=0; i<until; i++){
        sum += st.top();
        st.pop();
    }
    cout << sum << endl;
    return 0;
}