#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <memory>
#include <chrono>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	

class Client {
	private:
		string name;
		string father;
		string mother;
		string address;
		int age;
		string profession;
		float salary;
	public:
		Client(string n, string f, string m, string p, 
		    string ad, int age, float salary);
		//~Client();
		string getName();
		string getFather();
		string getMother();
		string getAddress();
		const int getAge();
		string getProfession();
		const float getSalary();
};

Client::Client( string n, string f, string m, string p, string ad, int age, float salary)
 : name(n), father(f), mother(m), profession(p), address(ad), age(age), salary(salary){}

/*Client::~Client(){
	free(this);
}*/

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

class Logger {
	private:
		string successMsg;
		string errMsg;
	public:
		Logger();
		//~Logger();
		string getSuccessMsg();
		string getErrMsg();
		void saveRecord(std::stringstream& contents);
};

Logger::Logger(){}

/*Logger::~Logger(){
	free(this);
}*/

string Logger::getSuccessMsg(){
	successMsg = "\033[1;35m\t\t[ INFO ]\033[0m \033[1;34mOperation successfully performed!\033[0m";
	return successMsg;
}

string Logger::getErrMsg(){
	errMsg = "\033[1;32m\t\t[ WARNING ]\033[0m \033[1;36mAn unexpected error happened! \n\t\t Operation not succeeded.\033[0m";
	return errMsg;
}

void Logger::saveRecord(std::stringstream& contents){
	std::fstream file;
	file.open("transactions.txt", std::ios::out | std::ios::app);
	file << contents.str();
	file.close();
}

class Deposit{
	private:
		float value;
		int counter;
	public:
		Deposit(float val);
		//~Deposit();
		float getValue();
		void newDeposit();
		int getCounter();	
};

Deposit::Deposit(float val) : value(val){
	newDeposit();
}

/*Deposit::~Deposit(){
	free(this);
}*/

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
		//~Withdraw();
		float getValue();
		void newWithdraw();
		int getCounter();
};

Withdraw::Withdraw(float val) : value(val){
	newWithdraw();
}

/*Withdraw::~Withdraw(){
	free(this);
}*/

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

class Password {
	private:
		string pin;
		string secretQuestion;
	public:
		Password(string pin);
		//~Password();
		string getPin();
		bool reset(string newPin);
		string askSecretQuestion();
		bool validate();
};

Password::Password(string pin) : pin(pin){
	secretQuestion = "\n What are your university enrollment code first four digits?";
}

/*Password::~Password(){
	free(this);
}*/

string Password::getPin(){
	return pin;
}

bool Password::reset(string newPin){
	pin = newPin;
	bool approved = validate();
	if(approved){
		return true;
	}
	cerr << "\n\t No new password has been set. Try again." << endl;
	return false;
}

bool Password::validate(){
	if(pin.size() != 4){
		cerr << "\n\t Password length not valid.\n\t It should have 4 characters." << endl;
		return false;
	}
	return true;
}

string Password::askSecretQuestion(){
	return secretQuestion;
}

class CreationDate {
	private:
		time_t time;
	public:
		CreationDate();
		//~CreationDate();
		string getTime();
};

CreationDate::CreationDate(){
	time = chrono::system_clock::to_time_t(chrono::system_clock::now());
}

/*CreationDate::~CreationDate(){
	free(this);
}*/

string CreationDate::getTime(){
    string date(30, '\0');
    strftime(&date[0], date.size(), "%d-%m-%Y %H:%M:%S", std::localtime(&time));
	return date;
}

class Account{
	private:
		Type type;
		State status;
		int category;
		float saldo;
		std::unique_ptr<Deposit> deposit;
		std::unique_ptr<Withdraw> withdraw;
		std::unique_ptr<Password> password;
		std::unique_ptr<CreationDate> creationDate;
	public:
		Account(int category, string pin);
		//~Account();
		Type getType();
		float getSaldo();
		State getStatus();
		string getPassword();
		string getCreationDate();
		bool validatePassword(string pin);
		bool resetPassword(string pin);
		bool makeDeposit(float amount);
		bool makeWithdraw(float amount);	
};

