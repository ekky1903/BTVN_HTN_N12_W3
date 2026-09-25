#include "stm32f10x.h"
#include "max7219.h"


const uint8_t triangle[8] = {
    0x00, // 00000000 
    0x18, // 00011000 (Hàng 2: Đỉnh tam giác rộng 2 chấm)
    0x3C, // 00111100 (Hàng 3)
    0x7E, // 01111110 (Hàng 4)
    0xFF, // 11111111 (Hàng 5: Đáy tam giác)
    0x00, // 00000000 (Hàng 6: Trống)
    0x00, // 00000000 
    0x00  // 00000000 
};

int main(void) {
    SystemInit();
    
    // Delay khởi động chờ ổn định nguồn
    for (volatile int i = 0; i < 500000; i++);

    MAX7219_Init();

    // Xuất 8 byte dữ liệu ra 8 dòng của ma trận LED
    for (int i = 0; i < 8; i++) {
        MAX7219_Write(i + 1, triangle[i]);
    }

    while (1) {
        // Chip đã chốt dữ liệu, CPU nghỉ ngơi
    }
}
