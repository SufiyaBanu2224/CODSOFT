#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

void drawBoard() {
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]
       << endl;
  cout << "---|---|---\n";
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]
       << endl;
  cout << "---|---|---\n";
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]
       << endl;
}

bool placeMarker(int slot) {
  int row = slot / 3;     //for row: (1,2,4,5,7,8)/3 = (0,0,1,1,2,2)  respectively
  int col;

  if (slot % 3 == 0) {  //If number will be 3,6,9 then only it will run
    row = row - 1;
    col = 2;
  } else {
    col = (slot % 3) - 1; 
  }

  if (board[row][col] != 'X' && board[row][col] != 'O') {
    board[row][col] = current_marker;
    return true;
  } else {
    return false;
  }
}

int winner() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) //Horizontol Check
      return current_player;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) //Vertical Check
      return current_player;
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])   //Diagonal Check from Left to right
    return current_player;                                        //
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0])   //Diagonal Check from Right to left
    return current_player;

  return 0;
}

void swapPlayerAndMarker() {   // Swap Player during restart of each loop
  if (current_marker == 'X')
    current_marker = 'O';
  else
    current_marker = 'X';

  if (current_player == 1)
    current_player = 2;
  else
    current_player = 1;
}

void game() {
  cout << "Player one, choose your marker(O or X): ";
  char marker_p1;
  cin >> marker_p1;

  current_player = 1;
  current_marker = marker_p1;

  drawBoard();

  int player_won;

  for (int i = 0; i < 9; i++) {
    cout << "It's player " << current_player << "'s turn. Enter your slot: ";
    int slot;
    cin >> slot;

    if (slot < 1 || slot > 9) {
      cout << "That slot is invalid! Try another slot!\n";
      i--;
      continue;
    }

    if (!placeMarker(slot)) {
      cout << "That slot is occupied! Try another slot!\n";
      i--;
      continue;
    }
    drawBoard();

    player_won = winner();

    if (player_won == 1) {
      cout << "Player one won! Congratulations!\n";
      break;
    }
    if (player_won == 2) {
      cout << "Player two won! Congratulations!\n";
      break;
    }

    swapPlayerAndMarker();
  }
  if (player_won == 0) {
    cout << "It's a tie game!\n";
  }
}

int main() {
  game();
  return 0;
}
