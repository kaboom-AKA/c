#include <stdio.h>
#include <stdbool.h> 
#include <math.h>

// Global variables
bool start_stop = true;

// Function declarations
void simple_trigo_and_log(void);
void Polynomial(void);
void Area_Under_a_Curve(void);
void Algebra(void);
void ExitProgram(void);
void simple_trigo(void);
void simple_log(void);

int main() {
    while (start_stop) 
    {
        int user_choice;
        printf("\n1. Simple trigonometry\n2. logarithms\n3. Polynomial \n4. Area Under a Curve \n5. up to 5 algebraic expression\n6. Exit\nEnter your option: ");
        scanf("%d", &user_choice); 
        switch(user_choice) {
            case 1:
                simple_trigo();
                break;
            case 2:
                simple_log();
                break;
            case 3:
                Polynomial();
                break;
            case 4:
                Area_Under_a_Curve();
                break;
            case 5:
                Algebra();
                break;
            case 6:
                ExitProgram();
                break;
            default:
                printf("\n\nInvalid Input! Please Enter Again\n");
        }
    }
    
    return 0;
}

void ExitProgram()
{
    char yes_no;
    printf("\n\nYou sure you want to end the program?\n[type 'Y' to affirm]: ");
    scanf(" %c", &yes_no);  // The space before %c ensures it skips any whitespace
    
    if (yes_no == 'Y' || yes_no == 'y') {  
        printf("\nThis is the end of the program.\n");
        start_stop = false;
    }
}

void simple_trigo()
{
    bool Start_Stop2 = true;
    int Trigo;
    double answer;

    //Find out the coefficent of the Trigo
    double coefficent;
    printf("Enter your coefficent :");
    scanf(" %lf", &coefficent);

    //Find out the radian of the Trigo
    double angle;
    printf("Enter your angle :");
    scanf(" %lf", &angle);
    double radians = angle * (M_PI / 180.0);

    //Find out which Trigo the user wants
    printf("1. Sin \n2. Cos \n3. Tan \n4. Cot \n5. csc 6. sec \nChoose your option :");
    scanf("%d", &Trigo); 

    //Perform calculation and display out answer
    while(Start_Stop2)
        switch(Trigo)
        {
            case 1 : 
                answer = sin(radians);
                printf("%f sin %f = %.5f",coefficent,angle,answer);
                Start_Stop2=false;
                break;
            case 2 : 
                answer = cos(radians);
                printf("%f cos %f = %.5f",coefficent,angle,answer);
                Start_Stop2=false;
                break;
            case 3 : 
                answer = tan(radians);
                printf("%f tan %f = %.5f",coefficent,angle,answer);                            
                Start_Stop2=false;
                break;                        
            case 4 : 
                answer = coefficent/sin(radians);
                printf("%f csc %f = %.5f",coefficent,angle,answer);                           
                start_stop=false;
                break; 
            case 5 : 
                answer = coefficent/cos(radians);
                printf("%f sec %f = %.5f",coefficent,angle,answer);                           
                Start_Stop2=false;
                break;
            case 6 :
                answer = coefficent/tan(radians);
                printf("%f cot %f = %.5f",coefficent,angle,answer);                           
                Start_Stop2=false;
                break;                                  
            default:
                printf("\n\nInvalid Input! Please Enter Again\n");
                scanf(" %d",&Trigo);
        }
}

void simple_log()
{
    bool Start_Stop = true;
    char Trigo;
    int answer;

    //Find out the base of log
    int base;
    printf("Enter your log base :");
    scanf(" %d", &base);

    //Find out the radian of the Trigo
    double angle;
    printf("Enter your angle :");
    scanf(" %f", &angle);
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
