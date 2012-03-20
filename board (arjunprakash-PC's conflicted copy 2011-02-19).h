#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>


#ifndef __BOARD
#define __BOARD

using namespace std;

enum ERRORS {OUTOFBOUNDS};

class board
{     
      public:
             board();
             ~board();
             board(board &other);
                                                    //player v player, player vs computer, computer vs player.
             void setPlayStyle(string playerState); // "PvP" = 1, "PvC" =2, "CvP" = 3 
             void setRow(int index, string color);  // set hidden row of pegs + colors   
             void setNumPegColors(int columns, int colors);// set number of pegs(columns) and number of colors
             
             //private variable return functions...
             int getState();             
             int getNumPegs();
             int getNumColors();
             // ... end.
             
             string operator[](int index);            
             void pushlist(); //display list
             
      protected: //possible inheritance
                void clear();   //clear pegs
                void clearHiddenCombo(); //clears hidden combination
                vector<string> hiddenCombo; //stores hidden combination until cleared at new game.
                vector<string> pegs; // users cmobination is stored here. index = column #. string = color.
                void copy(board &other);    // copy list
      private:
              int pStyle, numCols, numColors;
              void hidCombo();
              bool pegsColors, playerStyle, initializedPegs, hiddenIsSet;
              void initPegs(); // sets up vector string to proper number of elements
              
};

#endif

