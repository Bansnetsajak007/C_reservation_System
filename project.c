//total time wasted 34 hours

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSENGERS 50
#define MAX_BUFFER_SIZE 100  //for Password auth
//Defining maximum length of string inputs
#define MAX_STRING_LENGTH 50
char name_[MAX_STRING_LENGTH];
char type_ticket;
char log_in;

// Defining  maximum length for flight names
#define MAX_FLIGHT_NAME_LENGTH 20

// Defining the maximum length for seat class
#define MAX_SEAT_CLASS_LENGTH 20

// structure which holds details of passenger
typedef struct passenger {
  char name[MAX_STRING_LENGTH];
  int age;
  char gender;
  char from[MAX_STRING_LENGTH];
  char to[MAX_STRING_LENGTH];
  char flight_no[MAX_STRING_LENGTH];
  int seat_no;
  char seat_class[MAX_SEAT_CLASS_LENGTH];
  char departure_date[MAX_STRING_LENGTH];
  char return_date[MAX_STRING_LENGTH];

} Passenger;

//structure holds flight details
typedef struct flight {
  char name[MAX_FLIGHT_NAME_LENGTH];
} Flight;

//Array of string (All flight names)
Flight flights[] = {{"Flight-1"},
                    {"Flight-2"},
                    {"Flight-3"},
                    {"Flight-4"}};

int num_flights = sizeof(flights) / sizeof(flights[0]);  //returns total size of flights[] array

void display_flights() {
  printf("Available flights:\n");
  for (int i = 0; i < num_flights; i++) {
    printf("%d) %s\n", i + 1, flights[i].name);
  }
}

int get_flight_index(int option) { return option - 1; }

int get_seat_number() {
  int seat_no;
  printf("Enter seat number: ");
  scanf("%d", &seat_no);
  return seat_no;
}

void reserve_ticket(Passenger *passengers, int *num_passengers) {
    FILE *fp;
    Passenger p;

    printf("\nEnter Passenger Details:\n");
    printf("Name: ");
    scanf("%s", p.name);
    strcpy(name_, p.name);
    strcat(name_, ".txt");
    fp = fopen(name_, "a");
    printf("Age: ");
    scanf("%d", &p.age);
    printf("Gender (M/F): ");
    scanf(" %c", &p.gender);
    printf("From: ");
    scanf("%s", p.from);
    printf("To: ");
    scanf("%s", p.to);
    printf("Do you want a return Ticket [y/n]: ");
    scanf(" %c", &type_ticket);
    getchar();  // Consume the newline character

    if (type_ticket == 'y') {
        printf("Enter your departure date: ");
        fgets(p.departure_date, MAX_STRING_LENGTH, stdin);

        printf("Enter your return date: ");
        fgets(p.return_date, MAX_STRING_LENGTH, stdin);
    } else {
        printf("Enter your departure date: ");
        fgets(p.departure_date, MAX_STRING_LENGTH, stdin);
    }

    display_flights();
    printf("Enter your option: ");
    int option;
    scanf("%d", &option);

    if (option < 1 || option > num_flights) {
        printf("Invalid flight option!\n");
        option = 0;
        printf("Enter flight options again: ");
        scanf("%d", &option);
    }

    strcpy(p.flight_no, flights[get_flight_index(option)].name);

    printf("Enter seat class: ");
    scanf("%s", p.seat_class);

    if (strcmp(p.seat_class, "business") == 0) {
        p.seat_no = get_seat_number();
    } else {
        p.seat_no = get_seat_number();
    }

    if (*num_passengers >= MAX_PASSENGERS) {
        printf("Maximum number of passengers reached!\n");
        return;
    }

    passengers[*num_passengers] = p;
    *num_passengers += 1;

    // Code for writing ticket details in file
    fprintf(fp, "\n====================================================================");
    fprintf(fp, "\n\t\t\tTicket Details of %s", p.name);
    fprintf(fp, "\n====================================================================");
    fprintf(fp, "\nName: %-20sAge: %-20dGender: %c", p.name, p.age, p.gender);
    fprintf(fp, "\nFrom: %-20sTo: %-20sFlight Number: %s", p.from, p.to, p.flight_no);
    fprintf(fp, "\nClass: %-20sSeat Number: %-15€dDeparture Date: %s", p.seat_class, p.seat_no,p.departure_date);

    if (type_ticket == 'y') {
    fprintf(fp, "Return Date: %s",p.return_date);
    }

    fprintf(fp, "\n====================================================================\n");
    fclose(fp);

    printf("\nTicket Reserved Successfully!\n");
}


