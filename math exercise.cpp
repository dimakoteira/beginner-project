#include <iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
enum enlevel{easy=1,mid,hard,mix};
enum enop{add=1,sub,dive,mult,mixop};


int readnum(string message){
  cout<<message <<endl;
  int n;
  cin>>n;
  return n;
}


int random (int to, int from){
  int randomnum=to+rand()%(from-to+1);
  return randomnum;
}

enlevel readlevel(){
  int c;
  cout<<"choose the level of questions\n [1]: easy, [2]: mid, [3]: hard, [4]: mix ";
  cin>>c;
  if(c>4)
  return readlevel();
  return static_cast<enlevel>(c);

}

enop operation (){
  int c;
  cout<<"enter the operator type\n [1]: add, [2]: sub, [3]: div, [4]: mult, [5] : mix ";
  cin>>c;
   if(c>5)
  return operation();
  return static_cast<enop>(c);

}

int generatenum(enlevel level){
  switch(level){
    case easy: return random(1,10);
    case mid: return random(10,50);
    case hard: return random(10,150);
    case mix: return random(1,150);
  }
}


    char generateop(enop oper){
      switch (oper){
        case add: return '+';
        case sub: return '-';
        case dive: return '/';
        case mult: return '*';
        case mixop: return '?';



      }}



      int calculate(enop op,int a,int b){
        switch(op){
        case add: return a+b;
        case sub: return a-b;
        case dive: return a/b;
        case mult: return a*b;
      }}



      int getuserawnser(){
        int a;
        cin>>a;
        return a;
      }



  int getrightawnser(int x,int y,enop ope)
  {
   return calculate(ope,x,y);
  }




  void checkawnser(int &wrongaw,int &rightaw,int x,int y,enop op){
      if(getuserawnser()==getrightawnser(x,y,op)){
      system("color 27");
      cout<<"correct awnser";
      rightaw++;}
      else
        {
            system("color 47");
         cout<<"wrong awnser the right awnser is "<<getrightawnser(x,y,op);
      wrongaw++;
      }


  }



  bool passfail(int n,int userright){

    if(userright>=n/2)
    return true;
    else return false;
  }



  void displayscreen(int n,enlevel level,enop op,int right,int wrong){
    cout<<"\t\tQUIZE END\n";
    cout<<"\t____________\n";
    if(passfail(n,right))
    cout<<"\t\t PASSED\n ";
    else cout<<"\t\t FAIL\n";
    cout<<"\t____________\n";
    cout<<"quize level \t "<<level<<endl;
    cout<<"operator \t "<<generateop(op)<<endl;
    cout<<"right awnsers \t "<<right<<endl;
    cout<<"wrong awnsers \t "<<wrong<<endl;


  }



   void askagain ();


     void generatequiz ()
     {
         char s_v='y';
       int counter=0,awnser,wrong=0,right=0;
   int n= readnum("how many questions you want to answer ");

       enlevel level=readlevel();
       enop op=operation ();

       while (counter<n){
         int x=generatenum (level);
         int y=generatenum(level);

         enop current_op = (op == mixop) ? static_cast<enop>(random(1, 4)) : op;




     cout<<setw(3)<<x<<endl<<setw(5)<<generateop(current_op)<<endl<<setw(3)<<y<<endl<<"____"<<endl;

      checkawnser(wrong,right,x,y, current_op);

         cout<<endl;
         counter++;

       }

       displayscreen(n,level,op,right,wrong);
       askagain ();

         }


       void resetscreen ()
       {
           system("color 07");
         system("cls");
         }





int main() {
    srand(time(0));
    generatequiz();

}

void askagain ()
{
  char s_v='y';
           cout<<"do you want to take another quize y/n : ";
      cin>>s_v;
      if(s_v=='y'||s_v=='Y')

      {
      resetscreen();
      generatequiz();
      }

       }
