#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>



class Animal
{
    public:

    Animal(int val) {
        var = val;
    }

    ~Animal() {
        std::cout << "Adios...";
    }

    void setter(int val) {
        var = val;
    }

    int getter(){
        return var;
    }


    private:
        int var = 0xA;
};

#endif // ANIMAL_H
