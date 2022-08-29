#include<iostream>
using namespace std;

void ShowMenu()
{
	cout<<"------Menu------"<<endl;  // 12 dashes
	cout<<"1. Check balance."<<endl;
	cout<<"2. Deposit"<<endl;
	cout<<"3. Withdraw"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"----------------"<<endl;
}

int main()
{
	// Show menu, Check balance, deposit, withdraw
	
	int option;
	double balance=500; //initial value
	
	do{
	
	ShowMenu();
	cout<<"Option: ";
	cin>>option;
	system("cls");
	switch(option)
	{
		case 1:cout<<"Balance is: Rs."<<balance<<endl;
			   break;
		case 2: cout<<"Enter deposit amount: ";
				double depositAmount;
				cin>>depositAmount;
				balance+=depositAmount;
				break;
		case 3: cout<<"Enter withdraw amount: ";
				double withdrawAmount;
				cin>>withdrawAmount;
				if(withdrawAmount<=balance)
					balance-=withdrawAmount;
				else
					cout<<"not enough money"<<endl;
				break;
		//default:
		//	cout<<"Enter 1,2,3 or 4";
	}
	}while(option!=4);
	
	return 0;
}
