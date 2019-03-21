// Fibonacci_Recursive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int F(int n)
{
	int result = 0;

	//TODO : write code here : calculation of F(n) in a recursive way

	return result;
}

int main()
{
    std::cout << "Hello World!\n";

	std::cout << "Enter the number to calculate F() for :";
	int n = 0;
	std::cin >> n;

	std::cout << "F(%d) = %d" << n << F(n);
}

