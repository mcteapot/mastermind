/*
 *  UIBanggerButton.h
 *  UITest001
 *
 *  Created by arjun prakash on 2/17/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef UIBANGERBUTTON
#define UIBANGERBUTTON

#include <iostream>
#include <string>
#include "board.h"
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h" //MAC images
//#include "SDL_ttf/SDL_ttf.h" //MAC  Text
//#include "SDL_mixer/SDL_mixer.h" //MAC Sound
//#include "SDL/SDL_image.h" //WINDOWS
//#include "SDL/SDL_ttf.h" //WINDOWS
//#include "SDL/SDL_mixer.h" //WINDOWS

class UIBanggerButton
{
public:
	UIBanggerButton(int w, int h, SDL_Surface *a0,  
			 SDL_Surface *a1, SDL_Surface *a2, SDL_Surface *a3,
			 SDL_Surface *a4, SDL_Surface *a5, SDL_Surface *a6,
			 SDL_Surface *a7, SDL_Surface *a8, SDL_Surface *a9, SDL_Surface *aDestination);
	 bool handle_events(int aX, int aY, SDL_Event &event, string colorString );
	
	void displayColor(string colorString);
	bool getButtonSet();
	void setButtonSet(bool set);
private:
    //The part of the button sprite sheet that will be shown
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	
	bool buttonSet;
	SDL_Rect box;
	
	SDL_Rect* clip;
	
	SDL_Surface* white0;
	SDL_Surface* red1; 
	SDL_Surface* pink2; 
	SDL_Surface* blue3; 
	SDL_Surface* turk4; 
	SDL_Surface* aqua5; 
	SDL_Surface* green6; 
	SDL_Surface* yellow7; 
	SDL_Surface* orange8;
	SDL_Surface* black9; 
	SDL_Surface* destination;	
	
	
};
#endif //UIBANGERBUTTON