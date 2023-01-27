#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<array>
#include<memory>
#include<Windows.h>

using namespace std;

class Product {
    private:
        int productNumber;
        string productName;
        float productRate;
    public:
        Product();
        Product(int pNum, string pName, float pRate);
        int getNumber();
        string getName();
        float getRate();
        void setNumber(int value);
        void setName(string value);
        void setRate(int value);
};

Product::Product(){
    productNumber = 0;
    productName = "";
    productRate = 0.0;
}

Product::Product(int pNum, string pName, float pRate) 
    : productNumber(pNum), productName(pName), productRate(pRate)
{
    ofstream outProduct;
    outProduct.open("products.txt", ios::out | ios::app);
    outProduct << productNumber << ' ' << productName << ' ' << productRate << endl;
    outProduct.close();
    cout << "\n\t\t Product created successfully!" << endl;
    getch();
}

int Product::getNumber(){
    return productNumber;
}

string Product::getName(){
    return productName;
}

float Product::getRate(){
    return productRate;
}

void Product::setNumber(int value){
    productNumber = value;
}

void Product::setName(string value){
    productName = value;
}

void Product::setRate(int value){
    productRate = value;
}

class Bill {
    private:
        string date;
        float totalAmount;
    public:
        Bill();
        string getDate();
        float getTotalAmount();
};

Bill::Bill(){
    time_t now = time(0);
    char* dt = ctime(&now);    

    date = dt;
    totalAmount = 0.0;
}

string Bill::getDate(){
    return date;
}

float Bill::getTotalAmount(){
    return totalAmount;
}

class BillItems {
    private:
        std::unique_ptr<Product> product;
        int quantity;
    public:
        BillItems();
        void getItem(int code);
        int getQuantity();
        void setQuantity(int value);
        float getAmount();
        void showDetails();
};

BillItems::BillItems(){
    product = std::make_unique<Product>(Product());
}

void BillItems::getItem(int code){
    ifstream prod;
    prod.open("products.txt", ios::in);
    int pn; string pp; float pr;
    while(true){
        prod >> pn >> pp >> pr;
        if(pn == code){
            product->setNumber(pn);
            product->setName(pp);
            product->setRate(pr);
            break;
        }
    }
    prod.close();
}

void BillItems::setQuantity(int value){
    quantity = value;
}

float BillItems::getAmount(){
    float r; 
    r = product->getRate();
    return r * quantity;
}

int BillItems::getQuantity(){
    return quantity;
}

void BillItems::showDetails(){
    cout << "\t" <<setw(14) << product->getNumber() << "\n"
    << "\t" <<setw(12) << product->getName() << "\n"
    << "\t" <<setw(12) << product->getRate() << "\n"
    << "\t" <<setw(8) << getQuantity() << endl;
}

class Invoice : public Bill {
    private:
        int numOfItems;
        std::unique_ptr<BillItems> item[50];
};

class Controller {
    private:
        std::unique_ptr<Product> product;
    public:
        Controller();
        void createProduct();
        void displayProduct();
        void modifyProduct();
        void deleteProduct();
};

Controller::Controller(){}

void Controller::displayProduct(){
    system("cls");
    ifstream productFile;
    productFile.open("products.txt", ios::in);
    int lineNumber = 0; string line;

	cout << "\n\n\tDISPLAY ALL PRODUCTS"<<"\n\t============================================\n";
	if(!productFile.good()){
        cerr << " Could not read file. Make sure it has been created." << endl;
    }
    while(getline(productFile, line)){
        switch(lineNumber){
            case 1:
               cout << "\n\t" << line << "\n";
               break;
		    case 2: 
                cout << "\n\t" << line << "\n";
                break;
		    case 3:
                cout << "\n\t" << line << "\n";
                break;
            case 4:
                cout << "\n\t" << line << "\n";
                break;            
        }
        if(lineNumber == 4){
           lineNumber = 0;
        }
           lineNumber++;
           cout << "\n\t=================================================================";
    }
	//displaying on screen
    productFile.close();
	cout<<"\n\tPress any key";
	getch();
}

void Controller::createProduct(){
    system("cls");
    int n; string p; float r;

	cout << "\n\n\tENTER THE DETAILS OF THE PRODUCT" << endl;
	cout << "\n\tENTER THE PRODUCT NUMBER" << endl;
	cin >> n;
	cout << "\n\tENTER THE PRODUCT NAME" << endl;
	cin >> p;
	cout << "\n\tENTER THE PRODUCT RATE" << endl;
	cin >> r;
    product = std::make_unique<Product>(Product(n, p, r));

}

void Controller::modifyProduct(){
system("cls");
	displayProduct();//first display all products for the users to select the product
	ifstream prodIn;
	ofstream prodTmp;
	cout << "\n\t*****************************************************************";
	cout << "\n\tEnter the Product Number to Modify:\n";
	int modNum;
	cin >> modNum;
	prodIn.open("products.txt", ios::in);
	prodTmp.open("temp.txt", ios::out);
	int n;
	string p;
	float r;
	while (1)
	{
		prodIn >> n;
		if (prodIn.eof())
			break;
		prodIn >> p >> r;
		if (n == modNum)
		{
			cout << "\n\tEnter new rate:";
			cin >> r;
		}	
		prodTmp
			<< n
			<< ' '
			<< p
			<< ' '
			<< r
			<< endl;
		}
	prodIn.close();
	prodTmp.close();
	remove("products.txt");
	rename("temp.txt", "products.txt");
	cout << "\n\n\n\tPRODUCT RATE UPDATED SUCCESSFULLY";
	getch();
}


