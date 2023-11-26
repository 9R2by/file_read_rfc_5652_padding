#ifndef LEA_H
#define LEA_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <x86intrin.h>

#define ARRAY_WIDTH UINT8_C(4)
#define ROUNDS UINT8_C(24)
#define ROUNDKEY_ARRAY_SIZE UINT8_C(ROUNDS * ARRAY_WIDTH)

/* pre generated roundkeys from the key:
* 253635900 1264216440 2274796980 3285377520
*/
#define ROUNDKEYS {0x003a0fd4, 0x02497010, 0x194f7db1,      \
0x090d0883, 0x11fdcbb1, 0x9e98e0c8, 0x18b570cf, 0x9dc53a79, \
0xf30f7bb5, 0x6d6628db, 0xb74e5dad, 0xa65e46d0, 0x74120631, \
0xdac9bd17, 0xcd1ecf34, 0x540f76f1, 0x662147db, 0xc637c47a, \
0x46518932, 0x23269260, 0xe4dd5047, 0xf694285e, 0xe1c2951d, \
0x8ca5242c, 0xbaf8e5ca, 0x3e936cd7, 0x0fc7e5b1, 0xf1c8fa8c, \
0x5522b80c, 0xee22ca78, 0x8a6fa8b3, 0x65637b74, 0x8a19279e, \
0x6fb40ffe, 0x85c5f092, 0x92cc9f25, 0x9dde584c, 0xcb00c87f, \
0x4780ad66, 0xe61b5dcb, 0x4fa10466, 0xf728e276, 0xd255411b, \
0x656839ad, 0x9250d058, 0x51bd501f, 0x1cb40dae, 0x1abf218d, \
0x21dd192d, 0x77c644e2, 0xcabfaa45, 0x681c207d, 0xde7ac372, \
0x9436afd0, 0x10331d80, 0xf326fe98, 0xfb3ac3d4, 0x93df660e, \
0x2f65d8a3, 0xdf92e761, 0x27620087, 0x265ef76e, 0x4fb29864, \
0x2656ed1a, 0x227b88ec, 0xd0b3fa6f, 0xc86a08fd, 0xa864cba9, \
0xf1002361, 0xe5e85fc3, 0x1f0b0408, 0x488e7ac4, 0xc65415d5, \
0x51e176b6, 0xeca88bf9, 0xedb89ece, 0x9b6fb99c, 0x0548254b, \
0x8de9f7c2, 0xb6b4d146, 0x7257f134, 0x06051a42, 0x36bcef01, \
0xb649d524, 0xa540fb03, 0x34b196e6, 0xf7c80dad, 0x71bc7dc4, \
0x8fbee745, 0xcf744123, 0x907c0a60, 0x8215ec35, 0x0bf6adba, \
0xdf69029d, 0x5b72305a, 0xcb47c19f }

#define rotateLeftBy9(x) _rotl(x, 9)
#define rotateRightBy5(x) _rotr(x, 5)
#define rotateRightBy3(x) _rotr(x, 3)
#define rotateRightBy9(x) _rotr(x, 9)
#define rotateLeftBy5(x) _rotl(x, 5)
#define rotateLeftBy3(x) _rotl(x, 3)
#define endian_conversion(x) __asm__ volatile ("bswap %0" : "+r" (x))

void lea_encrypt(uint8_t buffer[16]);
void lea_decrypt(uint8_t buffer[16]);

#endif //LEA_H
