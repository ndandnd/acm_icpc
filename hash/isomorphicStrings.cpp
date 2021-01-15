#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> phi;
        bool iso = true;
        for(int i=0; i<s.length(); i++){
            if(!phi[s[i]]){ //if there is no mapping for that letter
                phi[s[i]] = t[i]; //map it to the corresponding ith letter of string t
            }
            else{ //if there was a mapping for this letter
                if(phi[s[i]]!=t[i]){ //it should be the same.
                    iso = false;
                    return iso;
                }

            }
        }
        swap(s,t); //change domain, codomain.
        unordered_map<int, int> psi;
        for(int i=0; i<s.length(); i++){
            if(!psi[s[i]]){ //if there is no mapping for that letter
                psi[s[i]] = t[i]; //map it to the corresponding ith letter of string t
            }
            else{ //if there was a mapping for this letter
                if(psi[s[i]]!=t[i]){ //it should be the same.
                    iso = false;
                    return iso;
                }
                
            }
        }
        return iso;
    }
};

//
//
//


bool isIsomorphic(string s, string t) {
        unordered_map<int, int> phi;
        bool iso = true;
        for(int i=0; i<s.length(); i++){
            if(!phi[s[i]]){ //if there is no mapping for that letter
                phi[s[i]] = t[i]; //map it to the corresponding ith letter of string t
            }
            else{ //if there was a mapping for this letter
                if(phi[s[i]]!=t[i]){ //it should be the same.
                    iso = false;
                    return iso;
                }

            }
        }
        swap(s,t); //change domain, codomain.
        unordered_map<int, int> psi;
        for(int i=0; i<s.length(); i++){
            if(!psi[s[i]]){ //if there is no mapping for that letter
                psi[s[i]] = t[i]; //map it to the corresponding ith letter of string t
            }
            else{ //if there was a mapping for this letter
                if(psi[s[i]]!=t[i]){ //it should be the same.
                    iso = false;
                    return iso;
                }
                
            }
        }
        return iso;
    }
int main(){
    string s = "paper";
    string t = "title";
    cout << isIsomorphic(s,t) << endl;
}