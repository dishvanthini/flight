#include <stdio.h>


            struct Meal {
            char name[50];
            float cost;
        };
        
        struct Meal menu[] = {
            {"Paneer Tikka Sandwich Combo", 400.0},
            {"Meal", 400.0},
            {"Chicken Sandwich Combo", 500.0},
            // Add more meal options here if needed
        };
        
        int main() {
            int numMeals;
            float totalCost = 0.0;
        
            printf("Welcome to the GDE Flight Meal Selection\n");
            printf("menu:\n");
            printf("1. Paneer Tikka Sandwich Combo - Rs 400\n");
            printf("2. Meal - Rs 400\n");
            printf("3. Chicken Sandwich Combo - Rs 500\n");
        
            printf("\nEnter the number of meals: ");
            scanf("%d", &numMeals);
        
            for (int i = 0; i < numMeals; i++) {
                int choice;
                printf("\n%d meal:\n", i + 1);
                for (int j = 0; j < sizeof(menu) / sizeof(menu[0]); j++) {
                    printf("%d. %s - Rs %.2f\n", j + 1, menu[j].name, menu[j].cost);
                }
                printf("Enter your choice: ");
                scanf("%d", &choice);
        
                if (choice >= 1 && choice <= sizeof(menu) / sizeof(menu[0])) {
                    totalCost += menu[choice - 1].cost;
                } else {
                    printf("Please select a valid meal.\n");
                    i--; 
                }
            }
        
            printf("\nYour selected meals:\n");
            for (int i = 0; i < numMeals; i++) {
                printf("%d. %s\n", i + 1, menu[i].name);
            }
            printf("Total cost: Rs %.2f\n", totalCost);
        
            return 0;
        }
