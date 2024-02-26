#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_LENGTH 26
void generateRandomKey(char *key);
void encryptMessage(char *message, char *key);
void decryptMessage(char *message, char *key);
int main() {
    char key[ALPHABET_LENGTH + 1];
    char message[100];
    int choice;
	printf("Enter the message to encrypt/decrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    generateRandomKey(key);

    printf("Generated key: %s\n", key);

    printf("Choose operation:\n");
    printf("1. Encrypt\n");#include <stdio.h>

int main() {
    long long int num_possible_keys = 1;
    int i;

    // Calculate the number of possible keys
    for (i = 26; i >= 22; i--) {
        num_possible_keys *= i;
    }

    // Account for the remaining letters of the alphabet to fill the key matrix
    num_possible_keys *= 21 * 20 * 19 * 18 * 17 / (5 * 4 * 3 * 2 * 1);

    printf("Approximate number of possible keys for Playfair cipher: %lld\n", num_possible_keys);

    return 0;
}

    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encryptMessage(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decryptMessage(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

void generateRandomKey(char *key) {
    char temp[ALPHABET_LENGTH + 1] = "abcdefghijklmnopqrstuvwxyz";
    int i, j;
    for (i = 0; i < ALPHABET_LENGTH; ++i) {
        j = rand() % ALPHABET_LENGTH;
        char tempChar = temp[i];
        temp[i] = temp[j];
        temp[j] = tempChar;
    }

    strcpy(key, temp);
}

void encryptMessage(char *message, char *key) {
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = key[message[i] - 'a'];
            } else {
                message[i] = toupper(key[tolower(message[i]) - 'a']);
            }
        }
    }
}

void decryptMessage(char *message, char *key) {
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = 'a' + (strchr(key, message[i]) - key);
            } else {
                message[i] = toupper('a' + (strchr(key, tolower(message[i])) - key));
            }
        }
    }
}
