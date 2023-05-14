#include "../src/duty.hpp"

int main() {
#if 0
    Handle *leader = new LeaderHandle;
    Handle *manger = new MangerHandle;
    Handle *bigManger = new BigMangerHandle;
    leader->setNext(manger);
    manger->setNext(bigManger);
    bigManger->setNext(nullptr);
    leader->HandleRequest(20);
    delete leader;
    delete manger;
    delete bigManger;
#endif
    std::shared_ptr<Carder> a(new A);
    std::shared_ptr<Carder> b(new B);
    std::shared_ptr<Carder> c(new C);

    a->setNext(b);
    b->setNext(c);
    c->setNext(a);

    std::cout<<"======================================================"<<std::endl;

    a->Handle(0);
    std::cout<<"游戏结束"<<std::endl;
}