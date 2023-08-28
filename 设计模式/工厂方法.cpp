#include<iostream>
using namespace std;

//基础产品类Product
class Product{
    public:
    //成员函数后加const-常函数 不可以修改成员属性
    virtual void use() const = 0;
};

class ConcreteProductA:public Product{
    public:
    void use() const override{
        std::cout<<"Using Concrete Product A."<<std::endl;
    }
};

class ConcreteProductB:public Product{
    public:
    void use() const override{
        std::cout<<"Using Concrete Product B."<<std::endl;
    }
};

//定义一个抽象工厂类Factory,由其子类实现具体产品的创建
class Factory{
    public:
    virtual Product* createProduct() const = 0;
};

//创建具体工厂类
class ConcreteFactoryA:public Factory{
    public:
    Product* createProduct() const override{
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB:public Factory{
    public:
    Product* createProduct() const override{
        return new ConcreteProductB();
    }
};

//使用工厂方法
int main(){
    //实例化工厂A
    Factory* factoryA = new ConcreteFactoryA();
    Product* productA = factoryA->createProduct();
    productA->use();

    delete factoryA;
    delete productA;

    return 0;
}