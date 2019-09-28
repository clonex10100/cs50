#include <cs50.h>
#include <stdio.h>
void print_n_times(char c, int n);
int main(void)
{
    int height;
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        //prints spaces before pyramid
        print_n_times(' ', height - i - 1);
        //prints bricks on the left
        print_n_times('#', i + 1);
        //prints gap
        printf("  ");
        //prints bricks on the right
        print_n_times('#', i + 1);
        //newline
        printf("\n");
    }
}

void print_n_times(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}
