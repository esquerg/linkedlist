#include <stdio.h>
#include <iostream>
#include <string.h>

#define ROWS 6
#define COLUMNS 7

using namespace std;

int board[ROWS][COLUMNS] = {0};
int choice;

void playerMove(int player){

    do{
        cout << "\nPlayer " << player << "\n";
        cout << "Select a column from 1 to 7 \n";
        cin >> choice;
    } while (choice < 0 || choice > 7);
    
    for(int i = ROWS - 1; i > 0; i--){
        if(board[i][choice-1] == 0){
            board[i][choice-1] = player;
            break;
        }
    }
}

bool checkGame(int player){ 
    for(int i = ROWS - 1; i >= 0; i--){
        for(int j = COLUMNS - 1; j >= 0; j--){
            if(board[i][j] == player){ // The tile is in place 
                if(board[i][j+1] == player){ // The tile on the right is also on place
                    if(board[i][j+2] == player){
                        if(board[i][j+3] == player){ // This is the fourth tile in a row to the right 
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                } else if (board[i+1][j] == player){  //Start checking for row below the tile
                    if(board[i+2][j] == player){
                        if(board[i+3][j] == player &&  i+3 <= 5){ // 4 tiles in a row below the tile
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                } else if (board[i][j-1] == player){ // Check the tiles backwards
                    if(board[i][j-2] == player){
                        if(board[i][j-3] == player){ // 4 tiles in a row backwards
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                } else if(board[i-1][j] == player){ //Check tiles upwards
                    if(board[i-2][j] == player){
                        if(board[i-3][j] == player){ //fourth tile in a row 
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                } else if(board[i-1][j+1] == player){ //Check tiles diagonal up right
                    if(board[i-2][j+2] == player){
                        if(board[i-3][j+3] == player){ //fourth tile in a row 
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                } else if(board[i-1][j-1] == player){ //Check tiles diagonal up left
                    if(board[i-2][j-2] == player){
                        if(board[i-3][j-3] == player){ //fourth tile in a row 
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                } else if(board[i+1][j+1] == player){ //Check tiles diagonal down right
                    if(board[i+2][j+2] == player){
                        if(board[i+3][j+3] == player){ //fourth tile in a row 
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                } else if(board[i+1][j-1] == player){ //Check tiles diagonal down left
                    if(board[i+2][j-2] == player){
                        if(board[i+3][j-3] == player){ //fourth tile in a row 
                            cout << "Player " << player << " won! \n";
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void printGame(){
    for(int i = 0; i < ROWS; i++){
        cout << "\n";
        for(int j = 0; j < COLUMNS; j++){
            cout << "| " << board[i][j] << " |";
        }
    }
    cout << "\n";
}

int main(){
    bool isEnd = true;
    while(checkGame(1) || checkGame(2)){
        printGame();
        playerMove(1);
        if (!checkGame(1)){
            break;
        }
        printGame();
        playerMove(2);
        if (!checkGame(2)){
            break;
        }
    }
    printGame();
}