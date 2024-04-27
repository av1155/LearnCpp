# Euclidean and Inverse Calculator

This program is a console application that performs various calculations related to the Euclidean algorithm and modular inverses. It provides an interactive menu that allows users to choose from a variety of operations, including computing the greatest common divisor (GCD), additive and multiplicative inverses, and verifying these inverses, all within a modular context.

## Features

-   **Euclidean Algorithm:** Calculate the GCD of two numbers.
-   **Additive Inverse:** Determine the additive inverse of a number under modulo.
-   **Verify Additive Inverses:** Check if two numbers are additive inverses under a specified modulo.
-   **Multiplicative Inverse:** Find the multiplicative inverses of all numbers under a specified modulo.
-   **Verify Multiplicative Inverses:** Verify if two numbers are multiplicative inverses under a specified modulo.
-   **Exit:** Terminate the application.

## How to Use

1.  Compile the program using a C++ compiler (e.g., `g++`).
2.  Run the compiled executable.
3.  Follow the on-screen prompts to select an option and enter necessary values.

## Example of Usage

```
Choose an option:
1) Euclidean Algorithm
2) Additive Inverse
3) Verify Pairs as Additive Inverses
4) Multiplicative Inverse
5) Verify Pairs as Multiplicative Inverses
6) Exit
> 1

Enter the first number: 543
Enter the second number: 289

gcd(543, 289)
543 = 289(1) + 254

gcd(289, 254)
289 = 254(1) + 35

gcd(254, 35)
254 = 35(7) + 9

gcd(35, 9)
35 = 9(3) + 8

gcd(9, 8)
9 = 8(1) + 1

gcd(543, 289) = 1

Choose an option:
1) Euclidean Algorithm
2) Additive Inverse
3) Verify Pairs as Additive Inverses
4) Multiplicative Inverse
5) Verify Pairs as Multiplicative Inverses
6) Exit
> 4

Enter Z_m: 12
Elements in Z_12 with multiplicative inverses:

Bézout coefficients: s = 1, t = 0
[1 * 1] modulo 12
[1] modulo 12 = 1
Element: 1       Multiplicative Inverse Modulo 12: 1

Bézout coefficients: s = 5, t = -2
[5 * 5] modulo 12
[25] modulo 12 = 1
Element: 5       Multiplicative Inverse Modulo 12: 5

Bézout coefficients: s = -5, t = 3
Since s is negative (s = -5), we add 12 to s to
get the positive multiplicative inverse.
[7 * (12 + (-5))] modulo 12
[7 * 7] modulo 12
[49] modulo 12 = 1
Bézout coefficients: s = 7, t = 3
Element: 7       Multiplicative Inverse Modulo 12: 7

Bézout coefficients: s = -1, t = 1
Since s is negative (s = -1), we add 12 to s to
get the positive multiplicative inverse.
[11 * (12 + (-1))] modulo 12
[11 * 11] modulo 12
[121] modulo 12 = 1
Bézout coefficients: s = 11, t = 1
Element: 11      Multiplicative Inverse Modulo 12: 11
```

## Requirements

-   C++ compiler (e.g., GCC, Clang)
-   Standard C++ libraries

## Contributing

Feel free to fork this repository and submit pull requests. You can also open issues for bugs, suggestions, or new feature requests.
