#include "board.h"

board::board()
{ 
	playerStyle = false;//checks if playerStyle is set.
	initializedPegs = false;//checks if the pegs vector string has been initialized.
	hiddenIsSet = false;//checks if the hidden combination vector string has been set.
	compare = false;
	initialHidden = false;
	numColorsIsSet = false;
	rowIsSet = false;
	colorSet = false;
	cols = false;
	quikStart = false;
	
	rowCount = 1; 
	rowCunt = 0;
	numCols = 0;
	numColors = 0;
	pStyle = 0;
	black = 0;
	white = 0;             
}

board::~board()
{
	clear();//clears "userGuess" v-string
	clearHiddenCombo(); // clears "hiddenCombo" v-string
}

void board::quickStart()
{     
	//cout << "inside of quickStart()!!\n\n\n";
	quikStart = true;
	vector<string> temp, temp2;
	temp.push_back("pvp"); temp.push_back("pvc"); temp.push_back("cvp");
	
	setPlayStyle( temp[random(0,3)].c_str() );     
	setNumPegs( random(4,10) ); 
	
	fstream colorz;
	
	colorz.open("colors.txt", ios::in);
    if( !(colorz.is_open()) )
	{
		cout <<"Unable to load colors.\n\n";
		system("pause");
		exit(0);
	}
    else
	{
		string line;
        while ( getline(colorz,line,'\n') )
			temp2.push_back(line);      
		colorz.close(); 
		
		int csize = random(4,11);
		
		for(int i = 0; i < csize; i++)
		{
			int x = random(0,10);
			if(temp2[x] != "taken")
			{
				colorChoices( temp2[x].c_str() );
				temp2[x] = "taken";
			}
		}
		for(int k = 0; k < temp2.size(); k++)
			colorChoices(temp2[k].c_str());
	}
}

int board::random()
{
	srand ( time(NULL) );
	return rand()%numColors;  
} 

int board::random(int lo, int hi)
{
    srand ( time(NULL) );
    int i=rand()%hi;
    return (i<lo) ?  i+lo : i;
}

/*
 void board::setPegColorz()
 {
 pegs.InitPegColors(numCols, 10, 71, 307, 563, 53);
 for(vector<string>::iterator i = userGuess.begin(); i != userGuess.end(); ++i)
 pegs.setPegColor(9, 3, *i);    
 }
 
 void board::setPegBW()
 {
 pegsBW.IntPegBW(10, 47, 563, 53);
 pegsBW.setPegBW(rowCunt, black, white);    
 }
 */             


string board::sColorsToNums()
{
	int count = 0;
	std::stringstream ss (stringstream::in | stringstream::out);
	for(int k =0; k < userGuess.size(); k++)
	{                            
		for(vector<string>::iterator i = colors.begin(); i != colors.end(); ++i)
		{                                
			if( userGuess[k] == *i )
				ss << getColorIndex(*i);
			else
				ss << "";                        
        }
		++count;
	}
	return ss.str();
}

void board::colorChoices(string color)
{
	colors.push_back(color);
	if(colors.size() > 3 && colors.size() < 10)
	{
		numColors = colors.size();
		colorSet = true;
	}
} 

bool board::colorCheck(string color)
{
	for(vector<string>::iterator i = colors.begin(); i != colors.end(); ++i)
	{
		if( *i == color)
			return true;
	}
}


void board::pushColors()
{
	if( colorSet )
		for(int i = 0; i < colors.size(); i++)
			cout << colors[i] << endl;
	
}

void board::comparison()
{
    if( hiddenCombo == userGuess )
	{
		compare = true;
		white=0;
		black=numCols;
	}
    
    else
    {   
		vector<string> temp1=hiddenCombo, temp2=userGuess;
		black=0;
		for(int i = 0; i < temp1.size(); i++)
		{
			if(temp1[i]==temp2[i])
			{
				black++;
				temp1[i]="0";
				temp2[i]="1";
			}
			
		}
		white=0;
		for(int i=0; i<temp1.size(); i++)
		{
			for(int j=0; j<temp2.size(); j++)
				if(temp1[i]==temp2[j])
				{
					white++;
					temp1[i]="2";
					temp2[j]="3";                  
				}   
		} 
    } 
}



void board::pushlist()
{
	if ( isReady() && rowIsSet )
	{
		if( userGuess.size() != 0 )
		{
			cout << "hiddenCombo: " << endl;
			for(int i = 0; i < hiddenCombo.size(); i++)
				cout << hiddenCombo[i] << endl;
			cout << endl << "userGuess: " << endl; 
			for(int i = 0; i < userGuess.size(); i++)
				cout << userGuess[i] << endl; 
			cout << "userGuess.size() : "<< userGuess.size() << endl;  
        }
		else
			printf("No list exists.\n");
	}
	else
		printf("Error pushlist: Game options not set.\n");
}



