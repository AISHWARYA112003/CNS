#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_LENGTH 256


void toUppercase(char *text) {
    while (*text) {
        *text = toupper((unsigned char)*text);
        text++;
    }
}


void preprocessText(char *text) {
    char *src = text, *dst = text;
    while (*src) {
        if (isalpha((unsigned char)*src)) {
            *dst++ = toupper((unsigned char)*src);
        }
        src++;
    }
    *dst = '\0';
}


void encryptVigenere(char *plaintext, char *key, char *ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < textLen; i++) {
        if (isalpha((unsigned char)plaintext[i])) {
            char shift = toupper((unsigned char)key[j % keyLen]) - 'A';
            ciphertext[i] = (toupper((unsigned char)plaintext[i]) - 'A' + shift) % ALPHABET_SIZE + 'A';
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}


void decryptVigenere(char *ciphertext, char *key, char *plaintext) {
    int textLen = strlen(ciphertext);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < textLen; i++) {
        if (isalpha((unsigned char)ciphertext[i])) {
            char shift = toupper((unsigned char)key[j % keyLen]) - 'A';
            plaintext[i] = (toupper((unsigned char)ciphertext[i]) - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE + 'A';
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char key[MAX_LENGTH];
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char decryptedText[MAX_LENGTH];


    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    // Remove newline character if present
    size_t len = strlen(key);
    if (len > 0 && key[len - 1] == '\n') {
        key[len - 1] = '\0';
    }


    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    // Remove newline character if present
    len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    toUppercase(key);
    preprocessText(plaintext);

  
    encryptVigenere(plaintext, key, ciphertext);
    printf("Encr+ypted message: %s\n", ciphertext);

    decryptVigenere(ciphertext, key, decryptedText);
    printf("Decrypted message: %s\n", decryptedText);

    return 0;
}
