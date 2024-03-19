#include <iostream>
#include <string>
using namespace std;

class Guitar{
    public:
        void fingerPicking();
        void strumming();
        void tunning();
        Guitar(string brand){
            this->brand = brand;
        }
        string getBrand(){
            return brand;
        }
    protected:
        string brand;
        float size;
    private:
        string shape;
        string color;
        float price;
        int numberOfStrings;

};

void Guitar::fingerPicking(){
    cout << "I'm figerpicking my guitar\n";
};

void Guitar::strumming(){
    cout << "I'm strumming my guitar\n";
};

void Guitar::tunning(){
    cout << "I'm tunning my guitar\n";
};


int main(){
    Guitar myGuitar = Guitar("Taylor");
    myGuitar.fingerPicking();
    cout << "Guitar's brand is " << myGuitar.getBrand();
    return 0;
}