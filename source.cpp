#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

bool toss();
int compTurn();
int userTurn();
int randNum();
void playagain();
int main()
{
	cout << "Welcome to HTGame" << endl;
	int userScore, compScore,tos ;
	char again,tosss,choice;
	do
	{
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
	} while (again=='y'||again=='Y');
	cout << "\n\nThanks for playing!\nMade By Adil Aziz."<<endl;
	cin >> again;
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

int compTurn()
{
	int userNum = 1, compNum = 0, score = 0;
	cout << "\n\nComputer's Turn\n";
	while (compNum != userNum)
	{
		score += compNum;
		compNum = randNum();
		cout << "Your Number: ";
		cin >> userNum;
		while (userNum>6 || userNum<1)
		{
			cout << "No ball! 1 score added to opponent's score";
			score=score +1;
			cout<<"\nYour number: ";
			cin >> userNum;
		}
		cout << "Computer Number: " << compNum << endl;
	}
	cout << "\nComputer is out!\nComputer\'s Score is " << score << endl;
	return score;
}
int userTurn()
{
	int userNum = 0, compNum = 1, score = 0;
	cout << "\n\nYour Turn\n";
	while (compNum != userNum)
	{
		score += userNum;
		compNum = randNum();
		cout << "Your Number: ";
		cin >> userNum;
		while (userNum>6 || userNum<1)
		{
			cout << "Your Number: ";
			cin >> userNum;
		}
		cout << "Computer Number: " << compNum << endl;
	}
	cout << "\nYou are Out!\nYour Score is " << score << endl;
	return score;
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
