#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "rc4.h"

// Hàm in dữ liệu dưới dạng HEX
static void print_hex(const uint8_t *buf, size_t len) {
    for (size_t i = 0; i < len; ++i)
        printf("%02X", buf[i]);
    printf("\n");
}

int main(void) {
    const uint8_t key[] = "mysecretkey";
    const char *plaintext = "Hanoi University of Science and Technology";
    size_t len = strlen(plaintext);

    uint8_t buffer[512];
    memcpy(buffer, plaintext, len);

    RC4State state;
    rc4_init(&state, key, strlen((const char*)key));
    rc4_crypt(&state, buffer, len);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext (hex): ");
    print_hex(buffer, len);

    return 0;
}
