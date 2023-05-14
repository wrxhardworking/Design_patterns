//
// Created by 28108 on 2023/4/11.
//

#include"../src/decorate.hpp"

int main(){
#if 1
    std::shared_ptr<Coffee> coffee1(new BlueCoffee);
    coffee1 = std::make_shared<Orange>(std::make_shared<Milk>(coffee1));
    coffee1->show();
    std::cout<<"\n";
    std::shared_ptr<Coffee> coffee2(new LatteCoffee);
    coffee2 = std::make_shared<Milk>(std::make_shared<Orange>(coffee2));
    coffee2->show();
#endif

#if 1
    std::shared_ptr<MainWindow> mainWindow(new MainWindow);
    mainWindow = std::make_shared<Transparency>(mainWindow);
    mainWindow = std::make_shared<Roller>(mainWindow);
    mainWindow->show();
#endif
}
