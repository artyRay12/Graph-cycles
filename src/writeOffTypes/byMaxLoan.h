#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <deque>
#include "writeOffUtilites.h"
using namespace std;

vector<int> getCycleWithMaxIndex(vector<int> minLoans)
{
    vector<int> cyclesIndex;
    int maxLoan = minLoans[0];
    for (int i = 0; i < minLoans.size(); i++)
    {
        if(maxLoan < minLoans[i])
        {
            maxLoan = minLoans[i];
        }
    }

    for (int i = 0; i < minLoans.size(); i++)
    {
        if(minLoans[i] == maxLoan)
        {
            cyclesIndex.push_back(i);
        }
    }
    return cyclesIndex;
}

void byMaxLoan(vector<string> companyNames, vector<vector<int>> &cycles, vector<vector<int>> &graph)
{
    vector<int> loans;
    vector<int> minLoans;
    vector<int> cells;
    vector<int> cycleWithMaxLoanIndex;
    int num;
    int minLoan = 0;
    for(int k = 0; k < cycles.size(); k++)
    {
        getWriteOffNumber(graph, cycles[k] , cells, loans);
        minLoan = getMinLoan(loans) * (cycles[k].size() - 1);
        minLoans.push_back(minLoan);
        cells.clear();
        loans.clear();
    }

    cycleWithMaxLoanIndex = getCycleWithMaxIndex(minLoans);
    if(cycleWithMaxLoanIndex.size() == 1)
    {
        getWriteOffNumber(graph, cycles[cycleWithMaxLoanIndex[0]] , cells, loans);
        cout << "Written off cycle: ";
        writeOff(cells, graph, getMinLoan(loans));
        cout << endl << "press any button to return to back menu" << endl;
    }
    else
    {
        printByUserMenu();
        printCyclesWithNames(companyNames, cycles, cycleWithMaxLoanIndex);
        cin >> num;
        if (num != 0)
        {
            getWriteOffNumber(graph, cycles[cycleWithMaxLoanIndex[num - 1]] , cells, loans);
            printOneVec(cycles[cycleWithMaxLoanIndex[num - 1]]);

            minLoan = getMinLoan(loans);
            cout << "Written off cycle: ";
            writeOff(cells, graph, minLoan);
            cout << endl << "press any button to return to back menu" << endl;
        }

    }
    

    //

  

    
    getch();
}