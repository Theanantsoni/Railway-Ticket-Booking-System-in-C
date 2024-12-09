// In this code ... Complete the successfully insert email & password for Register & check email & password for Login for client ... 30/09/24

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

// Function to remove newline character from fgets input
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function for new registration
void clientregdata() {
    FILE *fptr;
    char email[50], password[50], repeat_password[50];

    // Open the file "client_reg_data.txt" in append mode ("a")
    fptr = fopen("client_reg_data.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- New Registration ---\n");

    // Flush leftover newline from previous input (especially after using scanf)
    getchar(); // This will consume the newline character left in the buffer

    // Enter email
    printf("\nEnter your email: ");
    fgets(email, sizeof(email), stdin);
    removeNewline(email);  // Remove trailing newline character

    // Enter and confirm password
    while (1) {
        printf("\nEnter your password: ");
        fgets(password, sizeof(password), stdin);
        removeNewline(password);

        printf("\nRepeat your password: ");
        fgets(repeat_password, sizeof(repeat_password), stdin);
        removeNewline(repeat_password);

        // Check if passwords match
        if (strcmp(password, repeat_password) == 0) {
            printf("\nRegistration successful!");

            // Write the email and password to the file
            fprintf(fptr, "Email: %s, Password: %s\n", email, password);
            printf("\n\nClient registration data saved to file.");
            break;
        } else {
            printf("\nPasswords do not match. Please try again.");
        }
    }

    // Close the file
    fclose(fptr);
}

// Function for login
void clientlogdata() {
    FILE *fptr;
    FILE *logfptr;  // File pointer for logging successful logins
    char email[50], password[50];
    char stored_email[50], stored_password[50];
    char line[100]; // Buffer for reading a line from the file
    int login_success = 0;

    // Open the file "client_reg_data.txt" for reading
    fptr = fopen("client_reg_data.txt", "r");
    if (fptr == NULL) {
        printf("Error opening client registration file!\n");
        return;
    }

    printf("\n--- Login ---\n");

    // Flush leftover newline from previous input
    getchar(); // Consume any leftover newline character from buffer

    // Ask for user input for login
    printf("\nEnter your email: ");
    fgets(email, sizeof(email), stdin);
    removeNewline(email); // Remove trailing newline

    printf("\nEnter your password: ");
    fgets(password, sizeof(password), stdin);
    removeNewline(password); // Remove trailing newline

    // Read each line from the file
    while (fgets(line, sizeof(line), fptr) != NULL) {
        // Parse the stored email and password from the line
        sscanf(line, "Email: %[^,], Password: %s", stored_email, stored_password);

        // Check if the entered email and password match the stored client_reg_data
        if (strcmp(email, stored_email) == 0 && strcmp(password, stored_password) == 0) {
            login_success = 1; // client_reg_data match
            break;
        }
    }

    if (login_success) {
        printf("\nLogin successful!\n");

        // Open the "client_log_data.txt" file for appending the login details
        logfptr = fopen("client_log_data.txt", "a");
        if (logfptr == NULL) {
            printf("Error opening client log file!\n");
        } else {
            // Log the successful login
            fprintf(logfptr, "Email: %s, Password: %s\n", email, password);
            printf("\nLogin details saved to client_log_data.txt.\n");
            fclose(logfptr);  // Close the log file
        }
    } else {
        printf("\nInvalid email or password. Please try again.\n");
    }

    // Close the registration file
    fclose(fptr);
}

void main()
{
	//chside : select admin or client side ...
	//chrl : select registration or login ...
	
    int chside,chrl;
    char aemail[100], cemail[100], apass[100], cpass[100];
    char email[100], password[100],repeat_password[100];

    printf("----------------------- Welcome To Railway Ticket Booking Application -----------------------");

    printf("\n1. Admin Side");
    printf("\n2. Client Side");

    printf("\nEnter Your Choice : ");
    scanf("%d", &chside);

    switch(chside)
    {
        case 1:
        {
            printf("\nWelcome To Admin Side ... ");
            
            printf("\nEnter Your Email Id : ");
            scanf("%s", aemail);  
            
            if(strcmp(aemail, "admin@gmail.com") == 0)
            {
                printf("\nEnter The Password : ");
                scanf("%s", apass);  
                
                if(strcmp(apass, "admin123") == 0)
                {
                    printf("\nLogin Successful!");
                }
                else
                {
                    printf("\nIncorrect Password!");
                }
            }
            else
            {
                printf("\nInvalid Email!");
            }
            break;
        }
        
        case 2:
        {
            printf("\nWelcome To Client Side ... ");
            
            //Gives the option for new registration & login ...
            
            printf("\n 1. New Registration");
            printf("\n 2. Login");
            
            printf("\nEnter Your Choice : ");
            scanf("%d", &chrl);
            
            switch(chrl)
            {
            	case 1:  //For New Registration ...
				{
				    clientregdata();  // Call the registration function
            		break;
				}

				case 2: //For Login ...
				{
				    clientlogdata();  // Call the login function
            		break;
				}
				
			}
            
            break;
        }
        default:
            printf("\nInvalid Choice!");
    }
}

