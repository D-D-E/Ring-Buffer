/*
 * ring_buffer.c
 *
 *  Created on: Nov 19, 2019
 *      Author: dmitr
 */

#include "ring_buffer.h"

void RingBuffInit(ring_buffer *rng)
{
	rng->index_in = rng->index_out = 0;
}

void RingBuffPush(ring_buffer *rng, char element)
{
	rng->buffer[rng->index_in++] = element;
	rng->index_in &= BUF_MASK;
}

char RingBuffPop(ring_buffer *rng)
{
	char element = rng->buffer[rng->index_out++];
	rng->index_out &= BUF_MASK;
	return element;
}

uint8_t RingBuffIsEmpty(ring_buffer *rng)
{
	if (rng->index_in == rng->index_out)
	{
		return 1;
	}
	return 0;
}

void RingBuffClear(ring_buffer *rng)
{
	rng->buffer[0] = 0;
	rng->index_out = rng->index_in = 0;
}

uint8_t RingBuffLength(ring_buffer *rng)
{
	return (rng->index_in - rng->index_out) & BUF_MASK;
}

char * RingBuffGetArray(ring_buffer *rng)
{
	return ((char *)rng->buffer);
}

