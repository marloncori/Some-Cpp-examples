#include <iostream>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

void clearScreen();
void hms();
bool adminLogin();
void header();
int menu();
void adminHeader();
int adminMenu();
void addDoctor();
void viewDoctors();
void sortDoctors();
void updateDoctors();
void deleteDoctors();
void updateSalaries();
void viewPayments();
void viewReview();
void editManual();
void doctorHeader();
bool doctorLogin();
int doctorMenu();
void addPatient();
void sortPatients();
void viewPatients();
void updatePatients();
void deletePatients();
void registerPrescription();
void makeAppointments();
void viewAppointments();
void updateAppointments();
void deleteAppointments();
void generateReports();
void editFees();
void patientHeader();
int patientMenu();
void viewPrescriptions();
void viewReports();
void viewLabResults();
void viewDoctorFees();
void billPayments();
void giveReviews();
void manual();
// --------- functions for file handling ----- //
string parseRecord(int field, string line);
void storeOne();
void loadOne();
void loadDoctors(string lineOne);
void storeTwo();
void loadTwo();
void loadPatients(string lineTwo);
void storeThree();
void loadThree();
void loadPrescriptions(string lineThree);
void storeFour();
void loadFour();
void loadAppointments(string lineFour);
void storeFive();
void loadFive();
void loadReports(string lineFive);
void storeSix();
void loadSix();
void loadPayments(string lineSix);
void storeSeven();
void loadSeven();
// ---- validity checker -----------//
bool validityChecker();
bool contactValidation();
//---------- data structures (arrays, variables) ---//
const int MAX_RECORDS {50};
int doctorCount {0};
string doctorId[MAX_RECORDS];
string doctorPassword[MAX_RECORDS];
string doctorNames[MAX_RECORDS];
int doctorAges[MAX_RECORDS];
string doctorAddress[MAX_RECORDS];
string doctorQualification[MAX_RECORDS];
int doctorSalary[MAX_RECORDS];
string doctorContact[MAX_RECORDS];

int patientCount {0};
int prescriptionCount {0};
int appointmentCount {0};
int reportsCount {0};
int checkupFees {2000};
int paymentCount {0};
int reviewCount {0};

string patientId[MAX_RECORDS];
string patientDisease[MAX_RECORDS];
string patientName[MAX_RECORDS];
int patientAge[MAX_RECORDS];
string patientMedicine[MAX_RECORDS];
string patientAddress[MAX_RECORDS];
string patientContact[MAX_RECORDS];

string prescriptionId[MAX_RECORDS];
string addPrescription[MAX_RECORDS];

string appointmentId[MAX_RECORDS];
string appointmentDay[MAX_RECORDS];
string appointmentTime[MAX_RECORDS];

string reportsId[MAX_RECORDS];
string test[MAX_RECORDS];
string result[MAX_RECORDS];

string paymentId[MAX_RECORDS];
int payments[MAX_RECORDS];

string reviews[MAX_RECORDS];

