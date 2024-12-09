// Railway Ticket Booking System ...
//login : email : abc@gmail.com		password: 123
//Delete Ticket Booking Code Completed ... 3 DEC 2024
//Delete Admin Register Data Code Completed ... 4 DEC 2024
//Delete Admin Register Data Code Completed ... 5 DEC 2024

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

//destch = choice for destination ...
//clcoach = choice for coach [AC & Non-AC] ...
//chdata = choice for check data by admin ...

//chadminlog = yes or no for admin login after successfully registeration ...

char tourist_name[100], confirm;
char bookingID[10], chadminlog; // To store Booking ID
int tourist_age, destch, clcoach, clfood, clticket, tcktprice, chdata, day, month, year, tratime;
	
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

int removeNewline(char *str) 
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') 
	{
        str[len - 1] = '\0';
    }
}

// ------------------------------------------------ Function for exit the program ------------------------------------------------

int exitprogram() {
    printf("\nExiting the ticket booking application. Goodbye!\n");
    exit(0);
}

// ------------------------------------------------ [ START CODE FOR ADMIN SIDE ] ------------------------------------------------

// ------------------------------------------------ Function to confirm details [Admin] ------------------------------------------------

int confirmadminregDetails() 
{
    char choice;
    printf("\033[0;35m\nAre the details correct? (y/n): \033[0m");
    scanf(" %c", &choice);  // Space before %c to consume any leftover whitespace
    return (tolower(choice) == 'y');
}

// ------------------------------------------------ Function start For Check Data By Admin ------------------------------------------------

int admincheckdata()
{
    printf("\033[1;33m\n\n1.Check Admin Registration Data\033[0m");
	printf("\033[1;33m\n2.Check Admin Login Data\033[0m");
	printf("\033[1;33m\n3.Check Client Registration Data\033[0m");
	printf("\033[1;33m\n4.Check Client Login Data\033[0m");
	printf("\033[1;33m\n5.Check Ticket Booking Data\033[0m");
	
	printf("\033[1;33m\n6.Delete Admin Register Data\033[0m");
	printf("\033[1;33m\n7.Delete User Login Data\033[0m");
	printf("\033[1;33m\n8.Delete Ticket Booking Data\033[0m");
	
	printf("\033[1;33m\n9.Restart App\033[0m");
	printf("\033[1;33m\n10.Exit\033[0m");

	printf("\033[0;37m\n\nEnter your choice : \033[0m");
	scanf("%d", &chdata);
	
	switch(chdata)
	{
		case 1:
			{
				// Open the file
			    FILE *file = fopen("admin_reg_data.txt", "r");
			    
			    // Check if the file opened successfully
			    if (file == NULL) {
			        printf("\033[1;37mError: Could not open file admin_reg_data.txt\n\033[0m");
			        return;
			    }
			
			    // Buffer to hold each line of the file
			    char buffer[255];
			    
			    // Read and display the file line by line
			    printf("\033[1;37m\nAdmin Registration Data:\n");
			    while (fgets(buffer, sizeof(buffer), file)) {
			        printf("%s", buffer);
			    }
			
			    // Close the file
			    fclose(file);
			    admincheckdata();
				break;
			}
		case 2:
			{
				// Open the file
			    FILE *file = fopen("admin_log_data.txt", "r");
			    
			    // Check if the file opened successfully
			    if (file == NULL) {
			        printf("\033[0;37mError: Could not open file admin_reg_data.txt\n");
			        return;
			    }
			
			    // Buffer to hold each line of the file
			    char buffer[255];
			    
			    // Read and display the file line by line
			    printf("\033[1;37m\nAdmin Login Data:\n");
			    while (fgets(buffer, sizeof(buffer), file)) {
			        printf("%s", buffer);
			    }
			
			    // Close the file
			    fclose(file);
			    admincheckdata();
				break;
			}
		case 3:
			{
				// Open the file
			    FILE *file = fopen("client_reg_data.txt", "r");
			    
			    // Check if the file opened successfully
			    if (file == NULL) {
			        printf("\033[1;37mError: Could not open file admin_reg_data.txt\n");
			        return;
			    }
			
			    // Buffer to hold each line of the file
			    char buffer[255];
			    
			    // Read and display the file line by line
			    printf("\033[1;37m\nClient Registration Data:\n");
			    while (fgets(buffer, sizeof(buffer), file)) {
			        printf("%s", buffer);
			    }
			
			    // Close the file
			    fclose(file);
			    admincheckdata();
				break;
			}
		case 4:
			{
				// Open the file
			    FILE *file = fopen("client_log_data.txt", "r");
			    
			    // Check if the file opened successfully
			    if (file == NULL) {
			        printf("\033[1;37mError: Could not open file admin_reg_data.txt\n");
			        return;
			    }
			
			    // Buffer to hold each line of the file
			    char buffer[255];
			    
			    // Read and display the file line by line
			    printf("\033[1;37m\nClient Login Data:\n");
			    while (fgets(buffer, sizeof(buffer), file)) {
			        printf("%s", buffer);
			    }
			
			    // Close the file
			    fclose(file);
			    admincheckdata();
				break;
			}
		case 5:
			{
				// Open the file
			    FILE *file = fopen("ticketbook.txt", "r");
			    
			    // Check if the file opened successfully
			    if (file == NULL) {
			        printf("\033[1;37mError: Could not open file admin_reg_data.txt\n");
			        return;
			    }
			
			    // Buffer to hold each line of the file
			    char buffer[255];
			    
			    // Read and display the file line by line
			    printf("\033[1;37m\nTicket Booking Data:\n");
			    while (fgets(buffer, sizeof(buffer), file)) {
			        printf("%s", buffer);
			}
			
			    // Close the file
			    fclose(file);
			    admincheckdata();
				break;
			}
		case 6:
			{
			    char email[50], password[50];
				printf("\033[37m\nEnter email: \033[0m");
			    scanf("%s", email);
			    printf("\033[37m\nEnter Password: \033[0m");

			    scanf("%s", password);
			    
			    deleteAdminRegisterData(email, password);
			    return 0;
			    break;
			}
		
		case 7: 
			{
	            char email[50], password[50];
				printf("\033[37m\nEnter email: \033[0m");
	            scanf("%s", email);
			    printf("\033[37m\nEnter Password: \033[0m");
	            scanf("%s", password);
	
	            // Call delete user login data function with inputs
	            deleteuserlogindata(email, password);
	            admincheckdata(); // Loop back to admin menu
	            break;
        	}
			
		case 8: 
			{
				// Function for Delete Ticket Booking Data ...
	            char paymentID[20];
			    printf("\033[37m\nEnter the Payment ID to delete the Booking Ticket: \033[0m");
	            scanf("%s", paymentID);
	
	            // Call the delete function with the provided Payment ID
	            deleteBookedTicket(paymentID);
				admincheckdata();
	            break;
	        }
        case 9:
			{
				restartapp();
				break;
			}
		case 10:
			{
				exitprogram();
				break;
			}
		default:
            printf("\nInvalid Choice!");
	}
}

