#include<iostream>
#include <vector>
#include <algorithm> //for sorting
#include <cmath>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N, k;
cin >> N;
cin >> k;
vector<int> B;

for (int i=1; i <= N; i++){
    for (int j = i; j <= N; j++){ //upper triangular
        
        if(i==j){ //diagonal terms once
            B.push_back(i*j);
        }
        else{//other terms twice
            B.push_back(i*j);
            B.push_back(i*j);
        }
    }
}


sort(B.begin(), B.end());


cout << B[k]<< endl;
// for(int i=0; i<(N*N); i++){
//     cout << B[i] << endl;
// }
// cout << B.size() << endl;
return 0;
}