#include <iostream>
#include <string>
#include <fstream>
// #include<stdlib.h>
// #include <windows.h>
using namespace std;

// #define MAGENTA "\033[35m" /* Magenta */
// #define RESET "\033[0m"

class Hotel
{
    ifstream check;
    string status;

public:
    void showHotelList();
    void showHotelDetails(int hotelId);
    string openflag(int);
};
void Hotel::showHotelList()
{
    ifstream file("hotellist.txt");
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
void Hotel::showHotelDetails(int hotelId)
{
    string filename = "hotel_" + to_string(hotelId) + ".txt";
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
string Hotel::openflag(int id)
{
    string Number = "flag" + to_string(id) + ".txt";
    check.open(Number);
    getline(check, status);
    check.close();
    return status;
}

class payment
{
protected:
    long int choice1, bank, card, date, cvv, user_id;
    char password[10];

public:
    void pay_detail()
    {
        cout << " ================================" << endl;
        cout << "|   How would you like to pay?   |" << endl;
        cout << "|      1 -> Debit Card           |" << endl
             << "|      2 -> Credit Card          |" << endl
             << "|      3 -> Net Banking          |" << endl;
        cout << " ================================" << endl
             << endl;
        cout << "Enter your choice : ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter CVV no.:";
            cin >> cvv;
            cout << "\nTransaction Successful\n";
            break;
        case 2:
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful\n";
            break;
        case 3:
            cout << " ================================" << endl;
            cout << "|        Banks Available:        |" << endl
                 << "|    1 -> State Bank Of India    |" << endl
                 << "|    2 -> ICICI Bank             |" << endl
                 << "|    3 -> HDFC Bank              |" << endl
                 << "|    4 -> IDBI Bank              |" << endl
                 << "|    5 -> Others                 |" << endl;
            cout << " ================================" << endl
                 << endl;
            cout << "Select your bank:" << endl;
            cin >> bank;
            if (bank > 5)
                return pay_detail();
            cout << "You have selected : " << bank << endl;
            cout << "Enter user id : ";
            cin >> user_id;
            cout << "Enter password : ";
            cin >> password;
            cout << "\nTransaction Successful\n";
            break;
        default:
            cout << "\nWrong Input Entered. \nPlease Choose Correct Option" << endl;
            return pay_detail();
        }
    }
};

class check_status : public Hotel, public payment
{
    int total_price;
    int coupon_price = 0;
    string str;
    ofstream change;

public:
    void checkAvailability(int a);
    void makePayment();
    void applyCoupon();
    void booked(int);
    void returnRoomKeys(int);
    void final_price();
};

void check_status::checkAvailability(int a)
{
    str = openflag(a);
    if (str == "true")
    {
        cout << "ABC Hotel Is open for booking" << endl;
        int price_day = 4500;
        int days;
        cout << "Enter The Number Of The Days You Want To Book (Do Not Exceed 10)" << endl;
        cin >> days;
        if (days > 10)
        {
            throw "Number Of Days Can Not Exceed 10 !!";
        }
        cout << "Price : 2500 rupees for 1 Day and 1 night" << endl;
        total_price = days * 2500;
        cout << "Your Total Price : " << total_price << endl;
    }
    else
        cout << "Sorry The Hotel Is Fully Booked Right Now " << endl;
}
void check_status::makePayment()
{
    cout << "Enter 1 For Payment " << endl
         << "1.Pay Now 2. Pay Later" << endl;
    int pay;
    cin >> pay;
    pay_detail();
    cout << "Congratulation Your Hotel Is Booked :) " << endl;
}
void check_status::final_price()
{
    cout << "Total Price After Apply Discount Is :";
    total_price = total_price - (((float)10 / 100) * (total_price));
    cout << total_price << endl;
    makePayment();
}
void check_status::applyCoupon()
{
    int coupon = 500;
    total_price = total_price - 500;
    final_price();
}
void check_status::booked(int id)
{
    string Number = "flag" + to_string(id) + ".txt";
    change.open(Number);
    change << "false";
    change.close();
}
void check_status::returnRoomKeys(int id)
{
    string Number = "flag" + to_string(id) + ".txt";
    change.open(Number);
    change << "true";
    change.close();
}

class Railway
{
protected:
    string pnr;
    int departure, arrival, select, tprice;
    // long int tdate;
    string tdate;
    string dtime, atime, name;

public:
    void openfile()
    {
        ifstream train;
        train.open("trains.txt");
        string show;
        while (getline(train, show))
        {
            cout << show << endl;
        }
        train.close();
    }
    void detail()
    {
        cout << "Enter Your Date Of Journey(DDMMYY) :" << endl;
        cin >> tdate;
        if (tdate.length() > 6 || tdate.length() < 6)
            throw "Error!!, Should Be Of 6 Digits";
        for (int i = 0; i < tdate.length(); i++)
        {
            if (tdate.at(i) < 48 || tdate.at(i) > 57)
                throw "Error!!, Please Enter The Numeric Value Only (0 to 9)";
            else
                continue;
        }
        cout << " ================================" << endl;
        cout << "|          1 -> Mumbai           |" << endl;
        cout << "|          2 -> Agra             |" << endl
             << "|          3 -> Delhi            |" << endl
             << "|          4 -> Kolkata          |" << endl;
        cout << " ================================" << endl
             << endl;
        cout << "Choose Your Departure Station :" << endl;
        cin >> departure;
        cout << "Chosse Your Arrival Station :" << endl;
        cin >> arrival;

        if ((departure == 1 && arrival == 2) || (departure == 2 && arrival == 1) || (departure == 1 && arrival == 3) || (departure == 3 && arrival == 1) || (departure == 1 && arrival == 4) || (departure == 4 && arrival == 1) || (departure == 2 && arrival == 3) || (departure == 3 && arrival == 2) || (departure == 2 && arrival == 4) || (departure == 4 && arrival == 2) || (departure == 3 && arrival == 4) || (departure == 4 && arrival == 3))
            openfile();

        else if (departure == arrival)
        {
            cout << "\nSource and Destination can't be same.  \nTry again" << endl;
            return detail();
        }
        else
        {
            cout << "\nINVALID INPUT!!  \nTry again" << endl;
            return detail();
        }
    }

    void selecttrain()
    {
        cout << "Select One Of The Trains Availble Here" << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            name = "Rajdhani", dtime = "8:00", atime = "11:00", tprice = 2000;
            break;
        case 2:
            name = "Vande Bharat", dtime = "12:00", atime = "5:00", tprice = 1500;
            break;
        case 3:
            name = "Shatabdi", dtime = "3:00", atime = "9:00", tprice = 1800;
            break;
        default:
            cout << "Wrong Input !!" << endl;
            return selecttrain();
        }
    }
};

