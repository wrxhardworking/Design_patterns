//
// Created by 28108 on 2023/4/12.
//

//
// Created by 28108 on 2023/3/15.
//

#pragma once
#include<iostream>

template<typename T, typename U>
class calculator {
public:
    void Do() {
        InPut();
        OutPut();
    }

    void InPut() {
        std::cout << "请输入左操作数" << "\n";
        std::cin >> left;
        std::cout << "请输入运算符" << "\n";
        std::cin >> symbol;
        std::cout << "请输入右操作数" << "\n";
        std::cin >> right;
    }

    void OutPut();

    class calculation {
    public:
        //判断返回的是什么极限
        virtual typename std::conditional<(sizeof(U) > sizeof(T)), U, T>::type calculate(T a, U b)  = 0;
    };

private:
    void operatorProcess(calculation *s);

    calculation *cal;
    char symbol;
    T left;
    U right;
};

template<typename T, typename U>
void calculator<T, U>::operatorProcess(calculator<T, U>::calculation *s) {
    std::cout << "输出的结果是：" << s->calculate(left, right) << "\n";
}


template<typename T, typename U>
class Add : public calculator<T, U>::calculation {
public:
    typename std::conditional<(sizeof(U) > sizeof(T)), U, T>::type calculate(T a, U b) override {
        return a + b;
    }
};

template<typename T, typename U>
class Sub : public calculator<T, U>::calculation {
public:
    typename std::conditional<(sizeof(U) > sizeof(T)), U, T>::type calculate(T a, U b) override {
        return a - b;
    }
};

template<typename T, typename U>
class Mul : public calculator<T, U>::calculation {
public:
    typename std::conditional<(sizeof(U) > sizeof(T)), U, T>::type calculate(T a, U b) override {
        return a * b;
    }
};


template<typename T, typename U>
class Div : public calculator<T, U>::calculation {
public:
    typename std::conditional<(sizeof(U) > sizeof(T)), U, T>::type calculate(T a, U b) override {
        return a / b;
    }
};

template<typename T, typename U>
void calculator<T, U>::OutPut() {
    switch (this->symbol) {
        case '*':
            cal = new Mul<T, U>();
            operatorProcess(cal);
            break;
        case '+':
            cal = new Add<T, U>();
            operatorProcess(cal);
            break;
        case '-':
            cal = new Sub<T, U>();
            operatorProcess(cal);
            break;
        case '/':
            cal = new Div<T, U>();
            operatorProcess(cal);
            break;
        default:
            std::cout << "操作符有误" << "\n";
            break;
    }
    delete this->cal;
}

