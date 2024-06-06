#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class definition for Patient
class Patient {
private:
    string name;
    string diagnosis;
    string symptoms;
    string address;
    int age;

public:
    // Constructor
    Patient(string n, string d, string s, string a, int ag) : name(n), diagnosis(d), symptoms(s), address(a), age(ag) {}

    // Getter methods
    string getName() const { return name; }
    string getDiagnosis() const { return diagnosis; }
    string getSymptoms() const { return symptoms; }
    string getAddress() const { return address; }
    int getAge() const { return age; }
};

// Vector to store patient records
vector<Patient> patientRecords;

// Function to add patient records
void addPatientRecord() {
    char choice = 'y';
    while (tolower(choice) == 'y') {
        string name, diagnosis, symptoms, address;
        int age;

        cout << "Enter patient name: ";
        getline(cin, name);
        cout << "Enter diagnosis: ";
        getline(cin, diagnosis);
        cout << "Enter symptoms: ";
        getline(cin, symptoms);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); // Clear the input buffer

        // Create a patient object and store it in the vector
        Patient patient(name, diagnosis, symptoms, address, age);
        patientRecords.push_back(patient);

        cout << "Do you want to add another patient record? (Y/N): ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
    }
}

// Function to view patient records
void viewPatientRecords() {
    for (int i = 0; i < patientRecords.size(); ++i) {
        cout << "Patient " << i + 1 << ":" << endl;
        cout << "Name: " << patientRecords[i].getName() << endl;
        cout << "Diagnosis: " << patientRecords[i].getDiagnosis() << endl;
        cout << "Symptoms: " << patientRecords[i].getSymptoms() << endl;
        cout << "Address: " << patientRecords[i].getAddress() << endl;
        cout << "Age: " << patientRecords[i].getAge() << endl;
        cout << "---------------------" << endl;
    }
}

// Function to authenticate user
bool authenticateUser(const string& username, const string& password) {
    // Sample hardcoded credentials
    string storedUsername = "user";
    string storedPassword = "password";

    return (username == storedUsername && password == storedPassword);
}

int main() {
    // Get user input for login
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Authenticate user
    if (authenticateUser(username, password)) {
        cout << "Login successful!" << endl;
        cout << "Welcome, " << username << "!" << endl;

        char userType;
        cout << "Select user type: (C)lerical or (D)octor: ";
        cin >> userType;

        cin.ignore(); // Clear the input buffer

        if (tolower(userType) == 'c') {
            addPatientRecord();
        } else if (tolower(userType) == 'd') {
            viewPatientRecords();
        } else {
            cout << "Invalid user type!" << endl;
        }
    } else {
        cout << "Authentication failed. Exiting program." << endl;
    }

    return 0;
}
