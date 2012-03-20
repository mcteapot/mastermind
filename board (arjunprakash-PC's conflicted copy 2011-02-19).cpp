
#include "board.h"

board::board()
{
 pegsColors = false;
 playerStyle = false;
 initializedPegs = false;
 hiddenIsSet = false;              
}

board::~board()
{
     clear();
}

void board::setPlayStyle(string playerState)// PvP = 1, PvC =2, CvP = 3 
                                            //: -> bool (user set or did not set options. choose pegs, columns, play style.
{
                                            
 if( playerState == "pvp" | playerState == "PvP" | playerState == "pVp" |
     playerState == "PVP" )
 {
     pStyle = 1;
     playerStyle = true;
 }
 else if( playerState == "pvc" | playerState == "PvC" | playerState == "pVc" |
     playerState == "PVC" )
 {
     pStyle = 2;
     playerStyle = true;
 }
 else if( playerState == "cvp" | playerState == "CvP" | playerState == "cVp" |
     playerState == "CVP" )
 {
     pStyle = 3;
     playerStyle = true;
 }
 else
 {
     pStyle = 0;
     playerStyle = false;
 }
}

int board::getState()
{
    return pStyle;    
}

void board::setRow(int index, string color)
{
 if( pegsColors && playerStyle)     
 {
     int count = 0;    
  if(index >= 0 && index < numCols)
   {           
       if( pegs.empty() )
            initPegs();
            
           
         for(vector<string>::iterator i = pegs.begin(); i != pegs.end(); ++i)
              {
                 if(count == index)        
                    *i = color;               
                    ++count;
              }
       hiddenIsSet = true;
       hidCombo();
       
   }
  else
      {
         cout << "Error setRow: else executed.\n";
         system("pause");
         exit(1);
         }   
   } 
   else
       printf("Error setRow: Player style, pegs, and colors not set.\n");
       
}  
   

void board::setNumPegColors(int columns, int colors)
{
     if( playerStyle )
     {
     if( (columns >= 4 && columns <= 10) && (colors >= 4 && colors <= 10) )
      {
          numCols = columns;
          numColors = colors;
          pegsColors = true;
      }
     else
          pegsColors = false;
     }
}

int board::getNumPegs()
{
    if( pegsColors )
        return numCols;    
    else
        return 0;
}

int board::getNumColors()
{
    if( pegsColors )
        return numColors;    
    else
        return 0;
}

void board::pushlist()
{
     if ( playerStyle && pegsColors )
     {
     if( pegs.size() != 0 )
     {
        for(int i = 0; i < pegs.size(); i++)
           cout << pegs[i] << endl;
        /*   cout << endl; 
        for(int i = 0; i < hiddenCombo.size(); i++)
           cout << hiddenCombo[i] << endl; */
        }
     else
         printf("No list exists.\n");
     }
     else
         printf("Error pushlist: Player style, pegs, and colors not set.\n");
}

void board::copy(board &other)
{
     pegs = other.pegs;
}

string board::operator[](int index)
{
        if(index < 0 || index > (pegs.size()-1))
          throw OUTOFBOUNDS;
        return pegs[index];    
}

board::board(board &other)
{
     copy(other);                   
}

void board::clear()
{
     pegs.clear();
}

void board::clearHiddenCombo()
{
     hiddenCombo.clear();
}

void board::initPegs()
{
     int x = 0;
     string line = "";
     while (x < numCols)
       {
          pegs.push_back(line);
          x++;
       } 
       initializedPegs = true;
}


void board::hidCombo()
{
     hiddenCombo = pegs;
}
