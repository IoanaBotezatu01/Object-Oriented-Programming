//Knowing that we have coins of 1,2 and 5 units, determine the minimum number of coins to pay the given amount
#include <stdio.h>
int amount,coins,r;
int main()
{
scanf("%d",&amount);
while(amount-5>=0)//we substract 5 as long as the amount remains positive
{coins=coins+1;
amount=amount-5;
}

while(amount-2>=0)//we substract 2 as long as the amount remains positive
{coins=coins+1;
amount=amount-2;
}


coins=coins+amount;//the remaining amount will be 1 or 0 so we would use coins of 1 unit

printf("The number of coins is %d\n",coins);

return 0;
}
