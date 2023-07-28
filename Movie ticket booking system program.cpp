//Task 5
//Develop a program that simulates a movie ticket booking system.Allow users to view movie listings, select seats, make bookings,
//and calculate the total cost. Consider implementing seatavailability and seat selection validation
//Name :Omkar mohare
#include <iostream>
#include <string>
using namespace std;

const int MAX_ROWS = 5;
const int MAX_COLS = 10;

struct Movie {
    string title;
    double ticketPrice;
    int availableSeats[MAX_ROWS][MAX_COLS];
};

void initializeSeats(int seats[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            seats[i][j] = 1; // 1 represents an available seat
        }
    }
}

void displayMovieList(const Movie movies[], int numMovies) {
	cout<<"\t\t\t--------***BookMyShow***--------\n";
    cout << "Movie Listing:\n";
    for (int i = 0; i < numMovies; ++i) {
        cout << i + 1 << ". " << movies[i].title << " -$" << movies[i].ticketPrice << '\n';
    }
    cout << '\n';
}

void displaySeats(const int seats[MAX_ROWS][MAX_COLS]) {
    cout << "Seating Chart:\n";
    cout << "  ";
    for (int col = 0; col < MAX_COLS; ++col) {
        cout << col + 1 << " ";
    }
    cout << '\n';
    
    for (int row = 0; row < MAX_ROWS; ++row) {
        cout << row + 1 << " ";
        for (int col = 0; col < MAX_COLS; ++col) {
            cout << (seats[row][col] ? 'O' : 'X') << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    const int numMovies = 5;
    Movie movies[numMovies];
    
    movies[0] = { "Bawaal", 200.0 };
    movies[1] = { "Bahubali", 120.0 };
    movies[2] = { "Chichore", 150.0 };
    movies[3] = { "3-idiots", 180.0 };
    movies[4] = { "END-GAME", 120.0 };
   
    
    int selectedMovie = -1;
    int numSeats = -1;
    int selectedRow, selectedCol;

    int seats[MAX_ROWS][MAX_COLS];
    initializeSeats(seats);

    while (selectedMovie < 1 || selectedMovie > numMovies) {
        displayMovieList(movies, numMovies);
        cout << "Select a movie (1-" << numMovies << "): ";
        cin >> selectedMovie;
        if (selectedMovie < 1 || selectedMovie > numMovies) {
            cout << "Invalid movie selection. Try again.\n";
        }
    }

    displaySeats(seats);

    while (numSeats < 1) {
        cout << "How many seats do you want to book? ";
        cin >> numSeats;
        if (numSeats < 1) {
            cout << "Invalid number of seats. Try again.\n";
        }
    }

    for (int i = 0; i < numSeats; ++i) {
        while (true) {
            cout << "Select a row and column for seat " << i + 1 << " (row-col): ";
            cin >> selectedRow >> selectedCol;

            if (selectedRow < 1 || selectedRow > MAX_ROWS || selectedCol < 1 || selectedCol > MAX_COLS) {
                cout << "Invalid seat selection. Try again.\n";
            }
            else if (seats[selectedRow - 1][selectedCol - 1] == 0) {
                cout << "Seat is already booked. Try again.\n";
            }
            else {
                // Book the seat
                seats[selectedRow - 1][selectedCol - 1] = 0;
                break;
            }
        }
    }

    double totalCost = movies[selectedMovie - 1].ticketPrice * numSeats;
    cout << "Tickets booked for " << movies[selectedMovie - 1].title << " - Seats: ";
    for (int i = 0; i < numSeats; ++i) {
        cout << selectedRow - i << ", " << selectedCol << " ";
    }
    cout << "\n\n";
    cout << "Total cost: $" << totalCost << '\n';

    return 0;
}

