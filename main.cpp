#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
bool open = false;
bool isexit = false;
string username = "";
string exityn = "";
string command = "";
string pingg = "";
string ysqd = "";
string gameopen = "";
string v = "[beta0.2](C++开发)";
void game() {  
    string gameopen;  
    cout << "目前有游戏du狗小游戏(俄罗斯轮盘赌)(侵权联系立马删)输入money启动" << endl << "请输入你想启动的游戏：";  
    cin >> gameopen;  
  
    if (gameopen == "money") {  
        char currentDir[MAX_PATH];  
        if (GetCurrentDirectory(MAX_PATH, currentDir)) {  
            string fullPath = string(currentDir) + "\\game\\money.exe";
            string command = "start \"\" \"" + fullPath + "\"";  
            system(command.c_str());  
        } else {  
            cerr << "无法获取当前工作目录。" << endl;  
        }  
    } else {  
        cout << "未识别的游戏选项。" << endl;  
    }  
} 

void openn()
{
    cout << "请输入要打开文件的绝对路径:";
    cin >> ysqd;
    ysqd = "start "" " +ysqd;
    system(ysqd.c_str());
}
void ping()
{
    cout << "请输入要测试的域名:";
    cin >> pingg;
    pingg = "ping " + pingg;
    system(pingg.c_str());
}
void compute()
{
    system("calc");
}
void version()
{
    cout << v << endl;
}
void renameuser()
{
    string oldUsername, newUsername;
    ifstream inputFile("username");
    ofstream outputFile("username.tmp");

    if (inputFile.is_open())
    {
        getline(inputFile, oldUsername);
        inputFile.close();
    }
    else
    {
        cerr << "无法打开用户名文件！" << endl;
        return;
    }
    cout << "当前的用户名是: " << oldUsername << endl;
    cout << "请输入新的用户名: ";
    cin >> newUsername;
    if (outputFile.is_open())
    {
        outputFile << newUsername;
        outputFile.close();
    }
    else
    {
        cerr << "无法创建临时文件以写入新用户名！" << endl;
        return;
    }
    remove("username");
    rename("username.tmp", "username");

    cout << "用户名已更新为: " << newUsername << endl;
}
void usernamevoid()
{
    ifstream inputFile("username");
    if (inputFile.is_open())
    {
        getline(inputFile, username);
        inputFile.close();
    }
    if (username.empty())
    {
        cout << "你还没有设置你的名字！请输入:";
        cin >> username;

        ofstream outputFile("username");

        if (outputFile.is_open())
        {
            outputFile << username;
            outputFile.close();
        }
        else
        {
            cerr << "无法打开文件以写入用户名！" << endl;
        }
    }
}
void coutcommand()
{
    cout << "command(获取命令)" << endl
         << "exit(安全关闭Cmd++)" << endl
         << "rename(重置名字)" << endl
         << "version(获取版本号)" << endl
         << "compute(计算器)" << endl
         << "ping(测试当前计算机与测试ip/域名的连接性)" << endl
         << "open(打开任何类型的文件(不要包含空格与中文),如果打开了病毒该软件概不负责)" << endl
         << "game(打开自带的小游戏)" << endl;
}
void cmdexit()
{
    cout << "确认关闭Cmd++吗?[y/n](小写):";
    cin >> exityn;
    if (exityn == "y")
    {
        cout << "bye!~";
        isexit = true;
    }
    else
    {
        cout << "取消关闭" << endl;
    }
}
int main()
{
    system("chcp 936");
    system("cls");
    if (open == false)
    {
        cout << "Cmd++" << v << endl
             << "制作人:虫二。保留所有权利。" << endl
             << "使用command获取命令..." << endl
             << "注意！当前版本无法自动更新，请自行前往官网：" << endl
             << "yeecraftteam.cn/cmdjiajia更新版本!" << endl;
        open = true;
    }
    while (open)
    {
        usernamevoid();
        cout << "Users/" + username + ">>";
        cin >> command;
        if (command == "exit")
        {
            cmdexit();
            if (isexit)
            {
                return 0;
            }
        }
        else if (command == "command")
        {
            coutcommand();
        }
        else if (command == "rename")
        {
            renameuser();
        }
        else if (command == "version")
        {
            version();
        }
        else if (command == "compute")
        {
            compute();
        }
        else if (command == "ping")
        {
            ping();
        }
        else if (command == "open")
        {
            openn();
        }
        else if (command == "game"){
            game();
        }
        else
        {
            cout << "没有此功能，请输入command核对" << endl;
        }
    }
    return 0;
}