Account::Account(int category, string pin) : category(category){
	saldo = 0.0;
    status = State::ACTIVE;
    deposit = std::make_unique<Deposit>(Deposit(0.0));
    withdraw = std::make_unique<Withdraw>(Withdraw(0.0));
	password = std::make_unique<Password>(Password(pin));
	creationDate = std::make_unique<CreationDate>(CreationDate());
}

/*Account::~Account(){
	free(this);
}*/

Type Account::getType(){
	if(category == 1){
		type = Type::CURRENT;
		return type;
	}
	else {
		type = Type::SAVINGS;
		return type;
	}
}

float Account::getSaldo(){
	return saldo;
}

State Account::getStatus(){
	return status;
}

string Account::getPassword(){
	return password->getPin();
}

bool Account::resetPassword(string pin){
	bool result = password->reset(pin);
	return result;
}

string Account::getCreationDate(){
	return creationDate->getTime();
}

bool Account::validatePassword(string pin){
	bool ok = resetPassword(pin);
	if(ok){
		return true;
	}
	return false;
}

bool Account::makeDeposit(float amount){
	if(amount == 0 ){
		cerr << "\t There is no amount to be depositted!" << endl; 
		return false;
	}
	deposit = std::make_unique<Deposit>(Deposit(getSaldo()+amount));
    
	saldo = deposit->getValue();
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\t\t ---> This your account balance: $ " << getSaldo() << endl;
	SetConsoleTextAttribute(hConsole, 15);

	return true;	
}

bool Account::makeWithdraw(float amount){
	bool done = false;
	if(amount == 0 ){
		cerr << " There is no amount to be withdrawn!" << endl; 
		return done;
	}
	if(amount < getSaldo() && (getSaldo()-amount) > 0){
		withdraw = std::make_unique<Withdraw>(Withdraw(saldo-amount));
		if(getSaldo() == 0){
			cout << "\n\t  WARNING: There are no more resources in your account. \n\t  This is your current balance: " 
			<< getSaldo() << endl;
		}
		done = !done;
	}
	else{
		cerr << "\n\t  There is not enough money in account now. \n\t  This is your current balance: " 
		<< getSaldo() << ". \n\t   Maybe try and withdraw a smaller amount later." << endl;
		done = false;
	}
	return done;	
}

void footer(){
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\n\t-------------------------------------------" << endl;
	cout << "\t|    Thank you for choosing our software! |" << endl;
	cout << "\t-------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void clearScreen(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t Press any key to continue..." << endl;
    SetConsoleTextAttribute(hConsole, 15);
	getch();
	system("cls");	
}

class Bank {
	private:
		std::unique_ptr<Client> client;
		std::unique_ptr<Account> account;
		std::unique_ptr<Logger> logger;
	public:
		Bank();
		//~Bank();
		void accountHeader(int mode);
		void openAccount();
		void depositMoney();
		void withdrawMoney();
		 int bankMenu();
		void setNewPassword();
		void showInformation();
		void displayAccount();
};

Bank::Bank(){
	logger = std::make_unique<Logger>(Logger());
}

/*Bank::~Bank(){
	free(this);
}*/

void Bank::accountHeader(int mode){
	switch(mode){
		case 1:
			SetConsoleTextAttribute(hConsole, 13);
			cout << endl;
			cout << "\t    ----------------------------------" << endl;
			cout << "\t    |  ~~ OPEN A NEW BANK ACCOUNT ~~ |" << endl;
			cout << "\t    ----------------------------------" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			break;
		case 2:
			SetConsoleTextAttribute(hConsole, 13);
			cout << endl;
			cout << "\t    ===================================" << endl;
			cout << "\t    | ::: DEPOSIT TO BANK ACCOUNT ::: |" << endl;
			cout << "\t    ===================================" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			break;
		case 3:
			SetConsoleTextAttribute(hConsole, 13);
			cout << endl;
			cout << "\t    -----------------------------------------" << endl;
			cout << "\t    |  ++ DISPLAY ACCOUNT CURRENT STATUS ++ |" << endl;
			cout << "\t    -----------------------------------------" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			break;
		default:
			break;
	}
}

