#include<iostream>
#include<string>
using namespace std;

//自行车类
class Bike{
    private:
    std::string frame;
    std::string seat;

    public:
    std::string getFrame()const{
        return this->frame;
    }

    void setFrame(const std::string& frame){
        this->frame=frame;
    }

    std::string getSeat()const{
        return this->seat;
    }

    void setSeat(const string& seat){
        this->seat=seat;
    }
};

//抽象Builder类
class Builder{
    protected://子类可访问
    Bike mBike;

    public:
    virtual void buildFrame()=0;
    virtual void buildSeat()=0;
    virtual Bike createBike()=0;
};

//摩拜单车builder类
class MobikeBuilder:public Builder{
    public:
    void buildFrame() override{
        mBike.setFrame("铝合金车架 ");
    }

    void buildSeat() override{
        mBike.setSeat("真皮车座");
    }

    Bike createBike()override{
        return this->mBike;
    }
};

//ofo
class OfoBuilder:public Builder{
    public:
    void buildFrame()override{
        mBike.setFrame("碳纤维车架");
    }
    void buildSeat()override{
        mBike.setSeat("橡胶车座");
    }

    Bike createBike()override{
        return this->mBike;
    }
};

//指挥者类
class Director{
    private:
    Builder* mBuilder;

    public:
    Director(Builder* builder):mBuilder(builder){}

    Bike construct(){
        mBuilder->buildFrame();
        mBuilder->buildSeat();
        return mBuilder->createBike();
    }

};

int main(){
    Director director(new MobikeBuilder);
    Bike mobike_1 = director.construct();

    director=Director(new OfoBuilder());
    Bike ofobike_1 = director.construct();
}