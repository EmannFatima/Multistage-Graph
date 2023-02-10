#include <iostream>
#include<conio.h>
#include<windows.h>
#include<List>
using namespace std;
//Time Complexity of Multistage Graph is O(n^2)
class Graph 
{
private:
	//Initiallization of Graphs
	int graphs[13][13] = {
		//0,1,2,3,4,5,6,7,8,9,10,11,12
		 {0,0,0,0,0,0,0,0,0,0,0,0,0}, //0
		 {0,0,9,7,3,2,0,0,0,0,0,0,0}, //1
		 {0,0,0,0,0,0,4,2,1,0,0,0,0}, //2
		 {0,0,0,0,0,0,2,7,0,0,0,0,0}, //3
		 {0,0,0,0,0,0,0,0,11,0,0,0,0}, //4
		 {0,0,0,0,0,0,0,11,8,0,0,0,0}, //5
		 {0,0,0,0,0,0,0,0,0,6,5,0,0}, //6
		 {0,0,0,0,0,0,0,0,0,4,3,0,0}, //7
		 {0,0,0,0,0,0,0,0,0,0,5,6,0}, //8
		 {0,0,0,0,0,0,0,0,0,0,0,0,4}, //9
		 {0,0,0,0,0,0,0,0,0,0,0,0,2}, //10
		 {0,0,0,0,0,0,0,0,0,0,0,0,5}, //11
		 {0,0,0,0,0,0,0,0,0,0,0,0,0} //12
	};
	int n = 12;
	int stages = 5;
	int min;

public:
	void Matrix()
	{
		// Display the Multistage Graph
		cout << "\n\n\n\t\t\t\t-----------" << endl;
		cout << "\t\t\t\t | GRAPH |" << endl;
		cout << "\t\t\t\t-----------" << endl << endl;
		for (int i = 0; i < 13; i++)
		{
			cout << " ";
			for (int j = 0; j < 13; j++)
			{
				cout << graphs[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Graph_Cost()
	{
		//cost array
		int cost[13]; int d[13]; int path[6];
		cost[n] = 0;
		for (int i = n - 1; i >= 1; i--)
		{
			min = INT_MAX;
			for (int j = i + 1; j <= n; j++) {
				if (graphs[i][j] != 0 && (graphs[i][j] + cost[j]) < min)		//Formula
				{
					min = graphs[i][j] + cost[j];
					d[i] = j;
				}
			}
			cost[i] = min;
		}
		// Finding the Optimal Solution 
		path[0] = 0;
		path[1] = 1;
		path[stages] = n;
		for (int i = 2; i < stages; i++)
		{
			path[i] = d[path[i - 1]];
		}
		// Display the Shortest distance and optimal Solution
		cout << "\n\n\t\t\t\t | SHORTEST PATH & OPTIMAL SOLUTION |" << endl;
		cout << "\n\t\t\t\t";
		for (int i : path) 
		{
			cout << i << "\t";
		}
	}
};
void menu()
{
	Graph G;
	system("Color 2");
	cout << "\n\n\n\t\t\t\t----------------------" << endl;
	cout << "\t\t\t\t| MULTI STAGE GRAPH |" << endl;
	cout << "\t\t\t\t----------------------" << endl;
	system("pause");
	system("cls");
	//-----------------------------------------------
	system("Color 5");
	G.Matrix();
	system("pause");
	//-----------------------------------------------
	system("Color 1");
	G.Graph_Cost();

}
int main()
{
	menu();
	_getch();
	return 0;
}
