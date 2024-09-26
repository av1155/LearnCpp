#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Main function to drive the program.
 * Allows the user to select from options related to Euclidean algorithm computations and inverse
 * calculations. It continuously displays a menu for the user to choose operations like finding the
 * GCD, additive and multiplicative inverses, and verifying these inverses until the user decides to
 * exit.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Integer representing the exit status.
 */
int main( int argc, char *argv[] );

/**
 * @brief Executes the process of finding the GCD using the Euclidean algorithm.
 * Prompts the user for two numbers and displays the GCD.
 */
void euclideanAlgorithm();

/**
 * @brief Computes and displays the additive inverse of a number in a specified modulo.
 * Prompts the user for the modulo and the number, then calculates and displays the additive
 * inverse.
 */
void additiveInverse();

/**
 * @brief Verifies if two elements are additive inverses in a specified modulo.
 * Prompts the user for the modulo and two elements, checks if their sum modulo the given number is
 * zero, and displays whether they are additive inverses.
 */
void verifyAdditiveInversePair();

/**
 * @brief Computes and displays the multiplicative inverse of numbers in a specified modulo.
 * Iterates through all elements in the specified modulo, computes the multiplicative inverse for
 * each, and displays them.
 */
void multiplicativeInverse();

/**
 * @brief Verifies if two elements are multiplicative inverses in a specified modulo.
 * Prompts the user for the modulo and two elements, checks if their product modulo the given number
 * is one, and displays whether they are multiplicative inverses.
 */
void verifyMultiplicativeInversePair();

/**
 * @brief Calculates the greatest common divisor (GCD) of two integers using the Extended Euclidean
 * Algorithm. It also determines the Bézout coefficients that satisfy the equation gcd(a, b) = as +
 * bt.
 *
 * @param a First integer.
 * @param b Second integer.
 * @param x Pointer to store the first Bézout coefficient.
 * @param y Pointer to store the second Bézout coefficient.
 * @return The greatest common divisor of a and b.
 */
long bezoutCoefficients( long a, long b, long *x, long *y );

/**
 * @brief Collects a number from the user.
 * Prompts the user to enter a number and reads the input from the standard input.
 *
 * @return The number entered by the user.
 */
long collectNumber();

/**
 * @brief Calculates the greatest common divisor (GCD) of two integers using the Euclidean
 * algorithm. Recursively applies the Euclidean algorithm by swapping if necessary and finding the
 * remainder until it reaches zero.
 *
 * @param currentGCD Current GCD being calculated.
 * @param currentRemainder Current remainder in the calculation.
 * @return The GCD of the two input integers.
 */
long findGCD( long currentGCD, long currentRemainder );

/**
 * @brief Swaps two numbers if the first number is less than the second number.
 * Uses a temporary variable to swap the values of two numbers to ensure the first number is not
 * less than the second.
 *
 * @param firstNumber Reference to the first number.
 * @param secondNumber Reference to the second number.
 */
void swapIfLess( long &firstNumber, long &secondNumber );

int main( int argc, char *argv[] )
{
    int userOption;
    while ( true )
    {
        printf( "\nChoose an option:\n" );
        printf( "1) Euclidean Algorithm\n" );
        printf( "2) Additive Inverse\n" );
        printf( "3) Verify Pairs as Additive Inverses\n" );
        printf( "4) Multiplicative Inverse\n" );
        printf( "5) Verify Pairs as Multiplicative Inverses\n" );
        printf( "6) Exit\n> " );
        scanf( "%d", &userOption );

        switch ( userOption )
        {
        case 1:
            euclideanAlgorithm();
            break;

        case 2:
            additiveInverse();
            break;

        case 3:
            verifyAdditiveInversePair();
            break;

        case 4:
            multiplicativeInverse();
            break;

        case 5:
            verifyMultiplicativeInversePair();
            break;

        case 6:
            exit( 0 );

        default:
            exit( 1 );
        }
    }

    return 0;
}

void euclideanAlgorithm()
{
    printf( "\nEnter the first number: " );
    long firstNumber = collectNumber();

    printf( "Enter the second number: " );
    long secondNumber = collectNumber();

    printf( "\ngcd(%ld, %ld) = %ld\n", firstNumber, secondNumber,
            findGCD( firstNumber, secondNumber ) );
}

void additiveInverse()
{
    printf( "\nEnter Z_m: " );
    long Z_m = collectNumber();

    printf( "Enter the element to find its additive inverse in Z_%ld: ", Z_m );
    long a = collectNumber();

    long additiveInverse = Z_m - a;
    printf( "The additive inverse of %ld in %ld is %ld.\n", a, Z_m, additiveInverse );
}

void verifyAdditiveInversePair()
{

    printf( "\nEnter Z_m: " );
    long Z_m = collectNumber();

    printf( "The additive inverse relation between element A and B in Z_%ld will be verified.\n",
            Z_m );

    printf( "Enter element A: " );
    long a = collectNumber();

    printf( "Enter element B: " );
    long b = collectNumber();

    long sum = a + b;
    long remainder = sum % Z_m;

    if ( remainder == 0 )
        printf(
            "%ld and %ld are additive inverses of each other since [%ld + %ld] modulo %ld = %ld.\n",
            a, b, a, b, Z_m, remainder );

    else
        printf( "%ld and %ld are NOT additive inverses of each other because [%ld + %ld] modulo "
                "%ld = %ld, not 0.\n",
                a, b, a, b, Z_m, remainder );
}

