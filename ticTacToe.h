#include<iostream>

using namespace std;

class ticTacToe{
  private:
    int dimension;
    char board[100][100]; //max dimension = 100
    char isXplaying = true;
    char initValue;
    struct player{
      string name;
      int score;
    };
    player player1, player2, winner;

  public:
    ticTacToe(string p1, string p2, int dimension=3, char initValue=' '){
      this->player1 = {"(X) " + p1, 0};
      this->player2 = {"(O) " + p2, 0};
      this->dimension = dimension;
      this->resetBoard(initValue);
      this->initValue = initValue;

    }

    void resetBoard(char initValue){
      for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
          board[i][j] = initValue;;
        }
      }
    }

    char getCell(int row, int column){
      return this->board[row][column];
    }
    void setCell(int row, int column, char value){
      this->board[row][column] = value;
    }
    char getDimension(){
      return this->dimension;
    }
    bool getIsXPlaying(){
      return this->isXplaying;
    }
    void setIsXPlaying(bool value){
      this->isXplaying = value;
    }

    player getPlayer1(){
      return player1;
    }

    player getPlayer2(){
      return player2;
    }

    void setPlayer1Score(int score){
      this->player1.score = score;
    }
    void setPlayer2Score(int score){
      this->player2.score = score;
    }

    string getWinnerName(){
      return this->winner.name;
    }

    int getWinnerScore(){
      return this->winner.score;
    }

    bool isFull(){
      for(int i=0; i<this->dimension; i++){
        for(int j=0; j<this->dimension; j++){
          if(board[i][j] == initValue){
            return false;
          }
        }
      }
      return true;
    }

    void checkLine(){
      char nowPlaying = (this->isXplaying)?'O':'X';
      //check horizontal
      for(int i=0; i<this->dimension; i++){
        for(int j=0; j<this->dimension-3; j++){
          if(
            this->board[i][j] == nowPlaying &&
            this->board[i][j+1] == nowPlaying && 
            this->board[i][j+2] == nowPlaying
          ){
            this->board[i][j] = '-';
            this->board[i][j+1] = '-';
            this->board[i][j+2] = '-';
            (this->isXplaying)?this->player2.score++:this->player1.score++;
          }
        }
      }
      //check vertikal
      for(int i=0; i<this->dimension-3; i++){
        for(int j=0; j<this->dimension; j++){
          if(
            this->board[i][j] == nowPlaying &&
            this->board[i+1][j] == nowPlaying && 
            this->board[i+2][j] == nowPlaying
          ){
            this->board[i][j] = '|';
            this->board[i+1][j] = '|';
            this->board[i+2][j] = '|';
            (this->isXplaying)?this->player2.score++:this->player1.score++;
          }
        }
      }
      //check posDiagonal
      for(int i=0; i<this->dimension-3; i++){
        for(int j=0; j<this->dimension-3; j++){
          if(
            this->board[i+2][j] == nowPlaying &&
            this->board[i+1][j+1] == nowPlaying && 
            this->board[i][j+2] == nowPlaying
          ){
            this->board[i+2][j] = '/';
            this->board[i+1][j+1] = '/';
            this->board[i][j+2] = '/';
            (this->isXplaying)?this->player2.score++:this->player1.score++;
          }
        }
      }
      //check negDiagonal
      for(int i=0; i<this->dimension-3; i++){
        for(int j=0; j<this->dimension-3; j++){
          if(
            this->board[i][j] == nowPlaying &&
            this->board[i+1][j+1] == nowPlaying && 
            this->board[i+2][j+2] == nowPlaying
          ){
            this->board[i][j] = '\\';
            this->board[i+1][j+1] = '\\';
            this->board[i+2][j+2] = '\\';
            (this->isXplaying)?this->player2.score++:this->player1.score++;
          }
        }
      }
      if(player1.score > player2.score){
        winner = player1;
      }else if(player1.score < player2.score){
        winner = player2;
      }else{
        winner = {"seri", player1.score};
      }
      
    }

    bool getXPlaying(){
      return isXplaying;
    }

    void setXPlaying(bool value){
      this->isXplaying = value;
    }

    char getInitValue(){
      return this->initValue;
    }
    
};
