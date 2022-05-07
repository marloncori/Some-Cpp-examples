#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Client {
	private:
		string name;
		string father;
		string mother;
		string address;
		const int age;
		string profession;
		const float salary;
	public:
		Client(string n, string f, string m, string p, 
		    string ad, const int age, const float salary);
		string getName();
		string getFather();
		string getMother();
		string getAddress();
		const int getAge();
		string getProfession();
		const float getSalary();
};

Client::Client( string n, string f, string m, string p, string ad, const int age, const float salary)
 : name(n), father(f), mother(m), profession(p), address(ad), age(age), salary(salary){}
 
string Client::getName(){
	return name;
}

string Client::getFather(){
	return father;	
}

string Client::getMother(){
	return mother;
}

string Client::getAddress(){
	return address;
}

string Client::getProfession(){
	return profession;
}

const int Client::getAge(){
	return age;
}

const float Client::getSalary(){
	return salary;
}

class Deposit{
	private:
		float value;
		int counter;
	public:
		Deposit(float val);
		float getValue();
		void newDeposit();
		int getCounter();	
};

Deposit::Deposit(float val) : value(val){
	newDeposit();
}

void Deposit::newDeposit(){
	counter++;
}

float Deposit::getValue(){
	return value;
}

int Deposit::getCounter(){
	return counter;
}

class Withdraw {
	private:
		float value;
		int counter;
	public:
		Withdraw(float val);
		float getValue();
		void newWithdraw();
		int getCounter();
};

Withdraw::Withdraw(float val) : value(val){
	newWithdraw();
}

void Withdraw::newWithdraw(){
	counter++;
}
float Withdraw::getValue(){
	return value;
}

int Withdraw::getCounter(){
	return counter;
}

enum State {
	ACTIVE,
	INACTIVE
};

enum Type {
	CURRENT,
	SAVINGS
};

class Account{
	private:
		Type type;
		State status;
		int category;
		float saldo;
		Deposit deposit;
		Withdraw withdraw;
	public:
		Account();
		Type getType();
		float getSaldo();
		State getStatus();
		bool makeDeposit(float amount);
		bool makeWithdraw(float amount);	
};

Account::Account(){
    category = 2;
    status = std::static_cast<State>(State::ACTIVE);
    deposit = new Deposit(0.0);
    withdraw = new Withdraw(0.0);
}

Type Account::getType(){
	if(category == 1){
		type = std::static_cast<Type>(Type::CURRENT);
		return type;
	}
	else {
		type = std::static_cast<Type>(Type::SAVINGS);
		return type;
	}
}

float Account::getSaldo(){
	return saldo;
}

State Account::getStatus(){
	return status;
}

bool Account::makeDeposit(float amount){
	if(amount == 0 ){
		cerr << " There is no amount to be depositted!" << endl; 
		return false;
	}
	deposit = new Deposit(getSaldo()+amount);
	return true;	
}

bool Account::makeWithdraw(float amount){
	if(amount == 0 ){
		cerr << " There is no amount to be withdrawn!" << endl; 
		return false;
	}
	withdraw = new Withdraw(getSaldo()-amount);
	return true;	
}
		
class Bank {
	private:
		Client client;
		Account account;
	public:
		void openAccount();
		void depositMoney();
		void withdrawMoney();
		void showInformation();
		void displayAccount();
};

void Bank::openAccount(){
	string name, father, mother, profession, address;
	int age, category; 
	float salary;
	
	cout << "\n >>> Enter below the needed information: "<< endl;
	cout << "\n  1. Full name: ";
	getline(cin, name);
	
	cout << "\n  2. Father\'s name: ";
	getline(cin, father);
	
	cout << "\n  3. Mother\'s name: ";
	getline(cin, mother);
	
	cout << "\n  4. Age: ";
	cin >> age;
	
	cout << "\n  5. Address: ";
	getline(cin, address);
	
	cout << "\n  6. Profession: ";
	getline(cin, profession);
	
	cout << "\n  7. Salary: ";
	cin >> salary;
	client = new Client(name, father, mother, profession, address, age, salary);
	
	cout << "\n\n  >>> Choose a type of account: " << endl;
	cout << "\n\t ( 1 ) current" << endl;
	cout << "\n\t ( 2 ) savings" << endl;
	cout << "\t Option: ";
	cin >> category;
	account = new Account(category);
	cout << "\n   Your account has been successfully created!" << endl;
}

void Bank::showInformation(){
	cout << "\n\n  See below your information: " << endl;
	cout << "\n  > 1. Full name: " << client.getName() << endl;
	cout << "\n  > 2. Father\'s name: " << client.getFather() << endl;
	cout << "\n  > 3. Mother\'s name: " << client.getMother() << endl;
	cout << "\n  > 4. Age: " << client.getAge() << endl;
	cout << "\n  > 5. Address: " << client.getAddress() << endl;
	cout << "\n  > 6. Profession: " << client.getProfession() << endl;
	cout << "\n  > 7. Salary: " << client.getSalary() << endl;
	cout << "\n  > 8. Type of account: " << account.getType() << endl;
	cout << "\n  > 9. Account status: " << account.getStatus() << endl;
	cout << "\n  > 10. Account saldo: " << account.getSaldo() << endl;
}

/*void Bank::depositMoney(){
	
}
void Bank::withdrawMoney(){
}
void Bank::displayAccount(){
}*/
		
int main(){
	Bank PKO_BP = new Bank();
	
	PKO_BP.openAccount();
	PKO_BP.showInformation();
	
	return 0;
}
