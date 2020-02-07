void sortGraph(vector<vector<int>> &graph)
{
    for_each(graph.begin(), graph.end(), [](vector<int>& vector)
    {
        sort(vector.begin(), vector.end());
    });
}

vector<vector<int>> getUniqueVector(vector<vector<int>> &cycles)
{
    sortGraph(cycles);
    bool duplicateFound = false;
    for_each(cycles.begin(), cycles.end(), [](vector<int>& vector)
    {
        auto last = unique(vector.begin(), vector.end());
        vector.erase(last, vector.end());
        vector.push_back(vector[0]);
    });

    vector<vector<int>> outVector;
    for(int i = 0; i < cycles.size(); ++i)
    {
        for (int j = 0; j < outVector.size(); ++j)
        {
            if(cycles[i] == outVector[j])
            {
                duplicateFound = true;
            }
        }

        if(!duplicateFound)
        {
            outVector.push_back(cycles[i]);
        }
        duplicateFound = false;
    }

    return outVector;
}