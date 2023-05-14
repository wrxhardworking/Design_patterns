//
// Created by 28108 on 2023/4/12.
//
#include "../src/abstractFactory.hpp"

int main() {
    TCL::TCLFactory * s = new TCL::Refrigerator;
    s->product();
}