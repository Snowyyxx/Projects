#include"headers.h"

class Graph{

    std::vector<std::vector<int>>AdjMatrix;
    int NumVertices;

    public:
    Graph(int NumVertices){
        this->NumVertices = NumVertices;
        AdjMatrix = std::vector<std::vector<int>>(NumVertices,std::vector<int>(NumVertices,-1));
    }

    void CreateGraph(std::vector<int>RandomNumbers){
        for(auto i = RandomNumbers.begin();i!=RandomNumbers.end();++i){
            
        }
    }


};