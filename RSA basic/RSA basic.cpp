#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to calculate modular inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 1;
}

// RSA encryption function
int encrypt(int plainText, int publicKey, int modulus) {
    return fmod(pow(plainText, publicKey), modulus);
}

// RSA decryption function
int decrypt(int cipherText, int privateKey, int modulus) {
    return fmod(pow(cipherText, privateKey), modulus);
}

int main() {
    int p, q, e; // p and q are prime numbers, e is the public key
    int plaintext, encrypted, decrypted; // variables for input, encrypted and decrypted values

    std::cout << "Enter two prime numbers (p and q): ";
    std::cin >> p >> q;

    // Check if p and q are prime
    if (!isPrime(p) || !isPrime(q)) {
        std::cout << "Both numbers must be prime.\n";
        return 0;
    }

    int n = p * q; // Calculate modulus (n)
    int phi = (p - 1) * (q - 1); // Calculate Euler's totient function (phi)

    // Find public key (e)
    std::cout << "Enter a number (public key) less than phi(" << phi << ") and co-prime with it: ";
    std::cin >> e;

    // Check if e and phi are co-prime
    if (gcd(e, phi) != 1) {
        std::cout << "The public key must be co-prime with phi.\n";
        return 0;
    }

    // Find private key (d)
    int d = modInverse(e, phi);

    std::cout<<d<<std::endl;

    std::cout << "Enter a number to encrypt: ";
    std::cin >> plaintext;

    // Encrypt the plaintext
    encrypted = encrypt(plaintext, e, n);
    std::cout << "Encrypted: " << encrypted << std::endl;

    // Decrypt the ciphertext
    decrypted = decrypt(encrypted, d, n);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}

