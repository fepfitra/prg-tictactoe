#include <iostream>
#include "ticTacToe.h"
#include "interface.h"

using namespace std;

interface iFace;

bool mainLagi(){  
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
}

int main() {
  do{
    iFace.title();
    ticTacToe ttt(
      iFace.inputString("Masukkan nama player1 : "),
      iFace.inputString("Masukkan nama player2 : "),
      6
    );

    while(!ttt.isFull()){
      iFace.clearScreen();

      iFace.showScore(ttt);
      iFace.showBoard(ttt);
      
      iFace.newLine(2);
  
      iFace.inputCoordinate(ttt);
    }
    iFace.clearScreen();
    iFace.gameOver(ttt);
    
  }while(mainLagi());
  
  iFace.clearScreen();
}

