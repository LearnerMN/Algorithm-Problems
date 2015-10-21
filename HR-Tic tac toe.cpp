//https://www.hackerrank.com/challenges/tic-tac-toe/submissions/game/14637612
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
bool move  = false;
void check1(char p1, vector <string> board, bool move);
void check2(char p1, vector <string> board, bool move);
void check3(char p1, vector <string> board, bool move);
void check4(char p1, vector <string> board, bool move);
void check5(char p1, vector <string> board, bool move);
     
void nextMove(char p1, vector <string> board){
     if (!move) check1(p1,board,move);
     if (!move) check2(p1,board,move);
     if (!move) check3(p1,board,move);
     if (!move) check4(p1,board,move);
     if (!move) check5(p1,board,move);
     
}
char p2(char p1){ 
     if ((int)p1==88) return (char)79;
  return (char)88;
}
void check1(char p1, vector <string> board, bool move){
     
     int count[3] = {0};
     vector<int> vec[3];
     for (int i=0; i<3; i++){
         int c=0;
         for (int k=0; k<3; k++){
             if (board[i][k] == p1)  count[0]++;
             if (board[i][k] == p2(p1)) count[1]++;
             if (board[i][k] == char(95)){
                count[2]++;
                vec[c].push_back(i);
                vec[c++].push_back(k); 
             }
         }
         if (((count[1]==2) || (count[0]==2)) && count[2]==1){
            board[vec[0][0]][vec[0][1]] = p1;
            move  = true;
            break;
         }
         if (move) break;
         for (int p=0; p<3; p++) vec[p].clear();
     }
}
void check2(char p1, vector <string> board, bool move){
     
     vector<int> vec[3];
     int count[3] = {0};
     for (int i=0; i<3; i++){
         int c=0;
         for (int k=0; k<3; k++){
             if (board[k][i] == p1)  count[0]++;
             if (board[k][i] == p2(p1)) count[1]++;
             if (board[k][i] == char(95)){
                count[2]++;
                vec[c].push_back(i);
                vec[c++].push_back(k); 
             }
         }
         if (((count[1]==2) || (count[0]==2)) && count[2]==1){
            board[vec[0][0]][vec[0][1]] = p1;
            move  = true;
            break;
         }
         if (move) break;
         for (int p=0; p<3; p++) vec[p].clear();
     }  
}
void check3(char p1, vector <string> board, bool move){
     
     vector<int> vec[3];
     int count[3] = {0};
     int c=0;
     for (int k=0,i=0; k<3 && i<3; k++,i++){
         if (board[k][i] == p1)  count[0]++;
         if (board[k][i] == p2(p1)) count[1]++;
         if (board[k][i] == char(95)){
            count[2]++;
            vec[c].push_back(i);
            vec[c++].push_back(k); 
         }
     }
     if (((count[1]==2) || (count[0]==2)) && count[2]==1){
        board[vec[0][0]][vec[0][1]] = p1;
        move  = true;
     }
}
void check4(char p1, vector <string> board, bool move){
     
     vector<int> vec[3];
     int count[3] = {0};
     int c=0;
     for (int k=2,i=0; k>=0 && i<3; k--,i++){
         if (board[i][k] == p1)  count[0]++;
         if (board[i][k] == p2(p1)) count[1]++;
         if (board[i][k] == char(95)){
            count[2]++;
            vec[c].push_back(i);
            vec[c++].push_back(k); 
         }
     }
     if (((count[1]==2) || (count[0]==2)) && count[2]==1){
        board[vec[0][0]][vec[0][1]] = p1;
        move  = true;
     }
}
void check5(char p1, vector <string> board, bool move){
     
     for (int i=0; i<3; i++){
         for (int k=0; k<3; k++){
             if (board[i][k] == char(95)){
                board[i][k] = p1;
                move  = true;
                break;
             }
             if (move) break;
         }
     }
     for (int i=0; i<3; i++) {
         cout<<board[i]<<endl;
     }
}
int main() {

    char player;
    vector <string> board;

    cin >> player;

    for(int i=0; i<3; i++) {
      string s; cin >> s;
      board.push_back(s);
    }
    
   nextMove(player,board);
 return 0;
}
