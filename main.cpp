
/* 
 Arjun Prakash
 MasterMind
 */


#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h" //MAC images
//#include "SDL_ttf/SDL_ttf.h" //MAC  Text
//#include "SDL_mixer/SDL_mixer.h" //MAC Sound
//#include "SDL/SDL_image.h" //WINDOWS
//#include "SDL/SDL_ttf.h" //WINDOWS
//#include "SDL/SDL_mixer.h" //WINDOWS

#include "initialize.h"
#include "board.h"
#include "UIButton.h"
#include "PegCourdinates.h"
#include "computer.h"
#include "UIBanggerButton.h"

using namespace std;

//The attributes of the screen
const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The Surfaces that will be used
SDL_Surface *butStartPvPcOver01 = NULL;
SDL_Surface *butStartPcvPOver01 = NULL;
SDL_Surface *butStartPvPOver01 = NULL;
SDL_Surface *SoExitOver = NULL;
SDL_Surface *butOverNu04 = NULL;
SDL_Surface *butOverNu05 = NULL;
SDL_Surface *butOverNu06 = NULL;
SDL_Surface *butOverNu07 = NULL;
SDL_Surface *butOverNu08 = NULL;
SDL_Surface *butOverNu09 = NULL;
SDL_Surface *butOverNu10 = NULL;
SDL_Surface *butOverPg0 = NULL;
SDL_Surface *butOverPg1 = NULL;
SDL_Surface *butOverPg2 = NULL;
SDL_Surface *butOverPg3 = NULL;
SDL_Surface *butOverPg4 = NULL;
SDL_Surface *butOverPg5 = NULL;
SDL_Surface *butOverPg6 = NULL;
SDL_Surface *butOverPg7 = NULL;
SDL_Surface *butOverPg8 = NULL;
SDL_Surface *butOverPg9 = NULL;

SDL_Surface *butQuickStart01 = NULL;
SDL_Surface *butStartOver01 = NULL;
SDL_Surface *butStartUnder01 = NULL;
SDL_Surface *butReturnStart01 = NULL;

SDL_Surface *PExitOver01 = NULL;
SDL_Surface *butQuit01 = NULL;
SDL_Surface *butSetOver01 = NULL;
SDL_Surface *butSetUnder01 = NULL;

SDL_Surface *screenStart = NULL;
SDL_Surface *screenOption = NULL;
SDL_Surface *screenPlay = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *butPgE01 = NULL;
SDL_Surface *butPg0Whit01 = NULL;
SDL_Surface *butPg1Red01 = NULL;
SDL_Surface *butPg2Pink01 = NULL;
SDL_Surface *butPg3Blue01 = NULL;
SDL_Surface *butPg4Turkoise01 = NULL;
SDL_Surface *butPg5Aqua01 = NULL;
SDL_Surface *butPg6Green01 = NULL;
SDL_Surface *butPg7Yellow01 = NULL;
SDL_Surface *butPg8Orange01 = NULL;
SDL_Surface *butPg9Black01 = NULL;

SDL_Surface *LoadingScreen = NULL;
//key and mouse events
SDL_Event event;

//Method Declerations
SDL_Surface *load_image( std::string filename );
SDL_Surface *loadAlpha_image( std::string filename );
SDL_Surface *loadKey_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
bool init();
bool load_files();
void clean_up();
int stringToNum(string i);
string numToString(int i);

