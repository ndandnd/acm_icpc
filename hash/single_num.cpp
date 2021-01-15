#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int n : nums){
            if(hashset.count(n) == 0){
                hashset.insert(n);}
            else{
                hashset.erase(n);
            }
        }
        
        
        for(int n : nums){
        if(hashset.count(n)>0){
            return n;
        }   
        }
        
    }
};

int main(){
    int nums [5] = {4,1,2,1,2};
    unordered_set<int> hashset;
    for(int n : nums){
        if(hashset.count(n) == 0){
            hashset.insert(n);}
        else{
            hashset.erase(n);
        }
    }
    
    
    for(int n : nums){
    if(hashset.count(n)>0){
        cout<<n<<endl;
    }   
}
}