#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;
//1. login aand registration 
// 2. introduce customer with discount to previous known consumers
//3. give discount if the custome has been found visiting the shop earlier 
// 4. biggest bill and smallest bill 
// 5. help the business owner get into the analytics of the data that you have over , can you cahrt that data out on the windows screeen or get some analytics operations on the data that is stored over there
//6.
void menu();//main menu function prototype

class ManageMenu
{
protected:
    string userName; //hide admin name

public:

    //virtual void menu(){}

    ManageMenu()
    {
        system("color 0A"); //change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu(); //call to main function to load after executing the constructr
    }

    ~ManageMenu(){} //de
};

class Customer
{
public:
    string name, gender, address;
    int age, mobileNo, menuBack;
    static int cusID; // Static variable to maintain a unique customer ID
    char all[999];

    // Function to get customer details and save them to a file
    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app); // Open the file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID; // Input the customer ID
            cout << "Enter Name: ";
            cin >> name; // Input the customer's name
            cout << "Enter Age: ";
            cin >> age; // Input the customer's age
            cout << "Enter Mobile Number: ";
            cin >> mobileNo; // Input the customer's mobile number
            cout << "Address: ";
            cin >> address; // Input the customer's address
            cout << "Gender: ";
            cin >> gender; // Input the customer's gender
        }
        // Write the customer details to the file
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close(); // Close the file
        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n" << endl;
    }

    // Function to display old customer records from a file
    void showDetails()
    {
        ifstream in("old-customers.txt"); // Open the file for reading
        {
            if (!in)
            {
                cout << "File Error!" << endl; // Display an error message if the file cannot be opened
            }
            while (!in.eof())
            {
                in.getline(all, 999); // Read each line of customer records from the file
                cout << all << endl; // Display the customer records
            }
            in.close(); // Close the file
        }
    }
};

int Customer::cusID; // Initialize the static member variable


class Cabs
{
public:
    int cabChoice;          // To store the user's cab choice (1 for Standard, 2 for Luxury)
    int kilometers;         // To store the number of kilometers to be traveled
    float cabCost;          // To store the calculated cost for the cab ride
    static float lastCabCost;  // Static variable to store the cost of the last cab ride

    // Function to provide cab details and calculate the cost
    void cabDetails()
    {
        cout << "We collaborate with the fastest, safest, and smartest cab service around the country" << endl;
        cout << "-----------ABC Cabs-----------\n" << endl;
        cout << "1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 per 1KM" << endl;

        cout << "\nEnter another key to go back or," << endl;

        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;  // User selects the type of cab (1 for Standard, 2 for Luxury)
        cout << "Enter kilometers you have to travel: ";
        cin >> kilometers;  // User inputs the distance to be traveled

        int hireCab;  // Variable to store the user's choice to hire the selected cab

        if (cabChoice == 1)
        {
            cabCost = kilometers * 15;  // Calculate the cost for a standard cab ride
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab" << endl;
            cout << "Press 1 to hire this cab or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;  // Update the last cab cost with the calculated cost
                cout << "\nYou have successfully hired a standard cab" << endl;
                cout << "Go to Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();  // User can select another cab
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(7100);
                system("CLS");
                cabDetails();  // Invalid input, redirecting to cab selection
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometers * 25;  // Calculate the cost for a luxury cab ride
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab" << endl;
            cout << "Press 1 to hire this cab or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;  // Update the last cab cost with the calculated cost
                cout << "\nYou have successfully hired a luxury cab" << endl;
                cout << "Go to Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();  // User can select another cab
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();  // Invalid input, redirecting to cab selection
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();  // Invalid cab choice, redirecting to the main menu
        }

        cout << "\nPress 1 to Redirect to Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if (hireCab == 1)
        {
            menu();  // Redirect to the main menu
        }
        else
        {
            menu();  // Redirect to the main menu
        }
    }
};

float Cabs::lastCabCost; // Initialize the static member variable

class Booking
{
public:
    int choiceHotel;      // To store the user's choice of hotel (1 for Avendra, 2 for ChoiceYou, 3 for ElephantBay)
    int packChoice1;      // To store the user's choice of package within the selected hotel
    int gotoMenu;         // To store the user's choice to return to the main menu
    static float hotelCost;  // Static variable to store the cost of the selected hotel package

    // Function to handle hotel booking
    void hotels()
    {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};

        // Display the available hotels
        for (int a = 0; a < 3; a++)
        {
            cout << (a + 1) << ". Hotel " << hotelNo[a] << endl;
        }

