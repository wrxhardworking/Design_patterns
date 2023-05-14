//
// Created by 28108 on 2023/4/26.
//
#include"../src/memo.hpp"

int main(){
    //发起人
    auto* originator = new Originator();
    //管理者
    auto* caretaker = new Caretaker();
    // 修改发起人的状态并保存到备忘录对象中
    std::shared_ptr<Info> info(new Info);
    info->phone = 123;
    info->username = "wrx";
    info->password = "123";
    originator->setStateAndInfo(1,info);
    caretaker->addMemento(originator->createMemento());

    std::shared_ptr<Info> info1(new Info);
    info1->phone = 123;
    info1->username = "wrx";
    info1->password = "123456";
    originator->setStateAndInfo(2,info1);
    caretaker->addMemento(originator->createMemento());

    // 恢复发起人的状态到备忘录所记录的状态
    originator->setMemento(caretaker->getMemento(0));
    cout << "Current state: " << originator->getState()<< " Current info:";originator->getInfo()->Print();

    originator->setMemento(caretaker->getMemento(1));
    cout << "Current state: " << originator->getState()<< " Current info:";originator->getInfo()->Print();

    return 0;
}