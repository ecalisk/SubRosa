#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

void cipher(char *plain, int key);
void decipher(char *plain, int key);
void clear_stdin();

int main(void)
{

	int key;
	char plain[SIZE];
	char userChoice;

	printf("\nWelcome to SubRosa v0.1! SubRosa is a terminal-based, portable application to encrypt and decrypt messages. If you want to encrypt a plain text simply type 'e' and press enter. To decrypt, type 'd' and press enter. For more information about the program type 'i' and press enter.\n");

	userChoice = getchar();
	clear_stdin();
	switch (userChoice)
	{

	case 'e':

		printf("\n");

		printf("Please enter the plain text you want to encrypt\n");
		fgets(plain, SIZE, stdin);

		printf("\n");

		printf("Please enter the shift intiger:\n");
		scanf("%d", &key);

		printf("\n");

		printf("The encrypted text is:\n");
		cipher(plain, key);

		printf("\n");

		break;

	case 'd':

		printf("\n");

		printf("Please enter the ciphertext you want to decrypt:\n");
		fgets(plain, SIZE, stdin);

		printf("\n");

		printf("Please enter the shift intiger:\n");
		scanf("%d", &key);

		printf("\n");

		printf("The decrypted text is:\n");
		decipher(plain, key);

		printf("\n");

		break;

	case 'i':

		printf("\nWelcome to SubRosa v0.1! SubRosa is a terminal-based, portable application to encrypt and decrypt messages.\n\n");
		printf("What is more: SubRosa is an implementation of the well-known Ceaser cipher (aka the shift cipher), a symmetric encryption system. The algorithm follows a simple structure where characters of a given plain text is shifted key times in the ASCII. This, in return, turns important and vulnurable messages into scrambled, unreadable texts. Later this meaningless texts can be transformed back to their original states by people who know the key number by which the shift was applied.\n");
		break;

	default:
		printf("Invalid input! Program ended.\n");
	}
}

// Function to print the encrypted text
void cipher(char *plain, int key)
{

	char cipherChar;
	int cipherValue;
	int i = 0;

	while (plain[i] != '\0' && strlen(plain) - 1 > i)
	{
		cipherValue = ((int)plain[i] - 97 + key) % 26 + 97;
		cipherChar = (char)(cipherValue);

		printf("%c", cipherChar);
		i++;
	}
	printf("\n");
}

// Function to print the decrypted text
void decipher(char *plain, int key)
{

	char decipherChar;
	int decipherValue;
	int i = 0;

	while (plain[i] != '\0' && strlen(plain) - 1 > i)
	{
		decipherValue = ((int)plain[i] - 97 - key) % 26 + 97;
		decipherChar = (char)(decipherValue);

		printf("%c", decipherChar);
		i++;
	}
	printf("\n");
}

// Clears input buffer.
void clear_stdin()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		/* discard */;
}