        cout << "\nCurrently, we are collaborating with the above hotels!" << endl;

        cout << "Press any key to go back or\nEnter the number of the hotel you want to book or see details: ";
        cin >> choiceHotel;

        system("CLS");

        if (choiceHotel == 1)
        {
            // Display information about Hotel Avendra
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n" << endl;
            cout << "The Garden, food, and beverage. Enjoy all you can drink, stay cool, and get chilled in the summer sun." << endl;

            cout << "Packages offered by Avendra:\n" << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra: Rs.15000.00" << endl;

            cout << "\nPress another key to go back or\nEnter the package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked the Standard Pack at Avendra" << endl;
                cout << "Go to Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked the Premium Pack at Avendra" << endl;
                cout << "Go to Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked the Luxury Pack at Avendra" << endl;
                cout << "Go to Menu to take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect to the Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();  // Redirect to the main menu
            }
            else
            {
                menu();  // Redirect to the main menu
            }
        }
        else if (choiceHotel == 2)
        {
            // Display information about Hotel ChoiceYou
            cout << "-------WELCOME TO HOTEL CHOICEYOU-------\n" << endl;
            cout << "Swimming Pool | Free WiFi | Family Rooms \nFitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by ChoiceYou:\n" << endl;
            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter the package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 15000.00;
                cout << "You have successfully booked the Family Pack at ChoiceYou" << endl;
                cout << "Go to Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "You have successfully booked the Couple Pack at ChoiceYou" << endl;
                cout << "Go to Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked the Single Pack at ChoiceYou" << endl;
                cout << "Go to Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect to the Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();  // Redirect to the main menu
            }
            else
            {
                menu();  // Redirect to the main menu
            }
        }
        else if (choiceHotel == 3)
        {
            // Display information about Hotel ElephantBay
            cout << "-------WELCOME TO HOTEL ELEPHANTBAY-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river while seeing elephants" << endl;
            cout << "Amazing offer this summer: Rs.5000.00 for a one day!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked the ElephantBay Special Pack" << endl;
                cout << "Go to Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect to the Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();  // Redirect to the main menu
            }
            else
            {
                menu();  // Redirect to the main menu
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();  // Invalid hotel choice, redirecting to the main menu
        }
    }
};

float Booking::hotelCost;  // Initialize the static member variable

class Chargers : public Booking, Cabs, Customer // Inheriting from multiple base classes (Booking, Cabs, and Customer)
{
public:

    // Function to print the customer's bill
    void printBill()
    {
        // Open a file to create a receipt for the customer's bill
        ofstream outf("receipt.txt"); 
        {
            // Header section of the receipt
            outf << "--------ABC Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            // Customer details section
            outf << "Customer ID: " << Customer::cusID << endl << endl;

            // Cost breakdown section
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            // Total cost section
            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close(); // Close the receipt file
        //cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }

    // Function to show the customer's bill
    void showBill()
    {
        // Open the receipt file for reading
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close(); // Close the receipt file
    }
};

// Function to display the main menu
void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;

    cout << "\t\t      * ABC Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    //cout << "\t|\tAgency System Management -> 0" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; // Create an object of the Customer class
    Cabs a3; // Create an object of the Cabs class
    Booking a4; // Create an object of the Booking class
    Chargers a5; // Create an object of the Chargers class

    /*if(mainChoice == 0){

    }*/
    if (mainChoice == 1)
    {
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1)
        {
            a2.getDetails();  // Call the getDetails function to enter new customer information
        }
        else if (inChoice == 2)
        {
            a2.showDetails();  // Call the showDetails function to display old customer records
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();  // Call the cabDetails function to manage cab bookings
    }
    else if (mainChoice == 3)
    {
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();  // Call the hotels function to manage hotel bookings
    }
    else if (mainChoice == 4)
    {
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();  // Call the printBill function to print the customer's bill
        cout << "Your receipt is already printed; you can get it from the file path\n" << endl;
        cout << "To display your receipt on the screen, Enter 1: or Enter another key to go back to the main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            a5.showBill();  // Call the showBill function to display the customer's bill on the screen
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5)
    {
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}


int main()
{
    ManageMenu startObj;
    return 0;
}

/*
Used IDE: CodeBlocks
*/

Developed effective Travel details management system using C++, showcasing proficiency in file handling and object-oriented programming. Enables simple addition, listing, modification, and deletion of records for seamless user experience.