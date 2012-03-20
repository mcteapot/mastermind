/*
 *  UIButton.h
 *  UITest001
 *
 *  Created by arjun prakash on 2/14/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef UIBUTTON
#define UIBUTTON

#include <iostream>
#include <string>
#include "SDL/SDL.h"
//#include "SDL/SDL_image.h" //WINDOWS
#include "SDL_image/SDL_image.h" //MAC
//#include "SDL/SDL_ttf.h" //WINDOWS
#include "SDL_ttf/SDL_ttf.h" //MAC
//#include "SDL/SDL_mixer.h" //WINDOWS
#include "SDL_mixer/SDL_mixer.h" //MAC

using namespace std;


class UIButton
{
public:
	UIButton(int x, int y, int w, int h, 	SDL_Surface *aSource,  SDL_Surface *aDestination);
	
	//Handles events and set the button's sprite region
    bool handle_events(SDL_Event &event);
	
    //Shows the button on the screen
    //void show();
	bool getButtonSet();
	void setButtonSet(bool set);
	
private:
	
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
    //The attributes of the button
    SDL_Rect box;
	bool buttonSet;
    //The part of the button sprite sheet that will be shown
    SDL_Rect* clip;
	SDL_Surface* source; 
	SDL_Surface* destination;
};




#endif //UIBUTTON