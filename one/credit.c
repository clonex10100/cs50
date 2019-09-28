#include <stdio.h>
#include <cs50.h>
#include <math.h>

int access_at_n(long num, int n);
int get_len(long num);

int main(void)
{
    long card_num = get_long("Number: ");
    int card_num_len = get_len(card_num);
    int sum = 0;
    int digit;
    for (int i = 0; i < card_num_len; i++)
    {   
        digit = access_at_n(card_num, i);
        //If odd, multiply by two and add the digets
        if (i % 2 == 1)
        {
            digit *= 2;
            //add first digit
            sum += digit / 10;
            //add secound digit
            sum += digit % 10;
        }
        //else directly add
        else
        {
            sum += digit;
        } 
    }
    string out = "INVALID";
    //Check if it's valid
    if (sum % 10 == 0)
    {
        //first two digits to identify card
        int first = access_at_n(card_num, card_num_len - 1);
        int secound = access_at_n(card_num, card_num_len - 2);
        if ((first == 3 && (secound == 4 || secound == 7)) && card_num_len == 15)
        {
            out = "AMEX";
        }
        else if ((first == 5 && secound <= 5 && secound >= 1) && card_num_len == 16)
        {
            out = "MASTERCARD";
        }
        else if (first == 4 && (card_num_len == 13 || card_num_len == 16))
        {
            out = "VISA";
        }
    }
    printf("%s\n", out);
}

int access_at_n(long num, int n)
{
    return num / (long)pow(10, n) % 10;
}

int get_len(long num)
{
    int len = 1;
    while (num >= 10)
    {
        num /= 10;
        len++;
    }
    return len;
}
