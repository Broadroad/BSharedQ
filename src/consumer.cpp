#include <iostream>
#include "ShmQ.h"
using namespace std;

int main() {
    shm::ShmQ Q;
    for (int i = 0; i < 100; i++) {
        Request r;
        Q.GetQueue()->pop(r);
        std::cout << r.RequestId() << std::endl;
    }
    
}