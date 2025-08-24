#include <iostream>
#include <string>
#include <cstdlib>  // for system
#include <fstream>  // for file operations
#include <ctime>    // for random events
#include <windows.h>  // for Windows API
#include <limits>   // for input validation
#include <algorithm> // for min and max

using namespace std;

// Function declaration for setColor
void setColor(int color);

// Define color constants for Windows console
const int RED = 12;
const int GREEN = 10;
const int YELLOW = 14;
const int WHITE = 15;
const int CYAN = 11;
const int DARK_BLUE = 1;
const int BRIGHT_BLUE = 9;

// Base class Animal
class Animal {
public:
    string name;
    string species;
    int hunger;
    int happiness;
    int energy;
    int health;
    int currency;

    Animal() : hunger(10), happiness(10), energy(10), health(10), currency(100) {}

    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void rest() = 0;
    virtual void groom() = 0;
    virtual void healthCare() = 0;
    virtual void work() = 0;
    virtual void display() = 0;
};

// Derived class Cat
class Cat : public Animal {
public:
    void feed() override {
        if (currency >= 10) {
            setColor(GREEN);
            cout << "Feeding cat..." << endl;
            hunger = min(hunger + 10, 100);
            happiness = min(happiness + 5, 100);
            currency -= 10;
            if (hunger >= 100) {
                cout << name << " is not hungry anymore! Maybe let your cat rest or play." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency to feed your pet!" << endl;
            setColor(WHITE);
        }
    }

    void play() override {
        setColor(GREEN);
        cout << "Playing with cat..." << endl;
        happiness = min(happiness + 10, 100);
        energy = max(energy - 5, 0);
        if (happiness >= 100) {
            cout << name << " is very happy! Maybe let your cat rest or eat." << endl;
        }
        setColor(WHITE);
    }

    void rest() override {
        setColor(GREEN);
        cout << "Cat is resting..." << endl;
        energy = min(energy + 10, 100);
        health = min(health + 5, 100);
        if (energy >= 100) {
            cout << name << " is full of energy! Try playing or feeding your cat." << endl;
        }
        setColor(WHITE);
    }

    void groom() override {
        if (currency >= 5) {
            setColor(GREEN);
            cout << "Grooming cat..." << endl;
            health = min(health + 5, 100);
            happiness = min(happiness + 5, 100);
            currency -= 5;
            if (health >= 100) {
                cout << name << " is in great health! Maybe let your cat play or rest." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency to groom your pet!" << endl;
            setColor(WHITE);
        }
    }

    void healthCare() override {
        if (currency >= 20) {
            setColor(GREEN);
            cout << "Taking cat to the vet..." << endl;
            health = min(health + 20, 100);
            currency -= 20;
            if (health >= 100) {
                cout << name << " is in great health! Maybe let your cat play or rest." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency for healthcare!" << endl;
            setColor(WHITE);
        }
    }

    void work() override {
        setColor(GREEN);
        cout << "Cat is working..." << endl;
        happiness = max(happiness - 5, 0);
        energy = max(energy - 10, 0);
        health = min(health + 5, 100);
        currency += 15;
        if (happiness <= 0) {
            cout << name << " is unhappy! Try playing with your cat." << endl;
        }
        if (energy <= 0) {
            cout << name << " is tired! Let your cat rest." << endl;
        }
        setColor(WHITE);
    }

    void display() override {
        setColor(CYAN);
        cout << "Pet Status:" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Energy: " << energy << endl;
        cout << "Health: " << health << endl;
        cout << "Currency: $" << currency << endl;
        setColor(WHITE);
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void feed() override {
        if (currency >= 10) {
            setColor(GREEN);
            cout << "Feeding dog..." << endl;
            hunger = min(hunger + 10, 100);
            happiness = min(happiness + 5, 100);
            currency -= 10;
            if (hunger >= 100) {
                cout << name << " is not hungry anymore! Maybe let your dog rest or play." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency to feed your pet!" << endl;
            setColor(WHITE);
        }
    }

    void play() override {
        setColor(GREEN);
        cout << "Playing with dog..." << endl;
        happiness = min(happiness + 10, 100);
        energy = max(energy - 5, 0);
        if (happiness >= 100) {
            cout << name << " is very happy! Maybe let your dog rest or eat." << endl;
        }
        setColor(WHITE);
    }

    void rest() override {
        setColor(GREEN);
        cout << "Dog is resting..." << endl;
        energy = min(energy + 10, 100);
        health = min(health + 5, 100);
        if (energy >= 100) {
            cout << name << " is full of energy! Try playing or feeding your dog." << endl;
        }
        setColor(WHITE);
    }

    void groom() override {
        if (currency >= 5) {
            setColor(GREEN);
            cout << "Grooming dog..." << endl;
            health = min(health + 5, 100);
            happiness = min(happiness + 5, 100);
            currency -= 5;
            if (health >= 100) {
                cout << name << " is in great health! Maybe let your dog play or rest." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency to groom your pet!" << endl;
            setColor(WHITE);
        }
    }

    void healthCare() override {
        if (currency >= 20) {
            setColor(GREEN);
            cout << "Taking dog to the vet..." << endl;
            health = min(health + 20, 100);
            currency -= 20;
            if (health >= 100) {
                cout << name << " is in great health! Maybe let your dog play or rest." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency for healthcare!" << endl;
            setColor(WHITE);
        }
    }

    void work() override {
        setColor(GREEN);
        cout << "Dog is working..." << endl;
        happiness = max(happiness - 5, 0);
        energy = max(energy - 10, 0);
        health = min(health + 5, 100);
        currency += 15;
        if (happiness <= 0) {
            cout << name << " is unhappy! Try playing with your dog." << endl;
        }
        if (energy <= 0) {
            cout << name << " is tired! Let your dog rest." << endl;
        }
        setColor(WHITE);
    }

    void display() override {
        setColor(CYAN);
        cout << "Pet Status:" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Energy: " << energy << endl;
        cout << "Health: " << health << endl;
        cout << "Currency: $" << currency << endl;
        setColor(WHITE);
    }
};

// Derived class Bird
class Bird : public Animal {
public:
    void feed() override {
        if (currency >= 10) {
            setColor(GREEN);
            cout << "Feeding bird..." << endl;
            hunger = min(hunger + 10, 100);
            happiness = min(happiness + 5, 100);
            currency -= 10;
            if (hunger >= 100) {
                cout << name << " is not hungry anymore! Maybe let your bird rest or play." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency to feed your pet!" << endl;
            setColor(WHITE);
        }
    }

    void play() override {
        setColor(GREEN);
        cout << "Playing with bird..." << endl;
        happiness = min(happiness + 10, 100);
        energy = max(energy - 5, 0);
        if (happiness >= 100) {
            cout << name << " is very happy! Maybe let your bird rest or eat." << endl;
        }
        setColor(WHITE);
    }

    void rest() override {
        setColor(GREEN);
        cout << "Bird is resting..." << endl;
        energy = min(energy + 10, 100);
        health = min(health + 5, 100);
        if (energy >= 100) {
            cout << name << " is full of energy! Try playing or feeding your bird." << endl;
        }
        setColor(WHITE);
    }

    void groom() override {
        if (currency >= 5) {
            setColor(GREEN);
            cout << "Grooming bird..." << endl;
            health = min(health + 5, 100);
            happiness = min(happiness + 5, 100);
            currency -= 5;
            if (health >= 100) {
                cout << name << " is in great health! Maybe let your bird play or rest." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency to groom your pet!" << endl;
            setColor(WHITE);
        }
    }

    void healthCare() override {
        if (currency >= 20) {
            setColor(GREEN);
            cout << "Taking bird to the vet..." << endl;
            health = min(health + 20, 100);
            currency -= 20;
            if (health >= 100) {
                cout << name << " is in great health! Maybe let your bird play or rest." << endl;
            }
            setColor(WHITE);
        } else {
            setColor(RED);
            cout << "Not enough currency for healthcare!" << endl;
            setColor(WHITE);
        }
    }

    void work() override {
        setColor(GREEN);
        cout << "Bird is working..." << endl;
        happiness = max(happiness - 5, 0);
        energy = max(energy - 10, 0);
        health = min(health + 5, 100);
        currency += 15;
        if (happiness <= 0) {
            cout << name << " is unhappy! Try playing with your bird." << endl;
        }
        if (energy <= 0) {
            cout << name << " is tired! Let your bird rest." << endl;
        }
        setColor(WHITE);
    }

    void display() override {
        setColor(CYAN);
        cout << "Pet Status:" << endl;
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Energy: " << energy << endl;
        cout << "Health: " << health << endl;
        cout << "Currency: $" << currency << endl;
        setColor(WHITE);
    }
};

// Function to set text color using Windows API
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to initialize the game
Animal* initializeGame() {
    setColor(CYAN);
    cout << "Welcome to the Virtual Pet Game!" << endl;
    setColor(WHITE);
    cout << "Enter the name of your pet: ";
    string petName;
    cin >> petName;
    cout << "Choose your pet species:" << endl;
    cout << "1. Cat" << endl;
    cout << "2. Dog" << endl;
    cout << "3. Bird" << endl;
    cout << "Enter your choice: ";
    int speciesChoice;
    cin >> speciesChoice;

    while (cin.fail() || speciesChoice < 1 || speciesChoice > 3) {
        setColor(RED);
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        setColor(WHITE);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> speciesChoice;
    }

    Animal* myPet;

    switch (speciesChoice) {
        case 1:
            myPet = new Cat();
            myPet->species = "Cat";
            break;
        case 2:
            myPet = new Dog();
            myPet->species = "Dog";
            break;
        case 3:
            myPet = new Bird();
            myPet->species = "Bird";
            break;
    }

    myPet->name = petName;

    setColor(DARK_BLUE);
    cout << "Game loaded." << endl;
    setColor(WHITE);
    cout << endl;
    return myPet;
}

void displayMenu() {
    setColor(BRIGHT_BLUE);
    cout << "What would you like to do?" << endl;
    setColor(WHITE);
    cout << "1. Feed" << endl;
    cout << "2. Play" << endl;
    cout << "3. Rest" << endl;
    cout << "4. Groom" << endl;
    cout << "5. Health Care" << endl;
    cout << "6. Work" << endl;
    cout << "7. Check Status" << endl;
    cout << "8. Save Game" << endl;
    cout << "9. Load Game" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";
}

void saveGame(Animal* pet) {
    setColor(GREEN);
    ofstream file("savegame.txt");
    file << pet->name << endl;
    file << pet->species << endl;
    file << pet->hunger << endl;
    file << pet->happiness << endl;
    file << pet->energy << endl;
    file << pet->health << endl;
    file << pet->currency << endl;
    file.close();
    cout << "Game saved successfully!" << endl;
    setColor(WHITE);
}

Animal* loadGame() {
    setColor(GREEN);
    ifstream file("savegame.txt");
    if (file.is_open()) {
        string name, species;
        int hunger, happiness, energy, health, currency;

        getline(file, name);
        getline(file, species);
        file >> hunger;
        file >> happiness;
        file >> energy;
        file >> health;
        file >> currency;
        file.close();

        Animal* pet;

        if (species == "Cat") {
            pet = new Cat();
        } else if (species == "Dog") {
            pet = new Dog();
        } else if (species == "Bird") {
            pet = new Bird();
        } else {
            cout << "Unknown species in save file." << endl;
            return nullptr;
        }

        pet->name = name;
        pet->species = species;
        pet->hunger = hunger;
        pet->happiness = happiness;
        pet->energy = energy;
        pet->health = health;
        pet->currency = currency;

        cout << "Game loaded successfully!" << endl;
        setColor(WHITE);
        return pet;
    } else {
        cout << "No save file found." << endl;
        setColor(WHITE);
        return nullptr;
    }
}

int main() {
    Animal* myPet = initializeGame();
    int menuChoice = 0;

    while (menuChoice != 10) {
        displayMenu();
        cin >> menuChoice;

        while (cin.fail() || menuChoice < 1 || menuChoice > 10) {
            setColor(RED);
            cout << "Invalid choice. Please enter a number between 1 and 10: ";
            setColor(WHITE);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> menuChoice;
        }

        switch (menuChoice) {
            case 1:
                myPet->feed();
                break;
            case 2:
                myPet->play();
                break;
            case 3:
                myPet->rest();
                break;
            case 4:
                myPet->groom();
                break;
            case 5:
                myPet->healthCare();
                break;
            case 6:
                myPet->work();
                break;
            case 7:
                myPet->display();
                break;
            case 8:
                saveGame(myPet);
                break;
            case 9:
                delete myPet;
                myPet = loadGame();
                if (myPet == nullptr) {
                    myPet = initializeGame();
                }
                break;
            case 10:
                cout << "Exiting program. Goodbye!" << endl;
                break;
        }

        cout << endl;
   }

    return 0;
}