#include <iostream>
#include "ShmQ.h"
using namespace std;

int main() {
    shm::ShmQ Q;
    for (int i = 0; i < 100; i++) {
        Q.GetQueue()->push(Request(to_string(i), "test"));
        sleep(1);
    }
    
}