void Controller::deleteProduct(){
        system("cls");
		displayProduct();//first display all products for the users to select the product
		ifstream prodIn;
		ofstream prodTmp;
		cout << "\n\t*****************************************************************";
		cout << "\n\tEnter the Product Number to Delete:\n";
		int modNum;
		cin >> modNum;
		prodIn.open("products.txt", ios::in);
		prodTmp.open("temp.txt", ios::out);
		int n;
		string p;
		float r;
		while (1)
		{
			prodIn >> n;
			if (prodIn.eof())
				break;
			prodIn >> p >> r;
			if (n != modNum)
			{
				prodTmp
					<< n
					<< ' '
					<< p
					<< ' '
					<< r
					<< endl;
			}
		}
		prodIn.close();
		prodTmp.close();
		remove("products.txt");
		rename("temp.txt", "Products.txt");
		cout << "\n\n\n\tPRODUCT DELETED SUCCESSFULLY";
		getch();
}

class UI {
    private:
        std::unique_ptr<BillItems> billItems;
        std::unique_ptr<Bill> bill;
        std::unique_ptr<Controller> controller;
    public:
        UI();
        void intro();
        void user();
        void customer();
        void admin();
};

UI::UI(){
    billItems = std::make_unique<BillItems>(BillItems());
    bill = std::make_unique<Bill>(Bill());
    controller = std::make_unique<Controller>(Controller());
}

void UI::intro(){
    cout << "\n\n\n\tBILLING SYSTEM"<<endl;
	cout << "\n\t================================================================\n";
	cout << "\n\n\tMADE BY:";
	cout << "\n\n\tRishabh Kumar Varshney";
	cout << "\n\n\tRajnish Jha";
	cout << "\n\n\tNazar Kamal";
}

void UI::user(){
    int ch;
	system("cls");
    system("color 1f");
	cout << "\n\n\n\tMAIN MENU";
	cout << "\n\n\t1. CUSTOMER";
	cout << "\n\n\t2. ADMINISTRATOR";
	cout << "\n\n\t3. EXIT";
	cout << "\n\n\tPlease Select Your Option (1-3) : ";
	cin >> ch;
	switch (ch)
	{
	   case 1: 
            customer(); 
            break;
	   case 2: 
            admin(); 
            break;
	   case 3: 
            exit(0);
       default: 
            cout << " Invalid option!" << endl;
            user(); 
            break;
	}
}

void UI::customer(){
     int NumOfItems, code, qty;
	 array<BillItems*, 20> items;
     float amount, totalAmount;

	 system("cls");
     system("color 3e");
	 cout << "\n\n\tENTER THE NUMBER OF ITEMS: ";
	 cin >> NumOfItems;
	 controller->displayProduct(); //display all products

		for(int i = 0; i < NumOfItems; i++){
			cout << "\n\tENTER ITEM CODE: ";
			cin >> code;
			items.at(i)->getItem(code);
			cout << "\n\tENTER ITEM QUANTITY: ";
			cin >> qty;
			items.at(i)->setQuantity(qty);
		}
		for(int i = 0; i < NumOfItems; i++){
            amount = bill->getTotalAmount();
            totalAmount = amount + items.at(i)->getAmount();
        }
		cout << "\n\n\tINVOICE\t\t\tDate/Time:" << bill->getDate() << endl;
		cout << "\t======================================================================================================"<<endl;
		cout << "\tProduct Number\tProduct Name\tProduct Rate\tQuantity\tAmount" << endl;
		for (int i = 0; i < NumOfItems; i++){
			items.at(i)->showDetails();
			cout << setw(6) << items[i]->getAmount() << endl;
		}
		cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << totalAmount;
		cout << "\n\tThank You for Shopping" << endl;
		cout << "\n\tPress any key to continue...";
		getch();
}
        
void UI::admin(){
    system("cls");
    system("color 2a");
	 while (1){
		system("cls");
		int ch;
		cout << "\n\n\n\tADMIN MENU";
		cout << "\n\n\t1.CREATE PRODUCT";
		cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
		cout << "\n\n\t3.MODIFY PRODUCT";
		cout << "\n\n\t4.DELETE PRODUCT";
		cout << "\n\n\t5.BACK TO MAIN MENU";
		cout << "\n\n\tPlease Enter Your Choice (1-5) ";
		cin >> ch;
		switch (ch)
		{
			case 1: controller->createProduct(); break;
			case 2: controller->displayProduct(); break;
			case 3: controller->modifyProduct(); break;
			case 4: controller->deleteProduct(); break;
			case 5: user(); break;
			default: break;
		}
		
	}
}

int main(){
    std::unique_ptr<UI> billing_system = std::make_unique<UI>(UI());
    
    billing_system->intro();
    getch();
	system("cls");
    while(true){
        billing_system->user();
    }
    return 0;
}