#include<iostream>

class ReadFile {
public:
    void readfile(){
        std::cout<<"读取文件"<<std::endl;
    }
};

class Password {
public:
    void password(){
        std::cout<<"加密文件"<<std::endl;
    }
};

class Save {
public:
    void save(){
        std::cout<<"保存文件"<<std::endl;
    }
};

class Encryption {
public:
    void encryption(){
        readFile.readfile();
        password.password();
        save.save();
    }
private:
    ReadFile readFile;
    Password password;
    Save save;
};

/*----------------------------------------------------------------------------------------------------------------------*/

class Memory {
public:
    void check() {
        std::cout << "自检" << std::endl;
    }
};

class Cpu {
public:
    void run() {
        std::cout << "运行" << std::endl;
    }
};

class HardDisk {
public:
    void read() {
        std::cout << "读取" << std::endl;
    }
};

class Os {
public:
    void load() {
        std::cout << "载入" << std::endl;
    }
};

class MainFrame {
public:
    void on() {
        memory.check();
        cpu.run();
        hardDisk.read();
        os.load();
    }
private:
    Memory memory;
    Cpu cpu;
    HardDisk hardDisk;
    Os os;
};
