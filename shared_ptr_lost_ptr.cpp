#include <cassert>
#include <memory>
struct Demo{
    int content;
    bool freed;
    Demo():freed(false){}  
};
struct Deletor{
    void operator()(Demo* p){
        assert(p->freed);
        delete p;
    }
};
std::shared_ptr<Demo> temp(){
    std::shared_ptr<Demo> temp(new Demo,Deletor());
    temp->content++;
    return temp;
}
void lost(std::shared_ptr<Demo>& in){
    //in->freed=true;
    in=nullptr;
}
int main(int argc,char** argv){
    auto ttt=temp();
    lost(ttt);
}