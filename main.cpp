#include<iostream>
#include<string.h>
#include<cstdlib>
#include<conio.h>

using namespace std;
//Airplane booking system
static int p=0;
class Air
{
    char planen[5],pilot[10],arrival[5],departure[5],from[30],to[30],seat[8][4][12];
public:
    void Newplane();
    void Allotment();
    void Empty();
    void Show();
    void Avail();
    void position(int i);
}Airp[20];

void Air::Newplane()
{
   cout<<"Enter Flight no\t";
   cin>>Airp[p].planen;
   cout<<"\nEnter pilot name\t";
   cin>>Airp[p].pilot;
   cout<<"\nArrival time\t";
   cin>>Airp[p].arrival;
   cout<<"\nEnter departure time\t";
   cin>>Airp[p].departure;
   cout<<"\nFrom: \t\t\t";
   cin>>Airp[p].from;
   cout<<"\nTo: \t\t\t";
   cin>>Airp[p].to;
   Airp[p].Empty();
   p++;
};
void Air::Allotment()
{
    int seat,n;
    char number[5];
    top:
        cout<<"Flight Number: ";
        cin>>number;
        for(n=0;n<=p;n++)
        {
            if(strcmp(Airp[n].planen,number)==0)
                break;
        }
        while(n<=p)
        {
            cout<<"\nSeat Number: ";
            cin>>seat;
            if(seat>60)
            {
                cout<<"\nThere are only 60 seats Available in this Airplane. ";
            }
            else
            {
                if(strcmp(Airp[n].seat[seat/4][(seat%4)-1],"empty")==0)
                {
                    cout<<"Enter passanger's name: ";
                    cin>>Airp[n].seat[seat/4][(seat%4)-1];
                    break;
                }
                else
                {
                    cout<<"The seat no. is already reserved.\n";
                }
            }
            if(n>p)
            {
                cout<<"Enter correct Flight no.\n";
                goto top;
            }
        }
};
void Air::Empty()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<4;j++)
        {
            strcpy(Airp[p].seat[i][j],"empty");
        }
    }
};
void Air::Show()
{
    int n;
    char number[5];
    cout<<"Enter Flight Number : ";
    cin>>number;
    for(n=0;n<=p;n++)
    {
        if(strcmp(Airp[n].planen,number)==0)
        break;
    }
    while(n<=p)
    {
        cout<<"Flight No. :\t"<<Airp[n].planen<<"\nPilot Name :\t"<<Airp[n].pilot
        <<"\t\tArrival Time : \t"<<Airp[n].arrival<<"\tDeparture Time :\t"<<Airp[n].departure
        <<"\nFrom : \t\t"<<Airp[n].from<<"\t\t To :\t\t"<<Airp[n].to<<"\n";
        Airp[0].position(n);
        int a=1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(Airp[n].seat[i][j],"empty")!=0)
                cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<Airp[n].seat[i][j]<<".";
            }
        }
        break;
    }
    if(n>p)
    cout<<"Enter correct Flight no: ";
};
void Air::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(Airp[l].seat[i][j], "empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<Airp[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<Airp[l].seat[i][j];
        }
    }
  }
  cout<<"\n\nThere are "<<p<<" seats empty in Flight No: "<<Airp[l].planen;
};
void Air::Avail()
{
    int n;
    for(n=0;n<p;n++)
    {
        cout<<"Flight no: \t"<<Airp[n].planen<<"\nPilot: \t"<<Airp[n].pilot
    <<"\t\tArrival time: \t"<<Airp[n].arrival<<"\tDeparture Time: \t"
    <<Airp[n].departure<<"\nFrom: \t\t"<<Airp[n].from<<"\t\tTo: \t\t\t"
    <<Airp[n].to<<"\n";
    }
};
int main()
{
    system("cls");
    int w;
    while(1)
    {
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t1.New Plane\n\t\t\t"
        <<"2.Reservation\n\t\t\t"
        <<"3.Show\n\t\t\t"
        <<"4.Flights Available. \n\t\t\t"
        <<"5.Exit";
        cout<<"\n\t\t\tEnter your choice:-> ";
        cin>>w;
        switch(w)
        {
    case 1:
        Airp[p].Newplane();
        break;
    case 2:
        Airp[p].Allotment();
        break;
    case 3:
        Airp[0].Show();
        break;
    case 4:
        Airp[0].Avail();
        break;
    case 5:
        exit(0);
        }
}
    return 0;
}
