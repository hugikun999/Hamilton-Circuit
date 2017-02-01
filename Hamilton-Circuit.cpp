#include<stdio.h>
#include<iostream>
#define V 5
using namespace std; 

void printSolution(int path[]);
 

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;
 
    
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 

bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
   
    if (pos == V)
    {
        
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
          return false;
    }
 
   
    for (int v = 1; v < V; v++)
    {
        
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
 
           
            if (hamCycleUtil (graph, path, pos+1) == true)
                return true;
 
          
            path[pos] = -1;
        }
    }
 
    
    return false;
}
 

bool hamCycle(bool graph[V][V])
{
	//set the initial value to -1,meaning that haven't reach any point
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
   
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == false )
    {
        printf("\nSolution does not exist");
        return false;
    }
 
    printSolution(path);
    return true;
}
 

void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i] + 1);
 
    
    printf(" %d ", path[0] + 1);
    printf("\n");
}
 

int main()
{
	
	
	int i=0,j=0;
    bool graph1[V][V];
    
	//set the initial value to 0 
	for(int x=0;x<V;x++)
    for(int y=0;y<V;y++)
    graph1[x][y]=0;
    
    //input the diagram
	cout<< "Please enter i and j which means i and j can reach each other.If you have entered all path ,enter¡u0 0¡vto exit."<<endl;
    while(1)
    {
          cin>> i >> j;
          if(i==0||j==0)
          break;
          graph1[i-1][j-1]=1;  
          graph1[j-1][i-1]=1;
    }
    
    
    
	hamCycle(graph1);

	system("pause");
    return 0;
}
