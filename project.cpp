// Code by Faizan Mahmood

#include<iostream>
#include<fstream>
#include<string>
#include <typeinfo>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool des_hm_ck(char ck[4])
{
     if( (strcmp(ck,"ISB")==0) || (strcmp(ck,"isb")==0) || (strcmp(ck,"LHR")==0) || (strcmp(ck,"lhr")==0)
                               || (strcmp(ck,"KHI")==0) || (strcmp(ck,"khi")==0)
                               || (strcmp(ck,"RYD")==0) || (strcmp(ck,"ryd")==0)
                               || (strcmp(ck,"DUX")==0) || (strcmp(ck,"dux")==0)
                               || (strcmp(ck,"WDC")==0) || (strcmp(ck,"wdc")==0)
                               || (strcmp(ck,"LCY")==0) || (strcmp(ck,"lcy")==0) )
         return true;
     
     else
         return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void INVALID()
{
     cout<<"\n\nInvalid choice";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class person
{
      private:
              string add, name, cnic, tel;
      public:
             virtual void get()
             {
                  cout<<"\n\nEnter your First name\t\t";
                  cin>>name;
                  cout<<"\n\nEnter your CNIC number\t\t";
                  cin>>cnic;
                  cout<<"\n\nEnter your telephone number\t";
                  cin>>tel;
                  cout<<"\n\nEnter your city\t\t\t";
                  cin>>add;
             }
             
             virtual void show()
             {
                  cout<<"\n\n\t\tYour Information is:";   
                  cout<<"\n\nFIRST Name\t\t"<<name;
                  cout<<"\n\nCNIC number\t\t"<<cnic;
                  cout<<"\n\nTelephone number\t"<<tel;
                  cout<<"\n\nCity\t\t\t"<<add;
             }
             
              
             void write();
             
             void read(int);
            
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class passenger : public person
{
      private:
              int payop, fare;
              static int refno;
              char desck,des, home[4], destiny[4];
              string ms;
      public: 
              void get()
              {
                   person :: get();
                   refno++;
                   NI:
                   cout<<"\n\nSelect your destination"
                                     "\n\nN: National\n\nI: International\t\t";
                   cin>>desck;
                   
                   if((desck == 'N') || (desck == 'n'))
                   {
                            cout<<"\n\n\t\tOFFERED NATIONAL DESTINATIONS"
                                  "\n\nISB: Islamabad\n\nLHR: Lahore\n\nKHI: Karachi\t\t";
                   
                                  fare = 10000;
                   }     
                   else if((desck == 'I') || (desck == 'i'))
                   {
                           cout<<"\n\n\t\tOFFERED INTERNATIONAL DESTINATIONS"
                                 "\n\nLCY: London\n\nRYD: Riyadh\n\nISB: Islamabad\n\nDUX: DUBAI\n\nWDC: Washington DC";
                                 
                                 fare = 30000;
                   }
                   else
                   {
                           INVALID();
                           goto NI;
                   }
                   
                   HM:
                           
                   cout<<"\n\nEnter code of your home location\t";
                   cin>>home;
                   
                   int t =  des_hm_ck(home);
                   
                   if(t == true);
                   
                   else
                       {
                           INVALID();
                           goto HM;
                       }
                   DE:
                       
                   cout<<"\n\nEnter code of your destination\t\t";
                   cin>>destiny;
                   
                   t =  des_hm_ck(destiny);
                   if(t == true);

                   else
                       {
                           INVALID();    
                           goto DE; 
                       }
                       
                   PO:
                   
                   cout<<"\n\nWhat is the mode of your payment, Press!\n\n1: For Cheque\n\n2: For Credit Card\n\n3: For Cash\t\t\t";
                   cin>>payop;
                   
                   YN:
                   cout<<"\n\nWill to take baggage more than 30 kg y/n\t\t";
                   char yn;
                   cin>>yn;
                   if( (yn == 'y') || (yn == 'Y') )
                   {
                         fare += 1000 ;
                   }
                   else if( (yn == 'N') || (yn == 'n') );
                   else
                   {
                        INVALID();
                        goto YN;
                   }
              
                   switch(payop)
                   {
                                case 1:
                                case 2:
                                case 3:
                                     break;
                                default:
                                        INVALID();
                                        goto PO;                                
                   }
              }
              
              void show()
              {
                   person :: show();
                   cout<<"\n\nReference no.\t\t"<<refno;
                   cout<<"\n\nHome location\t\t"<<home;
                   cout<<"\n\nDestination\t\t"<<destiny;
                   cout<<"\n\nTotal Fare\t\t"<<fare;
                   if(payop == 1)
                   cout<<"\n\nPayment option\t\tCheque";
                   else if(payop == 2)
                   cout<<"\n\nPayment option\t\tCradit Card";
                   else
                   cout<<"\n\nPayment option\t\tCash";
              } 

              static void cancel(int ref) 
              {
                     cout<<"\n\nOK";
              } 
};

int passenger :: refno = 1000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void person :: write()
{
     ofstream objf;
     objf.open("passengers.txt", ios::app | ios::binary);
     objf.write(reinterpret_cast<char*>(this), sizeof(*this));
     cout<<"\n\n\t\t\tINFORMATION SAVED\n\n\t\t\tTHANK YOU !";
}

void person :: read(int ref)
{
     ifstream objf;
     int n = sizeof(this);
     objf.open("passengers.txt", ios::binary);
     objf.seekg(((ref-1001)*n), ios::beg);
     objf.read(reinterpret_cast<char*>(this),sizeof(*this));
     //this -> show();
     cout<<"\n\nOK";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    static int x;
    char ck;
    person* ptr[50];
    char start;
    int ref;
    passenger PPP;
    cout<<"\t\t\tWELCOME TO DX9 INTERNATIONAL AIRLINE";
    
    do
    {
    CH:
    
    cout<<"\n\nPRESS !!!\n\nR: FOR RESERVATION\n\nC: FOR CHECKING YOUR RESERVATION STATUS"
                       "\n\nD: FOR CENCELING YOUR RESERVATION\n\nE: FOR EXIT\t\t";
    cin>>start;
    
    switch(start)
    {
                 case 'R':
                 case 'r':
                      ptr[x] = new passenger;
                      RE:
                      ptr[x] -> get();
                      ptr[x] -> show();
                      IT:
                      
                      cout<<"\n\nPress C to change info or S to save\t";
                      char it;
                      cin>>it;
                      
                      if ( (it == 'C') || (it == 'c') )
                      goto RE;
                      
                      else if ( (it == 'S') || (it == 's') )
                      ptr[x] -> write();
                      
                      else
                      {
                          INVALID();
                          goto IT;
                      }
                      break;
                 case 'C':
                 case 'c':
                      cout<<"\n\nEnter your reference no.\t\t";
                      cin>>ref;
                      PPP.read(ref);
                      PPP.show();
                      break;
                 case 'D':
                 case 'd':
                      cout<<"\n\nEnter your reference no.\t\t";
                      cin>>ref;
                      passenger :: cancel(ref);
                      break;
                 case 'E':
                 case 'e':
                      system("pause");
                      return 0;
                 default :
                         INVALID();
                         goto CH;
    }
    
    x++;
    
    cout<<"\n\nPress y to repeat the process or any other key to exit\t\t";
    cin>>ck;
    
    }while(ck == 'y');
    
    cout<<"\n\n\t\t\t\tPROGRAM BY "
                   "\n\n\t\t\tFAIZAN MAHMOOD"<<endl;
        
    system("pause");
    return 0;
}
