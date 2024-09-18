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
void simple_log_and_expo(void);

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
                simple_log_and_expo();
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
    printf("1. Sin \n2. Cos \n3. Tan \n4. Csc \n5. Sec  \n6. Cot \nChoose your option :");
    scanf("%d", &Trigo); 

    //Perform calculation and display out answer
    while(Start_Stop2)
        switch(Trigo)
        {
            case 1 : 
                answer = coefficent*sin(radians);
                printf("\n%.2f sin %.2f = %.2f\n",coefficent,angle,answer);
                Start_Stop2=false;
                break;
            case 2 : 
                answer = coefficent*cos(radians);
                printf("\n%.2f cos %.2f = %.2f\n",coefficent,angle,answer);
                Start_Stop2=false;
                break;
            case 3 : 
                answer = coefficent*tan(radians);
                printf("\n%.2f tan %.2f = %.2f\n",coefficent,angle,answer);                            
                Start_Stop2=false;
                break;                        
            case 4 : 
                answer = coefficent/sin(radians);
                printf("\n%.2f csc %.2f = %.2f\n",coefficent,angle,answer);                           
                start_stop=false;
                break; 
            case 5 : 
                answer = coefficent/cos(radians);
                printf("\n%.2f sec %.2f = %.2f\n",coefficent,angle,answer);                           
                Start_Stop2=false;
                break;
            case 6 :
                answer = coefficent/tan(radians);
                printf("\n%.2f cot %.2f = %.2f",coefficent,angle,answer);                           
                Start_Stop2=false;
                break;                                  
            default:
                printf("\nInvalid Input! Please Enter Again\n");
                scanf(" %d",&Trigo);
        }
}

void simple_log_and_expo()
{
    double answer;
    bool Start_Stop2 = true;
    double coefficent;
    double base;

    //Find out if user want to calculate log or exponent
    int log_and_expo;
    printf("\n\n1. Logarium \n2. Exponent\nChoose your option :");
    scanf("%d", &log_and_expo); 

    while(Start_Stop2)
    {
        switch(log_and_expo)
        {
            case 1 :
                //Find out the coefficent          
                printf("Enter your coefficent :");
                scanf(" %lf", &coefficent);
                
                //Find out the base 
                printf("Enter your base :");
                scanf(" %lf", &base);

                //Find out the base of log
                double argument;
                printf("Enter your argument :");
                scanf(" %lf", &argument);

                //calculate the answer and print out answer
                answer = coefficent*log(argument)/log(base);
                printf("\n%.1f log%.1f(%.1f)  = %.5f\n",coefficent,base,argument,answer); 

                //end and reset
                Start_Stop2 = false;
                break;

            case 2 :
                //Find out the coefficent          
                printf("Enter your coefficent :");
                scanf(" %lf", &coefficent);
                
                //Find out the base 
                printf("Enter your base :");
                scanf(" %lf", &base);

                //Find out the power of exponent
                double exponent;
                printf("Enter your exponent :");
                scanf(" %lf", &exponent);

                //calculate the answer and print out answer
                answer = coefficent* pow(base,exponent);
                printf("\n%.1f (%.1f^%.1f)  = %.5f\n",coefficent,base,exponent,answer);

                //end and reset
                Start_Stop2 = false;
                break;

            default :
                printf("\nInvalid Input! Please Enter Again\n");
                scanf(" %d",&log_and_expo);
        } 
    }
}

void Polynomial()
{
    int degree;
    printf("\n\n Degree of the polynomial :");
    scanf("%d",degree);
}

void Area_Under_a_Curve()
{
    char equation;
    printf("\n\n Equation of your curve : ");
    scanf("%c",equation);
}

void Algebra()
{
    int Unknows;
    printf("\n\n Number of Unknowns : ");
    scanf("%d",Unknows);
    
}
