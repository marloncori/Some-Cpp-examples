#include <iostream>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <fstream>

using namespace std;
void clearScreen();
void hms();
bool adminLogin();
void header();
int menu();
void adminHeader();
int adminMenu();
void addDoctor();
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
void delePatients();
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
constexpr int MAX_RECORDS {50};
int doctorCount {0};
string doctorId[MAX_RECORDS];
string doctorPassword[MAX_RECORDS];
string doctorNames[MAX_RECORDS];
int doctorAges[MAX_RECORDS];
string doctorAdress[MAX_RECORDS];
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
            }
        }
    }


}



