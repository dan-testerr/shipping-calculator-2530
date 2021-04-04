#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const double USA_0 = 6.00, USA_1 = 9.00, USA_2 = 12.00;
const double CAN_0 = 8.00, CAN_1 = 12.00, CAN_2 = 15.00;
const double AUS_0 = 10.00, AUS_1 = 14.00, AUS_2 = 17.00;
const double MARS_0 = 100.00, MARS_1 = 150.00, MARS_2 = 200.00;
const double p0 = 50.00, p1 = 50.01, p2 = 100.00, p3 = 100.01, p4 = 150.00;
const double FRAGILE_COST = 2.00;

int main()
{
    cout << setfill('.') << setw(51) << "\n";
    cout << "ITCS 2530 - Programming Assignment for week #3\n";
    cout << setw(51) << "\n";

    string item;
    string dest;
    char yorn;
    double total;
    double shipping = 0.00;

    // GET INFO

    // get item name
    cout << left << setw(50) << "\nPlease enter the item name (no spaces)" << ":";
    cin >> item;

    // determine whether fragile or not
    cout << setw(49) << "Is the item fragile? (y=yes/n=no)" << ":";
    cin >> yorn;
    switch (yorn)
    {
        case 'Y':
        case 'y':
            shipping += FRAGILE_COST;
            break;
        case 'N':
        case 'n':
            break;
        default:
            cout << "\nInvalid entry, exiting";
            return 1;
    }

    // get order total
    cout << setw(49) << "Please enter your order total" << ":";
    cin >> total;

    // get shipping destination
    cout << setw(49) << "Please enter destination. (usa/can/aus/mars)" << ":";
    cin >> dest;
    if (dest == "usa")
    {
        if (total <= p0) // 50.00
            shipping += USA_0; // 6.00
        else if (total >= p1 && total <= p2) // 50.01 & 100.00
            shipping += USA_1; // 9.00
        else if (total >= p3 && total <= p4) // 100.01 & 150.00
            shipping += USA_2; // 12.00
    }
    else if (dest == "can")
    {
        if (total <= p0) // 50.00
            shipping += CAN_0; // 8.00
        else if (total >= p1 && total <= p2) // 50.01 & 100.00
            shipping += CAN_1; // 12.00
        else if (total >= p3 && total <= p4) // 100.01 & 150.00
            shipping += CAN_2; // 15.00
    }
    else if (dest == "aus")
    {
        if (total <= p0) // 50.00
            shipping += AUS_0; // 10.00
        else if (total >= p1 && total <= p2) // 50.01 & 100.00
            shipping += AUS_1; // 14.00
        else if (total >= p3 && total <= p4) // 100.01 & 150.00
            shipping += AUS_2; // 17.00
    }
    else if (dest == "mars")
    {
        if (total <= p0) // 50.00
            shipping += MARS_0; // 100.00
        else if (total >= p1 && total <= p2) // 50.01 & 100.00
            shipping += MARS_1; // 150.00
        else if (total >= p3 && total <= p4) // 100.01 & 150.00
            shipping += MARS_2; // 200.00
    }
    else // if incorrect value
    {
        cout << "\nInvalid entry, exiting";
        return 1;
    }

    // DISPLAY OUTPUT

    transform(item.begin(), item.end(), item.begin(), ::toupper);
    transform(dest.begin(), dest.end(), dest.begin(), ::toupper);
    cout << setw(41) << "\nYour item is" << item;
    cout << setw(41) << "\nYour shipping cost is" << fixed << setprecision(2) << "$" << shipping;
    cout << setw(41) << "\nYour are shipping to" << dest;
    cout << setw(41) << "\nYour total shipping costs are" << "$" << total + shipping;
    cout << endl << endl << right << setfill('-') << setw(51) << "Thank You!\n";

    return 0;
}