//----- validity checker--------//
string num;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{
    loadOne();
    loadTwo();
    loadThree();
    loadFour();
    loadFive();
    loadSix();
    loadSeven();
    system("cls");
    hms();
    header();
    int option = menu();
    clearScreen();
    while(option < 5) // we have set loop value true so loop will
    // keep running, we will apply some kind of cond to break it
    {
        if(option == 1)
        {
            hms();
            header();
            adminHeader();
            if(adminLogin())
            {
                clearScreen();
                hms();
                header();
                adminHeader();
                int adminOption = adminMenu();
                clearScreen();
                while(adminOption < 12){
                    if(adminOption == 1)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << " Add record" << endl;
                        cout << "-------------" << endl;
                        cout << endl;
                        if(doctorCount < MAX_RECORDS)
                        {
                            addDoctor();
                            storeOne();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No more capacity" << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 2)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << " View doctors (sorted according to salary)" << endl;
                        cout << "----------------------------------------------" << endl;
                        cout << endl;
                        if(doctorCount >= 1)
                        {
                            sortDoctors();
                            viewDoctors();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 3)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << " Update records " <<endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        if(doctorCount >= 1)
                        {
                            updateDoctors();
                        }
                        else 
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 4)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << " Delete records " <<endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        if(doctorCount >= 1)
                        {
                            deleteDoctors();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 5)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << " View patients (sorted according to age)" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            viewPatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 6)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << " View appointments " << endl;
                        cout << "--------------------" << endl;
                        cout << endl;
                        if(appointmentCount >= 1)
                        {
                            viewAppointments();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet" << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 7)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << " Update salaries " << endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        if(doctorCount >= 1)
                        {
                            updateSalaries();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet" << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 8)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << " View checkup fees " << endl;
                        cout << "-------------------" << endl;
                        cout << endl;
                        viewDoctorFees();
                        clearScreen();
                    }
                    if(adminOption == 9)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << " View bill payments " << endl;
                        cout << "-------------------" << endl;
                        cout << endl;
                        if(paymentCount >= 1)
                        {
                            viewPayments();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No payments yet." << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 10)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << " View reviews by patients " << endl;
                        cout << "--------------------------" << endl;
                        cout << endl;
                        if(reviewCount >= 1)
                        {
                            viewReview();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet" << endl;
                        }
                        clearScreen();
                    }
                    if(adminOption == 11)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "  Edit Instruction Manual " << endl;
                        cout << "--------------------------" << endl;
                        cout << endl;
                        editManual();
                        clearScreen();
                    }
                    hms();
                    header();
                    adminHeader();
                    adminOption = adminMenu();
                    clearScreen();
                }
            }
            else
            {
                cout << endl;
                cout << " Wrong Username or Password." << endl;
                cout << endl;
                clearScreen();
            }
        }
        if(option == 2)
        {
            hms();
            header();
            adminHeader();
            if(doctorLogin())
            {
                clearScreen();
                hms();
                header();
                doctorHeader();
                int doctorOpt = doctorMenu();
                clearScreen();
                while(doctorOpt < 15)
                {
                    if(doctorOpt == 1)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Add Patient" << endl;
                        cout << "--------------" << endl;
                        cout << endl;
                        if(patientCount < MAX_RECORDS)
                        {
                            addPatient();
                            storeTwo();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No more capacity." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 2 )
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " View patients (sorted according to age)" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            sortPatients();
                            viewPatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 3)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Update patients" << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            updatePatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();   
                    }
                    if(doctorOpt == 4)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Delete patients" << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            deletePatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();   
                    }
                    if(doctorOpt == 5)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Add prescriptions " << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(prescriptionCount >= 1)
                        {
                            registerPrescription();
                            storeThree();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 6)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Make appointments " << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            makeAppointments();
                            storeFour();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No patients to make an appointment with." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 7)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " View appointments " << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(appointmentCount >= 1)
                        {
                            viewAppointments();
                            storeFour();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No appointments to be displayed." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 8)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Update appointments " << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(appointmentCount >= 1)
                        {
                            updateAppointments();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No appointments to be displayed." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 9)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Cancel appointments " << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(appointmentCount >= 1)
                        {
                            deleteAppointments();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No appointments to be displayed." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 10)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " Generate reports " << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            generateReports();
                            storeFive();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 11)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << " View lab test reports " << endl;
                        cout << "-----------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            viewLabResults();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 12)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << endl;
                        cout << "  Edit checkup fees " << endl;
                        cout << "---------------------" << endl;
                        cout << endl;
                        editFees();
                    }
                    if(doctorOpt == 13)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "  View reviews by patients " << endl;
                        cout << "---------------------------" << endl;
                        cout << endl;
                        if(patientCount >= 1)
                        {
                            viewReview();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No reviews yet." << endl;
                        }
                        clearScreen();
                    }
                    if(doctorOpt == 14)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "  View bill payments " << endl;
                        cout << "---------------------" << endl;
                        cout << endl;
                        if(paymentCount >= 1)
                        {
                            viewPayments();
                        }
                        else
                        {
                            cout << endl;
                            cout << " No payments recorded yet." << endl;
                        }
                        clearScreen();
                    }
                    hms();
                    header();
                    doctorHeader();
                    doctorOpt = doctorMenu();
                    clearScreen();
                }
            }
            else
            {
                cout << endl;
                cout << " Wrong Username or Password." << endl;
                cout << endl;
                clearScreen();
            }
                        
        }
        if(option == 3)
        {
            hms();
            header();
            patientHeader();
            int patientOpt = patientMenu();
            clearScreen();
            while(patientOpt < 8)
            {
                if(patientOpt == 1)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << " View appointments " << endl;
                    cout << "------------------" << endl;
                    cout << endl;
                    if(appointmentCount >= 1)
                    {
                        viewAppointments();
                    }
                    else
                    {
                        cout << endl;
                        cout << " No appointments scheduled." << endl;
                    }
                    clearScreen();                    
                }
                if(patientOpt == 2)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << " View prescriptions " << endl;
                    cout << "------------------" << endl;
                    cout << endl;
                    if(prescriptionCount >= 1)
                    {
                        viewPrescriptions();
                    }
                    else
                    {
                        cout << endl;
                        cout << " No prescriptions to be displayed." << endl;
                    }
                    clearScreen();                    
                }
                if(patientOpt == 3)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << " View reports " << endl;
                    cout << "--------------" << endl;
                    cout << endl;
                    if(reportsCount >= 1)
                    {
                        viewReports();
                    }
                    else
                    {
                        cout << endl;
                        cout << " No reports generated yet." << endl;
                    }
                    clearScreen();                    
                }
                if(patientOpt == 4)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << " View lab results " << endl;
                    cout << "------------------" << endl;
                    cout << endl;
                    if(patientCount >= 1)
                    {
                        viewLabResults();
                    }
                    else
                    {
                        cout << endl;
                        cout << " No results recorded yet." << endl;
                    }
                    clearScreen();                    
                }
                if(patientOpt == 5)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << " View doctor fees " << endl;
                    cout << "------------------" << endl;
                    cout << endl;
                    viewDoctorFees();
                    clearScreen();                    
                }
                if(patientOpt == 6)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << " View bill payment " << endl;
                    cout << "-------------------" << endl;
                    cout << endl;
                    if(patientCount >= 1)
                    {
                        billPayments();
                        storeSix();
                    }
                    else
                    {
                        cout << endl;
                        cout << " No results recorded yet." << endl;
                    }
                    clearScreen();                    
                }
                if(patientOpt == 7)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << " Add review " << endl;
                    cout << "------------" << endl;
                    cout << endl;
                    if(patientCount >= 1)
                    {
                        giveReviews();
                        storeSeven();
                    }
                    else
                    {
                        cout << endl;
                        cout << " No results recorded yet." << endl;
                    }
                    clearScreen();                    
                }
                hms();
                header();
                patientHeader();
                patientOpt = patientMenu();
                clearScreen();
            }
        }
        if(option == 4)
		{	
        	hms();
            header();
            manual();
            clearScreen();
		}
		hms();
		header();
		option = menu();
		clearScreen();
		SetConsoleTextAttribute(hConsole, 15);
    }
}

//------ function definitions ------ //
void clearScreen()
{
	cout << endl;
	SetConsoleTextAttribute(hConsole, 14);
	cout << " Press any key to continue..." << endl;
    SetConsoleTextAttribute(hConsole, 15);
	getch();
	system("cls");	
}

void hms()
{
	cout << endl;
	SetConsoleTextAttribute(hConsole, 3);
	cout << "\t   HHHHH       HHHHH      MMMMM       MMMMM      SSSSSSSS     " << endl;
	cout << "\t   H:::H       H:::H      M::::M     M::::M     S::SSSSS::S   " << endl;
	cout << "\t   H:::H       H:::H      M:::::M   M:::::M    S::S     SSSS  " << endl;
	cout << "\t   H:::H-H-H-H-H:::H      M::::::M M::::::M    S::S           " << endl;
	cout << "\t   H:::::::::::::::H      M:::M:::M:::M:::M     S::SSSSSSS    " << endl;
	cout << "\t   H:::H-H-H-H-H:::H      M:::M M:::M M:::M       SSSSSSS::S  " << endl;
	cout << "\t   H:::H       H:::H      M:::M  M:M  M:::M              S::S " << endl;
	cout << "\t   H:::H       H:::H      M:::M   M   M:::M     SSSS     S::S " << endl;
	cout << "\t   H:::H       H:::H      M:::M       M:::M      S::SSSSS::S  " << endl;
	cout << "\t   HHHHH       HHHHH      MMMMM       MMMMM       SSSSSSSS    " << endl;
	SetConsoleTextAttribute(hConsole, 15); 	
}

