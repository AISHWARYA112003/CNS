#include <stdio.h>
#include <string.h>

// Function to perform Caesar Cipher encryption/decryption
void caesar(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        // Check if the character is a lowercase letter
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + shift + 26) % 26;
        }
        // Check if the character is an uppercase letter
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + shift + 26) % 26;
        }
    }
}

int main() {
    char message[256];
    int key;

    // Prompt the user for a message
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Prompt the user for the key
    printf("Enter the key: ");
    scanf("%d", &key);

    // Remove the newline character from the message if present
    size_t len = strlen(message);
    if (len > 0 && message[len-1] == '\n') {
        message[len-1] = '\0';
    }

    // Print the original message
    printf("Original message: %s\n", message);

    // Encrypt the message
    caesar(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    caesar(message, -key);
    printf("Decrypted message: %s\n", message);

    return 0;
}
