#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters();  //  Function counting the number of letter in text
int count_words();    //  Function counting the number of words in text
int count_sentences(); // Function counting the number of sentences in text

int main(void)
{
    string text = get_string("Text "); // Getting User Input


    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);


    // printf("%d letter(s)\n",  letters); // print number of letters in text
    // printf("%d words(s)\n",  words); // print number of words in text
    // printf("%d sentence(s)\n",  sentences); // print number of words in text

    //  Function counting the text grade,
    float av_letters = (float) letters / (float) words * 100; // the average number of letters per 100 words in the text
    float av_sentences = (float)  sentences / (float)  words * 100; // the average number of sentences per 100 words in the text
    float index = 0.0588 * av_letters - 0.296 * av_sentences - 15.8; // Coleman-Liau test by Sitraka

    if (index < 1)
    {
        printf("Before Grade 1\n");

    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %d\n", (int) round(index)); //give grade to that "lecturer"

    }

}

int count_letters(string input)      //Function counting the number of letter in text
{
    int num_letter = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (islower(input[i]) || isupper(input[i]))
        {
            num_letter++;
        }
    }
    return num_letter;
}

int count_words(string input)      // function counting the number of words in text
{
    int num_words = 1;

    for (int i = 0; i < strlen(input); i++)
    {
        if (isspace(input[i]))
        {
            num_words++;
        }
    }
    return num_words;
}

int count_sentences(string input)      //now counting the number of sentences in text
{
    int num_sentences = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if ('.' == input[i] || '!' == input[i] || '?' == input[i])
        {
            num_sentences++;
        }
    }
    return num_sentences;
}
//style50 readability.c
//submit50 cs50/problems/2022/x/readability
//Sitraka
