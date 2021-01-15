#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2){
        unordered_map<string, int> umap;
        vector<string> restaurants;
        int min = list1.size()+list2.size();
        //Map list1 by index
        for(int i=0; i<list1.size(); i++){
            umap[list1[i]] = i;
        }
        
        for(int i=0; i<list2.size(); i++){
            if(umap.count(list2[i]) != 0){//if the string is also in list1
                if( min > umap[list2[i]] + i){
                    min = umap[list2[i]] + i;
                    restaurants.clear();
                    restaurants.push_back(list2[i]);
                }
                else if(min == umap[list2[i]] + i){
                    restaurants.push_back(list2[i]);
                }
            }
        }
        return restaurants;
    } 
};
