#include<iostream>
using namespace std;
//抽象工厂模式将考虑多等级产品的生产，将同一个具体工厂所生产的位于不同等级的一组产品称为一个产品族，下图所示横轴是产品等级，也就是同一类产品；纵轴是产品族，也就是同一品牌的产品，同一品牌的产品产自同一个工厂。
//抽象产品接口
class AbstractProduct_A{
    public:
    virtual void use() const =0;
};

class AbstractProduct_B{
    public:
    virtual void consum() const =0;
};

//具体产品类A1
class ConcreteProduct_A1:public AbstractProduct_A{
    public:
    void use() const override{
        cout<<"正在使用具体产品A1."<<endl;
    }
};

//具体产品类A2
class ConcreteProduct_A2:public AbstractProduct_A{
    public:
    void use() const override{
        cout<<"正在使用具体产品A2."<<endl;
    }
};

//具体产品类B1
class ConcreteProduct_B1:public AbstractProduct_B{
    public:
    void consum() const override{
        cout<<"正在使用具体产品B1."<<endl;
    }
};

//具体产品类B2
class ConcreteProduct_B2:public AbstractProduct_B{
    public:
    void consum() const override{
        cout<<"正在使用具体产品B2."<<endl;
    }
};

//抽象工厂接口
class AbstractFactory{
    public:
    virtual AbstractProduct_A* createProduct_A() const = 0;
    virtual AbstractProduct_B* createProduct_B() const = 0;
};

//具体工厂类1 所有产品的等级1
//1类工厂
class ConcreteFactory_1:public AbstractFactory{
    public:
    AbstractProduct_A* createProduct_A() const override{
        return new ConcreteProduct_A1;
    }
    AbstractProduct_B* createProduct_B() const override{
        return new ConcreteProduct_B1;
    }
};

//2类工厂
class ConcreteFactory_2:public AbstractFactory{
    public:
    AbstractProduct_A* createProduct_A() const override{
        return new ConcreteProduct_A2;
    }
    AbstractProduct_B* createProduct_B() const override{
        return new ConcreteProduct_B2();
    }
};

int main()
{
    AbstractFactory* factory_1=new ConcreteFactory_1();
    AbstractFactory* factory_2=new ConcreteFactory_2();

    AbstractProduct_A* product_A1 = factory_1->createProduct_A();
    AbstractProduct_B* product_B2 = factory_2->createProduct_B();

    product_A1->use();
    product_B2->consum();

    return 0;
    
}

