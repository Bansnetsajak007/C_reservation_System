#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of passengers
#define MAX_PASSENGERS 50

//defining global variables
//can be accessed from any where 
char plane_1[] = "XYZ airline 009-A2";
char plane_2[] = "XYZ airline 009-A3";
char plane_3[] = "XYZ airline 79-B2";
char plane_4[] = "XYZ airline 1249-45-C5";

int option,seat_no;
char seat_class[20];

// Define the passenger structure
typedef struct passenger {
  char name[50];
  int age;
  char gender;
  char from[50];
  char to[50];
  char flight_no[10];
} Passenger;


char* flight_name(int user_option) {
    return (user_option == 1) ? plane_1 :
           (user_option == 2) ? plane_2 :
           (user_option == 3) ? plane_3 :
           (user_option == 4) ? plane_4 :
           NULL;
}

int seat_details(int seat_no) {
    return seat_no;
}

char* s_class(char* s_class){
	return s_class;
}




void flight_details(){
	char class1[] = "business";
	
	printf("Which flight you wnat to choose: \n");
//	printf("1. XYZ airline 009-A2\n");
//	printf("2. XYZ airline 009-A3\n");
//	printf("3. XYZ airline 79-B2\n");
//	printf("4. XYZ airline 1249-45-C5\n");

	printf("1) %s\n", plane_1);
	printf("2) %s\n", plane_2);
	printf("3) %s\n", plane_3);
	printf("4) %s\n", plane_4);
	
	printf("Enter your option: ");
	scanf("%d", &option);
	
	printf("Enter class: ");
//	gets(seat_class);
	scanf("%s", seat_class);	
	
	switch (option){
		case 1:
			printf("Booking for flight XYZ airline 009-A2 \n");

			if(strcmp(seat_class, class1) == 0){
				printf("Enter seat number of business class: ");
				scanf("%d", &seat_no);
				break;
			}
			
			else{
			
				printf("Enter seat number of economy class: ");
				scanf("%d", &seat_no);		
				break;
			}
				
		case 2:
			printf("Booking for flight XYZ airline 009-A3 \n");

			if(strcmp(seat_class, class1) == 0){
				printf("Enter seat number of business class: ");
				scanf("%d", &seat_no);
				break;
			}
			
			else{
			
				printf("Enter seat number of economy class: ");
				scanf("%d", &seat_no);		
				break;
			}	
//				
		case 3:
			printf("Booking for flight XYZ airline 79-B2 \n");

			if(strcmp(seat_class, class1) == 0){
				printf("Enter seat number of business class: ");
				scanf("%d", &seat_no);
				break;
			}
			
			else{
			
				printf("Enter seat number of economy class: ");
				scanf("%d", &seat_no);		
				break;
			}	
				
		case 4:
			printf("Booking for flight XYZ airline 1249-45-C5 \n");

			if(strcmp(seat_class, class1) == 0){
				printf("Enter seat number of business class: ");
				scanf("%d", &seat_no);
				break;
			}
			
			else{
			
				printf("Enter seat number of economy class: ");
				scanf("%d", &seat_no);		
				break;
			}
							
	}
}





// Function to reserve a ticket
void reserve_ticket(Passenger *passengers, int *num_passengers) {
  Passenger p;  //structure variable

  // Get the passenger details
  printf("\nEnter Passenger Details:\n");
  printf("Name: ");
  scanf("%s", p.name);
  printf("Age: ");
  scanf("%d", &p.age);
  printf("Gender (M/F): ");
  scanf(" %c", &p.gender);
  printf("From: ");
  scanf("%s", p.from);
  printf("To: ");
  scanf("%s", p.to);

  flight_details();

  // Add the passenger to the list
  passengers[*num_passengers] = p;
  *num_passengers += 1;

  printf("\nTicket Reserved Successfully!\n");
}

// Function to display the ticket
void display_ticket(Passenger *passengers, int num_passengers) {
  int i;
  char name[50];

  // Get the passenger name
  printf("\nEnter Passenger Name: ");
  scanf("%s", name);

  // Search for the passenger and display the ticket
  for (i = 0; i < num_passengers; i++) {
    if (strcmp(passengers[i].name, name) == 0) {
      printf("\nName: %s\n", passengers[i].name);
      printf("Age: %d\n", passengers[i].age);
      printf("Gender: %c\n", passengers[i].gender);
      printf("From: %s\n", passengers[i].from);
      printf("To: %s\n", passengers[i].to);
      printf("Flight details are..\n");
      printf("Flight Name: %s\n", flight_name(option));
      printf("seat number %d of %s class", seat_details(seat_no),s_class(seat_class));
      
      return;
    }
  }

  // If the passenger is not found
  printf("\nPassenger Not Found!\n");
}

//important function to be implemented
 void cancel_reservation(Passenger *passengers, int *num_passengers) {
   char name[50];
   int i, j;

   // Get the passenger name
   printf("\nEnter Passenger Name: ");
   scanf("%s", name);

   // Search for the passenger
  for (i = 0; i < *num_passengers; i++) {
   if(strcmp(passengers[i].name, name) == 0){
     if (strcmp(passengers[i].name, name) == 0) {
       printf("\nReservation Cancelled for %s\n", passengers[i].name);

        //Remove the passenger from the list
       for (j = i; j < *num_passengers - 1; j++) {
         passengers[j] = passengers[j+1];
       }
       *num_passengers -= 1;
     }
   }
  
   
  
	else{
	   // If the passenger is not found
	   printf("\nPassenger Not Found!\n");	
	}
	
}
}
 

int main() {
  Passenger passengers[MAX_PASSENGERS]; // array of structure
  int num_passengers = 0;
  int choice;

  // Display the reservation system menu
  while (1) {
    printf("\nAirline Ticket Reservation System\n");
    printf("1. Reserve a Ticket\n");
    printf("2. Display Ticket\n");
    printf("3. Cancel Ticket\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      reserve_ticket(passengers, &num_passengers);
      break;
    case 2:
      display_ticket(passengers, num_passengers);
      break;
    case 3: 
      cancel_reservation(passengers, &num_passengers);
      break;
    case 4:
      printf("Thankyou ");
    	exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