// ------------------------------------------------ Function end For Check Data By Admin ------------------------------------------------

// ------------------------------------------------ Function start for new registration [Admin] ------------------------------------------------

int adminregdata() 
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
       	printf("\033[0;34m\n------------------------ Admin Registration --------------------------\033[0m\n");
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
        	fprintf(fptr, "\nName: %s, Contact: %s, Address: %s, Email: %s, Password: %s\n", name, contact, address, email, password);
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

// ------------------------------------------------ Function end for new registration [Admin] ------------------------------------------------

// ------------------------------------------------ Function start for login [Admin] ------------------------------------------------

int adminlogdata() 
{
    FILE *fptr;
    FILE *logfptr;  // File pointer for logging successful logins
    char email[50], password[50];
    char stored_email[50], stored_password[50];
    char line[200]; // Buffer for reading a line from the file
    int login_success = 0;

    // Open the file "admin_reg_data.txt" for reading
    fptr = fopen("admin_reg_data.txt", "r");
    if (fptr == NULL) {
        printf("\033[0;35mError opening admin registration file!\033[0m\n");
        return 1; // Return an error code
    }

    printf("\033[0;34m\n--------------- Admin Login ---------------\033[0m\n");

    // Repeat until the login is successful
    while (!login_success) {
        // Ask for user input for login
        printf("\033[0;37m\nEnter your email: \033[0m");
        if (fgets(email, sizeof(email), stdin) == NULL) 
		{
            printf("\033[0;35m\nError reading email input.\033[0m\n");
            continue;  // Restart the loop if input fails
        }
        removeNewline(email); // Remove trailing newline
        
        printf("\033[0;37m\nEnter your password: \033[0m");
        if (fgets(password, sizeof(password), stdin) == NULL) 
		{
            printf("\033[0;35m\nError reading password input.\033[0m\n");
            continue;  // Restart the loop if input fails
        }
        removeNewline(password); // Remove trailing newline

        // Reset file pointer to the beginning of the file
        rewind(fptr);

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

        // If login was not successful, notify the user and ask for input again
        if (!login_success) 
		{
            printf("\033[0;35m\nInvalid email or password. Please try again.\033[0m\n");
        }
    }

    // When admin login is successful
    printf("\033[0;35m\nLogin successful!\n\033[0m");

    // Open the "admin_log_data.txt" file for appending the login details
    logfptr = fopen("admin_log_data.txt", "a");
    if (logfptr == NULL) 
	{
        printf("\033[0;35mError opening admin log file!\033[0m\n");
    } else {
        // Log the successful login without storing the password
        fprintf(logfptr, "\nEmail: %s, Password: %s, logged in successfully at %s\n", email, password, __TIME__);
        fclose(logfptr);  // Close the log file
        
        // Call admincheckdata after login success
        admincheckdata();
    }

    // Close the registration file
    fclose(fptr);

    return 0;
}

// ------------------------------------------------ Function end for login [Admin] ------------------------------------------------

// ------------------------------------------------ [ END CODE FOR ADMIN SIDE ] ------------------------------------------------

// ------------------------------------------------ [ START CODE FOR CLIENT SIDE ] ------------------------------------------------

// ------------------------------------------------ Function to confirm details [Client] ------------------------------------------------

