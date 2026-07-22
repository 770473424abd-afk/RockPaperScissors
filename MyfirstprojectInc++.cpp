#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
int read(string Message)
{
    int num;
    cout<<Message<<endl;
    cin>>num;
    return num;
}
int RandomNum(int From,int To)
{
    int Random=rand()%(To-From+1)+From;
    return Random;
}
enum EnChoices{stone=1,paper=2,scissors=3};
string compare(int num)
{
    switch (num)
    {
    case EnChoices::paper:
    return "Paper";
        break;
    case EnChoices::scissors:
     return "scissors";
     break;
    case EnChoices::stone:
    return "Stone";
    break;       
    }
}
void CompareChoices(int UserChoice,int computerChoice)
{
    if(UserChoice!=computerChoice)
    {
        if(UserChoice==1&&computerChoice==2)
         {cout<<"Round winner : [Computer]";
            system("color 4F");
         }
         else if(UserChoice==1&&computerChoice==3)
         {cout<<"Round winner : [Player1]";
            system("color 2F");
            Beep(800,200);
         }
         else if (UserChoice==2&&computerChoice==1)
         {cout<<"Round winner : [Player1]";
            system("color 2F");
            Beep(800,200);
         }
         else if (UserChoice==2&&computerChoice==3)
         {cout<<"Round winner : [Computer]";
            system("color 4F");
         }
         else if(UserChoice==3&&computerChoice==1)
        {cout<<"Round winner : [Computer]";
            system("color 4F");
         }
         else if (UserChoice==3&&computerChoice==2)
          {cout<<"Round winner : [Player1]";
            system("color 2F");
            Beep(800,200);
         }
    }
    else
    {
    cout<<"Round winner : [No Winner]";
    system("color 6F");
    }
    
}

void Gamestart()
{
   
    int userChoice;
    int round=read("Hou Many Rounds 1 to 10 ?");
    for(int i=1;i<=round;i++)
    {
        cout<<"\nRound ["<<i<<"] begins:\n";
        cout<<"\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors ?\n";
        cin>>userChoice;
        int competerChoice=RandomNum(1,3);
        
            cout<<"\n____________Round ["<<i<<"]_____________\n";
            cout<<"Player1 Choice : "<<compare(userChoice);
            cout<<endl;
            cout<<"computer Choice :"<<compare(competerChoice);
            cout<<endl;
            CompareChoices(userChoice,competerChoice);
            cout<<endl;
            cout<<"__________________________________________";
    }
    int GameAgain=read("Do you want to play again? [1]Yes.[2]No ?");
    if(GameAgain==1)
    {
        Gamestart();
    }

}
int main()
{
    srand((unsigned)time(NULL));
    Gamestart();
}