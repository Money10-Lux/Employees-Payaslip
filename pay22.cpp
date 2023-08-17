#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Employee {
    string name;
    int payrollNo;
    double basicSalary;
    double houseAllowance;
    double commuterAllowance;
};

void generatePayslip(Employee emp) {

    double grossPay = emp.basicSalary + emp.houseAllowance + emp.commuterAllowance;
    double paye = 0.3 * grossPay;
    double nssf = 500;
    double nhif = 200;
    double deductions = paye + nssf + nhif;
    double netSalary = grossPay - deductions;

    ofstream outFile("payslips.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Employee Name: " << emp.name << endl;
        outFile << "Payroll No: " << emp.payrollNo << endl;
        outFile << "Basic Salary: " << emp.basicSalary << endl;
        outFile << "House Allowance: " << emp.houseAllowance << endl;
        outFile << "Commuter Allowance: " << emp.commuterAllowance << endl;
        outFile << "Gross Pay: " << grossPay << endl;
        outFile << "PAYE: " << paye << endl;
        outFile << "NHIF: " << nssf << endl;
        outFile << "NSSF: " << nhif << endl;
        outFile << "Deductions: " << deductions << endl;
        outFile << "Net Salary: " << netSalary << endl;
        outFile << "----------------------------------------" << endl;
    }
    outFile.close();
}


void displayAllPayslips() {
    ifstream inFile("payslips.txt");
    if (inFile.peek() != EOF) {
        do {
            string line;
            getline(inFile, line);
            cout << line << endl;
        } while (!inFile.eof());

        inFile.close();
    } else {
        cout << "File is empty." << endl;
    }
}
void searchPayslip(string name) {
    ifstream inFile("payslips.txt");
    if (inFile.is_open()) {
        string line;
        cout << "Displaying payslip for " << name << "." << endl;
        while (getline(inFile, line)) {
            if (line.find("Employee Name: " + name) != string::npos) {
                cout << line << endl;
                for (int i = 0; i < 10; i++) {
                    getline(inFile, line);
                    cout << line << endl;
                }
                inFile.close();
                return;
            }
        }
        inFile.close();
        cout << "No payslip found for " << name << "." << endl;
    } else {
        cout << "File is empty." << endl;
    }
}
void deletePayslipByName(string deleteName) {
    ifstream inFile("payslips.txt");
    ofstream tempFile("temp.txt", ios::app);
    if (inFile.is_open() && tempFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.find("Employee Name: " + deleteName) != string::npos) {
                found = true;
                for (int i = 0; i < 11; i++) {
                    getline(inFile, line);
                }
            } else {
                tempFile << line << endl;
            }
        }
        inFile.close();
        tempFile.close();

        remove("payslips.txt");
        rename("temp.txt", "payslips.txt");

        if (found) {
            cout << "Payslip for " << deleteName << " deleted." << endl;
        } else {
            cout << "No payslip found for " << deleteName << "." << endl;
        }
    } else {
        cout << "File is empty." << endl;
    }
}
int main() {
    system("cls");

    while (true) {
        cout << "\n============= Payroll System =============" << endl;
        cout << "\n(1) Generate Payslip" << endl;
        cout << "(2) Display all Payslips" << endl;
        cout << "(3) Search individual payslip" << endl;
        cout << "(4) Delete payslip by Name (Individual)" << endl;
        cout << "(5) Delete the entire payslip Recodes" << endl;
        cout << "(6) Exit" << endl;

        int choice;
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                int numEmployees;
                cout << "\nHow many employees do you want to generate payslips for? ";
                cin >> numEmployees;

                for (int i = 0; i < numEmployees; i++) {
                    Employee emp;
                    cout << "\nEnter information for employee " << i + 1 << ":" << endl;
                    cout << "Employee Name: ";
                    cin.ignore();
                    getline(cin, emp.name);
                    cout << "Employee Payroll No: ";
                    cin >> emp.payrollNo;
                    cout << "Employee Basic Salary: ";
                    cin >> emp.basicSalary;
                    cout << "Employee House Allowance: ";
                    cin >> emp.houseAllowance;
                    cout << "Employee Commuter Allowance: ";
                    cin >> emp.commuterAllowance;
                    generatePayslip(emp);

                    }

                cout << "\nDo you want to save the information? (Y/N) ";
                char ch;
                cin >> ch;

                if (ch == 'y' || ch == 'Y') {
                    cout << "\nInformation saved successfully." << endl;
                } else {
                    cout << "\nInformation not saved." << endl;
                }
                break;
            }
            case 2:
                system("cls");
                cout<<"\n";
                displayAllPayslips();
                break;
            case 3: {
                system("cls");

                string searchName;
                cout << "\nEnter Employee Name to Search: ";
                cin.ignore();
                getline(cin, searchName);
                searchPayslip(searchName);
                break;
            }
            case 4: {
                system("cls");
                string deleteName;
                cout << "\nEnter Employee Name to Delete Payslip: ";
                cin.ignore();
                getline(cin, deleteName);
                deletePayslipByName(deleteName);
                break;
            }
            case 5: {
                system("cls");
                remove("payslips.txt");
                cout << "Payroll Records Deleted Successfully." << endl;
                break;
            }
            case 6:
                system("cls");
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    }

    return 0;
}

