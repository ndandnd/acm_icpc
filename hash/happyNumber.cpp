#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
int sum_square(int n){
    int ans(0);
    while(n!=0){ //2^31 is 10 digits
        
        ans +=(n % 10)*(n % 10);
        
        n = n/10;
        //cout << ans << ' '<< n << endl;
    }
    return ans;
}

bool isHappy(int n) {
    //Decomposition
    unordered_set<int> uset;
    
    
    while(n != 1){

        uset.insert(n); 
        n = sum_square(n);
        if (uset.count(n) > 0){
            return false;
        }
    }
    return true;
    //square sum
    
}



int main(){
int num;
cin >> num;
cout << isHappy(num) << endl;
return 0;
}