#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Flight {
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

struct Flight f;

void phase1() {
   printf("XXXXXXX XXXXXXXX WELCOME TO GDE AIRLINES XXXXXXX XXXXXXX\n\n");
    printf("FROM:\t\t");
    scanf("%s", f.from);
    printf("TO:\t\t");
    scanf("%s", f.to);
    printf("DEPARTURE(mm-dd):");
    scanf("%d-%d", &f.m, &f.d);
    printf("NO OF TRAVELLERS:");
    scanf("%d", &f.traveller);
printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
    printf("\tCLASS:\n\t\t1. Economy\n\t\t2. Premium Economy\n\t\t3. Business\n\t\
\tENTER CLASS -\t");
    scanf("%d", &f.ch);
printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
    switch (f.ch) {
        case 1:
            strcpy(f.cls,"Economy ");
            printf("Economy class\n");
            break;
        case 2:
            strcpy(f.cls,"Premium Economy ");
            printf("Premium Economy class\n");
            break;
        case 3:
            strcpy(f.cls,"Business ");
            printf("Business class\n");
            break;
    }
    printf("SEARCHING FLIGHT......................!\n\n");
}

void login() {
printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");
    printf("\x1b[34mLogin with GDE \n");  // x1b - blue color
    printf("\t\x1b[m+91_");
    scanf("%s", f.ph);
    printf("\n\x1b[34mOther login options:\n");
    printf("\t \x1b[mLog in with Google\n");
    printf("\t \x1b[mLog in with Facebook\n\n");
    printf("\x1b[34mEnter your email ID: \x1b[m");
    printf("\t\x1b[34m@gmail.com \n\x1b[m");
    scanf("%s", f.mail);
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
    
    if (islower(f.mail[0])) {
        printf("Email ID verified!\n");  // verifying the mail
    } else {
        printf("\x1b[31mPlease enter a valid email ID (start with a lowercase letter).\n");
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
        return;
    }
}

void details() {
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
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
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
    }
}

void phdetails() {
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
    printf("Contact Details:\n");
    printf("\tCountry code: +91\n");
    printf("\tMobile number: %s\n", f.ph);
    printf("\tEmail: %s\n", f.mail);
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
}

int pin() {
    char phoneNumber[12];  
    char checkDigits[6]; 
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
    printf("Enter UPI ID mobile no : \n");
	scanf("%s",phoneNumber);
    printf("Enter 10-digit phone number:");
    printf("₹ %d\n", f.total);

    if (fgets(phoneNumber, sizeof(phoneNumber), stdin) == NULL) {
        printf("Error reading phone number.\n");
        return 1;
    }
    printf("Enter the last 4 digits to check - PIN: \n");
    if (fgets(checkDigits, sizeof(checkDigits), stdin) == NULL) {
        printf("Enter the PIN.\n");
        return 1;
    }
    phoneNumber[strcspn(phoneNumber, "\n")] = '\0';
    checkDigits[strcspn(checkDigits, "\n")] = '\0';

// newline character ('\n') in the input, and it replaces it with a null terminator ('\0').
//starting from index 6 ---ph[6]
    if (strlen(phoneNumber) == 10 && strlen(checkDigits) == 4) {
        if (strncmp(&phoneNumber[6], checkDigits, 4) == 0) {
            printf("Paid successfully.\n");
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
        } else {
            printf("Enter valid PIN.\n");
        }
    } else {
        printf("Please ensure the PIN.\n");
    }

    return 0;
}

void ticket() {
printf("Thank you for your booking ......!\n");
printf("xxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
printf("Summary\n");
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
printf("FROM: %s\t\t", f.from);
    printf("TO: %s\n", f.to);
    printf("DEPARTURE: %d-%d-2024\n", f.m, f.d);
   printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
    printf("TRAVELLERS & CLASS:\n");
    printf("Traveller's Details \n");
    printf("\tTitle\tFirst & Middle name\tLastname\n");
    printf("\t%s\t%s\t\t%s\n", f.title, f.name, f.Lname);
 printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
    printf("Contact Details \n");
    printf("\tCountry code-India(+91)\n");
    printf("\tMobile number\t\tEmail\n");
    printf("\t%s\t\t%s@gmail.com\n", f.ph, f.mail);
printf("xxxxxxxxxxxxxx xxxxxxxxxxxxxx\n\n");
}

int main() {
    f.total = 6043;
    phase1();
    login();
    details();
    phdetails();
    //adrs();
    //pin();
    ticket();
    return 0;
}
