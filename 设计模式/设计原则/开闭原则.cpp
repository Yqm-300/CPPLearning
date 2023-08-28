#include<iostream>
using namespace std;

class Skin
{
    public:

  virtual void display()=0;
};

class DefaultSpecificSkin:public Skin
{
  void display()
  {
    cout<<"正在使用默认皮肤"<<endl;
  };
  
};

class HeimaSpecificSkin:public Skin
{
  void display()
  {
    cout<<"正在使用黑马皮肤"<<endl;
  };
  
};

class SougouInput
{
  public:
  
  Skin *AbstractSkin;
  
  void display()
  {
    this->AbstractSkin->display();
    
  };

  void setSkin(Skin *skin)
  {
    this->AbstractSkin = skin;
  }
};

//测试类
class Client
{
  public:

  static void test(string args)
  {
    //创建搜狗输入法对象
    SougouInput *input=new SougouInput();
    //创建皮肤对象
    DefaultSpecificSkin *skin=new DefaultSpecificSkin();
    //将皮肤设置到输入法中
    input->setSkin(skin);
    //显示皮肤
    input->display();

  }
};

int main()
{   
    string str="ass";
    Client client;
    client.test(str);

    return 0;
}