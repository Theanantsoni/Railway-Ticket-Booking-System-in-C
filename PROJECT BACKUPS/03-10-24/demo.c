// In this code ... Complete the successfully insert email & password for Register & check email & password for Login for client ... 30/09/24

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

//destch = choice for destination ...
//clcoach = choice for coach [AC & Non-AC]

char tourist_name[100], confirm;
char bookingID[10]; // To store Booking ID
int tourist_age, destch, clcoach, clfood, clticket, tcktprice;
	
// Define an array of destinations
const char *destinations[] = {
    "Surat To Vadodara", 
    "Surat To Ahmedabad", 
    "Surat To Rajkot", 
    "Surat To Jamnagar", 
    "Surat To Bhuj", 
    "Surat To Gandhinagar", 
    "Surat To Junagadh", 
    "Surat To Porbandar", 
    "Surat To Palanpur", 
    "Surat To Navsari"
};

// ------------------------------------------------ Function to remove newline character from fgets input ------------------------------------------------
void removeNewline(char *str) 
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') 
	{
        str[len - 1] = '\0';
    }
}

// ------------------------------------------------ START CODE FOR ADMIN SIDE ------------------------------------------------

// ------------------------------------------------ Function to confirm details [Admin] ------------------------------------------------

int confirmadminregDetails() 
{
    char choice;
    printf("\033[0;35m\nAre the details correct? (y/n): \033[0m");
    scanf(" %c", &choice);  // Space before %c to consume any leftover whitespace
    return (tolower(choice) == 'y');
}

// ------------------------------------------------ Function for new registration [Admin] ------------------------------------------------

void adminregdata() 
{
    FILE *fptr;
    char name[100], contact[20], address[200], email[50], password[50], repeat_password[50];

    // Open the file "admin_reg_data.txt" in append mode ("a")
    fptr = fopen("admin_reg_data.txt", "a");
    if (fptr == NULL) 
	{
        printf("\033[0;35mError opening file!\033[0m\n");
        return;
    }

    while (1) 
	{
       printf("\033[0;34m\n--------------- Admin Registration ---------------\033[0m\n");

        // Clear the input buffer before reading user input
        getchar();  // Consume leftover newline from previous inputs

        printf("\033[0;37m\nEnter your full name: \033[0m");
		fgets(name, sizeof(name), stdin);
		removeNewline(name);  // Remove trailing newline character
		
		printf("\033[0;37m\nEnter your contact number: \033[0m");
		fgets(contact, sizeof(contact), stdin);
		removeNewline(contact);  // Remove trailing newline character
		
		printf("\033[0;37m\nEnter your address: \033[0m");
		fgets(address, sizeof(address), stdin);
		removeNewline(address);  // Remove trailing newline character
		
		printf("\033[0;37m\nEnter your email: \033[0m");
		fgets(email, sizeof(email), stdin);
		removeNewline(email);  // Remove trailing newline character

        // Enter and confirm password
        while (1) 
		{
            printf("\033[0;37m\nEnter your password: \033[0m");
			fgets(password, sizeof(password), stdin);
			removeNewline(password);
			
			printf("\033[0;37m\nRepeat your password: \033[0m");
			fgets(repeat_password, sizeof(repeat_password), stdin);
			removeNewline(repeat_password);

            // Check if passwords match
            if (strcmp(password, repeat_password) == 0) 
			{
                break;  // Passwords match, proceed to confirmation
            } 
			else 
			{
                printf("\033[0;35m\nPasswords do not match. Please try again.\033[0m");
            }
        }

        // Show entered details for confirmation ------------------------------------------------
        printf("\033[0;34m\n--------------- Confirm Your Details ---------------\033[0m\n");
		printf("Name     : \033[0;37m%s\033[0m\n", name);
		printf("Contact  : \033[0;37m%s\033[0m\n", contact);
		printf("Address  : \033[0;37m%s\033[0m\n", address);
		printf("Email    : \033[0;37m%s\033[0m\n", email);
		printf("Password : \033[0;37m%s\033[0m\n", password);

        // Confirm details
        if (confirmadminregDetails()) 
		{
            // Save the details in the file
            fprintf(fptr, "Name: %s, Contact: %s, Address: %s, Email: %s, Password: %s\n",
                    name, contact, address, email, password);
           printf("\033[0;35m\nRegistration successful! Admin registration data saved to file.\033[0m\n");
            break;  // Exit the registration loop
        } 
		else 
		{
            printf("\033[0;35m\nDetails are incorrect. Please try again.\n\033[0m");
            continue;  // Retry the registration process
        }
    }
    // Close the file after registration is done
    fclose(fptr);
}

