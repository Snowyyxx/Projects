#include"headers.h"
#include"Linear Search.h"
#include"Menue.h"
#include"BST.h"


void DisplayRandomNumbers(std::vector<int>RandomNumbers){
    for(auto i = RandomNumbers.begin();i!=RandomNumbers.end();++i){
        std::cout<<*i<<",";
    }
}

void AddElementsToVector(std::vector<int>&Numbers){
    
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

void ShowMenue(){
    Menue menue;
    menue.Insert("BST");
    menue.Insert("Linear Search");
    menue.DisplayMenue();

}

int SearchWhat(){
    int num;
    std::cout<<"What Element would you like to search: ";
    std::cin>>num;
    return num;
}


int main(){
    int NumberOfElements;
    int option;
    std::cout<<"How many elements do you want in the search list: ";
    std::cin>>NumberOfElements;
    std::vector<int>RandomNumbers(NumberOfElements);
    GenerateRandomNumbers(RandomNumbers,NumberOfElements);
    ShowMenue();

    std::cout<<"What would you like to use: ";
    std::cin>>option;

   
    if(option==0){
        BinarySearchTree BST;
        BST.AddElementsToBSTUsingVector(NumberOfElements,RandomNumbers);
        DisplayRandomNumbers(RandomNumbers);
        BST.CalculateTimeBST(SearchWhat());
        
    } else if(option==1){
        DisplayRandomNumbers(RandomNumbers);
        CalculateTimeForLinearSearch(RandomNumbers,SearchWhat());
    }


    
}