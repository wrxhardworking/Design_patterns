#include <iostream>
#include<vector>
#include <string>

class MyIterator {
public:
    MyIterator(int index ,std::vector<std::string> &data) : index(index), data(data) {}

    std::string& operator*() { return data[index]; }

    bool operator!=(const MyIterator &other) const { return index != other.index; }

    MyIterator &operator++() {
        index++;
        return *this;
    }
    MyIterator &operator--() {
        index--;
        return *this;
    }
    MyIterator &operator-(int i) {
        index-=i;
        return *this;
    }
private:
    int index;
    std::vector<std::string> &data;
};

class MyTvChannel {
public:
    explicit MyTvChannel(std::vector<std::string> &data) : data(data) {}

    MyIterator begin() { return MyIterator(0,data); }

    MyIterator end() { return MyIterator(data.size(),data); }

private:
    std::vector<std::string> &data;
};


class Control{
public:
    explicit Control(std::vector<std::string>& channels):myTvChannel(channels){
    }
    void show(){
        std::cout<<"正向遍历"<<std::endl;
        for(const auto& channel : myTvChannel){
            std::cout<<channel<<std::endl;
        }
    }
private:
    MyTvChannel myTvChannel;
};


