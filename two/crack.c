#include <stdio.h>
#include <string.h>
#include <crypt.h>

//Max length to try
#define MAX_LEN 5

void inc(char pass[], int i);
int char_done(char c);
int check_pass(char pass[], char salt[], char hash[]);

int main(int argc, char *argv[])
{
    //Make sure a hash was passed in
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    //Create pointer for hash and sets up salt string
    char *hash = argv[1];
    char salt[] = {hash[0], hash[1], '\0'};

    //Create string to hold guesses
    char pass[MAX_LEN + 1];

    //Try every password of length len, then increment len and try again until len exceeds MAX_LEN
    for (int len = 1; len <= MAX_LEN; len++)
    {
        //Sets up the password string
        pass[len] = '\0';
        for (int i = 0; i < len; i++)
        {
            pass[i] = 'a';
        }

        //Keeps adding to the pw string until the final character is over z
        while (!char_done(pass[len - 1]))
        {
            //Prints current guess
            //printf("%s\n", pass);

            //Check if password matches the hash
            if (check_pass(pass, salt, hash))
            {
                printf("%s\n", pass);
                return 0;
            }

            //Increments pass, then checks if any of he letters are too big, if so "carries" (E.G. resets the char to 'a' and increments the next char by one)
            inc(pass, 0);
            for (int i = 0; char_done(pass[i]) && i < len - 1; i++)
            {
                pass[i] = 'a';
                inc(pass, i + 1);
            }
        }
    }
}

//Increments the pass[i] by one, if it's z switch to uppercase
void inc(char pass[], int i)
{
    if (pass[i] == 'z')
    {
        pass[i] = 'A';
    }
    else
    {
        pass[i]++;
    }
}

//Check if char is done being incrimented, eg it's passed Z
int char_done(char c)
{
    return c > 'Z' && c < 'a';
}

//Check if encrypted pass guess matches the hash
int check_pass(char pass[], char salt[], char hash[])
{
    return strcmp(crypt(pass, salt), hash) == 0;
}
