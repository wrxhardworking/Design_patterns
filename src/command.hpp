#include<iostream>
#include<vector>
#include<queue>
class Command {
public:
    virtual void Execute() {}

    virtual ~Command() = default;

};

class TvOpen : public Command {
public:
    void Execute() override {
        std::cout << "电视机打开了" << std::endl;
    };

    ~TvOpen() override = default;
};

class TvClose : public Command {
public:
    void Execute() override {
        std::cout << "电视机关闭了" << std::endl;
    };

    ~TvClose() override = default;
};

class TvInvoker {
public:

    void StartCall() {
        for (auto &cmd: commends) {
            cmd->Execute();
        }
    }

    void addCommend(Command *cmd) {
        commends.push_back(cmd);
    }

private:
    std::vector<Command *> commends;

};


/*======================================================================================================*/

class TextCommand {
public:
    virtual void Execute() = 0;

    virtual ~TextCommand() = default;
};

class NewCommand : public TextCommand {
public:
    void Execute() override {
        std::cout << "新建了一个文本" << std::endl;
    }
};

class CloseCommand : public TextCommand {
public:
    void Execute() override {
        std::cout << "关闭了一个文本" << std::endl;
    }
};

class SaveCommand : public TextCommand {
public:
    void Execute() override {
        std::cout << "保存了一个文本" << std::endl;
    }
};

class TextEditor{
public:
    void addCommand(TextCommand * cmd){
        this->cmds.push(cmd);
    }
    void Start(){
        while(!cmds.empty()){
            cmds.front()->Execute();
            cmds.pop();
        }
    }

    [[noreturn]] void Show(){
        int i;
        while(true){
            std::cout<<"请选择一个按钮 :1.新建文件 2.为文件打开按钮 3.保存文件"<<std::endl;
            std::cin>>i;
            switch (i) {
                case 1 :
                    addCommand(new NewCommand());
                    break;
                case 2 :
                    addCommand(new CloseCommand());
                    break;
                case 3 :
                    addCommand(new SaveCommand());
                    break;
                default:
                    std::cout<<"范围出错请重新输入"<<std::endl;
            }
            Start();
        }
    }
private:
    std::queue<TextCommand*> cmds;
};
