#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

//#include "PegCourdinates.h"

#ifndef __BOARD
#define __BOARD

using namespace std;

enum ERRORS {OUTOFBOUNDS};

class board 
{     
public:
	
	board();//default constructor sets booleans to false. 
	~board(); // clears vector strings.
	board(board &other);//copy vector strings
	
	//player v player, player vs computer, computer vs player.
	void setPlayStyle(string playerState); // "PvP" = 1, "PvC" =2, "CvP" = 3 
	void setRow(int index, string color);  // set hidden row of pegs + colors  
	void setHidden(int index, string color);
	void setUserGuessRowCount();    //only executes if the rowIsSet == true.
	void setNumPegs(int columns);
	
	/*
	 void setPegColorz();
	 void setPegBW(int row, int black, int white);
	 */
	
	void comparison();
	void colorChoices(string color);
	string sColorsToNums(); //converts the color 
	
	
	//private variable return functions...
	int getState();                       //
	int getNumColors();                   //
	int getNumColumns();
	int getBlacks();
	int getWhites();
	int getColorIndex(string color);     // -> for william's computer 
	int getRowCount();   
	string getColorName(int x);
	// ... end.                           //
	
	
	bool isReady(); //returns true if all game options are set and is ready to start game
	bool compareResults();
	bool hiddenIsReady();
	bool colorCheck(string color);
	
	string operator[](int index);             
	
	void clear();// Call to clear 'vector<string> pegs' .            
	void pushlist(); //display list
	void pushColors();
	void newGame(); // call this function to clear vector strings and set boolean checks to false for a new game.
	void quickStart();
	
protected: 
	//clear pegs
	void clearHiddenCombo(); //clears hidden combination
	vector<string> hiddenCombo; //stores hidden combination until cleared at new game.
	vector<string> userGuess; // users cmobination is stored here. index = column #. string = color.
	vector<string> colors;
	void copy(board &other); 
	/*
	 PegCourdinates pegs;
	 PegCourdinates pegsBW;
	 */
	
private: //get hub
	
	bool playerStyle, initializedPegs, hiddenIsSet, initialHidden, rowIsSet; 
	bool numColorsIsSet, colorSet, cols, compare, quikStart;
	int pStyle, numCols, numColors, rowCount, rowCunt;
	int black, white;     
	
	void initPegs(); // sets up vector string to proper number of elements
	void initHidden();
	void hidCombo();
	int random();
               int random(int lo, int hi);
               
              
};

#endif
