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
string v = "[beta0.2](C++����)";
void game() {  
    string gameopen;  
    cout << "Ŀǰ����Ϸdu��С��Ϸ(����˹���̶�)(��Ȩ��ϵ����ɾ)����money����" << endl << "������������������Ϸ��";  
    cin >> gameopen;  
  
    if (gameopen == "money") {  
        char currentDir[MAX_PATH];  
        if (GetCurrentDirectory(MAX_PATH, currentDir)) {  
            string fullPath = string(currentDir) + "\\game\\money.exe";
            string command = "start \"\" \"" + fullPath + "\"";  
            system(command.c_str());  
        } else {  
            cerr << "�޷���ȡ��ǰ����Ŀ¼��" << endl;  
        }  
    } else {  
        cout << "δʶ�����Ϸѡ�" << endl;  
    }  
} 

void openn()
{
    cout << "������Ҫ���ļ��ľ���·��:";
    cin >> ysqd;
    ysqd = "start "" " +ysqd;
    system(ysqd.c_str());
}
void ping()
{
    cout << "������Ҫ���Ե�����:";
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
        cerr << "�޷����û����ļ���" << endl;
        return;
    }
    cout << "��ǰ���û�����: " << oldUsername << endl;
    cout << "�������µ��û���: ";
    cin >> newUsername;
    if (outputFile.is_open())
    {
        outputFile << newUsername;
        outputFile.close();
    }
    else
    {
        cerr << "�޷�������ʱ�ļ���д�����û�����" << endl;
        return;
    }
    remove("username");
    rename("username.tmp", "username");

    cout << "�û����Ѹ���Ϊ: " << newUsername << endl;
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
        cout << "�㻹û������������֣�������:";
        cin >> username;

        ofstream outputFile("username");

        if (outputFile.is_open())
        {
            outputFile << username;
            outputFile.close();
        }
        else
        {
            cerr << "�޷����ļ���д���û�����" << endl;
        }
    }
}
void coutcommand()
{
    cout << "command(��ȡ����)" << endl
         << "exit(��ȫ�ر�Cmd++)" << endl
         << "rename(��������)" << endl
         << "version(��ȡ�汾��)" << endl
         << "compute(������)" << endl
         << "ping(���Ե�ǰ����������ip/������������)" << endl
         << "open(���κ����͵��ļ�(��Ҫ�����ո�������),������˲���������Ų�����)" << endl
         << "game(���Դ���С��Ϸ)" << endl;
}
void cmdexit()
{
    cout << "ȷ�Ϲر�Cmd++��?[y/n](Сд):";
    cin >> exityn;
    if (exityn == "y")
    {
        cout << "bye!~";
        isexit = true;
    }
    else
    {
        cout << "ȡ���ر�" << endl;
    }
}
int main()
{
    system("chcp 936");
    system("cls");
    if (open == false)
    {
        cout << "Cmd++" << v << endl
             << "������:�������������Ȩ����" << endl
             << "ʹ��command��ȡ����..." << endl
             << "ע�⣡��ǰ�汾�޷��Զ����£�������ǰ��������" << endl
             << "yeecraftteam.cn/cmdjiajia���°汾!" << endl;
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
            cout << "û�д˹��ܣ�������command�˶�" << endl;
        }
    }
    return 0;
}