#include <iostream>
using namespace std;

//////////////////////////////
// Game Board 

const int boardRows= 6;
const int boardColumns = 7;

//////////////////////////////
// Displaying the Board

void boardVisual (char boardUpdater [boardRows][boardColumns]) 
{ for (int boardRowId = 0; boardRowId < boardRows; boardRowId++) 
{ for (int boardColumnId = 0; boardColumnId < boardColumns; boardColumnId++)
{ cout << boardUpdater [boardRowId][boardColumnId] << " "; } cout << endl; }

for (int labelColumn = 1; labelColumn <= boardColumns; labelColumn++) 
{ cout << labelColumn << " "; }
cout << endl << endl; }

//////////////////////////////
// Drop Game Piece Mechanic

bool dropPlayerChip(char boardUpdater [boardRows] [boardColumns], int playerMove, char activePlayer) 
{ for (int boardRowId = boardRows - 1; boardRowId >= 0; boardRowId--) 

{ if (boardUpdater[boardRowId][playerMove] == '.') 
{ boardUpdater [boardRowId][playerMove] = activePlayer;
  
return true; }} return false;}

//////////////////////////////
// Winner Checker Mechanic

char determineWinner(char boardUpdater [boardRows] [boardColumns])

//////////////////////////////

{ for (int boardRowId = 0; boardRowId < boardRows; boardRowId++) 
{ for (int boardColumnId = 0; boardColumnId <= boardColumns - 4; boardColumnId++) 
{ char checkPlay = boardUpdater [boardRowId][boardColumnId];
  
  if (checkPlay != '.' && checkPlay ==
	  boardUpdater [boardRowId] [boardColumnId + 1] &&
	  
checkPlay == boardUpdater [boardRowId] [boardColumnId + 2] &&
checkPlay == boardUpdater [boardRowId] [boardColumnId + 3]) 

{ return checkPlay;}}}

//////////////////////////////

  for (int boardColumnId = 0; boardColumnId < boardColumns; boardColumnId++) 
{ for (int boardRowId = 0; boardRowId <= boardRows - 4; boardRowId++) 
{ char checkPlay = boardUpdater [boardRowId] [boardColumnId];                                                      
  
  if (checkPlay != '.' && checkPlay == 
	  boardUpdater [boardRowId + 1] [boardColumnId] &&

checkPlay == boardUpdater [boardRowId + 2] [boardColumnId] &&
checkPlay == boardUpdater [boardRowId + 3] [boardColumnId])

{ return checkPlay;}}}

//////////////////////////////

  for (int boardRowId = 3; boardRowId < boardRows; boardRowId++)
{ for (int boardColumnId = 0; boardColumnId <= boardColumns - 4; boardColumnId++)
{ char checkPlay = boardUpdater [boardRowId] [boardColumnId];

  if (checkPlay != '.' && checkPlay ==
	  boardUpdater [boardRowId - 1][boardColumnId + 1] &&

checkPlay == boardUpdater [boardRowId - 2][boardColumnId + 2] &&
checkPlay == boardUpdater [boardRowId - 3][boardColumnId + 3]) 
 
{ return checkPlay;}}}

//////////////////////////////

  for (int boardRowId = 0; boardRowId <= boardRows - 4; boardRowId++) 
{ for (int boardColumnId = 0; boardColumnId <= boardColumns - 4; boardColumnId++) 
{ char checkPlay = boardUpdater [boardRowId] [boardColumnId];

  if (checkPlay != '.' && checkPlay ==
	  boardUpdater [boardRowId + 1][boardColumnId + 1] &&

checkPlay == boardUpdater [boardRowId + 2] [boardColumnId + 2] &&
checkPlay == boardUpdater [boardRowId + 3] [boardColumnId + 3]) 
 
{ return checkPlay; }}}

//////////////////////////////

 return 'N'; }

//////////////////////////////
// Player Choice Game Logic

int main() 
{ char activePlayer, playAgain, playerOne, playerTwo;

/////////////////////////////
// Set Board

do 
{ char boardUpdater [boardRows][boardColumns];
  for (int boardRowId = 0; boardRowId < boardRows; boardRowId++) 

{ for (int boardColumnId = 0; boardColumnId < boardColumns; boardColumnId++) 
{ boardUpdater [boardRowId] [boardColumnId] = '.'; }}

//////////////////////////////
// Active Player Setup

cout << "Symbol for Player 1? : ";
cin >> playerOne;

cout << "Symbol for Player 2? : ";
cin >> playerTwo;

activePlayer= playerOne;

char gameWinner = 'N';
int gameTurn = 0;

//////////////////////////////
// Game Active Player Sequencing

cout << "Start!" << endl;

while (gameTurn < boardRows * boardColumns)
{ boardVisual(boardUpdater);

int playerMove;
cout << "Player " << activePlayer << " enter a number (1-7):";
cin >> playerMove;

//////////////////////////////
//Error Clauses

if ( playerMove < 1 || playerMove > 7) 
{ cout << "Not Possible, Try again." << endl; continue; }

if (!dropPlayerChip( boardUpdater, playerMove - 1, activePlayer)) 
{ cout << "Not Possible. Try again." << endl; continue; }

//////////////////////////////
// End Game

gameWinner = determineWinner(boardUpdater);
if (gameWinner != 'N')
{ boardVisual(boardUpdater); 
cout << "Winner: " << gameWinner << endl; break; }

activePlayer = (activePlayer == playerOne) ? playerTwo : playerOne;
gameTurn++; }

if (gameWinner == 'N') 
{ boardVisual (boardUpdater);
  cout << "Draw" << endl; }

//////////////////////////////
// Endgame Prompt

cout << "play another game? (Y/N): ";
cin >> playAgain; } 

while (playAgain == 'Y');
return 0;}