//Program start
int main(int argc, char *argv[])
{
	//Init Data
	int quit = 0;
	bool loading = true;
	bool startScreen = true;
	bool optionsScreen = false;
	bool gameScreen = false;
	bool white0, red1, pink2, blue3, turkoise4, aqua5, green6, yellow7, orange8, black9; 
	int j0, j1, j2, j3, j4, j5, j6, j7, j8, j9;
	string str4 = "0000";
	string str5 = "00000";
	string str6 = "000000";
	string str7 = "0000000";
	string str8 = "00000000";
	string str9 = "000000000";
	string str10 = "0000000000";
	int rowCounter;
	
	//Init Classes
	board theBoard;
	PegCourdinates pegsColor;
	PegCourdinates pegsBW;
	computer npc; //William
    //Initialize
    if( init() == false ) {
        return 1;    
    }
    //Load the files
    if( load_files() == false ) {
        return 1;    
    }
	//Creat Buttons
	UIButton startBuPvPc(182, 72, 242, 32, butStartPvPcOver01, screen);
	UIButton startBuPcvP(182, 118, 242, 32, butStartPcvPOver01, screen);
	UIButton startBuPvP(182, 163, 242, 32, butStartPvPOver01, screen);
	UIButton SOExit(182, 547, 62, 24, SoExitOver, screen);
	
	UIButton butNu04(183, 111, 18, 27, butOverNu04, screen);
	UIButton butNu05(220, 111, 18, 27, butOverNu05, screen);
	UIButton butNu06(257, 111, 18, 27, butOverNu06, screen);
	UIButton butNu07(294, 111, 18, 27, butOverNu07, screen);
	UIButton butNu08(329, 111, 18, 27, butOverNu08, screen);
	UIButton butNu09(365, 111, 18, 27, butOverNu09, screen);
	UIButton butNu10(404, 111, 28, 27, butOverNu10, screen);
	
	UIButton butPeg0(181, 271, 43, 43, butOverPg0, screen); //white
	UIButton butPeg1(233, 271, 43, 43, butOverPg1, screen); //red
	UIButton butPeg2(285, 271, 43, 43, butOverPg2, screen); //pink
	UIButton butPeg3(338, 271, 43, 43, butOverPg3, screen); //blue
	UIButton butPeg4(390, 271, 43, 43, butOverPg4, screen); //turquise
	
	UIButton butPeg5(181, 322, 43, 43, butOverPg5, screen); //aqua
	UIButton butPeg6(233, 322, 43, 43, butOverPg6, screen); //green
	UIButton butPeg7(285, 322, 43, 43, butOverPg7, screen); //yellow
	UIButton butPeg8(338, 322, 43, 43, butOverPg8, screen); //orange
	UIButton butPeg9(390, 322, 43, 43, butOverPg9, screen); //black
	
	UIButton butQStart(183, 493, 179, 27, butQuickStart01, screen); 
	UIButton butStart(182, 441, 90, 26, butStartOver01, screen);
	UIButton butReturn(285, 547, 105, 28, butReturnStart01, screen); 
	
	UIButton butSet(360, 71, 55, 26, butSetOver01, screen); 
	UIButton butQuit(360, 491, 70, 30, butQuit01, screen); 
	UIButton PExit(360, 548, 64, 27, PExitOver01, screen);
	
	UIBanggerButton aBanger00(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger01(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger02(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger03(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger04(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger05(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger06(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger07(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger08(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	UIBanggerButton aBanger09(24, 24,butPg0Whit01, butPg1Red01, butPg2Pink01, 
							  butPg3Blue01, butPg4Turkoise01, butPg5Aqua01,
							  butPg6Green01, butPg7Yellow01, butPg8Orange01, 
							  butPg9Black01, screen);
	
	
	//UIButton butPegCol00(
	
	
	//MAIN LOOP//
	while ( !quit ) {
		//INIT LOAD//
		if (loading) {
			//TODO: Master Reset for theBoard
			theBoard.newGame();
			pegsBW.IntPegBW(10, 47, 553, 53);
			cout << "master reset" << endl;
			apply_surface(0, 0, screenStart, screen);
			white0 = red1 = pink2 = blue3 = turkoise4 = aqua5 = green6 = yellow7 = orange8 = black9 = false;
			j0 = j1 = j2=  j3=  j4= j5= j6= j7= j8= j9 = 0;
			rowCounter =0;
			if( SDL_Flip( screen ) == -1 ) {
				return 1;    
			}
			startBuPvPc.setButtonSet(false);
			startBuPcvP.setButtonSet(false);
			startBuPvP.setButtonSet(false);
			
			butNu04.setButtonSet(false);
			butNu05.setButtonSet(false);
			butNu06.setButtonSet(false);
			butNu07.setButtonSet(false);
			butNu08.setButtonSet(false);
			butNu09.setButtonSet(false);
			butNu10.setButtonSet(false);
			
			butPeg0.setButtonSet(false);
			butPeg1.setButtonSet(false);
			butPeg2.setButtonSet(false);
			butPeg3.setButtonSet(false);
			butPeg4.setButtonSet(false);
			
			butPeg5.setButtonSet(false);
			butPeg6.setButtonSet(false);
			butPeg7.setButtonSet(false);
			butPeg8.setButtonSet(false);
			butPeg9.setButtonSet(false);
			
			butQStart.setButtonSet(false);
			butStart.setButtonSet(false);
			butReturn.setButtonSet(false);
			
			butSet.setButtonSet(false);
			butQuit.setButtonSet(false);
			PExit.setButtonSet(false);
			
			loading = false;	
			startScreen = true;
			optionsScreen = false;
			gameScreen = false;
		}//INIT LOAD end
		
		//START SCREEN//
		if (startScreen) {
			// Check for events 
			if( SDL_PollEvent( &event ) ) {
				//Check Button Events
				if(startBuPvPc.handle_events(event)) {
					theBoard.setPlayStyle("pvc");
					cout << "PvPc" << endl;
					startScreen = false;
					optionsScreen = true;
					apply_surface(0, 0, screenOption, screen);
				}
				if(startBuPcvP.handle_events(event)) {
					theBoard.setPlayStyle("cvp");
					cout << "PcvP" << endl;
					startScreen = false;
					optionsScreen = true;
					apply_surface(0, 0, screenOption, screen);
				}
				if(startBuPvP.handle_events(event)) {
					theBoard.setPlayStyle("pvp");
					cout << "PvP" << endl;
					startScreen = false;
					optionsScreen = true;
					apply_surface(0, 0, screenOption, screen);
				}
				if(SOExit.handle_events(event)) {
					quit = true;
				}
				//If a key was pressed
				if( event.type == SDL_KEYDOWN )
				{
					//Set the proper message surface
					switch( event.key.keysym.sym )
					{
						case SDLK_ESCAPE: quit = true; break;	
						default: break; ;
					}
				}
				
				//If the user has Xed out the window
				else if( event.type == SDL_QUIT )
				{
					//Quit the program
					quit = true;
				}
				
				//Flip Screen
				
				if( SDL_Flip( screen ) == -1 ) {
					return 1;    
				}
				if (startScreen) {
					apply_surface(0, 0, screenStart, screen);
				}
				
				
			}
			
		}//START SCREEN end
		
		//OPTION SCREEN//
		if (optionsScreen) {
			if( SDL_PollEvent( &event ) ) {
				//Check Button Events
				
				//Set Row Number
				//cout << theBoard.getNumPegs() << endl;
				if(theBoard.getNumColumns() == 0) {
					if(butNu04.handle_events(event)) {
						cout << "butNu04" << endl;
						theBoard.setNumPegs(4);
					}
					if(butNu05.handle_events(event)) {
						cout << "butNu05" << endl;
						theBoard.setNumPegs(5);
					}
					if(butNu06.handle_events(event)) {
						cout << "butNu06" << endl;
						theBoard.setNumPegs(6);
					}
					if(butNu07.handle_events(event)) {
						cout << "butNu07" << endl;
						theBoard.setNumPegs(7);
					}
					if(butNu08.handle_events(event)) {
						cout << "butNu08" << endl;
						theBoard.setNumPegs(8);
					}
					if(butNu09.handle_events(event)) {
						cout << "butNu09" << endl;
						theBoard.setNumPegs(9);
					}
					if(butNu10.handle_events(event)) {
						cout << "butNu10" << endl;
						theBoard.setNumPegs(10);
					}
				}else {
					switch (theBoard.getNumColumns()) {
						case 4: butNu04.handle_events(event); break;
						case 5: butNu05.handle_events(event); break;
						case 6: butNu06.handle_events(event); break;
						case 7: butNu07.handle_events(event); break;
						case 8: butNu08.handle_events(event); break;
						case 9: butNu09.handle_events(event); break;
						case 10: butNu10.handle_events(event); break;
						default: break;
					}
				}
				for (int i =0; i <theBoard.getNumColors(); i++) {
					cout << theBoard.getColorName(i) << "bitches" << endl;
				}
				//TODO: Get Colors SEt
				//Set Color 
				if (butPeg0.handle_events(event)) {
					if (white0 == false) {
						theBoard.colorChoices("white");
						cout << "white" << endl;
						white0 = true;
					}
				}
				if (butPeg1.handle_events(event)) {
					if (red1 == false) {
						theBoard.colorChoices("red");
						cout << "red" << endl;
						red1 = true;
					}
				}
				if (butPeg2.handle_events(event)) {
					if (pink2 == false) {
						theBoard.colorChoices("pink");
						cout << "pink" << endl;
						pink2 = true;
					}
				}
				if (butPeg3.handle_events(event)) {
					if (blue3 == false) {
						theBoard.colorChoices("blue");
						cout << "blue" << endl;
						blue3 = true;
					}
				}
				if (butPeg4.handle_events(event)) {
					if (turkoise4 == false) {
						theBoard.colorChoices("turquise");
						cout << "turquise" << endl;
						turkoise4 = true;
					}
				}
				if (butPeg5.handle_events(event)) {
					if (aqua5 == false) {
						theBoard.colorChoices("aqua");
						cout << "aqua" << endl;
						aqua5 = true;
					}
				}
				if (butPeg6.handle_events(event)) {
					if (green6 == false) {
						theBoard.colorChoices("green");
						cout << "green" << endl;
						green6 = true;
					}
				}
				if (butPeg7.handle_events(event)) {
					if (yellow7 == false) {
						theBoard.colorChoices("yellow");
						cout << "yellow" << endl;
						yellow7 = true;
					}
				}
				if (butPeg8.handle_events(event)) {
					if (orange8 == false) {
						theBoard.colorChoices("orange");
						cout << "orange" << endl;
						orange8 = true;
					}
				}
				if (butPeg9.handle_events(event)) {
					if (black9 == false) {
						theBoard.colorChoices("black");
						cout << "black" << endl;
						black9 = true;
					}
				}
				//Start 
				if ((theBoard.getNumColumns())&&(theBoard.getNumColors() >= 4 )) {
					apply_surface(181, 441, butStartUnder01, screen);
					if (butStart.handle_events(event)) {
						pegsColor.InitPegColors(theBoard.getNumColumns(), 11, 71, 307, 553, 53);
						gameScreen = true;
						optionsScreen = false;
						npc.set(theBoard.getNumColumns() ,theBoard.getNumColors());
                        for(int i=0; i<theBoard.getNumColumns(); i++){
							cout << theBoard.getNumColumns() << "coloumns" << endl;
							//string hide = numToString(npc.random());
							string hide = theBoard.getColorName(npc.random());
                            //string hide = theBoard.getColorName(npc.random());
							//string hide = numToString(theBoard.random( theBoard.getNumColors()));
							//theBoard.ColorIntString(npc.random());
							//theBoard.setHidden(i, "3");
							theBoard.setHidden(i, hide);
							//pegsColor.getPegColor(10, i) == hide;
							pegsColor.setPegColor(10, i, hide);
							//pegsColor.setPegColor(10, i, "3");
							theBoard.setPlayStyle("pvc");
							
							
						}
						
						apply_surface(0, 0, LoadingScreen, screen);
						if( SDL_Flip( screen ) == -1 ) {
							return 1;    
						}
					}
				}
				//Quick Start TODO: quickstart
				/* 
				 if (butQStart.handle_events(event)) {
				 
				 cout << "set random inits" << endl;
				 pegsColor.InitPegColors(4, 11, 71, 307, 551, 60);
				 gameScreen = true;
				 optionsScreen = false;
				 
				 apply_surface(0, 0, screenPlay, screen);
				 } */
				//Quick Start
				if (butReturn.handle_events(event)) {
					loading = true;
					optionsScreen = false;
					cout << "Return" << endl;
					apply_surface(0, 0, screenStart, screen);
					
				}
				//Exit Button
				if(SOExit.handle_events(event)) {
					quit = true;
				}
				//If a key was pressed
				if( event.type == SDL_KEYDOWN )
				{
					//Set the proper message surface
					switch( event.key.keysym.sym )
					{
						case SDLK_ESCAPE: quit = true; break;	
						default: break; ;
					}
				}
				
				//If the user has Xed out the window
				else if( event.type == SDL_QUIT )
				{
					//Quit the program
					quit = true;
				}
				if( SDL_Flip( screen ) == -1 ) {
					return 1;    
				}
				
				if(optionsScreen) {
					apply_surface(0, 0, screenOption, screen);
				}	
			}	
			
		}//OPTION SCREEN end
		
		//GAME SCREEN//
		if (gameScreen) {
			//PVC Game
			//cout << "Game Screen" << endl;
			if (theBoard.getState() == 2) {
				if( SDL_PollEvent( &event ) ) {
					//Check Button Events
					//End Turn
					//cout << "Game Screen02" << endl;
					butSet.setButtonSet(false);
					apply_surface(361, 71, butSetUnder01, screen);
					
					if (butSet.handle_events(event)) {
						theBoard.setUserGuessRowCount();
						pegsBW.setPegBW(theBoard.getRowCount(), theBoard.getBlacks(), theBoard.getWhites());
						cout << theBoard.getRowCount() << " BLACK:" << theBoard.getBlacks()<<" WHITE:" << theBoard.getWhites();
						j0 = j1 = j2=  j3=  j4= j5= j6= j7= j8= j9 = 0;
						aBanger00.setButtonSet(false);
						aBanger01.setButtonSet(false);
						aBanger02.setButtonSet(false);
						aBanger03.setButtonSet(false);
						aBanger04.setButtonSet(false);
						aBanger05.setButtonSet(false);
						aBanger06.setButtonSet(false);
						aBanger07.setButtonSet(false);
						aBanger08.setButtonSet(false);
						aBanger09.setButtonSet(false);
						
					}
					//theBoard.setRow(rowCounter, "1220");
					//Quit Button
					if(butQuit.handle_events(event)) {
						gameScreen = false;
						loading = true;
					}
					//Exit Button
					if(PExit.handle_events(event)) {
						quit = true;
					}
					
					
					//for (int i=0; i<theBoard.getNumColumns(); i++) {
					//	if(i =0){
					
					
					//}
					
					//}	
					//BOARD SETTINGS
					for (int i=0; i<11; i++) {
						for (int j=0; j<theBoard.getNumColumns(); j++) {
							string checker;
							if (pegsColor.getPegColor(i, j) == "e") {
								checker = "e";
							}
							else {
								checker = pegsColor.getPegColor(i, j);
							}
							if (checker == "e") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPgE01, screen);}
							else if (checker == "white") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg0Whit01, screen);}
							else if (checker == "red") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg1Red01, screen);}
							else if (checker == "pink") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg2Pink01, screen);}
							else if (checker == "blue") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg3Blue01, screen); }
							else if (checker == "turquise") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg4Turkoise01, screen);}
							else if (checker == "aqua") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg5Aqua01, screen);}
							else if (checker == "green") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg6Green01, screen);}
							else if (checker == "yellow") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg7Yellow01, screen);}
							else if (checker == "orange") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg8Orange01, screen);}
							else if (checker == "black") { apply_surface(pegsColor.getPegX(i,j), pegsColor.getPegY(i,j), butPg9Black01, screen); ;}
							else { cout << "noting " << endl;}
							
							
						}
					}
					//cout << theBoard.getColorName(j0) << endl;
					//cout<< theBoard.getNumColumns() << endl;
					//cout<< theBoard.getRowCount() << endl;
					if (theBoard.getNumColumns() ==4) {
						
						if (aBanger00.handle_events(pegsColor.getPegX((theBoard.getRowCount()),0), pegsColor.getPegY((theBoard.getRowCount()),0), event,  (theBoard.getColorName(j0)))) {
							j0++;
							cout << "test00";
							if (j0 == (theBoard.getNumColors())) {
								j0 =0;
							}
							theBoard.setRow(0, theBoard.getColorName(j0));
							pegsColor.setPegColor(theBoard.getRowCount(), 0, theBoard.getColorName(j0));
							
						}
						
						if (aBanger01.handle_events(pegsColor.getPegX((theBoard.getRowCount()),1), pegsColor.getPegY((theBoard.getRowCount()),1), event,  (theBoard.getColorName(j1)))) {
							j1++;
							cout << "test01";
							if (j1 == (theBoard.getNumColors())) {
								j1 =0;
							}
							theBoard.setRow(1, theBoard.getColorName(j1));
							pegsColor.setPegColor(theBoard.getRowCount(), 1,theBoard.getColorName(j1));
						}
						
						if (aBanger02.handle_events(pegsColor.getPegX((theBoard.getRowCount()),2), pegsColor.getPegY((theBoard.getRowCount()),2), event,  (theBoard.getColorName(j2)))) {
							j2++;
							cout << "test03";
							if (j2 == (theBoard.getNumColors())) {
								j2 =0;
							}
							theBoard.setRow(2, theBoard.getColorName(j2));
							pegsColor.setPegColor(theBoard.getRowCount(), 2, theBoard.getColorName(j2));
						}
						
						if (aBanger03.handle_events(pegsColor.getPegX((theBoard.getRowCount()),3), pegsColor.getPegY((theBoard.getRowCount()),3), event,  (theBoard.getColorName(j3)))) {
							j3++;
							cout << "test04";
							if (j3 == (theBoard.getNumColors())) {
								j3 =0;
							}
							theBoard.setRow(3, theBoard.getColorName(j3));
							pegsColor.setPegColor(theBoard.getRowCount(), 3, theBoard.getColorName(j3));
						}
						
					}
					else if (theBoard.getNumColumns() == 5) {
						
						if (aBanger00.handle_events(pegsColor.getPegX((theBoard.getRowCount()),0), pegsColor.getPegY((theBoard.getRowCount()),0), event,  (theBoard.getColorName(j0)))) {
							j0++;
							cout << "test00";
							if (j0 == (theBoard.getNumColors())) {
								j0 =0;
							}
							
						}
						
						if (aBanger01.handle_events(pegsColor.getPegX((theBoard.getRowCount()),1), pegsColor.getPegY((theBoard.getRowCount()),1), event,  (theBoard.getColorName(j1)))) {
							j1++;
							cout << "test01";
							if (j1 == (theBoard.getNumColors())) {
								j1 =0;
							}
						}
						
						if (aBanger02.handle_events(pegsColor.getPegX((theBoard.getRowCount()),2), pegsColor.getPegY((theBoard.getRowCount()),2), event,  (theBoard.getColorName(j2)))) {
							j2++;
							cout << "test03";
							if (j2 == (theBoard.getNumColors())) {
								j2 =0;
							}
						}
						
						if (aBanger03.handle_events(pegsColor.getPegX((theBoard.getRowCount()),3), pegsColor.getPegY((theBoard.getRowCount()),3), event,  (theBoard.getColorName(j3)))) {
							j3++;
							cout << "test04";
							if (j3 == (theBoard.getNumColors())) {
								j3 =0;
							}
						}
						
						if (aBanger04.handle_events(pegsColor.getPegX((theBoard.getRowCount()),4), pegsColor.getPegY((theBoard.getRowCount()),4), event,  (theBoard.getColorName(j4)))) {
							j4++;
							cout << "test04";
							if (j4 == (theBoard.getNumColors())) {
								j4 =0;
							}
						}
						
					}
					else if (theBoard.getNumColumns() == 6) {
						
						if (aBanger00.handle_events(pegsColor.getPegX((theBoard.getRowCount()),0), pegsColor.getPegY((theBoard.getRowCount()),0), event,  (theBoard.getColorName(j0)))) {
							j0++;
							cout << "test00";
							if (j0 == (theBoard.getNumColors())) {
								j0 =0;
							}
							
						}
						
						if (aBanger01.handle_events(pegsColor.getPegX((theBoard.getRowCount()),1), pegsColor.getPegY((theBoard.getRowCount()),1), event,  (theBoard.getColorName(j1)))) {
							j1++;
							cout << "test01";
							if (j1 == (theBoard.getNumColors())) {
								j1 =0;
							}
						}
						
						if (aBanger02.handle_events(pegsColor.getPegX((theBoard.getRowCount()),2), pegsColor.getPegY((theBoard.getRowCount()),2), event,  (theBoard.getColorName(j2)))) {
							j2++;
							cout << "test03";
							if (j2 == (theBoard.getNumColors())) {
								j2 =0;
							}
						}
						
						if (aBanger03.handle_events(pegsColor.getPegX((theBoard.getRowCount()),3), pegsColor.getPegY((theBoard.getRowCount()),3), event,  (theBoard.getColorName(j3)))) {
							j3++;
							cout << "test04";
							if (j3 == (theBoard.getNumColors())) {
								j3 =0;
							}
						}
						
						if (aBanger04.handle_events(pegsColor.getPegX((theBoard.getRowCount()),4), pegsColor.getPegY((theBoard.getRowCount()),4), event,  (theBoard.getColorName(j4)))) {
							j4++;
							cout << "test04";
							if (j4 == (theBoard.getNumColors())) {
								j4 =0;
							}
						}
						if (aBanger05.handle_events(pegsColor.getPegX((theBoard.getRowCount()),5), pegsColor.getPegY((theBoard.getRowCount()),5), event,  (theBoard.getColorName(j5)))) {
							j5++;
							cout << "test04";
							if (j5 == (theBoard.getNumColors())) {
								j5 =0;
							}
						}
						
					} 
					else if (theBoard.getNumColumns() == 7) {
						
						if (aBanger00.handle_events(pegsColor.getPegX((theBoard.getRowCount()),0), pegsColor.getPegY((theBoard.getRowCount()),0), event,  (theBoard.getColorName(j0)))) {
							j0++;
							cout << "test00";
							if (j0 == (theBoard.getNumColors())) {
								j0 =0;
							}
							
						}
						
						if (aBanger01.handle_events(pegsColor.getPegX((theBoard.getRowCount()),1), pegsColor.getPegY((theBoard.getRowCount()),1), event,  (theBoard.getColorName(j1)))) {
							j1++;
							cout << "test01";
							if (j1 == (theBoard.getNumColors())) {
								j1 =0;
							}
						}
						
						if (aBanger02.handle_events(pegsColor.getPegX((theBoard.getRowCount()),2), pegsColor.getPegY((theBoard.getRowCount()),2), event,  (theBoard.getColorName(j2)))) {
							j2++;
							cout << "test03";
							if (j2 == (theBoard.getNumColors())) {
								j2 =0;
							}
						}
						
						if (aBanger03.handle_events(pegsColor.getPegX((theBoard.getRowCount()),3), pegsColor.getPegY((theBoard.getRowCount()),3), event,  (theBoard.getColorName(j3)))) {
							j3++;
							cout << "test04";
							if (j3 == (theBoard.getNumColors())) {
								j3 =0;
							}
						}
						
						if (aBanger04.handle_events(pegsColor.getPegX((theBoard.getRowCount()),4), pegsColor.getPegY((theBoard.getRowCount()),4), event,  (theBoard.getColorName(j4)))) {
							j4++;
							cout << "test04";
							if (j4 == (theBoard.getNumColors())) {
								j4 =0;
							}
						}
						if (aBanger05.handle_events(pegsColor.getPegX((theBoard.getRowCount()),5), pegsColor.getPegY((theBoard.getRowCount()),5), event,  (theBoard.getColorName(j5)))) {
							j5++;
							cout << "test04";
							if (j5 == (theBoard.getNumColors())) {
								j5 =0;
							}
						}
						if (aBanger06.handle_events(pegsColor.getPegX((theBoard.getRowCount()),6), pegsColor.getPegY((theBoard.getRowCount()),6), event,  (theBoard.getColorName(j6)))) {
							j6++;
							cout << "test04";
							if (j6 == (theBoard.getNumColors())) {
								j6 =0;
							}
						}
						
					} 
					else if (theBoard.getNumColumns() == 8) {
						
						if (aBanger00.handle_events(pegsColor.getPegX((theBoard.getRowCount()),0), pegsColor.getPegY((theBoard.getRowCount()),0), event,  (theBoard.getColorName(j0)))) {
							j0++;
							cout << "test00";
							if (j0 == (theBoard.getNumColors())) {
								j0 =0;
							}
							
						}
						
						if (aBanger01.handle_events(pegsColor.getPegX((theBoard.getRowCount()),1), pegsColor.getPegY((theBoard.getRowCount()),1), event,  (theBoard.getColorName(j1)))) {
							j1++;
							cout << "test01";
							if (j1 == (theBoard.getNumColors())) {
								j1 =0;
							}
						}
						
						if (aBanger02.handle_events(pegsColor.getPegX((theBoard.getRowCount()),2), pegsColor.getPegY((theBoard.getRowCount()),2), event,  (theBoard.getColorName(j2)))) {
							j2++;
							cout << "test03";
							if (j2 == (theBoard.getNumColors())) {
								j2 =0;
							}
						}
						
						if (aBanger03.handle_events(pegsColor.getPegX((theBoard.getRowCount()),3), pegsColor.getPegY((theBoard.getRowCount()),3), event,  (theBoard.getColorName(j3)))) {
							j3++;
							cout << "test04";
							if (j3 == (theBoard.getNumColors())) {
								j3 =0;
							}
						}
						
						if (aBanger04.handle_events(pegsColor.getPegX((theBoard.getRowCount()),4), pegsColor.getPegY((theBoard.getRowCount()),4), event,  (theBoard.getColorName(j4)))) {
							j4++;
							cout << "test04";
							if (j4 == (theBoard.getNumColors())) {
								j4 =0;
							}
						}
						if (aBanger05.handle_events(pegsColor.getPegX((theBoard.getRowCount()),5), pegsColor.getPegY((theBoard.getRowCount()),5), event,  (theBoard.getColorName(j5)))) {
							j5++;
							cout << "test04";
							if (j5 == (theBoard.getNumColors())) {
								j5 =0;
							}
						}
						if (aBanger06.handle_events(pegsColor.getPegX((theBoard.getRowCount()),6), pegsColor.getPegY((theBoard.getRowCount()),6), event,  (theBoard.getColorName(j6)))) {
							j6++;
							cout << "test04";
							if (j6 == (theBoard.getNumColors())) {
								j6 =0;
							}
						}
						if (aBanger07.handle_events(pegsColor.getPegX((theBoard.getRowCount()),7), pegsColor.getPegY((theBoard.getRowCount()),7), event,  (theBoard.getColorName(j7)))) {
							j7++;
							cout << "test04";
							if (j7 == (theBoard.getNumColors())) {
								j7 =0;
							}
						}
						
					} 
					else if (theBoard.getNumColumns() == 9) {
						
						if (aBanger00.handle_events(pegsColor.getPegX((theBoard.getRowCount()),0), pegsColor.getPegY((theBoard.getRowCount()),0), event,  (theBoard.getColorName(j0)))) {
							j0++;
							cout << "test00";
							if (j0 == (theBoard.getNumColors())) {
								j0 =0;
							}
							
						}
						
						if (aBanger01.handle_events(pegsColor.getPegX((theBoard.getRowCount()),1), pegsColor.getPegY((theBoard.getRowCount()),1), event,  (theBoard.getColorName(j1)))) {
							j1++;
							cout << "test01";
							if (j1 == (theBoard.getNumColors())) {
								j1 =0;
							}
						}
						
						if (aBanger02.handle_events(pegsColor.getPegX((theBoard.getRowCount()),2), pegsColor.getPegY((theBoard.getRowCount()),2), event,  (theBoard.getColorName(j2)))) {
							j2++;
							cout << "test03";
							if (j2 == (theBoard.getNumColors())) {
								j2 =0;
							}
						}
						
						if (aBanger03.handle_events(pegsColor.getPegX((theBoard.getRowCount()),3), pegsColor.getPegY((theBoard.getRowCount()),3), event,  (theBoard.getColorName(j3)))) {
							j3++;
							cout << "test04";
							if (j3 == (theBoard.getNumColors())) {
								j3 =0;
							}
						}
						
						if (aBanger04.handle_events(pegsColor.getPegX((theBoard.getRowCount()),4), pegsColor.getPegY((theBoard.getRowCount()),4), event,  (theBoard.getColorName(j4)))) {
							j4++;
							cout << "test04";
							if (j4 == (theBoard.getNumColors())) {
								j4 =0;
							}
						}
						if (aBanger05.handle_events(pegsColor.getPegX((theBoard.getRowCount()),5), pegsColor.getPegY((theBoard.getRowCount()),5), event,  (theBoard.getColorName(j5)))) {
							j5++;
							cout << "test04";
							if (j5 == (theBoard.getNumColors())) {
								j5 =0;
							}
						}
						if (aBanger06.handle_events(pegsColor.getPegX((theBoard.getRowCount()),6), pegsColor.getPegY((theBoard.getRowCount()),6), event,  (theBoard.getColorName(j6)))) {
							j6++;
							cout << "test04";
							if (j6 == (theBoard.getNumColors())) {
								j6 =0;
							}
						}
						if (aBanger07.handle_events(pegsColor.getPegX((theBoard.getRowCount()),7), pegsColor.getPegY((theBoard.getRowCount()),7), event,  (theBoard.getColorName(j7)))) {
							j7++;
							cout << "test04";
							if (j7 == (theBoard.getNumColors())) {
								j7 =0;
							}
						}
						if (aBanger08.handle_events(pegsColor.getPegX((theBoard.getRowCount()),8), pegsColor.getPegY((theBoard.getRowCount()),8), event,  (theBoard.getColorName(j8)))) {
							j8++;
							cout << "test04";
							if (j8 == (theBoard.getNumColors())) {
								j8 =0;
							}
						}
						
					} 
					else if (theBoard.getNumColumns() == 10) {
						
						if (aBanger00.handle_events(pegsColor.getPegX((theBoard.getRowCount()),0), pegsColor.getPegY((theBoard.getRowCount()),0), event,  (theBoard.getColorName(j0)))) {
							j0++;
							cout << "test00";
							if (j0 == (theBoard.getNumColors())) {
								j0 =0;
							}
							
						}
						
						if (aBanger01.handle_events(pegsColor.getPegX((theBoard.getRowCount()),1), pegsColor.getPegY((theBoard.getRowCount()),1), event,  (theBoard.getColorName(j1)))) {
							j1++;
							cout << "test01";
							if (j1 == (theBoard.getNumColors())) {
								j1 =0;
							}
						}
						
						if (aBanger02.handle_events(pegsColor.getPegX((theBoard.getRowCount()),2), pegsColor.getPegY((theBoard.getRowCount()),2), event,  (theBoard.getColorName(j2)))) {
							j2++;
							cout << "test03";
							if (j2 == (theBoard.getNumColors())) {
								j2 =0;
							}
						}
						
						if (aBanger03.handle_events(pegsColor.getPegX((theBoard.getRowCount()),3), pegsColor.getPegY((theBoard.getRowCount()),3), event,  (theBoard.getColorName(j3)))) {
							j3++;
							cout << "test04";
							if (j3 == (theBoard.getNumColors())) {
								j3 =0;
							}
						}
						
						if (aBanger04.handle_events(pegsColor.getPegX((theBoard.getRowCount()),4), pegsColor.getPegY((theBoard.getRowCount()),4), event,  (theBoard.getColorName(j4)))) {
							j4++;
							cout << "test04";
							if (j4 == (theBoard.getNumColors())) {
								j4 =0;
							}
						}
						if (aBanger05.handle_events(pegsColor.getPegX((theBoard.getRowCount()),5), pegsColor.getPegY((theBoard.getRowCount()),5), event,  (theBoard.getColorName(j5)))) {
							j5++;
							cout << "test04";
							if (j5 == (theBoard.getNumColors())) {
								j5 =0;
							}
						}
						if (aBanger06.handle_events(pegsColor.getPegX((theBoard.getRowCount()),6), pegsColor.getPegY((theBoard.getRowCount()),6), event,  (theBoard.getColorName(j6)))) {
							j6++;
							cout << "test04";
							if (j6 == (theBoard.getNumColors())) {
								j6 =0;
							}
						}
						if (aBanger07.handle_events(pegsColor.getPegX((theBoard.getRowCount()),7), pegsColor.getPegY((theBoard.getRowCount()),7), event,  (theBoard.getColorName(j7)))) {
							j7++;
							cout << "test04";
							if (j7 == (theBoard.getNumColors())) {
								j7 =0;
							}
						}
						if (aBanger08.handle_events(pegsColor.getPegX((theBoard.getRowCount()),8), pegsColor.getPegY((theBoard.getRowCount()),8), event,  (theBoard.getColorName(j8)))) {
							j8++;
							cout << "test04";
							if (j8 == (theBoard.getNumColors())) {
								j8 =0;
							}
						}
						if (aBanger09.handle_events(pegsColor.getPegX((theBoard.getRowCount()),9), pegsColor.getPegY((theBoard.getRowCount()),9), event,  (theBoard.getColorName(j9)))) {
							j9++;
							cout << "test04";
							if (j9 == (theBoard.getNumColors())) {
								j9 =0;
							}
						}
						
					} 
					//If a key was pressed
					if( event.type == SDL_KEYDOWN )
					{
						//Set the proper message surface
						switch( event.key.keysym.sym )
						{
							case SDLK_ESCAPE: quit = true; break;	
							case SDLK_UP: break;
							case SDLK_DOWN: break;
							case SDLK_LEFT: break;
							case SDLK_RIGHT: break;
							default: break; ;
						}
					}
					
					//If the user has Xed out the window
					else if( event.type == SDL_QUIT )
					{
						//Quit the program
						quit = true;
					}
					if( SDL_Flip( screen ) == -1 ) {
						return 1;    
					}
					
					if(gameScreen) {
						apply_surface(0, 0, screenPlay, screen);
					}	
				}	
			}//PVC Game end
			//PVC Game
			//PVP Game
			if (theBoard.getState() == 1) {
			}//PVP Game end
			//CVP Game
			if (theBoard.getState() == 3) {
			}//CVP Game end
		}//GAME SCREEN end
		
	}//MAIN LOOP end
	
	
	//Clean Up 
	clean_up();
	return(0);
}//End Of Program//