// ------------------------------------------------ Function for login [Admin] ------------------------------------------------

void adminlogdata() 
{
    FILE *fptr;
    FILE *logfptr;  // File pointer for logging successful logins
    char email[50], password[50];
    char stored_email[50], stored_password[50];
    char line[200]; // Buffer for reading a line from the file
    int login_success = 0;

    // Open the file "admin_reg_data.txt" for reading
    fptr = fopen("admin_reg_data.txt", "r");
    if (fptr == NULL) 
	{
        printf("\033[0;35mError opening admin registration file!\033[0m\n");
        return;
    }

    printf("\033[0;34m\n--------------- Admin Login ---------------\033[0m\n");

    // Flush leftover newline from previous input
    getchar(); // Consume any leftover newline character from buffer

    // Ask for user input for login
    printf("\033[0;37m\nEnter your email: \033[0m");
	fgets(email, sizeof(email), stdin);
	removeNewline(email); // Remove trailing newline
	
	printf("\033[0;37m\nEnter your password: \033[0m");
	fgets(password, sizeof(password), stdin);
	removeNewline(password); // Remove trailing newline

    // Read each line from the file
    while (fgets(line, sizeof(line), fptr) != NULL) 
	{
        // Parse the stored email and password from the line
        sscanf(line, "Name: %*[^,], Contact: %*[^,], Address: %*[^,], Email: %[^,], Password: %s", stored_email, stored_password);

        // Check if the entered email and password match the stored admin_reg_data
        if (strcmp(email, stored_email) == 0 && strcmp(password, stored_password) == 0) 
		{
            login_success = 1; // admin_reg_data match
            break;
        }
    }

    if (login_success) // When admin will be success login than data will be stored in admin_log_data.txt file ...
	{
        printf("\033[0;35m\nLogin successful!\n\033[0m");

        // Open the "admin_log_data.txt" file for appending the login details
        logfptr = fopen("admin_log_data.txt", "a");
        if (logfptr == NULL) 
		{
            printf("\033[0;35mError opening admin log file!\033[0m\n");
        } 
		else 
		{
            // Log the successful login
            fprintf(logfptr, "Email: %s Password: %s logged in successfully at %s\n", email, stored_password, __TIME__);
            printf("\033[0;35m\nLogin details saved to admin_log_data.txt.\033[0m\n");
            fclose(logfptr);  // Close the log file
        }
    } 
	else 
	{
        printf("\033[0;35m\nInvalid email or password. Please try again.\033[0m\n");
    }

    // Close the registration file
    fclose(fptr);
}

// ------------------------------------------------ END CODE FOR ADMIN SIDE ------------------------------------------------

// ------------------------------------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------ START CODE FOR CLIENT SIDE ------------------------------------------------

// ------------------------------------------------ Function to confirm details [Client] ------------------------------------------------

int confirmclientregDetails() 
{
    char choice;
    printf("\033[0;35m\nAre the details correct? (y/n): \033[0m");
    scanf(" %c", &choice);  // Space before %c to consume any leftover whitespace
    return (tolower(choice) == 'y');
}

// ------------------------------------------------ Function for new registration [Client] ------------------------------------------------

