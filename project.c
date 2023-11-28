// total time wasted 34 hours
//final ready

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_PASSENGERS 50
#define MAX_BUFFER_SIZE 100  // for Password auth
#define MAX_STRING_LENGTH 50 // Defining maximum length of string inputs
char name_[MAX_STRING_LENGTH];
char type_ticket;
char log_in;
char bookedBy[MAX_USERNAME_LENGTH];

// Defining  maximum length for flight names
#define MAX_FLIGHT_NAME_LENGTH 20

// Defining the maximum length for seat class
#define MAX_SEAT_CLASS_LENGTH 20

// structure of login and signup authentication
struct User
{
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};

typedef struct User User;

User users[MAX_USERS];
int userCount = 0;

// structure which holds details of passenger
typedef struct passenger
{
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

// structure holds flight details
typedef struct flight
{
  char name[MAX_FLIGHT_NAME_LENGTH];
} Flight;

// Array of string (All flight names)
Flight flights[] = {{"Flight-1"},
                    {"Flight-2"},
                    {"Flight-3"},
                    {"Flight-4"}};

int num_flights = sizeof(flights) / sizeof(flights[0]); // returns total size of flights[] array

void display_flights()
{
  printf("Available flights:\n");
  for (int i = 0; i < num_flights; i++)
  {
    printf("%d) %s\n", i + 1, flights[i].name);
  }
}

int get_flight_index(int option) { return option - 1; }

int get_seat_number()
{
  int seat_no;
  printf("Enter seat number: ");
  scanf("%d", &seat_no);
  return seat_no;
}


// important
void loadUserDataFromFile() {
  FILE *file = fopen("userdata.txt", "r");
  if (file == NULL)
  {
    return; // user data doesnot exist
  }

  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  while (fscanf(file, "%s %s", username, password) != EOF)
  {
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
  }

  fclose(file);
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
  getchar(); // Consume the newline character

  if (type_ticket == 'y')
  {
    printf("Enter your departure date: ");
    fgets(p.departure_date, MAX_STRING_LENGTH, stdin);

    printf("Enter your return date: ");
    fgets(p.return_date, MAX_STRING_LENGTH, stdin);
  }
  else
  {
    printf("Enter your departure date: ");
    fgets(p.departure_date, MAX_STRING_LENGTH, stdin);
  }

  display_flights();
  printf("Enter your option: ");
  int option;
  scanf("%d", &option);

  if (option < 1 || option > num_flights)
  {
    printf("Invalid flight option!\n");
    option = 0;
    printf("Enter flight options again: ");
    scanf("%d", &option);
  }

  strcpy(p.flight_no, flights[get_flight_index(option)].name);

  printf("Enter seat class: ");
  scanf("%s", p.seat_class);

  if (strcmp(p.seat_class, "business") == 0)
  {
    p.seat_no = get_seat_number();
  }
  else
  {
    p.seat_no = get_seat_number();
  }

  if (*num_passengers >= MAX_PASSENGERS)
  {
    printf("Maximum number of passengers reached!\n");
    return;
  }

  passengers[*num_passengers] = p;
  *num_passengers += 1;

  // Code for writing ticket details in file
  fprintf(fp, "=================================================================================\n");
  fprintf(fp, "                       Ticket Details of %s\n", p.name);
  fprintf(fp, "=================================================================================\n");
  fprintf(fp, "Name: %-20s Age: %-2d                        Gender: %c\n", p.name, p.age, p.gender);
  fprintf(fp, "From: %-20s To: %-20s        Flight Number: %s\n", p.from, p.to, p.flight_no);
  fprintf(fp, "Class: %-18s  Seat Number: %-2d                  Departure Date: %s\n", p.seat_class, p.seat_no, p.departure_date);
  fprintf(fp, "Booked By: %-20s\n",bookedBy);

  if (type_ticket == 'y')
  {
    fprintf(fp, "Return Date: %-20s", p.return_date);
  }

  fprintf(fp, "\n=================================================================================n");
  fclose(fp);

  printf("\nTicket Reserved Successfully!\n");
}

void display_ticket(Passenger *passengers, int num_passengers) {
  char name[MAX_STRING_LENGTH];
  printf("\nEnter Passenger Name: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_passengers; i++)
  {
    if (strcmp(passengers[i].name, name) == 0)
    {
      found = 1;
    printf("=================================================================================\n");
    printf("                       Ticket Details of %s\n", name);
    printf("=================================================================================\n");
      printf("Name: %-20s Age: %-2d                           Gender: %c\n", passengers[i].name, passengers[i].age, passengers[i].gender);
      printf("From: %-20s To: %-20s         Flight Number: %s\n", passengers[i].from, passengers[i].to, passengers[i].flight_no);
      printf("Class: %-18s  Seat Number: %-2d                   Departure Date: %s\n", passengers[i].seat_class, passengers[i].seat_no, passengers[i].departure_date);
      printf("Booked By: %-20s",bookedBy);

      if (type_ticket == 'y')
      {
        printf("Return Date: %-15s", passengers[i].return_date);
        break;
      }

      printf("\n=================================================================================n");
    }

    if (!found)
    {
      printf("\nPassenger Not Found!\n");
    }
  }
}

//important
void cancel_reservation(Passenger *passengers, int *num_passengers)
{
  char *file_name;
  char name[MAX_STRING_LENGTH];

  printf("\nEnter Passenger Name: ");
  scanf("%s", name);

  int found = 0; // Firstly indicating found as 0 (FALSE)
  for (int i = 0; i < *num_passengers; i++)
  {
    if (strcmp(passengers[i].name, name) == 0)
    {
      found = 1; // if passenger is found indicating 1 (TRUE)

      file_name = strcat(name, ".txt");
      if (remove(file_name) == 0)
      {
        printf("\nReservation Cancelled for %s\n", passengers[i].name);
      }

      for (int j = i; j < *num_passengers - 1; j++)
      {
        passengers[j] = passengers[j + 1];
      }
      *num_passengers -= 1;
      break;
    }
  }

  if (!found)
  {
    printf("\nPassenger Not Found!\n");
  }
}

void displayChoice()
{
  printf("\n\t\t What Would You Like To Do?");
  printf("\n\t\t________________________________________\n\n");
  printf("\n\t\t 1. Reserve Ticket");
  printf("\n\t\t 2. Display Ticket");
  printf("\n\t\t 3. Cancel Ticket");
  printf("\n\t\t 4. Exit\n");
  printf("\n\t\t________________________________________\n\n");
}

int isLoggedIn(const char *username, const char *password){
      for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful! Welcome, %s!\n", username);
            strcpy(bookedBy, username);
            return 1;
        }
    }

    return 0;

}