void Bank::openAccount(){
	accountHeader(1);
	string name, father, mother, profession, address;
	int age, category; string pin, repetition;
	float salary, balance;
	string initialPassword = "asdf$%$%^$YUIdfrewtpf4r198721";

	char buffer[1024];
	setvbuf(stdout, buffer, _IOFBF, 1024);
	
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n\t-------------------------------------------" << endl;
	cout << "\t| >>> Enter below the needed information: |"<< endl;
	cout << "\t-------------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
	cout << "\t|" << endl;
	cout << "\n\t|\t  1. Full name: ";
	std::getline(std::cin, name);
	Sleep(1);
	cout << "\t|" << endl;

	cout << "\n\t|\t  2. Father\'s name: ";
	std::getline(std::cin, father);
	Sleep(1);
	cout << "\t|" << endl;
	cout << "\n\t|\t  3. Mother\'s name: ";
	std::getline(std::cin, mother);
	Sleep(1);

	cout << "\t|" << endl;
	cout << "\n\t|\t  4. Age: ";
	cin >> age;
	cout << "\t|" << endl;
	fflush(stdout);	
	cout << "\n\t|\t  5. Address: ";
	std::getline(std::cin, address);
	Sleep(1);

	cout << "\t|" << endl;
	cout << "\n\t|\t  6. Profession: ";
	cin >> profession;
	Sleep(1);

	cout << "\t|" << endl;
	cout << "\n\t|\t  7. Salary: ";
	cin >> salary;
	client = std::make_unique<Client>(Client(
		name, father, mother, profession, address, age, salary));
	cout << "\t|" << endl;
	cout << "\t|" << endl;
	cout << "\n\n\t|\t  >>> Choose a type of account: " << endl;
	cout << "\t|" << endl;
	cout << "\n\t|\t ( 1 ) current" << endl;
	cout << "\t|" << endl;
	cout << "\n\t|\t ( 2 ) savings" << endl;
	cout << "\t|" << endl;
	cout << "\n\t|\t Option: ";
	cin >> category;
	account = std::make_unique<Account>(Account(category, initialPassword));
	cout << "\t|" << endl;
	
	cout << "\t|\t  Now choose four numeric digits for the password: " << endl;
	cout << "\t|\t\t >>> Pin: ";
	cin >> pin;
	cout << "\t|\t\t >>> Repeat password: ";
	cin >> repetition;
	if(pin.compare(repetition) != 0){
		setNewPassword();
	}
	else{
		bool approved = account->validatePassword(pin);
		if(approved){
			bool result = account->resetPassword(pin);
			if(result){
				cout << "\t|\t" << logger->getSuccessMsg() << endl;
			} else {
				cout << "\t|\t" << logger->getErrMsg() << endl;
				setNewPassword();
			}
		}
		else{
			cout << "\t|\t" << logger->getErrMsg() << endl;
			setNewPassword();	
		}
		cout << "\t|\t  Enter the amount of your first deposit: ";
		cin >> balance;
		account->makeDeposit(balance);
    	cout << "\t|" << endl;
		cout << "\n\t|   Your account has been successfully created!" << endl;
	}
}

void Bank::setNewPassword(){
	string pin, repetition;
	cout << "\t|\t  Choose four numeric digits for the password: " << endl;
	cout << "\t|\t\t >>> Pin: ";
	cin >> pin;
	cout << "\t|\t\t >>> Repeat password: ";
	cin >> repetition;
	bool approved = account->validatePassword(pin);
	if(approved && pin.compare(repetition) == 0){
		bool result = account->resetPassword(pin);
		if(result){
			cout << "\t|\t" << logger->getSuccessMsg() << endl;
			return;
		}
		else{
			cout << "\t|\t" << logger->getErrMsg() << endl;
			setNewPassword();
		}
	}else{
		cout << "\t|\t" << logger->getErrMsg() << endl;
		setNewPassword();
	}
}

