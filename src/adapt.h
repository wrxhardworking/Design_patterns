#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class QuickSort {
public:
    static void Do(std::vector<int> &v) {
        std::sort(v.begin(), v.end());
    }
};

class BinarySearch {
public:
    static int Do(std::vector<int> &v, int tag) ;
};

class SortAdapter{
public:
    void quickSort(std::vector<int> &v){
        QuickSort::Do(v);
    }

    int binarySearch(std::vector<int> &v, int tag){
        int res = BinarySearch::Do(v, tag);
        return res;
    }

};

class DateOperation {
public:
    DateOperation(){
        adapter = new SortAdapter;
    }
    void quickSort(std::vector<int> &v){
        adapter->quickSort(v);
    }
    int binarySearch(std::vector<int> &v, int tag){
        return adapter->binarySearch(v,tag);
    }
    ~DateOperation(){
        delete this->adapter;
    }
private:
    SortAdapter* adapter;
};


