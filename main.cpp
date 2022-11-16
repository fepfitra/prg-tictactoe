#include <iostream>

using namespace std;

class ticTacToe{
  private:
    char board[6][6];
    char playingCode = 'X';
    struct {
      string name;
      int score;
    } player1, player2;
    string winner;

  public:
    void inputPlayerName(){
      //Todo1
    }

    void showBoard(){
      //Todo2
    }

    void inputToBoard(){
      //Todo3
    }

    void checkLine(){
      //todo4
    }

    string win(){
      //todo5
      return winner;
    }

    void clearScreen(){
      //todo6=≠
    }
};

int main() {
  return 0;
}
