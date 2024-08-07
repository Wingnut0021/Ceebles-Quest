#ifndef UTIL_PERFDELAY_H
#define UTIL_PERFDELAY_H

/** Performant delay function, use instead of delay.

    @param numloops   Number of loops to run per delay cycle.
*/
void perf_delay(uint8_t numloops);
void clear_sprite_data(uint8_t sprite_index);

#endif