#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <conio.h>
#include <deque>
#include <iterator>
#include "writeOffUtilites.h"
using namespace std;



vector<int> getLongestCyclesIndex(vector<vector<int>> &cycles)
{
    vector<int> cyclesLength;
    vector<int> longestCyclesIndex;
    int lengthOfLongestCycle = 0;

    for(int i = 0; i < cycles.size(); i++)
    {
        cyclesLength.push_back(cycles[i].size()); //получаем длины циклов
        if(cycles[i].size() > lengthOfLongestCycle)
        {
            lengthOfLongestCycle = cycles[i].size();
        }
    }

    for(int i = 0; i < cycles.size(); i++)
    {
        if(cycles[i].size() == lengthOfLongestCycle)
        {
            longestCyclesIndex.push_back(i);
        }
    }

    return longestCyclesIndex;  
}
 


void byIncreaseCompany(vector<string> companyNames, vector<vector<int>> &cycles, vector<vector<int>> &graph)
{
    vector<int> longestCycles = getLongestCyclesIndex(cycles);
    vector<int> cells;
    vector<int> loans;
    int num;
    int minLoan1 = 0;
    
    if(longestCycles.size() == 1)
    {
        getWriteOffNumber(graph, cycles[longestCycles[0]] , cells, loans);
        printOneVec(cycles[longestCycles[0]]);

        minLoan1 = getMinLoan(loans);
        cout << "Written off cycle: ";
        writeOff(cells, graph, minLoan1);
        cout << endl << "press any button to return to back menu" << endl;
    }
    else 
    {
        printByUserMenu();
        printCyclesWithNames(companyNames, cycles, longestCycles);
        cin >> num;
        if (num != 0)
        {
            getWriteOffNumber(graph, cycles[longestCycles[num - 1]] , cells, loans);
            printOneVec(cycles[longestCycles[num - 1]]);

            minLoan1 = getMinLoan(loans);
            cout << "Written off cycle: ";
            writeOff(cells, graph, minLoan1);
            cout << endl << "press any button to return to back menu" << endl;
        }
    }
}