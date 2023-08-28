#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<speaker.h>
//演讲管理类
class SpeechManager
{
    public:
    //构造函数
    SpeechManager();

    //初始化创建12名选手
    void createSpeaker();

    //开始比赛 - 比赛流程控制
    void startSpeech();

    //比赛
    void speechContest();

    //抽签
    void speechDraw();

    //显示比赛结果
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
    void loadRecord();
    //文件为空的标注
    bool fileIsEmpty;
    //往届记录 注意这里是string
    //届数，分数
    map<int,vector<string>>m_Record;

    //显示往届得分
    void showRecord();

    //展示菜单
    void show_Menu();

    //退出
    void exitSystem();

    //析构函数
    ~SpeechManager();

    //比赛选手容器 12人
    vector<int>v1;
    //第一轮晋级容器 6人
    vector<int>v2;
    //胜利前三名容器 3人
    vector<int>vVictory;

    //存放编号 以及对应的 具体选手 容器
    map<int,Speaker>m_Speaker;

    //轮数
    int m_index;

    //6.3.2初始化属性
    void initSpeech();
};