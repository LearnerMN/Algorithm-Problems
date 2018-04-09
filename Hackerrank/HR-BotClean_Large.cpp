//https://www.hackerrank.com/challenges/botcleanlarge
#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

void move_cor(int i,int j, int x1,int y1){
    if (i < x1){
        cout<<"DOWN"<<endl;
        return;
    }else if (i > x1){
        cout<<"UP"<<endl;
        return;
    }
    if (j < y1){
        cout<<"RIGHT"<<endl;
        return;
    }else if (j > y1){
        cout<<"LEFT"<<endl;
        return;
    }
}

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
    if (board[posr][posc] == 'd'){
        cout<<"CLEAN"<<endl;
        return;
    }
    //add logic here
    int tmp_x=-1,tmp_y=-1;
    int mins = INT_MAX;
    for (int i=0; i<dimh; i++){
        for (int j=0; j<dimw; j++){
            if (!(posr == i && posc == j) && board[i][j] == 'd'){
               int tmp_sum = abs(posr - i) + abs(posc - j);
               if (tmp_sum < mins){
                   tmp_x = i; tmp_y = j;
                   mins = tmp_sum;
               }
            }
        }
    }
    
    if (!(tmp_x == -1 && tmp_y == -1)){
        move_cor(posr,posc,tmp_x,tmp_y);
    }else{
        
    }
}
int main(void) {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
