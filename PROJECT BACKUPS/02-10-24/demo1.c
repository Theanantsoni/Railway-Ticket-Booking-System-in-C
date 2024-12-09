#include<stdio.h>
#include<conio.h>
#include <time.h>

int generateBookingID(char bookingID[]) {
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


int main()
{
	//destch = choice for destination ...
	//clcoach = choice for coach [AC & Non-AC]
	//clfood = choice for food [veg & non-veg]
	
	char tourist_name[100], confirm;
	char bookingID[10]; // To store Booking ID
	srand(time(0)); // Seed for random number generator
	int tourist_age, destch, clcoach, clfood, clticket, tcktprice;
	
	printf("\n\n-------------------------------- You Are Login SuccessFully --------------------------------");
	printf("\033[0;34m\n-------------------------------- Fill The Details & Book Your Ticket Easily Here --------------------------------\033[0m\n");
	
	printf("\033[1;37m\nEnter the Tourist Name : \033[0m");
	scanf("%s", tourist_name); // Note: No need for '&' with char arrays
	
	// Print "Enter the Tourist Age :" in white
	printf("\033[1;37m\nEnter the Tourist Age : \033[0m");
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
    
	printf("\033[1;37m\nEnter Your Choice For Select Destination : \033[0m");

    scanf("%d", &destch);
    
    switch(destch)
    {
    	case 1:		//1		Surat		Vadodara
    		{
    			printf("\n\n\033[1;31mYou Select The Destination Surat To Vadodara\033[0m");
    			
    			printf("\033[31m\n\nPrice For AC Coach is : Rs.350/- Only Per Person\033[0m");
				printf("\033[31m\n\nPrice For Non-AC Coach is : Rs.250/- Only Per Person\033[0m");

    			
				// Display the question in blue
				printf("\033[1;34m\n\nWhich type of Coach do you want ?");
				printf("\n\n\t1. AC \n\t2. Non-AC\033[0m"); // Reset color after the text

    			
    			// Display the prompt in white
				printf("\033[1;37m\n\nEnter Your Choice For Select Coach : \033[0m"); // Reset color after the text
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

					    if (confirm == 'Y' || confirm == 'y') 
						{
						    // If the user confirms the booking
						    generateBookingID(bookingID); // Generate random booking ID
						
						    // Display booking details
							printf("\033[1;34m\n----------------------- Your Ticket is Successfully Booked -----------------------\033[0m");
							
							printf("\033[1;31m\n\nTourist Name is : \033[0m\033[1;37m%s\033[0m", tourist_name);
						
							// Print "Tourist Age is:" in blue
							printf("\033[1;34m\n\nTourist Age is : \033[0m\033[1;37m%d\033[0m", tourist_age);
							
							printf("\033[1;31m\n\nTicket Booked Date : \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
							
							printf("\033[1;34m\n\nTicket Booked Time : \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
							
							printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Vadodara\033[0m");
							
							printf("\033[1;34m\n\nYour Coach is : \033[0m\033[1;37mAC Coach\033[0m");
							
							printf("\n\nYour Food is : ");
						    if (clfood == 1) 
							{
							    printf("\033[1;37mVeg\033[0m");  // Print "Veg" in white
							} 
							else if (clfood == 2) 
							{
							    printf("\033[1;37mNon-veg\033[0m");  // Print "Non-veg" in white
							}

							printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
							
							// Calculate total price
							tcktprice = 350 * clticket;
					
							printf("\033[1;31m\n\nYour total ticket price is : Rs.\033[0m\033[1;37m%d\033[0m/- \033[0m", tcktprice);
	
							printf("\033[1;34m\n\nYou Have Done Your Payment : Rs.\033[0m\033[1;37m%d\033[0m/-\033[0m", tcktprice);

							printf("\033[1;31m\n\nPayment ID :          \033[0m\033[1;37m%s\033[0m", bookingID);
							
							printf("\033[1;34m\n\nPayment Status :      \033[0m\033[1;37mPaid\033[0m");

							printf("\033[1;31m\n\nThank You for Booking with Us!\033[0m");
							
							printf("\033[1;34m\n\n----------------------- Happy Journey! -----------------------\033[0m");

						
						    // Now append the details to the file (use append mode "a")
						    FILE *file = fopen("ticketbook.txt", "a");
						    if (file == NULL) {
						        printf("\nError opening file!\n");
						        return 1;
						    }
						
						    // Write booking details to the file
						    fprintf(file, "\n--------------------------------------------------------------------------------------------");
						    fprintf(file, "\n\nTourist Name is : %s", tourist_name);
						    fprintf(file, "\n\nTourist Age is : %d", tourist_age);
						    fprintf(file, "\n\nTicket Booked Date : %02d-%02d-%04d", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
						    fprintf(file, "\n\nTicket Booked Time : %02d:%02d:%02d", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
						    fprintf(file, "\n\nYour Destination is : Surat To Vadodara");
						    fprintf(file, "\n\nYour Coach is : AC Coach");
						
						    fprintf(file, "\n\nYour Food is : ");
						    if (clfood == 1) {
						        fprintf(file, "Veg");
						    } else if (clfood == 2) {
						        fprintf(file, "Non-veg");
						    }
						
						    fprintf(file, "\n\nTotal number of tickets : %d", clticket);
						    fprintf(file, "\n\nYour total ticket price is : Rs.%d/-", tcktprice);
						    fprintf(file, "\n\nYou Have Done Your Payment : Rs.%d/-", tcktprice);
						    fprintf(file, "\n\nPayment ID :          %s", bookingID);
						    fprintf(file, "\n\nPayment Status :      Paid");
						    fprintf(file, "\n\nThank You for Booking with Us!");
						    fprintf(file, "\n\n--------------------------------------------------------------------------------------------");
						
						    // Close the file
						    fclose(file);
						} 
						else if (confirm == 'N' || confirm == 'n') 
						{
						    // If the user cancels the booking
						    printf("\n\n----------------------- Booking Canceled -----------------------");
						    printf("\n\nYou have canceled the booking. Feel free to book again later.");
						} 
						else 
						{
						    // Invalid input handling
						    printf("\n\nInvalid input. Please enter 'Y' or 'N'.");
						}

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
						
						// Get the current date and time
						time_t now;
						time(&now);
						struct tm *tm_info = localtime(&now); // Use a pointer to struct tm
						
						printf("\033[1;34m\n\nTicket Booked Date: \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900); // Date in white
						
						printf("\033[1;31m\n\nTicket Booked Time: \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec); // Time in white
						
						printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Vadodara\033[0m");
						
						printf("\033[1;34m\n\nYour Coach is : \033[0m\033[1;37mNon-AC Coach\033[0m");
						
						printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
						
						// Calculate ticket price
						tcktprice = 250 * clticket;
						
						printf("\033[1;31m\n\nYour total ticket price is : \033[0m\033[1;37m%d\033[0m", tcktprice);
					
						printf("\033[1;34m\n\nYou Have To Pay : \033[0m\033[1;37m%d\033[0m", tcktprice);
						printf("\033[1;31m\n\nDo you want to proceed with booking? (Y/N): \033[0m");
						scanf(" %c", &confirm);

					    if (confirm == 'Y' || confirm == 'y') 
						{
						    // If the user confirms the booking
						    generateBookingID(bookingID); // Generate random booking ID
						
						    // Display booking details
							printf("\033[1;34m\n----------------------- Your Ticket is Successfully Booked -----------------------\033[0m");
							
							printf("\033[1;31m\n\nTourist Name is : \033[0m\033[1;37m%s\033[0m", tourist_name);
						
							// Print "Tourist Age is:" in blue
							printf("\033[1;34m\n\nTourist Age is : \033[0m\033[1;37m%d\033[0m", tourist_age);
							
							printf("\033[1;31m\n\nTicket Booked Date : \033[0m\033[1;37m%02d-%02d-%04d\033[0m", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
							
							printf("\033[1;34m\n\nTicket Booked Time : \033[0m\033[1;37m%02d:%02d:%02d\033[0m", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
							
							printf("\033[1;31m\n\nYour Destination is : \033[0m\033[1;37mSurat To Vadodara\033[0m");

							printf("\033[1;34m\n\nYour Coach is : \033[0m\033[1;37mAC Coach\033[0m");
							
							printf("\033[1;34m\n\nTotal number of tickets : \033[0m\033[1;37m%d\033[0m", clticket);
							
							// Calculate total price
							tcktprice = 250 * clticket;
					
							printf("\033[1;31m\n\nYour total ticket price is : Rs.\033[0m\033[1;37m%d\033[0m/- \033[0m", tcktprice);
	
							printf("\033[1;34m\n\nYou Have Done Your Payment : Rs.\033[0m\033[1;37m%d\033[0m/-\033[0m", tcktprice);

							printf("\033[1;31m\n\nPayment ID :          \033[0m\033[1;37m%s\033[0m", bookingID);
							
							printf("\033[1;34m\n\nPayment Status :      \033[0m\033[1;37mPaid\033[0m");

							printf("\033[1;31m\n\nThank You for Booking with Us!\033[0m");
							
							printf("\033[1;34m\n\n----------------------- Happy Journey! -----------------------\033[0m");

						
						    // Now append the details to the file (use append mode "a")
						    FILE *file = fopen("ticketbook.txt", "a");
						    if (file == NULL) {
						        printf("\nError opening file!\n");
						        return 1;
						    }
						
						    // Write booking details to the file
						    fprintf(file, "\n--------------------------------------------------------------------------------------------");
						    fprintf(file, "\n\nTourist Name is : %s", tourist_name);
						    fprintf(file, "\n\nTourist Age is : %d", tourist_age);
						    fprintf(file, "\n\nTicket Booked Date : %02d-%02d-%04d", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
						    fprintf(file, "\n\nTicket Booked Time : %02d:%02d:%02d", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
						    fprintf(file, "\n\nYour Destination is : Surat To Vadodara");
						    fprintf(file, "\n\nYour Coach is : AC Coach");
						    fprintf(file, "\n\nTotal number of tickets : %d", clticket);
						    fprintf(file, "\n\nYour total ticket price is : Rs.%d/-", tcktprice);
						    fprintf(file, "\n\nYou Have Done Your Payment : Rs.%d/-", tcktprice);
						    fprintf(file, "\n\nPayment ID :          %s", bookingID);
						    fprintf(file, "\n\nPayment Status :      Paid");
						    fprintf(file, "\n\nThank You for Booking with Us!");
						    fprintf(file, "\n\n--------------------------------------------------------------------------------------------");
						
						    // Close the file
						    fclose(file);
						} 
						else if (confirm == 'N' || confirm == 'n') 
						{
						    // If the user cancels the booking
						    printf("\n\n----------------------- Booking Canceled -----------------------");
						    printf("\n\nYou have canceled the booking. Feel free to book again later.");
						} 
						else 
						{
						    // Invalid input handling
						    printf("\n\nInvalid input. Please enter 'Y' or 'N'.");
						}

					    break;
					}
					
				}	
			}
	}
	getch();
}