int confirmclientregDetails() 
{
    char choice;
    printf("\033[0;35m\nAre the details correct? (y/n): \033[0m");
    scanf(" %c", &choice);  // Space before %c to consume any leftover whitespace
    return (tolower(choice) == 'y');
}

// ------------------------------------------------ Function start for new registration [Client] ------------------------------------------------

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
                printf("\033[0;35m\nPasswords do not match. Please try again.\n\033[0m");
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
            fprintf(fptr, "\nName: %s, Contact: %s, Address: %s, Email: %s, Password: %s\n",
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

// ------------------------------------------------ Function end for new registration [Client] ------------------------------------------------

// ------------------------------------------------ Function start for login [Client] ------------------------------------------------

int clientlogdata() 
{
    FILE *fptr;
    FILE *logfptr;  // File pointer for logging successful logins
    char email[50], password[50];
    char stored_email[50], stored_password[50], stored_name[100], stored_contact[20], stored_address[200];
    char line[300];  // Buffer for reading a line from the file
    int login_success = 0;

    while (!login_success)  // Loop until login is successful
    {
        // Open the file "client_reg_data.txt" for reading
        fptr = fopen("client_reg_data.txt", "r");
        if (fptr == NULL) 
        {
            printf("\033[0;35mError: Unable to open client registration file.\033[0m\n");
            return -1;  // Return -1 for error
        }

        printf("\033[0;34m\n--------------- Client Login ---------------\033[0m\n");

        // Ask for user input for login
        printf("\033[0;37m\nEnter your email: \033[0m");
        fgets(email, sizeof(email), stdin);
        removeNewline(email);  // Remove trailing newline from email

        printf("\033[0;37m\nEnter your password: \033[0m");
        fgets(password, sizeof(password), stdin);
        removeNewline(password);  // Remove trailing newline from password

        // Read each line from the file to find a matching email and password
        while (fgets(line, sizeof(line), fptr) != NULL) 
        {
            // Parse the stored details (Name, Contact, Address, Email, Password)
            sscanf(line, "Name: %[^,], Contact: %[^,], Address: %[^,], Email: %[^,], Password: %s", 
                   stored_name, stored_contact, stored_address, stored_email, stored_password);

            // Check if the entered email and password match the stored client data
            if (strcmp(email, stored_email) == 0 && strcmp(password, stored_password) == 0) 
            {
                login_success = 1;  // Client data match
                break;
            }
        }

        fclose(fptr);  // Close the registration data file

        if (!login_success)  // If login fails, ask the user to try again
        {
            printf("\033[0;35m\nLogin failed! Invalid email or password. Please try again.\033[0m\n");
        }
    }

    // Once login is successful
    printf("\033[0;35m\nLogin successful!\n\033[0m");

    // Open the "client_log_data.txt" file for appending the login details
    logfptr = fopen("client_log_data.txt", "a");
    if (logfptr == NULL) 
    {
        printf("\033[0;35mError: Unable to open client log file.\033[0m\n");
        return -1;  // Return -1 for error
    } 
    else 
    {
        // Log the successful login details, including Name, Contact, and Address
        fprintf(logfptr, "\nEmail: %s Password: %s logged in successfully at %s\n", 
                email, password, __TIME__);
        printf("\033[0;35m\nLogin details saved to client_log_data.txt.\033[0m\n");
        fclose(logfptr);  // Close the log file

        bookticket();  // Call function to book a ticket after successful login
    }

    return 1;  // Return 1 to indicate successful login
}

// ------------------------------------------------ Function end for login [Client] ------------------------------------------------

// ------------------------------------------------ Function start for generate booing or payment ID ------------------------------------------------

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

// ------------------------------------------------ Function end for generate booing or payment ID ------------------------------------------------

//---------------------------------------------- Function start Book Ticket For Ac Coach after confirm yes or no ----------------------------------------------

int BookACCoachTicket(int tcktprice)  // Add ticket price parameter
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
        printf("\033[1;37m\n----------------------- Your Ticket is Successfully Booked -----------------------\033[0m");
		printf("\033[1;32m\n\nTourist Name: \033[0m\033[1;37m%s\033[0m", tourist_name);
		printf("\033[1;32m\n\nTourist Age: \033[0m\033[1;37m%d\033[0m", tourist_age);
		
		// Display booking date and time
		printf("\033[1;32m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
		printf("\033[1;32m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
		
		// Display destination and coach
		printf("\033[1;32m\n\nDestination: \033[0m\033[1;37m%s\033[0m", destinations[destch - 1]);
		printf("\033[1;32m\n\nCoach: \033[0m\033[1;37mAC Coach\033[0m");
		
		// Display food preference
		printf("\033[1;32m\n\nFood: \033[0m\033[1;37m");
		if (clfood == 1) 
		{
		    printf("\033[1;37mVeg\033[0m");
		} 
		else if (clfood == 2) 
		{
		    printf("\033[1;37mNon-veg\033[0m");
		}
		
		// Write travelling date and time
		printf("\033[1;32m\n\nTravelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);
		
		// Display travelling time
		printf("\033[1;32m\n\nTravelling Time: \033[0m");
		if (tratime == 1) 
		{
		    printf("\033[1;37m7:00 To 12:00 AM\033[0m");
		} 
		else if (tratime == 2) 
		{
		    printf("\033[1;37m12:00 To 6:00 PM\033[0m");
		} 
		else if (tratime == 3) 
		{
		    printf("\033[1;37m6:00 To 12:00 PM\033[0m");
		} 
		else if (tratime == 4) 
		{
		    printf("\033[1;37m12:00 To 6:00 AM\033[0m");
		}
		else
		{
		    printf("\033[1;37mInvalid Number\033[0m");
		}
		
		// Display number of tickets and total price
		printf("\033[1;32m\n\nTotal Tickets: \033[0m\033[1;37m%d\033[0m", clticket);
		printf("\033[1;32m\n\nTotal Ticket Price: Rs.\033[0m\033[1;37m%d\033[0m/-", tcktprice);  // Use passed ticket price
		
		// Display payment information
		printf("\033[1;32m\n\nPayment Amount: Rs.\033[0m\033[1;37m%d\033[0m/-", tcktprice);  // Use passed ticket price
		printf("\033[1;32m\n\nPayment ID: \033[0m\033[1;37m%s\033[0m", bookingID);
		printf("\033[1;32m\n\nPayment Status: \033[0m\033[1;37mPaid\033[0m");


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
//        fprintf(file, "\n\n-------------------------------------- START --------------------------------------");
        fprintf(file, "\n\nPayment ID: %s", bookingID);
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
        else
        {
        	fprintf(file, "Invalid Number");
		}
		
		 // Write travelling date and time
	    fprintf(file, "\n\nTravelling Date: %02d-%02d-%04d", day, month, year);
	    
	    if (tratime == 1) 
	    {
	        fprintf(file, "\n\nTravelling Time: 7:00 To 12:00 AM");
	    } 
	    else if (tratime == 2) 
	    {
	        fprintf(file, "\n\nTravelling Time: 12:00 To 6:00 PM");
	    } 
	    else if (tratime == 3) 
	    {
	        fprintf(file, "\n\nTravelling Time: 6:00 To 12:00 PM");
	    } 
	    else if (tratime == 4) 
	    {
	        fprintf(file, "\n\nTravelling Time: 12:00 To 6:00 AM");
	    }
	    else
        {
        	fprintf(file, "Invalid Number");
		}
        
        fprintf(file, "\n\nTotal Tickets: %d", clticket);
        fprintf(file, "\n\nTotal Ticket Price: Rs.%d/-", tcktprice);  // Use passed ticket price
        fprintf(file, "\n\nPayment Amount: Rs.%d/-", tcktprice);  // Use passed ticket price
        
        fprintf(file, "\n\nPayment Status: Paid");
        fprintf(file, "\n\nThank you for booking with us!");
        fprintf(file, "\n\n----------------------------------------------------------------------------");

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


//---------------------------------------------- Function end Book Ticket For Ac Coach after confirm yes or no ----------------------------------------------

//---------------------------------------------- Function start for Book Ticket For Non-Ac Coach after confirm yes or no ----------------------------------------------

int BookNonACCoachTicket(int tcktprice)		
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
        printf("\033[1;37m\n----------------------- Your Ticket is Successfully Booked -----------------------\033[0m");
        printf("\033[1;32m\n\nTourist Name: \033[0m\033[1;37m%s\033[0m", tourist_name);
		printf("\033[1;32m\n\nTourist Age: \033[0m\033[1;37m%d\033[0m", tourist_age);
		
		// Display booking date and time
		printf("\033[1;32m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
		printf("\033[1;32m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
		
		// Display destination and coach
		printf("\033[1;32m\n\nDestination: \033[0m\033[1;37m%s\033[0m", destinations[destch - 1]);
		printf("\033[1;32m\n\nCoach: \033[0m\033[1;37mNon-AC Coach\033[0m");
		
		// Write travelling date and time
		printf("\033[1;32m\n\nTravelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);
		
		// Display travelling time
		printf("\033[1;32m\n\nTravelling Time: \033[0m");
		if (tratime == 1) 
		{
		    printf("\033[1;37m7:00 To 12:00 AM\033[0m");
		} 
		else if (tratime == 2) 
		{
		    printf("\033[1;37m12:00 To 6:00 PM\033[0m");
		} 
		else if (tratime == 3) 
		{
		    printf("\033[1;37m6:00 To 12:00 PM\033[0m");
		} 
		else if (tratime == 4) 
		{
		    printf("\033[1;37m12:00 To 6:00 AM\033[0m");
		}
		else
		{
		    printf("\033[1;37mInvalid Number\033[0m");
		}
		
		// Display number of tickets and total price
		printf("\033[1;32m\n\nTotal Tickets: \033[0m\033[1;37m%d\033[0m", clticket);
		printf("\033[1;32m\n\nTotal Ticket Price: Rs.\033[0m\033[1;37m%d\033[0m/-", tcktprice);  // Use passed ticket price
		
		// Display payment information
		printf("\033[1;32m\n\nPayment Amount: Rs.\033[0m\033[1;37m%d\033[0m/-", tcktprice);  // Use passed ticket price
		printf("\033[1;32m\n\nPayment ID: \033[0m\033[1;37m%s\033[0m", bookingID);
		printf("\033[1;32m\n\nPayment Status: \033[0m\033[1;37mPaid\033[0m");


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
//		fprintf(file, "\n\n-------------------------------------- START --------------------------------------");
        fprintf(file, "\n\nPayment ID: %s", bookingID);
        fprintf(file, "\n\nTourist Name: %s", tourist_name);
        fprintf(file, "\n\nTourist Age: %d", tourist_age);
        fprintf(file, "\n\nTicket Booked Date: %02d-%02d-%04d", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
        fprintf(file, "\n\nTicket Booked Time: %02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        fprintf(file, "\n\nDestination: %s", destinations[destch - 1]);
        fprintf(file, "\n\nCoach: Non-AC Coach");
		
		// Write travelling date and time
	    fprintf(file, "\n\nTravelling Date: %02d-%02d-%04d", day, month, year);
	    
	    if (tratime == 1) 
	    {
	        fprintf(file, "\n\nTravelling Time: 7:00 To 12:00 AM");
	    } 
	    else if (tratime == 2) 
	    {
	        fprintf(file, "\n\nTravelling Time: 12:00 To 6:00 PM");
	    } 
	    else if (tratime == 3) 
	    {
	        fprintf(file, "\n\nTravelling Time: 6:00 To 12:00 PM");
	    } 
	    else if (tratime == 4) 
	    {
	        fprintf(file, "\n\nTravelling Time: 12:00 To 6:00 AM");
	    }
	    else
        {
        	fprintf(file, "Invalid Number");
		}
		
        fprintf(file, "\n\nTotal Tickets: %d", clticket);
        fprintf(file, "\n\nTotal Ticket Price: Rs.%d/-", tcktprice);  // Use passed ticket price
        fprintf(file, "\n\nPayment Amount: Rs.%d/-", tcktprice);  // Use passed ticket price
        
        fprintf(file, "\n\nPayment Status: Paid");
        fprintf(file, "\n\nThank you for booking with us!");
        fprintf(file, "\n\n----------------------------------------------------------------------------");

        // Close the file
        fclose(file);
    } 
    else if (confirm == 'N' || confirm == 'n') 
    {
        // User cancels the booking
        printf("\n\n----------------------- Booking Canceled -----------------------");
        printf("\033[0;37m\n\nYou have canceled the booking. Feel free to book again later.");
    } 
    else 
    {
        // Invalid input handling
        printf("\n\n\033[1;37mInvalid input. Please enter 'Y' or 'N'.\033[0m");
    }
	return 0;
}

//---------------------------------------------- Function end for Book Ticket For Non-Ac Coach after confirm yes or no ----------------------------------------------

// ------------------------------------------------ Function Start for Delete Ticket Data ------------------------------------------------

int deleteBookedTicket(char *paymentID) {
    FILE *file = fopen("ticketbook.txt", "r");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return 1;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("\nError opening temporary file!\n");
        fclose(file);
        return 1;
    }

    char line[1024];
    int skipBlock = 0;     // Indicates if the current block should be skipped (deleted)
    int ticketFound = 0;   // Indicates if the specified ticket was found and deleted

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        if (skipBlock) {
            // Check if this is the end of the block and stop skipping
            if (strstr(line, "----------------------------------------------------------------------------") != NULL) {
                skipBlock = 0; // Stop skipping after this line
                continue;      // Do not write this END line
            }
            continue; // Skip all other lines in the block
        }

        // Check for the Payment ID in the current line
        if (strstr(line, "Payment ID:") != NULL && strstr(line, paymentID) != NULL) {
            // Mark this block for skipping (deleting)
            skipBlock = 1;
            ticketFound = 1;
            continue; // Do not write the matching Payment ID line
        }

        // Write the current line to the temp file if not skipping
        fputs(line, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    // Handle file renaming or cleanup
    if (ticketFound) {
        remove("ticketbook.txt");
        rename("temp.txt", "ticketbook.txt");
        printf("\nTicket with Payment ID %s has been successfully deleted.\n", paymentID);
    } else {
        printf("\nNo booking found with Payment ID %s.\n", paymentID);
        remove("temp.txt"); // Clean up temp file if no match is found
    }

    return 0;
}

// ------------------------------------------------ Function End for Delete ticket Data ------------------------------------------------

// ------------------------------------------------ Function Start for Delete Admin Register Data ------------------------------------------------

int deleteAdminRegisterData(char *email, char *password) {
    FILE *file = fopen("admin_reg_data.txt", "r");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return 1;
    }

    char line[1024];
    char updatedBuffer[10000] = ""; // Buffer to hold updated contents after deletion
    int recordFound = 0;
    int isPreviousLineValid = 0;   // To track if the last added line is valid

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Trim trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Skip completely empty lines
        if (strlen(line) == 0) {
            continue;
        }

        // Check if the line contains the email and password to delete
        if (strstr(line, "Email:") != NULL && strstr(line, email) != NULL && strstr(line, password) != NULL) {
            recordFound = 1; // Mark the record as found and skip this line
            continue;
        }

        // Add a blank line between valid records if needed
        if (isPreviousLineValid) {
            strcat(updatedBuffer, "\n\n"); // Add one blank line
        }

        // Append the valid line to the buffer
        strcat(updatedBuffer, line);
        isPreviousLineValid = 1; // Mark the current line as valid
    }

    fclose(file);

    if (recordFound) {
        // Reopen the file in write mode to clear its contents
        file = fopen("admin_reg_data.txt", "w");
        if (file == NULL) {
            printf("\nError reopening file for writing!\n");
            return 1;
        }

        // Write the updated buffer to the file
        fputs(updatedBuffer, file);
        fclose(file);

        printf("\nAdmin data with email '%s' has been successfully deleted.\n", email);
    } else {
        printf("\nNo admin data found with email '%s' and the provided password.\n", email);
    }

    return 0;
}

// ------------------------------------------------ Function End for Delete Admin Register Data ------------------------------------------------

// ------------------------------------------------ Function Start for Delete User Login Data ------------------------------------------------

int deleteuserlogindata(char *email, char *password) {
    FILE *file = fopen("client_log_data.txt", "r");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    char line[1024];
    char updatedBuffer[10000] = ""; // Buffer to store updated data
    int recordFound = 0;
    int isPreviousLineValid = 0;   // To track if the last added line is valid

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Trim trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Skip empty lines
        if (strlen(line) == 0) {
            continue;
        }

        // Check if the line matches the email and password
        if (strstr(line, email) != NULL && strstr(line, password) != NULL) {
            recordFound = 1; // Mark the record as found and skip this line
            continue;
        }

        // Add a blank line between valid records if needed
        if (isPreviousLineValid) {
            strcat(updatedBuffer, "\n\n");
        }

        // Append the current valid line to the buffer
        strcat(updatedBuffer, line);
        isPreviousLineValid = 1; // Mark the current line as valid
    }

    fclose(file);

    // Write back updated data to the file
    if (recordFound) {
        file = fopen("client_log_data.txt", "w");
        if (file == NULL) {
            printf("\nError reopening file for writing!\n");
            return;
        }

        // Write the updated buffer to the file
        fputs(updatedBuffer, file);
        fclose(file);

        printf("\nUser login data with email '%s' has been successfully deleted.\n", email);
    } else {
        printf("\nNo user login data found with email '%s' and the provided password.\n", email);
    }
}

// ------------------------------------------------ Function End for Delete User Login Data ------------------------------------------------

//---------------------------------------------- Main Fucntion start for book ticket ----------------------------------------------

int bookticket()	// Function For Ticket Booking Process
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
						              
					    printf("\033[1;37m\n\nHow many tickets do you want : \033[0m");
					    scanf("%d", &clticket);
					    
					    printf("\033[1;37m\n\n--------------------------- Check Your Details ---------------------------\033[0m");
					
					    // Confirm the details & make a payment ...                       
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
					    printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mAC Coach\033[0m");                        
					    printf("\033[1;34m\n\nYour Food is: \033[0m");
					    if (clfood == 1) 
					    {
					        printf("\033[1;37mVeg\033[0m");  
					    } 
					    else if (clfood == 2) 
					    {
					        printf("\033[1;37mNon-veg\033[0m");  
					    }
					    
					    printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					
					    printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						       
					    // Calculate ticket price
					    tcktprice = 850 * clticket;
					
					    printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					    
					    printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
					    printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
					    scanf(" %c", &confirm);
					    
					    BookACCoachTicket(tcktprice);  // Pass ticket price directly
					    break;
					}

					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");		
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
										
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
												
						// Calculate ticket price
						tcktprice = 450 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
												
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
						
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 2350 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");		
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
										
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 2150 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
						
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 2150 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");			
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
									
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1750 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
						
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1750 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");	
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
											
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1450 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
						
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1350 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");			
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
									
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 950 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
						
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 950 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");	
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
											
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 650 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
											
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
						    printf("\033[1;37mVeg\033[0m"); 
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 2250 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						// Print "You Have To Pay:" in blue
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");		
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
										
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1750 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
									
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m"); 
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1850 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");		
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
										
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1250 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
						
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 850 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);
					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");		
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
										
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
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 550 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
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
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
									
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
						    printf("\033[1;37mVeg\033[0m");  
						} 
						else if (clfood == 2) 
						{
						    printf("\033[1;37mNon-veg\033[0m");  
						}
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }

						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 1250 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookACCoachTicket(tcktprice);

					    break;
					}
					
					case 2:
					{
						printf("\033[1;34m\n\nYou Select Non-AC Coach\033[0m");		
						
						printf("\033[1;37m\n\nEnter Travelling Date (DD-MM-YYYY): \033[0m");
    					scanf("%d-%d-%d", &day, &month, &year);
					    
					    printf("\033[1;37m\n\nSelect Travelling Time : \033[0m");
					    printf("\n1. 7:00 To 12:00 AM");
					    printf("\n2. 12:00 To 6:00 PM");
					    printf("\n3. 6:00 To 12:00 PM");
					    printf("\n4. 12:00 To 6:00 AM");
					    printf("\033[1;37m\n\nEnter Travelling Time Number : \033[0m");
					    scanf("%d", &tratime);
										
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
						printf("\033[1;31m\n\nYour Coach is: \033[0m\033[1;37mNon-AC Coach\033[0m");
						
						printf("\033[1;31m\n\nYour Travelling Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", day, month, year);                     
						 					
						printf("\033[1;34m\n\nYour Travelling Time is: \033[0m");
					    if (tratime == 1) 
					    {
					        printf("\033[1;37m 7:00 To 12:00 AM\033[0m");  
					    } 
					    else if (tratime == 2) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 PM\033[0m");  
					    }
					    else if (tratime == 3) 
					    {
					        printf("\033[1;37m 6:00 To 12:00 PM\033[0m");  
					    } 
					    else if(tratime == 4) 
					    {
					        printf("\033[1;37m 12:00 To 6:00 AM\033[0m");  
					    }
					    
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
												
						// Calculate ticket price
						tcktprice = 950 * clticket;						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);
						
						BookNonACCoachTicket(tcktprice);						
					    break;
					}
				}    			
    			break;
			}
	}
}

