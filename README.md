# Employees-Payaslip: Payroll System
Generating Payslip using C++

Overview
This is a simple command-line payroll management system written in C++. It allows users to generate, display, search, and delete employee payslips. The system calculates gross pay, deductions (PAYE, NSSF, NHIF), and net salary for employees, storing the information in a text file (payslips.txt).

# Features
1. Generate Payslip: Input employee details and generate a payslip with calculated gross pay, deductions, and net salary.
2. Display All Payslips: View all stored payslips from the payslips.txt file.
3. Search Payslip: Search for an individual employee's payslip by name.
4. Delete Payslip: Remove an individual employee's payslip by name.
5. Delete All Records: Clear all payslip records from the file.
6. Exit: Terminate the program.

# Prerequisites
A C++ compiler (e.g., g++, MinGW, or any IDE like Visual Studio, Code::Blocks).
Basic understanding of C++ file I/O and structs.

# Installation
Clone or download the source code to your local machine.
Open the code in your preferred C++ IDE or text editor.
Compile and run the program using a C++ compiler. For example:

g++ pay22.cpp -o pay22
./pay22

# Usage
Run the compiled program.
A menu will appear with the following options:
============= Payroll System =============
(1) Generate Payslip
(2) Display all Payslips
(3) Search individual payslip
(4) Delete payslip by Name (Individual)
(5) Delete the entire payslip Records
(6) Exit
Enter Choice:
Enter a number (1–6) to select an option and follow the prompts.

# Example Workflow
Generate Payslip: Choose option 1, enter the number of employees, and provide details (name, payroll number, basic salary, house allowance, commuter allowance). The payslip is saved to payslips.txt.

Search Payslip: Choose option 3, enter an employee’s name, and view their payslip if found.

Delete Payslip: Choose option 4, enter an employee’s name, and remove their payslip from the file.

# File Structure
payslips.txt: Stores all generated payslips. Created automatically when payslips are generated.

temp.txt: Temporary file used during deletion operations (deleted after use).

# Calculations
Gross Pay: Basic Salary + House Allowance + Commuter Allowance
Deductions:
        PAYE: 30% of Gross Pay
        NSSF: Fixed at 500
        NHIF: Fixed at 200
        Net Salary: Gross Pay - (PAYE + NSSF + NHIF)

# Notes
The program uses a simple text file (payslips.txt) for persistent storage.
Deduction rates (PAYE, NSSF, NHIF) are hardcoded and may need adjustment based on real-world requirements.

The system("cls") command is used to clear the console, which works on Windows. For Linux/macOS, replace it with system("clear") or remove it.

# Limitations
No input validation for negative values or non-numeric inputs.

Payslip deletion relies on exact name matches (case-sensitive).

No option to edit existing payslips.

File handling assumes the program has write permissions in the working directory.

# Future Improvements
Add input validation for robustness.

Implement an option to update existing payslips.

Use a database instead of a text file for better scalability.

Support configurable tax and deduction rates.

