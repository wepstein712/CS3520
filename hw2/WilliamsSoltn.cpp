
#include <iostream> 
#include <vector> 
using namespace std; 

void print_board(vector<vector<char> > board) { 
  
    for (int i = 0; i < board.size(); i++) { 
        for (int j = 0; j < board[i].size(); j++) 
            cout << "|" << board[i][j] << "|"; 
        cout << endl; 
    } 
}

bool is_over_row(vector<vector<char> > board) {
    bool check = false;
  char hold = ' ';
  
  for (int i = 0; i < board.size(); i++) {
   for (int j = 0; j < board[i].size(); j++) {
   
     if (j == 0) {
       if (board[i][j] == ' ') {
       
         break;
       }
       hold = board[i][j];
      
       continue;
     } else {
       if (board[i][j] == board[i][j-1]) {
          if (j == board[i].size() - 1) {
            check = true;
            
          }
         continue;
       } else {
         break;
        
       }
      
     }
   }
  }
  return check;
}

bool is_over_column(vector<vector<char> > board) {
  bool check = false;
  char hold = ' ';
  
    for (int j = 0; j < board.size(); j++) {
   for (int i = 0; i < board[j].size(); i++) {
    
     if (i == 0) {
       if (board[i][j] == ' ') {
        
         hold = ' ';
         break;
       }
       hold = board[i][j];
     
       continue;
     } else {
       if (board[i][j] == hold) {
          if (i == board[j].size() - 1) {
            check = true;
            
          }
         
         continue;
       } else {
         hold = ' ';
          
         break;
        
       }
      
     }
   }
  
  }
 return check;
}
bool is_over_neg_diag(vector<vector<char> > board) {
  bool check = false;
  char hold = ' ';

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      
      if (i == j) {
        if (i == 0 ) {
          if (board[i][j] == ' ') {
            hold = ' ';
           
            break;
          } else {
            hold = board[i][j];
           
          }
        } else {
          if (board[i][j] == hold) {
            if (i == board.size() - 1 && board[i][j] != ' ') {
              check = true;
              
            } 
           
            continue;
          } else {
            hold =  ' ';
            
            break;
          }
        }
      } else {
       
      }
    }
   
  }
   return check;
}


bool is_over_pos_diag(vector<vector<char> > board) {
  bool check;
  char hold = ' ';
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      
      if (i+j == board.size()-1) {
        if (j == board.size()-1 ) {
          if (board[i][j] == ' ') {
            hold = ' ';
           
            break;
          } else {
            hold = board[i][j];
            
          }
        } else {
          if (board[i][j] == hold) {
            if (i == board.size() - 1 && board[i][j] != ' ') {
              check = true;
              
            } 
            
            continue;
          } else {
            hold =  ' ';
            
            break;
          }
        }
      } else {
       
      }
    }
  }
  return check;
}
bool is_over(vector<vector<char> > board) {
    return is_over_pos_diag(board) || is_over_neg_diag(board) || is_over_column(board) || is_over_row(board);
}

bool check_tie(vector<vector<char> > board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

bool check_move(int x, int y, vector<vector<char> > board) {
  return board[x][y] != ' ';
}

int main() 
{ 
  bool x_turn = true;
  bool c_game = false;
  int size = 4;
  cout << "Please input the size of the game you would like to play: ";
  cin >> size;
  cout << endl << "A reminder that this is zero indexed, to play the top rightmost spot you would enter 0 0 as your play. Also the first number is row and the second is column with a space in between. Enjoy the game!" << endl;
  vector<vector<char> > board(size, (vector<char>(size, ' ')));
  
  int x_play = 0;
  int y_play = 0;
  while (!is_over(board)) {
    x_turn = !x_turn;
    cout << "The board is currently: " << endl;
    print_board(board);
    if (x_turn) {
      cout << "Player X, enter your move: ";
      cin >> x_play >> y_play;
      while (x_play < 0 || x_play >= size || y_play < 0 || y_play >= size || check_move(y_play, x_play, board)) {
        cout << "Player X that is not a valid play, please input another play: ";
        cin >> x_play >> y_play;
      }
      board[y_play][x_play] = 'X';
      cout << "Move successful!" << endl;
    } else {
      cout << "Player O, enter your move: ";
      cin >> x_play >> y_play;
      while (x_play < 0 || x_play >= size || y_play < 0 || y_play >= size || check_move(y_play, x_play, board)) {
        cout << "Player O that is not a valid play, please input another play: ";
        cin >> x_play >> y_play;
      }
      board[y_play][x_play] = 'O';
      cout << "Move successful!" << endl;
      c_game = check_tie(board);
      if (c_game) {
        break;
      }
    }

  }
  if (!c_game){
    cout << "Congratualtions Player ";
    if (x_turn) {
      cout << "X";
    } else {
      cout << "O";
    }
    cout << endl;
  } else {
    cout << "It was a draw!, here is the final board: " << endl;
  }
  print_board(board);

  return 0; 
} 