//---------------------------------------------- Main Fucntion end for book ticket ----------------------------------------------

//------------------------------------------------ [ END CODE FOR CLIENT SIDE ] ------------------------------------------------

// ------------------------------------------------ RESTART APP CODE START ------------------------------------------------

int restartapp()
{
	//chside : select admin or client side ...
	//chrl : select registration or login ...
	
    int chside,chrl, secpin;
    char aemail[100], cemail[100], apass[100], cpass[100];
    char email[100], password[100],repeat_password[100];

    printf("\033[0;31m\n----------------------- Welcome To Railway Ticket Booking Application -----------------------\033[0m\n");

    printf("\n1. Admin Side");
    printf("\n2. Client Side");
    printf("\n3. Restart App");
	printf("\n4. Exit");

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
			printf("\033[1;31m\n 3. Restart App\033[0m");
			printf("\033[1;31m\n 4. Exit\033[0m");
            
            printf("\033[0;37m\n\nEnter Your Choice: \033[0m");
            scanf("%d", &chrl);
            
            switch(chrl)
            {
            	case 1:  //For Admin New Registration ...
				{
					printf("\033[0;37m\nEnter Admin Security PIN for New Register : \033[0m");
				    scanf("%d", &secpin);
				    
				    if(secpin == 6317)
				    {
				    	adminregdata();  // Call the registration function for admin
				    	
					    printf("\033[0;37m\n\nEnter for login? (Y/y for Yes, N/n for No): \033[0m");
						scanf(" %c", &chadminlog);  // Read a single character input (Y, y, N, n)
						getchar();  // Consume the newline character left over after scanf()
						
						// Check if user entered 'Y' or 'y'
						if (chadminlog == 'Y' || chadminlog == 'y') 
						{
						    adminlogdata();   // Run the login function if 'Y' or 'y'
						} 
						else if (chadminlog == 'N' || chadminlog == 'n') 
						{
						    printf("You chose not to log in.\n");
						} 
						else 
						{
						    printf("Invalid input. Please enter Y/y for Yes or N/n for No.\n");
						}
					}
					else
					{
						printf("\033[0;31mInvalid Security PIN\033[0m\n");
						restartapp();
					}
             		break;
				}

				case 2:  // For Admin Login ...
				{
				    // Clear input buffer to remove any leftover newlines
				    getchar();  // Consume the newline left by the previous input
				
				    adminlogdata();  // Call the login function for admin
				    break;
				}
				case 3:
				{
					restartapp();
					break;
				}
				case 4:
				{
					exitprogram();
					break;
				}
				default:
            		printf("\nInvalid Choice!");
			}            
            break;
        }
        
        case 2:		// For Client Side ...
        {
            printf("\033[0;34m\n\n----------------------- Welcome To Client Side -----------------------\033[0m");
            
            //Gives the option for new registration & login ...
            
            printf("\033[1;31m\n 1. New Registration\033[0m");
			printf("\033[1;31m\n 2. Login\033[0m");
			printf("\033[1;31m\n 3. Restart App\033[0m");
			printf("\033[1;31m\n 4. Exit\033[0m");
            
            printf("\033[0;37m\n\nEnter Your Choice: \033[0m");
            scanf("%d", &chrl);
            
            switch(chrl)
            {
            	case 1:  // For Client New Registration
			    {
			        clientregdata();  // Call the registration function for client
			        
			        // Ask the user if they want to log in after registration
			        printf("\033[0;37m\n\nEnter for login? (Y/y for Yes, N/n for No): \033[0m");
			        scanf(" %c", &chadminlog);  // Read a single character input (Y, y, N, n)
			        getchar();  // Consume the newline character left over after scanf()
			
			        // Check if the user entered 'Y' or 'y'
			        if (chadminlog == 'Y' || chadminlog == 'y') 
			        {
			            clientlogdata();   // Run the login function if 'Y' or 'y'
			        } 
			        else if (chadminlog == 'N' || chadminlog == 'n') 
			        {
			            printf("\033[1;37mYou chose not to log in.\n\033[0m");
			        } 
			        else 
			        {
			            printf("Invalid input. Please enter Y/y for Yes or N/n for No.\n");
			        }
			        break;
			    }
			
			    case 2:  // For Client Login
			    {
			        getchar();  // This will clear the buffer and remove any leftover newline characters.
			        clientlogdata();  // Call the login function for client
			        break;
			    }
			    case 3:
				{
					restartapp();
					break;
				}
				case 4:
				{
					exitprogram();
					break;
				}
				default:
            		printf("\nInvalid Choice!");
			}            
            break;
        } 
		case 3:
		{
			restartapp();
			break;
		}
		case 4:
		{
			exitprogram();
			break;
		}
        default:
            printf("\nInvalid Choice!");
    }
}
// ------------------------------------------------ RESTART APP CODE END ------------------------------------------------

