#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int len = nums.size();
//         bool done = false;
//         vector<int> ans(2); //array of size 2
//         for(int i=0; i<len-1; i++){
//             for(int j=i+1; j<len; j++){
//                 if (nums[i] + nums[j] == target){
//                     ans[0]=i;
//                     ans[1]=j;
//                     done = true; //raise flag to get out of all loops
//                     break;
//                     //break only breaks the innermost for loop
//                 }
//             }
//             if(done){//we have the answer, no need to conitnue
//                 break;
//             }

//         }
//         return ans;
//     }
// };

//Solution using hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2); //array of size 2
        unordered_map<int,int> hashmap; //Map each element to its index.
        bool found = false;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]] = i;
        }

        

        //My try
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i]; //If diff exists in the domain, and

            if(hashmap[diff] &&
                hashmap[diff]!= i) //Makes sure that nums=[3, 3], target=6, we get [0,1], not [0,0]
                {
                ans[0] = i;
                ans[1] = hashmap[diff];
                break;
            }
        }
        return ans;
    }
};
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2); //array of size 2
        unordered_map<int,int> hashmap; //Map each element to its index.
        bool found = false;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]] = i;
        }

        

        //My try
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i]; //If diff exists in the domain, and

            if(hashmap[diff] &&
                hashmap[diff]!= i) //Makes sure that nums=[3, 3], target=6, we get [0,1], not [0,0]
                {
                ans[0] = i;
                ans[1] = hashmap[diff];
                break;
            }
        }
        return ans;
    }
int main(){
    vector<int> v1{2,9,7,1};
    int target(9);
    vector<int> v2 = twoSum(v1, target);
    for(int x : v2){
        cout<< x<< " ";
    }
}