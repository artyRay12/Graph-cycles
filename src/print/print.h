#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

void setBlue()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void setWhite()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

void printTwoVec(vector<vector<int>> graph)
{
    if(graph.size() == 0)
    {
        cout << "No cycles" << endl;
    }
    else
    {
        for_each(graph.begin(), graph.end(), [](vector<int>& vec_pogr)
        {
            for_each(vec_pogr.begin(),vec_pogr.end(), [](int i)
            {
                
                cout << "  " << i;
            });
            cout << endl;
        });
    }
}

void printCompanyName(vector<string> list)
{

    for_each(list.begin(),list.end(), [](string i)
    {
        cout <<left << i;
            cout << endl;
    });

}

void printOneVec(vector<int> list)
{

    for_each(list.begin(),list.end(), [](int i)
    {
        cout <<left << i;
    });
}
                       
void printCyclesWithCompanyNames(vector<string> companyList, vector<vector<int>> cycles)
{
    int cycleNumber = 1;

    for(int i = 0; i < cycles.size(); ++i)
    {
        cout << cycleNumber<< ". ";
        for(int j = 0; j < cycles[i].size() - 1; ++j)
        {
            cout << companyList[cycles[i][j] - 1] <<"("; setBlue(); cout<< cycles[i][j]; setWhite(); cout << ") ---> ";
        }
        cout << companyList[cycles[i][0] - 1] << "("; setBlue(); cout<<cycles[i][0]; setWhite(); cout << ")" << endl;
        cycleNumber++;
    }
}

void printCyclesWithNames(vector<string> companyList, vector<vector<int>> cycles, vector<int> cyclesIndex)
{
    int cycleNumber = 1;  
    for(int i = 0; i < cyclesIndex.size(); ++i)
    {
        cout << cycleNumber << ". ";
        for(int j = 0; j < cycles[cyclesIndex[i]].size() - 1; ++j)
        {
            cout << companyList[cycles[cyclesIndex[i]][j] - 1] <<"("; setBlue(); cout<< cycles[cyclesIndex[i]][j]; setWhite(); cout << ") ---> ";
        }
        cout << companyList[cycles[cyclesIndex[i]][0] - 1] << "("; setBlue(); cout << cycles[cyclesIndex[i]][0]; setWhite(); cout << ")" << endl;        
        cycleNumber++;
    }
}