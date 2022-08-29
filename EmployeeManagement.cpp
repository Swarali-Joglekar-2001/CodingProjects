#include<iostream>
#include<windows.h>
using namespace std;

void showMenu()
{
	cout<<"\nPress 1: Enter data"<<endl;
	cout<<"Press 2: Show data"<<endl;
	cout<<"Press 3: Search data"<<endl;
	cout<<"Press 4: Update data"<<endl;
	cout<<"Press 5: Delete data"<<endl;
	cout<<"Press 6: Logout"<<endl;
	cout<<"Press 7: Exit"<<endl;
	
}

struct emp{
	string name,id,address;
	int contact,salary;
};
emp e[100];
int total_emp=0;
void empdata(){
	int choice;
	cout<<"Enter no. of employees: ";
	cin>>choice;
	for(int i=total_emp; i<total_emp+choice; i++)
	{
		cout<<"Enter data of employee "<<i+1<<endl;
		cout<<"Employee name: ";
		cin>>e[i].name;
		cout<<"Employee ID: ";
		cin>>e[i].id;
		cout<<"Employee address: ";
		cin>>e[i].address;
		cout<<"Employee contact: ";
		cin>>e[i].contact;
		cout<<"Employee salary: ";
		cin>>e[i].salary;
	}
	total_emp+=choice;
}

void show(){
		if(total_emp!=0){
		for(int i=0; i<total_emp; i++){
		cout<<"Data of employee "<<i+1<<endl;
		cout<<"Employee name: ";
		cout<<e[i].name<<endl;
		cout<<"Employee ID: ";
		cout<<e[i].id<<endl;
		cout<<"Employee address: ";
		cout<<e[i].address<<endl;
		cout<<"Employee contact: ";
		cout<<e[i].contact<<endl;
		cout<<"Employee salary: ";
		cout<<e[i].salary<<endl;
		
		}
			
		}
	
		else{
			cout<<"Empty records..."<<endl;
		}
	
}

void search(){
	if(total_emp!=0){
		string id;
		cout<<"Enter employee id: ";
		cin>>id;
		for(int i=0; i<total_emp; i++){
			if(id==e[i].id){
		cout<<"Data of employee "<<i+1<<endl;
		cout<<"Employee name: ";
		cout<<e[i].name<<endl;
		cout<<"Employee ID: ";
		cout<<e[i].id<<endl;
		cout<<"Employee address: ";
		cout<<e[i].address<<endl;
		cout<<"Employee contact: ";
		cout<<e[i].contact<<endl;
		cout<<"Employee salary: ";
		cout<<e[i].salary<<endl;
		break;		
			}
			if(i==total_emp-1)
				cout<<"No record found"<<endl;
		}
	}
	else
		cout<<"Empty records..."<<endl;
}
void update(){
	if(total_emp!=0){
		string id;
		cout<<"Enter employee id for data updation: ";
		cin>>id;
			for(int i=0; i<total_emp; i++){
			if(id==e[i].id){
		cout<<"Previous data: "<<endl;
		cout<<"Data of employee "<<i+1<<endl;
		cout<<"Employee name: ";
		cout<<e[i].name<<endl;
		cout<<"Employee ID: ";
		cout<<e[i].id<<endl;
		cout<<"Employee address: ";
		cout<<e[i].address<<endl;
		cout<<"Employee contact: ";
		cout<<e[i].contact<<endl;
		cout<<"Employee salary: ";
		cout<<e[i].salary<<endl;
		cout<<"\nEnter new data:"<<endl;
		cout<<"Employee name: ";
		cin>>e[i].name;
		cout<<"Employee ID: ";
		cin>>e[i].id;
		cout<<"Employee address: ";
		cin>>e[i].address;
		cout<<"Employee contact: ";
		cin>>e[i].contact;
		cout<<"Employee salary: ";
		cin>>e[i].salary;
		
		
		
		break;		
			}
			if(i==total_emp-1)
				cout<<"No record found"<<endl;
		}
		
		
	}
	else{
		cout<<"Empty records..."<<endl;
	}
	
	
	
}
void del(){
	char user;
	cout<<"Press 1: Delete entire record"<<endl;
	cout<<"Press 2: Delete specific record"<<endl;
	cin>>user;
	if(total_emp!=0){
		
	
	if(user=='1')
		total_emp=0;
		cout<<"Entire record deleted..."<<endl;	
	}
	else if(user=='2'){
		string id;
		cout<<"Enter employee id for data deletion: ";
		cin>>id;
		for(int i=0; i<total_emp;i++)
		{
			if(id==e[i].id)
			{
				for(int j=i; j<total_emp;j++)
				{
				
				e[j].name=e[j+1].name;
				e[j].id=e[j+1].id;
				e[j].address=e[j+1].address;
				e[j].contact=e[j+1].contact;
				e[j].salary=e[j+1].salary;
				total_emp--;
				break;
				}
			if(i==total_emp-1)
				cout<<"No record found"<<endl;
			}
		}
	}
	else
		cout<<"Empty records..."<<endl;
	
	
}

int main()
{
	cout<<"\t\tEmployee Management System"<<endl;
	cout<<"\n \t\t SIGN UP:"<<endl;
	string username, password;
	cout<<"\t\t Enter username: ";
	cin>>username;
	cout<<"\n \t\t Enter password: ";
	cin>>password;
	cout<<endl;
	cout<<"\t\t Wait, your ID is being created";
//	cout<<"\t\t";
	for(int i=0; i<5; i++)
	{
		cout<<".";
		Sleep(900); // in milliseconds
	}
	
	system("cls");
	
	cout<<"\t\tEmployee Management System"<<endl;
	start:
	cout<<"\n \t\t LOG IN:"<<endl;
	string username1, password1;
	cout<<"\t\tUsername: ";
	cin>>username1;
	cout<<"\n\t\tPassword: ";
	cin>>password1;
	if(username1==username && password1==password)
		{
			system("cls");
			char user;
			while(1)
			{	showMenu();
				cin>>user;
				switch(user){
					case '1':
						empdata();
						break;
					case '2':
						show();
						break;
					case '3':
						search();
						break;
					case '4':
						update();
						break;
					case '5':
						del();
						break;
					case 6:
						goto start;
						break;
					default:
						cout<<"\a Invalid input"<<endl; // \a for sound
						break;
				}
			}
		}
	else if(username1!=username)
		{
		cout<<"\t\tIncorrect username"<<endl;
		Sleep(3000);
		goto start;
		}
	else if(password1!=password)
		{
		cout<<"\t\tIncorrect password"<<endl;
		Sleep(3000);
		goto start;
		}
	return 0;
}