// will write main function to match the final requirement
int main()
{

  Passenger passengers[MAX_PASSENGERS];
  int num_passengers = 0;
  int i;
  int firstIteration = 0; // flag that checks how many iteration has occured
  int choice, option;
  char userName[MAX_STRING_LENGTH], password[MAX_STRING_LENGTH];
  char buffer[MAX_BUFFER_SIZE];
  // char username[MAX_BUFFER_SIZE];
  // char Password_[MAX_BUFFER_SIZE];
  int loggedIn = 0;
  int flag = 0;
  // char login;

  loadUserDataFromFile(); // load user data from the file at the start of the program

  printf("\n\t\t\t_______________________________________");
  printf("\n");
  printf("\n\t\t\t\t    WELCOME ");
  printf("\n\t\t\t\t      TO ");
  printf("\n\t\t\t  AIRLINE TICKET RESERVATION SYSTEM  ");
  printf("\n\t\t\t_______________________________________");
  printf("\n\n");

    while(1) {
  if(flag == 0){
    printf("Enter your username: ");
    scanf("%s", userName);
    printf("Enter your password: ");
    scanf("%s", password);
    flag = isLoggedIn(userName, password);

    if(flag == 0){
      printf("Login Failed. Please check your username and password\n");
      continue; //asking for input again
    }

  }
        printf("\n");
        displayChoice(); // function that displays the choice
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
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
