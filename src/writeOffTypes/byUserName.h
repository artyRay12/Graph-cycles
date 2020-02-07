#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <deque>
#include "writeOffUtilites.h"
using namespace std;

void byUserName(vector<string> companyNames, vector<vector<int>> &cycles, vector<vector<int>> &graph)
{
    vector<int> loans;
    vector<int> cellsForWriteOff;
    bool run = true;
    int ch;
    int lastName;
    int minLoan;

    printByUserMenu(); 
    printCyclesWithCompanyNames(companyNames, cycles);
    cin >> ch;
    if(ch != 0)
    {
        getWriteOffNumber(graph, cycles[ch - 1], cellsForWriteOff, loans);
        minLoan = getMinLoan(loans);
        cout << "Written off cycle: ";
        printOneVec(cycles[ch - 1]);
        writeOff(cellsForWriteOff, graph, minLoan);
        cout << endl << "press any button to return to back menu" << endl;
        getch();
    }
}