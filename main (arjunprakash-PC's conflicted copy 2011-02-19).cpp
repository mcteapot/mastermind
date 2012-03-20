
/* 
 Arjun Prakash
 MasterMind
*/
   

#include <iostream>
#include <string>
#include "SDL/SDL.h"
//#include "SDL/SDL_image.h" //WINDOWS
#include "SDL_image/SDL_image.h" //MAC
//#include "SDL/SDL_ttf.h" //WINDOWS
#include "SDL_ttf/SDL_ttf.h" //MAC
//#include "SDL/SDL_mixer.h" //WINDOWS
#include "SDL_mixer/SDL_mixer.h" //MAC

#include "initialize.h"
#include "board.h"
#include "UIButton.h"

using namespace std;

//The attributes of the screen
const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The Surfaces that will be used
SDL_Surface *butStartPvPcOver = NULL;
SDL_Surface *butStartPcvPOver = NULL;
SDL_Surface *butStartPvPOver = NULL;
SDL_Surface *SoExitOver = NULL;
SDL_Surface *screenStart = NULL;
SDL_Surface *screenOption = NULL;
SDL_Surface *screen = NULL;

//key and mouse events
SDL_Event event;

//Method Declerations
SDL_Surface *load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
bool init();
bool load_files();
void clean_up();

int main(int argc, char *argv[])
{
	//Init Data
	int quit = 0;
	bool loading = true;
	bool startScreen = true;
	bool optionsScreen = false;
	bool gameScreen = false;
	//Init Classes
	board theBoard;

    //Initialize
    if( init() == false ) {
        return 1;    
    }
    //Load the files
    if( load_files() == false ) {
        return 1;    
    }
	//Creat Buttons
	UIButton startBuPvPc(180, 72, 242, 32, butStartPvPcOver, screen);
	UIButton startBuPcvP(180, 157, 242, 32, butStartPcvPOver, screen);
	UIButton startBuPvP(180, 218, 242, 32, butStartPvPOver, screen);
	UIButton SOExit(244, 730, 80, 37, SoExitOver, screen);
	
	//MAIN LOOP//
	while ( !quit ) {
		//INIT LOAD//
		if (loading) {
			apply_surface(0, 0, screenStart, screen);
			if( SDL_Flip( screen ) == -1 ) {
				return 1;    
			}
			startBuPvPc.setButtonSet(false);
			startBuPcvP.setButtonSet(false);
			startBuPvP.setButtonSet(false);
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
						case SDLK_UP: break;
						case SDLK_DOWN: break;
						case SDLK_LEFT: break;
						case SDLK_RIGHT: break;
						default : ;
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
						case SDLK_UP: break;
						case SDLK_DOWN: break;
						case SDLK_LEFT: break;
						case SDLK_RIGHT: break;
						default : ;
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
	}
	//GAME SCREEN//
	if (gameScreen) {
		if( SDL_PollEvent( &event ) ) {
			//Check Button Events
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
					case SDLK_UP: break;
					case SDLK_DOWN: break;
					case SDLK_LEFT: break;
					case SDLK_RIGHT: break;
					default : ;
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
				apply_surface(0, 0, screenOption, screen);
			}	
		}	
		
	}//GAME SCREEN end

	//Clean Up 
	clean_up();
	return(0);
}//MAIN LOOP end


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
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
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
    butStartPvPcOver = load_image("UITest001.app/Contents/Resources/startBuPvPcOver01.png");
	butStartPcvPOver = load_image("UITest001.app/Contents/Resources/startBuPcvPOver01.png");
	butStartPvPOver = load_image("UITest001.app/Contents/Resources/startBuPvPOver01.png");
	SoExitOver = load_image("UITest001.app/Contents/Resources/SOExitOver01.png");
	/* Load the images WINDOWS
	screenStart = load_image("ScreenStart01.png");
	screenOption = load_image("ScreenOptions01.bmp");
    butStartPvPcOver = load_image("startBuPvPcOver01.png");
	butStartPcvPOver = load_image("startBuPcvPOver01.png");
	butStartPvPOver = load_image("startBuPvPOver01.png");
	SoExitOver = load_image("SOExitOver01.png");
    //If there was an error in loading the image
	 */
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
    
    //Quit SDL
    SDL_Quit();    
}
