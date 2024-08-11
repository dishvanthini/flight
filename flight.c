#include <stdio.h>
#include <string.h>
#include <ctype.h>

void phase1();
void login();
void details();
void phdetails();
void adrs();
void pay();
int pin();

struct flight {
    int ch, m, d;
    char from[20];
    char to[20];
    char mail[30];
    int traveller;
    char cls[10];
    char ph[12];
    char title[10];
    char name[20];
    char Lname[20];
    int total;
};

struct flight f;

void phase1() {
    printf("FROM:\t\t");
    scanf("%s", f.from);
    printf("TO:\n");
    scanf("%s", f.to);
    printf("DEPARTURE: month-date\n");
    scanf("%d%d", &f.m, &f.d);
    printf("TRAVELLERS:\n");
    scanf("%d", &f.traveller);
    printf("Enter CLASS:\n1. Economy\n2. Premium Economy\n3. Business\n");
    scanf("%d", &f.ch);
    switch (f.ch) {
        case 1:
            printf("Economy\n");
            break;
        case 2:
            printf("Premium economy\n");
            break;
        case 3:
            printf("Business\n");
            break;
    }
    printf("SEARCHING................................!\n\n");
}

void login() {
    printf("\x1b[34mLogin with GDE \n");
    printf("\t\x1b[m+91_");
    scanf("%s", f.ph);  // Changed to string input
    printf("\n\x1b[34mOther login options:\n");
    printf("\t \x1b[mLog in with Google\n");
    printf("\t \x1b[mLog in with Facebook\n\n");

    // Prompt user to enter email ID
    printf("\x1b[34mEnter your email ID: \x1b[m");
    scanf("%s", f.mail);

    // Verify the first letter of the email is lowercase
    if (islower(f.mail[0])) {
        printf("Email ID verified!\n");
    } else {
        printf("\x1b[31mPlease enter a valid email ID (start with a lowercase letter).\n");
        return;
    }


}

void details() {
    printf("Hey %s!\n", f.mail);
    for (int i = 0; i < f.traveller; i++) {
        printf("Traveller %d Details:\n", i + 1);
        printf("\tTitle: ");
        scanf("%s", f.title);
        printf("\tFirst & Middle name: ");
        scanf("%s", f.name);
        printf("\tLast name: ");
        scanf("%s", f.Lname);
        printf("\tNationality: Indian\n\n");
    }
}

void phdetails() {
    printf("Contact Details:\n");
    printf("\tCountry code: +91\n");
    printf("\tMobile number: %s\n", f.ph);
    printf("\tEmail: %s@gmail.com\n", f.mail);
}

void adrs() {
    printf("Billing Address:\nAs per latest govt regulations, it's mandatory to provide your address.\n");
    printf("Pincode:\t");
    printf("Address:\n");
    printf("City:\t");
    printf("State:\n");
}

int pin() {
    char phoneNumber[12];
    char checkDigits[6];

    printf("Enter UPI ID manually\n");
    printf("Enter 10-digit phone number: ");
    if (fgets(phoneNumber, sizeof(phoneNumber), stdin) == NULL) {
        printf("Enter a valid UPI phone number.\n");
        return 1;
    }
    phoneNumber[strcspn(phoneNumber, "\n")] = '\0';

    printf("Amount to be paid: ₹%d\n", f.total);
    printf("Enter the last 4 digits to check - PIN: \n");

    if (fgets(checkDigits, sizeof(checkDigits), stdin) == NULL) {
        printf("Invalid PIN.\n");
        return 1;
    }
    checkDigits[strcspn(checkDigits, "\n")] = '\0';

    if (strlen(phoneNumber) == 10 && strlen(checkDigits) == 4) {
        if (strncmp(&phoneNumber[6], checkDigits, 4) == 0) {
            printf("Paid successfully.\n");
        } else {
            printf("Enter a valid PIN.\n");
        }
    } else {
        printf("Please ensure the PIN is correct.\n");
    }

    return 0;
}

int main() {
    f.total = 6043;
    // phase1();
    login();
    // details();
    // phdetails();
    // adrs();
    // pin();

    return 0;
}
