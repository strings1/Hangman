#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <ctime>
using namespace std;
char a[2]="1";
ifstream f("cuvine.in");
void menu();
void start();
int main()
{ char a;
    while(true)
    {
    menu();
    start();
    cout<<endl<<"Wanna try again? Y/N"<<endl;
    cin>>a;
    if(a!='y')
        break;

    }

}
void hangman_ascii(int n)
{

    switch(n)
    {
    case 0:
        {
            system("CLS");
            cout<<",---| "<<endl;
        cout<<"|     "<<endl; //head
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"L_____"<<endl;
        break;
        }
    case 1:
    {            system("CLS");

        cout<<",---| "<<endl;
        cout<<"|  ( )"<<endl; //head
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"L_____"<<endl;
        break;
    }
    case 2:
    {            system("CLS");

        cout<<",---| "<<endl;
        cout<<"|  ( )"<<endl; //head
        cout<<"|   | "<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"L_____"<<endl;
        break;
    }
    case 3:
    {            system("CLS");

        cout<<",---| "<<endl;
        cout<<"|  ( )"<<endl; //head
        cout<<"|  /|\\"<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"|     "<<endl;
        cout<<"L_____"<<endl;
        break;
    }
    case 4:
    {            system("CLS");

        cout<<",---| "<<endl;
        cout<<"|  ( )"<<endl; //head
        cout<<"|  /|\\"<<endl;
        cout<<"|   ^ "<<endl;
        cout<<"|  / \\"<<endl;
        cout<<"|     "<<endl;
        cout<<"L_____"<<endl;
        break;
    }
    case 5:
    {            system("CLS");

        cout<<",---| "<<endl;
        cout<<"|  (!)"<<endl; //head
        cout<<"|  /|\\"<<endl;
        cout<<"|   ^ "<<endl;
        cout<<"|  | |"<<endl;
        cout<<"|     "<<endl;
        cout<<"L_____"<<endl;
        break;

    }
    case 6:
        {
              system("CLS");

        cout<<",---| "<<endl;
        cout<<"|  (X)"<<endl; //head
        cout<<"|  /|\\"<<endl;
        cout<<"|   ^ "<<endl;
        cout<<"|  | |"<<endl;
        cout<<"|     "<<endl;
        cout<<"L_____"<<endl;
        break;
        }

    }
}
void menu()
{
    cout<<"Press X to start"<<endl;
}

void start()
{
    char aux[50];
    int v[50]={0};
    int i;

    while(!(a[0]=='X' || a[0]=='x'))
    {
        cin.getline(a,2);
        if(!(a[0]=='X' || a[0]=='x'))
        {
            cout<<"Unknown Command";
            Sleep(1000);
            system("CLS");
            menu();
        }
    }
    cout<<"I am going to pick a word for you now,"<<endl<<"please wait.";

    Sleep(300);
    cout<<".";
    Sleep(300);
    cout<<".";
    Sleep(500);

    srand((int)time(0));
    int random=rand()%447+1;
    system("CLS");
    cout<<"Okay, let's start!"<<endl;
   cout<<random<<endl;
   //Game Start (RANDOM SELECTOR + CLEANING ARRAY)
    while(random--)
        f>>aux;

    int health=0;
    bool sw=0;
    bool win=0;
    while (health!=6)
    {   sw=1;
        win=1;
        hangman_ascii(health);
        for(i=0;i<strlen(aux);i++)
        {
            if(v[i]==0)
                cout<<"[?]";
            else cout<<(char)(aux[i]-32);
        }
        cout<<endl;
        cin.getline(a,2);
        for(i=0;i<strlen(aux);i++)
        {
            if(a[0]==aux[i])
            {
                v[i]++;
                sw=0;
            }
            if(v[i]==0)
            {
                win=0;
            }
        }
        if(sw)
            health++;
            if(win)
                { hangman_ascii(health);

                for(i=0;i<strlen(aux);i++)
        {
            if(v[i]==0)
                cout<<"_";
            else cout<<(char)(aux[i]-32);
        }
                    cout<<endl<<"YOU WON";break;}
    }
    if(health==6)
    {hangman_ascii(health);
cout<<"GAME OVER"<<endl<<"The word was:  "<<aux;}


}
