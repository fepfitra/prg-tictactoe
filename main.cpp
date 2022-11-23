#include <iostream>
#include "ticTacToe.h"
#include "interface.h"

using namespace std;

interface iFace;


bool play(){
  iFace.title();
  ticTacToe ttt(
    iFace.inputString("Masukkan nama player1 : "),
    iFace.inputString("Masukkan nama player2 : "),
    6
  );

  // for test purpose
  // ticTacToe ttt("Hoho", "Hehe", 6);
  while(!ttt.isFull()){
    iFace.clearScreen();

    //showScore
    iFace.showScore(ttt);
    iFace.showBoard(ttt);
    iFace.newLine(2);

    //fill the board
    iFace.inputCoordinate(ttt);
  }
  iFace.clearScreen();
  iFace.gameOver(ttt);

  
  while(true){
    cout << "Mau main lagi ? (y/n) : ";
    char c;
    cin >> c;

    
    if(c == 'y'){
      return true;
    }else if(c== 'n'){
      return false;
    }
  }
  return false;
}

int main() {
  bool running = true;
  while(running){
    running = play();
  }
}

