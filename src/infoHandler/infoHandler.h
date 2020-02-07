#include <sstream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


vector<int> getEdgeInfo(string str)
{   
    vector<int> outVector;
    string newStr;
    stringstream strStream(str);

    while(getline(strStream, newStr, ' '))
    {
       outVector.push_back(stoi(newStr));
    }
    return outVector;
}

vector<vector<int>> getGraphInfo(int &n, ifstream &loans)
{
    vector<vector<int>> outVector;
    string str;

    while(getline(loans, str))
    {
        outVector.push_back(getEdgeInfo(str));
        n++;
    }
    return outVector;
}

vector<string> getCompanyNames(int &n, ifstream &companyNames)
{
    vector<string> outVector;
    string str;
    while(getline(companyNames, str))
    {
        outVector.push_back(str);
    }
    return outVector;
}

