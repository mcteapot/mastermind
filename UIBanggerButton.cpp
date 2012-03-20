/*
 *  UIBanggerButton.cpp
 *  UITest001
 *
 *  Created by arjun prakash on 2/17/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "UIBanggerButton.h"

UIBanggerButton::UIBanggerButton(int w, int h, SDL_Surface *a0,  
				SDL_Surface *a1, SDL_Surface *a2, SDL_Surface *a3,
				SDL_Surface *a4, SDL_Surface *a5, SDL_Surface *a6,
				SDL_Surface *a7, SDL_Surface *a8, SDL_Surface *a9, SDL_Surface *aDestination) {

    box.w = w;
    box.h = h;
	destination = aDestination;
	buttonSet = false;
	white0 = a0;
	red1 = a1; 
	pink2 = a2; 
	blue3 = a3;
	turk4 = a4;
	aqua5 = a5; 
	green6 = a6; 
	yellow7 = a7; 
	orange8 = a8;
	black9 = a9;
}

bool UIBanggerButton::getButtonSet() {
	return buttonSet;
}
void UIBanggerButton::setButtonSet(bool set) {
	buttonSet = set;
}

bool UIBanggerButton::handle_events(int aX, int aY, SDL_Event &event, string colorString ) {
	box.x = aX;
    box.y = aY;
		int x = 0, y = 0;
	//If the mouse moved
	if( event.type == SDL_MOUSEMOTION )
	{
		//Get the mouse offsets
		x = event.motion.x;
		y = event.motion.y;
		
		//If the mouse is over the button
		if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
		{
			//Set the button sprite
			//apply_surface(box.x, box.y, source, destination);
			if (buttonSet) {
				displayColor(colorString);
			}
			return false;
		}
		//If not
		else
		{
			//Set the button sprite
			//apply_surface(box.x, box.y, source, destination);
			if (buttonSet) {
				displayColor(colorString);
			}
			return false;
		}
	}
	//If a mouse button was pressed
	if( event.type == SDL_MOUSEBUTTONDOWN )
	{
		//If the left mouse button was pressed
		if( event.button.button == SDL_BUTTON_LEFT )
		{
			//Get the mouse offsets
			x = event.button.x;
			y = event.button.y;
			
			//If the mouse is over the button
			if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
			{
				//Set the button sprite
				if (buttonSet) {
					displayColor(colorString);
				}			
				buttonSet = true;
				
				return true;
			}
		}
	}
	//If a mouse button was released
	if( event.type == SDL_MOUSEBUTTONUP )
	{
		//If the left mouse button was released
		if( event.button.button == SDL_BUTTON_LEFT )
		{
			//Get the mouse offsets
			x = event.button.x;
			y = event.button.y;
			
			//If the mouse is over the button
			if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
			{
				//Set the button sprite
				if (buttonSet) {
					displayColor(colorString);
				}	
	
				cout << "WTF" << endl;
				return false;
				
			}
		}
	}
	if (buttonSet) {
		displayColor(colorString);
	}	
	return false;	

}

void UIBanggerButton::displayColor(string colorString){

	if (colorString == "white") { apply_surface(box.x, box.y, white0, destination);}
	else if (colorString == "red") { apply_surface(box.x, box.y, red1, destination);}
	else if (colorString == "pink") { apply_surface(box.x, box.y, pink2, destination);}
	else if (colorString == "blue") { apply_surface(box.x, box.y, blue3, destination); }
	else if (colorString == "turquise") { apply_surface(box.x, box.y, turk4, destination);}
	else if (colorString == "aqua") { apply_surface(box.x, box.y, aqua5, destination);}
	else if (colorString == "green") { apply_surface(box.x, box.y, green6, destination);}
	else if (colorString == "yellow") { apply_surface(box.x, box.y, yellow7, destination);}
	else if (colorString == "orange") { apply_surface(box.x, box.y, orange8, destination);}
	else if (colorString == "black") { apply_surface(box.x, box.y, black9, destination);}
	else { cout << "fuck C++ " << endl;}
	
	
}

void UIBanggerButton::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination) {
    //Holds offsets
    SDL_Rect offset;
	
    //Get offsets
    offset.x = x;
    offset.y = y;
	
    //Blit
    SDL_BlitSurface( source, NULL, destination, &offset );
}
