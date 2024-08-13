#include<stdio.h>
#include<math.h>


long long int power(long long int a, long long int b, long long int p) {
    long long int result = 1;
    a = a % p;
  
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % p;
        }
        b = b >> 1;  // b = b / 2
        a = (a * a) % p;
    }
    return result;
}

int main() {
    long long int P, G, x, a, b, y, ka, kb;
    
    printf("Enter the value of P (prime number): ");
    scanf("%lld", &P);
    printf("Enter the value of G (prime number): ");
    scanf("%lld", &G);
    printf("Enter the private key of Alice: ");
    scanf("%lld", &a); 
    printf("Enter the private key of Bob: ");
    scanf("%lld", &b);  
    

    x = power(G, a, P); 
    y = power(G, b, P);  
    

    ka = power(y, a, P);  
    kb = power(x, b, P); 
    
    printf("Public key of Alice (x): %lld\n", x);
    printf("Public key of Bob (y): %lld\n", y);
    printf("Secret key calculated by Alice: %lld\n", ka);
    printf("Secret key calculated by Bob: %lld\n", kb);
    
    return 0;
}
