#include<bits/stdc++.h>
using namespace std;
void add(int a[7][8],int col, int turn)
{	cout<<"Here"<<col;
	for (int i = 6; i >= 1; --i)
	{	cout<<a[i][col];
		if(a[i][col] == 0)
			{	cout<<i<<" "<<col;
				if(turn % 2 == 0)
					{
						a[i][col] = 1;
						break;
					}
				else
					{
						a[i][col] = 2;
						break;
					}
			}

	}
}
void disp(int a[7][8])
{
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 7; ++j)
		{
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}
}
void print(int a[7][8])
{	char ch;
	cout<<endl;
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 7; ++j)
		{	if(a[i][j] == 0)
				ch = ' ';
			if(a[i][j] == 1)
				ch = 'O';
			if(a[i][j] == 2)
				ch = 'X';
			cout<<" | "<<ch;
		}
		cout<<" | "<<endl;
	}
	cout<<" -----------------------------\n";
	cout<<"   1   2   3   4   5   6   7\n";
}
int check(int a[7][8])
{	for (int i = 1; i <= 6; ++i)
	{	
	for (int j = 1; j <= 4; ++j)
		{
			if(a[i][j] == a[i][j+1] && a[i][j+1] == a[i][j+2] && a[i][j] == a[i][j+3] && a[i][j] != 0 )
				return 1;
		}	
	}

	for (int j = 1; j <= 7; ++j)
	{	
	for (int i = 1; i <= 3; ++i)
		{
			if(a[i][j] == a[i+1][j] && a[i][j] == a[i+2][j] && a[i][j] == a[i+3][j] && a[i][j] != 0 )
				return 1;
		}	
	}
	for (int i = 6; i >= 4; --i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if(a[i][j] == a[i-1][j+1] && a[i][j] == a[i-2][j+2] && a[i][j] == a[i-3][j+3] && a[i][j] !=0 )
			return 1;
		}
	}
	for (int i = 6; i >= 4; --i)
	{
		for (int j = 7; j >= 4; --j)
		{
			if(a[i][j] == a[i-1][j-1] && a[i][j] == a[i-2][j-2] && a[i][j] == a[i-3][j-3] && a[i][j] !=0 )
			return 1;
		}
	}
	return 0;
}
int main()
{	int a[7][8]={0};
	int flag = 0 , col;
	string player1,player2;
	cout<<"Enter player 1 name: ";
	cin>>player1;
	cout<<"Enter player 2 name: ";
	cin>>player2;
	int turn=0;
	int total=42;
	while(turn < total)
	{

				if(turn % 2 == 0)
				{
					cout<<"\n"<<player1<<"'s turn: ";
					cin>>col;
					if(col < 1 || col > 7 || a[1][col] != 0)
						{
							cout<<"Wrong input try again! \n";
							continue;
						}
					add(a,col,turn);
					//disp(a);
				}
				else
				{
					cout<<"\n"<<player2<<"'s turn: ";
					cin>>col;
					if(col < 1 || col > 7 || a[1][col] != 0)
						{
							cout<<"Wrong input try again! \n";
							continue;
						}
					add(a,col,turn);
					//disp(a);
				}
				print(a);
				if(check(a) == 1)
				{
					if (turn % 2 == 0)
					{
						cout<<player1<<" wins\n";
						flag = 1;
						break;
					}
					else
					{
						cout<<player2<<" wins\n";
						flag = 1;
						break;
					}
				}

			turn++;
	}
	if(flag == 0)
		cout<<"Its a draw";
	return 0;
}