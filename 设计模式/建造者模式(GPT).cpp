#include<iostream>
using namespace std;
#include<string>
//建造者模式可以用来封装构建这些部件的过程

//部件
class CPU{
    public:
    //spec在函数内部不能被修改
    void setSpecification(const string& spec){
        specification = spec;
    }
    string getSpecification()
    {
        return this->specification;
    }
    
    private:
    string specification;
};

class Memory{
    public:
    void setCapacity(const string& cap){
        capacity=cap;
    }

    string getCapacity()const{
        return capacity;
    }
    private:
    string capacity;
};

class HardDrive{
    public:
    void setStorage(const string& storage){
        this->storage=storage;
    }

    string getStorage()const{
        return this->storage;
    }

    private:
    string storage;
};

//电脑建造者类
class ComputerBuilder{
    public:
    void buildCPU(const string& spec){
      cpu.setSpecification(spec);
    }

    void buildMemory(const string& cap){
        memory.setCapacity(cap);
    }

    void buildHardDrive(const string& storage){
        hardDrive.setStorage(storage);
    }

    //直接返回实例化的部件
    CPU getCPU() const{
        return cpu;
    }
    Memory getMemory()const{
        return memory;
    }
    HardDrive getHardDrive()const{
        return hardDrive;
    }

    private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
};

//指挥者类
class Director{
    public:
    //传入实例化的建造者
    void constructGamingComputer(ComputerBuilder& builder){
        builder.buildCPU("Intel Core i7");
        builder.buildMemory("16GB");
        builder.buildHardDrive("1TB SSD");
    }

    void constructOfficeComputer(ComputerBuilder& builder){
        builder.buildCPU("Intel Core i5");
        builder.buildMemory("8GB");
        builder.buildHardDrive("500GB HDD");
    }
};

int main(){
    ComputerBuilder builder;
    Director director;

    director.constructGamingComputer(builder);
    CPU gamingCPU=builder.getCPU();
    Memory gamingMemory=builder.getMemory();
    HardDrive gamingHardDrive=builder.getHardDrive();
    std::cout<<builder.getCPU().getSpecification()<<std::endl;
    //构建办公电脑
    director.constructOfficeComputer(builder);
    std::cout<<builder.getCPU().getSpecification()<<std::endl;

    
}

