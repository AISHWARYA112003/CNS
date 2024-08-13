#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<openssl/aes.h>
unsigned char aes_key[] = "0123456789abcdef";
void aes_encrypt(unsigned char* plaintext, unsigned char* ciphertext) {
AES_KEY key;
AES_set_encrypt_key(aes_key, 128, &key);
AES_encrypt(plaintext, ciphertext, &key);
}
void aes_decrypt(unsigned char* plaintext, unsigned char* ciphertext) {
AES_KEY key;
AES_set_decrypt_key(aes_key, 128, &key);
AES_decrypt(plaintext, ciphertext, &key);
}
int main() {
unsigned char plaintext[] = "welcome to ISE";
unsigned char ciphertext[AES_BLOCK_SIZE];
unsigned char decryptedtext[AES_BLOCK_SIZE];
aes_encrypt(plaintext, ciphertext);
printf("Original message: %s\n", plaintext);
printf("Encrypted message: ");
for(int i = 0; i < AES_BLOCK_SIZE; i++) {
printf("%02x", ciphertext[i]);
}
printf("\n");
aes_decrypt(ciphertext, decryptedtext);
printf("Decrypted message: %s\n", decryptedtext);
return 0;
}