bool adminLogin(){
	string ID, password, username = "marloncori";
	cout << " Enter user id and password below." << endl;
	cout << endl;
	cout << "\t\tUser ID: ";
	getline(cin, ID);
	cout << "\t\tPassword: ";
	getline(cin, password);
	if(ID.compare(username) == 0 && password.compare("Mc0489921") == 0){
		return true;
	}
	return false;
}

void header(){
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "\t  *************************************************" << endl;
	cout << "\t  *********  HOSPITAL  MANAGEMENT  SYSTEM *********" << endl;
    cout << "\t  *************************************************" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}

int menu(){
	int option = 0;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\t\t\t----------------------" << endl;
	cout << "\t\t\t|    Main   Menu     |" << endl;
	cout << "\t\t\t----------------------" << endl;
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	cout << " ---------------------------------" << endl;
	cout << " |  Select one option from menu: |" << endl;
	cout << " ---------------------------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t 1. Admin" << endl;
	cout << "\t 2. Doctor" << endl;
	cout << "\t 3. Patient" << endl;
	cout << "\t 4. Instruction manual" << endl;
	cout << "\t 5. Exit" << endl;
	cout << endl;
	cout << " >>> Your option --> ";
	cin >> option;
	return option;
}

void adminHeader(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\t\t\t -----------------------" << endl;
	cout << "\t\t\t |    Admin   Menu     |" << endl;
	cout << "\t\t\t -----------------------" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
}

int adminMenu(){
	int opt = 0;
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	cout << " ---------------------------------" << endl;
	cout << " |  Select one option from menu: |" << endl;
	cout << " ---------------------------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t 1. Add record" << endl;
	cout << "\t 2. View records" << endl;
	cout << "\t 3. Update record" << endl;
	cout << "\t 4. Delete record" << endl;
	cout << "\t 5. View patients" << endl;
	cout << "\t 6. View appointments" << endl;
	cout << "\t 7. Update salaries" << endl;
	cout << "\t 8. View checkup fees" << endl;
	cout << "\t 9. View bill payments" << endl;
	cout << "\t 10. View reviews by patients" << endl;
	cout << "\t 11. Edit instruction manual" << endl;
	cout << "\t 12. Exit" << endl;
	cout << endl;
	cout << " >>> Your option --> ";
	cin >> opt;
	return opt;
}

void addDoctor(){
	cout << " I) Doctor ID: ";
	cin >> doctorId[doctorCount];
	cout << " II) Doctor password: ";
	cin >> doctorPassword[doctorCount];
	cout << " III) Docotr name: ";
	cin.ignore();
	getline(cin, doctorNames[doctorCount]);
	while(true){
		cout << " IV) Doctor age: ";
		cin >> num;
		if(validityChecker()){
			doctorAges[doctorCount] = stoi(num);
			break;
		}
		else{
			cout << " Age format not valid.";
			cout << endl;
		}
	}
	cout << " V) Doctor address: ";
	cin.ignore();
	getline(cin, doctorAddress[doctorCount]);
	while(true){
		cout << " VI) Contact number (without spaces): ";
		cin >> num;
		if(contactValidation()){
			doctorContact[doctorCount] = num;
			break;
		}
		else {
			cout << " Phone number format not valid.";
			cout << endl;
		}
	}
	cout << " VII) Doctor qualification: ";
	cin.ignore();
	getline(cin, doctorQualification[doctorCount]);
	while(true){
		cout << " VIII) Doctor salary: ";
		cin >> num;
		if(validityChecker()){
			doctorSalary[doctorCount] = stoi(num);
			break;
		}
		else {
			cout << " Input format not valid.";
			cout << endl;
		}
	}
	cout << endl;
	doctorCount++;
}

void sortDoctors(){
	for(int i=0; i<doctorCount; i++){
		int j, tempSalary, tempAge;
		string tempName, tempAddress, tempQualification;
		string tempContact, tempId, tempPassword;
		int maxSalary = -1;
		int idx = 0;
		for(j = i; j < doctorCount; j++){
			if(doctorSalary[j] > maxSalary){
				maxSalary = doctorSalary[j];
				idx = j;
			}
			
		} 
		tempSalary = doctorSalary[i];
		tempName = doctorNames[i];
		tempAge = doctorAges[i];
		tempQualification = doctorQualification[i];
		tempAddress = doctorAddress[i];
		tempContact = doctorContact[i];
		tempId = doctorId[i];
		tempPassword = doctorPassword[i];
		
		doctorSalary[i] = doctorSalary[idx];
		doctorNames[i] = doctorNames[idx];
		doctorAges[i] = doctorAges[idx];
		doctorQualification[i] = doctorQualification[idx];
		doctorAddress[i] = doctorAddress[idx];
		doctorContact[i] = doctorContact[idx];
		doctorId[i] = doctorId[idx];
		doctorPassword[i] = doctorPassword[idx];
		
		doctorSalary[idx] = tempSalary;
		doctorNames[idx] = tempName;
		doctorAges[idx] = tempAge;
		doctorQualification[idx] = tempQualification;
		doctorAddress[idx] = tempAddress;
		doctorContact[idx] = tempContact;
		doctorId[idx] = tempId;
		doctorPassword[idx] = tempPassword;
	}
}

void viewDoctors(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "  DotorID\t\tPassword\tName\t\tAge\t\tSalary\t\tQualification\t\tAddress\t\tContact " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	for(int i=0; i<= doctorCount; i++){
		if(doctorSalary[i] == 0){
			continue;
		}
		else {
			cout << ( i + 1) << ". " << doctorId[i] << "\t\t\t" << doctorPassword[i] << "\t\t\t" << doctorNames[i] << "\t\t" << doctorAges[i] << "\t\t" << doctorSalary[i]
			  << "\t\t" << doctorQualification[i] << "\t\t" << doctorAddress[i] << "\t\t" << doctorContact[i] << endl;
			 
		}
	}
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;	
}

