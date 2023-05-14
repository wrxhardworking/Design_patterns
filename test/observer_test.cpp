#include"../src/observer.hpp"

int main() {
    // 创建股票对象
    Stock stock("Apple", 100.0f);

    // 创建两个股票持有者对象
    StockHolder holder1("Tom", 10, 100.0f);
    StockHolder holder2("Jerry", 5, 100.0f);

    // 股票持有者对象订阅股票对象
    stock.attach(&holder1);
    stock.attach(&holder2);

    // 模拟股票价格变化
    stock.setPrice(120.0f);
    stock.setPrice(90.0f);
    stock.setPrice(130.0f);

    // 股票持有者对象取消订阅股票对象
    stock.detach(&holder2);

    // 再次模拟股票价格变化
    stock.setPrice(140.0f);

    return 0;
}