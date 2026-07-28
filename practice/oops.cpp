#include <bits/stdc++.h>
using namespace std;


class Animal {
public:
    string breed;

    virtual void sound() = 0;

    string getBreed() {
        return breed;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog is making a sound\n";
    }
    void bark() {
        cout << "bark\n";
    }
};


int main() {
    Animal* d = new Dog();
    d->sound();
}
