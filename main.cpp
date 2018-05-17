#include <iostream>
#include "myvector.h"

int main() {
    std::cout<<"start"<<std::endl;
    myvector<myvector<int>> b(4, myvector<int>(2));
    std::cout<<b[0].size() << " b[0]-size " << std::endl;
    for(size_t i = 0; i < b.size(); i++){
        std::cout<<b.size() << " b-size "<<std::endl;
        std::cout<<i<< std::endl;
        for(size_t j = 0; j < b[0].size(); j++){
            std::cout<<b[0].size() << " b[0]-size " << std::endl;
            std:: cout << b[i][j] << std::endl;
        }
    }
    return 0;
}