class Aircraft
{
protected:
    string A_pnr;
    int A_departure, A_arrival, A_select, A_price;
    // long int A_date;
    string A_date;
    string A_dtime, A_atime, A_name;

public:
    void openflight()
    {
        ifstream flight;
        flight.open("flights.txt");
        string show;
        while (getline(flight, show))
        {
            cout << show << endl;
        }
        flight.close();
    }
    void F_detail()
    {
        cout << "Enter Your Date Of Journey(DDMMYY) :" << endl;
        cin >> A_date;
        if (A_date.length() > 6 || A_date.length() < 6)
            throw "Error!!, Should Be Of 6 Digits";
        for (int i = 0; i < A_date.length(); i++)
        {
            if (A_date.at(i) < 48 || A_date.at(i) > 57)
                throw "Error!!, Please Enter The Numeric Value Only (0 to 9)";
            else
                continue;
        }
        cout << " ================================" << endl;
        cout << "|          1 -> Mumbai           |" << endl;
        cout << "|          2 -> Agra             |" << endl
             << "|          3 -> Delhi            |" << endl
             << "|          4 -> Kolkata          |" << endl;
        cout << " ================================" << endl
             << endl;
        cout << "Choose Your Departure Station :" << endl;
        cin >> A_departure;
        cout << "Chosse Your Arrival Station :" << endl;
        cin >> A_arrival;
        if ((A_departure == 1 && A_arrival == 2) || (A_departure == 2 && A_arrival == 1) || (A_departure == 1 && A_arrival == 3) || (A_departure == 3 && A_arrival == 1) || (A_departure == 1 && A_arrival == 4) || (A_departure == 4 && A_arrival == 1) || (A_departure == 2 && A_arrival == 3) || (A_departure == 3 && A_arrival == 2) || (A_departure == 2 && A_arrival == 4) || (A_departure == 4 && A_arrival == 2) || (A_departure == 3 && A_arrival == 4) || (A_departure == 4 && A_arrival == 3))
            openflight();
        else if (A_departure == A_arrival)
        {
            cout << "\nSource and Destination can't be same.  \nTry again" << endl;
            return F_detail();
        }
        else
        {
            cout << "\nINVALID INPUT!!  \nTry again" << endl;
            return F_detail();
        }
    }