void Bank::showInformation(){
	std::stringstream contents;
	char buffer[1024];
	setvbuf(stdout, buffer, _IOFBF, 1024);
	system("cls");
	accountHeader(1);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n\t--------------------------------------------" << endl;
	contents << "\n\t-------------------------------------------" << endl;
	cout << "\t|        See below your information:      |" << endl;
	contents << "\t|        See below your information:      |" << endl;
	cout << "\t-------------------------------------------" << endl;
	contents << "\t-------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 15);

	cout << "\n\t|  > 1. Full name: " << client->getName() << endl;
	contents << " |  > 1. Full name: " << client->getName() << "\n";
	cout << "\t|  > 2. Father\'s name: " << client->getFather() << endl;
	contents << "\t|  > 2. Father\'s name: " << client->getFather() << endl;
	cout << "\t|  > 3. Mother\'s name: " << client->getMother() << endl;
	contents << "\t|  > 3. Mother\'s name: " << client->getMother() << endl;
	cout << "\t|  > 4. Age: " << client->getAge() << endl;
	contents << "\t|  > 4. Age: " << client->getAge() << endl;
	fflush(stdout);
	cout << "\t|  > 5. Address: " << client->getAddress() << endl;
	contents << "\t|  > 5. Address: " << client->getAddress() << endl;
	cout << "\t|  > 6. Profession: " << client->getProfession() << endl;
	contents << "\t|  > 6. Profession: " << client->getProfession() << endl;
	cout << "\t|  > 7. Salary: " << client->getSalary() << endl;
	contents << "\t|  > 7. Salary: " << client->getSalary() << endl;
	cout << "\t|  > 8. Type of account: " << (account->getType()  == Type::CURRENT ? " CURRENT " : " SAVINGS ") << endl;
	cout << "\t|  > 9. Account status: " << (account->getStatus() == State::ACTIVE ? " ACTIVE " : " INACTIVE ") << endl;
	contents << "\t|  > 8. Type of account: " << (account->getType()  == Type::CURRENT ? " CURRENT " : " SAVINGS ") << "\n" 
	<< "\t|  > 9. Account status: " << (account->getStatus() == State::ACTIVE ? " ACTIVE " : " INACTIVE ") << endl;
	cout << "\t|  > 10. Account saldo: " << account->getSaldo() << endl;
	contents << "\t|  > 10. Account saldo: " << account->getSaldo() << endl;
	contents << "\t|  > 11. Account password: " << account->getPassword() << endl;
	contents << "\t|  > 12. Creation date: " << account->getCreationDate() << endl;
	logger->saveRecord(contents);

	cout << "\n\t|  " << logger->getSuccessMsg() << endl;
	footer();
}

void Bank::displayAccount(){
char buffer[1024];
	setvbuf(stdout, buffer, _IOFBF, 1024);
	system("cls");
	accountHeader(1);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n\t--------------------------------------------------" << endl;
	cout << "\t|   Check below your savings account information:  |" << endl;
	cout << "\t----------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 15);

	cout << "\t|  >> 1) Account bearer: " << client->getName() << endl;
	cout << "\t|  >> 2) Type of account: " << (account->getType()  == Type::CURRENT ? " CURRENT " : " SAVINGS ") << endl;
	cout << "\t|  >> 3) Account status: " << (account->getStatus() == State::ACTIVE ? " ACTIVE " : " INACTIVE ") << endl;
	cout << "\t|  >> 4) Personal password: " << account->getPassword() << endl;
	cout << "\t|  >> 5) Current balance:" << account->getSaldo() << endl;
	cout << "\t|  >> 6) Date of creation: " << account->getCreationDate() << endl;
	fflush(stdout);
	cout << "\n\t|  " << logger->getSuccessMsg() << endl;
	footer();
}

void Bank::depositMoney(){
	accountHeader(2);
	float newAmount;
	
	char buffer[1024];
	setvbuf(stdout, buffer, _IOFBF, 1024);
	
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n\t------------------------------------------------" << endl;
	cout << "\t| >>> Tell us below the amount to be depositted: |"<< endl;
	cout << "\t--------------------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);

    cout << "\t|\t Value: $ ";
	cin >> newAmount;
	bool success = account->makeDeposit(newAmount);
	if(success){
		cout << logger->getSuccessMsg() << endl;
	}
	else {
		cout << logger->getErrMsg() << endl;
	}
	footer();
}