void updateDoctors(){
	viewDoctors();
    string choice; int record;
	cout << " Please select record you want to update." << endl;
	cout << "  Id: ";
	cin >> record;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "  DotorID\t\tPassword\tName\t\tAge\t\tSalary\t\tQualification\t\tAddress\t\tContact " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	cout << "  " << doctorId[record-1] << "\t\t\t" << doctorPassword[record-1] << "\t\t\t" << doctorNames[record-1] << "\t\t" << doctorAges[record-1] << "\t\t" << doctorSalary[record-1]
			  << "\t\t" << doctorQualification[record-1] << "\t\t" << doctorAddress[record-1] << "\t\t" << doctorContact[record-1] << endl;
	cout << endl;
	cout << " Select field you would like to update (salary, address, contact)" << endl;
	cout << "  >>> Your choice: ";
	cin.ignore();
	getline(cin, choice);
	if(choice.compare("salary") == 0 || choice.compare("Salary") == 0){
		while(true){
			cout << " Previous salary: " << doctorSalary[record-1] << endl;
			cout << "  Enter new salary --> ";
			cin >> num;
			if(validityChecker()){
				doctorSalary[record-1] = stoi(num);
				break;
			}else{
				cout << " Input format not valid." << endl;
				cout << endl;
			}
		}
	}
	else if(choice.compare("address") == 0 || choice.compare("Address") == 0){
		cout << " Previous address: " << doctorAddress[record-1] << endl;
		cout << "  Enter new address --> ";
		getline(cin, doctorAddress[record-1]);
			
	}
	else if(choice.compare("contact") == 0 || choice.compare("Contact") == 0){
		while(true){
			cout << " Previous contact: " << doctorContact[record-1] << endl;
			cout << "  Enter new phone number --> ";
			cin >> num;
			if(contactValidation()){
				doctorContact[record-1] = stoi(num);
				break;
			}else{
				cout << " Contact format not valid." << endl;
				cout << endl;
			}
		}
	}
	else {
		cout << " Wrong option." << endl;
		cout << endl;
	}
}

void deleteDoctors(){
	viewDoctors();
    int record;
	cout << " Please select record you want to delete." << endl;
	cout << "  Id: ";
	cin >> record;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "  DotorID\t\tPassword\tName\t\tAge\t\tSalary\t\tQualification\t\tAddress\t\tContact " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	cout << "  " << doctorId[record-1] << "\t\t\t" << doctorPassword[record-1] << "\t\t\t" << doctorNames[record-1] << "\t\t" << doctorAges[record-1] << "\t\t" << doctorSalary[record-1]
			  << "\t\t" << doctorQualification[record-1] << "\t\t" << doctorAddress[record-1] << "\t\t" << doctorContact[record-1] << endl;
	cout << endl;
	doctorSalary[record-1] = 0;
	doctorNames[record-1] = "";
	doctorAges[record-1] = 0;
	doctorQualification[record-1] = "";
	doctorAddress[record-1] = "";
	doctorContact[record-1] = "";
	doctorId[record-1] = "";
	doctorPassword[record-1] = "";
	cout << endl;
	cout << " Doctor record successfully deleted.";
	cout << endl;
}

void updateSalaries(){
	int count = 0;
	viewDoctors();
	cout << endl;
	string record;
	cout << " Enter Doctor ID: ";
	getline(cin, record);
	for(int i=0; i<doctorCount; i++){
		if(record.compare(doctorId[i]) == 0){
		    while(true){
			cout << " Previous salary: " << doctorSalary[i] << endl;
			cout << "  Enter new salary --> ";
			cin >> num;
			    if(validityChecker()){
				    doctorSalary[i] = stoi(num);
				    count++;
				    break;
			    }else{
				    cout << " Input format not valid." << endl;
				    cout << endl;
			    }
		    }	
		}
	}
	if(count == 0){
		cout << endl;
		cout << " No such ID." << endl;
		cout << endl;
	}
}