    void select_flight()
    {
        cout << "Select One Of The Flights Availble Here" << endl;
        cin >> A_select;
        switch (A_select)
        {
        case 1:
            A_name = "Vistara", A_dtime = "11:00", A_atime = "2:00", A_price = 5000;
            break;
        case 2:
            A_name = "Indigo", A_dtime = "15:00", A_atime = "18:00", A_price = 7500;
            break;
        case 3:
            A_name = "Air India", A_dtime = "20:00", A_atime = "23:00", A_price = 9000;
            break;
        default:
            cout << "Wrong Input !!" << endl;
            return select_flight();
        }
    }
};

class customer : public Railway, public Aircraft, public payment
{
    string Name, email_id;
    int gender, age;
    // long long int contact;
    string contact;

public:
    friend void create(customer);
    friend void F_create(customer);
    string train_pnr()
    {
        ifstream t;
        string number;
        t.open("tpnr.txt");
        getline(t, number);
        t.close();
        return number;
    }
    void write_pnr()
    {
        ofstream wt;
        string write;
        int num;
        ifstream see;
        see.open("tpnr.txt");
        getline(see, write);
        see.close();
        num = stoi(write);
        wt.open("tpnr.txt");
        wt << ++num;
        wt.close();
    }
    void set_data()
    {
        detail();
        selecttrain();
        cin.ignore();
        cout << "Enter Your Name :";
        getline(cin, Name);
        cout << "Enter Your Age :";
        cin >> age;
        cin.ignore();
        cout << "Enter Your Contact Number \n(Please Enter 10 Digit Number) :";
        getline(cin, contact);
        if (contact.length() != 10)
            throw "Oyeee NUMBER SHOULD BE OF 10 DIGITS";
        // pnr = ++PNR;
    }
    void other_details()
    {
        cout << " ============================" << endl;
        cout << "|   Choose Your Gender :     |" << endl;
        cout << "|     1 -> Male              |" << endl
             << "|     2 -> Female            |" << endl
             << "|     3 -> Others            |" << endl;
        cout << " ============================" << endl
             << endl;
        cin >> gender;
        if (gender > 3 || gender < 1)
            throw "Error!!! , Enter Correct Gender";
        cin.ignore();
        cout << "Enter Your Email Id :" << endl;
        getline(cin, email_id);
        cout << "Your Ticket Has Been Booked." << endl;
        cout << "Thanks For Your Visit. Hope Your Journey Will Become Fantastic." << endl;
        pnr = train_pnr();
        write_pnr();
    }
    void display_passenger_details()
    {
        cout << endl;
        cout << "PNR Number :" << pnr << endl;
        cout << "Train :" << name << endl;
        cout << "Train Date :" << tdate << endl;
        cout << "Departure Time :" << dtime << endl;
        cout << "Arrival Time :" << atime << endl;
        cout << "Total Price :" << tprice << endl;
        cout << "Name :" << Name << endl;
        cout << "Age :" << age << endl;
    }

