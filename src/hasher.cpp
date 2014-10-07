#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cstdlib>

// openssl libraries
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <openssl/md2.h>
#include <openssl/md4.h>
#include <openssl/md5.h>

using namespace std;

// Global definations
#define MOD 1000000007
#define rec(i, n) for(int i = 0; i < n; i++)
#define max(a,b) ((a)>(b))?(a):(b)
#define u unsigned
#define NEWLINE printf("\n")

// Global functions

/**
 * Function to print all the help message
 */
void help() {
	printf("--- HAHSER BY HECTOR09 ---\n");
	printf("For correct usage use one of the following commands\n");
	printf("\thasher -h : for help \n");
	printf("\thasher -a <string> : to calculate all type of listed hashes \n");
	printf("\thasher -md5 <string> : to calculate md5 digest \n");
	printf("\thasher -md4 <string> : to calculate md4 digest \n");
	printf("\thasher -md2 <string> : to calculate md2 digest \n");
	printf("\thasher -b64 <string> : to calculate both base64 encoded & decoded string \n");
	printf("\thasher -b64E <string> : to calculate base64 encoded string \n");
	printf("\thasher -b64D <string> : to calculate base64 decoded string \n");
	printf("\thasher -sha1 <string> : to calculate sha1 of the string \n");
	printf("\thasher -sha256 <string> : to calculate sah256 of the string \n");
	printf("\thasher -sha512 <string> : to calculate sha512 of the string \n");
	// -- examples
	printf("\tExample: hasher -md5 hector\n");
}

// Function to calculate and print the md5 digest of the input string
void md5(char s[]) {
	int length = strlen(s);
	unsigned char digest[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, s, length);
    MD5_Final(digest, &ctx);
 
    char mdString[33];
    for (int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
 
    printf("md5: %s\n", mdString);
}

// Function to calculate and print the md5 digest of the input string
void md4(char s[]) {
	int length = strlen(s);
	unsigned char digest[16];
    MD4_CTX ctx;
    MD4_Init(&ctx);
    MD4_Update(&ctx, s, length);
    MD4_Final(digest, &ctx);
 
    char mdString[33];
    for (int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
 
    printf("md4: %s\n", mdString);
}

// Function to calculate and print the md5 digest of the input string
void md2(char s[]) {
	int length = strlen(s);
	unsigned char digest[16];
    MD2_CTX ctx;
    MD2_Init(&ctx);
    MD2_Update(&ctx, (const unsigned char *)s, length);
    MD2_Final(digest, &ctx);
 
    char mdString[33];
    for (int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
 
    printf("md2: %s\n", mdString);
}

// Function to compute sha-1 hash of the given string
void sha1(char s[]) {
	int len = strlen(s);
	unsigned char digest[20];
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, (const unsigned char *)s, len);
	SHA1_Final(digest, &ctx);

	char shaString[41];
    for (int i = 0; i < 20; i++)
        sprintf(&shaString[i*2], "%02x", (unsigned int)digest[i]);

	printf("SHA-1: %s\n", shaString);
}

// Function to compute sha256 hash of the given string
void sha256(char s[]) {
	int len = strlen(s);
	unsigned char digest[32];
	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, (const unsigned char *)s, len);
	SHA256_Final(digest, &ctx);

	char shaString[65];
    for (int i = 0; i < 32; i++)
        sprintf(&shaString[i*2], "%02x", (unsigned int)digest[i]);

	printf("SHA256: %s\n", shaString);
}

// Function to compute sha256 hash of the given string
void sha512(char s[]) {
	int len = strlen(s);
	unsigned char digest[64];
	SHA512_CTX ctx;
	SHA512_Init(&ctx);
	SHA512_Update(&ctx, (const unsigned char *)s, len);
	SHA512_Final(digest, &ctx);

	char shaString[128];
    for (int i = 0; i < 64; i++)
        sprintf(&shaString[i*2], "%02x", (unsigned int)digest[i]);

	printf("SHA512: %s\n", shaString);
}


// Function to calculate and print the base64 encoded string
void base64Encode(char s[]) {
	printf("base64 encode: ");
	BIO *bio, *b64;
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_fp(stdout, BIO_NOCLOSE);
	BIO_push(b64, bio);
	BIO_write(b64, s, strlen(s));
	BIO_flush(b64);
	BIO_free_all(b64);
}

/**
 * Function to calculate and print the base64 decoded string
 *
 * @todo - make it working with base64 values, currently showing bogus result
 */
void base64Decode(char s[]) {
	int length = strlen(s);
	printf("base64 decode: ");

	BIO *b64, *bmem;
	char buffer[length];

	b64 = BIO_new(BIO_f_base64());
	bmem = BIO_new_mem_buf(s, length);
	bmem = BIO_push(b64, bmem);

	BIO_read(bmem, buffer, length);
	BIO_free_all(bmem);

	printf("%s\n", buffer);
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

	if (!strcmp(argv[1], "-md5")) {
		// For md5 digest
		md5(argv[2]);
	} else if (!strcmp(argv[1], "-md4")) {
		md4(argv[2]);
	} else if (!strcmp(argv[1], "-md2")) {
		md2(argv[2]);
	} else if (!strcmp(argv[1], "-b64")) {

		// For both base64 encode & decode
		base64Encode(argv[2]);
		base64Decode(argv[2]);

	} else if (!strcmp(argv[1], "-b64E")) {
		// For base 64 encode
		base64Encode(argv[2]);

	} else if (!strcmp(argv[1], "-b64D")) {
		// for base 64 decode
		base64Decode(argv[2]);

	} else if (!strcmp(argv[1], "-sha1")) {
		// for base sha1
		sha1(argv[2]);

	} else if (!strcmp(argv[1], "-sha256")) {
		// for base sha 256
		sha256(argv[2]);

	} else if (!strcmp(argv[1], "-sha512")) {
		// for sha 512
		sha512(argv[2]);

	}  else if (!strcmp(argv[1], "-a")) {
		// -- call each functions one by one!
		md5(argv[2]);
		md4(argv[2]);
		md2(argv[2]);
		base64Encode(argv[2]);
		base64Decode(argv[2]);

		sha1(argv[2]);
		sha256(argv[2]);
		sha512(argv[2]);

	} else {
		help();
	}
	return 0;
}