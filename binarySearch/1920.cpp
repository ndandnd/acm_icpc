#include<iostream>
#include <vector>
#include <algorithm> //for sorting
#include <cmath>
using namespace std;

// int binarySearch(vector<int> vec, int begin, int end, int lookfor){ //returns 1 if in the vector, 0 otherwise
//     int mid;
//     if(end >= begin){
//         mid = (begin+end)/2;
//         if(vec[mid] == lookfor){
//             return 1;
//         }
//         if(vec[mid] > lookfor){
//             return binarySearch(vec, begin, mid-1, lookfor);
//         }
//         if(vec[mid] < lookfor){
//             return binarySearch(vec, mid+1, end, lookfor);
//         }
//     }
//     return -1;
// }

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N, M;
cin >> N;
vector<int> members, test, answer;


for(int i=0; i<N;i++){
    int next;
    cin >> next;
    members.push_back(next);
}
cin >> M;
for(int i=0; i<M;i++){
    int next;
    cin >> next;
    test.push_back(next);
}

sort(members.begin(), members.end());
// make_heap(members.begin(),members.end());
// sort_heap(members.begin(),members.end());
//members is now sorted.

// for(int i=0; i<N;i++){
//     cout << members[i] << ' ';
// }
// int begin = members.front();
// int end = members.back();



int max_iter = ceil(log2(members.size()));


for(int i=0; i<M;i++){
    int begin = 0, end = N; //reset after each trial
    for(int iter = 1; iter <= max_iter+2; iter++){//+1 for case where N=1
        
        if(iter == max_iter+2 || (begin > end)){ //Not found
            cout << 0 << '\n';
            break; //
        }
    
        int mid = (begin+end)/2;
        

        if(members[mid] == test[i]){
            cout << 1 << '\n';
            break; //move on to next test[i]
        }
        
        else if(members[mid] > test[i]){
            end = mid-1;
        }
        else{
            begin = mid+1;
        }
    }

return 0;
}



// class MaxHeap{
//     private:
//         int _size{}; //C++11 this means _size = 0;
//         vector<int> vect = {-1}; // -1 in first position
//         int parent(int i){return i/2;};
//         int left_child(int i){return i*2;};
//         int right_child(int i){return i*2+1;};
//     public:
//         bool isEmpty() const{return _size ==0;};
//         int getMax() const{return vect[1];};
//         void instertItem(int val);
//         void shiftUp(int i);
//         int extractMax();
//         void shiftDown(int i);
// };

// void MaxHeap::shiftUp(int i){// shiftUp element to proper position
//     if (i > _size) return; // we cannot shift up if the index is larger than _size
//     if (i == 1) return; //End recursion when we are at the top
//     if (vect[i] > vect[parent(i)]) { //If it is larger than the parent, swap
//         swap(vect[i], vect[parent(i)]);
//     }
//     shiftUp(parent(i));//Recursion
// }

// void MaxHeap::instertItem(int val) {
//     if ( _size + 1 >= vect.size()){
//         vect.push_back(0); //placeholder
//     }
//     vect[++_size] = val;
//     shiftUp(_size);
//     return;
// }

// void MaxHeap::shiftDown(int i){
//     if(i>_size) return; // does not make sense
    
//     int swapID = i;
//     if (left_child(i) <= _size && //If the left child exists
//         vect[i] < vect[left_child(i)]){ //left child is greater
//         swapID = left_child(i);
//     }
//     if (right_child(i) <= _size && //right child exists
//         vect[swapID] < vect[right_child(i)]){ //swapID is left or the id
//             swapID = right_child(i);
//         }
    
//     if(swapID != i) {
//         swap(vect[i], vect[swapID]);
//         shiftDown(swapID);
//     }
//     return;
// }

// int MaxHeap::extractMax(){ //Get rid of the maximum
//     int maxNum = vect[1];
//     swap(vect[1], vect[_size--]);//After swapping vect[1],vect[_size], decrement the size
//     shiftDown(1);
//     return maxNum;
// }


// int main(){
//     MaxHeap* PriorityQueue = new MaxHeap(); 
//     if (PriorityQueue->isEmpty()){
//         cout << "Correct" << endl;
//     } else{
//         cout << "We have a problem with isEmpty fct" << endl;
//     }
//     PriorityQueue -> instertItem(10);
//     PriorityQueue -> instertItem(120);
//     PriorityQueue -> instertItem(34);
//     PriorityQueue -> instertItem(41);
//     PriorityQueue -> instertItem(5);
//     cout << PriorityQueue->getMax() << endl;
//     PriorityQueue->extractMax();
//     cout << PriorityQueue->getMax() << endl;
//     if (!PriorityQueue->isEmpty()){
//         cout << "Correct" << endl;
//     } else{
//         cout << "We have a problem with isEmpty fct" << endl;
//     }

//     return 0;
// }