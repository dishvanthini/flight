#include<stdio.h>
void ticket()
{
    printf("FROM:%s\t\t",f.from);
    printf("TO:%s\n",f.to);
    printf("DEPARTURE:%s\n",f.d);
    printf("TRAVELLERS & CLASS:\n");
    printf("Traveller's Details \n");
    printf("\tTitle\t\t\tFirst & Middle name\t\tlast name\n");
    printf("\t%s\t\t%s\t\t\t%s\n", f.title, f.firstName, f.lastName);
    printf("nationality:%s\t\n\n",f.nationality);
    printf("Contact Details \n");
    printf("\tCountry code\t\tMobile number\t\t\tEmail\n");
    printf("\t%d\t\t%d\t\t\t%s\n", f.countryCode, f.mobileNumber, f.email);
    printf("\tIndia(+91)\n");
    };