void Bank::withdrawMoney(){
	accountHeader(3);
	float amount;
	
	char buffer[1024];
	setvbuf(stdout, buffer, _IOFBF, 1024);
	
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\n\t----------------------------------------------------" << endl;
	cout << "\t| >>> Tell us below the amount you want to withdraw: |"<< endl;
	cout << "\t------------------------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);

    cout << "\t|\t Withdrawal: $ ";
	cin >> amount;
	bool success = account->makeWithdraw(amount);
	if(success){
		cout << logger->getSuccessMsg() << endl;
		cout << "\n\t ---> Now this your account balance: " << account->getSaldo() << endl;
	}
	else {
		cout << logger->getErrMsg() << endl;
		clearScreen();
		bankMenu();
	}
	footer();
}

int Bank::bankMenu(){
	int opt = 0;
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	cout << "\t ---------------------------------" << endl;
	cout << "\t |  Select one option from menu: |" << endl;
	cout << "\t ---------------------------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t 1. Open account" << endl;
	cout << "\t\t 2. Make deposit" << endl;
	cout << "\t\t 3. Withdraw money" << endl;
	cout << "\t\t 4. Account status" << endl;
	cout << "\t\t 5. Exit application" << endl;
	cout << endl;
	cout << "\t >>> Your option --> ";
	cin >> opt;

	return opt;
}

/*void Bank::withdrawMoney(){
}*/

std::unique_ptr<Bank> PKO_BP = std::make_unique<Bank>(Bank());
void bms()
{
	cout << endl;
	SetConsoleTextAttribute(hConsole, 3);
	cout << "\t   BBBBBBBBBBBBB        MMMMM       MMMMM      SSSSSSSS     " << endl;
	cout << "\t   B:::B     B:::B      M::::M     M::::M     S::SSSSS::S   " << endl;
	cout << "\t   B:::B      B:::B     M:::::M   M:::::M    S::S     SSSS  " << endl;
	cout << "\t   B:::B-B-B-B:::B      M::::::M M::::::M    S::S           " << endl;
	cout << "\t   B::::::::::::B       M:::M:::M:::M:::M     S::SSSSSSS    " << endl;
	cout << "\t   B:::B-B-B-B:::B      M:::M M:::M M:::M       SSSSSSS::S  " << endl;
	cout << "\t   B:::B       B:::B    M:::M  M:M  M:::M              S::S " << endl;
	cout << "\t   B:::B      B:::B     M:::M   M   M:::M     SSSS     S::S " << endl;
	cout << "\t   B:::B     B:::B      M:::M       M:::M      S::SSSSS::S  " << endl;
	cout << "\t   BBBBBBBBBBBBB        MMMMM       MMMMM       SSSSSSSS    " << endl;
	SetConsoleTextAttribute(hConsole, 15); 	
}

void header(){
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "\t  ******************************************************" << endl;
	cout << "\t  ***********  BANKING  MANAGEMENT  SYSTEM  ***********" << endl;
    cout << "\t  *****************************************************" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void startApp(int option){
	if(!isdigit(option)){
		cerr << "\t  The option should be a number!" << endl;
	}
	if(option == 0){
		cerr << "\t  There is no such option!" << endl;
	}
	switch(option){
		case 1:
			bms();
			header();
			PKO_BP->openAccount();
			system("cls");
			PKO_BP->showInformation();
			clearScreen();
			break;
		case 2:
			bms();
			header();
			PKO_BP->depositMoney();
			clearScreen();
			break;
		case 3:
			bms();
			header();
			PKO_BP->withdrawMoney();
			clearScreen();
			break;
		case 4:	
			bms();
			header();
			PKO_BP->displayAccount();
			clearScreen();
			break;
		case 5:
			bms();
			header();
			cout << "\t\t See you next time! " << endl;
			footer();
			break;
		default:
			cerr << "\t\t >>> Invalid option. Try again!" << endl;
			option = PKO_BP->bankMenu();
			startApp(option);
			break;
	}
}

main(){
	int option = 0;

	bms();
	header();
	cout << endl;
	option = PKO_BP->bankMenu();
	clearScreen();

	while(option < 5){
		startApp(option);
		bms();
		header();
		option = PKO_BP->bankMenu();
		clearScreen();
		SetConsoleTextAttribute(hConsole, 15);
	}

	getch();
}
