#include <stdlib.h>
#include <vector>
#include <thread> 
struct temp{
    int aa;
    temp():aa(rand()){}
};
#ifdef SHARED
typedef  std::shared_ptr<temp> ptr_t;
#else
typedef  temp* ptr_t;
#endif
void foo(ptr_t ptr){
    std::vector<ptr_t>(100000,ptr);
}
int main(int argc, char** argv){
#ifdef SHARED
    ptr_t t(new temp);
#else
    ptr_t t=new temp;
#endif
    std::vector<std::thread> p;
    p.reserve(80);
    for (int i = 0; i < 80; i++)
    {
        p.emplace_back(foo,t);
    }
    for(auto & thread:p){
        thread.join();
    }
    
}