#include <stdio.h>
#include <math.h>


#define srok_max 365
#define vklad_min 1000

int calc();

main (){
    int srok,vklad,sum;
    printf("\nInput srok\n");
    scanf("%i",&srok);
    if (srok > srok_max && srok > 0){
        printf("\nSrok in [1-365] days. Exit\n");
        return(0);
    }

    printf("Input vklad\n");
    scanf("%i",&vklad);
    if (vklad<vklad_min){
        printf("\nMin vklad is 1000 rubbles. Exit\n");
        return(0);
    }
    sum = calc(srok,vklad);
    printf("\nYour vklad is %i\n",sum);
}

int calc (int s, int v){
    if (s <= 30){
        v = v - v * 0.01;
//        printf("\n<30 %i\n",v);
    }
    else if (s > 30 && s <= 120){
        v = v + v * 1.02 * s / 365;
//        printf("\n<120 %i\n",v);
    }
    else if (s > 120 && s <= 240){
        v = v + v * 1.06 * s / 365;
//        printf("\n<240 %i\n",v);
    }
    else {
        v = v + v * 1.12 * s / 365;
//        printf("\n<365 %i\n",v);
    }
    return(v);
}
