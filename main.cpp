#include <iostream>
#include <ctime>
#include "conio.h"
#include "windows.h"

using namespace std;

class Road
{
private:
int Length;
int Width;
char **road;
public:

Road()
{
    Length=70;
    Width=2;
}

int GetLength ()
{
return Length;
}

int GetWidth ()
{
return Width;
}

 char** GetRoad()
 {
 return road;
 }

void SetRoad()
{
    cout<<"������� ����� ����� �� 2 �� 79"<<endl;
     cin>>Length;
     if(Length<2 || Length>79)
     {
         cout<<"������ �� ������ , ������������ ������� ��������"<<endl;
         Length=79;
     }
     cout<<"�������  ������ ����� �� 2 �� 9"<<endl;
    cin>>Width;
         if(Width<2 || Width>9)
     {
         cout<<"������ �� ������ , ������������ ������� ��������"<<endl;
         Width=9;
     }
}

void BuildRoad()
{
     int n = Length - 1;
      road = new char* [Width];   // �������
  for (int i = 0; i < Width; i++) {          // ���������
    road[i] = new char [Length]; // ������
  }                                      // !

  for (int i = 0; i < Width; i++) {

    for (int j = 0; j < Length; j++) {

      int a = rand()% Length  ;
       if (a==1){
            road[i][j] = '!' ;
       }
       else {
            road[i][j] = '.' ;
       }
        road[i][n]=6;
    }
    }
}

void SetRoadManual (int Length ,int Width)
{
    int n = Length - 1;
      road = new char* [Width];   // �������
  for (int i = 0; i < Width; i++) {          // ���������
    road[i] = new char [Length]; // ������
  }                                      // !
  for (int i = 0; i < Width; i++) {
    for (int j = 0; j < Length; j++) {
      int a = rand()% Length  ;
       if (a==1){
            road[i][j] = '!' ;
       }
       else{
        road[i][j] = '.' ;
       }
        road[i][n]=6;
    }
  }
}

void ShowRoad()
{
       for (int i = 0; i < Width; i++) {
    for (int j = 0; j < Length; j++) {
    cout << road[i][j];
    }
    cout<<endl;
  }
   cout<<"------------------------------------------------"<<endl;
}

~Road()
{
    delete[] road;
cout<<"Road delete"<<endl;
}
};

class Car
{
    private:
    int Accel;
    int Handling;

public:

Car()
{
    Accel=50;
    Handling=500;
}
int GetAccel ()
{
    return Accel;
}
int GetHandling ()
{
    return Handling;
}
};

class Svetofor
{
    private:
    int RT1;
    int RT2;

public:
    Svetofor()
    {
        RT1=0;
        RT2=600;
    }

    int GetRT1()
    {
        return RT1;
    }

    int GetRT2()
    {
        return RT2;
    }

    void StartSvetofor()
    {
        cout<<"��� ������ ������� ����� ����� ������ �������� �����"<<endl;
        Sleep(1000);
    system("color 0C");//������� ����� ������� (0-������ ���; �-�������� ���)
    cout<<" ������� "<<endl;
    Sleep(3000);

    if(_kbhit())
    {
    system ( "color 07" );
        cout<<"��������� , ����� 5 ���!"<<endl;
    RT1=5000;
         }
if (RT1==0)
{
        system("color 0E");//������� ����� ������� (0-������ ���; �-�������� ���)
    cout<<" Ƹ����  "<<endl;
    Sleep(3000);

    if(_kbhit())
    {
    system ( "color 07" );
        cout<<"��������� , ����� 5 ���!"<<endl;
    RT1=5000;
         }
if (RT1==0)
{
        system("color 0A");//������� ����� ������� (0-������ ���; �-�������� ���)
    cout<<" ������ "<<endl;
}
}
int y=0;
    while(RT1==0)
    {
       Sleep(10) ;
        y+=10;
    if(_kbhit())
    {
    system ( "color 07" );
        cout<<"����� ������� ="<<y<<endl;
    RT1=y;
         }
     //   choice = _getch();
    }

    }

};

class Race : public Road , public Car , public Svetofor
{
    private:
int TrackDriver ;
int TrackOpponent ;

    public:
Race()
{
    TrackDriver=1;
    TrackOpponent=2;
}

int GetTrackDriver()
{
    return TrackDriver;
}

int GetTrackOpponent()
{
    return TrackOpponent;
}

void SetTrack()
{
     cout<<"������� ����� �������  �� 1 �� "<<GetWidth()<<endl;
 cin >>TrackDriver;
        cout<<"������� ����� ������� ��������� �� 1 �� "<<GetWidth()<<endl;
    cin >>TrackOpponent;
}
void Stage ()
{
int x=0 , ET1=0 , ET2=0 , n=0 , N=0;  //ET ������ �����
float X=0;
X=GetAccel()/10.0;
n = GetTrackDriver()-1;
N = GetTrackOpponent()-1;
  for (int z = 0; z < GetLength(); z++) {
if (GetRoad()[n][z]=='!'){
        Sleep(GetHandling());
        ET1=ET1+GetHandling();
    x=0;
  //  z++;
}
    for (int j = 0; j < GetLength(); j++) {
            GetRoad()[n][z]=2;
    cout << GetRoad()[n][j];
    }
    Sleep(400-x*X);
    ET1=ET1+(400-x*X);
    x++;

  GetRoad()[n][z]='.';

 /*   COORD position = {0,5}; //������� x � y
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsole, position);  */

cout<<"\r";
  }
int T1=ET1+GetRT1(); // ����� ����� ������� ������
cout<<endl;
cout<<"Your score-"<<T1<<endl;

    x=0;
  for (int z = 0; z < GetLength(); z++) {
if (GetRoad()[N][z]=='!'){
        Sleep(GetHandling());
        ET2=ET2+GetHandling();
    z++;
    x=0;
}

    for (int j = 0; j < GetLength(); j++) {
            GetRoad()[N][z]=1;
    cout << GetRoad()[N][j];
    }
    Sleep(400-x*X);
    ET2=ET2+(400-x*X);
    x++;

  GetRoad()[N][z]='.';

  cout<<"\r";
  }

int T2=ET2+GetRT2(); //����� ����� ������� ������
cout<<endl;
cout<<"opponent's score-"<<T2<<endl;
cout<<endl;
char D=2;
if(T1<=T2) {cout<<D<<" You're the winner ! "<<D<<endl;
Sleep(3000);}
  else {
    D--;
    cout<<D<<" You've lost ! "<<D<<endl;
    Sleep(3000);
  }
}

};

int main()
{
    setlocale(0, "");
srand( time( 0 ) );

Race a;
a.SetRoad();
a.BuildRoad();
a.ShowRoad();
a.SetTrack();
a.StartSvetofor();
a.Stage();

system("pause");
    return 0;
}
