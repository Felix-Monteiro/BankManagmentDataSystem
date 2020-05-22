#include "Menu.h"

using namespace std;

int Menu::DisplayMenuOptions()
{
	cout << "\n              ====Bank Database Managment System====\n" << endl;
	cout << "====================================================================" << endl;
	int x = 1;
	srand(time(0));
	cout << "Loading Database..." << endl;

	/////////////////////////////////////////////////////////////////////////////////////////
	//Creation of the Bank Databases
	ClientTree* BankTree = new ClientTree();//Tree Clients Accounts
	TPriorityQueue<Pins>* templateIDs = new TPriorityQueue<Pins>(20);//Queue Pins
	EmployeesHashTable* StaffTable = new EmployeesHashTable(16);//Hash Table Staff

	//Employees Database
	StaffTable->Insert(new StaffInfoStr("15248756", "William Kidd","2"));
	StaffTable->Insert(new StaffInfoStr("45218392", "Edward Teach","15"));
	StaffTable->Insert(new StaffInfoStr("12566388", "Charles Vane","20"));
	StaffTable->Insert(new StaffInfoStr("12458755", "Anne Bonny","11"));
	StaffTable->Insert(new StaffInfoStr("14587227", "James Flint","13"));

	//Creation of Accounts Database
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
	/////////////////////////////////////////////////////////////////////////////////////////
	cout << "\n              ====Bank Database Managment System====\n" << endl;
	cout << "====================================================================" << endl;
	while (x > 0)
	{
		//Menu Interface
		cout << "====================================================================\n" << endl;
		cout << "                          === Menu ===" << endl;
		cout << "     -Type the respective number to execute an operation:" << endl;
		cout << "====================================================================" << endl;
		cout << "====================================================================\n" << endl;
		cout << "                    ==== Clients Operations ====\n" << endl;
		cout << "1-Display Clients Database        2-Search a Respective Account " << endl;
		cout << "3-Delete an Account               4-Find the Successor of an Account" << endl;
		cout << "5-Find the Height of the BST      6-Unlock Client Account"<< endl;
		cout << "====================================================================\n" << endl;
		cout << "                    ==== Staff Operations ====\n" << endl;
		cout << "7-Display List of Bank Employees  8-Register a New Employee" << endl;
		cout << "9-Remove an Employee              " << endl;
		cout << "\n0-Quit" << endl;
		cout << "====================================================================" << endl;
		cout << "====================================================================" << endl;
		cout << "->";
		cin >> x;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		switch (x)
		{
		//Quit
		case 0:
			cout << "Thank you for your Service!" << endl;
		break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Display the Accounts Database (Tree DS)
		case 1:
		{
			BankTree->IsBst(BankTree->root, INT_MIN, INT_MAX);//Cheks if BST Structure is being respected

			cout << "\n      ==== Client Database ====" << endl;
			BankTree->DisplayInOrder(BankTree->root);
			cout << "\n" << endl;
		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Search an Account (Tree DS)
		case 2:
		{
			int number;
			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
			cout << "-Search Account:\n" << endl;

			cout << "Enter the Account Number to be searched:";
			cin >> number;
			//If the Account is found, print "EXISTS", the account number and the account amound
			if (BankTree->Search(BankTree->root, number) == true) {
				Client* found = BankTree->Find(number);
				cout << "Valid Account!\n";
				cout << "====================================" << endl;
				cout<< "Account Number: " << found->AccountNumber << endl;
				cout << "Amount: " << found->Amount << "$"<< endl;
			} 
			else cout << "Not Found\n";
		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Delete an Account (Tree DS)
		case 3:
		{
			int number;
			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
			cout << "-Delete Account:" << endl;

			cout << "Enter the Account Number to be deleted:";
			cin >> number;
			BankTree->root = BankTree->DeleteAccount(BankTree->root, number);
			Sleep(3000);
			cout << "Account Deleted!\n";
			cout << "\n" << endl;
		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Find the Successor of an account in the tree Structure (Tree DS)
		case 4:
		{
			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
			cout << "-Account Successor:" << endl;

			int number;
			cout << "Enter the Account Number to find respective Sucessor:";
			cin >> number;
			cout << "\n=Request:" << endl;
			struct Client* successor = BankTree->Getsuccessor(BankTree->root, number);
			if (successor == NULL) cout << "No successor Found\n";
			else
				cout << "The successor is the Account Number: " << successor->AccountNumber << "\n";
		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Find the Height of the Root of this Binary tree database Structure (Tree DS)
		case 5:
		{
			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
			cout << "-Height of the Database Binary Tree" << endl;

			cout << "The Height of the Database Binary Tree root is: ";
			cout << BankTree->FindHeight(BankTree->root);
			cout << "\n\n";
		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Unlocking an Account (Queue DS)
		case 6:
		{
			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
			cout << "-Clients Account Re-Validation:\n" << endl;

			cout << "WARNING: \n!! For security reasons, the next Operation will delete Pins Database!!\n" << endl;

			while (!templateIDs->IsEmpty()) {
				Pins* obj = templateIDs->Remove();
				cout << "Client's Name: " << obj->name << "\tClient Temporary Pin: " << obj->key  << endl;
			}
		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Displat the Staff Database (Hash Table DS)
		case 7:
		{
			cout << "\n                            ==== Staff Database ====\n" << endl;
			StaffTable->Display();
			cout << "\n" << endl;

		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Registration of a New Employee (Hash Table DS)
		case 8:
		{
			string IDE;
			string newE;
			string Eyear = "0";

			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
				cout << "\n      ==== New Employee Registration ====\n" << endl;

				if (Eyear=="0")
				{
					cout << "Enter the New Employeer Name:";
					cin.get();
					getline(cin, newE);

					cout << "Enter the New Employeer ID:";
					cin.get();
					getline(cin, IDE);
				}

				StaffTable->Insert(new StaffInfoStr(IDE, newE, Eyear));
				cout << "\nNew Employee Added!\n";
		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Delete of a Staff Member (Hash Table DS)
		case 9:
		{
			string ID;

			cout << "====================================" << endl;
			cout << "\n=Request:" << endl;
			cout << "\n      ==== Firing an Employee ====\n" << endl;

			cout << "Enter Employeer ID:";
			cin >> ID;
			StaffTable->Delete(ID);
			cout << "====================================" << endl;
			cout << "Employee Deleted!\n";

		}break;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		default:
			cout << "Incorrect Command!!" << endl;
		}
	}
	system("pause");
	return 0;
}