void display_ticket(Passenger *passengers, int num_passengers) {
    char name[MAX_STRING_LENGTH];
    printf("\nEnter Passenger Name: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_passengers; i++) {
        if (strcmp(passengers[i].name, name) == 0) {
            found = 1;
            printf("\n==========================================================================");
            printf("\n\t\t\tTicket Details of %s", passengers[i].name);
            printf("\n==========================================================================");
            printf("\nName: %-20sAge: %-20dGender: %c", passengers[i].name, passengers[i].age, passengers[i].gender);
            printf("\nFrom: %-20sTo: %-20sFlight Number: %s", passengers[i].from, passengers[i].to, passengers[i].flight_no);
            printf("\nClass: %-20sSeat Number: %-15dDeparture Date: %s", passengers[i].seat_class, passengers[i].seat_no,passengers[i].departure_date);

          if (type_ticket == 'y') {
            printf("Return Date: %s",passengers[i].return_date);
            printf("\n==========================================================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nPassenger Not Found!\n");
    }
}
}


void cancel_reservation(Passenger *passengers, int *num_passengers) {
  char *file_name;
  char name[MAX_STRING_LENGTH];

  printf("\nEnter Passenger Name: ");
  scanf("%s", name);

  int found = 0; // Firstly indicating found as 0 (FALSE)
  for (int i = 0; i < *num_passengers; i++) {
    if (strcmp(passengers[i].name, name) == 0) {
      found = 1; // if passenger is found indicating 1 (TRUE)

      file_name = strcat(name, ".txt");
      if (remove(file_name) == 0) {
        printf("\nReservation Cancelled for %s\n", passengers[i].name);
      }

      for (int j = i; j < *num_passengers - 1; j++) {
        passengers[j] = passengers[j + 1];
      }
      *num_passengers -= 1;
      break;
    }
  }

  if (!found) {
    printf("\nPassenger Not Found!\n");
  }
}

int main() {
  
  Passenger passengers[MAX_PASSENGERS];
  int num_passengers = 0;
  int i;
  int progress;
  int total = 20; // Total number of progress bar units
  int firstIteration = 0;  //flag that checks how many iteration has occured
  int choice,option;
  char UserName[MAX_STRING_LENGTH],Password[MAX_STRING_LENGTH];
  char buffer[MAX_BUFFER_SIZE];
  char username[MAX_BUFFER_SIZE];
  char Password_[MAX_BUFFER_SIZE];

    printf("\n\t\t\t_______________________________________");
    printf("\n");
    printf("\n\t\t\t\t    WELCOME ");
    printf("\n\t\t\t\t      TO ");
    printf("\n\t\t\t  AIRLINE TICKET RESERVATION SYSTEM  ");
    printf("\n\t\t\t_______________________________________");
    printf("\n\n");


  printf("Enter Your UserName:");
  fgets(UserName,MAX_STRING_LENGTH,stdin);

  //logic to take password by the user safely
  printf("Enter Your Password: ");
  for (i = 0; i < MAX_STRING_LENGTH; i++) {
        Password[i] = getch();
        if (Password[i] == '\r') // Stop taking input if Enter key is pressed
            break;
        printf("*");
    }
    Password[i] = '\0'; // Add null terminator at the end of the Password string


    printf("\n\n");


//loading animation
    printf("Loading: [");
    fflush(stdout);

    for (i = 0; i <= total; i++) {
        progress = i * 100 / total;

        // Display progress bar
        printf("\rLoading: [");
        int j;
        for (j = 0; j < i; j++) {
            printf("=");
        }
        printf(">");
        for (j = i + 1; j <= total; j++) {
            printf(" ");
        }
        printf("] %d%%", progress);
        fflush(stdout);

        struct timespec sleepTime;
            sleepTime.tv_sec = 0;
            sleepTime.tv_nsec = 100000000L; // 100 milliseconds
            nanosleep(&sleepTime, NULL);
    }
        printf("\n");




  while (1) {
    if(firstIteration){
    printf("\n\nWelcome To Our Reservation service  %s\n\n", UserName);
    firstIteration = 0 ; //setting the flag to 0 indicating false

    }

     printf("\n\t\t What Would You Like To Do?");
     printf("\n\t\t________________________________________\n\n");
     printf("\n\t\t 1. Reserve Ticket");
     printf("\n\t\t 2. Display Ticket");
     printf("\n\t\t 3. Cancel Ticket");
     printf("\n\t\t 4. Exit\n");
     printf("\n\t\t________________________________________\n\n");
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
      printf("\nThank you for Choosing Us.\n\n\n");
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
  
  return 0;


}