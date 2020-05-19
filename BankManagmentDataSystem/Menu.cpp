#include "Menu.h"

using namespace std;

int Menu::DisplayMenuOptions()
{
	cout << "\n              ====Bank Database Managment System====\n\n" << endl;
	cout << "====================================================================" << endl;
	int x = 1;

	//Creation of the Bank Database:
	ClientTree* BankTree = new ClientTree();//Clients Accounts
	TPriorityQueue<Pins>* templateIDs = new TPriorityQueue<Pins>(20);//Clients Pins
	EmployeesHashTable* StaffTable = new EmployeesHashTable(16);//Employees Information

	//Employees Database
	StaffTable->Insert(new StaffInfoStr("15248756", "Mary Jane","2"));
	StaffTable->Insert(new StaffInfoStr("45218392", "Edward Teach","15"));
	StaffTable->Insert(new StaffInfoStr("12566388", "Charles Vane","20"));
	StaffTable->Insert(new StaffInfoStr("12458755", "Anne Bonny","11"));
	StaffTable->Insert(new StaffInfoStr("14587227", "James Flint","13"));


	srand(time(0));
	cout << "Loading Database..." << endl;
	for (int i = 0; i < 20; i++)
	{
		BankTree->InsertAccount(rand(), rand());
	}
	//Pins Database
	templateIDs->Insert(new Pins(rand() % 10000, "Ronda Jobs"));
	templateIDs->Insert(new Pins(rand() % 10000, "Jon Smith"));
	templateIDs->Insert(new Pins(rand() % 10000, "Arnold Gates"));
	templateIDs->Insert(new Pins(rand() % 10000, "Tony Stark"));
	templateIDs->Insert(new Pins(rand() % 10000, "Steve Roggers"));
	templateIDs->Insert(new Pins(rand() % 10000, "Buggy Barns"));
	cout << " Database Ready!" << endl;
	Sleep(2000);
	system("cls");
	//////////////////////////////////////////////////////////////

	cout << "\n              ====Bank Database Managment System====\n\n" << endl;
	cout << "====================================================================" << endl;
	while (x > 0)
	{
		//Menu Interface
		cout << "                          === Menu ===" << endl;
		cout << "     -Type the respective number to execute an operation:\n\n" << endl;
		cout << "1-Display Clients Database        3-Delete an Account" << endl;
		cout << "2-Search a Respective Account     4-Find the Successor of an Account" << endl;
		cout << "5-Find the Height of the BST      6-Unlock Client Account"<< endl;
		cout << "7-Display List of Bank Employees  8-Register a New Employee" << endl;
		cout << "9-Remove an Employee              10-" << endl;
		cout << "\nType 0 to Quit!" << endl;
		cout << "====================================================================" << endl;
		cout << "->";
		cin >> x;
		switch (x)
		{
		//Quit
		case 0:
			cout << "Thank you for your Service!" << endl;
			break;
		//Display the Database
		case 1:
		{
			BankTree->IsBst(BankTree->root, INT_MIN, INT_MAX);//Cheks if BST Structure is being respected
			cout << "\n      ==== Client Database ====" << endl;
			BankTree->DisplayInOrder(BankTree->root);
			cout << "\n" << endl;
			cout << "====================================================================" << endl;
		}break;
		//Search an Account
		case 2:
		{
			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
			cout << "-Search Account:\n" << endl;



			int number;
			cout << "Enter the Account Number to be searched:";
			cin >> number;
			//If number is found, print "EXISTS" and the account number
			if (BankTree->Search(BankTree->root, number) == true) cout << "Account Exists!\n" << "Account Number: " << number << "\n";
			else cout << "Not Found\n";

			cout << "====================================================================" << endl;
			//BankTree->DisplayInOrder(BankTree->root);
			cout << "\n" << endl;
		}break;
		//Delete an Account
		case 3:
		{
			cout << "\n=Request:" << endl;
			cout << "-Delete Account:" << endl;
			cout << "Enter the Account Number to be deleted:";
			int number;
			cin >> number;
			BankTree->root = BankTree->DeleteAccount(BankTree->root, number);
			Sleep(3000);
			cout << "Account Deleted!";
			cout << "\n==== Client Database ====" << endl;
			BankTree->DisplayInOrder(BankTree->root);
			cout << "\n" << endl;

		}break;
		//Find the Successor of an account in the tree Structure
		case 4:
		{
			cout << "Enter the Account Number to find respective Sucessor:";
			int number;
			cin >> number;
			cout << "\n=Request:" << endl;
			struct Client* successor = BankTree->Getsuccessor(BankTree->root, number);
			if (successor == NULL) cout << "No successor Found\n";
			else
				cout << "The successor is the Account Number: " << successor->AccountNumber << "\n";


		}break;
		//Find the Height of the Root of this Binary tree database Structure
		case 5:
		{
			cout << "The Height of the Database Binary Tree root is: ";
			cout << BankTree->FindHeight(BankTree->root);
			cout << "\n\n";
		}break;
		//Queue
		case 6:
		{
			cout << "\nClients Account Validation:\n" << endl;
			cout << "WARNING: \nFor security reasons, next Operation will delete Pins Database!\n" << endl;

			while (!templateIDs->IsEmpty()) {
				Pins* obj = templateIDs->Remove();
				cout << "Client's Name: " << obj->name << "\tClient Temporary Pin: " << obj->key  << endl;
			}
			cout << "====================================================================\n" << endl;
		}break;
		case 7:
		{
			cout << "\n      ==== Staff Database ====" << endl;
			StaffTable->Display();
			cout << "\n" << endl;
			cout << "====================================================================" << endl;
		}break;
		case 8:
		{
			string IDE;
			string newE;
			string Eyear = "0";

				cout << "====================================================================" << endl;
				cout << "\n      ==== New Employee Registration ====\n" << endl;
				if (Eyear=="0")
				{
					cout << "Enter the New Employeer Name:";

					cin >> newE;
					getline(cin, newE);

					cout << "Enter the New Employeer ID:";

					cin >> IDE;
					getline(cin, IDE);
				}

				StaffTable->Insert(new StaffInfoStr(IDE, newE, Eyear));
				cout << "New Employee Added!";
				cout << "====================================================================" << endl;
			
		}break;
		case 9:
		{

			string ID;
			cout << "====================================================================" << endl;
			cout << "\n      ==== Firing an Employee ====\n" << endl;
			cout << "Enter the New Employeer ID:";
			cin >> ID;
			StaffTable->Delete(ID);
			cout << "====================================================================" << endl;
			cout << "Employee Deleted!\n";
			cout << "====================================================================" << endl;

		}break;
		case 10:
		{

		}break;

		default:
			cout << "Incorrect Command!!" << endl;
		}

	}

	system("pause");
	return 0;
}

