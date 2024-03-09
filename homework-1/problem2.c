//Read two integer numbers and compute their sum,average and sum of the squares of the numbers.
#include <stdio.h>
int sum,sumsq,number1,number2;
float avg;
int main()
{
scanf("%d",&number1);
scanf("%d",&number2);
sum=number1+number2;
avg=(number1+number2)/2.0;
sumsq=(number1*number1)+(number2*number2);
printf("The sum of the number is %d\n",sum);
printf("The average is %f\n",avg);
printf("The sum of the squares is %d\n",sumsq);

return 0;
}
