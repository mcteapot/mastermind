/*
 *  PegCourdinates.cpp
 *  BoardVector
 *
 *  Created by arjun prakash on 2/16/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#include "PegCourdinates.h"

PegCourdinates::PegCourdinates() {}
PegCourdinates::~PegCourdinates() {}

void PegCourdinates::CreatePeg() {
	pegcord.push_back(PegCord());
}

void PegCourdinates::AddPeg(int setX, int setY) {
	pegcord.push_back(PegCord(setX, setY));
}

void PegCourdinates::AddPegColor(string setColor) {
	pegcord.push_back(PegCord(setColor));
}

PEGCORD PegCourdinates::getPeg(int i) {
	return pegcord[i];
}

int PegCourdinates::getPegX(int ai, int aj) {
	//cout << ai * columns << endl;
	//cout << (ai * columns) + aj << endl;
	return getPeg(((ai * columns) + aj)).x;
	
}

int PegCourdinates::getPegY(int ai, int aj) {
	return getPeg(((ai * columns) + aj)).y;
	
}
int PegCourdinates::getPegBWX(int ai) {
	return getPeg(ai).x;
}
int PegCourdinates::getPegBWY(int ai){
	return getPeg(ai).y;
}

string PegCourdinates::getPegColor(int ai, int aj) {
	return getPeg(((ai * columns) + aj)).color;
}

void PegCourdinates::setPegColor(int ai, int aj, string color) {
	pegcord[((ai * columns) + aj)].color = color;
}
void PegCourdinates::setPegBW(int ai, int bl, int wh) {
	pegcord[ai].black = bl;
	pegcord[ai].white = wh;
}
int PegCourdinates::getPegB(int ai) {
	return pegcord[ai].black;
}
int PegCourdinates::getPegW(int ai) {
	return pegcord[ai].white;
}
void PegCourdinates::InitPegColors(int setColumns, int setRows, int startX, int endX,int yStart, int ySpace){
	columns = setColumns;
	rows = setRows;
	xSpacing = (endX - startX)/columns;
	ySpacing = yStart;
	pegcord.clear();
	//Loop to init all the rows
	for (int i=0; i < rows; i++) {
		int xAdding = startX; 
		if (i!=0) {
			ySpacing -= ySpace;
		}
		for (int j=0; j < columns; j++) {
			//CreatePeg();
			if (j==0) {
				//xAdding = xSpacing/2;
				AddPeg(startX, ySpacing);
				cout << "Spot i:" << i << " j:" << j << " (x:"<< xAdding << " y:" << ySpacing << ") ";
			}
			else {
				xAdding += xSpacing; 
				AddPeg(xAdding, ySpacing);
				cout << "Spot i:" << i << " j:" << j << " (x:"<< xAdding << " y:" << ySpacing << ") ";
			}
			
			setPegColor(i , j, "e");	
		}
		cout << endl;
	}
}

void PegCourdinates::IntPegBW(int setRows,int theX, int yStart, int ySpace) {
	rows = setRows;
	ySpacing = yStart;
	pegcord.clear();
	for (int i =0; i<rows; i++) {
		if (i==0) {
			AddPeg(theX, ySpacing);
			
		}
		else {
			ySpacing -= ySpace;
			AddPeg(theX, ySpacing);
		}
			setPegBW(i, 0, 0);
	}


}
