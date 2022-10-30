#include <stdio.h>
#include <cs50.h>
//check50 cs50/problems/2022/x/credit
#include <string.h>
#include <stdlib.h>

long get_positive_long(void);
int check_num_length(int length);
int verify_checksum(int arr[], int length);
void check_card_type(int length, int digit0, int digit1);


int main(void)
{
    // Assign the input number to a long
    long number = get_positive_long();

// Create an array separating each digit of the number
// to allow for easy manipulation
    int arr[100];
    int length = 0;
    int j, k, r;
    int validation;

    // Separate each digit and assign a position in array
    while (number != 0)
    {
        r = number % 10;

        arr[length] = r;
        length++;

        number = number/10;
    }

    // Create an ordered array
    int digit[length];
    for (int i = 0; i < length; i++)
    {
        digit[i] = arr[length-1-i];
    }


// Verify the checksum
    validation = verify_checksum(arr, length);

// If checksum is fine, check the type of card and give an output to the user
    if (validation == 1)
    {
        check_card_type(length, digit[0], digit[1]);
    }
    else
    {
        printf("INVALID");
    }
    printf("\n"); //n means that you should insert a new line
     }

long get_positive_long(void)
{
    long n;
    do
     {
        n = get_long("Number: ");
    } while (n < 1);
    return n;

}

// Verifies the numbers checksum
int verify_checksum(int arr[], int length)
{
// Declare variables for use in figuring out number of digits
// Based on positioning of first digit counting from right to left
    int second_to_last_d = length / 2;
    int last_d;
    if (length % 2 == 0)
    {
        last_d = length / 2;
    }
    else
    {
        last_d = (length / 2) + 1;
    }

    // Declare other variables
    int doubled_digits[second_to_last_d];
    int not_doubled_digits[last_d];
    int summed_doubled_digits = 0;
    int last_digit;
    int even = 1;
    int odd = 0;


    // Double digits starting from the second to last and assign
    // them to the array doubled_digits
    for (int i = 0; i < second_to_last_d; i++)
    {
        doubled_digits[i] = arr[even] * 2;
        even += 2;
    }

    // Assign digits starting from the last digit to the array
    // not_doubled_digits
    for (int i = 0; i < last_d; i++)
    {
        not_doubled_digits[i] = arr[odd];
        odd += 2;
    }

    // Sum up all the digits in doubled_digits
    for (int i = 0; i < second_to_last_d ; i++)
    {
        int ones = doubled_digits[i] % 10;
        int tens = doubled_digits[i] / 10;

        summed_doubled_digits += tens + ones;
    }

    // Add all the digits in not_doubled_digits to the
    // summed_double_digits
    for (int i = 0; i < last_d; i++)
    {
        int ones = not_doubled_digits[i] % 10;
        int tens = not_doubled_digits[i] / 10;
        summed_doubled_digits += tens + ones;
    }

    // Get the last_digit of the summed_doubled_digits
    last_digit = summed_doubled_digits % 10;
    // Check if the last digit is 0 and return a 1 if true
    if (last_digit == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Checks the first two digits to verify if they are:
// - 34 or 34 for AMEX
// - 51, 52, 53, 54 or 55 for MASTERCARD
// - 4 for VISA
void check_card_type(int length, int digit0, int digit1)
{
    // Declare character variables for the digits
    char d1[20];
    char d2[20];

    // Assigns the first two digits to character variables
    sprintf(d1, "%d", digit0);
    sprintf(d2, "%d", digit1);

    // Concatenates the first two digits
    strcat(d1, d2);

    // Declare the first two digits as one single variable
    int first_digits = atoi(d1);

    // Now checks the type of card based on first 2 digits
    if (length == 15 && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX");
    }
    else if (length == 16 && (
            first_digits == 51 || first_digits == 52 ||
            first_digits == 53 || first_digits == 54 ||
            first_digits == 55)
            )
    {
        printf("MASTERCARD");
    }
    else if ((length == 13 || length == 16) && (digit0 == 4))
    {
        printf("VISA");
    }
    else
    {
        printf("INVALID");
    }
}
