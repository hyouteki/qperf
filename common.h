#pragma once

#include <quicly.h>
#include <stdbool.h>
#include <stdint.h>

ptls_context_t *get_tlsctx();

struct addrinfo *get_address(const char *host, const char *port);
bool send_pending(quicly_context_t *ctx, int fd, quicly_conn_t *conn);
void print_escaped(const char *src, size_t len);


static inline int64_t min_int64(int64_t a, int64_t b)
{
    if(a < b) {
        return a;
    } else {
        return b;
    }
}

static inline int64_t max_int64(int64_t a, int64_t b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

static inline int64_t clamp_int64(int64_t val, int64_t min, int64_t max)
{
    if(val < min) {
        return min;
    }
    if(val > max) {
        return max;
    }
    return val;
}
