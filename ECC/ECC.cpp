#include <iostream>
#include <string>
#include <cmath>

// Định nghĩa lớp điểm trên đường cong Elliptic
class ECPoint {
public:
    int x, y; // Tọa độ (x, y) của điểm trên đường cong
    int a, b; // Tham số đường cong Elliptic: y^2 = x^3 + ax + b

    ECPoint(int x, int y, int a, int b) {
        this->x = x;
        this->y = y;
        this->a = a;
        this->b = b;
    }

    bool operator==(const ECPoint& other) const {
        return (x == other.x && y == other.y && a == other.a && b == other.b);
    }
};

// Phép cộng hai điểm trên đường cong Elliptic
ECPoint ECAdd(const ECPoint& P, const ECPoint& Q) {
    int a = P.a;
    int b = P.b;

    int m;
    if (P == Q) {
        m = (3 * std::pow(P.x, 2) + a) * (2 * P.y);
        m %= 26;
    }
    else {
        m = (Q.y - P.y) * (Q.x - P.x);
        m %= 26;
    }

    int x = ((m * m) - P.x - Q.x) % 26;
    int y = (m * (P.x - x) - P.y) % 26;

    return ECPoint(x, y, a, b);
}

// Phép nhân điểm với một số nguyên trên đường cong Elliptic
ECPoint ECMultiply(const ECPoint& P, int n) {
    ECPoint result = P;
    n--;
    while (n > 0) {
        result = ECAdd(result, P);
        n--;
    }
    return result;
}

// Mã hóa plaintext
ECPoint Encrypt(const std::string& plaintext, int publicKey) {
    // Tham số đường cong Elliptic: y^2 = x^3 + ax + b
    int a = 2;
    int b = 2;

    // Điểm cơ sở trên đường cong
    ECPoint basePoint(0, 1, a, b);

    // Tính điểm plaintext từ plain text
    int x = plaintext[0] - 'A';

    // Tính điểm ciphertext
    ECPoint ciphertext = ECMultiply(basePoint, publicKey);
    ECPoint plaintextPoint = ECAdd(ciphertext, ECMultiply(basePoint, x));

    return plaintextPoint;
}

// Giải mã ciphertext
std::string Decrypt(const ECPoint& ciphertext, int privateKey) {
    // Tham số đường cong Elliptic: y^2 = x^3 + ax + b
    int a = 2;
    int b = 2;

    // Điểm cơ sở trên đường cong
    ECPoint basePoint(0, 1, a, b);

    // Tính điểm plaintext
    ECPoint decryptedPoint = ECAdd(ciphertext, ECMultiply(basePoint, -privateKey));

    // Chuyển đổi tọa độ điểm thành plaintext
    int x = decryptedPoint.x;
    char plaintext = 'A' + x;

    return std::string(1, plaintext);
}

int main() {
    // Plain text
    std::string plaintext = "H";

    // Khóa công khai và khóa bí mật
    int publicKey = 5;
    int privateKey = 5;

    // Mã hóa plaintext
    ECPoint ciphertext = Encrypt(plaintext, publicKey);

    // Giải mã ciphertext
    std::string decryptedText = Decrypt(ciphertext, privateKey);

    // In plaintext ban đầu và decrypted text
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
