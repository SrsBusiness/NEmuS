#ifndef UTIL_H
#define UTIL_H

static inline int set_SR_N(uint8_t val) {
    return (val & 0x80) >> 7;
}

static inline int set_SR_Z(uint8_t val) {
    return (val & 0xff) == 0;
}

#endif
