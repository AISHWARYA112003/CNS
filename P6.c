#include<stdio.h>


long long int power(long long int base, long long int exp, long long int modulus) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}

long long int encrypt(long long int plaintext, long long int e, long long int n) {
    return power(plaintext, e, n);
}

// Function to perform RSA decryption
long long int decrypt(long long int ciphertext, long long int d, long long int n) {
    return power(ciphertext, d, n);
}


long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


long long int modInverse(long long int e, long long int phi) {
    long long int m0 = phi, t, q;
    long long int x0 = 0, x1 = 1;

    if (phi == 1)
        return 0;


    while (e > 1) {
        q = e / phi;
        t = phi;

        phi = e % phi;
        e = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {

    long long int p, q;
    printf("Enter prime number p: ");
    scanf("%lld", &p);
    printf("Enter prime number q: ");
    scanf("%lld", &q);

  
    long long int n = p * q;
    long long int phi = (p - 1) * (q - 1);


    long long int e;
    printf("Enter public exponent e (such that 1 < e < phi and e is coprime to phi): ");
    scanf("%lld", &e);

    while (gcd(e, phi) != 1) {
        printf("e is not coprime with phi. Enter another value for e: ");
        scanf("%lld", &e);
    }

 
    long long int d = modInverse(e, phi);

    long long int plaintext;
    printf("Enter plaintext message (number less than %lld): ", n);
    scanf("%lld", &plaintext);

    
    if (plaintext >= n) {
        printf("Plaintext too large! It must be less than %lld.\n", n);
        return 1;
    }

  
    long long int ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted message: %lld\n", ciphertext);


    long long int decryptedtext = decrypt(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decryptedtext);

    return 0;
}
