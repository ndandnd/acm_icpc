#include<iostream>
#include<deque>
using namespace std;

/*
//Assume that deque is [FRONT, ... , BACK]
void rotate_left(deque<int> &q, int k){ //must call by reference
    //sends k integers to the back
    for(int i=0; i<k; i++){
        int temp = q.front();
        q.pop_front();
        q.push_back(temp);
    }

}

void rotate_right(deque<int> &q, int k){ //must call by reference
    //sends k integers to the front
    for(int i=0; i<k; i++){
        int temp = q.back();
        q.pop_back();
        q.push_front(temp);
    }
    
}
*/

int keepInRange(int arg, int cell_size){ // call by ref.
    if(arg>cell_size){
        arg -= cell_size;
    }
    else if(arg<1){
        arg += cell_size;
    }
    return arg;
} 

int pushes_needed(int arg, int cell_size){
    int mid = 1 + cell_size/2;
    if(arg <= mid){//bottom half
        return arg-1;
    }
    else{//on the top half.
        return cell_size-arg+1;
    }
    
}

int main(){
    //for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rotations(0); //output
    int size, num_to_pick;
    cin >> size >> num_to_pick;
    
    //create todo list
    deque<int> todo;
    for(int i=0; i<num_to_pick; i++){
        int pick;
        cin >> pick;
        todo.push_back(pick);
    }

    //must count till todo list is empty
    while(!todo.empty()){
        int med = 1 + size/2;
        int pushby = pushes_needed(todo.front(), size);
        rotations += pushby; //update by that many pushes

        for(int j=1;j<=todo.size();j++){//update the todo loop, except the front
            if(todo.front() <= med){//rotate left
                todo[j] -= pushby;
                todo[j] = keepInRange(todo[j], size); //keep them in range
                }
            else{ //rotate right
                todo[j] += pushby;
                todo[j] = keepInRange(todo[j], size);
            }
            todo[j]--; //since we are going to pop the front.
        }
        todo.pop_front();
        size--;
    }
    cout << rotations;
    return 0;
}