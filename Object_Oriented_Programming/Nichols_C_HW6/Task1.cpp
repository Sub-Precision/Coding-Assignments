#include <iostream>
using namespace std;
class Base{
    public:
    Base();
    virtual void testFunction (); //1 of 2 differences needed
    int get_x();
    void set_x(int x);
    private:
    int x;
};
class Derived : public Base{
    public:
    Derived();
    void testFunction (); //2 of 2 differences needed
    private:
    int x;
};
Base::Base() : x(0){}
int Base::get_x(){
    return this->x;
}
void Base::set_x(int x){
    this->x = x;
}
void Base::testFunction (){
    cout << "I am Mr. Base." << endl;
}
Derived::Derived(): Base(), x(0){}
void Derived::testFunction(){
    cout << "I am Mr. Derived." << endl;
}
int main(){
    Base* ptr = new Base;
    ptr -> testFunction ();
    delete ptr;
    ptr = new Derived;
    ptr -> testFunction ();
    delete ptr;
    return 0;
}