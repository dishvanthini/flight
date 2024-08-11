#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char code[10];
    int boardingHour;
    int boardingMinute;
    int droppingHour;
    int droppingMinute;
    float price;
} Flightlist;

typedef struct {
    Flightlist flights[MAX];
    int front, rear;
} FlightQueue;

void initQ(FlightQueue *q);
void insertR(FlightQueue *q, Flightlist flight);
Flightlist deleteF(FlightQueue *q);
void displayQ(FlightQueue *q);
int readInt(); 
float readFloat();

int main() {
    FlightQueue queue;
    initQ(&queue);

    int choice;
    Flightlist flight;

    while (1) {
        printf("1. Add Flight\n");
        printf("2. Remove Flight\n");
        printf("3. Display Flights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        choice = readInt();

        switch (choice) {
            case 1:
                printf("Enter flight code: ");
                fgets(flight.code, sizeof(flight.code), stdin);
                flight.code[strcspn(flight.code, "\n")] = '\0'; 

                printf("Enter boarding time (hour minute): ");
                flight.boardingHour = readInt();
                flight.boardingMinute = readInt();

                printf("Enter dropping time (hour minute): ");
                flight.droppingHour = readInt();
                flight.droppingMinute = readInt();

                printf("Enter flight price: ");
                flight.price = readFloat(); 

                insertR(&queue, flight);
                break;

            case 2:
                flight = deleteF(&queue);
                if (strlen(flight.code) > 0) {
                    printf("Removed Flight: %s\n", flight.code);
                }
                break;

            case 3:
                displayQ(&queue);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void initQ(FlightQueue *q) {
    q->front = 0;
    q->rear = -1;
}

void insertR(FlightQueue *q, Flightlist flight) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        q->flights[++q->rear] = flight;
        printf("Flight added successfully.\n");
    }
}

Flightlist deleteF(FlightQueue *q) {
    Flightlist flight; 

    if (q->front > q->rear) {
        printf("Queue is empty\n"); 
        strcpy(flight.code, "");
        flight.boardingHour = 0;
        flight.boardingMinute = 0;
        flight.droppingHour = 0;
        flight.droppingMinute = 0;
        flight.price = 0.0;
    } else {
        flight = q->flights[q->front];
        q->front++; 
        printf("Flight removed successfully.\n");
    }

    return flight; 
}

int readInt() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n'); 
    }
    getchar(); 
    return value;
}

float readFloat() {
    float value;
    while (scanf("%f", &value) != 1) {
        printf("Invalid input. Please enter a float: ");
        while (getchar() != '\n'); 
    }
    getchar(); 
    return value;
}

void displayQ(FlightQueue *q) {
    if (q->rear < q->front) {
        printf("Queue is empty\n");
    } else {
        printf("FLIGHT DETAILS\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%s\t  %02d:%02d\t  -  %02d:%02d\t  ₹%.2f\n",
                q->flights[i].code,
                q->flights[i].boardingHour, q->flights[i].boardingMinute,
                q->flights[i].droppingHour, q->flights[i].droppingMinute,
                q->flights[i].price);
            printf("BLR\t  NON-STOP\t  IXM\t      \t");
            printf("\n__\n");
        }
    }
}
