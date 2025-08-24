#include<iostream>
#include<fstream>
#include<sstream>
#include<limits>
using namespace std;

class Transport {
    public:
        virtual void displayInfo() = 0;
        virtual void displayStations() = 0;
        virtual void generateTicket() = 0;
        virtual void addFavourite() = 0;
        virtual void showFavourite() = 0;
};

class MetroBus : public Transport {
    private:
        string starting_time, lastdeparture_time, headway_time;
        double base_ticket;
        int number_bus, number_station, serial_number;
        string name;
    public:
        MetroBus(string starttime, string endtime, string headwaytime, double basefare, int numberbus, int numberstation, int serialnumber)
            : starting_time(starttime), lastdeparture_time(endtime), headway_time(headwaytime), base_ticket(basefare), number_bus(numberbus), number_station(numberstation), serial_number(serialnumber) {}

        void displayInfo() override {
            cout << "\t\t\t\t\t-------------------------\n";
            cout << "\t\t\t\t\tDisplaying Metro Bus Information\n";
            cout << "\t\t\t\t\t-------------------------\n";
            cout << "|       Total Buses:        | " << number_bus << " Buses\n";
            cout << "|       Total Stations:     | " << number_station << " Stations\n";
            cout << "|       Starting Time:      | " << starting_time << "\n";
            cout << "|       Last Departure Time:| " << lastdeparture_time << "\n";
            cout << "|       Headway Time:       | " << headway_time << "\n";
            cout << "|       Base Ticket:        | " << base_ticket << " PKR\n";
            cout << "\t\t\t\t\t-------------------------\n";
        }

        void displayStations() override {
            cout << "All the Lahore Metro Stations are given below:\n\n";
            string line;
            ifstream file("C:/Users/ST/Desktop/files/metro_bus.txt");
            if (file.is_open()) {
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "Unable to open file" << endl;
            }
        }

        void generateTicket() override {
            ifstream file("C:\\Users\\ST\\Desktop\\files\\serial_numberm.txt");
            if (file.is_open()) {
                file >> serial_number;
                file.close();
            } else {
                serial_number = 1;
            }
            cout << "\t\t\t\tGenerating Metro Bus Ticket\n";
            cout << "Metro Bus Ticket Generated Successfully:\n";
            cout << "----------------------" << endl;
            cout << "| Metro Bus Ticket |" << endl;
            cout << "| Serial Number: " << serial_number << " |" << endl;
            cout << "| Ticket Price: " << base_ticket << " PKR |" << endl;
            cout << "----------------------" << endl;

            serial_number++;
            ofstream file_out("C:\\Users\\ST\\Desktop\\files\\serial_numberm.txt");
            file_out << serial_number;
            file_out.close();
        }

