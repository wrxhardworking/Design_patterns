#include"../src/iterator.hpp"

int main(){
    std::vector<std::string> channle{"cctv1","cctv2"};
    Control control(channle);
    control.show();
}