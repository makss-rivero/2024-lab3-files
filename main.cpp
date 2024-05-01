#include <iostream>
#include <map>
#include <fstream>
using namespace std;

// TASK: 3

// Structure fields: car brand, manufacture year, producing country.
// Operation: calculate amount of cars with specified manufacture year


    struct Car {
        string carBrand;
        string producingCountry;
        int manufactureYear;
    };


    int handleMenu();
    void viewData(int carsList, int maximumCarsCount, Car cars[]);
    void addData(int& carsList, int minimalCarsCount, int maximumCarsCount, Car cars[]);

    void storeDataInFile(Car cars[], int carsList);
    void readDataFromFile();
    void addDataToFile(Car cars[], int carsList, int maximumCarsCount);
    void deleteDataFromFile(string carBrand, Car cars[], int& carsList);
    void calculateAmountOfCars(int carsList, Car cars[]);
    void deleteDataAndFile(int& carsList, Car cars[]);



int main() {
    int studentCode = 84883;
    int totalTaskCount = 20;
    int taskNumber = studentCode % totalTaskCount;

    cout << "Student code: " << studentCode << " & Task number: " << taskNumber << endl;
    cout << endl;

    string input;
    int selectedMenuOption = 0;
    const int maximumCarsCount = 10;
    const int minimalCarsCount = 1;
    int carsList = 0;
    Car cars[maximumCarsCount];

    cout << "Enter 'menu' to view menu options: ";


    while(true) {
        if (cin >> input && input == "menu") {
            selectedMenuOption = handleMenu();
        } else {
            cout << "Invalid input. Enter 'menu' to view menu options: ";
        }

        switch(selectedMenuOption) {
            case 1:
                viewData(carsList, maximumCarsCount, cars);
                break;
            case 2:
                addData(carsList, minimalCarsCount, maximumCarsCount, cars);
                break;
            case 3:
                storeDataInFile(cars, carsList);
                break;
            case 4:
                readDataFromFile();
                break;
            case 5:
                addDataToFile(cars, carsList, maximumCarsCount);
                break;
            case 6: {
                if (carsList == 0) {
                    cout << "No data available" << endl;
                    cout << endl;
                    cout << "Enter 'menu' to view menu options: ";
                    break;
                }
                string carBrand;
                cout << "Enter car brand to delete: ";
                cin >> carBrand;
                deleteDataFromFile(carBrand, cars, carsList);
                break;
            }
            case 7:
                calculateAmountOfCars(carsList, cars);
                break;
            case 8:
                deleteDataAndFile(carsList, cars);
                break;
            case 9:
                cout << "Exiting program..." << endl;
                return 0;
            default: {
                cout << "Invalid menu option" << endl;
                cout << "Enter 'menu' to view menu options: ";
            }
        }
    }
}


int handleMenu() {
    int selectedMenuOption;
    cout << "Menu: " << endl;
    cout << "1. View data" << endl;
    cout << "2. Add data" << endl;
    cout << "3. Store data in text file" << endl;
    cout << "4. Read data from text file" << endl;
    cout << "5. Add data to the file" << endl;
    cout << "6. Remove car brand from list" << endl;
    cout << "7. Calculate amount of cars with specified manufacture year" << endl;
    cout << "8. Delete data and file" << endl;
    cout << "9. Exit program" << endl;
    cout << endl;
    cout << "Select menu option: ";
    cin >> selectedMenuOption;
    return selectedMenuOption;
}