    string Flight_pnr()
    {
        ifstream f;
        string number;
        f.open("fpnr.txt");
        getline(f, number);
        f.close();
        return number;
    }
    void F_write_pnr()
    {
        ofstream fwt;
        string write;
        int num;
        ifstream see;
        see.open("fpnr.txt");
        getline(see, write);
        see.close();
        num = stoi(write);
        fwt.open("fpnr.txt");
        fwt << ++num;
        fwt.close();
    }
    void F_set_data()
    {
        F_detail();
        select_flight();
        cin.ignore();
        cout << "Enter Your Name :";
        getline(cin, Name);
        cout << "Enter Your Age :";
        cin >> age;
        cin.ignore();
        cout << "Enter Your Contact Number \n(Please Enter 10 Digit Number) :";
        getline(cin, contact);
        if (contact.length() != 10)
            throw "Oyeee NUMBER SHOULD BE OF 10 DIGITS";
    }

    void F_other_details()
    {
        cout << " ============================" << endl;
        cout << "|   Choose Your Gender :     |" << endl;
        cout << "|     1 -> Male              |" << endl
             << "|     2 -> Female            |" << endl
             << "|     3 -> Others            |" << endl;
        cout << " ============================" << endl
             << endl;
        cin >> gender;
        if (gender > 3 || gender < 1)
            throw "Error!!! , Enter Correct Gender";
        cin.ignore();
        cout << "Enter Your Email Id :" << endl;
        getline(cin, email_id);
        cout << "Your Ticket Has Been Booked." << endl;
        cout << "Thanks For Your Visit. Hope Your Journey Will Become Fantastic." << endl;
        A_pnr = Flight_pnr();
        F_write_pnr();
    }

    void Flight_display_passenger_details()
    {
        cout << endl;
        cout << "PNR Number :" << A_pnr << endl;
        cout << "Flight Name :" << A_name << endl;
        cout << "Flight Date :" << A_date << endl;
        cout << "Departure Time :" << A_dtime << endl;
        cout << "Arrival Time :" << A_atime << endl;
        cout << "Total Price :" << A_price << endl;
        cout << "Name :" << Name << endl;
        cout << "Age :" << age << endl;
    }
};

void create(customer c)
{
    ofstream out;
    out.open("passenger.txt", ios::app);
    out << "PNR Number :" << c.pnr << endl;
    out << "Train :" << c.name << endl;
    out << "Train Date :" << c.tdate << endl;
    out << "Departure Time :" << c.dtime << endl;
    out << "Arrival Time :" << c.atime << endl;
    out << "Name :" << c.Name << endl;
    out << "Age :" << c.age << endl;
    out.close();
}

void checkticket(string x)
{
    ifstream show;
    string line;

    bool pass = true;
    show.open("passenger.txt");
    while (getline(show, line))
    {
        if (line.find("PNR Number :" + x) != string::npos)
        {
            int i = 1;
            cout << ("PNR Number :" + x) << endl;
            while (i < 7)
            {
                getline(show, line);
                cout << line << endl;
                i++;
            }
            pass = true;
            break;
        }
        pass = false;
    }
    show.close();
    if (pass == true)
    {
    }
    else
    {
        cout << "Ticket Not Found !!" << endl;
    }
}

