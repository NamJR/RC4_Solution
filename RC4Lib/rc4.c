#include "rc4.h"

void rc4_init(RC4State *state, const uint8_t *key, size_t keylen) {
    uint8_t tmp;
    uint16_t j = 0; // dùng 16-bit để tránh tràn khi cộng
    for (int i = 0; i < 256; ++i)
        state->S[i] = i;

    state->i = 0;
    state->j = 0;

    for (int i = 0; i < 256; ++i) {
        j = (j + state->S[i] + key[i % keylen]) & 0xFF; // luôn modulo 256
        tmp = state->S[i];
        state->S[i] = state->S[j];
        state->S[j] = tmp;
    }
}

void rc4_crypt(RC4State *state, uint8_t *data, size_t len) {
    uint8_t tmp, K;

    for (size_t n = 0; n < len; ++n) {
        state->i = (state->i + 1) & 0xFF;
        state->j = (state->j + state->S[state->i]) & 0xFF;

        tmp = state->S[state->i];
        state->S[state->i] = state->S[state->j];
        state->S[state->j] = tmp;

        K = state->S[(state->S[state->i] + state->S[state->j]) & 0xFF];
        data[n] ^= K;
    }
}
