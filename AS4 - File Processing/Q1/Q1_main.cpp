#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// class TA to store information about a TA
class TA {
public:
    int student_id;
    string first_name;
    string last_name;
    int hire_year;
    string classification;
    int numWorkingHours;
};

// function prototypes
bool search_duplicate_ID(int); // function to check if id is already in file
int validateID(); // function which validates the user's input for the student id of a new TA
int validateHireYear(); // function which validates user input for hire year of new TA
int validateWorkingHours(); // function which validates user input for number of working hours of new TA
string validateClassification(); // function which validates user input for classification of new TA
string validateFirstName(); // function which validates user input for first name of new TA
string validateLastName(); //function which validates user input for last name of new TA
bool AddnewTA(); // function to append information of new TA to file if they are not Alum

int main() {
    // read data from file and store in array of TA objects
    
    // create ifstream object and check if file opened successfully
    ifstream in_file;
    in_file.open("TAs.txt");
    if (!in_file) {
        cerr << "File could not be found!" << endl;
        return 1;
    }
    
    // read total number of records from file
    int size;
    in_file >> size;
    
    // create array of TA objects to store records read from file
    TA records[size];
    
    in_file.seekg(1,ios::cur); // reposition file pointer to next line
    
    // loop size times to initialize array objects with read data
    for (int i = 0; i < size; i++) {
        string line; // variable to store line from file
        getline(in_file,line); // read data line by line using getline and store in string line
        stringstream ss(line); // initialize string stream with line
        
        // variables to store input
        int id, year, hours;
        string fname, lname, classif;
        
        ss >> id >> fname >> lname >> year >> classif >> hours; // parse the string stream
        // initialize records in array
        records[i].student_id = id;
        records[i].first_name = fname;
        records[i].last_name = lname;
        records[i].hire_year = year;
        records[i].classification = classif;
        records[i].numWorkingHours = hours;
    
    }
    
    in_file.close();

    // update file by writing only valid TAs back to the file
    
    // create ofstream object and check file 
    ofstream out_file{"TAs.txt"};
    if (!out_file) {
        cerr << "Problem creating file!" << endl;
        return 1;
    }
    
    int numRecords = 0;
    out_file << numRecords << endl; // write number of valid records to first line of file
    
    for (int i = 0; i < size; i++) {
        // writing records of grad students to file
        if (records[i].classification == "Grad") {
            out_file << records[i].student_id << " " << records[i].first_name << " " << records[i].last_name
                     << " " << records[i].hire_year << " " << records[i].classification 
                     << " " << records[i].numWorkingHours << endl;
            numRecords++;
        }
    }
    
    out_file.seekp(0,ios::beg); // reposition file pointer to beginning of file
    out_file << numRecords; // update number of valid records in file
    out_file.close();
    cout << "File has been successfully updated with only valid TA records" << endl;
    
    // adding new TAs
    char selection;
    do {
        cout << "\nWould you like to add a new TA? (y=yes/n=no): ";
        cin >> selection;
        if (selection == 'y' || selection == 'Y') {
            if (AddnewTA()) { // if new TA is valid (Grad)
            // update number of records in file
                numRecords++;
                ofstream output;
                output.open("TAs.txt", ios::in | ios::out);
                output.seekp(0,ios::beg);
                output << numRecords;
                output.close();
            }
        }
        else if (selection == 'n' || selection == 'N') {
            cout << "\nTA records can be found in file TAs.txt" << endl;
            break;
        }
        else {
            cout << "Please enter y/n!" << endl;
        }
    } while (true);
    
    
    return 0;
}

// function definitions
bool search_duplicate_ID(int id) {
    bool found = false;
    ifstream infile;
    infile.open("TAs.txt");
    string f_name, l_name, c;
    int s_id, yr, hrs;
    int records;
    
    infile >> records;
    while (!infile.eof()) {
        infile >> s_id;
        infile >> f_name;
        infile >> l_name;
        infile >> yr;
        infile >> c;
        infile >> hrs;
        if(s_id == id) {
            found = true;
            break;
        }
    }
    infile.close();
    
    return found;
}

int validateID() {
    int id{};
    string input;
    bool done = false;
    do {
        cout << "Enter student ID: ";
        cin >> input;
        istringstream validator{input}; // connect input to string stream
        if (validator >> id) { // check if extraction was successful
            if (id > 0) { // check if integer is positive
                if (!search_duplicate_ID(id)) // check if id is not duplicate entry
                    done = true;
                else
                    cout << "This ID already exists in the file!" << endl;
            }
            else
                cout << "ID cannot be negative!" << endl;
        }
        else
            cout << "You entered an invalid ID!" << endl; // user did not enter an integer
        
        // discard input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    } while (!done);
    
    return id;
}

int validateHireYear() {
    int year{};
    string input;
    bool done = false;
    do {
        cout << "Enter hire year: ";
        cin >> input;
        istringstream validator{input}; // connect input to string stream
        if (validator >> year) { // check if extraction was successful
            if (year > 0) // check if integer is positive
                done = true;
            else
                cout << "Year cannot be negative!" << endl;
        }
        else
            cout << "You entered an invalid year!" << endl; // user did not enter an integer
        
        // discard input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    } while (!done);
    
    return year;
}

int validateWorkingHours() {
    int hours{};
    string input;
    bool done = false;
    do {
        cout << "Enter number of working hours: ";
        cin >> input;
        istringstream validator{input}; // connect input to string stream
        if (validator >> hours) { // check if extraction was successful
            if (hours > 0) // check if integer is positive
                done = true;
            else
                cout << "Hours cannot be negative!" << endl;
        }
        else
            cout << "You entered an invalid number of hours!" << endl; // user did not enter an integer
        
        // discard input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    } while (!done);
    
    return hours;
}

string validateClassification() {
    string input;
    bool done = false;
    do {
        cout << "Enter classifaction in the format Grad/Alum: ";
        cin >> input;
        if (input == "Grad" || input == "Alum") // check if classification was enetered as expected
            done = true;
        else
            cout << "You entered an invalid classification!" << endl; 
        
        // discard input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    } while (!done);
    
    return input;
}

string validateFirstName() {
    string input;
    bool done = false;
    do {
        cout << "Enter first name: ";
        cin >> input;
        if (string::npos == input.find_first_of("0123456789")) // check if input conatins digits
            done = true;
        else
            cout << "Name cannot contain numbers!" << endl; 
        
        // discard input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    } while (!done);
    
    return input;
}

string validateLastName() {
    string input;
    bool done = false;
    do {
        cout << "Enter last name: ";
        cin >> input;
        if (string::npos == input.find_first_of("0123456789")) // check if input conatins digits
            done = true;
        else
            cout << "Name cannot contain numbers!" << endl; 
        
        // discard input buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
    } while (!done);
    
    return input;
}

bool AddnewTA() {
    int student_id, hire_year, number_of_working_hours;
    string first_name, last_name, classification;
    
    // get validated user inputs
    student_id = validateID();
    first_name = validateFirstName();
    last_name = validateLastName();
    hire_year = validateHireYear();
    classification = validateClassification();
    number_of_working_hours = validateWorkingHours();
    
    // if a grad student is entered, append information to file
    if (classification == "Grad") {
        ofstream outfile;
        outfile.open("TAs.txt",ios::app);
        outfile << student_id << " " << first_name << " " << last_name << " " << hire_year
                << " " << classification << " " << number_of_working_hours << endl;
        outfile.close();
        return true;
    }
    
    cout << "Alum cannot be added to file!" << endl;
    return false;
}