long bezoutCoefficients( long a, long b, long *s, long *t )
{
    // Base case: if a is 0, the GCD is b and the coefficients are (0,1)
    if ( a == 0 )
    {
        *s = 0; // Set s coefficient to 0
        *t = 1; // Set t coefficient to 1
        return b;
    }

    long temp_s, temp_t; // Temporary variables to store coefficients during recursion
    long gcd = bezoutCoefficients( b % a, a, &temp_s, &temp_t ); // Recursive call

    // Update the coefficients for the current recursion level
    *s = temp_t - ( b / a ) * temp_s;
    *t = temp_s;

    return gcd; // Returns GCD and sets s and t for the current recursion level
}

void multiplicativeInverse()
{
    printf( "\nEnter Z_m: " ); // Prompt user for the modulus
    long Z_m;
    scanf( "%ld", &Z_m ); // Read the modulus

    printf( "Elements in Z_%ld with multiplicative inverses:\n", Z_m );
    for ( long a = 1; a < Z_m; ++a )
    {
        long s, t; // Variables to store the Bézout coefficients
        long gcd = bezoutCoefficients( a, Z_m, &s, &t ); // Compute GCD and coefficients

        if ( gcd == 1 )
        { // Only elements coprime with Z_m have inverses
            // Calculate the positive multiplicative inverse modulo Z_m
            long multiplicativeInverse = ( s % Z_m + Z_m ) % Z_m;

            // Check and adjust 's' if negative
            if ( s < 0 )
            {
                printf( "\nBézout coefficients: s = %ld, t = %ld", s, t );
                printf( "\nSince s is negative (s = %ld), we add %ld to s to\nget the positive "
                        "multiplicative inverse.\n",
                        s, Z_m );
                printf( "[%ld * (%ld + (%ld))] modulo %ld\n", a, Z_m, s, Z_m );
                printf( "[%ld * %ld] modulo %ld\n", a, Z_m + s, Z_m );
                printf( "[%ld] modulo %ld = 1\n", a * ( Z_m + s ), Z_m );
                s += Z_m; // Adjust 's' to be positive
                printf( "Bézout coefficients: s = %ld, t = %ld\n", s, t );
            }

            else
            {
                printf( "\nBézout coefficients: s = %ld, t = %ld\n", s, t );
                printf( "[%ld * %ld] modulo %ld\n", a, s, Z_m );
                printf( "[%ld] modulo %ld = 1\n", a * s, Z_m );
            }

            printf( "Element: %ld \t Multiplicative Inverse Modulo %ld: %ld\n", a, Z_m,
                    multiplicativeInverse );
        }
    }
}

void verifyMultiplicativeInversePair()
{
    printf( "\nEnter Z_m: " );
    long Z_m = collectNumber();

    printf(
        "The multiplicative inverse relation between element A and B in Z_%ld will be verified.\n",
        Z_m );

    printf( "Enter element A: " );
    long a = collectNumber();

    printf( "Enter element B: " );
    long b = collectNumber();

    long product = a * b;
    long remainder = product % Z_m;

    if ( remainder == 1 )
        printf( "%ld and %ld are multiplicative inverses of each other since [%ld * %ld] modulo "
                "%ld = %ld.\n",
                a, b, a, b, Z_m, remainder );

    else
        printf( "%ld and %ld are NOT multiplicative inverses of each other because [%ld * %ld] "
                "modulo %ld = %ld, not 1.\n",
                a, b, a, b, Z_m, remainder );
}

long collectNumber()
{
    long number = 0;
    scanf( "%ld", &number );
    return number;
}

long findGCD( long currentGCD, long currentRemainder )
{
    swapIfLess( currentGCD, currentRemainder );

    long remainder = currentGCD % currentRemainder;
    printf( "\ngcd(%ld, %ld)", currentGCD, currentRemainder );
    printf( "\n%ld = %ld(%ld) + %ld\n", currentGCD, currentRemainder, currentGCD / currentRemainder,
            remainder );

    while ( remainder != 0 )
    {
        currentGCD = currentRemainder;
        currentRemainder = remainder;
        remainder = currentGCD % currentRemainder;
        long quotient = currentGCD / currentRemainder;

        if ( remainder > 0 )
        {
            printf( "\ngcd(%ld, %ld)", currentGCD, currentRemainder );
            printf( "\n%ld = %ld(%ld) + %ld\n", currentGCD, currentRemainder, quotient, remainder );
        }
    }

    return currentRemainder;
}

void swapIfLess( long &firstNumber, long &secondNumber )
{
    long swapTemp;

    if ( firstNumber < secondNumber )
    {
        swapTemp = firstNumber;
        firstNumber = secondNumber;
        secondNumber = swapTemp;
    }
}
