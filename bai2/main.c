#include "stm32f10x.h"
#include "max7219.h"

// Mảng hình tròn rỗng
const uint8_t circle[8] = {
    0x3C,
    0x42,
    0x81,
    0x81,
    0x81,
    0x81,
    0x42,
    0x3C
};

int main(void) {
    SystemInit();
    
    // Delay khởi động chờ ổn định nguồn
    for(volatile int i = 0; i < 500000; i++);

    MAX7219_Init();

    // Xuất ra 8 dòng của ma trận
    for (int i = 0; i < 8; i++) {
        MAX7219_Write(i + 1, circle[i]);
    }

    while (1) {
        // Hoàn tất hiển thị
    }
}