void viewPayments(){
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=====================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "   Patient ID"
	     << "\t  "
	     << " Payments " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=====================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	for(int i=0; i<paymentCount; i++){
		cout << " " << paymentId[i] << "\t " << payments[i] << endl; 
	}
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=====================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void viewReview(){
	cout << endl;
	for(int i=0; i<reviewCount; i++){
		cout << i+1 << ". " << reviews[i] << endl;
	}
	cout << endl;
}

void doctorHeader(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\t\t\t -----------------------" << endl;
	cout << "\t\t\t |    Doctor  Menu     |" << endl;
	cout << "\t\t\t -----------------------" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
}

int doctorMenu(){
	int opt = 0;
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	cout << " ---------------------------------" << endl;
	cout << " |  Select one option from menu: |" << endl;
	cout << " ---------------------------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t 1. Add patient" << endl;
	cout << "\t 2. View records" << endl;
	cout << "\t 3. Update record" << endl;
	cout << "\t 4. Delete record" << endl;
	cout << "\t 5. Advise prescription" << endl;
	cout << "\t 6. Make appointments" << endl;
	cout << "\t 7. View appointments" << endl;
	cout << "\t 8. Update appointments" << endl;
	cout << "\t 9. Cancel appointments" << endl;
	cout << "\t 10. Generate reports" << endl;
	cout << "\t 11. Check lab test results" << endl;
	cout << "\t 12. Edit checkup fees" << endl;
	cout << "\t 13. View reviews by patients" << endl;
	cout << "\t 14. View bill payments" << endl;
	cout << "\t 15. Exit" << endl;
	cout << endl;
	cout << " >>> Your option --> ";
	cin >> opt;
	return opt;
}

bool doctorLogin(){
	bool check = false;
	string ID, password;
	cout << " Enter doctor id and password below." << endl;
	cout << endl;
	cout << "\t\tDoctor ID: ";
	getline(cin, ID);
	cout << "\t\tPassword: ";
	getline(cin, password);
	for(int i= 0; i<doctorCount; i++){
		if(ID.compare(doctorId[i]) == 0 && password.compare(doctorPassword[i]) == 0){
			 check = true;
			 break;
		}
	}	
	return check;
}

void addPatient(){
	cout << " Patient ID: ";
	cin >> patientId[patientCount];
	cout << " Patient name: ";
	cin.ignore();
	getline(cin, patientName[patientCount]);
	while(true){
		cout << " Patient age: ";
		cin >> num;
		if(validityChecker()){
			patientAge[patientCount] = stoi(num);
			break;
		}
		else {
			cout << " Invalid age format!" << endl;
			cout << endl;
		}
	}
	cout << " Patient disease: ";
	cin.ignore();
	getline(cin, patientDisease[patientCount]);
	cout << " Patient medicine: ";
	cin.ignore();
	getline(cin, patientMedicine[patientCount]);
	cout << " Patient address: ";
	cin.ignore();
	getline(cin, patientAddress[patientCount]);
	while(true){
		cout << " Patient contact: ";
		cin >> num;
		if(contactValidation()){
			patientContact[patientCount] = stoi(num);
			break;
		}
		else {
			cout << " Invalid phone number format!" << endl;
			cout << endl;
		}
	}
}

void sortPatients(){
	for(int i=0; i<patientCount; i++){
		int j, tempAge;
		string tempName, tempAddress, tempDisease, tempMedicine;
		string tempContact, tempId;
		int maxAge = 999;
		int idx = 0;
		for(j = i; j < doctorCount; j++){
			if(patientAge[j] > maxAge){
				maxAge = patientAge[j];
				idx = j;
			}
			
		} 
		tempMedicine = patientMedicine[i];
		tempName = patientName[i];
		tempAge = patientAge[i];
		tempDisease = patientDisease[i];
		tempAddress = patientAddress[i];
		tempContact = patientContact[i];
		tempId = patientId[i];
		
		patientMedicine[i] = patientMedicine[idx];
		patientName[i] = patientName[idx];
		patientAge[i] = patientAge[idx];
		patientDisease[i] = patientDisease[idx];
		patientAddress[i] = patientAddress[idx];
		patientContact[i] = patientContact[idx];
		patientId[i] = patientId[idx];
		
		patientMedicine[idx] = tempMedicine;
		patientName[idx] = tempName;
		patientAge[idx] = tempAge;
		patientDisease[idx] = tempDisease;
		patientAddress[idx] = tempAddress;
		patientContact[idx] = tempContact;
		patientId[idx] = tempId;
	}
}

void viewPatients(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "==============================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "   ID\t\tName\t\tAge\t\tDisease\t\tMedicine\t\tAddress\t\tContact " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "==============================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	for(int i=0; i<= patientCount; i++){
		if(patientAge[i] == 0){
			continue;
		}
		else {
			cout << ( i + 1) << ". " << patientId[i] << "\t\t" << patientName[i] << "\t\t\t" << patientAge[i] << "\t\t" << patientDisease[i] << "\t\t" << patientMedicine[i]
			  << "\t\t" << patientAddress[i] << "\t\t" << patientContact[i] << endl;
			 
		}
	}
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;	
}

void updatePatients(){
	viewPatients();
    string choice; int record;
	cout << " Please select record you want to update." << endl;
	cout << "  Id: ";
	cin >> record;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "   ID\t\tName\t\tAge\t\tDisease\t\tMedicine\t\tAddress\t\tContact " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
			cout << " " << patientId[record-1] << "\t\t" << patientName[record-1] << "\t\t\t" << patientAge[record-1] << "\t\t" << patientDisease[record-1] << "\t\t" << patientMedicine[record-1]
			  << "\t\t" << patientAddress[record-1] << "\t\t" << patientContact[record-1] << endl;
	cout << endl;
	cout << " Select field you would like to update (medicine, contact)" << endl;
	cout << "  >>> Your choice: ";
	cin.ignore();
	getline(cin, choice);
	if(choice.compare("medicine") == 0 || choice.compare("Medicine") == 0){
		cout << " Previous medicine: " << patientMedicine[record-1] << endl;
		cout << " Enter new medicine name --> ";
		getline(cin, patientMedicine[record-1]);
	}
	else if(choice.compare("contact") == 0 || choice.compare("Contact") == 0){
		while(true){
			cout << " Previous contact: " << patientContact[record-1] << endl;
			cout << " Enter new phone number --> ";
			cin >> num;
			if(contactValidation()){
				patientContact[record-1] = stoi(num);
				break;
			}else{
				cout << " Contact format not valid." << endl;
				cout << endl;
			}
		}
	}
	else {
		cout << " Wrong option." << endl;
		cout << endl;
	}
}

void deletePatients(){
	viewPatients();
    int record;
	cout << " Please select record you want to update." << endl;
	cout << "  Id: ";
	cin >> record;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
cout << "   ID\t\tName\t\tAge\t\tDisease\t\tMedicine\t\tAddress\t\tContact " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	cout << " " << patientId[record-1] << "\t\t" << patientName[record-1] << "\t\t\t" << patientAge[record-1] << "\t\t" << patientDisease[record-1] << "\t\t" << patientMedicine[record-1]
			  << "\t\t" << patientAddress[record-1] << "\t\t" << patientContact[record-1] << endl;
	cout << endl;
		patientMedicine[record-1] = "";
		patientName[record-1] = "";
		patientAge[record-1] = 0;
		patientDisease[record-1] = "";
		patientAddress[record-1] = "";
		patientContact[record-1] = "";
		patientId[record-1] = "";
	cout << endl;
	cout << " Patient record successfully deleted.";
	cout << endl;
}

void registerPrescription(){
	viewPatients();
	int count = 0;
	cout << endl;
	cout << " To patient ID: ";
	cin >> prescriptionId[prescriptionCount];
	for(int i=0; i<patientCount; i++){
		if(prescriptionId[prescriptionCount] == patientId[i]){
			cout << patientName[i] << endl;
			cout << patientAge[i] << endl;
			cout << patientDisease[i] << endl;
			cout << patientMedicine[i] << endl;
			cout << patientContact[i] << endl;
			cout << " Add prescription: " << endl;
			cout << " >>> ";
			cin.ignore();
			getline(cin, addPrescription[prescriptionCount]);
			prescriptionCount++;
			count++;
			break;
		}
	}
	if(count == 0){
		cout << endl;
		cout << " No such id.";
		cout << endl;
	}
}

void makeAppointments(){
	viewPatients();
	int count = 0;
	cout << endl;
	cout << " With patient ID: ";
	cin >> appointmentId[appointmentCount];
	for(int i=0; i< patientCount; i++){
		if(appointmentId[appointmentCount] == patientId[i]){
			cout << patientName[i] << endl;
			cout << patientAge[i] << endl;
			cout << patientDisease[i] << endl;
			cout << patientMedicine[i] << endl;
			cout << patientContact[i] << endl;
			cout << patientAddress[i] << endl;
			cout << "\n >> Day: " << endl;
			cin.ignore();
			getline(cin, appointmentDay[appointmentCount]);
			cout << "\n >> Hour: " << endl;
			cin.ignore();
			getline(cin, appointmentTime[appointmentCount]);
			appointmentCount++;
			count++;
			break;
		}
	}
	if(count == 0){
		cout << endl;
		cout << " No such id.";
		cout << endl;
	}
}

void viewAppointments(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "====================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "  Patient ID\t\tName\t\tAppointment day\t\tAppointment time " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=============================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	for(int i=0; i<= appointmentCount; i++){
		if(appointmentId[i] == ""){
			continue;
		}
		for(int j=i; j < patientCount; j++){	
		    if(appointmentId[i] == patientId[j]){	
			    cout << ( i + 1) << ". " << patientId[i] << "\t\t" << patientName[i] << "\t\t\t" << appointmentDay[i] << "\t\t" << appointmentTime[i] << endl;
			    break; 
		   }
		}
	}
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;	
}

