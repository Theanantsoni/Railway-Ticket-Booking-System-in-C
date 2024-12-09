#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBookingID(char bookingID[]) {
    // Generates a random Booking ID like AB1234567
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i; // Declare the loop variable outside the for loop (C89 compatible)
    
    bookingID[0] = letters[rand() % 26];
    bookingID[1] = letters[rand() % 26];
    
    for (i = 2; i < 9; i++) {
        bookingID[i] = '0' + rand() % 10; // Generates digits from 0 to 9
    }
    bookingID[9] = '\0'; // Null-terminate the string
}

int main() {
    char confirm;
    char bookingID[10]; // To store Booking ID
    srand(time(0)); // Seed for random number generator
    
    // Display a confirmation prompt
    printf("Do you want to proceed with booking? (Y/N): ");
    scanf(" %c", &confirm); // Taking user input
    
    if (confirm == 'Y' || confirm == 'y') {
        // If the user confirms the booking
        generateBookingID(bookingID); // Generate random booking ID
        
        // Display booking details
        printf("\n----------------------- Your Ticket is Successfully Booked -----------------------\n");
        printf("Booking ID:          %s\n", bookingID);
        printf("Payment Status:      Paid\n");
        printf("Thank You for Booking with Us!\n");
        printf("----------------------- Happy Journey! -----------------------\n");
    } else if (confirm == 'N' || confirm == 'n') {
        // If the user cancels the booking
        printf("\n----------------------- Booking Canceled -----------------------\n");
        printf("You have canceled the booking. Feel free to book again later.\n");
    } else {
        // Invalid input handling
        printf("Invalid input. Please enter 'Y' or 'N'.\n");
    }

    return 0;
}

