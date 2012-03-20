/*
 *  PegCourdinates.h
 *  BoardVector
 *
 *  Created by arjun prakash on 2/16/11.
 *  Copyright 2011 bellmonde. All rights reserved.
 *
 */

#ifndef PEGCOURDINATES
#define PEGCOURDINATES



#include <vector>
#include <iostream>

using namespace std;

typedef unsigned short USHORT;
typedef struct PegCord
{
	USHORT x;
	USHORT y;
	string color;
	int black;
	int white;
	PegCord()
	{
		x = 0;
		y = 0;
		color = "e";
		black = 0;
		white = 0;
	}
	PegCord(int aX, int aY)
	{
		x = aX;
		y = aY;
		
	}
	PegCord(string aColor)
	{
		color = aColor;
		
	}
} PEGCORD;

class PegCourdinates
{
public:
	PegCourdinates();
	~PegCourdinates();
	void CreatePeg();
	void AddPeg(int setX, int setY);
	void AddPegColor(string setColor);
	PEGCORD getPeg(int i);
	int getPegX(int ai, int aj);
	int getPegY(int ai, int aj);
	int getPegBWX(int ai);
	int getPegBWY(int ai);
	string getPegColor(int ai, int aj);
	void setPegColor(int ai, int aj, string color);
	void setPegBW(int ai, int bl, int wh);
	int getPegB(int ai); 
	int getPegW(int ai); 
	void InitPegColors(int setColumns, int setRows, int startX, int endX,int yStart, int ySpace);
	void IntPegBW(int setRows,int theX, int yStart, int ySpace);
private:
	vector<PEGCORD> pegcord;
	int columns;
	int rows;
	int xSpacing;
	int ySpacing;
};


#endif //PEGCOURDINATES
