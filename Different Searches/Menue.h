#include"headers.h"

class Menue{

    std::unordered_map<int,std::string>Map;
    public:

    void DisplayMenue(){
        for(auto i = Map.begin();i!=Map.end();++i){
            std::cout<<(*i).first<<": "<<(*i).second<<std::endl;
        }
    }
   
    void Insert(std::string Item){
        static int count =0;
        Map.insert({count,Item});
        count++;
    }

};