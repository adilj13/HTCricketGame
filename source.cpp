#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int totalover=0;
bool toss();
int compTurn();
int userTurn();
int randNum();
void playagain();
int main()
{
	cout << "Welcome to HTGame" << endl;
	int userScore, compScore,tos,balls=1 ;
	char again,tosss,choice;
	do
	{
		cout<<"How Many overs do you want to play? ";
		cin>>totalover;
		cout<<"\t"<<totalover<<" Overs Match \n"<<endl;
		
		cout << "Select Head/Tales: (H/T) ";
		cin >> tosss;
		while (tosss != 'h' && tosss != 'H' && tosss != 't' && tosss != 'T')
		{
			cout << "Select Head/Tales: (H/T)" << endl;
			cin >> tosss;
		}
		tos = toss();
		if (tos)
		{
			if (tosss=='h'||tosss=='H')
			{
				cout << "Its Heads" << endl;
			}
			else
			{
				cout << "Its Tails" << endl;
			}
			cout << "Congratulations\nYou Won the Toss.\nWhat will you chose Bat or Field(B/F)??";
			cin >> choice;
			while (choice != 'b' && choice != 'B' && choice != 'f' && choice != 'F')
			{
				cout << "What will you chose Bat or Field(B/F)??" << endl;
				cin >> choice;
			}
			if (choice == 'b' || choice == 'B')
			{
				userScore = userTurn();
				compScore = compTurn();
			}
			else
			{
				compScore = compTurn();
				userScore = userTurn();
			}
		}
		else
		{
			if (tosss == 'h' || tosss == 'H')
			{
				cout << "Its Tails" << endl;
			}
			else
			{
				cout << "Its Heads" << endl;
			}
			choice=rand()%2+1;
			if(choice==1){
				cout<<"\nYour Opponent choose to bat first"<<endl;
				compScore = compTurn();
			    userScore = userTurn();
			}else{
				cout<<"\nYour opponent choose to bowl first "<<endl;
				userScore = userTurn();
				compScore = compTurn();
			}
			
		}
		
		if (compScore>userScore)
		{
			cout << "\nComputer Wins.\nYou Lose." << endl;
		}
		else if (userScore>compScore)
		{
			cout << "\nYou Wins.\nComputer Lose." << endl;
		}
		else
		{
			cout << "\nWell Played\nMatch Tie." << endl;
		}
		playagain();
	}
	 while (again=='y'||again=='Y');
	cout << "\n\nThanks for playing!\nMade By Adil Aziz."<<endl;
	return 0;
}
void playagain(){
	char again;
	cout << "Do you want to play again? (Y/N)";
    cin >> again;
	if (again=='y'||again=='Y')
	{
		main();
	}
}
int randNum()
{
	int num;
	srand(time(0));
	num = 1 + rand() % 6;
	return num;
}
int compscore=0,userscore=0;
int compTurn()
{
	
	int over=0,balls=0;
	int userNum = 1, compNum = 0;
	cout << "\tComputer's Turn\n";
	while (compNum != userNum)
	{
		balls=balls+1;
		compscore += compNum;
		compNum = randNum();
		cout<<"\nTotal Score: "<<compscore<<endl;
		cout<<"\nOver "<<over<<"."<<balls;
		if (balls==6)
		{
			over=over+1;
			balls=0;
		}
		if (over==totalover)
		{
			cout<<"\n\tOvers Ended";
			break;
		}
		
		
		
		cout << "\nYour Number: ";
		cin >> userNum;
		while (userNum>6 || userNum<1)
		{
			cout << "No ball! 1 score added to opponent's score";
			compscore=compscore +1;
			cout<<"\nYour number: ";
			cin >> userNum;

		}
		
		cout << "Computer Number: " << compNum << endl;
	}
	cout << "\nComputer's Inning Ended!\nComputer\'s Score is " << compscore << endl;
	return compscore;
}
int userTurn()
{
	int over=0,balls=0;
	int userNum = 0, compNum = 1;
	cout << "\tYour Turn\n";
	while (compNum != userNum)
	{
		balls=balls+1;
		userscore += userNum;
		compNum = randNum();
		cout<<"\nTotal Score: "<<userscore<<endl;
		cout<<"\nOver "<<over<<"."<<balls;
		if (balls==6)
		{
			over=over+1;
			balls=0;
		}
		if (over==totalover)
		{
			cout<<"\n\tOvers Ended";
			break;
		}
		cout << "\nYour Number: ";
		cin >> userNum;
		while (userNum>6 || userNum<1)
		{
			cout<<"Invalid number!\n";
			cout << "Your Number: ";
			cin >> userNum;
		}
		
		cout << "Computer Number: " << compNum << endl;
		
	}
	cout << "\nYour Inning Ended!\nYour Score is " << userscore << endl;
	return userscore;
}
bool toss()
{
	int result;
	srand(time(0));
	result = rand();
	if (result%2==0)
	{
		return false;
	}
	return true;
}
