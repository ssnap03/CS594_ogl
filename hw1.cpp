/*****************************
*	Author: Anirudh Nistala	 *	
*   Roll No.: B16091         *
*                            *
*****************************/

#include <bits/stdc++.h>
#include "EasyBMP.h"


using namespace std;

void drawLine_x(int x1, int y1, int x2, int y2, char*fileNameToSaveBitmap)
{
	typedef vector<pair<int,int> > tup_vec;
	
	tup_vec plot_coords;

	int dx = x2-x1;
	int dy = y2-y1;

	int y_0 = 1;

	if(dy<0)
	{
		y_0 = -1;
		dy = -dy;
	}	

	int p = 2*dy - dx;
	int y = y1;

	for(int x = x1; x <= x2; x++)
	{
		plot_coords.push_back(make_pair(x,y));//plot(x,y)
		
		if(p>0)
		{
			y= y + y_0;
			p = p - 2*dx;
		}
		p = p + 2*dy;
	}	

	BMP bm;
	bm.SetSize(200,200);

	for(tup_vec::iterator it = plot_coords.begin(); it!=plot_coords.end(); ++it)
	{
		int x_coord = it->first;
		int y_coord = it->second;

		//cout<<"("<<x_coord<<","<<y_coord<<")"<<endl;
		bm(x_coord,y_coord)->Red = 100;
		bm(x_coord,y_coord)->Blue = 100;
		bm(x_coord,y_coord)->Green = 100;
	}

	bm.WriteToFile(fileNameToSaveBitmap);
}

void drawLine_y(int x1, int y1, int x2, int y2, char*fileNameToSaveBitmap)
{
	typedef vector<pair<int,int> > tup_vec;
	
	tup_vec plot_coords;

	int dx = x2-x1;
	int dy = y2-y1;

	int x_0 = 1;

	if(dx<0)
	{
		x_0 = -1;
		dx = -dx;
	}	

	int p = 2*dx - dy;
	int x = x1;

	for(int y = y1; y <= y2; y++)
	{
		plot_coords.push_back(make_pair(x,y));//plot(x,y)
		
		if(p>0)
		{
			x = x + x_0;
			p = p - 2*dy;
		}
		p = p + 2*dx;
	}	

	BMP bm;
	bm.SetSize(200,200);

	for(tup_vec::iterator it = plot_coords.begin(); it!=plot_coords.end(); ++it)
	{
		int x_coord = it->first;
		int y_coord = it->second;

		//cout<<"("<<x_coord<<","<<y_coord<<")"<<endl;
		bm(x_coord,y_coord)->Red = 100;
		bm(x_coord,y_coord)->Blue = 100;
		bm(x_coord,y_coord)->Green = 100;
	}

	bm.WriteToFile(fileNameToSaveBitmap);	
}

void drawLine(int x1, int y1, int x2, int y2, char *fileNameToSaveBitmap)
{
/* your code which draws a line from (x1,y1) to (x2, y2) */

	if(abs(y2 - y1) < abs(x2 - x1))
    {
        if(x1 > x2)
            drawLine_x(x2, y2, x1, y1, fileNameToSaveBitmap);
        else
            drawLine_x(x1, y1, x2, y2, fileNameToSaveBitmap);
    }
    else
    {
        if(y1 > y2)
            drawLine_y(x2, y2, x1, y1, fileNameToSaveBitmap);
        else
            drawLine_y(x1, y1, x2, y2, fileNameToSaveBitmap);
    }
    
}

int main()
{
	drawLine(10, 10, 50, 60, "one.bmp");
	drawLine(10, 50, 60, 10, "two.bmp");
	drawLine(90, 100, 10, 20, "three.bmp");
	drawLine(90, 10, 30, 70, "four.bmp");
	drawLine(10, 10, 10, 90, "five.bmp");
}