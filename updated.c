#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 50

// Define the maximum length for string inputs
#define MAX_STRING_LENGTH 50
char name_[MAX_STRING_LENGTH];

// Define the maximum length for flight names
#define MAX_FLIGHT_NAME_LENGTH 20

// Define the maximum length for seat class
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
} Passenger;

typedef struct flight {
  char name[MAX_FLIGHT_NAME_LENGTH];
} Flight;

Flight flights[] = {{"XYZ airline 009-A2"},
                    {"XYZ airline 009-A3"},
                    {"XYZ airline 79-B2"},
                    {"XYZ airline 1249-45-C5"}};

int num_flights = sizeof(flights) / sizeof(flights[0]);

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

  //file operations
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

  display_flights();
  printf("Enter your option: ");
  int option;
  scanf("%d", &option);

  if (option < 1 || option > num_flights) {
    printf("Invalid flight option!\n");
    return;
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

  fprintf(fp, "\nTicket Details of %s", p.name);
  fprintf(fp, "\n\nName: %s\t Age: %d\t Gender: %c\t", p.name, p.age, p.gender);
  fprintf(fp, "\n");
  fprintf(fp, "\nFrom: %s\t To: %s\t Flignt Number: %d\t", p.from, p.to,
          option);
  fprintf(fp, "\n");
  fprintf(fp, "\n\nClass: %s\t Seat Number: %d\t", p.seat_class, p.seat_no);
  fprintf(fp, "\n");
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
      printf("\nName: %s\n", passengers[i].name);
      printf("Age: %d\n", passengers[i].age);
      printf("Gender: %c\n", passengers[i].gender);
      printf("From: %s\n", passengers[i].from);

      printf("To: %s\n", passengers[i].to);
      printf("Flight details:\n");
      printf("Flight Name: %s\n", passengers[i].flight_no);
      printf("Seat Number: %d\n", passengers[i].seat_no);
      printf("Seat Class: %s\n", passengers[i].seat_class);
      break;
    }
  }

  if (!found) {
    printf("\nPassenger Not Found!\n");
  }
}

void cancel_reservation(Passenger *passengers, int *num_passengers) {
  FILE *file;
  char name[MAX_STRING_LENGTH];

  printf("\nEnter Passenger Name: ");
  scanf("%s", name);

  int found = 0; // Firstly indicating found as 0 (FALSE)
  for (int i = 0; i < *num_passengers; i++) {
    if (strcmp(passengers[i].name, name) == 0) {
      found = 1; // if passenger is found indicating 1 (TRUE)

        strcat(name, ".txt");
        file = fopen(name, "w");
        fclose(file);
      printf("\nReservation Cancelled for %s\n", passengers[i].name);

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
  int choice;
  printf("WELCOME TO XYZ AIRLINE SERVICE");
  printf("\n");
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
      printf("Thank you for using the Airline Ticket Reservation System.\n");
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
