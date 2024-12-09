#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to save email and password to a file
void saveCredentials(const char* email, const char* password) {
    FILE *fptr;
    
    // Open the file in append mode (creates the file if it doesn't exist)
    fptr = fopen("credentials.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Write email and password to the file
    fprintf(fptr, "Email: %s, Password: %s\n", email, password);
    
    // Close the file
    fclose(fptr);
    
    printf("Credentials saved successfully.\n");
}

int main() {
    char email[50], password[50];

    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;  // Remove trailing newline

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove trailing newline

    // Save credentials to the file
    saveCredentials(email, password);

    return 0;
}