int clientregdata() 
{
    FILE *fptr;
    char name[100], contact[20], address[200], email[50], password[50], repeat_password[50];

    while (1) 
	{
        // Open the file "client_reg_data.txt" in append mode ("a")
        fptr = fopen("client_reg_data.txt", "a");
        if (fptr == NULL) 
		{
            printf("\033[0;35mError opening file!\033[0m\n");
            return;
        }

        printf("\033[0;34m\n--------------- Client Registration ---------------\033[0m\n");

        // Flush leftover newline from previous input (especially after using scanf)
        getchar(); // This will consume the newline character left in the buffer

        printf("\033[0;37m\nEnter your full name: \033[0m");
		fgets(name, sizeof(name), stdin);
		removeNewline(name);  // Remove trailing newline character
		
		printf("\033[0;37m\nEnter your contact number: \033[0m");
		fgets(contact, sizeof(contact), stdin);
		removeNewline(contact);  // Remove trailing newline character
		
		printf("\033[0;37m\nEnter your address: \033[0m");
		fgets(address, sizeof(address), stdin);
		removeNewline(address);  // Remove trailing newline character
		
		printf("\033[0;37m\nEnter your email: \033[0m");
		fgets(email, sizeof(email), stdin);
		removeNewline(email);  // Remove trailing newline character

        // Enter and confirm password 
        while (1) 
		{
            printf("\nEnter your password: ");
            fgets(password, sizeof(password), stdin);
            removeNewline(password);

            printf("\nRepeat your password: ");
            fgets(repeat_password, sizeof(repeat_password), stdin);
            removeNewline(repeat_password);

            // Check if passwords match
            if (strcmp(password, repeat_password) == 0) 
			{
                break;  // Passwords match, proceed to confirmation
            } 
			else 
			{
                printf("\033[0;35m\nPasswords do not match. Please try again.\033[0m");
            }
        }

        // Show entered details for confirmation ------------------------------------------------
        printf("\033[0;34m\n--------------- Confirm Your Details ---------------\033[0m\n");
        printf("Name     : \033[0;37m%s\033[0m\n", name);
		printf("Contact  : \033[0;37m%s\033[0m\n", contact);
		printf("Address  : \033[0;37m%s\033[0m\n", address);
		printf("Email    : \033[0;37m%s\033[0m\n", email);
		printf("Password : \033[0;37m%s\033[0m\n", password);  // (In a real-world application, don't display the password)

        // Confirm details
        if (confirmclientregDetails()) 
		{
            // Save the details in the file
            fprintf(fptr, "Name: %s, Contact: %s, Address: %s, Email: %s, Password: %s\n",
                    name, contact, address, email, password);
            printf("\033[0;35m\nRegistration successful! Client registration data saved to file.\033[0m\n");
            fclose(fptr);
            break;  // Exit the registration loop
        } 
		else 
		{
            printf("\033[0;35m\nDetails are incorrect. Please try again.\n\033[0m");
            fclose(fptr);
            continue;  // Retry the registration process
        }
    }
}

// ------------------------------------------------ Function for login [Client] ------------------------------------------------
int clientlogdata() 
{
    FILE *fptr;
    FILE *logfptr;  // File pointer for logging successful logins
    char email[50], password[50];
    char stored_email[50], stored_password[50], stored_name[100], stored_contact[20], stored_address[200];
    char line[300]; // Buffer for reading a line from the file
    int login_success = 0;

    // Open the file "client_reg_data.txt" for reading
    fptr = fopen("client_reg_data.txt", "r");
    if (fptr == NULL) 
	{
        printf("\033[0;35mError opening client registration file!\033[0m\n");
        return;
    }

   	printf("\033[0;34m\n--------------- Client Login ---------------\033[0m\n");

    // Flush leftover newline from previous input
    getchar(); // Consume any leftover newline character from buffer

    // Ask for user input for login
    printf("\033[0;37m\nEnter your email: \033[0m");
    fgets(email, sizeof(email), stdin);
    removeNewline(email); // Remove trailing newline

    printf("\033[0;37m\nEnter your password: \033[0m");
    fgets(password, sizeof(password), stdin);
    removeNewline(password); // Remove trailing newline

    // Read each line from the file
    while (fgets(line, sizeof(line), fptr) != NULL) 
	{
        // Parse the stored details (Name, Contact, Address, Email, Password)
        sscanf(line, "Name: %[^,], Contact: %[^,], Address: %[^,], Email: %[^,], Password: %s", 
               stored_name, stored_contact, stored_address, stored_email, stored_password);

        // Check if the entered email and password match the stored client_reg_data
        if (strcmp(email, stored_email) == 0 && strcmp(password, stored_password) == 0) 
		{
            login_success = 1; // client_reg_data match
            break;
        }
    }

    fclose(fptr); // Close the registration data file

    if (login_success) // When client logs in successfully
	{
        printf("\033[0;35m\nLogin successful!\n\033[0m");

        // Open the "client_log_data.txt" file for appending the login details
        logfptr = fopen("client_log_data.txt", "a");
        if (logfptr == NULL) 
		{
            printf("\033[0;35mError opening client log file!\033[0m\n");
        } 
		else 
		{
            // Log the successful login details, including Name, Contact, and Address
            fprintf(logfptr, "Client Name: %s, Contact: %s, Address: %s, Email: %s logged in successfully at %s\n", stored_name, stored_contact, stored_address, email, __TIME__);
            printf("\033[0;35m\nLogin details saved to client_log_data.txt.\033[0m\n");
            fclose(logfptr);  // Close the log file
            bookticket();
        }
    }
	else
	{
        printf("\033[0;35m\nLogin failed! Invalid email or password.\033[0m\n");
    }
}

