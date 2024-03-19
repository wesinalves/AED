#include <iostream>
#include <string>
using namespace std;

class Guitar{
    public:
        void fingerPicking();
        void strumming();
        void tunning();
        Guitar(float price){
            this->price = price;
        };
        string getPrice(){
            return to_string(price) + "\n";
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
    Guitar myGuitar = Guitar(1200);
    cout << myGuitar.getPrice();
    myGuitar.tunning();
    myGuitar.strumming();
    return 0;
}