//Load Surface Image
SDL_Surface *load_image( std::string filename ) {
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
	
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
	
    //Load the image using SDL_image
    loadedImage = IMG_Load( filename.c_str() );
	
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
		//Create an Alpha Image
		//optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
	
    //Return the optimized image
    return optimizedImage;
}
//Load Surface Image
SDL_Surface *loadAlpha_image( std::string filename ) {
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
	
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
	
    //Load the image using SDL_image
    loadedImage = IMG_Load( filename.c_str() );
	
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        //optimizedImage = SDL_DisplayFormat( loadedImage );
		//Create an Alpha Image
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
	
    //Return the optimized image
    return optimizedImage;
}

SDL_Surface *loadKey_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
	
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
	
    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
	
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
		
        //Free the old image
        SDL_FreeSurface( loadedImage );
		
        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );
			
            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }
	
    //Return the optimized image
    return optimizedImage;
}

//Apply the Surface
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
	
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

//Init Applicaiton
bool init() {
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "Master Mind", NULL );
    
    //If everything initialized fine
    return true;
}

//Load Files
bool load_files() {
    //Load the image for MAC
    screenStart = load_image("UITest001.app/Contents/Resources/ScreenStart01.png");
	screenOption = load_image("UITest001.app/Contents/Resources/ScreenOptions01.bmp");
	screenPlay = load_image("UITest001.app/Contents/Resources/ScreenPlay01.png");
	
    butStartPvPcOver01 = load_image("UITest001.app/Contents/Resources/startBuPvPcOver01.png");
	butStartPcvPOver01 = load_image("UITest001.app/Contents/Resources/startBuPcvPOver01.png");
	butStartPvPOver01 = load_image("UITest001.app/Contents/Resources/startBuPvPOver01.png");
	SoExitOver = load_image("UITest001.app/Contents/Resources/SOExitOver01.png");
	
	butOverNu04 = load_image("UITest001.app/Contents/Resources/optBu4.png");
	butOverNu05 = load_image("UITest001.app/Contents/Resources/optBu5.png");
	butOverNu06 = load_image("UITest001.app/Contents/Resources/optBu6.png");
	butOverNu07 = load_image("UITest001.app/Contents/Resources/optBu7.png");
	butOverNu08 = load_image("UITest001.app/Contents/Resources/optBu8.png");
	butOverNu09 = load_image("UITest001.app/Contents/Resources/optBu9.png");
	butOverNu10 = load_image("UITest001.app/Contents/Resources/optBu10.png");
	
	butOverPg0 = load_image("UITest001.app/Contents/Resources/optBuPe0.png");
	butOverPg1 = load_image("UITest001.app/Contents/Resources/optBuPe1.png");
	butOverPg2 = load_image("UITest001.app/Contents/Resources/optBuPe2.png");
	butOverPg3 = load_image("UITest001.app/Contents/Resources/optBuPe3.png");
	butOverPg4 = load_image("UITest001.app/Contents/Resources/optBuPe4.png");
	butOverPg5 = load_image("UITest001.app/Contents/Resources/optBuPe5.png");
	butOverPg6 = load_image("UITest001.app/Contents/Resources/optBuPe6.png");
	butOverPg7 = load_image("UITest001.app/Contents/Resources/optBuPe7.png");
	butOverPg8 = load_image("UITest001.app/Contents/Resources/optBuPe8.png");
	butOverPg9 = load_image("UITest001.app/Contents/Resources/optBuPe9.png");
	
	PExitOver01 = load_image("UITest001.app/Contents/Resources/PExitOver01.png");
	butQuit01 = load_image("UITest001.app/Contents/Resources/plBuQuit01.png");
	butSetOver01 = load_image("UITest001.app/Contents/Resources/plBuSetOv01.png");
	butSetUnder01 = load_image("UITest001.app/Contents/Resources/plBuSetUn01.png");
	
	butQuickStart01 = load_image("UITest001.app/Contents/Resources/optBuQstart01.png");
	butStartOver01 = load_image("UITest001.app/Contents/Resources/optBuStartOv01.png");
	butStartUnder01 = load_image("UITest001.app/Contents/Resources/optBuStartUn01.png");
	butReturnStart01 = load_image("UITest001.app/Contents/Resources/optBuReturn01.png");
	
	butPgE01 = load_image("UITest001.app/Contents/Resources/plPEEMPTpg01.png");
	butPg0Whit01 = load_image("UITest001.app/Contents/Resources/plPG0Whit01.png");
	butPg1Red01 = load_image("UITest001.app/Contents/Resources/plPG1Red01.png");
	butPg2Pink01 = load_image("UITest001.app/Contents/Resources/plPG2Pink01.png");
	butPg3Blue01 = load_image("UITest001.app/Contents/Resources/plPG3Blue01.png");
	butPg4Turkoise01 = load_image("UITest001.app/Contents/Resources/plPG4Turquise01.png");
	butPg5Aqua01 = load_image("UITest001.app/Contents/Resources/plPG5Aqua01.png");
	butPg6Green01 = load_image("UITest001.app/Contents/Resources/plPG6Green01.png");
	butPg7Yellow01 = load_image("UITest001.app/Contents/Resources/plPG7Yellow01.png");
	butPg8Orange01 = load_image("UITest001.app/Contents/Resources/plPG8Orange01.png");
	butPg9Black01 = load_image("UITest001.app/Contents/Resources/plPG9Black01.png");
	
	LoadingScreen = load_image("UITest001.app/Contents/Resources/LoadingPlayer01.png");
	
	//SDL_DisplayFormatAlpha (butPgE01, SDL_SRCALPHA, alpha);
	
	//Load the images WINDOWS
	/* 
	 screenStart = load_image("ScreenStart01.png");
	 screenOption = load_image("ScreenOptions01.bmp");
	 screenPlay = load_image("ScreenPlay01.png");
	 
	 butStartPvPcOver01 = load_image("startBuPvPcOver01.png");
	 butStartPcvPOver01 = load_image("startBuPcvPOver01.png");
	 butStartPvPOver01 = load_image("startBuPvPOver01.png");
	 SoExitOver = load_image("SOExitOver01.png");
	 
	 butOverNu04 = load_image("optBu4.png");
	 butOverNu05 = load_image("optBu5.png");
	 butOverNu06 = load_image("optBu6.png");
	 butOverNu07 = load_image("optBu7.png");
	 butOverNu08 = load_image("optBu8.png");
	 butOverNu09 = load_image("optBu9.png");
	 butOverNu10 = load_image("optBu10.png");
	 
	 butOverPg0 = load_image("optBuPe0.png");
	 butOverPg1 = load_image("optBuPe1.png");
	 butOverPg2 = load_image("optBuPe2.png");
	 butOverPg3 = load_image("optBuPe3.png");
	 butOverPg4 = load_image("optBuPe4.png");
	 butOverPg5 = load_image("optBuPe5.png");
	 butOverPg6 = load_image("optBuPe6.png");
	 butOverPg7 = load_image("optBuPe7.png");
	 butOverPg8 = load_image("optBuPe8.png");
	 butOverPg9 = load_image("optBuPe9.png");
	 
	 PExitOver01 = load_image("PExitOver01.png");
	 butQuit01 = load_image("plBuQuit01.png");
	 butSetOver01 = load_image("plBuSetOv01.png");
	 butSetUnder01 = load_image("plBuSetUn01.png");
	 
	 butQuickStart01 = load_image("optBuQstart01.png");
	 butStartOver01 = load_image("optBuStartOv01.png");
	 butStartUnder01 = load_image("optBuStartUn01.png");
	 butReturnStart01 = load_image("optBuReturn01.png");
	 
	 butPgE01 = load_image("plPEEMPTpg01.png");
	 butPg0Whit01 = load_image("plPG0Whit01.png");
	 butPg1Red01 = load_image("plPG1Red01.png");
	 butPg2Pink01 = load_image("plPG2Pink01.png");
	 butPg3Blue01 = load_image("plPG3Blue01.png");
	 butPg4Turkoise01 = load_image("plPG4Turquise01.png");
	 butPg5Aqua01 = load_image("plPG5Aqua01.png");
	 butPg6Green01 = load_image("plPG6Green01.png");
	 butPg7Yellow01 = load_image("plPG7Yellow01.png");
	 butPg8Orange01 = load_image("plPG8Orange01.png");
	 butPg9Black01 = load_image("plPG9Black01.png");
 	 */
	//If there was an error in loading the image
    if( screenStart == NULL )
    {
        return false;    
    }
    
    //If everything loaded fine
    return true;    
}

