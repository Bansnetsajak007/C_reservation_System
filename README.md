 <!-- work in prograss -->

 Inspired by reservation architecture. This is just the basic prototype of reservation architecture written in C. For More depth information you can visit **https://en.wikipedia.org/wiki/Computer_reservation_system.**

```
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
```

First we get started with the inclusion of all the necessary header files


```
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
  printf("Do you want return Ticket [y/n]: ");
  scanf(" %c", &type_ticket);
  getchar();  // Consume the newline character

  if(type_ticket == 'y'){
    printf("Enter your depature date: ");
    // scanf("%s", p.depature_date);
    fgets(p.depature_date,MAX_STRING_LENGTH,stdin);

    printf("Enter your return date: ");
    // scanf("%s", p.return_date);
    fgets(p.return_date,MAX_STRING_LENGTH,stdin);
  }

 else{
  printf("Enter your depature date: ");
  // scanf("%s", p.depature_date);
    fgets(p.depature_date,MAX_STRING_LENGTH,stdin);
 }

  display_flights();
  printf("Enter your option: ");
  int option;
  scanf("%d", &option);

  if (option < 1 || option > num_flights) {
    printf("Invalid flight option!\n");
    option = 0;
    printf("Enter filight options again: ");
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

//code for writing ticket details in file
if(type_ticket == 'y'){
  fprintf(fp, "\n\t\t\tTicket Details of %s", p.name);
  fprintf(fp, "\n\nName: %s\t Age: %d\t Gender: %c\t", p.name, p.age, p.gender);
  fprintf(fp, "\n");
  fprintf(fp, "\nFrom: %s\t To: %s\t Flignt Number: %d\t", p.from, p.to,
          option);
  fprintf(fp, "\n");
  fprintf(fp, "\nClass: %s\t Seat Number: %d\t", p.seat_class, p.seat_no);
  fprintf(fp, "\nDepature Date: %s\t", p.depature_date);
  fprintf(fp, "\n");
  fprintf(fp, "\nReturn Date: %s\t", p.return_date);
  fprintf(fp, "\n");
  fclose(fp);

  printf("\nTicket Reserved Successfully!\n");
  }

else{
  fprintf(fp, "\nTicket Details of %s", p.name);
  fprintf(fp, "\n\nName: %s\t Age: %d\t Gender: %c\t", p.name, p.age, p.gender);
  fprintf(fp, "\n");
  fprintf(fp, "\nFrom: %s\t To: %s\t Flignt Number: %d\t", p.from, p.to,
          option);
  fprintf(fp, "\n");
  fprintf(fp, "\nClass: %s\t Seat Number: %d\t", p.seat_class, p.seat_no);
  fprintf(fp, "\nDepature Date: %s\t", p.depature_date);
  fprintf(fp, "\n");
  fclose(fp);

  printf("\nTicket Reserved Successfully!\n"); 
    }
}
```




