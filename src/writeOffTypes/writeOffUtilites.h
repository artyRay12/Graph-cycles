#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <deque>
using namespace std;
#pragma once

void getWriteOffNumber(vector<vector<int>> graph, vector<int> cycle, vector<int> &cellsForWriteOff, vector<int> &loans)
{
    for(int i = 0; i < cycle.size(); i++)
    {
        for(int j = 0; j < graph.size(); j++)
        {   
            if (i < cycle.size() - 1)
            {
                if((cycle[i] == graph[j][0] ) && (cycle[i + 1] == graph[j][1]))
                {
                    loans.push_back(graph[j][2]);
                    cellsForWriteOff.push_back(j);
                }
            }
        }
    }
}

void writeOff(vector<int> cellsForWriteOff, vector<vector<int>> &graph, int minLoan)
{
    for(int i = 0; i < cellsForWriteOff.size(); i++)
    {
        graph[cellsForWriteOff[i]][2] -= minLoan;
    } 
    cout << endl; 
    cout << "write off from each other: " << minLoan << endl;
}

int getMinLoan(vector<int> loans)
{   
    int minLoan = loans[0];
     for(int i = 0; i < loans.size(); i++)
    {
        if (loans[i] < minLoan)
        {
            minLoan = loans[i];
        }
    } 
    return minLoan;
}

void updateGraph(vector<vector<int>> &graph)
{
    for(int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][2] == 0)
            {
                graph.erase(graph.begin() + i);
            }   
        }
    }
}