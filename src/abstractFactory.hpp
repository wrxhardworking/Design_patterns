//
// Created by 28108 on 2023/3/22.
//
#include <iostream>

class FactoryManger {
public:
    virtual void show() = 0;
};

class Haier : public FactoryManger {
public:
    class HaierFactory {
    public:
        virtual void product() = 0;
    };

    class TV : public Haier::HaierFactory {
    public:
        void product() override {
            std::cout << "我是生产电视的部门" << std::endl;
        }
    };

    class AirCondition : public Haier::HaierFactory {
    public:
        void product() override {
            std::cout << "我是生产空调的部门" << std::endl;
        }
    };

    class Refrigerator : public Haier::HaierFactory {
    public:
        void product() override {
            std::cout << "我是生产冰箱的部门" << std::endl;
        }
    };

    void show() override {
        std::cout << "我是海尔" << std::endl;
    }
};

class TCL : public FactoryManger {
public:
    class TCLFactory {
    public:
        virtual void product() = 0;
    };

    class TV : public TCLFactory {
    public:
        void product() override {
            std::cout << "我是生产电视的部门" << std::endl;
        }
    };

    class AirCondition : public TCLFactory {
    public:
        void product() override {
            std::cout << "我是生产空调的部门" << std::endl;
        }
    };

    class Refrigerator : public TCLFactory {
    public:
        void product() override {
            std::cout << "我是生产冰箱的部门" << std::endl;
        }
    };
    void show() override {
        std::cout << "我是TCL" << std::endl;
    }
};