void cancelticket(string pnr)
{
    ifstream fin("passenger.txt");
    ofstream fout("temp.txt");
    string line;

    bool found = false;

    while (getline(fin, line))
    {
        if (line.find("PNR Number :" + pnr) != string::npos)
        {
            found = true;
            for (int i = 0; i < 6; ++i)
            {
                getline(fin, line);
            }
        }
        else
        {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    if (found)
    {
        remove("passenger.txt");
        rename("temp.txt", "passenger.txt");
        cout << "Ticket with PNR " << pnr << " canceled successfully." << endl;
    }
    else
    {
        cout << "Ticket with PNR " << pnr << " not found." << endl;
        remove("temp.txt");
    }
}

void F_create(customer f)
{
    ofstream out;
    out.open("fpassenger.txt", ios::app);
    out << "PNR Number :" << f.A_pnr << endl;
    out << "Flight Name :" << f.A_name << endl;
    out << "Flight Date :" << f.A_date << endl;
    out << "Departure Time :" << f.A_dtime << endl;
    out << "Arrival Time :" << f.A_atime << endl;
    out << "Name :" << f.Name << endl;
    out << "Age :" << f.age << endl;
    out.close();
}
void F_checkticket(string a)
{
    ifstream show;
    string line;
    bool pass = true;
    show.open("fpassenger.txt");
    while (getline(show, line))
    {
        if (line.find("PNR Number :" + a) != string::npos)
        {
            int i = 1;
            cout << ("PNR Number :" + a) << endl;
            while (i < 7)
            {
                getline(show, line);
                cout << line << endl;
                i++;
            }
            pass = true;
            break;
        }
        pass = false;
    }
    show.close();
    if (pass == true)
    {
    }
    else
    {
        cout << "Ticket Not Found" << endl;
    }
}

void F_cancelticket(string f_pnr)
{
    ifstream fin("fpassenger.txt");
    ofstream fout("ftemp.txt");
    string line;

    bool found = false;

    while (getline(fin, line))
    {
        if (line.find("PNR Number :" + f_pnr) != string::npos)
        {
            found = true;
            for (int i = 0; i < 6; ++i)
            {
                getline(fin, line);
            }
        }
        else
        {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    if (found)
    {
        remove("fpassenger.txt");
        rename("ftemp.txt", "fpassenger.txt");
        cout << "Ticket with PNR " << f_pnr << " canceled successfully." << endl;
    }
    else
    {
        cout << "Ticket with PNR " << f_pnr << " not found." << endl;
        remove("ftemp.txt");
    }
}

void T_receipt(string p)
{
    ifstream show;
    string print;
    show.open("passenger.txt");
    bool pass = true;
    while (getline(show, print))
    {
        if (print.find("PNR Number :" + p) != string::npos)
        {
            int i = 1;
            string copy;
            string FileName = "treceipt" + (p) + ".txt";
            ofstream wr(FileName);
            wr << ("PNR Number :" + p) << endl;
            while (i < 7)
            {
                getline(show, print);
                wr << print << endl;
                // cout << print << endl;
                i++;
            }
            pass = true;
            wr.close();
            break;
        }
        pass = false;
    }
    show.close();
    if (pass == true)
    {
    }
    else
        cout << "Ticket Not Found!" << endl;
}

void F_receipt(string p)
{
    ifstream show;
    string print;
    show.open("fpassenger.txt");
    bool pass = true;
    while (getline(show, print))
    {
        if (print.find("PNR Number :" + p) != string::npos)
        {
            int i = 1;
            string copy;
            string FileName = "freceipt" + (p) + ".txt";
            ofstream wr(FileName);
            wr << ("PNR Number :" + p) << endl;
            while (i < 7)
            {
                getline(show, print);
                wr << print << endl;
                // cout << print << endl;
                i++;
            }
            pass = true;
            wr.close();
            break;
        }
        pass = false;
    }
    show.close();
    if (pass == true)
    {
    }
    else
        cout << "Ticket Not Found!" << endl;
}

int main()
{
    system("Color D");
    cout << endl
         << endl
         << endl;
    cout << "\t\t\tWELCOME TO APNA TRAVEL AGENCY \n\t\tOHH YOU WANNA BOOK HOTELS/TICKETS FOR YOUR TRIP \n\t\t    THEN YOU'RE AT RIGHT PLACE MY FRIEND :)" << endl
         << endl
         << endl;

    cout << " ------------------------------------------------------------------------ " << endl;
    cout << " _________________________________________________________________________" << endl;
    cout << "|                    We Provide You Hotel Booking,                        |\n|                  Ticket Booking -> Flight, Train.                       |" << endl;
    cout << "|                                                                         |" << endl;
    cout << "|                          Press The Button:                              |\n|                       1 -> Book A Hotel                                 |\n|                       2 -> Book A Train Tickets                         |" << endl;
    cout << "|                       3 -> Book A Flight Ticket                         |\n|                       4 -> Exit                                         |" << endl;
    cout << " -------------------------------------------------------------------------" << endl;
    cout << " ________________________________________________________________________ " << endl
         << endl
         << endl;

    int choose;
    try
    {
        cin >> choose;
        if (choose > 4 || choose < 1)
            throw "CHOOSE CORRECT CHOICE NEXT TIME.";
    }
    catch (const char *ptr)
    {
        cout << ptr << endl;
    }

    check_status h1;
    customer *arr = new customer[10];
    customer *frr = new customer[10];
    string p;
    int i = 0, a;
    switch (choose)
    {
    case 1:
        // Hotel System
        // system("start Lushlife.mp3");

        cout << "                                          _ _.-'`-._ _                       " << endl;
        cout << "                                         ;.'________'.;                      " << endl;
        cout << "                              _________n.[____________].n_________           " << endl;
        cout << "                             |--_--_--_--||==||==||==||--_--_--_--|          " << endl;
        cout << "                             |--_--_--_--||..||..||..||--_--_--_--|          " << endl;
        cout << "                             |LI LI LI LI||LI||LI||LI||LI LI LI LI|          " << endl;
        cout << "                             |.. .. .. ..||..||..||..||.. .. .. ..|          " << endl;
        cout << "   Made By ~                 |LI LI LI LI||LI||LI||LI||LI LI LI LI|          " << endl;
        cout << "   Harsh Banswal          ,,;;,;;;,;;;,;;;,;;;,;;;,;;;,;;,;;;,;;;,;;,,       " << endl;
        cout << "                         ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      " << endl;
        cout << endl
             << endl;
        try
        {
        A:
            h1.showHotelList();
            int value;
            cout << "\nEnter The ID Of Hotel to view their status: " << endl;
            cin >> value;
            if (value > 2 || value < 1)
                throw "Error!!, Not Available Right Now";
            h1.showHotelDetails(value);
        B:
            cout << " ==============================================" << endl;
            cout << "|    Press 1 for check availabilty status      |" << endl
                 << "|    Press 2 for Hotel List                    |" << endl
                 << "|    Press 3 for Return The Hotel Room keys    |" << endl
                 << "|    Press 4 for Return To Home Screen         |" << endl;
            cout << " ==============================================" << endl
                 << endl;
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                h1.checkAvailability(value);
                break;

            case 2:
                goto A;
                break;

            case 3:
                h1.returnRoomKeys(value);
                cout << "Thanks For Visiting." << endl;
                goto A;
                break;
            case 4:
                return main();
            default:
                cout << "Invalid Input!!!" << endl;
                goto B;
            }
            if (h1.openflag(value) == "true")
            {
            C:
                cout << "Press 1 to apply coupon if you have any or else" << endl
                     << "Press 2" << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    h1.applyCoupon();
                    break;

                case 2:
                    h1.final_price();
                    break;
                default:
                    cout << "Invalid Input!!!" << endl;
                    goto C;
                }
                h1.booked(value);
            }
            else
            {
                goto A;
                cout << endl;
            }
        }

        catch (const char *ptr)
        {
            cout << ptr << endl;
        }
        break;

    case 2:
        // train
        cout << "                                     _____                 . . . . . o o o o o        " << endl;
        cout << "                            __|[_]|__ ___________ _______    ____      o              " << endl;
        cout << "                           |[] [] []| [] [] [] [] [_____(__  ][]]_n_n__][.            " << endl;
        cout << "                          _|________|_[_________]_[________]_|__|________)<           " << endl;
        cout << "   Made By ~               oo    oo 'oo      oo ' oo    oo 'oo 0000---oo\\_           " << endl;
        cout << "   Harsh Banswal           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     " << endl;
        cout << endl
             << endl;
        try
        {
            do
            {
                cout << "Welcome To Train Booking Page" << endl;
                cout << " ==========================" << endl;
                cout << "|    1 -> Book Tickets     |" << endl
                     << "|    2 -> Check Ticket     |" << endl
                     << "|    3 -> Cancel Ticket    |" << endl
                     << "|    4 -> Home Screen      |" << endl
                     << "|    5 -> Print Receipt    |" << endl;
                cout << " ==========================" << endl
                     << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    arr[i].set_data();
                    arr[i].other_details();
                    arr[i].display_passenger_details();
                    arr[i].pay_detail();
                    create(arr[i]);
                    break;
                case 2:
                    cout << "Enter Your PNR Number :" << endl;
                    cin >> p;
                    checkticket(p);
                    // j++;
                    break;
                case 3:
                    cout << "Enter PNR Number to cancel ticket: ";
                    cin >> p;
                    cancelticket(p);
                    break;
                case 4:
                    return main();
                case 5:
                    cout << "Enter PNR Number to cancel ticket: ";
                    cin >> p;
                    T_receipt(p);
                    break;
                default:
                    cout << "INVALID INPUT!!" << endl;
                    return main();
                }
                i++;
            } while (a != 5);
        }
        catch (const char *ptr)
        {
            cout << ptr << endl;
        }
        break;

    case 3:
        // flight
        try
        {
            do
            {
                cout << "                          ______                                                   " << endl;
                cout << "                                 \\ _~-\\__                                        " << endl;
                cout << "                          =  = ==(_AA_D                                            " << endl;
                cout << "                                      \\,-~`-.._                                   " << endl;
                cout << "                                      /     o O o o o o O O o o o o o o O o  |\\_  " << endl;
                cout << "   Made By ~                          `~-.__        ___..----..                  ) " << endl;
                cout << "   Harsh Banswal                        ---~~\\___________/------------``````````  " << endl;
                cout << "                                               ====(_D                             " << endl;
                cout << endl;
                cout << "Welcome To Flight Booking Page" << endl;
                cout << " ==========================" << endl;
                cout << "|    1 -> Book Tickets     |" << endl
                     << "|    2 -> Check Ticket     |" << endl
                     << "|    3 -> Cancel Ticket    |" << endl
                     << "|    4 -> Home Screen      |" << endl
                     << "|    5 -> Print Receipt    |" << endl;
                cout << " ==========================" << endl
                     << endl;
                cin >> a;
                switch (a)
                {
                case 1:
                    frr[i].F_set_data();
                    frr[i].F_other_details();
                    frr[i].Flight_display_passenger_details();
                    frr[i].pay_detail();
                    F_create(frr[i]);
                    break;
                case 2:
                    cout << "Enter Your PNR Number :" << endl;
                    cin >> p;
                    F_checkticket(p);
                    break;
                case 3:
                    cout << "Enter PNR Number to cancel ticket: ";
                    cin >> p;
                    F_cancelticket(p);
                    break;
                case 4:
                    return main();
                case 5:
                    cout << "Enter PNR Number to cancel ticket: ";
                    cin >> p;
                    F_receipt(p);
                    break;
                default:
                    cout << "INVALID INPUT!!" << endl;
                    return main();
                }
                i++;
            } while (a != 5);
        }
        catch (const char *ptr)
        {
            cout << ptr << endl;
        }
        break;
    case 4:
        cout << "Exiting The Program...." << endl;
        break;
    default:
        break;
    }

    delete[] arr;
    delete[] frr;
    return 0;
}
