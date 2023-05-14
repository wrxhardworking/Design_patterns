//
// Created by 28108 on 2023/4/25.
//
#include <memory>
#include "../src/command.hpp"

class Test{
public:
    void add(int a){
        res.push_back(a);
    }

private:
    std::vector<int> res;
};
int main(){
#if 0
    std::shared_ptr<TvInvoker> tvInvoker(new TvInvoker);

    tvInvoker->addCommend(new TvOpen());
    tvInvoker->addCommend(new TvClose());
    tvInvoker->addCommend(new TvOpen());

    tvInvoker->StartCall();
#endif
    std::shared_ptr<TextEditor> textEditor(new TextEditor);
    textEditor->Show();
};