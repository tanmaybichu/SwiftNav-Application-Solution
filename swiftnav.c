#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<assert.h>

// Function to check if a number is prime
// Takes an integer as input and returns true if the number is prime. Else, returns false.
bool isPrime(int n){

	if (n<2)				// Negative numbers, 0 and 1 are not prime
		return false ;

	if (n==2)				// Special case : 2 is prime.
		return true ;

	else{					// Check if divisible by any number upto sqrt(n)
		int i ;
		for(i=2;i<=sqrt(n);i++){
			if (n%i == 0)			// If divisible, not prime.
				return false ;		
		}
	}

	return true ;			// Passed all tests. Prime number!
}

// Function to generate the first n fibonacci numbers and return the nth number in the sequence.
// Takes an integer "n" as input and returns the "n"th Fibonacci number
long fibonacci(int n){
	if (n==1)				// Special Case : n=1
		return 1 ;

	long fib[n-1], i ;		// fib[n-1] : Array to hold the n Fibonacci numbers
	fib[0] = 1 ;			// Initialize first 2 numbers
	fib[1] = 1 ;

	for (i=2;i<n;i++)		// Loop to calculate the next Fibonacci number
		fib[i] = fib[i-1] + fib[i-2] ;

	return fib[n-1] ;		// Return the last number in the sequence.
}

int main(int argc, char *argv[]){
	if(argc != 2) {
		printf ("Incorrect number of arguments. Please enter only 1 positive integer input. Aborting...\n") ;
		return -1 ;
	}
		
	int num = atoi(argv[1]) ;
	if (num <= 0){
		printf ("Please enter a positive number. Aborting...\n") ;
		return -1 ;
	}

	long a = fibonacci(atoi(argv[1])) ;
	printf ("The number at position %d in the Fibonacci sequence is %ld\n",atoi(argv[1]),a) ;

	if (a%3 == 0)			// Divisibility by 3
		printf("Buzz\n") ;

	if (a%5 == 0)			// Divisibility by 5
		printf("Fizz\n") ;

	if(isPrime(a))
		printf("BuzzFizz\n") ;

	return 0 ;
}
