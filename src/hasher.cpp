#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cstdlib>

using namespace std;

#define MOD 1000000007
#define rec(i, n) for(int i = 0; i < n; i++)
#define max(a,b) ((a)>(b))?(a):(b)
#define u unsigned

/**
 * Function to print all the help message
 */
void help() {
	printf("--- HAHSER BY HECTOR09 ---\n");
	printf("For correct usage use one of the following commands\n");
	printf("\thasher -h : for help \n");
	printf("\thasher -a <string> : to calculate all type of listed hashes \n");
	printf("\thasher -md5 <string> : to calculate md5 digest \n");
	printf("\thasher -b64 <string> : to calculate both base64 encoded & decoded string \n");
	printf("\thasher -b64E <string> : to calculate base64 encoded string \n");
	printf("\thasher -b64D <string> : to calculate base64 decoded string \n");


	// -- examples
	printf("\tExample: hasher -md5 hector\n");
}

/**
 * Fucntion to calculate and print the md5 digest of the input string
 *
 * @todo - later shift this to use openssl library rather than running
 * system command ...
 */
void md5(char s[]) {
	char command[100];
	int x = sprintf(command, "md5 -s \"%s\"", s);
	system(command);
}

/**
 * Fucntion to calculate and print the base64 encoded string
 *
 * @todo - later shift this to use openssl library rather than running
 * system command ...
 */
void base64Encode(char s[]) {
	char command[100];
	int x = sprintf(command, "echo \"%s\" | base64", s);
	system(command);
}

/**
 * Fucntion to calculate and print the base64 decoded string
 *
 * @todo - later shift this to use openssl library rather than running
 * system command ...
 */
void base64Decode(char s[]) {
	char command[100];
	int x = sprintf(command, "echo \"%s\" | base64 -D", s);
	system(command);
}

// ---- Declare Global Variables from here


/**
 * Main()
 */
int main(int argc, char *argv[]) {

	if (argc != 3) {
		// Means incorrect approach
		help();
		return 0;
	}

	if (!strcmp(argv[1],"-md5")) {
		// For md5 digest
		md5(argv[2]);
	} else if (!strcmp(argv[1],"-b64")) {
		// For both base64 encode & decode
		// Encode
		printf("-- base64 encode --\n");
		base64Encode(argv[2]);

		printf("-- base64 decode --\n");
		base64Decode(argv[2]);

	} else if (!strcmp(argv[1],"-b64E")) {
		// For base 64 encode
		base64Encode(argv[2]);

	} else if (!strcmp(argv[1],"-b64D")) {
		// for base 64 decode
		base64Decode(argv[2]);

	} else if (!strcmp(argv[1],"-a")) {
		// -- call each functions one by one!
		printf("-- MD5 --\n");
		md5(argv[2]);

		printf("-- base64 encode -- \n");
		base64Encode(argv[2]);

		printf("-- base64 decode --\n");
		base64Decode(argv[2]);

	}
	return 0;
}