void updateAppointments(){
	viewAppointments();
    string choice; int record;
	cout << " Please select appointment you want to change." << endl;
	cout << "  Id: ";
	cin >> record;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "  Patient ID\t\tName\t\tAppointment day\t\tAppointment time " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "=================================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	cout << "  " << patientId[record-1] << "\t\t" << patientName[record-1] << "\t\t\t" << appointmentDay[record-1] << "\t\t" << appointmentTime[record-1] << endl;
	cout << endl;
	cout << " Select field you would like to update (day, time)" << endl;
	cout << "  >>> Your choice: ";
	cin.ignore();
	getline(cin, choice);
	if(choice.compare("day") == 0 || choice.compare("Day") == 0){
		cout << " Previous appointment day: " << appointmentDay[record-1] << endl;
		cout << " Enter new day for appointment --> ";
		getline(cin, appointmentDay[record-1]);
	}
	else if(choice.compare("time") == 0 || choice.compare("Time") == 0){
		cout << " Old appointment time: " << appointmentTime[record-1] << endl;
		cout << " Enter new time for appointment --> ";
		cin >> appointmentTime[record-1];
	}
	else {
		cout << " Wrong option." << endl;
		cout << endl;
	}
}

void deleteAppointments(){
	viewAppointments();
    int record;
	cout << " Please enter the ID of the appointment you want to cancel." << endl;
	cout << "  Id: ";
	cin >> record;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "==================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "  Patient ID\t\tName\t\tAppointment day\t\tAppointment time " << endl;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "==================================================================================================================================" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	cout << "  " << patientId[record-1] << "\t\t" << patientName[record-1] << "\t\t\t" << appointmentDay[record-1] << "\t\t" << appointmentTime[record-1] << endl;
	cout << endl;
		appointmentTime[record-1] = "";
		appointmentDay[record-1] = "";
		appointmentId[record-1] = "";
	cout << endl;
	cout << " Appointment successfully canceled.";
	cout << endl;
}

void generateReports(){
	fstream file;
	stringstream contents;
	int count = 0;
	cout << " Generate reports of patients ID: ";
	cin >> reportsId[reportsCount];
	file.open("patient_report.txt", ios::out | ios::app);
	for(int i=0; i<patientCount; i++){
		if(patientId[i] == reportsId[reportsCount]){
			cout << " -------------------------------------------\n";
			contents << " -------------------------------------------\n";
			cout << " | --- PATIENT -- INFORMATION -- REPORT --- |\n";
			contents << " | --- PATIENT -- INFORMATION -- REPORT --- |\n";
			cout << " -------------------------------------------\n";
			contents << " -------------------------------------------\n";
			cout << "  Name: " << patientName[i] << "\n";
			cout << "  Age: " << patientAge[i] << "\n";
			cout << "  Address: " << patientAddress[i] << "\n";
			cout << "  Contact: " << patientContact[i] << "\n";
			cout << "  Disease: " << patientDisease[i] << "\n";
			cout << "  Medicine: " << patientMedicine[i] << "\n";
			
			contents << "  Name: " << patientName[i] << "\n";
			contents << "  Age: " << patientAge[i] << "\n";
			contents << "  Address: " << patientAddress[i] << "\n";
			contents << "  Contact: " << patientContact[i] << "\n";
			contents << "  Disease: " << patientDisease[i] << "\n";
			contents << "  Medicine: " << patientMedicine[i] << "\n";
			cout << "  Test taken: ";
			cin >> test[reportsCount];
			cout << "\n";
			contents << "  Test taken: " << test[reportsCount] << "\n"; 
			cout << "  Result: ";
			cin >> result[reportsCount];
			cout << "\n";
			contents << "  Result: " << result[reportsCount] << "\n";
			cout << " -------------------------------------------\n";
			contents << " -------------------------------------------\n";
			file << contents.str();
			reportsCount++;
			count++;
			break;
		}
	}
	file.close();
	if(count == 0){
		cout << " No such id." << endl;
		cout << endl;
	}
}

void editFees(){
	cout << " Previous checkup fees: " << checkupFees << endl;
	cout << endl;
	cout << " Add new checkup fees: ";
	cin >> checkupFees;
}

void patientHeader(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\t\t\t -----------------------" << endl;
	cout << "\t\t\t |   Patient  Menu     |" << endl;
	cout << "\t\t\t -----------------------" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
}

int patientMenu(){
	int opt = 0;
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl;
	cout << " ---------------------------------" << endl;
	cout << " |  Select one option from menu: |" << endl;
	cout << " ---------------------------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t 1. View appointments" << endl;
	cout << "\t 2. View prescriptions" << endl;
	cout << "\t 3. View reports" << endl;
	cout << "\t 4. View lab results" << endl;
	cout << "\t 5. View doctor fees" << endl;
	cout << "\t 6. Bill payments" << endl;
	cout << "\t 7. Give review" << endl;
	cout << "\t 8. Exit" << endl;
	cout << endl;
	cout << " >>> Your option --> ";
	cin >> opt;
	return opt;
}

void viewPrescriptions(){
	int count = 0;
	string ptPrescriptionId;
	cout << " Enter patient ID: ";
	cin >> ptPrescriptionId;
	cout << endl;
	for(int i = 0; i < prescriptionCount; i++){
		if(ptPrescriptionId == prescriptionId[i]){
			cout << patientName[i] << endl;
			cout << patientAge[i] << endl;
			cout << patientDisease[i] << endl;
			cout << patientMedicine[i] << endl;
			cout << patientContact[i] << endl;
			cout << addPrescription[i] << endl;
			count++;
		}
	}	
	if(count == 0){
		cout << endl;
		cout << "  No such id.";
		cout << endl;
	}
}

