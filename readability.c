#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters();
int count_words();
int count_sentences();

int main(void)
{
    string s = get_string("Text: ");

    double letters = count_letters(s);
    double words = count_words(s);
    double sentences = count_sentences(s);

    double L = letters / words * 100;
    double S = sentences / words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int count_letters(string string)
{
    int count_l = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (isalpha(string[i]))
        {
            count_l++;
        }
    }
    return count_l;
}

int count_words(string string)
{
    int count_w = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (isspace(string[i]))
        {
            count_w++;
        }
    }
    return count_w + 1;
}

int count_sentences(string string)
{
    int count_s = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if ((string[i] == '.') || (string[i] == '?') || (string[i] == '!'))
        {
            count_s++;
        }
    }
    return count_s;
}