#include"headers.h"

void LinearSearch(std::vector<int>RandomNumbers,int Element_To_Find){
    int count =0;
    for(auto i =RandomNumbers.begin();i!=RandomNumbers.end();i++){
            if(*i==Element_To_Find){
                std::cout<<"Element found in Linear Search found at index:"<<count<<std::endl;
                break;
            }
            count++;
        }
}

void CalculateTimeForLinearSearch(std::vector<int>RandomNumbers,int Element_To_Find){
        auto start = std::chrono::high_resolution_clock::now();
        LinearSearch(RandomNumbers,Element_To_Find);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout <<std::endl <<"Execution time for LINEAR SEARCH: " << duration.count() << " microseconds" << std::endl;
}