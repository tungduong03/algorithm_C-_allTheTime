#include <iostream>
#include <string>
#include <cryptopp/eccrypto.h>
#include <cryptopp/oids.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;

std::string EccEncrypt(const std::string& plaintext) {
    AutoSeededRandomPool rng;

    // Định nghĩa đường cong elliptic
    ECIES<ECP>::Encryptor encryptor;
    encryptor.AccessKey().Initialize(rng, ASN1::secp256r1());

    // Mã hóa plaintext
    std::string ciphertext;
    StringSource(plaintext, true, new PK_EncryptorFilter(rng, encryptor, new HexEncoder(new StringSink(ciphertext))));

    return ciphertext;
}

std::string EccDecrypt(const std::string& ciphertext) {
    AutoSeededRandomPool rng;

    // Định nghĩa đường cong elliptic
    ECIES<ECP>::Decryptor decryptor;
    decryptor.AccessKey().Initialize(rng, ASN1::secp256r1());

    // Giải mã ciphertext
    std::string decryptedtext;
    StringSource(ciphertext, true, new HexDecoder(new PK_DecryptorFilter(rng, decryptor, new StringSink(decryptedtext))));

    return decryptedtext;
}

int main() {
    // Plain text
    std::string plaintext = "H";

    // Mã hóa plaintext
    std::string ciphertext = EccEncrypt(plaintext);

    // Giải mã ciphertext
    std::string decryptedText = EccDecrypt(ciphertext);

    // In plaintext ban đầu và decrypted text
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