void clean_up() {
    //Free the image
	SDL_FreeSurface( screenStart );
	SDL_FreeSurface( screenOption );
	SDL_FreeSurface( screenPlay );
	
	SDL_FreeSurface( butStartPvPcOver01 );
	SDL_FreeSurface( butStartPcvPOver01 );
	SDL_FreeSurface( butStartPvPOver01 );
	SDL_FreeSurface( SoExitOver );
	
	SDL_FreeSurface( butOverNu04 );
	SDL_FreeSurface( butOverNu05 );
	SDL_FreeSurface( butOverNu06 );
	SDL_FreeSurface( butOverNu07 );
	SDL_FreeSurface( butOverNu08 );
	SDL_FreeSurface( butOverNu09 );
	SDL_FreeSurface( butOverNu10 );
	
	SDL_FreeSurface( butOverPg0 );
	SDL_FreeSurface( butOverPg1 );
	SDL_FreeSurface( butOverPg2 );
	SDL_FreeSurface( butOverPg3 );
	SDL_FreeSurface( butOverPg4 );
	SDL_FreeSurface( butOverPg5 );
	SDL_FreeSurface( butOverPg6 );
	SDL_FreeSurface( butOverPg7 );
	SDL_FreeSurface( butOverPg8 );
	SDL_FreeSurface( butOverPg9 );
	
	SDL_FreeSurface( PExitOver01 );
	SDL_FreeSurface( butQuit01 );
	SDL_FreeSurface( butSetOver01 );
	SDL_FreeSurface( butSetUnder01 );
	
	SDL_FreeSurface( butQuickStart01 );
	SDL_FreeSurface( butStartOver01 );
	SDL_FreeSurface( butStartUnder01 );
	SDL_FreeSurface( butReturnStart01 );
	
	SDL_FreeSurface( butPgE01 );
	SDL_FreeSurface( butPg0Whit01 );
	SDL_FreeSurface( butPg1Red01 );
	SDL_FreeSurface( butPg2Pink01 );
	SDL_FreeSurface( butPg3Blue01 );
	SDL_FreeSurface( butPg4Turkoise01 );
	SDL_FreeSurface( butPg5Aqua01 );
	SDL_FreeSurface( butPg6Green01 );
	SDL_FreeSurface( butPg7Yellow01 );
	SDL_FreeSurface( butPg8Orange01 );
	SDL_FreeSurface( butPg9Black01 );
	
	SDL_FreeSurface(LoadingScreen);
	
    //Quit SDL
    SDL_Quit();    
}

int stringToNum(string i) {
	int num;
	
	if (i == "0") { num =0;}
	else if (i == "1") { num =1;}
	else if (i == "2") { num =2;}
	else if (i == "3") { num =3;}
	else if (i == "4") { num =4;}
	else if (i == "5") { num =5;}
	else if (i == "6") { num =6;}
	else if (i == "7") { num =7;}
	else if (i == "8") { num =8;}
	else if (i == "9") { num =9;}
	else {num =-1;}
	return num;
}
string numToString(int i) {
	string num;
	
	if (i == 0) { num ="0";}
	else if (i == 1) { num ="1";}
	else if (i == 2) { num ="2";}
	else if (i ==3) { num ="3";}
	else if (i == 4) { num ="4";}
	else if (i == 5) { num ="5";}
	else if (i == 6) { num ="6";}
	else if (i == 7) { num ="7";}
	else if (i == 8) { num ="8";}
	else if (i == 9) { num ="9";}
	else {num =-1;}
	return num;
}
