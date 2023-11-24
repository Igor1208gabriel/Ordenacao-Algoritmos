#include <iostream>
int main(){
    int m[5] = {1, 2, 3, 4, 5};
    for(int i = 1; i < 4; i++){
        m[i] = m[i+1];
    }
    for(int i = 0; i < 5; i++) std::cout << m[i] << " ";
}