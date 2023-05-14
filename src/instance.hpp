//
// Created by 28108 on 2023/3/22.
//
#include<iostream>

class SonWindow{
public:

    static SonWindow* getInstance(){
        static SonWindow s;
        return &s;
    }
    void show(){
        std::cout<<"我是子窗体"<<std::endl;
    }
};
class MainWindow{
public:
    void show(){
        std::cout<<"我是主窗体"<<std::endl;
    }
    void Do(){
        //永远只会创建一次
        show();
        SonWindow ::getInstance()->show();
    }
};