/* ... START of INITIALIZATIONS. */
void board::initHidden()
{
	int x = 0;
	string line = "";
	while (x < numCols)
	{
		hiddenCombo.push_back(line);
		x++;
	} 
	
	initialHidden = true;
}

void board::initPegs()
{
	int x = 0;
	string line = "";
	while (x < numCols)
	{
		userGuess.push_back(line);
		x++;
	} 
	
	initializedPegs = true;
}
/* ... END of INITIALIZATIONS. */



void board::newGame() // Called for new game. Clears out the vector strings and sets 
// all booleans to false -> user must input all settings again.
{
	userGuess.clear();
	hiddenCombo.clear();
	colors.clear(); 
	
	playerStyle = false;
	initializedPegs = false;
	hiddenIsSet = false;
	compare = false;
	initialHidden = false;
	numColorsIsSet = false;
	rowIsSet = false;
	colorSet = false;
	cols = false;
	quikStart = false;
	
	rowCount = 1; 
	rowCunt = 0;
	numCols = 0;
	numColors = 0;
	pStyle = 0;
	black = 0;
	white = 0;  
	
}

/* START of BOOLEANS ... */ 

bool board::compareResults()
{
	if(compare)
		return true;
	else
		return false;
}

bool board::hiddenIsReady()
{
	return hiddenIsSet;
}

bool board::isReady() 
{
	if(colorSet && playerStyle && cols && !compare)
		return true;
	else
		return false;      
}
/* ... END of BOOLEANS. */



/* START of SETTERS... */
void board::setUserGuessRowCount()
{
	
	if( rowIsSet )
	{
		if( rowCount > numCols )
		{          
			comparison();  
		}
		rowCunt++;
	}
}

void board::setRow(int index, string color)
{
	if ( (rowCount <= (numCols*10 + numCols)) && initialHidden )
	{
		if( isReady() )     
		{
			int count = 0;    
			if(index >= 0 && index < numCols)
			{           
				if( userGuess.empty() )
					initPegs();                       
				
				for(vector<string>::iterator i = userGuess.begin(); i != userGuess.end(); ++i)
				{
					if(count == index)        
                        *i = color;               
					++count;
				}
				rowCount++;
				
				if( rowCount%numCols == 0 )
				{
					
					rowIsSet = true;
					//setUserGuessRowCount();
				}
				
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
		
	}// end if rowCount
	else 
		printf("Game Over.\n");
	
}  //end setRow
void board::setHidden(int index, string color)
{ 
	
	if( isReady() )     
	{
		int count = 0;    
		if(index >= 0 && index < numCols)
		{           
			if( hiddenCombo.empty() )
                initHidden();                       
			
			for(vector<string>::iterator i = hiddenCombo.begin(); i != hiddenCombo.end(); ++i)
			{
				if(count == index)        
					*i = color;               
				++count;
			}
			
			hiddenIsSet = true;
			
			rowCount++;
		}
		else
		{
			cout << "Error setHidden: else executed.\n";
			system("pause");
			exit(1);
		}   
	} 
	else
		printf("Error setRow: Player style, columns, and colors not set.\n");
	
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

void board::setNumPegs(int columns)
{
	if( (columns > 3 && columns <= 10) )
		numCols = columns;
	cols = true;
}

/* ...END of SETTERS */




/* START of GETTERS.... */

int board::getNumColors()
{
    return numColors;
}

int board::getColorIndex(string color)
{
    int count = 0;    
	if( isReady() && !(colors.empty()) )
	{                                               
		for(vector<string>::iterator i = colors.begin(); i != colors.end(); ++i)
		{
			if( *i == color )
				return count; 
			else       
				++count;
		}
	}
	else
		return -1;     
}

string board::getColorName(int x)
{
	return colors[x];       
}

int board::getRowCount()
{
    if( isReady() )
        return rowCunt; //( (rowCount-2)/hiddenCombo.size() )
    else
        return 0;
}
int board::getBlacks()
{
    return black;
}

int board::getWhites() 
{
    
	return (white);    
}

int board::getNumColumns()
{
    if( isReady() )
		return numCols;
    else
		return 0;
}

int board::getState()
{
    return pStyle;    
}
/* ...END of GETTERS. */



/*         STARt of ETC ....        */

void board::copy(board &other)
{
     userGuess = other.userGuess;
}

string board::operator[](int index)
{
        if(index < 0 || index > (userGuess.size()-1))
          throw OUTOFBOUNDS;
        return userGuess[index];    
}

board::board(board &other)
{
     copy(other);                   
}

void board::clear()
{
     userGuess.clear();
}

void board::clearHiddenCombo()
{
     hiddenCombo.clear();
}

void board::hidCombo()
{
     hiddenCombo = userGuess;
}
/*          END of ETC            */
