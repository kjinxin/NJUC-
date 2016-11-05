#include <iostream>
#include <ctime>
#include "doodlebug.h"
using namespace std;

namespace organismsavith
{
	void doodlebug :: move (node grid[22][22])
	{
		bool is_move[22][22];
		for (int i=1; i<=20; i++)
			for (int j=1; j<=20; j++)
				is_move[i][j]=false;
		srand ((int) time(0));
		for (int i=1; i<=20; i++)
			for (int j=1; j<=20; j++)
				if (grid[i][j].ch=='X' && is_move[i][j]==false)
				{
					int cnt=0,temp[4];
					if (grid[i-1][j].ch=='o') { temp[cnt]=0; cnt++; }
					if (grid[i][j-1].ch=='o') { temp[cnt]=1; cnt++; }
					if (grid[i][j+1].ch=='o') { temp[cnt]=2; cnt++; }
					if (grid[i+1][j].ch=='o') { temp[cnt]=3; cnt++; }
					if (cnt!=0)
					{
						int x=rand()%cnt;
						switch (temp[x])
						{
						case 0: grid[i-1][j].ch='X'; grid[i][j].ch=' '; grid[i-1][j].sur_time++; grid[i][j].sur_time=0; grid[i-1][j].is_breed=grid[i][j].is_breed; grid[i-1][j].hun_time=grid[i][j].hun_time=0; is_move[i-1][j]=true; break;
						case 1:	grid[i][j-1].ch='X'; grid[i][j].ch=' '; grid[i][j-1].sur_time++; grid[i][j].sur_time=0; grid[i][j-1].is_breed=grid[i][j].is_breed; grid[i][j-1].hun_time=grid[i][j].hun_time=0; is_move[i][j-1]=true; break;
						case 2:	grid[i][j+1].ch='X'; grid[i][j].ch=' '; grid[i][j+1].sur_time++; grid[i][j].sur_time=0; grid[i][j+1].is_breed=grid[i][j].is_breed; grid[i][j+1].hun_time=grid[i][j].hun_time=0; is_move[i][j+1]=true; break;
						case 3:	grid[i+1][j].ch='X'; grid[i][j].ch=' '; grid[i+1][j].sur_time++; grid[i][j].sur_time=0; grid[i+1][j].is_breed=grid[i][j].is_breed; grid[i+1][j].hun_time=grid[i][j].hun_time=0; is_move[i+1][j]=true; break;
						}
					}
					else
					{
						if (grid[i-1][j].ch==' ') { temp[cnt]=0; cnt++; }
						if (grid[i][j-1].ch==' ') { temp[cnt]=1; cnt++; }
						if (grid[i][j+1].ch==' ') { temp[cnt]=2; cnt++; }
						if (grid[i+1][j].ch==' ') { temp[cnt]=3; cnt++; }
						if (cnt!=0)
						{
							int x=rand()%cnt;
							switch (temp[x])
							{
							case 0: grid[i-1][j].ch='X'; grid[i][j].ch=' '; grid[i-1][j].sur_time=grid[i][j].sur_time+1; grid[i][j].sur_time=0; grid[i-1][j].is_breed=grid[i][j].is_breed; grid[i][j].is_breed=false; grid[i-1][j].hun_time=grid[i][j].hun_time+1; grid[i][j].hun_time=0; break;
							case 1: grid[i][j-1].ch='X'; grid[i][j].ch=' '; grid[i][j-1].sur_time=grid[i][j].sur_time+1; grid[i][j].sur_time=0; grid[i][j-1].is_breed=grid[i][j].is_breed; grid[i][j].is_breed=false; grid[i][j-1].hun_time=grid[i][j].hun_time+1; grid[i][j].hun_time=0; break;
							case 2: grid[i][j+1].ch='X'; grid[i][j].ch=' '; grid[i][j+1].sur_time=grid[i][j].sur_time+1; grid[i][j].sur_time=0; grid[i][j+1].is_breed=grid[i][j].is_breed; grid[i][j].is_breed=false; grid[i][j+1].hun_time=grid[i][j].hun_time+1; grid[i][j].hun_time=0; break;
							case 3: grid[i+1][j].ch='X'; grid[i][j].ch=' '; grid[i+1][j].sur_time=grid[i][j].sur_time+1; grid[i][j].sur_time=0; grid[i+1][j].is_breed=grid[i][j].is_breed; grid[i][j].is_breed=false; grid[i+1][j].hun_time=grid[i][j].hun_time+1; grid[i][j].hun_time=0; break;
							}
						}
					}
				}
	}
	void doodlebug :: breed (node grid[22][22])
	{
		srand ((int) time(0));
		for (int i=1; i<=20; i++)
			for (int j=1; j<=20; j++)
				if (grid[i][j].ch=='X' && grid[i][j].sur_time==9 && grid[i][j].is_breed==false)
				{
					int cnt=0,temp[4];
					if (grid[i-1][j].ch==' ')
                    {
                        temp[cnt]=0;
                        cnt++;
                    }
					if (grid[i][j-1].ch==' ')
                    {
                        temp[cnt]=1;
                        cnt++;
                    }
					if (grid[i][j+1].ch==' ')
                    {
                        temp[cnt]=2;
                        cnt++;
                    }
					if (grid[i+1][j].ch==' ')
                    {
                        temp[cnt]=3;
                        cnt++;
                    }
					if (cnt!=0)
					{
						int x=rand()%cnt;
						switch (temp[x])
						{
						case 0: grid[i-1][j].ch='X';  grid[i][j].is_breed=true; break;
						case 1: grid[i][j-1].ch='X';  grid[i][j].is_breed=true; break;
						case 2: grid[i][j+1].ch='X';  grid[i][j].is_breed=true; break;
						case 3: grid[i+1][j].ch='X';  grid[i][j].is_breed=true; break;
						}
					}
				}
	}
    void doodlebug :: starve (node grid[22][22])
	{
		for (int i=1; i<=20; i++)
			for (int j=1; j<=20; j++)
				if (grid[i][j].ch=='X' && grid[i][j].hun_time==4)
				{ grid[i][j].ch=' '; grid[i][j].sur_time=0; grid[i][j].is_breed=false; grid[i][j].hun_time=0; }
	}
}
