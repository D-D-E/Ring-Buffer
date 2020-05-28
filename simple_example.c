#include <stdio.h>
#include "ring_buffer.h"

int main(void)
{
	ring_buffer rng;
	RingBuffInit(&rng);

	RingBuffPush(&rng, 'A');
	RingBuffPush(&rng, 'B');
	RingBuffPush(&rng, 'C');
	RingBuffPush(&rng, '\0'); //for printf %s

	printf("%s, %u \n", RingBuffGetArray(&rng), RingBuffLength(&rng));

	return 1;
}