#ifndef RC4_H
#define RC4_H

#include <stddef.h>   // để dùng size_t
#include <stdint.h>   // để dùng uint8_t

// Cấu trúc lưu trạng thái RC4
typedef struct {
    uint8_t S[256];   // Hoán vị 256 phần tử
    uint8_t i;        // Bộ đếm i
    uint8_t j;        // Bộ đếm j
} RC4State;

// Khởi tạo RC4 với khóa (Key Scheduling Algorithm - KSA)
void rc4_init(RC4State *state, const uint8_t *key, size_t keylen);

// Mã hóa/Giải mã RC4 (Pseudo-Random Generation Algorithm - PRGA)
void rc4_crypt(RC4State *state, uint8_t *data, size_t len);

#endif // RC4_H
