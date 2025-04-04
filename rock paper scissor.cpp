#include <iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
enum enchoice {rock=1,paper, scissor};


int readnum(string message){
  int n;
  cout<<message <<endl;
  cin>>n;
  return n;
}

short random (int to, int from){
  int randomnum=to+rand()%(from-to+1);
  return randomnum;
}




enchoice userchoice(){
  int c;
  cout <<" what is your choice\n [1]: for rock\n[2]: for paper\n[3]: for scissor :";
  cin>>c;
  if (c>3||c<1)
  return userchoice();
  else
  return static_cast<enchoice>(c);
}

enchoice computerchoice()
{
  cout <<" computer's choice is: ";
return static_cast<enchoice>(random(1,3));
}



void displaychoice (enchoice choice)
 {
  switch (choice){
    case rock: cout<<"rock"; break;
    case paper: cout<<"paper "; break;
    case scissor: cout<<"scissor";
                        break;
  }

}




  void winner(enchoice userchoice,enchoice computerchoice, int &userc,int &computerc,int &drawc){



    if((userchoice==scissor&& computerchoice==paper)||(userchoice==paper&&computerchoice==rock)||(userchoice==rock&& computerchoice==scissor))
{
    cout<<"you!\n ";
   userc++;
   system("color A7");

    }
    else if(userchoice==computerchoice)
{
cout<<"no one win\n ";
drawc++;
system("color 67");

 }
else {
cout<<"computer\n";
computerc ++;
system("color 47");

       }
  }
 void displaygame(int n, int userwin,int cowin,int drawtime){
   cout<<"\t_______\n";
   cout<<"\t\tGAME OVER\n  ";

 cout<<"\t_______\n";
 cout<<"\t__ RESULTS____\n";
 cout<<"\trounds  :   "<<"\t\t"<<n<<endl;
 cout<<"\tuser win  :   "<<"\t\t"<<userwin<<endl;
 cout<<"\tcomputer win  :   "<<"\t"<<cowin<<endl;
 cout<<"\tdraw times  :   "<<"\t"<<drawtime<<endl;

 if(cowin>userwin)
 cout<<"\tfinal winner  :\t \tcomputer"<<endl;
 else if(userwin>cowin)
 cout<<"\tfinal winner  :\t\tuser"<<endl;
 else

 cout<<"\tfinal winner  :\t\tno one"<<endl;
 cout<<"\t_______\n";
 }

 void resetscreen(){
 system("color 0F");
 system("cls");
 }

       void rounds(int n)
       {
         int counter=0;
           int userc=0, computerc=0,drawc=0;
           char s_v;
           cout<<"do you want to play rock paper scissor with the computer, enter 'Y' for yes  or 'N' for no: ";
           /* åæä ßÇä ããßä ÇÚãá Ïæ æÇíá ãÔÇä ãÇ ÍØ åÇí ÇáÑÓÇáÉ*/
           cin>>s_v;
        cout<<endl;
           while(s_v=='y'||s_v=='Y'){
             n=readnum(" enter how many rounds you want to play ");
         while(counter<n){
           cout<<"__ ROUND["<<counter+1<<"] begin_____\n";
     enchoice user=userchoice();

cout<<" your choice is: " ;displaychoice (user); cout<<endl;
      enchoice computer=     computerchoice();
      displaychoice (computer);

           cout<<" \n the winner for the "<<counter+1<<" round is: ";winner(user, computer,userc, computerc,drawc);
  cout<<endl;

 counter++;
 }
displaygame(n,userc,computerc,drawc);
 cout<<" do you want to play again y/n? ";
 cin>>s_v; counter=0;userc=0, computerc=0,drawc=0;
 if(s_v=='y'||s_v=='Y')
 resetscreen();
 }
 }




int main()

{
  srand(time(0));
  enchoice choice;
  int n;

  rounds(n);


}
