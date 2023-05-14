#include "../src/bridge.hpp"
#include <iostream>

int main() {
    Birds *bird = new Eagle();
    bird->AddAction(new Fly(true));
    bird->show();
    Birds *birds1 = new Penguin();
    birds1->show();
    Birds *birds2 = new Dove();
    birds2->show();
}