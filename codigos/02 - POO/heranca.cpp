#include <iostream>
using namespace std;

class Pet{
protected:
    string name;
    int age;
    float weight;
public:
    Pet(string name, int age, float weight){
        this->name = name;
        this->age = age;
        this->weight = weight;
    }
    void eat(){
        cout << "I'm a pet and I'm hungry\n";
    }
};

class Dog: public Pet{
    bool isTrained;
public:
    Dog(string name, int age, float weight, bool trained): Pet(name, age, weight){
        isTrained = trained;
    }
    void eat(){
        cout << "I am a dog and I'm hungry\n";
    }
    string getName(){
        return name;
    }
    bool getIsTrained(){
        return isTrained;
    }
};

class Pussy: public Pet{
    int numLifes;
public:
    Pussy(string name, int age, float weight, int lifes): Pet(name, age, weight){
        numLifes = lifes;
    }
    void eat(){
        cout << "I am a cat and I'm hungry\n";
    }
    string getName(){
        return name;
    }
    int getNumLifes(){
        return numLifes;
    }
};

int main(){
    Dog d1 = Dog("snoop", 5, 12.4, false);
    Pussy p1 = Pussy("felix", 4, 8.5, 7);
    d1.eat();
    p1.eat();
    cout << d1.getName() << " isTrained=" << d1.getIsTrained() << endl;
    cout << p1.getName() << " tem " << p1.getNumLifes() << " vidas." << endl;
    return 0;
}