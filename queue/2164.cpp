#include<iostream>
#include<queue>
using namespace std;
int main(){
    //for speed (only makes a difference if we cining a lot)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> cards;
    int num_cards;
    cin >> num_cards;
    
    //create card deck
    for(int i=1; i<=num_cards;i++){
        cards.push(i);
    }
    while(cards.size()>1){
        cards.pop();
        int to_back;
        to_back = cards.front();
        cards.pop();
        cards.push(to_back);
    }
    cout<<cards.front()<<'\n';
}