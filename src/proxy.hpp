#include<iostream>
#include<vector>
#include<string>
#include <chrono>
#include <map>
#include<thread>

struct User {
    std::string name;
    int password{};

    bool operator==(const User &user) const {
        return this->name == user.name && this->password == user.password;
    }
};

//商品信息
struct Product {
    std::string productName;
    int productNum{};
    std::string customerName;

    bool operator==(const Product &product) const {
        return  this->productName == product.productName &&
               this->customerName == product.customerName;
    }
};

std::map<std::string, int> Stock{
        {"chicken", 100},
        {"egg", 100},
};

std::vector<Product> products{
};

std::vector<User> Users;


class Operaion {
public:
    virtual ~Operaion() = default;

    virtual void request() = 0;
};

class Register : public Operaion {
public:
    void request() override {
        User user;
        std::cout << "请输入用户名" << std::endl;
        std::cin >> user.name;
        std::cout << "请输入密码" << std::endl;
        std::cin >> user.password;
        Users.push_back(user);
        std::cout<<"注册成功"<<std::endl;
    };
};

class Add : public Operaion {
public:
    void request() override {
        Product product;
        User user;
        std::cout << "请输入用户名" << std::endl;
        std::cin >> user.name;
        std::cout << "请输入密码" << std::endl;
        std::cin >> user.password;
        std::cout << "请输入商品名称" << std::endl;
        std::cin >> product.productName;
        std::cout << "请输入商品数量" << std::endl;
        std::cin >> product.productNum;

        if (std::find(Users.begin(), Users.end(), user) == Users.end()) {
            std::cout << "该用户不存在" << std::endl;
            return;
        }
        std::cout << "登陆成功" << std::endl;
        product.customerName = user.name;
        if (Stock.find(product.productName) == Stock.end()) {
            std::cout << "没有该商品" << std::endl;
            return;
        }
        if (Stock[product.productName] - product.productNum <= 0) {
            std::cout << "库存不足" << std::endl;
            return;
        }
        Stock[product.productName] -= product.productNum;
        std::cout << "更新仓库为" << Stock[product.productName];
        products.push_back(product);
        std::cout << product.customerName << "订购了" << product.productNum << "个" << std::endl;
    }
};

class Modify : public Operaion {
public:
    void request() override {
        Product product;
        User user;
        std::cout << "请输入用户名" << std::endl;
        std::cin >> user.name;
        std::cout << "请输入密码" << std::endl;
        std::cin >> user.password;
        std::cout << "请输入商品名称" << std::endl;
        std::cin >> product.productName;
        std::cout << "请输入修改后商品数量" << std::endl;
        std::cin >> product.productNum;
        if (std::find(Users.begin(), Users.end(), user) == Users.end()) {
            std::cout << "该用户不存在" << std::endl;
            return;
        }
        product.customerName = user.name;

        auto it = std::find(products.begin(),products.end(),product);
        if(it == products.end()){
            std::cout << "该用户无权限" << std::endl;
            return;
        }
        if (Stock.find(product.productName) == Stock.end()) {
            std::cout << "没有该商品" << std::endl;
            return;
        }
        if ((Stock[product.productName] +(it->productNum-product.productNum)) <= 0) {
            std::cout << "库存不足" << std::endl;
            return;
        }
        Stock[product.productName] += (it->productNum-product.productNum);
        std::cout << "更新仓库为" << Stock[product.productName];
        std::cout << product.customerName << "订购了" << product.productNum << "个" << std::endl;
    }
};

class Proxy : public Operaion {
public:
    Proxy() {
        this->regis = new Register;
        this->modify = new Modify;
        this->add = new Add;
    }

    ~Proxy() override {
        delete this->regis;
        delete this->modify;
    }

    [[noreturn]] void request() override {
        while (true) {
            std::cout<<"请选择业务"<<std::endl;
            std::cout<<"1.注册  2.修改订单 3.添加订单"<<std::endl;
            int tmp;
            std::cin>>tmp;
            switch (tmp) {
                case 1:
                    regis->request();
                    break;
                case 2:
                    modify->request();
                    break;
                case 3:
                    add->request();
                    break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cin.clear();
            system("cls");
        }
    }

private:
    Register *regis;
    Modify *modify;
    Add *add;
};