void viewReports(){
int count = 0;
	string ptReportId;
	cout << " Enter patient ID: ";
	cin >> ptReportId;
	cout << endl;
	for(int i = 0; i < patientCount; i++){
		if(ptReportId == patientId[i]){
			for(int j=0; j<reportsCount; j++){
				if(reportsId[j] == ptReportId){
					cout << endl;
					cout << patientName[i] << endl;
					cout << patientAge[i] << endl;
					cout << patientDisease[i] << endl;
					cout << patientMedicine[i] << endl;
					cout << patientContact[i] << endl;
					cout << test[i] << endl;
					cout << result[i] << endl;
					count++;
					break;
				}
		    }
		}
	}	
	if(count == 0){
		cout << endl;
		cout << "  No such id.";
		cout << endl;
	}	
}

void viewLabResults(){
	string id;
	cout << " Enter Patient ID: ";
	getline(cin, id);
	cout << endl;
	cout << "   >> Test taken: Blood sample" << endl;
	cout << "   >> Red blood cells: 432" << endl;
	cout << "   >> White blood cells: 223" << endl;
	cout << "   >> Platets (billion/L): 272" << endl;
	cout << "   >> RBC (trillion/L): 3.84" << endl;
	cout << "   >> HB (g/dL): 11.7" << endl;
	cout << "   >> WBC (billion/L): 8.00" << endl;
	cout << "   >> Lymphs: 68H" << endl;
	cout << "   >> Homoglobin: 10.8L" << endl;
	cout << "   >> EOS: 0.7" << endl;	
}

void viewDoctorFees(){
	cout <<"\n----------------------------------------" << endl;
	cout << "  Doctor checkup fees: " << checkupFees;
	cout <<"\n----------------------------------------" << endl;
	cout << endl;	
}

void billPayments(){
	int medicine, laboratory;
	cout << "  Enter patient ID: ";
	cin >> paymentId[paymentCount];
	cout << "  Doctor checkup Fees: " << checkupFees << endl;
	cout << "  Enter medicine bill: ";
	cin >> medicine;
	cout << "  Enter laboratory test fees: ";
	cin >> laboratory,
	payments[paymentCount] = checkupFees + medicine + laboratory,
	cout << " Payable amount: " << payments[paymentCount];
	cout << endl;
	paymentCount;	
}

void giveReviews(){
	cout << "  Please write your review: ";
	cin.ignore();
	getline(cin, reviews[reviewCount]);
	reviewCount++;	
}

void manual(){
	cout << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "\t\t |   INSTRUCTION MANUAL    |" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	cout << endl;
	cout << "    1. For appointments, call between --> 9:00 AM - 10:00 PM " << endl;
	cout << "    2. Telephone --> 121-090-556 : 313-472-873 " << endl;
	cout << "    3. Mobile    --> 882-416-882 : 690-219-538 " << endl;
	cout << "    4. Fax       --> 357-549-039 " << endl;
	cout << "    5. E-mail :   info@hospitalsysem.org " << endl;
	cout << "    6. Website:   www.milleniumhospital.org " << endl;
	cout << "    7. Address:   Kilinskiego 14, Trynek - Gliwice " << endl;
}

void editManual(){
	int line = 0;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << endl;
	cout << "\t\t &&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
	cout << "\t\t &&  INSTRUCTION MANUAL   &&" << endl;
	cout << "\t\t &&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	string line1, line2, line3, line4, line5, line6, line7;
	line1 = "    For appointments, call between --> 9:00 AM - 10:00 PM ";
	line2 = "    Telephone --> 121-090-556 : 313-472-873 ";
	line3 = "    Mobile    --> 882-416-882 : 690-219-538 ";
	line4 = "    Fax       --> 357-549-039 ";
	line5 = "    E-mail :   info@hospitalsysem.org ";
	line6 = "    Website:   www.milleniumhospital.org ";
	line7 = "    Address:   Kilinskiego 14, Trynek - Gliwice ";
		cout << endl;
		cout << line + 1 << ". " << line1 << endl;
		cout << line + 2 << ". " << line2 << endl;
		cout << line + 3 << ". " << line3 << endl;
		cout << line + 4 << ". " << line4 << endl;
		cout << line + 5 << ". " << line5 << endl;
		cout << line + 6 << ". " << line6 << endl;
		cout << line + 7 << ". " << line7 << endl;
		cout << endl;
	int choice;
	cout << " Select field you want to edit (1, 2, 3, 4, 5, 6, 7):" << endl;
	cout << endl;
	cin >> choice;
	char stop11;
	switch(choice){
		case 1:
			cout << " > Previous: " << line1 << endl;
			cout << " > New instruction: ";
			getline(cin, line1);
			cout << endl; break;
		case 2:
			cout << " > Previous: " << line2 << endl;
			cout << " > New instruction: ";
			getline(cin, line2);
			cout << endl; break;
		case 3:
			cout << " > Previous: " << line3 << endl;
			cout << " > New instruction: ";
			getline(cin, line3);
			cout << endl; break;
		case 4:
			cout << " > Previous: " << line4 << endl;
			cout << " > New instruction: ";
			getline(cin, line4);
			cout << endl; break;
		case 5:
			cout << " > Previous: " << line5 << endl;
			cout << " > New instruction: ";
			getline(cin, line5);
			cout << endl; break;
		case 6:
			cout << " > Previous: " << line6 << endl;
			cout << " > New instruction: ";
			getline(cin, line6);
			cout << endl; break;
		case 7:
			cout << " > Previous: " << line7 << endl;
			cout << " > New instruction: ";
			getline(cin, line7);
			cout << endl; break;	
	}
	cout << "   ---> Done. Manual successfully editted! " << endl;
}
//--------------- file handling functions ----------//
string parseRecord(int field, string line){
	int comma = 1; string item;
	for(int x = 0; line[x] != '\0'; x++){
		if(line[x] == '\n'){
			comma += 1;
		}
		else if(comma == field){
			item += line[x];
		}
	}
	return item;
}

