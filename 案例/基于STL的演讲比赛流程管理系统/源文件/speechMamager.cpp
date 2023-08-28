#include"speechManager.h"
#include<algorithm>
#include<random>
#include<deque>
#include<fstream>

//ctrl+k+0/j  折叠/展开所有代码
//ctrl+k+[/]  折叠/展开选中代码

SpeechManager::SpeechManager()
{
  //在SpeechManager构造函数中调用初始化函数void initSpeech();
  //初始化属性
  this->initSpeech();

  //初始化选手
  this->createSpeaker();
}

void SpeechManager::createSpeaker()
{
	string nameSeed="ABCDEFGHIJKL";
   for(int i=0;i<nameSeed.size();i++)
   {
	string name="选手";
	name+=nameSeed[i];
	Speaker sp;
	sp.m_Name=name;
	for(int i=0;i<2;i++)
	{
		sp.m_Score[i]=0;
	}

    this->v1.push_back(i+10001);

	//选手编号以及对应的选手 存放到map容器中
	this->m_Speaker.insert(make_pair(i+10001,sp));

   }
}

void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	speechDraw();
	//2、比赛
    speechContest();
	//3、显示晋级结果
    showScore();
	//第二轮比赛
    this->m_index++;
	//1、抽签
    speechDraw();
	//2、比赛
    speechContest();
	//3、显示最终结果
    showScore();
	//4、保存分数	
	saveRecord();
	//5、读取分数
	loadRecord();
	//6、显示往届得分
	showRecord();


}

void SpeechManager::speechContest()
{
	cout<<"---------第"<<this->m_index<<"轮比赛正式开始-------"<<endl;

    //允许一个key对不同的value
	//key分数  value选手编号
	//降序排列
	multimap<double,int,greater<double>>groupScore;
    
    int num=0;//记录人员数，6个为一组

	vector<int>v_Src;//比赛的人员容器
	if(this->m_index==1) v_Src=v1;
	else v_Src=v2;

    //遍历所有参赛选手
	for(vector<int>::iterator it=v_Src.begin();it!=v_Src.end();it++)
	{
        
		num++;

		//评委打分
		deque<double>d;
		for(int i=0;i<10;i++)//10个评委打分
		{
		//代码的目的是生成一个随机的分数，范围在60到100之间，精确到小数点后一位
          double score =(rand()%401+600)/10.f;//600~100
		  d.push_back(score);

		}

		//排序 从大到小排 默认是从小到大 内建函数对象
		sort(d.begin(),d.end(),greater<double>());
		d.pop_front();
		d.pop_back();

        //总分 0.0f让总分变成浮点数
		double sum=accumulate(d.begin(),d.end(),0.0f);
		double avg=sum/(double)d.size();//类型转换

		//保存每个人的平均分
		this->m_Speaker[*it].m_Score[this->m_index-1]=avg;

		//6个人一组，用临时容器保存
		groupScore.insert(make_pair(avg,*it));

		if(num%6==0)
		{
          cout<<"第"<<num/6<<"组比赛名次："<<endl;
		  for(multimap<double,int,greater<double>>::iterator it=groupScore.begin();it!=groupScore.end();it++)
		  {
			cout<<"编号："<<it->second<<"姓名："<<this->m_Speaker[it->second].m_Name
			<<"成绩："<<this->m_Speaker[it->second].m_Score[this->m_index-1]<<endl;

		  }

           int count=0;
		   //取前三
		   for(multimap<double,int,greater<double>>::iterator it=groupScore.begin();it!=groupScore.end()&&count<3;it++,count++)
		   {
            if(this->m_index==1) v2.push_back((*it).second);
			else vVictory.push_back((*it).second);
		   }

		   groupScore.clear();

		   cout<<endl;
		   cout<<"-----"<<this->m_index<<"轮比赛完毕------"<<endl;
		   system("pause");

		}



	}
	


}

void SpeechManager::speechDraw()
{
	cout<<"第"<<this->m_index<<"轮选手正在抽签"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"抽签后演讲顺序如下："<<endl;

    //使用随机数引擎 一个真实的硬件随机数生成器
	std::random_device rd;
	//mt19937是一个伪随机数生成器类
	//这是一个构造函数 传入rd
	//将真实的随机设备连接到mt19937生成器以提供更好的随机性
	std::mt19937 generator(rd());

	if(this->m_index==1)
	{
		std::shuffle(v1.begin(),v1.end(),generator);
		
		for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
		{
			cout<<*it<<" ";

		}
		cout<<endl;

	}
	else
	{
        std::shuffle(v2.begin(),v2.end(),generator);
        for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;


	}
	cout<<"------------------"<<endl;
	system("pause");
	cout<<endl;
}

void SpeechManager::showScore()
{
	cout<<"---------第"<<this->m_index<<"轮晋级选手信息如下："<<endl;
	vector<int>v;
	if(this->m_index==1) v=v2;
	else v=vVictory;

	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<"选手编号："<<*it<<" 姓名："<<this->m_Speaker[*it].m_Name
		<<" 得分："<<this->m_Speaker[*it].m_Score[this->m_index-1]<<endl;

	}
	cout<<endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::saveRecord()
{
  //创建写文件流对象
  ofstream ofs;
  ofs.open("speech.csv",ios::out|ios::app);//out为写文件而打开文件，app追加方式写文件

  for(vector<int>::iterator it=vVictory.begin();it!=vVictory.end();it++)
  {
	ofs<<*it<<","<<this->m_Speaker[*it].m_Score[1]<<",";
  }
  ofs<<endl;

  ofs.close();

  cout<<"记录已保存"<<endl;

}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in);
    
	//判断文件是否存在 
	if(!ifs.is_open())
	{
		this->fileIsEmpty=true;
		cout<<"文件不存在！"<<endl;
		ifs.close();
		return;
	}
	
    //判断文件是否为空
	char ch;
	ifs>>ch;//读取一个字符保存在ch中
    if(ifs.eof())//是否读到文件末尾 若返回false则还有数据可读
	{
		cout<<"文件为空！"<<endl;
		this->fileIsEmpty=true;
		ifs.close();
		return;
	}
    
	//文件不为空
	this->fileIsEmpty=false;
	ifs.putback(ch);//读取的单个字符放回去

	string data;
    int index=1;

	while (ifs>>data)//逐行读取数据
	{
		cout<<"data"<<endl;
		//10002,86.675,10009,81.3,10007,78.55,

        vector<string>v;//存放6个分离的string的字符串
        int pos = -1;//查到“，”位置的变量
		int start = 0;//起始位置

        while(true)
		{
		pos=data.find(",",start);//从start开始找，

		if(pos==-1) break;

		string temp = data.substr(start,pos-start);
        
		v.push_back(temp);

		start = pos+1;

		}
        
        this->m_Record.insert(make_pair(index,v));
		v.clear();
		index++;
	}
	ifs.close();


	



    


}

void SpeechManager::showRecord()
{
	for(int i=1;i<this->m_Record.size()+1;i++)
	{
		cout<<"第"<<i<<"届"<<
		"冠军编号："<<this->m_Record[i][0]<<"得分："<<this->m_Record[i][1]<<endl;


	}
}

void SpeechManager::show_Menu()
{
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout<<"欢迎下次使用"<<endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}

//初始化属性
void SpeechManager::initSpeech()
{
	//保证容器为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//初始化比赛轮数
	this->m_index = 1;
}