        void addFavourite() override {
            cout << "\t\t\t\tPlease Enter your Name for Metro_bus Favourite File\n";
            cout << "\t\t\t\t-----------------------------------------\n";
            cout << "\t\t\t\t Name:-----------------------------\n";
            cout << "\t\t\t\t|                                       |\n";
            cout << "\t\t\t\t|  ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "\t\t\t\t-----------------------------------------\n";
            cout << "\n\t\t\t\t------------- File Created Successfully-------------\n";
            cout << "\n\t\t\t\t------------- Welcome " << name << "-------------\n";
            ofstream obj;
            obj.open("C:\\Users\\ST\\Desktop\\files\\signin_details.txt", ios_base::app);
            obj << "\nMetro_Bus Name:" << name << endl;
            obj.close();

            while (true) {
                int id;
                displayStations();
                cout << "Please Enter the ID of Station you want to add to favourite\n";
                cin >> id;
                if (cin.fail() || id > 27 || id < 1 || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
                    cout << "Invalid input! Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                ifstream file("C:\\Users\\ST\\Desktop\\files\\metro_bus.txt");
                string line, station;
                int stationId;
                if (file.is_open()) {
                    while (getline(file, line)) {
                        stringstream ss(line);
                        ss >> stationId >> station;
                        if (stationId == id) {
                            cout << "The station corresponding to ID " << id << " is :" << station << endl;
                            obj.open(("C:\\Users\\ST\\Desktop\\favourite\\mfav\\" + name + ".txt").c_str(), ios_base::app);
                            obj << id << "                " << station << endl;
                            cout << "Station Added Successfully!\n";
                            obj.close();
                            break;
                        }
                    }
                    file.close();
                } else {
                    cout << "Unable to open file" << endl;
                }
                int temp;
                cout << "Enter 1 to add more stations in Favourite list || Enter any other integer to exit:\n";
                cin >> temp;
                if (cin.fail() || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
                    cout << "Invalid input! Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (temp != 1) break;
            }
        }

        void showFavourite() override {
            string name1;
            cout << "Please Enter the name of file of Favourite file:\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name1);
            ifstream obj(("C:\\Users\\ST\\Desktop\\favourite\\mfav\\" + name1 + ".txt").c_str());
            if (obj.is_open()) {
                cout << "\t\t\t\t---------------Welcome Back " << name1 << "---------------" << endl;
                cout << "Here is your Metro_bus Favourite List:\nStation id\tStation Name\n\n";
                string s;
                while (getline(obj, s)) {
                    cout << s << endl;
                }
                obj.close();
            } else {
                cout << "File does not exist." << endl;
            }
        }
};

class SpeedoBus : public Transport {
    private:
        string starting_time, lastdeparture_time, headway_time;
        double base_ticket;
        int number_bus, number_station, serial_number;
        string name;
    public:
        SpeedoBus(string starttime, string endtime, string headwaytime, double basefare, int numberbus, int numberstation, int serialnumber)
            : starting_time(starttime), lastdeparture_time(endtime), headway_time(headwaytime), base_ticket(basefare), number_bus(numberbus), number_station(numberstation), serial_number(serialnumber) {}

        void displayInfo() override {
            cout << "\t\t\t\t\t-------------------------\n";
            cout << "\t\t\t\t\tDisplaying Speedo Bus Information\n";
            cout << "\t\t\t\t\t-------------------------\n";
            cout << "|       Total Buses:        | " << number_bus << " Buses\n";
            cout << "|       Total Stations:     | " << number_station << " Stations\n";
            cout << "|       Starting Time:      | " << starting_time << "\n";
            cout << "|       Last Departure Time:| " << lastdeparture_time << "\n";
            cout << "|       Headway Time:       | " << headway_time << "\n";
            cout << "|       Base Ticket:        | " << base_ticket << " PKR\n";
            cout << "\t\t\t\t\t-------------------------\n";
        }

        void displayStations() override {
            cout << "All the Lahore Speedo Bus Stations are given below:\n\n";
            string line;
            ifstream file("C:/Users/ST/Desktop/files/speedo_bus.txt");
            if (file.is_open()) {
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "Unable to open file" << endl;
            }
        }

        void generateTicket() override {
            ifstream file("C:\\Users\\ST\\Desktop\\files\\serial_numbers.txt");
            if (file.is_open()) {
                file >> serial_number;
                file.close();
            } else {
                serial_number = 1;
            }
            cout << "\t\t\t\tGenerating Speedo Bus Ticket\n";
            cout << "Speedo Bus Ticket Generated Successfully:\n";
            cout << "----------------------" << endl;
            cout << "| Speedo Bus Ticket |" << endl;
            cout << "| Serial Number: " << serial_number << " |" << endl;
            cout << "| Ticket Price: " << base_ticket << " PKR |" << endl;
            cout << "----------------------" << endl;

            serial_number++;
            ofstream file_out("C:\\Users\\ST\\Desktop\\files\\serial_numbers.txt");
            file_out << serial_number;
            file_out.close();
        }

        void addFavourite() override {
            cout << "\t\t\t\tPlease Enter your Name for Speedo_bus Favourite File\n";
            cout << "\t\t\t\t-----------------------------------------\n";
            cout << "\t\t\t\t Name:-----------------------------\n";
            cout << "\t\t\t\t|                                       |\n";
            cout << "\t\t\t\t|  ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "\t\t\t\t-----------------------------------------\n";
            cout << "\n\t\t\t\t------------- File Created Successfully-------------\n";
            cout << "\n\t\t\t\t------------- Welcome " << name << "-------------\n";
            ofstream obj;
            obj.open("C:\\Users\\ST\\Desktop\\files\\signin_details.txt", ios_base::app);
            obj << "\nSpeedo_Bus Name:" << name << endl;
            obj.close();

            while (true) {
                int id;
                displayStations();
                cout << "Please Enter the ID of Station you want to add to favourite\n";
                cin >> id;
                if (cin.fail() || id > 30 || id < 1 || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
                    cout << "Invalid input! Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                ifstream file("C:\\Users\\ST\\Desktop\\files\\speedo_bus.txt");
                string line, station;
                int stationId;
                if (file.is_open()) {
                    while (getline(file, line)) {
                        stringstream ss(line);
                        ss >> stationId >> station;
                        if (stationId == id) {
                            cout << "The station corresponding to ID " << id << " is :" << station << endl;
                            obj.open(("C:\\Users\\ST\\Desktop\\favourite\\sfav\\" + name + ".txt").c_str(), ios_base::app);
                            obj << id << "                " << station << endl;
                            cout << "Station Added Successfully!\n";
                            obj.close();
                            break;
                        }
                    }
                    file.close();
                } else {
                    cout << "Unable to open file" << endl;
                }
                int temp;
                cout << "Enter 1 to add more stations in Favourite list || Enter any other integer to exit:\n";
                cin >> temp;
                if (cin.fail() || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
                    cout << "Invalid input! Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (temp != 1) break;
            }
        }

        void showFavourite() override {
            string name1;
            cout << "Please Enter the name of file of Favourite file:\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name1);
            ifstream obj(("C:\\Users\\ST\\Desktop\\favourite\\sfav\\" + name1 + ".txt").c_str());
            if (obj.is_open()) {
                cout << "\t\t\t\t---------------Welcome Back " << name1 << "---------------" << endl;
                cout << "Here is your Speedo_bus Favourite List:\nStation id\tStation Name\n\n";
                string s;
                while (getline(obj, s)) {
                    cout << s << endl;
                }
                obj.close();
            } else {
                cout << "File does not exist." << endl;
            }
        }
};

class OrangeTrain : public Transport {
    private:
        string starting_time, lastdeparture_time, headway_time;
        double base_ticket;
        int number_train, number_station, serial_number;
        string name;
    public:
        OrangeTrain(string starttime, string endtime, string headwaytime, double basefare, int numbertrain, int numberstation, int serialnumber)
            : starting_time(starttime), lastdeparture_time(endtime), headway_time(headwaytime), base_ticket(basefare), number_train(numbertrain), number_station(numberstation), serial_number(serialnumber) {}

        void displayInfo() override {
            cout << "\t\t\t\t\t-------------------------\n";
            cout << "\t\t\t\t\tDisplaying Orange Train Information\n";
            cout << "\t\t\t\t\t-------------------------\n";
            cout << "|       Total Trains:        | " << number_train << " Trains\n";
            cout << "|       Total Stations:     | " << number_station << " Stations\n";
            cout << "|       Starting Time:      | " << starting_time << "\n";
            cout << "|       Last Departure Time:| " << lastdeparture_time << "\n";
            cout << "|       Headway Time:       | " << headway_time << "\n";
            cout << "|       Base Ticket:        | " << base_ticket << " PKR\n";
            cout << "\t\t\t\t\t-------------------------\n";
        }

        void displayStations() override {
            cout << "All the Lahore Orange Train Stations are given below:\n\n";
            string line;
            ifstream file("C:/Users/ST/Desktop/files/orange_train.txt");
            if (file.is_open()) {
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "Unable to open file" << endl;
            }
        }

        void generateTicket() override {
            ifstream file("C:\\Users\\ST\\Desktop\\files\\serial_numbero.txt");
            if (file.is_open()) {
                file >> serial_number;
                file.close();
            } else {
                serial_number = 1;
            }
            cout << "\t\t\t\tGenerating Orange Train Ticket\n";
            cout << "Orange Train Ticket Generated Successfully:\n";
            cout << "----------------------" << endl;
            cout << "| Orange Train Ticket |" << endl;
            cout << "| Serial Number: " << serial_number << " |" << endl;
            cout << "| Ticket Price: " << base_ticket << " PKR |" << endl;
            cout << "----------------------" << endl;

            serial_number++;
            ofstream file_out("C:\\Users\\ST\\Desktop\\files\\serial_numbero.txt");
            file_out << serial_number;
            file_out.close();
        }

        void addFavourite() override {
            cout << "\t\t\t\tPlease Enter your Name for Orange_train Favourite File\n";
            cout << "\t\t\t\t-----------------------------------------\n";
            cout << "\t\t\t\t Name:-----------------------------\n";
            cout << "\t\t\t\t|                                       |\n";
            cout << "\t\t\t\t|  ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "\t\t\t\t-----------------------------------------\n";
            cout << "\n\t\t\t\t------------- File Created Successfully-------------\n";
            cout << "\n\t\t\t\t------------- Welcome " << name << "-------------\n";
            ofstream obj;
            obj.open("C:\\Users\\ST\\Desktop\\files\\signin_details.txt", ios_base::app);
            obj << "\nOrange_Train Name:" << name << endl;
            obj.close();

            while (true) {
                int id;
                displayStations();
                cout << "Please Enter the ID of Station you want to add to favourite\n";
                cin >> id;
                if (cin.fail() || id > 26 || id < 1 || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
                    cout << "Invalid input! Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                ifstream file("C:\\Users\\ST\\Desktop\\files\\orange_train.txt");
                string line, station;
                int stationId;
                if (file.is_open()) {
                    while (getline(file, line)) {
                        stringstream ss(line);
                        ss >> stationId >> station;
                        if (stationId == id) {
                            cout << "The station corresponding to ID " << id << " is :" << station << endl;
                            obj.open(("C:\\Users\\ST\\Desktop\\favourite\\ofav\\" + name + ".txt").c_str(), ios_base::app);
                            obj << id << "                " << station << endl;
                            cout << "Station Added Successfully!\n";
                            obj.close();
                            break;
                        }
                    }
                    file.close();
                } else {
                    cout << "Unable to open file" << endl;
                }
                int temp;
                cout << "Enter 1 to add more stations in Favourite list || Enter any other integer to exit:\n";
                cin >> temp;
                if (cin.fail() || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
                    cout << "Invalid input! Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (temp != 1) break;
            }
        }

        void showFavourite() override {
            string name1;
            cout << "Please Enter the name of file of Favourite file:\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name1);
            ifstream obj(("C:\\Users\\ST\\Desktop\\favourite\\ofav\\" + name1 + ".txt").c_str());
            if (obj.is_open()) {
                cout << "\t\t\t\t---------------Welcome Back " << name1 << "---------------" << endl;
                cout << "Here is your Orange_train Favourite List:\nStation id\tStation Name\n\n";
                string s;
                while (getline(obj, s)) {
                    cout << s << endl;
                }
                obj.close();
            } else {
                cout << "File does not exist." << endl;
            }
        }
};

void mainMenu() {
    cout << "************************************* Welcome to the Transportation System *************************************\n";
    cout << "Please select your transport service:\n";
    cout << "1. Metro Bus\n";
    cout << "2. Speedo Bus\n";
    cout << "3. Orange Train\n";
    cout << "0. Exit\n";
}

int main() {
    int choice;
    while (true) {
        mainMenu();
        cin >> choice;
        if (cin.fail() || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
            cout << "Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice == 0) {
            cout << "Thank you for using the Transportation System. Goodbye!\n";
            break;
        }
        string starttime, endtime, headwaytime;
        double basefare;
        int number, numberstation, serialnumber;
        cout << "Enter starting time: ";
        cin >> starttime;
        cout << "Enter last departure time: ";
        cin >> endtime;
        cout << "Enter headway time: ";
        cin >> headwaytime;
        cout << "Enter base fare: ";
        cin >> basefare;
        cout << "Enter number of vehicles: ";
        cin >> number;
        cout << "Enter number of stations: ";
        cin >> numberstation;
        cout << "Enter serial number: ";
        cin >> serialnumber;

        Transport* transport;
        if (choice == 1) {
            transport = new MetroBus(starttime, endtime, headwaytime, basefare, number, numberstation, serialnumber);
        } else if (choice == 2) {
            transport = new SpeedoBus(starttime, endtime, headwaytime, basefare, number, numberstation, serialnumber);
        } else if (choice == 3) {
            transport = new OrangeTrain(starttime, endtime, headwaytime, basefare, number, numberstation, serialnumber);
        } else {
            cout << "Invalid choice! Please select a valid option.\n";
            continue;
        }

        while (true) {
            cout << "Please select an option:\n";
            cout << "1. Display Information\n";
            cout << "2. Display Stations\n";
            cout << "3. Generate Ticket\n";
            cout << "4. Add Favourite\n";
            cout << "5. Show Favourite\n";
            cout << "0. Back to main menu\n";
            int option;
            cin >> option;
            if (cin.fail() || (cin.peek() != EOF && cin.peek() != '\n' && cin.peek() != ' ')) {
                cout << "Invalid input! Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (option == 0) {
                break;
            }
            switch (option) {
                case 1:
                    transport->displayInfo();
                    break;
                case 2:
                    transport->displayStations();
                    break;
                case 3:
                    transport->generateTicket();
                    break;
                case 4:
                    transport->addFavourite();
                    break;
                case 5:
                    transport->showFavourite();
                    break;
                default:
                    cout << "Invalid choice! Please select a valid option.\n";
                    break;
            }
        }
        delete transport;
    }
    return 0;
}

