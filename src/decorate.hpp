//
// Created by 28108 on 2023/4/2.
//

#include <iostream>
#include <memory>

class Coffee {
public:
    virtual void show() = 0;

    int price{};
};

//蓝山咖啡
class BlueCoffee : public Coffee {
public:
    BlueCoffee() {
        this->price = 8;
    }

    void show() override {
        std::cout << "蓝山咖啡";
    }

private:
};

//拿铁咖啡
class LatteCoffee : public Coffee {
public:
    LatteCoffee() {
        this->price = 10;
    }

    void show() override {
        std::cout << "拿铁咖啡";
    }
};

class CoffeeDecorator : public Coffee {
public:
    int total{};
};

class Milk : public CoffeeDecorator {
public:
    explicit Milk(const std::shared_ptr<Coffee> &coffee) {
        coffee->show();
        this->price = 2 + coffee->price;
    }

    void show() override {
        std::cout << "加了牛奶为：" << this->price << " ";
    }
};

class Orange : public CoffeeDecorator {
public:
    explicit Orange(const std::shared_ptr<Coffee> &coffee) {
        coffee->show();
        this->price = 3 + coffee->price;
    }

    void show() override {
        std::cout << "加了橙汁为：" << this->price << " ";
    }
};


/*--------------------------------------------------------------------------------------------------------------------*/
class MainWindow {
public:
    virtual void show() {
        std::cout << "这是主窗口" << " ";
    }
};

class MainDecorate : public MainWindow {
    virtual void Add()  = 0;
};


class Roller : public MainDecorate {
public:
    explicit Roller(const std::shared_ptr<MainWindow> &mainWindow) {
        mainWindow->show();
    }

    void Add() override {
        std::cout << "加了滚轮" ;
    }
    void show() override {
        Add();
    }
};

class Transparency : public MainDecorate {
public:
    explicit Transparency(const std::shared_ptr<MainWindow> &mainWindow) {
        mainWindow->show();
    }

    void Add() override {
        std::cout << "是透明";
    }

    void show() override {
        Add();
    }
};




