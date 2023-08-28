#include<iostream>
using namespace std;

//单例模式
class Singleton
{
    private:
    Singleton();
    Singleton(const Singleton& other);

    public:
    static Singleton* getInstance();
    static Singleton* m_Instance;
};

Singleton* Singleton::m_Instance=NULL;

//线程非安全版本
Singleton* Singleton::getInstance()//用静态getInstance函数调用构造函数
{
  if(m_Instance==NULL) m_Instance=new Singleton();
  return m_Instance;
}

//线程安全版本，但锁的代价过高 在高并发的时候
//当创建完后🔒还在，只需要return m_Instance不需要加锁
Singleton* Singleton::getInstance()
{
  //对这个方法全局加锁，29-31行 执行完31行后释放
  Lock lock;
  if(m_Instance==NULL) m_Instance=new Singleton();
  return m_Instance;
}

//双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance()
{
    if(m_Instance==NULL)//没创建才加锁 为了只读操作
    {
        Lock lock;
        if(m_Instance==NULL)//避免同时进38行
        {
            m_Instance=new Singleton();
        }   
    }
    return m_Instance;

    
}





