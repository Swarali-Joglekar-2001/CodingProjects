#include<iostream>
using namespace std; 
void showMenu()
{
	cout<<"------------------------------"<<endl;
	cout<<" Parking system:"<<endl;
	cout<<"Press 1: To park rikshaw"<<endl;
	cout<<"Press 2: To park car"<<endl;
	cout<<"Press 3: To park bus"<<endl;
	cout<<"Press 4: To show record"<<endl;
	cout<<"Press 5: To delete record"<<endl;
	cout<<"Press 6: To show menu"<<endl;
	cout<<"Press 7: Exit from the system"<<endl;
	cout<<"Press 8: Clear screen"<<endl;
	cout<<"------------------------------"<<endl;
	
}

		// I haven't yet modified the code to unpark the vehicle.

int main()
{
	int rik=0, cars=0, buses=0, total_vehic=0;
	int choice, amount=0;
	// maximum 50 vehicles can be parked
	showMenu();
while(1)
{
	cin>>choice;
	if(choice==1 || choice==2 || choice==3)
	{
	
		if(total_vehic==50)
		{
			cout<<"Sorry, maximum limit of number of vehicles has been reached. You can't park for now."<<endl;
			break;
		}
	}
	if(choice==7) // exit from system
		break;
	switch(choice)
	{
		case 1:
			rik++;
			amount+=100;
			total_vehic++;
			cout<<"Added 1 rikshaw in record"<<endl;
			
			break;
		case 2:
			cars++;
			amount+=200;
			total_vehic++;
			cout<<"Added 1 car in record"<<endl;
		
			break;
		case 3:
			buses++;
			amount+=300;
			total_vehic++;
			cout<<"Added 1 bus in record"<<endl;
		
			break;
		case 4:
			cout<<"--------Current record---------"<<endl;
			cout<<"Total amount= "<<amount<<endl;
			cout<<"Total vehicles= "<<total_vehic<<endl;
			cout<<"Rikshaws= "<<rik<<endl;
			cout<<"Cars= "<<cars<<endl;
			cout<<"Buses= "<<buses<<endl;
			cout<<"-------------------------"<<endl;
			
			break;
		case 5:
			rik=0;cars=0;amount=0;total_vehic=0;
			cout<<"Record deleted"<<endl;
			
			break;
		case 6:
			showMenu();
			break;
		case 8:
			system("cls");
			break;
		default:
			cout<<"Invalid input"<<endl;
			cout<<"See the menu:"<<endl;
			showMenu();
			
	}
	
	
}
	return 0;
}
