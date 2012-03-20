/*
 *  UIButton.cpp
 *  UITest001
 *
 *  Created by arjun prakash on 2/14/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "UIButton.h"

UIButton::UIButton(int x, int y, int w, int h, 	SDL_Surface *aSource,  SDL_Surface *aDestination) {
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
	source = aSource; 
	destination = aDestination;
	buttonSet = false;

}

bool UIButton::getButtonSet() {
	return buttonSet;
}
void UIButton::setButtonSet(bool set) {
	buttonSet = set;
}
bool UIButton::handle_events(SDL_Event &event) {
		int x = 0, y = 0;
    //The mouse offsets
	if (!buttonSet) {

		
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
				apply_surface(box.x, box.y, source, destination);
				return false;
			}
			//If not
			else
			{
				//Set the button sprite
				//apply_surface(box.x, box.y, source, destination);
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
					apply_surface(box.x, box.y, source, destination);
					return false;
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
					apply_surface(box.x, box.y, source, destination);
					return true;
					buttonSet = true;
				}
			}
		}
		return false;
	}
	else {
		apply_surface(box.x, box.y, source, destination);
		return true;
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
					apply_surface(box.x, box.y, source, destination);
					return true;
					buttonSet = false;
				}
			}
		}	
	}

}



void UIButton::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination) {
    //Holds offsets
    SDL_Rect offset;
	
    //Get offsets
    offset.x = x;
    offset.y = y;
	
    //Blit
    SDL_BlitSurface( source, NULL, destination, &offset );
}