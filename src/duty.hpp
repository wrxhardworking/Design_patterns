#include<iostream>
#include <utility>
#include<vector>
#include<random>
#include <memory>
#include <thread>

class Handle {
public:
    virtual void HandleRequest(int days) = 0;

    void setNext(Handle *n) {
        this->next = n;
    }

    virtual ~Handle() = default;

    [[nodiscard]] Handle *getNext() const {
        return this->next;
    }

    Handle *next{};
};


class LeaderHandle : public Handle {
public:
    void HandleRequest(int days) override {
        if (days < 3 && days >= 0) {
            std::cout << "主人批准" << std::endl;
        } else {
            std::cout << "交给经理处理" << std::endl;
            if (getNext()) {
                getNext()->HandleRequest(days);
            }
        }
    }

private:
};

class MangerHandle : public Handle {
public:
    void HandleRequest(int days) override {
        if (days >= 3 && days < 10) {
            std::cout << "经理批准" << std::endl;
        } else {
            std::cout << "交由总经理处理" << std::endl;
            if (getNext()) {
                getNext()->HandleRequest(days);
            }
        }
    }

private:
};

class BigMangerHandle : public Handle {
public:
    void HandleRequest(int days) override {
        if (days >= 10 && days < 30) {
            std::cout << "总经理批准" << std::endl;
        } else {
            if (getNext()) {
                getNext()->HandleRequest(days);
            }
            std::cout << "不准批价" << std::endl;
        }
    }

private:
};


/*===============================================================================================*/

//记录成员变量
static int memberNum = 3;
//经历两转回到
static int poll = 2;
//记录当前要不起过的次数
static int count = 0;

class Carder {
public:
    Carder() {
        //初始化每个人手中的牌
        int minNum = 1; // 指定范围的最小值
        int maxNum = 15; // 指定范围的最大值

        std::this_thread::sleep_for(std::chrono::seconds(1));
        srand(time(nullptr)); // 初始化随机数种子
        for (int i = 0; i < 3; ++i) {
            int randomNumber = rand() % (maxNum - minNum + 1) + minNum; // 生成指定范围内的随机数
            cards.push_back(randomNumber);
        }
        show();
    }

    virtual void Handle(int data) = 0;

    void setNext(std::shared_ptr<Carder> n) {
        this->next = n;
    }

    [[nodiscard]] std::shared_ptr<Carder> getNext() const {
        return next;
    }

    [[nodiscard]] bool isSkip() const {
        if (this->cards.empty()) {
            return true;
        }
        return false;
    }

    void show() {
        for (auto &&card: cards) {
            std::cout << card << " ";
        }
        std::cout << "\n";
    }

    bool compare(int data) {
        for (auto &card: cards)
            if (card > data)
                return true;

        return false;
    }

    bool putCard(int data) {
        auto it = find(cards.begin(), cards.end(), data);
        if (it == cards.end()) {
            std::cout << "不存在卡牌" << std::endl;
        } else {
            cards.erase(it);
            if (cards.empty())
                return false;
        }
        return true;
    }

    static bool isOver() {
        if (memberNum <= 1) {
            return true;
        }
        return false;
    }

    std::shared_ptr<Carder> next;

    std::vector<int> cards;
};

class A : public Carder {
public:
    void Handle(int data) override {
        //判断该玩家是否出局
        if (isSkip()) {
            if (getNext()) {
                getNext()->Handle(data);
            }
        }
        if (compare(data) || count == poll) {
            if (count == poll) {
                data = 0;
            }
            count = 0;
            int card = 0;
            if (isOver()) {
                return;
            }
            std::cout << "A手中拥有的卡牌" << std::endl;
            show();
            while (card <= data) {
                if (isOver()) {
                    return;
                }
                std::cout << "A玩家请选择你要出的牌" << std::endl;
                std::cin >> card;
                if (card <= data)
                    std::cout << "太小了" << std::endl;
            }
            //如果下一次出牌不会成功 说明已经胜利
            if (!putCard(card)) {
                std::cout << "A已经胜利" << std::endl;
                memberNum--;
                poll--;
                count = 0;
            }
            if (getNext()) {
                getNext()->Handle(card);
            }
        } else {
            count++;
            std::cout << "要不起,轮到下家" << std::endl;
            if (getNext()) {
                getNext()->Handle(data);
            }
        }

    }

};

class B : public Carder {
public:
    void Handle(int data) override {
        if (isSkip()) {
            if (getNext()) {
                getNext()->Handle(data);
            }
        }
        if (compare(data) || count == poll) {
            if (count == poll) {
                data = 0;
            }
            count = 0;
            if (isOver()) {
                return;
            }
            std::cout << "B手中拥有的卡牌" << std::endl;
            show();
            int card = 0;
            while (card <= data) {

                std::cout << "B玩家请选择你要出的牌" << std::endl;
                std::cin >> card;
                if (card <= data)
                    std::cout << "太小了" << std::endl;
            }
            if (!putCard(card)) {
                std::cout << "B已经胜利" << std::endl;
                poll--;
                memberNum--;
                count = 0;
            }
            if (getNext()) {
                getNext()->Handle(card);
            }
        } else {
            count++;
            std::cout << "要不起,轮到下家" << std::endl;
            if (getNext()) {
                getNext()->Handle(data);
            }
        }
        //判断游戏是否已经结束

    }
};

class C : public Carder {
public:
    void Handle(int data) override {
        if (isSkip()) {
            if (getNext()) {
                getNext()->Handle(data);
            }
        }

        if (compare(data) || count == poll) {
            if (count == poll) {
                data = 0;
            }
            count = 0;
            if (isOver()) {
                return;
            }
            std::cout << "C手中拥有的卡牌" << std::endl;
            show();

            int card = 0;
            while (card <= data) {

                std::cout << "C玩家请选择你要出的牌" << std::endl;
                std::cin >> card;
                if (card <= data)
                    std::cout << "太小了" << std::endl;
            }
            if (!putCard(card)) {
                std::cout << "C已经胜利" << std::endl;
                poll--;
                memberNum--;
                count = 0;
            }
            if (getNext()) {
                getNext()->Handle(card);
            }
        } else {
            count++;
            std::cout << "要不起,轮到下家" << std::endl;
            if (getNext()) {
                getNext()->Handle(data);
            }
        }
    }
};