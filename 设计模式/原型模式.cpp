#include<iostream>
using namespace std;

//定义抽象原型类
class Prototype{
    public:
    virtual Prototype* clone() const = 0;
    virtual void use() const = 0;
};

//具体原型类
class ConcretePrototype:public Prototype{
    public:
    Prototype* clone() const override{
     return new ConcretePrototype(*this);
    }

    void use() const override{
        std::cout<<"Using Concrete Prototype."<<endl;
    }
};

int main()
{
    Prototype* pro_1 = new ConcretePrototype();
    Prototype* clone_1 = pro_1->clone();
    clone_1->use();

    return 0;
}

