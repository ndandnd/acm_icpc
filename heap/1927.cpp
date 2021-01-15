#include<iostream>
#include<vector>
using namespace std;
class MinHeap{
    private:
        int _size{}; //C++11 this means _size = 0;
        vector<int> vect = {-1}; // -1 in first position
        int parent(int i){return i/2;};
        int left_child(int i){return i*2;};
        int right_child(int i){return i*2+1;};
    public:
        bool isEmpty() const{return _size ==0;};
        int getMin() const{return vect[1];};
        void instertItem(int val);
        void shiftUp(int i);
        int extractMin();
        void shiftDown(int i);
};

void MinHeap::shiftUp(int i){// shiftUp element to proper position
    if (i > _size) return; // we cannot shift up if the index is larger than _size
    if (i == 1) return; //End recursion when we are at the top
    if (vect[i] < vect[parent(i)]) { //If it is smaller than the parent, swap
        swap(vect[i], vect[parent(i)]);
    }
    shiftUp(parent(i));//Recursion
}

void MinHeap::instertItem(int val) {
    if ( _size + 1 >= vect.size()){
        vect.push_back(0); //placeholder
    }
    vect[++_size] = val;
    shiftUp(_size);
    return;
}

void MinHeap::shiftDown(int i){
    if(i>_size) return; // does not make sense
    
    int swapID = i;
    if (left_child(i) <= _size && //If the left child exists
        vect[i] > vect[left_child(i)]){ //left child is smaller
        swapID = left_child(i);
    }
    if (right_child(i) <= _size && //right child exists
        vect[swapID] > vect[right_child(i)]){ //swapID is left or the id
            swapID = right_child(i);
        }
    
    if(swapID != i) {
        swap(vect[i], vect[swapID]);
        shiftDown(swapID);
    }
    return;
}

int MinHeap::extractMin(){ //Get rid of the maximum
    int minNum = vect[1];
    swap(vect[1], vect[_size--]);//After swapping vect[1],vect[_size], decrement the size
    shiftDown(1); // The number at node 1, the smallest one
    return minNum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    MinHeap* PriorityQueue = new MinHeap();
    int numOp;
    cin >> numOp;
    for(int i=0; i<numOp; i++){
        int input;
        cin >> input;
        if(input != 0){
            PriorityQueue -> instertItem(input);
        }
        else{
            if(PriorityQueue->isEmpty()){
                cout << 0 << '\n';
            }
            else{
                cout << PriorityQueue->getMin() << '\n';
                PriorityQueue->extractMin();
            }
        }
    
    }
    return 0;
}