int generateBookingID(char bookingID[]) 
{
    // Generates a random Booking ID like AB1234567
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i; // Declare the loop variable outside the for loop (C89 compatible)
    
    bookingID[0] = letters[rand() % 26];
    bookingID[1] = letters[rand() % 26];
    
    for (i = 2; i < 9; i++) 
	{
        bookingID[i] = '0' + rand() % 10; // Generates digits from 0 to 9
    }
    bookingID[9] = '\0'; // Null-terminate the string
}

//---------------------------------------------- Book Ticket For Ac Coach after confirm yes or no ----------------------------------------------

int BookACCoachTicket()		
{
    // Get the current date and time
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);  // Initialize localTime

    if (confirm == 'Y' || confirm == 'y') 
    {
        // User confirms the booking
        generateBookingID(bookingID);  // Generate random booking ID

        // Display booking confirmation message
        printf("\033[1;34m\n----------------------- Your Ticket is Successfully Booked -----------------------\033[0m");
        printf("\033[1;31m\n\nTourist Name: \033[0m\033[1;37m%s\033[0m", tourist_name);
        printf("\033[1;34m\n\nTourist Age: \033[0m\033[1;37m%d\033[0m", tourist_age);
        
        // Display booking date and time
        printf("\033[1;31m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
        printf("\033[1;34m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

        // Display destination and coach
        printf("\033[1;31m\n\nDestination: \033[0m\033[1;37m%s\033[0m", destinations[destch - 1]);
        printf("\033[1;34m\n\nCoach: \033[0m\033[1;37mAC Coach\033[0m");

        // Display food preference
        printf("\n\nFood: ");
        if (clfood == 1) 
		{
            printf("\033[1;37mVeg\033[0m");
        } 
		else if (clfood == 2) 
		{
            printf("\033[1;37mNon-veg\033[0m");
        }

        // Display number of tickets and total price
        printf("\033[1;34m\n\nTotal Tickets: \033[0m\033[1;37m%d\033[0m", clticket);
        int totalTicketPrice = 350 * clticket;
        printf("\033[1;31m\n\nTotal Ticket Price: Rs.\033[0m\033[1;37m%d\033[0m/-", totalTicketPrice);

        // Display payment information
        printf("\033[1;34m\n\nPayment Amount: Rs.\033[0m\033[1;37m%d\033[0m/-", totalTicketPrice);
        printf("\033[1;31m\n\nPayment ID: \033[0m\033[1;37m%s\033[0m", bookingID);
        printf("\033[1;34m\n\nPayment Status: \033[0m\033[1;37mPaid\033[0m");

        // Thank the user and wish a happy journey
        printf("\033[1;31m\n\nThank you for booking with us!\033[0m");
        printf("\033[1;34m\n\n----------------------- Happy Journey! -----------------------\033[0m");

        // Save the booking details to a file
        FILE *file = fopen("ticketbook.txt", "a");
        if (file == NULL) 
		{
            printf("\nError opening file!\n");
            return 1;
        }

        // Write booking details to the file
        fprintf(file, "\n--------------------------------------------------------------------------------------------");
        fprintf(file, "\n\nTourist Name: %s", tourist_name);
        fprintf(file, "\n\nTourist Age: %d", tourist_age);
        fprintf(file, "\n\nTicket Booked Date: %02d-%02d-%04d", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
        fprintf(file, "\n\nTicket Booked Time: %02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        fprintf(file, "\n\nDestination: %s", destinations[destch - 1]);
        fprintf(file, "\n\nCoach: AC Coach");

        fprintf(file, "\n\nFood: ");
        if (clfood == 1) 
		{
            fprintf(file, "Veg");
        } 
		else if (clfood == 2) 
		{
            fprintf(file, "Non-veg");
        }

        fprintf(file, "\n\nTotal Tickets: %d", clticket);
        fprintf(file, "\n\nTotal Ticket Price: Rs.%d/-", totalTicketPrice);
        fprintf(file, "\n\nPayment Amount: Rs.%d/-", totalTicketPrice);
        fprintf(file, "\n\nPayment ID: %s", bookingID);
        fprintf(file, "\n\nPayment Status: Paid");
        fprintf(file, "\n\nThank you for booking with us!");
        fprintf(file, "\n\n--------------------------------------------------------------------------------------------");

        // Close the file
        fclose(file);
    } 
    else if (confirm == 'N' || confirm == 'n') 
    {
        // User cancels the booking
        printf("\n\n----------------------- Booking Canceled -----------------------");
        printf("\n\nYou have canceled the booking. Feel free to book again later.");
    } 
    else 
    {
        // Invalid input handling
        printf("\n\nInvalid input. Please enter 'Y' or 'N'.");
    }
	return 0;
}

//---------------------------------------------- Book Ticket For Non-Ac Coach after confirm yes or no ----------------------------------------------

int BookNonACCoachTicket()		
{
    // Get the current date and time
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);  // Initialize localTime

    if (confirm == 'Y' || confirm == 'y') 
    {
        // User confirms the booking
        generateBookingID(bookingID);  // Generate random booking ID

        // Display booking confirmation message
        printf("\033[1;34m\n----------------------- Your Ticket is Successfully Booked -----------------------\033[0m");
        printf("\033[1;31m\n\nTourist Name: \033[0m\033[1;37m%s\033[0m", tourist_name);
        printf("\033[1;34m\n\nTourist Age: \033[0m\033[1;37m%d\033[0m", tourist_age);
        
        // Display booking date and time
        printf("\033[1;31m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", 
               localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
        printf("\033[1;34m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", 
               localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

        // Display destination and coach
        printf("\033[1;31m\n\nDestination: \033[0m\033[1;37m%s\033[0m", destinations[destch - 1]);
        printf("\033[1;34m\n\nCoach: \033[0m\033[1;37mNon-AC Coach\033[0m");

        // Display number of tickets and total price
        printf("\033[1;34m\n\nTotal Tickets: \033[0m\033[1;37m%d\033[0m", clticket);
        int totalTicketPrice = 350 * clticket;
        printf("\033[1;31m\n\nTotal Ticket Price: Rs.\033[0m\033[1;37m%d\033[0m/-", totalTicketPrice);

        // Display payment information
        printf("\033[1;34m\n\nPayment Amount: Rs.\033[0m\033[1;37m%d\033[0m/-", totalTicketPrice);
        printf("\033[1;31m\n\nPayment ID: \033[0m\033[1;37m%s\033[0m", bookingID);
        printf("\033[1;34m\n\nPayment Status: \033[0m\033[1;37mPaid\033[0m");

        // Thank the user and wish a happy journey
        printf("\033[1;31m\n\nThank you for booking with us!\033[0m");
        printf("\033[1;34m\n\n----------------------- Happy Journey! -----------------------\033[0m");

        // Save the booking details to a file
        FILE *file = fopen("ticketbook.txt", "a");
        if (file == NULL) 
		{
            printf("\nError opening file!\n");
            return 1;
        }

        // Write booking details to the file
        fprintf(file, "\n--------------------------------------------------------------------------------------------");
        fprintf(file, "\n\nTourist Name: %s", tourist_name);
        fprintf(file, "\n\nTourist Age: %d", tourist_age);
        fprintf(file, "\n\nTicket Booked Date: %02d-%02d-%04d", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
        fprintf(file, "\n\nTicket Booked Time: %02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        fprintf(file, "\n\nDestination: %s", destinations[destch - 1]);
        fprintf(file, "\n\nCoach: Non-AC Coach");
        fprintf(file, "\n\nTotal Tickets: %d", clticket);
        fprintf(file, "\n\nTotal Ticket Price: Rs.%d/-", totalTicketPrice);
        fprintf(file, "\n\nPayment Amount: Rs.%d/-", totalTicketPrice);
        fprintf(file, "\n\nPayment ID: %s", bookingID);
        fprintf(file, "\n\nPayment Status: Paid");
        fprintf(file, "\n\nThank you for booking with us!");
        fprintf(file, "\n\n--------------------------------------------------------------------------------------------");

        // Close the file
        fclose(file);
    } 
    else if (confirm == 'N' || confirm == 'n') 
    {
        // User cancels the booking
        printf("\n\n----------------------- Booking Canceled -----------------------");
        printf("\n\nYou have canceled the booking. Feel free to book again later.");
    } 
    else 
    {
        // Invalid input handling
        printf("\n\nInvalid input. Please enter 'Y' or 'N'.");
    }
	return 0;
}

int bookticket()	//Function For Ticket Booking Process
{
	//destch = choice for destination ...
	//clcoach = choice for coach [AC & Non-AC]
	
	printf("\n\n-------------------------------- You Are Login SuccessFully --------------------------------");
	printf("\033[0;34m\n-------------------------------- Fill The Details & Book Your Ticket Easily Here --------------------------------\033[0m\n");
	
    printf("\033[1;37m\nEnter the Tourist Name: \033[0m");
	scanf("%s", tourist_name);  // No need for '&' as 'tourist_name' is an array
	
	printf("\033[1;37m\nEnter the Tourist Age: \033[0m");
	scanf("%d", &tourist_age);
    
    printf("\n--------------------------------------------------------------------------------------------------------");    
    printf("\n\t\t No	||	\tSource\t	||	\tDestination");
    printf("\n\t\t 1	||	\tSurat		||	\tVadodara");
    printf("\n\t\t 2	||	\tSurat		||	\tAhmedabad");
    printf("\n\t\t 3	||	\tSurat		||	\tRajkot");
    printf("\n\t\t 4	||	\tSurat		||	\tJamnagar");
    printf("\n\t\t 5	||	\tSurat		||	\tBhuj");
    printf("\n\t\t 6	||	\tSurat		||	\tGandhinagar");
    printf("\n\t\t 7	||	\tSurat		||	\tJunagadh");
    printf("\n\t\t 8	||	\tSurat		||	\tPorbandar");
    printf("\n\t\t 9	||	\tSurat		||	\tPalanpur");
    printf("\n\t\t10	||	\tSurat		||	\tNavsari");    
    printf("\n--------------------------------------------------------------------------------------------------------");
    
    printf("\033[1;37m\nEnter Your Choice For Select Destination: \033[0m");
    scanf("%d", &destch);
    
    switch(destch)
    {
    	case 1:		//1		Surat		Vadodara
    		{
    			printf("\n You Select The Destination Surat To Vadodara");    			
				printf("\033[1;37m\nWhich type of Coach do you want?\033[0m");
				printf("\033[1;37m\n\t1. AC\n\t2. Non-AC\033[0m");
				printf("\033[1;37m\nEnter Your Choice For Select Coach: \033[0m");
				scanf("%d", &clcoach);
				
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");
						scanf("%d", &clfood);						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); // Date in white
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); // Time in white						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Vadodara\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");
					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
												
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Vadodara\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
												
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
												
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
		case 2:		//2		Surat		Ahemedabad
    		{
    			printf("\n You Select The Destination Surat To Ahemedabad");
    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");
    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");
						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");

						scanf("%d", &clfood);
						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Ahemedabad\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");

					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 						
						
						srand(time(0)); // Seed for random number generator
												
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Ahemedabad\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
			
		case 3:		//3		Surat		Rajkot
    		{
    			printf("\n You Select The Destination Surat To Rajkot");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");
    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");
						scanf("%d", &clfood);
						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Rajkot\033[0m");
						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");
					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Rajkot\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
		
		case 4:		//4		Surat		Jamnagar
    		{
    			printf("\n You Select The Destination Surat To Jamnagar");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");
						scanf("%d", &clfood);
						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Jamnagar\033[0m");
												
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");											
						printf("\033[1;34m\n\nYour Food is: \033[0m");
					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Jamnagar\033[0m");
						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
		
		case 5:		//5		Surat		Bhuj
    		{
    			printf("\n You Select The Destination Surat To Bhuj");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");

						scanf("%d", &clfood);
						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Bhuj\033[0m");	
											
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");

					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Bhuj\033[0m");
						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
		
		case 6:		//6		Surat		Gandhinagar
    		{
    			printf("\n You Select The Destination Surat To Gandhinagar");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");
    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");

						scanf("%d", &clfood);
						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Gandhinagar\033[0m");		
										
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");

					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Gandhinagar\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
		
		case 7:		//7		Surat		Junagadh
    		{
    			printf("\n You Select The Destination Surat To Junagadh");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");
						scanf("%d", &clfood);						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Junagadh\033[0m");
												
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");

					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Junagadh\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
		
		case 8:		//8		Surat		Porbandar
    		{
    			printf("\n You Select The Destination Surat To Porbandar");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");    			
    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");
						scanf("%d", &clfood);						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Porbandar\033[0m");	
											
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");

					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Porbandar\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
			
		case 9:		//9		Surat		Palanpur
    		{
    			printf("\n You Select The Destination Surat To Palanpur");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");						
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");
						scanf("%d", &clfood);
						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Palanpur\033[0m");	
											
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");
					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 
						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Palanpur\033[0m");
						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
		
		case 10:		//10		Surat		Navsari
    		{
    			printf("\n You Select The Destination Surat To Navsari");    			
				printf("\n Which type of Coach do you want ?");
    			printf("\n\t1. AC \n\t2. Non-AC");    			
    			printf("\nEnter Your Choice For Select Coach : ");
    			scanf("%d", &clcoach);
    			
    			switch(clcoach)
    			{
    				case 1:
					{
						printf("\033[1;34m\n\nYou Select AC Coach\033[0m");
						printf("\033[1;31m\n\nWhich type of food do you want: \033[0m");						
						printf("\033[1;37m\n\n\t1. Veg \n\t2. Non-veg\033[0m");								
						printf("\033[1;37m\n\nEnter your choice for select food : \033[0m");
						scanf("%d", &clfood);						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...
					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Navsari\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");						
						printf("\033[1;34m\n\nYour Food is: \033[0m");
					    if (clfood == 1) 
						{
						    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
						}

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket();

					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");						
						printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
						scanf("%d", &clticket);
						
						printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");

					    //Confirm the details & make a payment ...					    
						printf("\033[1;34m\n\nTourist Name is: \033[0m\033[1;37m%s\033[0m", tourist_name); 						
						printf("\033[1;31m\n\nTourist Age is: \033[0m\033[1;37m%d\033[0m", tourist_age); 						
						
						srand(time(0)); // Seed for random number generator
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); 						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); 						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Vadodara\033[0m");						
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
												
						// Calculate ticket price
						tcktprice = 350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket();						
					    break;
					}
				}    			
    			break;
			}
	}
}

//------------------------------------------------ END CODE FOR CLIENT SIDE ------------------------------------------------

// ------------------------------------------------ MAIN VOID METHOD START ------------------------------------------------

void main()
{
	//chside : select admin or client side ...
	//chrl : select registration or login ...
	
    int chside,chrl;
    char aemail[100], cemail[100], apass[100], cpass[100];
    char email[100], password[100],repeat_password[100];

    printf("\033[0;31m\n----------------------- Welcome To Railway Ticket Booking Application -----------------------\033[0m\n");

    printf("\n1. Admin Side");
    printf("\n2. Client Side");

    printf("\033[0;37m\n\nEnter Your Choice: \033[0m");
    scanf("%d", &chside);

    switch(chside)
    {
        case 1:		// For Admin Side ...
        {
			printf("\033[0;34m\n\n----------------------- Welcome To Admin Side -----------------------\033[0m");
            
            //Gives the option for new registration & login ...
            
            printf("\033[1;31m\n 1. New Registration\033[0m");
			printf("\033[1;31m\n 2. Login\033[0m");
            
            printf("\033[0;37m\n\nEnter Your Choice: \033[0m");
            scanf("%d", &chrl);
            
            switch(chrl)
            {
            	case 1:  //For Admin New Registration ...
				{
				    adminregdata();  // Call the registration function for admin
             		break;
				}

				case 2: //For Admin Login ...
				{
				    adminlogdata();  // Call the login function for admin
            		break;
				}
			}
            
            break;
        }
        
        case 2:		// For Client Side ...
        {
            printf("\033[0;34m\n\n----------------------- Welcome To Client Side -----------------------\033[0m");
            
            //Gives the option for new registration & login ...
            
            printf("\033[1;31m\n 1. New Registration\033[0m");
			printf("\033[1;31m\n 2. Login\033[0m");
            
            printf("\033[0;37m\n\nEnter Your Choice: \033[0m");
            scanf("%d", &chrl);
            
            switch(chrl)
            {
            	case 1:  //For Client New Registration ...
				{
				    clientregdata();  // Call the registration function for client
            		break;
				}

				case 2: //For Client Login ...
				{
				    clientlogdata();  // Call the login function for client
            		break;
				}	
			}            
            break;
        }        
        default:
            printf("\nInvalid Choice!");
    }
}

// ------------------------------------------------ MAIN VOID METHOD END ------------------------------------------------