// ------------------------------------------------ [ MAIN VOID METHOD START ] ------------------------------------------------

void main()
{
	//chside : select admin or client side ...
	//chrl : select registration or login ...
	
    int chside,chrl, secpin;
    char aemail[100], cemail[100], apass[100], cpass[100];
    char email[100], password[100],repeat_password[100];

    printf("\033[0;31m\n----------------------- Welcome To Railway Ticket Booking Application -----------------------\033[0m\n");

    printf("\n1. Admin Side");
    printf("\n2. Client Side");
    printf("\n3. Restart App");
	printf("\n4. Exit");

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
			printf("\033[1;31m\n 3. Restart App\033[0m");
			printf("\033[1;31m\n 4. Exit\033[0m");
            
            printf("\033[0;37m\n\nEnter Your Choice: \033[0m");
            scanf("%d", &chrl);
            
            switch(chrl)
            {
            	case 1:  //For Admin New Registration ...
				{
					printf("\033[0;37m\nEnter Admin Security PIN for New Register : \033[0m");
				    scanf("%d", &secpin);
				    
				    if(secpin == 6317)
				    {
				    	adminregdata();  // Call the registration function for admin
				    	
					    printf("\033[0;37m\n\nEnter for login? (Y/y for Yes, N/n for No): \033[0m");
						scanf(" %c", &chadminlog);  // Read a single character input (Y, y, N, n)
						getchar();  // Consume the newline character left over after scanf()
						
						// Check if user entered 'Y' or 'y'
						if (chadminlog == 'Y' || chadminlog == 'y') 
						{
						    adminlogdata();   // Run the login function if 'Y' or 'y'
						} 
						else if (chadminlog == 'N' || chadminlog == 'n') 
						{
						    printf("You chose not to log in.\n");
						} 
						else 
						{
						    printf("Invalid input. Please enter Y/y for Yes or N/n for No.\n");
						}
					}
					else
					{
						printf("\033[0;31mInvalid Security PIN\033[0m\n");
						restartapp();
					}
             		break;
				}

				case 2:  // For Admin Login ...
				{
				    // Clear input buffer to remove any leftover newlines
				    getchar();  // Consume the newline left by the previous input
				
				    adminlogdata();  // Call the login function for admin
				    break;
				}
				case 3:
				{
					restartapp();
					break;
				}
				case 4:
				{
					exitprogram();
					break;
				}
				default:
            		printf("\nInvalid Choice!");
			}            
            break;
        }
        
        case 2:		// For Client Side ...
        {
            printf("\033[0;34m\n\n----------------------- Welcome To Client Side -----------------------\033[0m");
            
            //Gives the option for new registration & login ...
            
            printf("\033[1;31m\n 1. New Registration\033[0m");
			printf("\033[1;31m\n 2. Login\033[0m");
			printf("\033[1;31m\n 3. Restart App\033[0m");
			printf("\033[1;31m\n 4. Exit\033[0m");
            
            printf("\033[0;37m\n\nEnter Your Choice: \033[0m");
            scanf("%d", &chrl);
            
            switch(chrl)
            {
            	case 1:  // For Client New Registration
			    {
			        clientregdata();  // Call the registration function for client
			        
			        // Ask the user if they want to log in after registration
			        printf("\033[0;37m\n\nEnter for login? (Y/y for Yes, N/n for No): \033[0m");
			        scanf(" %c", &chadminlog);  // Read a single character input (Y, y, N, n)
			        getchar();  // Consume the newline character left over after scanf()
			
			        // Check if the user entered 'Y' or 'y'
			        if (chadminlog == 'Y' || chadminlog == 'y') 
			        {
			            clientlogdata();   // Run the login function if 'Y' or 'y'
			        } 
			        else if (chadminlog == 'N' || chadminlog == 'n') 
			        {
			            printf("\033[1;37mYou chose not to log in.\n\033[0m");
			        } 
			        else 
			        {
			            printf("Invalid input. Please enter Y/y for Yes or N/n for No.\n");
			        }
			        break;
			    }
			
			    case 2:  // For Client Login
			    {
			        getchar();  // This will clear the buffer and remove any leftover newline characters.
			        clientlogdata();  // Call the login function for client
			        break;
			    }
			    case 3:
				{
					restartapp();
					break;
				}
				case 4:
				{
					exitprogram();
					break;
				}
				default:
            		printf("\nInvalid Choice!");
			}            
            break;
        } 
		case 3:
		{
			restartapp();
			break;
		}
		case 4:
		{
			exitprogram();
			break;
		}
        default:
            printf("\nInvalid Choice!");
    }
}

// ------------------------------------------------ [ MAIN VOID METHOD END ] ------------------------------------------------

