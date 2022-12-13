#include<iostream>

using namespace std;

class interface{
  public:

    void clearScreen(){
    #ifdef WINDOWS
        system("cls");
    #else
        // Assume POSIX
        system("clear");
    #endif
    }

    void title(){
      this->newLine(2);
      this->divider('=');
      this->newLine();
      cout << "mmmmmmm   \"          mmmmmmm              mmmmmmm\n";
      cout << "   #    mmm     mmm     #     mmm    mmm     #     mmm    mmm\n";
      cout << "   #      #    #\"  \"    #    \"   #  #\"  \"    #    #\" \"#  #\"  #\n";
      cout << "   #      #    #        #    m\"\"\"#  #        #    #   #  #\"\"\"\"\n";
      cout << "   #    mm#mm  \"#mm\"    #    \"mm\"#  \"#mm\"    #    \"#m#\"  \"#mm\"\n";
      this->newLine();
      this->divider('=');
      this->newLine(2);
    }

    string inputString(string message){
      cout << message;
      string s;
      cin >> s;
      return s;
    }

    void divider(char style, int width=63, bool newLine=true){
      if(width<1){
        cout << "Invalid divider() usage: width must be 1 above";
      }else{
        for(int i=0; i<width; i++){
          cout << style;
        }
      }
      if(newLine) cout << endl;
    }

    void newLine(int lineCount=1){
      if(lineCount<1){
        cout << "Invalid newLine() usage: lineCount must be 1 above";
      }else{
        for(int i=0; i<lineCount; i++){
          cout << "\n";
        }
      }
    }

    void showBoard(ticTacToe& game, string divider = " | ", int distance=10){
      
      this->divider('-', 3 + 4*game.getDimension(), false);
      this->divider(' ', distance, false);
      this->divider('-', 3 + 5*game.getDimension());
      cout << "  Board";
      this->divider(' ', 4*game.getDimension()+distance-2, false);
      cout << "Visual" << endl;
      this->divider('-', 3 + 4*game.getDimension(), false);
      this->divider(' ', distance, false);
      this->divider('-', 3 + 5*game.getDimension());

      
      for(int i=0; i<game.getDimension(); i++){
        cout << divider;
        for(int j=0; j<game.getDimension(); j++){
          cout << game.getCell(i,j);
          cout << divider;
        }
        this->divider(' ', distance, false);
        cout << divider;
        for(int j=0; j<game.getDimension(); j++){
          (game.getCell(i, j)==' ') ?  cout << char(97+i) << char(97+j): cout << "  ";
          cout << divider;
        }

        
        this->newLine();
        this->divider('-', 3 + 4*game.getDimension(), false);
        this->divider(' ', distance, false);
        this->divider('-', 3 + 5*game.getDimension());
      }
    }

    void showScore(ticTacToe& game){
      this->divider('=');
      cout << game.getPlayer1().name << "\t\t" << game.getPlayer1().score << endl;
      cout << game.getPlayer2().name << "\t\t" << game.getPlayer2().score << endl;
      this->divider('=');
      this->newLine(2);
    }

    void inputCoordinate(ticTacToe& game){
      string coordinate;
      char val;
      if(game.getIsXPlaying()){
        coordinate = this->inputString(game.getPlayer1().name + " giliran main, silakan input koordinat : ") + "\n";
        game.setIsXPlaying(false);
        val = 'X';
      }else{
        coordinate = this->inputString(game.getPlayer2().name + " giliran main, silakan input koordinat : ") + "\n";
        game.setIsXPlaying(true);
        val = 'O';
      }
      int row = coordinate.at(0)-97;
      int column = coordinate.at(1)-97;
      if(game.getCell(row, column) == game.getInitValue()){
        game.setCell(row , column, val);
      }else{
        game.getIsXPlaying()?game.setIsXPlaying(false):game.setIsXPlaying(true);
      }
      game.checkLine(row, column);
    }

    void gameOver(ticTacToe game){
      newLine(5);
      cout << "OUR WINNER IS ...";
      newLine(2);
      divider('=');
      newLine(2);
      cout << game.getWinnerName() << "!!!" << endl;
      cout << "Point : " << game.getWinnerScore() << endl;;
      newLine(2);
      divider('=');
      newLine(5);
    }
};
