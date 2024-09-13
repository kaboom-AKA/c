#include <stdio.h>
#include <stdbool.h> 

// Global variables
bool start_stop = true;

// Function declarations
void simple_trigo_and_log();
void Polynomial();
void Area_Under_a_Curve();
void Algebra();
void ExitProgram();

int main() {
    while (start_stop) 
    {
        int user_choice;
        printf("\n1. Simple trigonometry and logarithms \n2. Polynomial \n3. Area Under a Curve \n4. up to 5 algebraic expression \n5. Exit\nEnter your option: ");
        scanf("%d", &user_choice); 
        switch(user_choice) {
            case 1:
                simple_trigo_and_log();
                break;
            case 2:
                Polynomial();
                break;
            case 3:
                Area_Under_a_Curve();
                break;
            case 4:
                Algebra();
                break;
            case 5:
                ExitProgram();
                break;
            default:
                printf("\n\nInvalid Input! Please Enter Again\n");
        }
    }
    return 0;
}

void simple_trigo_and_log()
{
    printf("\n\n 1. Trigonometry \n2. logarithms\n ");
}

void Polynomial()
{
    printf("\n\n Degree of the polynomial :");
}

void Area_Under_a_Curve()
{
    printf("\n\n Equation of your curve : ");
}

void Algebra()
{
    printf("\n\n Number of Unknowns : ");
}
void ExitProgram() 
{
    char yes_no;
    printf("You sure you want to end the program?\n[type to affirm 'Y']: ");
    scanf("%c", &yes_no);  
    if (yes_no == 'Y' || yes_no == 'y') 
    {  
        printf("This is the end of the program.\n");
        start_stop = false;
    }
}