#include <iostream>
using namespace std;
class Mammal
{
      public:
            Mammal(void);
            ~Mammal(void);

            virtual void Move() const;
            virtual void Speak() const;

      protected:
            int itsAge;
};
Mammal::Mammal(void) :itsAge(1) {
    cout << "Mammal constructor..." << endl;
}

Mammal::~Mammal(void) {
    cout << "Mammal destructor..." << endl;
}

void Mammal::Move() const {
    cout << "Mammal moves a step!" << endl;
}

void Mammal::Speak() const {
    cout << "What does a mammal speak? Mammilian!" << endl;
}
class Dog : public Mammal
{
public:
    Dog(void);
    ~Dog(void);

    virtual void Move() const;
    virtual void Speak() const;

protected:
    int itsAge;
};
Dog::Dog(void) :itsAge(1) {
    cout << "Dog constructor..." << endl;
}

Dog::~Dog(void) {
    cout << "Dog destructor..." << endl;
}

void Dog::Move() const {
    cout << "Dog moves a step!" << endl;
}

void Dog::Speak() const {
    cout << "Hoof Hoof!" << endl;
}

class Cat : public Mammal{
      public:
            Cat(void);
            ~Cat(void);

            virtual void Move() const;
            virtual void Speak() const;

      protected:
            int itsAge;
};

Cat::Cat(void):itsAge(1){
      cout << "Cat constructor..." << endl;
}
Cat::~Cat(void){
      cout << "Cat destructor..." << endl;
}
void Cat::Move() const{
      cout << "Cat moves a step!" << endl;
}
void Cat::Speak() const{
      cout << "Meow Meow!" << endl;
}
class Horse : public Mammal{
      public:
            Horse(void);
            ~Horse(void);

            virtual void Move() const;
            virtual void Speak() const;

      protected:
            int itsAge;
};
Horse::Horse(void):itsAge(1){
      cout << "Horse constructor..." << endl;
}
Horse::~Horse(void){
      cout << "Horse destructor..." << endl;
}
void Horse::Move() const{
      cout << "Horse moves a step!" << endl;
}
void Horse::Speak() const{
      cout << "Neigh Neigh!" << endl;
}
class GuineaPig : public Mammal{
      public:
            GuineaPig(void);
            ~GuineaPig(void);

            virtual void Move() const;
            virtual void Speak() const;

      protected:
            int itsAge;
};
GuineaPig::GuineaPig(void):itsAge(1){
      cout << "GuineaPig constructor..." << endl;
}
GuineaPig::~GuineaPig(void){
      cout << "GuineaPig destructor..." << endl;
}
void GuineaPig::Move() const{
      cout << "GuineaPig moves a step!" << endl;
}
void GuineaPig::Speak() const{
      cout << "Weep Weep!" << endl;
}
int main (){
   Mammal* theArray[5];
   Mammal* ptr;
   int choice, i;
   for (i = 0; i<5; i++){
      cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
      cin >> choice;
      switch (choice){
         case 1: ptr = new Dog; break;
         case 2: ptr = new Cat; break;
         case 3: ptr = new Horse; break;
         case 4: ptr = new GuineaPig; break;
         default: ptr = new Mammal; break;
      }
      theArray[i] = ptr;
   }
   for (i=0; i<5; i++)
      theArray[i]->Speak();

   for (i=0; i<5; i++)
        delete theArray[i];
   return 0;
}