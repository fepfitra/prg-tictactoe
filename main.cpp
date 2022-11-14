#include <iostream>

using namespace std;

char board[5][5]; //pakai papan 3x3, nilai hanya X, O, dan _
bool isPlayerx = true;
struct {
  string name;
  int score;
} playerx, playero;

void init(); //Todo mengisi data dan menampilkan papan kosong
bool isAvailable(int row, int column); //mengecek apakah bisa diisi atau tidak
bool isInputValid(int number); //mengecek apakah inputnya valdi

void clearScreen(); //menghapus layar

bool isEnd(); //mengecek apakah tabel terisi semua

void showBoard(); //menampilkan semua data

int main() {
  init();
  showBoard();
  return 0;
}
