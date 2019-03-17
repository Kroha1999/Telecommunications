#include <stdio.h>
#include <ctype.h>


double telephone(unsigned int mins);
double internet(unsigned int mins);
double television(unsigned int mins,  unsigned int pack_type);

int main(){
    unsigned int accountNumb,minutes,TV_Pack;
    char serviceCode;
    double sum; 
   
    printf("Please, enter account number\n");
    scanf("%d",&accountNumb);
   // getchar();
    while(1)
    {
        getchar();
        printf("Please, enter service code: P - telephone, I - internet, T - television\n");
        if(scanf("%c",&serviceCode)==-1)
        {  
            printf("You entered wrong data\n");
            continue;
        }
        
        if(toupper(serviceCode)=='P' || toupper(serviceCode)=='I' || toupper(serviceCode)=='T')
            break; 
        else
        {  
            printf("You entered wrong data\n");
            continue;
        }
    }

    while(1){
    printf("Please, enter service consumption in minutes\n");

    if(scanf("%d",&minutes)!=-1)break;
    }

    if(toupper(serviceCode)=='T'){
        while(1)
        {
            printf("Please, enter your version of TVpack: 1 - Basic pack, 2 - Premium pack\n");
            if(scanf("%d",&TV_Pack)==-1)
            {
                printf("You entered wrong data\n");
                continue;
            }
            if(TV_Pack>2)
            {
                printf("You entered wrong data\n");
                continue;
            }
            else break;
        }
    }

    switch(toupper(serviceCode))
    {
        case 'P':
            sum = telephone(minutes);
            break;
        case 'I':
            sum = internet(minutes);
            break;
        case 'T':
            sum = television(minutes,TV_Pack);
            break;
    }

    printf("User account: %d\nAmmount for service %.2lf£\n",accountNumb,sum);

    getchar();
    return 0;
}



double telephone(unsigned int mins){
    return 15.0+ (double)mins*0.05;
}

double internet(unsigned int mins){
    if(mins<=1000)return 20.0;
    else return 20.0 + (double)(mins-1000)*0.02;
}

double television(unsigned int mins, unsigned int pack_type){
    //Basic pack
    if(pack_type == 1)
    {
        if(mins<=60)return 5.0;
        else return 5.0 + (double)(mins-60)*0.01;
    }
    else if(pack_type == 2)
    {
        if(mins<=60)return 10.0;
        else return 10.0 + (double)(mins-60)*0.02;
    }
}
