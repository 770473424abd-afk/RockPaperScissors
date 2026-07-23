#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
enum EnChoices{stone=1,paper=2,scissors=3};
enum EnWinner{Player1=1,computer=2,draw=3};
struct stRoundInfo
{
    short RoundNumber=0;
    EnChoices layer1Choice;
    EnChoices computerchoice;
    EnWinner Winner ;
    string WinnerName; 

    
};
struct stGameResltsInfo
{
    short GameRound=0;
    short player1WonTimes=0;
    short computerWonTimes=0;
    short DrawTimes=0;
    EnWinner GameWinner;
    string FinalWinner="";
};
int RandomNum(int From,int To)
{
    int Random=rand()%(To-From+1)+From;
    return Random;
}
string WinnerName(EnWinner Winner)
{
    string arrWinnerName[3]={"player1","computer","No Winner"};
    return arrWinnerName[Winner-1];
}
EnWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if(RoundInfo.layer1Choice==RoundInfo.computerchoice)
    {
        return EnWinner::draw;
    }
    switch (RoundInfo.layer1Choice)
    {
    case EnChoices::stone:
    if (RoundInfo.computerchoice==EnChoices::paper)
    {
        return EnWinner::computer;
    }
        break;
        case EnChoices::paper:
    if (RoundInfo.computerchoice==EnChoices::scissors)
    {
        return EnWinner::computer;
    }
        break;
        case EnChoices::scissors:
    if (RoundInfo.computerchoice==EnChoices::stone)
    {
        return EnWinner::computer;
    }
        break;
    }
    return EnWinner::Player1;
}
string ChoicName(EnChoices Choice)
{
    string arrGameChoices[3]={"Stone","Paper","Scissors"};
    return arrGameChoices[Choice-1];
}
void SetWinnerScreenColor(EnWinner Winner)
{
    switch (Winner)
    {
    case EnWinner::Player1:
        system("color 2F"); //turn screen to green
        break;
    case EnWinner::computer:
        system("color 4F"); //turn screen to Red
        cout<<"\a";
        break;
    default:
       system("color 6F");//turn screen to yellw
        break;
    }
}
void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout<<"\n____________Round ["<<RoundInfo.RoundNumber<<"]_____________\n";
            cout<<"Player1 Choice : "<<ChoicName(RoundInfo.layer1Choice);
            cout<<endl;
            cout<<"computer Choice :"<<ChoicName(RoundInfo.computerchoice);
            cout<<endl;
            cout<<"Round Winner : ["<<RoundInfo.WinnerName<<"]\n";
            cout<<"__________________________________________"<<endl;
            SetWinnerScreenColor(RoundInfo.Winner);

}
EnWinner WhoWonTheGame(short Player1Wintimes,short computerWimtimes)
{
    if(Player1Wintimes>computerWimtimes) return EnWinner::Player1;
    else if (computerWimtimes>Player1Wintimes) return EnWinner::computer;
    else  return EnWinner::draw;
}
stGameResltsInfo FillGameResults(int GameRounds,short Player1wintimes,short computerWinTimes,short DrawTimes)
{
    stGameResltsInfo GameResults;
    GameResults.GameRound=GameRounds;
    GameResults.DrawTimes=DrawTimes;
    GameResults.computerWonTimes=computerWinTimes;
    GameResults.player1WonTimes=Player1wintimes;
    GameResults.GameWinner=WhoWonTheGame(Player1wintimes,computerWinTimes);
    GameResults.FinalWinner=WinnerName(GameResults.GameWinner);
    return GameResults;
}
EnChoices ReadPlayer1Choice()
{
    short Choice=1;
    do
    {
        cout<<"\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors ?\n";
        cin>>Choice;
    }while(Choice<1||Choice>3);
    return (EnChoices)Choice; 
}
EnChoices GetComputerChoiec()
{
    return (EnChoices) RandomNum(1,3);
}
stGameResltsInfo Playgame(short HowManyRounds)
{
    stRoundInfo RoundIfo;
    short PlayerWintimes=0, computerWimTimes=0, DrawTimes=0;
     for(short i=1;i<=HowManyRounds;i++)
    {
        cout<<"\nRound ["<<i<<"] begins:\n";
        RoundIfo.RoundNumber=i;
        RoundIfo.layer1Choice=ReadPlayer1Choice();
        RoundIfo.computerchoice=GetComputerChoiec();
        RoundIfo.Winner=WhoWonTheRound(RoundIfo);
        RoundIfo.WinnerName=WinnerName(RoundIfo.Winner);
        //Increase win/Draw counters
        if(RoundIfo.Winner==EnWinner::Player1)
           {PlayerWintimes++;}
        else if(RoundIfo.Winner==EnWinner::computer)
          { computerWimTimes++;}
        else
         { DrawTimes++;}


         PrintRoundResults(RoundIfo);
    }
    return FillGameResults(HowManyRounds,PlayerWintimes,computerWimTimes,DrawTimes);

}
string Tabs(short NumberOfTabs)
{
    string t="";
    for(int i=1;i<NumberOfTabs;i++)
    {
        t=t+"\t";
        cout<<t;
    }
    return t;
}
void ShowGameOnverScreen()
{
    cout<<Tabs(2)<<"--------------------------------------------------------------------------------------------\n\n";
    cout<<Tabs(2)<<"                                         +++G a m e O v e r +++\n";
    cout<<Tabs(2)<<"--------------------------------------------------------------------------------------------\n\n";
}
void ShowFinalGameResult(stGameResltsInfo GameResults)
{
    cout<<Tabs(2)<<"------------------------------------[Game Results ]------------------------\n\n";
    cout<<Tabs(2)<<"Game Rounds        :"<<GameResults.GameRound<<endl;
    cout<<Tabs(2)<<"Player1 Won times  :"<<GameResults.player1WonTimes<<endl;
    cout<<Tabs(2)<<"Computer won times :"<<GameResults.computerWonTimes<<endl;
    cout<<Tabs(2)<<"Draw times         :"<<GameResults.DrawTimes<<endl;
    cout<<Tabs(2)<<"Final Winner       :"<<GameResults.FinalWinner<<endl;
    cout<<Tabs(2)<<"----------------------------------------------------------------------------";
    SetWinnerScreenColor(GameResults.GameWinner);
}
short HowManyRounds()
{
    short GameRounds=1;
    do
    {
        cout<<"How Many Round 1 to 10 ? \n";
        cin>>GameRounds;
    } while(GameRounds<1||GameRounds>10);
    return GameRounds;
}
void Restscreen()
{
    system("cls");
    system("color 0F");
}
void Gamestart()
{
    
    char PlayAgain='Y';
    do
    {
    Restscreen();
    stGameResltsInfo gameResults=Playgame(HowManyRounds());
    Restscreen();
    ShowGameOnverScreen();
    ShowFinalGameResult(gameResults);
    
        
    cout<<endl<< Tabs(3)<<"Do you want to play again? [1]Yes.[2]No ?";
    cin>>PlayAgain;
    
    } while(PlayAgain=='Y'|| PlayAgain=='y');
    
    
}
int main()
{
    srand((unsigned)time(NULL));
    Gamestart();
}