void viewData(int carsList, int maximumCarsCount, Car cars[]) {
    bool dataAvailable = false;

    if (carsList == 0) {
        cout << "No data available" << endl;
        cout << endl;
        cout << "Enter 'menu' to view menu options: ";
        return;
    }
    cout << "Cars list: " << endl;
    cout << endl;

    for (int i = 0; i < maximumCarsCount; i++) {
        if (!cars[i].carBrand.empty()) {
            dataAvailable = true;
            cout << "Car brand: " << cars[i].carBrand << endl;
            cout << "Producing country: " << cars[i].producingCountry << endl;
            cout << "Manufacture year: " << cars[i].manufactureYear << endl;
            cout << endl;
        }
    }
    if (!dataAvailable) {
        cout << "No data available" << endl;
        cout << endl;
    }
    cout << "Enter 'menu' to view menu options: ";
}
void addData(int& carsList, int minimalCarsCount, int maximumCarsCount, Car cars[]) {
    cout << "Enter car data: " << endl;
    cout << endl;

    for (int i = 0; i < maximumCarsCount; i++) {
        carsList++;
        cout << "Enter car " << i + 1 << " brand: ";
        cin >> cars[i].carBrand;
        cout << "Enter producing country: ";
        cin >> cars[i].producingCountry;
        cout << "Enter manufacture year: ";
        cin >> cars[i].manufactureYear;
        cout << endl;

        if (i > minimalCarsCount && i % 2 == 0) {
            cout << "Would you like to fill in data for another car? (yes/no): ";
            string answer;
            cin >> answer;
            if (answer == "no") {
                break;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "Enter 'menu' to view menu options: ";
}

void storeDataInFile(Car cars[], int carsList) {
    if (carsList == 0) {
        cout << "No data to store" << endl;
        cout << endl;
        cout << "Enter 'menu' to view menu options: ";
        return;
    }
    ofstream file("cars.txt");
    for (int i = 0; i < carsList; i++) {
        file << cars[i].carBrand << ", "
             << cars[i].producingCountry << ", "
             << cars[i].manufactureYear << "\n";
    }
    file.close();
    cout << "Data stored in file successfully" << endl;
    cout << endl;
    cout << "Enter 'menu' to view menu options: ";
}
void readDataFromFile()  {
    if (!ifstream("cars.txt")) {
        cout << "File does not exist" << endl;
    } else {
        ifstream file("cars.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    cout << endl;
    cout << "Enter 'menu' to view menu options: ";
}
void addDataToFile(Car cars[], int carsList, int maximumCarsCount) {
    int originalCarsList = carsList;
    if (carsList == 0) {
        cout << "No data available" << endl;
        cout << endl;
        cout << "Enter 'menu' to view menu options: ";
        return;
    }
    for (int i = carsList; i < maximumCarsCount; i++) {
        cout << "Enter car " << i + 1 << " brand: ";
        cin >> cars[i].carBrand;
        cout << "Enter producing country: ";
        cin >> cars[i].producingCountry;
        cout << "Enter manufacture year: ";
        cin >> cars[i].manufactureYear;
        cout << endl;
        carsList++;

        if (i > 0 && i % 2 == 0) {
            cout << "Would you like to fill in data for another car? (yes/no): ";
            string answer;
            cin >> answer;
            if (answer == "no") {
                break;
            }
        }
        cout << endl;
    }

    ofstream file("cars.txt", ios::app);
    for (int i = originalCarsList; i < carsList; i++) {
        file << cars[i].carBrand << ", "
             << cars[i].producingCountry << ", "
             << cars[i].manufactureYear << "\n";
    }
    file.close();
    cout << "Data added to file successfully" << endl;
    cout << endl;

    cout << "Enter 'menu' to view menu options: ";
}
void deleteDataFromFile(string carBrand, Car cars[], int& carsList) {
    int tempSize = 0;
    for (int i = 0; i < carsList; i++) {
        if (cars[i].carBrand != carBrand) {
            cars[tempSize] = cars[i];
            tempSize++;
        }
    }

    for (int i = tempSize; i < carsList; i++) {
        cars[i].carBrand = "";
        cars[i].producingCountry = "";
        cars[i].manufactureYear = 0;
    }

    carsList = tempSize;

    ifstream file("cars.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool carFound = false;

    while (getline(file, line)) {
        if (line.find(carBrand) != string::npos) {
            carFound = true;
            continue;
        }
        tempFile << line << endl;
    }
    file.close();
    tempFile.close();
    remove("cars.txt");
    rename("temp.txt", "cars.txt");

    if (carFound) {
        cout << "Data deleted successfully" << endl;
    } else {
        cout << "Specified brand not found" << endl;
    }
    cout << endl;
    cout << "Enter 'menu' to view menu options: ";
}

void calculateAmountOfCars(int carsList, Car cars[]) {
    if (carsList == 0) {
        cout << "No data available" << endl;
        cout << endl;
        cout << "Enter 'menu' to view menu options: ";
        return;
    }
    int manufactureYear;
    cout << "Enter manufacture year to calculate amount of cars: ";
    cin >> manufactureYear;
    int amountOfCars = 0;
    for (int i = 0; i < carsList; i++) {
        if (cars[i].manufactureYear == manufactureYear) {
            amountOfCars++;
        }
    }

    if (amountOfCars == 0) {
        cout << "No cars manufactured in " << manufactureYear << endl;
        cout << endl;
        cout << "Enter 'menu' to view menu options: ";
        return;
    }
    cout << "Amount of cars manufactured in " << manufactureYear << " is: " << amountOfCars + 1 << endl;
    cout << endl;
    cout << "Enter 'menu' to view menu options: ";
}

void deleteDataAndFile(int& carsList, Car cars[]) {
    Car defaultCar = {"", "", 0};
    for (int i = 0; i < carsList; i++) {
        cars[i] = defaultCar;
    }
    carsList = 0;
    remove("cars.txt");
    cout << "Data and file deleted successfully" << endl;
    cout << endl;
    cout << "Enter 'menu' to view menu options: ";
}