#include <stdio.h>

void display_ticket_details(const char *name, int age, char gender, const char *from, const char *to, const char *flight_number, const char *class, int seat_number, const char *departure_date, const char *booked_by, const char *return_date) {
    printf("====================================================================\n");
    printf("                       Ticket Details of %s\n", name);
    printf("====================================================================\n");
    printf("Name: %-20s Age: %-4d Gender: %c\n", name, age, gender);
    printf("From: %-20s To: %-20s Flight Number: %s\n", from, to, flight_number);
    printf("Class: %-19s Seat Number: %-4d Departure Date: %s\n", class, seat_number, departure_date);
    printf("Booked By: %-20s Return Date: %s\n", booked_by, return_date);
    printf("====================================================================\n");
}

int main() {
    // Example ticket details
    const char *name = "sajak";
    int age = 20;
    char gender = 'm';
    const char *from = "ktm";
    const char *to = "pkhr";
    const char *flight_number = "Flight-2";
    const char *class = "business";
    int seat_number = 34;
    const char *departure_date = "20 oct";
    const char *booked_by = "sajak";
    const char *return_date = "21 oct";

    // Display ticket details using the function
    display_ticket_details(name, age, gender, from, to, flight_number, class, seat_number, departure_date, booked_by, return_date);

    return 0;
}
