#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "rc4.h"

static int hex2bytes(const char *hex, uint8_t *out) {
    size_t len = strlen(hex);
    if (len % 2 != 0) return -1;
    for (size_t i = 0; i < len / 2; ++i) {
        sscanf(&hex[2*i], "%2hhx", &out[i]);
    }
    return (int)(len / 2);
}

int main(void) {
    const uint8_t key[] = "mysecretkey";
    const char *cipher_hex = "A2B216D7A9696BFEA97B5B4F892BB0C7293AC33A51C1164A27EE156737B9291E414FA9C62A36657ABF09";

    uint8_t buffer[512];
    int bytes = hex2bytes(cipher_hex, buffer);
    if (bytes < 0) {
        printf("Ciphertext hex không hợp lệ!\n");
        return 1;
    }

    RC4State state;
    rc4_init(&state, key, strlen((const char*)key));
    rc4_crypt(&state, buffer, bytes);
    buffer[bytes] = '\0';

    printf("Decrypted text: %s\n", buffer);
    return 0;
}
