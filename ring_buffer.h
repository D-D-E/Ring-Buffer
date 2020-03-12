#ifndef RING_BUFFER_RING_BUFFER_H_
#define RING_BUFFER_RING_BUFFER_H_
#include "stdint.h"

#define BUF_SIZE 4096
#define BUF_MASK (BUF_SIZE-1)

typedef struct ring_buffer_struct {
	uint16_t index_in, index_out;
	char buffer[BUF_SIZE];
}ring_buffer;

void RingBuffInit();

void RingBuffPush(ring_buffer *rng, char element);
char RingBuffPop(ring_buffer *rng);

uint8_t RingBuffIsEmpty(ring_buffer *rng);
void RingBuffClear(ring_buffer *rng);

uint8_t RingBuffLength(ring_buffer *rng);
char * RingBuffGetArray(ring_buffer *rng);

#endif /* RING_BUFFER_RING_BUFFER_H_ */