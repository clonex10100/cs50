#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
int unshift(char c);
char enc_char(char c, char s);
int args_valid(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if (args_valid(argc, argv))
    {
        //set keyword to the codeword passed in
        char *keyword = argv[1];
        int klen = strlen(keyword);

        //get plaintext
        string plain = get_string("plaintext:  ");

        //Get len of plaintext and create cipher string
        int len = strlen(plain);
        char cipher[len + 1];
        cipher[len] = '\0';
        
        //temp storage for cipher char
        char c;

        //Iterate over plaintext and if the current char is a letter encrypt it using the current letter of the keyword
        for (int i = 0, j = 0; i < len; i++)
        {
            c = plain[i];
            if isalpha(c)
            {
                c = enc_char(plain[i], keyword[j % klen]);
                j++;
            }
            cipher[i] = c;
        }
        printf("ciphertext: %s\n", cipher);
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

//Check if the program was given a single command line argument of a keyword
int args_valid(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 0;
    }
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            return 0;
        }
    }
    
    return 1;
}

//Turn c into it's shift value
int shift(char c)
{
    return tolower(c) - 'a';
}

//Turn shift value into lowercase letter
int unshift(char c)
{
    return c + 'a';
}

//Encrypt char c with value of char key k
char enc_char(char c, char k)
{
    int upper = isupper(c);
    c = unshift((shift(c) + shift(k)) % 26);
    if (upper)
    {
        c = toupper(c);
    }
    return c;
}
