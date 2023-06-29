#include<iostream>
#include<vector>
#include<unordered_map>
#include"BST.h"
#include <chrono>



void AddElementsToVector(std::vector<int>&Numbers){
    int len = Numbers.size();
    for(auto i =0;i<len;i++){
        Numbers[i]=Algorithim(i);
    }
}

void CalculateTimeBST(int Element_To_Find,BinarySearchTree &BST){
    auto start = std::chrono::high_resolution_clock::now();
    BST.Search(Element_To_Find);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout <<std::endl <<"Execution time for TREE: " << duration.count() << " microseconds" << std::endl;

}

void LinearSearch(std::vector<int>&Numbers, int element_to_find){
    int count=0;
    for(auto i =Numbers.begin();i!=Numbers.end();++i){
        if(*i==element_to_find){
            std::cout<<*i<<" found at: "<<count<<" index!";
            break;
        }
        count++;
    }
}

void InsertMenue(std::unordered_map<int,std::string>&Menue,std::string Item){
    static int count =0;
    Menue.insert({count,Item});
    count++;
}

void DisplayMenue(std::unordered_map<int,std::string>&Menue){
    for(auto i = Menue.begin();i!=Menue.end();++i){
        std::cout<<(*i).first<<": "<<(*i).second;
    }
}

int main(){
    
    int NumberOfElements;
    int Element_To_Find;
    std::unordered_map<int,std::string>Menue;
    BinarySearchTree BST;
   
    std::cout<<"How many elements do you want in the search list: ";
    std::cin>>NumberOfElements;
    
    AddElementsToBST(BST,NumberOfElements);
    
    std::vector<int>Numbers(NumberOfElements);
    AddElementsToVector(Numbers);

    std::cout<<"What element to find: ";
    std::cin>>Element_To_Find;

    CalculateTimeBST(Element_To_Find,BST);

}
