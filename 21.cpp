/*Имеется  информация о взаимных долгах предприятий. Если
имеется цепочка предприятий
     A1(a1) --> A2(a2) --> ... -->An(an) --> A1(a1),
где Ai - наименование предприятия,  а ai - размер долга,  то с
каждого из предприятий можно списать долг в размере min(ai), а
предприятие с минимальным долгом исключить из списка должников
следующему в цепочке  предприятию.  Требуется  найти  варианты
взаимного  списания  долгов. Предложить критерии оптимальности
и способы оптимизации */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <deque>
#include "src/print/print.h"
#include "src/infoHandler/infoHandler.h"
#include "src/menu/menu.h"
#include "src/writeOffTypes/byUserName.h"
#include "src/writeOffTypes/byMaxLoan.h"
#include "src/writeOffTypes/byCycleLong.h"

using namespace std;

void addCycle(int cycleStart, int cycleEnd, vector<int> &ribs, vector<vector<int>> &cycles)
{
    vector<int> cycle;
    cycle.push_back(cycleEnd);
    for(int i = cycleStart; i != cycleEnd; i = ribs[i])
    {
        cycle.push_back(i);
    }
    cycle.push_back(cycleEnd);
    cycles.push_back(cycle);
}

void dfs(int vertex, int &n, vector<int> &ribs, vector<int> &color,  vector<vector<int>> graph, vector<vector<int>> &cycles, int cycleStart, vector<int> &test)
{
    int to;
    color[vertex] = 1;
    for(int j = 0; j < graph.size(); j++)
    {
        if(graph[j][0] == vertex)
        {
            if(graph[j][1] >= cycleStart)
            {
                to = graph[j][1];
                if (color[to] != 1)
                {  
                    ribs[vertex] = to;
                    dfs(to, n, ribs, color, graph, cycles, cycleStart, test);
                } 
                else 
                {
                    test.clear();
                    cout << endl;
                    addCycle(to, vertex, ribs, cycles);
                }
            }
        }
    }
    
    color[vertex] = 2;
}

int main(int argc, char* argv[])
{
    vector<string> companyNames;
    vector<vector<int>> graph;
    vector<vector<int>> cycles;
    vector<int> color;
    vector<int> ribs;

    vector<deque<int>> deqContainer;
    deque<int> deq;

    int to = 0;
    int cycleStart = 0;
    char ch;
    bool run = true;

    ifstream loansF(argv[1]), companyNamesF(argv[2]);
    int x= 0;

    graph = getGraphInfo(x, loansF);
    companyNames = getCompanyNames(x, companyNamesF);

    vector<int> test;
    while(run)
    {
        setWhite();
        x = graph.size();
        color.assign(x, 0);
        ribs.assign(x, -1);
        for(int i = 0; i < companyNames.size(); i++)
        {
            cycleStart = i;
            if(color[i] != 2)
                dfs(i, x, ribs, color, graph, cycles, cycleStart, test);
            
        }

        printMainMenu();
        ch = getch();

        switch(ch)
        {
            case 49: byMaxLoan(companyNames, cycles, graph);
                     break;
            case 50: byIncreaseCompany(companyNames, cycles, graph);
                     break;
            case 51: byUserName(companyNames, cycles, graph);
                     break;
            case 52: printTwoVec(cycles);
                     getch();
                     break;
            case 53: printTwoVec(graph);
                     getch();
                     break;
            default: run = false; 
                     break;
        }
        updateGraph(graph);
        color.clear();
        ribs.clear();
        cycles.clear();
        x = 0;
    }
}