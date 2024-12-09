// In this code ... Complete the successfully insert admin & client registeration & login data ...
//All printf message are display in color text // 01/10/24

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

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
        sscanf(line, "Name: %*[^,], Contact: %*[^,], Address: %*[^,], Email: %[^,], Password: %s", 
               stored_email, stored_password);

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
            fprintf(logfptr, "Client Name: %s, Contact: %s, Address: %s, Email: %s logged in successfully at %s\n", 
                    stored_name, stored_contact, stored_address, email, __TIME__);
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

int bookticket()
{
	printf("\n\n-------------------------------- You Are Login SuccessFully --------------------------------");
	printf("\n-------------------------------- Fill The Details & Book Your Ticket Easily Here --------------------------------");
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

