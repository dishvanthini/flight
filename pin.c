
int pin() {
    char phoneNumber[12];  
    char checkDigits[6];  
    printf("Enter UPI ID manually\n");
    printf("Enter 10-digit phno:");
    printf("₹ %d",f.total);
    if (fgets(phoneNumber, sizeof(phoneNumber), stdin) == NULL) {
        printf("Error reading phone number.\n");
        return 1;
    }
    printf("Enter the last 4 digits to check -PIN : ");
    if (fgets(checkDigits, sizeof(checkDigits), stdin) == NULL) {
        printf("Enter the PIN .\n");
        return 1;
    }
    phoneNumber[strcspn(phoneNumber, "\n")] = '\0';
    checkDigits[strcspn(checkDigits, "\n")] = '\0';

    if (strlen(phoneNumber) == 10 && strlen(checkDigits) == 4) {
        if (strncmp(&phoneNumber[6], checkDigits, 4) == 0) {
            printf("Paid successfully.\n");
        } else {
            printf("Enter valid PIN.\n");
        }
    } else {
        printf("Please ensure the PIN .\n");
    }
}
