#include <stdio.h>
#define MAX 10

double kurtosis(double* x, int numberOfx);
double numerator(double* x, int numberOfx);
double denominator(double* x, int numberOfx);
double average(double* x, int numberOfx);
double power(double value, int power);


int main()
{
    double x[MAX], kur;
    int numb;
    printf("Enter the values to calculate kurtosis (negative value to stop)\n");
    for(numb = 0;numb<MAX;numb++){
       if(scanf("%lf",&(x[numb]))==-1)break;
       if(x[numb]<0)break;
    }
    
    if(numb==MAX){
        printf("The maximum capacity is reached\n");
    }
    
    printf("\n");
    kur = kurtosis(x,numb);

    for(int i = 0;i<numb;i++)
    {
        printf("Value %.2d = %lg\n",i+1,x[i]);
    }
    printf("---------------------\n");
    printf("Kurtosis = %lg\n",kur);


    getchar();
    return 0;
}

double kurtosis(double* x, int numberOfx)
{
    double kurtosis;
    kurtosis = numerator(x,numberOfx)/denominator(x,numberOfx);
    return kurtosis;
}

double numerator(double* x, int numberOfx)
{
    double sum = 0;
    double avr = average(x,numberOfx);
    for(int i =0; i < numberOfx;i++)
    {
        sum+=power(x[i]-avr,4);
    }
    sum = sum/numberOfx;
    return sum;
}

double denominator(double* x, int numberOfx)
{
    double sum = 0;
    double avr = average(x,numberOfx);
    for(int i =0; i<numberOfx;i++)
    {
        sum+=power(x[i]-avr,2);
    }
    sum = sum/numberOfx;
    sum = power(sum,2);
    return sum;
}

double average(double* x, int numberOfx)
{
    double sum=0;
    for(int i =0;i<numberOfx;i++)sum+=x[i];
    sum = sum /numberOfx;
    return sum;
}

double power(double value, int power)
{
    double startValue = value;
    for(int i = 2;i<=power;i++)value*=startValue;
    return value;
}


