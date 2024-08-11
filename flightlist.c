#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
struct Flightlist {
    char code[10];
    int boardingHour;
    int boardingMinute;
    int droppingHour;
    int droppingMinute;
    float price;
};

// Queue to hold flights
struct FlightQueue {
    struct Flightlist flights[MAX];
    int front, rear;
};

void initQueue(struct FlightQueue *q) {
    q->front = 0;
    q->rear = -1;
}

// Function to add a flight to the queue
void insertFlight(struct FlightQueue *q, struct Flight flight) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        q->flights[++q->rear] = flight;
        printf("Flight added successfully.\n");
    }
}

struct Flightlist deleteFlight(struct FlightQueue *q) {
    struct Flight flight = {"", 0, 0, 0, 0, 0.0};
    if (q->rear < q->front) {
        printf("Queue is empty\n");
    } else {
        flight = q->flights[q->front++];
        printf("Flight removed successfully.\n");
    }
    return flight;
}

// Function to validate time inputs
int isValidTime(int hour, int minute) {
    return (hour >= 0 && hour < 24 && minute >= 0 && minute < 60);
}

// Function to display all flights in the queue in the desired format
void displayFlights(struct FlightQueue *q) {
    if (q->rear < q->front) {
        printf("Queue is empty\n");
    } else {
        printf("FLIGHT DETAILS\n");
        for (int i = q->front; i <= q->rear; i++) {
            // Calculate the boarding and dropping time in "HH.MM" format
            printf("GDE\t  %02d.%02d\t    %02d.%02d\t  $%.2f\t\n", 
                q->flights[i].boardingHour, q->flights[i].boardingMinute, 
                q->flights[i].droppingHour, q->flights[i].droppingMinute, 
                q->flights[i].price);
            printf("\n%s\t  BLR\t  NON-STOP\t  IXM\t      \t\n", q->flights[i].code);
            printf("\n__\n");
        }
    }
}

int main() {
    struct FlightQueue queue;
    initQueue(&queue);

    int choice;
    struct Flight flight;

    while (1) {
        printf("1. Add Flight\n");
        printf("2. Remove Flight\n");
        printf("3. Display Flights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter flight code: ");
                fgets(flight.code, sizeof(flight.code), stdin);
                flight.code[strcspn(flight.code, "\n")] = '\0'; 
                
                // Input and validate boarding time
                do {
                    printf("Enter boarding time (hour minute): ");
                    scanf("%d %d", &flight.boardingHour, &flight.boardingMinute);
                    getchar(); // to consume the newline character left by scanf

                    if (!isValidTime(flight.boardingHour, flight.boardingMinute)) {
                        printf("Invalid boarding time. Please enter again.\n");
                    }
                } while (!isValidTime(flight.boardingHour, flight.boardingMinute));

                // Input and validate dropping time
                do {
                    printf("Enter dropping time (hour minute): ");
                    scanf("%d %d", &flight.droppingHour, &flight.droppingMinute);
                    getchar(); // to consume the newline character left by scanf

                    if (!isValidTime(flight.droppingHour, flight.droppingMinute)) {
                        printf("Invalid dropping time. Please enter again.\n");
                    }
                } while (!isValidTime(flight.droppingHour, flight.droppingMinute));

                printf("Enter flight price: ");
                scanf("%f", &flight.price);
                getchar(); // to consume the newline character left by scanf

                insertFlight(&queue, flight);
                break;

            case 2:
                flight = deleteFlight(&queue);
                if (strlen(flight.code) > 0) {
                    printf("Removed Flight: %s\n", flight.code);
                }
                break;

            case 3:
                displayFlights(&queue);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
