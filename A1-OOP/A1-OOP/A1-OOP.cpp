// A1-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
void read_array(int v[],int &len)
{
    int i;
    printf("Choose the number of elements:");
    scanf_s("%d", &len);
    
    printf("Read the array:");
    for (i = 1; i <= len; i++)
        scanf_s("%d", &v[i]);

    
      
}
int prime(int x)
{
    int i;
    if (x < 2)
        return false;
    if (x > 2 && x % 2 == 0)
        return false;
    for (i = 3; i * i <= x; i = i + 2)
        if (x % i == 0)
            return false;
    return true;
}
void prime_numbers()
{
    int n,i;
    printf("Choose a number:");
    scanf_s("%d",&n);
    i = 2;
    while (i < n)
    {
        if (prime(i))
         printf("%d ", i);      //print the number if is prime 
           
        i++;                   //increase the number in order to find the prime numbers

    }
    printf("\n");
}
void subs_sum_prime(int v[],int len)
{
    int i,j=1,ok=0,cnt=1,maxs=0,last=0;
    for (i = 1; i < len; i++)
    {
    while (prime(v[i] + v[i + 1])&&(v[i]<=v[i+1]))     //verify if 2 consecutive numbers are in ascending order and their sum is prime
        {
                                         
            i++;            //while this is true,we increment the index of the array
            ok = 1;
            cnt++;          //the length of the subsequence increases

        }
    if (ok == 1)
        {
        i++;                //if the subsequnce stops,we increment again the index in order to find a new subsequence if it exists
        ok = 2;
        }

    if (cnt > maxs)         //find if it is the lonest subsequence
        {
        maxs = cnt;
        last = i;
        }
    if (ok == 2)            //then reset the length in order to find the new subsequence
        {
        cnt = 1;
        ok = 0;
        i--;
        }
    
        
    }
    
    for (i = last-maxs; i < last; i++)
        printf("%d ", v[i]);

    printf("\n");
      
}
int main()
{
    int option,array[1001],length=1;
    printf("1.Read an array of numbers.\n");
    printf("2.Generate the fist n prime numbers.\n");
    printf("3.Find the longest increasing contiguous subsequence ,such the sum of any 2 consecutive elements is a prime number.\n");
    printf("4.Exit.\n");
    
    while (true)
    {
        printf("Choose an option:");
        scanf_s("%d", &option);

    if (option == 1)
       read_array(array,length);
    if (option == 2)
        prime_numbers();
    
    if (option == 3)
        subs_sum_prime(array,length);
    if (option == 4)
        return false;
    }
   




    prime_numbers();

    
}