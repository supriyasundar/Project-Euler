/*
 * Author:Supriya Sundar
 * Class:ECE 6122
 * Last Date Modified: 25-9-2021
 * Description: Langton's ant problem was implemented succesfully.
 */
#include<iostream>
#include<fstream>
#include<utility>
#include<string>
#include<set>
#include<bits/stdc++.h>
using namespace std;
int numberOfSquares(signed long numberOfMoves)
{
    int color=0,newDirection=4;
    /* assuming color as binary - 0 as white and 1 as black;
    *assuming integers as directions with 1 as up, 2 as down, 3 as left and 4 as right.*/    
    int xcoord,ycoord;  // position of ant in terms of x and y coordinates is taken as integers
    unsigned long int counter=0;  // counter variable used for incrementation to count number of black squares
    unordered_map<string,int>grid;  // unordered map holds the coordinate positions of ant and color of square it occupies as the key and value
    string position=to_string(xcoord)+" "+to_string(ycoord);
    for(int numberOfSquares=1;numberOfSquares>0;numberOfSquares--) // looping through the grid square by square
    {
        position=to_string(xcoord)+" "+to_string(ycoord); // converting integer coordinates to string
        auto element = grid.find(position); // finding coordinates in the map 
        switch(newDirection)
    	{
        case 1:
	    if(color==0)
            { 
                grid[position]=1; // square is changed to black
                newDirection=4; // move right
                xcoord+=1;
            }
	    else if(color==1)
	    {
	        grid[position]=0;
		newDirection=3;
		xcoord-=1;
	    }
	    break;
	case 2:
	    if(color==0)
	    {
	        grid[position]=1;
		newDirection=3;
		xcoord-=1;
	    }
	    else if(color==1)
	    {
		grid[position]=0;
		newDirection=4;
		xcoord+=1;
	    }
	    break;
	case 3:
	    if(color==0)
	    {
		grid[position]=1;
		newDirection=1;
		ycoord+=1;
	    }
	    else if(color==1)
	    {
		grid[position]=0;
		newDirection=2;
		ycoord-=1;
	    }
	    break;
	case 4:
	    if(color==0)
	    {
		grid[position]=1;
		newDirection=2;
		ycoord-=1;
	    }
	    else if(color==1)
	    {
		grid[position]=0;
		newDirection=1;
		ycoord+=1;
	    }
	    break; // each case demonstrates the next step to be taken
	}
    }
    for(auto itr=grid.begin();itr!=grid.end();itr++)
    {
        if(itr->second==1) // checking the number of black squares
        counter++;
    }
    return counter;
}
int main(int argc,char* argv[])
{
    signed long numberOfMoves=atoi(argv[1]);
    unsigned long int numberOfBlackSquares=numberOfSquares(numberOfMoves);
    ofstream file;
    file.open("output2.txt",ios::out|ios::trunc); // saving output to external file
    file<<numberOfBlackSquares;
    file.close();
    return 0;
}
