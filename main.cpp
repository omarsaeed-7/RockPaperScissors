#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

string getComputerChoice()
{
    string choices[]={"rock","paper","scissor"};
    int index = rand()%3;
    return choices[index];
}
string mapCharToChoice(char c)
{
    c=tolower(c);
    if(c=='r')
    {
        return "rock";
    }
    else if (c=='p')
    {
        return "paper";
    }
    else if(c=='s')
    {
        return "scissor";
    }
    else 
    {
        return "";
    }
}
string determineWinner(string player ,string computer)
{
    if(player==computer)
    {
        return "tie";
    }
    if((player=="rock"&&computer=="scissor")
    (player=="paper"&&computer=="rock")
    (player=="scissor"&&computer=="paper"))
    {
        return "player";
    }
    else
    {
        return "computer";
    }
}
string getResult(string winner,int& playerscore,int& computerscore)
{
   if(winner=="tie")
   {
    return "It's tie";
   } 
   else if(winner=="player")
   {
    playerscore++;
    return "You win";
   }
   else
   {
    computerscore++;
    return "You lose";
   };
}

int main ()
{
    int playerscore,computerscore;
    int rounds;
    string playerChoice,computerChoice;
    char playerchar;
    cout<<"welcome to Rock Paper Scissor Game"<<endl;
    cout<<"enter r for rock p for paper s for scissor"<<endl;
    cout<<"How many rounds you want?";
    cin>>rounds;
    for(int i=1;i<=rounds;i++)
    {
        cout<<"Rounds"<<i<<endl;
        cout<<"Enter choice [r/p/s]:";
        cin>>playerchar;
        playerChoice=mapCharToChoice(playerchar);
        if(playerChoice == "")
        {
            cout<<"Invalid Input . please Enter [r/p/s]"<<endl;
        }
        while(playerChoice == "" );
        computerChoice=getComputerChoice();
        cout<<"Computer Chose :"<<endl;
        string winner = determineWinner(playerChoice,computerChoice);
        string result = getResult(winner,playerscore,computerscore);
        cout<<result;
        cout<< "Your Score:"<<playerscore<<endl;
        cout<< "Computer Score:"<<computerscore<<endl;  
    }
    cout<<"Game Over"<<endl;
    cout<<"Your Score:"<<playerscore<<endl;
    cout<<"Computer Score:"<<computerscore<<endl;
    if(playerscore > computerscore)
    {
        cout<<"You Win!";
    }
    else if(playerscore < computerscore )
    {
        cout<<"You Lose";
    }
    else
    {
        cout<<"It's Tie";
    }



   
return 0;     

}
