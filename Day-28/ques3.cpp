#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Configuration constants
const int ROWS = 5;
const int COLS = 6;
const double TICKET_PRICE = 12.50;

// Struct to represent an individual seat
struct Seat {
    int rowNum;
    int colNum;
    bool isBooked = false;
    string passengerName = "";
};

// Class to manage the booking system operations
class TicketBookingSystem {
private:
    Seat seatingChart[ROWS][COLS];

public:
    // Initialize the seating layout grid
    TicketBookingSystem() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                seatingChart[i][j].rowNum = i + 1;
                seatingChart[i][j].colNum = j + 1;
            }
        }
    }

    // Display the current arrangement of available and reserved seats
    void displaySeatLayout() {
        cout << "\n================= SEATING CHART =================" << endl;
        cout << "      ";
        for (int j = 0; j < COLS; ++j) {
            cout << "[Col " << j + 1 << "] ";
        }
        cout << "\n-------------------------------------------------" << endl;

        for (int i = 0; i < ROWS; ++i) {
            cout << "[Row " << i + 1 << "]  ";
            for (int j = 0; j < COLS; ++j) {
                if (seatingChart[i][j].isBooked) {
                    cout << "  [X]   "; // Seat is taken
                } else {
                    cout << "  [O]   "; // Seat is available
                }
            }
            cout << endl;
        }
        cout << "-------------------------------------------------" << endl;
        cout << "Legend: [O] Available   [X] Reserved" << endl;
        cout << "Ticket Price per Seat: $" << fixed << setprecision(2) << TICKET_PRICE << endl;
        cout << "=================================================\n" << endl;
    }

    // Process a seat reservation request
    void bookTicket() {
        int r, c;
        string name;

        cout << "Enter Row Number (1-" << ROWS << "): ";
        cin >> r;
        cout << "Enter Column Number (1-" << COLS << "): ";
        cin >> c;

        // Input validation bounds check
        if (r < 1 || r > ROWS || c < 1 || c > COLS) {
            cout << "\nError: Invalid seat selection. Row or Column out of bounds." << endl;
            return;
        }

        // Adjust index positions for array coordinates
        int rowIndex = r - 1;
        int colIndex = c - 1;

        if (seatingChart[rowIndex][colIndex].isBooked) {
            cout << "\nError: This seat is already reserved by " 
                 << seatingChart[rowIndex][colIndex].passengerName << "." << endl;
            return;
        }

        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, name);

        // Assign booking data
        seatingChart[rowIndex][colIndex].isBooked = true;
        seatingChart[rowIndex][colIndex].passengerName = name;

        cout << "\nSuccess: Ticket booked successfully for " << name << "!" << endl;
        cout << "Seat Details: Row " << r << ", Column " << c << endl;
        cout << "Total Amount Charged: $" << fixed << setprecision(2) << TICKET_PRICE << endl;
    }

    // Process a reservation cancellation notice
    void cancelTicket() {
        int r, c;
        cout << "Enter booked Row Number (1-" << ROWS << "): ";
        cin >> r;
        cout << "Enter booked Column Number (1-" << COLS << "): ";
        cin >> c;

        if (r < 1 || r > ROWS || c < 1 || c > COLS) {
            cout << "\nError: Invalid seat choice entered." << endl;
            return;
        }

        int rowIndex = r - 1;
        int colIndex = c - 1;

        if (!seatingChart[rowIndex][colIndex].isBooked) {
            cout << "\nNotice: This seat is already empty." << endl;
            return;
        }

        cout << "\nSuccess: Booking for " << seatingChart[rowIndex][colIndex].passengerName 
             << " at Row " << r << ", Column " << c << " has been canceled." << endl;

        // Reset reservation indicators
        seatingChart[rowIndex][colIndex].isBooked = false;
        seatingChart[rowIndex][colIndex].passengerName = "";
    }
};

// Driver entry loop function
int main() {
    TicketBookingSystem system;
    int menuChoice;

    do {
        cout << "=== MAIN SYSTEM MENU ===" << endl;
        cout << "1. Display Seating Layout Grid" << endl;
        cout << "2. Reserve/Book a Ticket" << endl;
        cout << "3. Cancel Existing Booking" << endl;
        cout << "4. Terminate Program" << endl;
        cout << "Select option action (1-4): ";
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                system.displaySeatLayout();
                break;
            case 2:
                system.bookTicket();
                break;
            case 3:
                system.cancelTicket();
                break;
            case 4:
                cout << "\nThank you for using the ticket booking system. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid alternative. Please input a choice between 1 and 4." << endl;
        }
        cout << endl;
    } while (menuChoice != 4);

    return 0;
}
