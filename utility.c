int main() {
  
  Passenger passengers[MAX_PASSENGERS];
  int num_passengers = 0;
  int i;
  int firstIteration = 0;  //flag that checks how many iteration has occured
  int choice,option;
  char UserName[MAX_STRING_LENGTH],Password[MAX_STRING_LENGTH];
  char buffer[MAX_BUFFER_SIZE];
  char username[MAX_BUFFER_SIZE];
  char Password_[MAX_BUFFER_SIZE];
  int loggedIn = 0;
  char login;

  loadUserDataFromFile(); //load user data from the file at the start of the program

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

    displayLoadingBar();
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