void storeOne(){
	fstream file;
	file.open("doctor_information.txt", ios::out);
    for(int i=0; i<doctorCount; i++){
    	file << "\n================================================================================\n" << "   DOCTOR  INFORMATION\n" 
 		 << "  Doctor ID: "  << doctorId[i] << "  Password: " << doctorPassword[i] << "\n" << "  Name: " << doctorNames[i] 
		 << "\n" << "  Age: " << doctorAges[i] << "\n" << "  Contact: " << doctorContact[i] << "\n" << "  Qualification: " << doctorQualification[i]
		 << "\n" << "  Salary: " << doctorSalary[i]		  
		 << "\n================================================================================\n";
	}
	file.close();
}

void loadOne(){
	string line1;
	fstream file;
	file.open("doctor_information.txt", ios::in);
	while(!file.eof()){
		getline(file, line1);
		if(line1.compare("") != 0){
			loadDoctors(line1);
		}
		
	}
	file.close();
}

void loadDoctors(string line){
	stringstream header;
	header << parseRecord(0, line) << "\n"
 	       << parseRecord(1, line) << "\n"
	       << parseRecord(2, line) << "\n";
	doctorId[doctorCount] = parseRecord(3, line);
	doctorPassword[doctorCount] = parseRecord(4, line);
	doctorNames[doctorCount] = parseRecord(5, line);
	doctorAges[doctorCount] = stoi(parseRecord(6, line));
	doctorContact[doctorCount] = parseRecord(7, line);
	doctorQualification[doctorCount] = parseRecord(8, line);
	doctorSalary[doctorCount] = stoi(parseRecord(9, line));
	doctorCount++;	
}

void storeTwo(){
	fstream file;
	file.open("patient_information.txt", ios::out);
    for(int i=0; i<patientCount; i++){
    	file << patientId[i] << "\n" << patientName[i] << "\n" << patientAge[i] << "\n" 
		        << patientAddress[i] << "\n" << patientDisease[i] << "\n" << patientMedicine[i] << "\n"
		           << patientContact[i] << "\n";
	}
	file.close();
}

void loadTwo(){
	fstream file; string line;
	file.open("patient_information.txt", ios::in);
	while(!file.eof()){
		getline(file, line);
		if(line != ""){
			loadPatients(line);
		}
	}
}

void loadPatients(string line){
	patientId[patientCount]       = parseRecord(1, line);
	patientName[patientCount]     = parseRecord(2, line);
	patientAge[patientCount]      = stoi(parseRecord(3, line));
	patientDisease[patientCount]  = parseRecord(4, line);
	patientMedicine[patientCount] = parseRecord(5, line);
	patientAddress[patientCount]  = parseRecord(6, line);
	patientContact[patientCount]  = parseRecord(7, line);
	patientCount++;	
}

void storeThree(){
	fstream file;
	file.open("prescriptions.txt", ios::out);
    for(int i=0; i<prescriptionCount; i++){
    	file << prescriptionId[i] << "\n" << addPrescription[i] << endl;
	}
	file.close();
}

void loadThree(){
	fstream file; string line;
	file.open("prescriptions.txt", ios::in);
	while(!file.eof()){
		getline(file, line);
		if(line != ""){
			loadPrescriptions(line);
		}
	}
}

void loadPrescriptions(string line){
	prescriptionId[prescriptionCount] = parseRecord(1, line);
	addPrescription[prescriptionCount] = parseRecord(2, line);
	prescriptionCount++;
}

void storeFour(){
	fstream file;
	file.open("appointments.txt", ios::out);
    for(int i=0; i<appointmentCount; i++){
    	file << appointmentId[i] << "\n" << appointmentDay[i] << "\n" << appointmentTime[i] << endl;
	}
	file.close();
}

void loadFour(){
	fstream file; string line;
	file.open("appointments.txt", ios::in);
	while(!file.eof()){
		getline(file, line);
		if(line != ""){
			loadAppointments(line);
		}
	}
}

void loadAppointments(string line){
	appointmentId[appointmentCount] = parseRecord(1, line);
	appointmentDay[appointmentCount] = parseRecord(2, line);
	appointmentTime[appointmentCount] = parseRecord(3, line);
	appointmentCount++;
}

void storeFive(){
	fstream file;
	file.open("reports.txt", ios::out);
    for(int i=0; i<reportsCount; i++){
    	file << reportsId[i] << "\n" << test[i] << "\n" << result[i] << endl;
	}
	file.close();
}

void loadFive(){
	fstream file; string line;
	file.open("reports.txt", ios::in);
	while(!file.eof()){
		getline(file, line);
		if(line != ""){
			loadReports(line);
		}
	}
}

void loadReports(string line){
	reportsId[reportsCount] = parseRecord(1, line);
	test[reportsCount] = parseRecord(2, line);
	result[reportsCount] = parseRecord(3, line);
	reportsCount++;
}

void storeSix(){
	fstream file;
	file.open("payments.txt", ios::out);
    for(int i = 0; i< paymentCount; i++){
    	file << paymentId[i] << "\n" << payments[i] << endl;
	}
	file.close();
}

void loadSix(){
	fstream file; string line;
	file.open("payments.txt", ios::in);
	while(!file.eof()){
		getline(file, line);
		if(line != ""){
			loadPayments(line);
		}
	}
}

void loadPayments(string line){
	paymentId[paymentCount] = parseRecord(1, line);
	payments[paymentCount] = stoi(parseRecord(2, line));
	paymentCount++;
}

void storeSeven(){
	fstream file;
	file.open("reviews.txt", ios::out);
    for(int i = 0; i< reviewCount; i++){
    	file << reviews[i] << endl;
	}
	file.close();
}

void loadSeven(){
	fstream file; string line;
	file.open("reviews.txt", ios::in);
	while(!file.eof()){
		getline(file, line);
		if(line != ""){
			reviews[reviewCount] = line;
			reviewCount++;
		}
	}
}

bool validityChecker(){
	int count1 = 0, count2 = 0;
	for(int i = 0; num[i] != '\0'; i++){
		count1++;
	}
	for(int j=0; num[j] != '\0'; j++){
		if(num[j] >= '0' && num[j] <= '9'){
			count2++;
		}
	}
	if(count1 == count2){
		return true;
	}
	return false;
}

bool contactValidation(){
	int count1 = 0, count2 = 0;
	for(int i = 0; num[i] != '\0'; i++){
		count1++;
	}
	for(int j=0; num[j] != '\0'; j++){
		if(num[j] >= '0' && num[j] <= '9'){
			count2++;
		}
	}
	if((count1 == 11) && (count1 == count2)){
		return true;
	}
	return false;
}

