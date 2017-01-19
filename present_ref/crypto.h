#ifndef __CRYPTO_H
#define __CRYPTO_H

#include <msp430.h>
#include <string.h>
#include <driverlib.h>

// Define basic parameters
#define CRYPTO_IN_SIZE  8 	// Present has 64-bit blocks
#define CRYPTO_KEY_SIZE 10  // Present has 80-bit key
#define CRYPTO_OUT_SIZE 8   // Present has 64-bit blocks

// Define bit manipulation inline functions
static inline uint8_t getbit(const uint8_t word, const uint8_t bit) {
	return (word >> bit) & 0x1;
	// or, if return value != 0 means: bit set
	// return (word & (1 << bit));
}

static inline void setbit(const uint8_t* word, const uinst8_t bit) {
	*word |= (1  << bit);
}

static inline void clrbit(const uint8_t* word, const uint8_t bit) {
	*word &= ~(1 << bit);
}


// The function to test
void crypto_func(uint8_t pt[CRYPTO_IN_SIZE], uint8_t key[CRYPTO_KEY_SIZE]);

void add_round_key(uint8_t pt[CRYPTO_IN_SIZE], uint8_t key[CRYPTO_IN_SIZE]);

void sbox_layer(uint8_t s[CRYPTO_IN_SIZE]);

void pbox_layer(uint8_t s[CRYPTO_IN_SIZE]);

#endif
