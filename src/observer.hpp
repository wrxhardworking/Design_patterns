#include <iostream>
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 抽象观察者类
class Observer {
public:
    virtual void update(float price) = 0;
};

// 抽象被观察者类
class Subject {
public:
    virtual void attach(Observer *observer) = 0;

    virtual void detach(Observer *observer) = 0;

    virtual void notify(float price) = 0;
};

// 具体观察者类，表示股票持有者
class StockHolder : public Observer {
public:
    StockHolder(string name, int quantity, float price) :
            m_name(std::move(name)), m_quantity(quantity), m_price(price) {}

    void update(float price) override {
        if (abs(price - m_price) / m_price > 0.05f) {
            cout << "Stock price has changed to " << price << " (" << m_name << ")" << endl;
            m_price = price;
        }
    }

private:
    string m_name;
    int m_quantity;
    float m_price;
};

// 具体被观察者类，表示股票
class Stock : public Subject {
public:
    Stock(string name, float price) :
            m_name(std::move(name)), m_price(price) {}

    void attach(Observer *observer) override {
        m_observers.push_back(observer);
    }

    void detach(Observer *observer) override {
        for (auto it = m_observers.begin(); it != m_observers.end(); it++) {
            if (*it == observer) {
                m_observers.erase(it);
                break;
            }
        }
    }

    void notify(float price) override {
        for (auto observer: m_observers) {
            observer->update(price);
        }
    }

    void setPrice(float price) {
        if (abs(price - m_price) / m_price > 0.05f) {
            m_price = price;
            notify(price);
        }
    }
private:
    string m_name;
    float m_price;
    vector<Observer *> m_observers;
};



