#include <iostream>
#include <vector>

class Action {
public:
    virtual const char *act() = 0;
    virtual ~Action()= default;
    bool can{};
};


class Fly : public Action {
public:
    explicit Fly(bool c) {
        can = c;
    }

    const char *act() override {
        if (can)
            return "能飞";
        else
            return "不能飞";
    }
};

class Swimming : public Action {
public:
    explicit Swimming(bool c) {
        can = c;
    }

    const char *act() override {
        if (can)
            return "能游泳";
        else
            return "不能游泳";
    }
};


class Birds {
public:
    std::vector<Action *> actions;

    void AddAction(Action * action){
        actions.push_back(action);
    }

    virtual void show() = 0;

    virtual ~Birds() = default;
};

class Dove : public Birds {
public:
    Dove() = default;

    void show() override {
        std::cout << "鸽子:" << std::endl;
        for (auto &&action: actions) {
            std::cout << action->act() << std::endl;
        }
    }

    ~Dove() override {
        for (auto action: actions) {
            delete (action);
        }
    }
};

class Eagle : public Birds {
public:
    Eagle() = default;

    void show() override {
        std::cout << "老鹰:" << std::endl;
        for (auto &&action: actions) {
            std::cout << action->act() << std::endl;
        }
    }

    ~Eagle() override {
        for (auto action: actions) {
            delete (action);
        }
    }
};

class Penguin : public Birds {
public:
    Penguin() = default;

    void show() override {
        std::cout << "企鹅" << std::endl;
        for (auto &&action: actions) {
            std::cout << action->act() << std::endl;
        }
    }

    ~Penguin() override {
        for (auto action: actions) {
            delete (action);
        }
    }
};