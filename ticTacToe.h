#include <iostream>

using namespace std;

class ticTacToe {
private:
  int dimension;
  
  char board[100][100];
  char isXplaying = true;
  char initValue;
  struct player {
    string name;
    int score;
  };
  player player1, player2, winner;

public:
  ticTacToe(string p1, string p2, int dimension = 3, char initValue = ' ') {
    this->player1 = {"(X) " + p1, 0};
    this->player2 = {"(O) " + p2, 0};
    this->dimension = dimension;
    this->resetBoard(initValue);
    this->initValue = initValue;
  }

  void resetBoard(char initValue) {
    for (int i = 0; i < dimension; i++) {
      for (int j = 0; j < dimension; j++) {
        board[i][j] = initValue;
        ;
      }
    }
  }

  char getCell(int row, int column) { return this->board[row][column]; }
  void setCell(int row, int column, char value) {
    this->board[row][column] = value;
  }
  char getDimension() { return this->dimension; }
  bool getIsXPlaying() { return this->isXplaying; }
  void setIsXPlaying(bool value) { this->isXplaying = value; }

  player getPlayer1() { return player1; }

  player getPlayer2() { return player2; }

  void setPlayer1Score(int score) { this->player1.score = score; }
  void setPlayer2Score(int score) { this->player2.score = score; }

  string getWinnerName() { return this->winner.name; }

  int getWinnerScore() { return this->winner.score; }

  bool isFull() {
    for (int i = 0; i < this->dimension; i++) {
      for (int j = 0; j < this->dimension; j++) {
        if (board[i][j] == initValue) {
          return false;
        }
      }
    }
    return true;
  }

  void checkLine(int row, int column) {
    char nowPlaying = (this->isXplaying) ? 'O' : 'X';
    try {
      // check vertical
      for (int i = 0; i < 3; i++) {
        if (this->board[row - 2 + i][column] == nowPlaying &&
            this->board[row - 1 + i][column] == nowPlaying &&
            this->board[row     + i][column] == nowPlaying) {
          this->board[row - 2 + i][column] = '|';
          this->board[row - 1 + i][column] = '|';
          this->board[row     + i][column] = '|';
          (this->isXplaying)?this->player2.score++:this->player1.score++;
        }
      }
      //check horizontal
      for(int i=0; i<3; i++){
         if(
          this->board[row][column - 2 + i] == nowPlaying &&
          this->board[row][column - 1 + i] == nowPlaying &&
          this->board[row][column     + i] == nowPlaying
         ) {
          this->board[row][column - 2 + i] = '-';
          this->board[row][column - 1 + i] = '-';
          this->board[row][column    + i] = '-';
          (this->isXplaying)?this->player2.score++:this->player1.score++;
         }
      }
      //plus diagonal
      for(int i=0; i<3; i++){
         if(
          this->board[row - 2 + i][column + 2 + i] == nowPlaying &&
          this->board[row - 1 + i][column + 1 + i] == nowPlaying &&
          this->board[row     + i][column     + i] == nowPlaying
         ) {
          this->board[row - 2 + i][column + 2 + i] = '/';
          this->board[row - 1 + i][column + 1 + i] = '/';
          this->board[row     + i][column     + i] = '/';
          (this->isXplaying)?this->player2.score++:this->player1.score++;
         }
      }
      //minus diagonal
      for(int i=0; i<3; i++){
         if(
          this->board[row - 2 + i][column - 2 + i] == nowPlaying &&
          this->board[row - 1 + i][column - 1 + i] == nowPlaying &&
          this->board[row     + i][column     + i] == nowPlaying
         ) {
          this->board[row - 2 + i][column - 2 + i] = '\\';
          this->board[row - 1 + i][column - 1 + i] = '\\';
          this->board[row     + i][column     + i] = '\\';
          (this->isXplaying)?this->player2.score++:this->player1.score++;
         }
      }
    }catch (...) {}

    // update score
    if (player1.score > player2.score) {
      winner = player1;
    } else if (player1.score < player2.score) {
      winner = player2;
    } else {
      winner = {"seri", player1.score};
    }
  }

  char getInitValue() { return this->initValue; }
};
