//Nguyen Tung Duong - 0266
/*
Bài 1.1. Viết một chương trình C nhập vào 3 số nguyên.
Thiết lập một con trỏ để lần lượt trỏ tới từng số nguyên và
hiển thị kết quả giá trị tham chiếu ngược của con trỏ.
Lưu ý: Phép toán & trả về địa chỉ của biến.
*/

#include <stdio.h>

int main(){
    int x,y,z;
    printf("Enter three integers:\n");
    scanf("%d%d%d", &x, &y, &z);

    int* ptr;
    printf("The three integers are:\n");

    ptr = &x;
    printf("x = %d\n", *ptr);
    ptr = &y;
    printf("y = %d\n", *ptr);
    ptr = &z;
    printf("z = %d\n", *ptr);

    return 0;
}
//Nguyen Tung Duong - 0266
