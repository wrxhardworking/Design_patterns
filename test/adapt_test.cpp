//
// Created by 28108 on 2023/4/12.
//

#include  <vector>
#include "../src/adapt.h"

int main(){
    std::vector<int> test {1,2,3,4,5,6,3,2,1,};
    auto * dateOperation = new DateOperation;
    std::cout<<"排序前的数组:"<<std::endl;
    for(auto && x: test){
        std::cout<<x<<" ";
    }
    std::cout<<"\n";
    dateOperation->quickSort(test);
    std::cout<<"排序后的数组:"<<std::endl;
    for(auto && x: test){
        std::cout<<x<<" ";
    }
    std::cout<<"\n";
    std::cout<<"请输入你想查找的数字:"<<std::endl;
    int number;
    std::cin>>number;
    std::cout<<"查找结果是："<<dateOperation->binarySearch(test,number);
}