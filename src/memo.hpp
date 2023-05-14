#include<iostream>
#include<string>
#include <utility>
#include<vector>
#include<algorithm>

using std::cout;

struct Info {
    void Print() const {
        std::cout << this->username << " " << this->password << " " << this->phone << std::endl;
    }
    std::string username;
    std::string password;
    int phone;
};

// 备忘录类，用于存储发起人的状态
class Memento {
public:
    Memento(int s, std::shared_ptr<Info> info) : state_(s), info_(std::move(info)) {}

    [[nodiscard]] int getState() const {
        return state_;
    }

    std::shared_ptr<Info> getInfo() {
        std::cout << "用户名:" << info_->username << "密码:" << info_->password << "手机:" << info_->phone << std::endl;
        return info_;
    }

private:
    std::shared_ptr<Info> info_;
    int state_;
};

// 发起人类，可以创建备忘录和使用备忘录恢复自身状态
class Originator {
public:

    void setStateAndInfo(int s, std::shared_ptr<Info> info) {
        state = s;
        info_ = std::move(info);
    }

    [[nodiscard]] int getState() const {
        return state;
    }

    std::shared_ptr<Info> getInfo() {
        return info_;
    }

    Memento *createMemento() {
        return new Memento(state, info_);
    }

    void setMemento(Memento *m) {
        state = m->getState();
        info_ = m->getInfo();
        delete m;
    }

private:
    std::shared_ptr<Info> info_;
    int state;
};


// 管理者类，用于保存和获取备忘录对象
class Caretaker {
public:
    void addMemento(Memento *m) {
        mementos.push_back(m);
    }

    Memento *getMemento(int index) {
        return mementos[index];
    }
private:
    std::vector<Memento *> mementos;
};



