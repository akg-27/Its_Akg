#include<iostream>
#include<stdio>
#include<conio>
#include<iomanip>
#include<fstream>
#include<stdlib>

using namespace std;

 class Bank
{
  private:

	char acname[20];
	int acno;
	double bal;

  public:

	void addacc();
	void allacc();
	void dpst(int);
	void wtdr(int);
	void dsply(int);
};


 void Bank::addacc()
 {
	cout<<"\nEnter Acc.Holder Name :";
	cin.ignore();
	cin.getline(acname,19);
	cout<<"\nEnter Acc.No :";
	cin>>acno;
	cout<<"\nEnter minimum amount :";
	cin>>bal;
 }

 void Bank::allacc()
 {
	cout<<setw(27)<<acname<<setw(14)<<acno<<setw(16)<<"Private"<<endl;
 }
 void Bank::dsply(int c)
 {
	if(acno==c)
	{
		cout<<"\nYour account details are given below :-\n"<<endl;
		cout<<"Holder Name :"<<acname<<endl;
		cout<<"Account Number :"<<acno<<endl;
		cout<<"Balance in Account :"<<bal<<endl;

	}
	else
	{
		cout<<"\nAccount does not exist..!!"<<endl;
	}
 }

 void Bank::dpst(int a)
 {


	if(acno==a)
	{
		cout<<"\nEnter amount to be deposited:";
		double m;
		cin>>m;
		bal=bal+m;
		cout<<"\nAmount deposited successfully to your account.."<<endl;

	}
	else
	{
	  cout<<"Sorry account not found !!"<<endl;
	}
 }

 void Bank::wtdr(int b)
 {
		cout<<"\nEnter amount to witdraw:";
		double m;
		cin>>m;

	if(acno==b && bal>=m)
	{
		bal=bal-m;
		cout<<"\nAmount withdrawn successfully from your account.."<<endl;
	}
	else
	{
	  cout<<"\nSorry account not found or Insufficient balance !!"<<endl;
	}
 }

 int main()
 {

	Bank B;
	ifstream bin;
	ofstream bout;

	while(1)
	{

		cout<<"\n\t\t  Welcome to ABC Bank...Please make choice from 1-6:";
		cout<<"\n1.Create new account";
		cout<<"\n2.Deposit to account";
		cout<<"\n3.Withdraw from account";
		cout<<"\n4.Display details of an account";
		cout<<"\n5.Display details of all accounts";
		cout<<"\n6.Exit";
		cout<<"\nENTER YOUR CHOICE : ";
	int n;
	cin>>n;
	cout<<"\n";


	if(n==1)
	{

		B.addacc();
		bout.open("bank.dat",ios::app);
		bout.write((char *) &B,sizeof(B));
		bout.close();
	}
	else if(n==2)
	{
			bin.open("bank.dat",ios::in|ios::binary);
			bout.open("bank1.dat",ios::out|ios::binary);

			cout<<"Enter your account no.:";
			int x;
			cin>>x;


		while(bin.read((char *) &B,sizeof(B)))
		{
				B.dpst(x);
				bout.write((char *) &B,sizeof(B));
		}

			bin.close();
			bout.close();
			remove("bank.dat");
			rename("bank1.dat","bank.dat");
	}
	else if(n==3)
	{

			bin.open("bank.dat",ios::in|ios::binary);
			bout.open("bank1.dat",ios::out|ios::binary);

			cout<<"Enter your account no.:";
			int y;
			cin>>y;

		while(bin.read((char *) &B,sizeof(B)))
		{
				B.wtdr(y);
				bout.write((char *) &B,sizeof(B));
		}

			bin.close();
			bout.close();
			remove("bank.dat");
			rename("bank1.dat","bank.dat");
	}
	else if(n==4)
	{

		cout<<"Enter acc no. to see your details :";
		int no;
		cin>>no;
		bin.open("bank.dat",ios::in|ios::binary);

			while(bin.read((char *) &B,sizeof(B)))
			{
				 B.dsply(no);
			}
		bin.close();
	}
	else if(n==5)
	{

			cout<<"\n\t\t\t\tACCOUNT HOLDER LIST\n\n";
			cout<<"\t\t  Acc.Holder"<<setw(15)<<"Acc.No"<<setw(15)<<"Amount"<<endl;

		 bin.open("bank.dat",ios::in|ios::binary);

			while(bin.read((char *) &B,sizeof(B)))
			{
				B.allacc();
			}

		 bin.close();
	}
	else if(n==6)
	{

		cout<<"\n\t\t\tTHANK YOU...VISIT US AGAIN.. :)";
		cout<<"\n\t\t\t Press Enter key to exit";
		getch();
		exit(0);
	}
	}
    return 0;
}