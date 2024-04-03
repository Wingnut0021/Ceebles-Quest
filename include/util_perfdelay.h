#ifndef UTIL_PERFDELAY_H
#define UTIL_PERFDELAY_H

/** Performant delay function, use instead of delay.

    @param numloop   Number of loops to run per delay cycle, faster than standard delay.
*/
void perf_delay(UINT8 numloops);

#endif