#include "lea.h"


/**
 *
 * @param uint8_t buffer 16
 */
void lea_encrypt(uint8_t buffer[16]) {
    uint8_t b0[4], b1[4], b2[4], b3[4];
    uint32_t x0, x1, x2, x3;
    uint32_t roundkey_arr[ROUNDKEY_ARRAY_SIZE] = ROUNDKEYS;
    uint32_t tmp;

    memcpy(b0, buffer, 4);
    memcpy(b1, buffer + 4, 4);
    memcpy(b2, buffer + 8, 4);
    memcpy(b3, buffer + 12, 4);

    x0 = (b0[0] << 24) | (b0[1] << 16) | (b0[2] << 8) | b0[3];
    x1 = (b1[0] << 24) | (b1[1] << 16) | (b1[2] << 8) | b1[3];
    x2 = (b2[0] << 24) | (b2[1] << 16) | (b2[2] << 8) | b2[3];
    x3 = (b3[0] << 24) | (b3[1] << 16) | (b3[2] << 8) | b3[3];

    endian_conversion(x0);
    endian_conversion(x1);
    endian_conversion(x2);
    endian_conversion(x3);

    //round 1
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[0]) + (x1 ^ roundkey_arr[1]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[2]) + (x2 ^ roundkey_arr[1]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[3]) + (x3 ^ roundkey_arr[1]));
    x3 = tmp;

    //round 2
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[4]) + (x1 ^ roundkey_arr[5]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[6]) + (x2 ^ roundkey_arr[5]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[7]) + (x3 ^ roundkey_arr[5]));
    x3 = tmp;

    //round 3
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[8]) + (x1 ^ roundkey_arr[9]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[10]) + (x2 ^ roundkey_arr[9]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[11]) + (x3 ^ roundkey_arr[9]));
    x3 = tmp;

    //round 4
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[12]) + (x1 ^ roundkey_arr[13]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[14]) + (x2 ^ roundkey_arr[13]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[15]) + (x3 ^ roundkey_arr[13]));
    x3 = tmp;

    //round 5
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[16]) + (x1 ^ roundkey_arr[17]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[18]) + (x2 ^ roundkey_arr[17]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[19]) + (x3 ^ roundkey_arr[17]));
    x3 = tmp;

    //round 6
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[20]) + (x1 ^ roundkey_arr[21]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[22]) + (x2 ^ roundkey_arr[21]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[23]) + (x3 ^ roundkey_arr[21]));
    x3 = tmp;

    //round 7
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[24]) + (x1 ^ roundkey_arr[25]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[26]) + (x2 ^ roundkey_arr[25]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[27]) + (x3 ^ roundkey_arr[25]));
    x3 = tmp;

    //round 8
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[28]) + (x1 ^ roundkey_arr[29]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[30]) + (x2 ^ roundkey_arr[29]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[31]) + (x3 ^ roundkey_arr[29]));
    x3 = tmp;

    //round 9
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[32]) + (x1 ^ roundkey_arr[33]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[34]) + (x2 ^ roundkey_arr[33]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[35]) + (x3 ^ roundkey_arr[33]));
    x3 = tmp;

    //round 10
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[36]) + (x1 ^ roundkey_arr[37]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[38]) + (x2 ^ roundkey_arr[37]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[39]) + (x3 ^ roundkey_arr[37]));
    x3 = tmp;

    //round 11
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[40]) + (x1 ^ roundkey_arr[41]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[42]) + (x2 ^ roundkey_arr[41]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[43]) + (x3 ^ roundkey_arr[41]));
    x3 = tmp;

    //round 12
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[44]) + (x1 ^ roundkey_arr[45]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[46]) + (x2 ^ roundkey_arr[45]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[47]) + (x3 ^ roundkey_arr[45]));
    x3 = tmp;

    //round 13
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[48]) + (x1 ^ roundkey_arr[49]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[50]) + (x2 ^ roundkey_arr[49]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[51]) + (x3 ^ roundkey_arr[49]));
    x3 = tmp;

    //round 14
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[52]) + (x1 ^ roundkey_arr[53]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[54]) + (x2 ^ roundkey_arr[53]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[55]) + (x3 ^ roundkey_arr[53]));
    x3 = tmp;

    //round 14
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[56]) + (x1 ^ roundkey_arr[57]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[58]) + (x2 ^ roundkey_arr[57]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[59]) + (x3 ^ roundkey_arr[57]));
    x3 = tmp;

    //round 15
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[60]) + (x1 ^ roundkey_arr[61]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[62]) + (x2 ^ roundkey_arr[61]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[63]) + (x3 ^ roundkey_arr[61]));
    x3 = tmp;

    //round 16
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[64]) + (x1 ^ roundkey_arr[65]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[66]) + (x2 ^ roundkey_arr[65]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[67]) + (x3 ^ roundkey_arr[65]));
    x3 = tmp;

    //round 17
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[68]) + (x1 ^ roundkey_arr[69]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[70]) + (x2 ^ roundkey_arr[69]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[71]) + (x3 ^ roundkey_arr[69]));
    x3 = tmp;

    //round 18
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[72]) + (x1 ^ roundkey_arr[73]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[74]) + (x2 ^ roundkey_arr[73]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[75]) + (x3 ^ roundkey_arr[73]));
    x3 = tmp;


    //round 19
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[76]) + (x1 ^ roundkey_arr[77]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[78]) + (x2 ^ roundkey_arr[77]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[79]) + (x3 ^ roundkey_arr[77]));
    x3 = tmp;

    //round 20
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[80]) + (x1 ^ roundkey_arr[81]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[82]) + (x2 ^ roundkey_arr[81]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[83]) + (x3 ^ roundkey_arr[81]));
    x3 = tmp;

    //round 21
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[84]) + (x1 ^ roundkey_arr[85]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[86]) + (x2 ^ roundkey_arr[85]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[87]) + (x3 ^ roundkey_arr[85]));
    x3 = tmp;

    //round 22
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[88]) + (x1 ^ roundkey_arr[89]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[90]) + (x2 ^ roundkey_arr[89]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[91]) + (x3 ^ roundkey_arr[89]));
    x3 = tmp;

    //round 23
    tmp = x0;
    x0 = rotateLeftBy9((x0 ^ roundkey_arr[92]) + (x1 ^ roundkey_arr[93]));
    x1 = rotateRightBy5((x1 ^ roundkey_arr[94]) + (x2 ^ roundkey_arr[93]));
    x2 = rotateRightBy3((x2 ^ roundkey_arr[95]) + (x3 ^ roundkey_arr[93]));
    x3 = tmp;


    memcpy(buffer, &x0, sizeof(uint32_t));
    memcpy(buffer + sizeof(uint32_t), &x1, sizeof(uint32_t));
    memcpy(buffer + 2 * sizeof(uint32_t), &x2, sizeof(uint32_t));
    memcpy(buffer + 3 * sizeof(uint32_t), &x3, sizeof(uint32_t));

    endian_conversion(x0);
    endian_conversion(x1);
    endian_conversion(x2);
    endian_conversion(x3);

}


void lea_decrypt(uint8_t buffer[16]) {
    uint32_t rk_arr[ROUNDKEY_ARRAY_SIZE] = ROUNDKEYS;
    uint8_t b0[4], b1[4], b2[4], b3[4];
    uint32_t xi0, xi1, xi2, xi3, x0, x1, x2, x3;

    memcpy(b0, buffer, 4);
    memcpy(b1, buffer + 4, 4);
    memcpy(b2, buffer + 8, 4);
    memcpy(b3, buffer + 12, 4);

    x0 = (b0[0] << 24) | (b0[1] << 16) | (b0[2] << 8) | b0[3];
    x1 = (b1[0] << 24) | (b1[1] << 16) | (b1[2] << 8) | b1[3];
    x2 = (b2[0] << 24) | (b2[1] << 16) | (b2[2] << 8) | b2[3];
    x3 = (b3[0] << 24) | (b3[1] << 16) | (b3[2] << 8) | b3[3];

    endian_conversion(x0);
    endian_conversion(x1);
    endian_conversion(x2);
    endian_conversion(x3);

    //round 1
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (x3 ^ rk_arr[92])) ^ rk_arr[93];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[94])) ^ rk_arr[93];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[95])) ^ rk_arr[93];

    //round 2
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[88])) ^ rk_arr[89];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[90])) ^ rk_arr[89];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[91])) ^ rk_arr[89];

    //round 3
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[84])) ^ rk_arr[85];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[86])) ^ rk_arr[85];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[87])) ^ rk_arr[85];

    //round 4
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[80])) ^ rk_arr[81];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[82])) ^ rk_arr[81];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[83])) ^ rk_arr[81];

    //round 5
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[76])) ^ rk_arr[77];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[78])) ^ rk_arr[77];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[79])) ^ rk_arr[77];


    //round 6
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[72])) ^ rk_arr[73];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[74])) ^ rk_arr[73];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[75])) ^ rk_arr[73];

    //round 7
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[68])) ^ rk_arr[69];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[70])) ^ rk_arr[69];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[71])) ^ rk_arr[69];

    //round 8
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[64])) ^ rk_arr[65];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[66])) ^ rk_arr[65];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[67])) ^ rk_arr[65];

    //round 9
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[60])) ^ rk_arr[61];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[62])) ^ rk_arr[61];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[63])) ^ rk_arr[61];

    //round 10
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[56])) ^ rk_arr[57];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[58])) ^ rk_arr[57];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[59])) ^ rk_arr[57];

    //round 11
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[52])) ^ rk_arr[53];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[54])) ^ rk_arr[53];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[55])) ^ rk_arr[53];

    //round 12
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[48])) ^ rk_arr[49];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[50])) ^ rk_arr[49];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[51])) ^ rk_arr[49];

    //round 13
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[44])) ^ rk_arr[45];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[46])) ^ rk_arr[45];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[47])) ^ rk_arr[45];

    //round 14
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[40])) ^ rk_arr[41];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[42])) ^ rk_arr[41];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[43])) ^ rk_arr[41];

    //round 15
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[36])) ^ rk_arr[37];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[38])) ^ rk_arr[37];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[39])) ^ rk_arr[37];

    //round 16
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[32])) ^ rk_arr[33];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[34])) ^ rk_arr[33];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[35])) ^ rk_arr[33];

    //round 17
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[28])) ^ rk_arr[29];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[30])) ^ rk_arr[29];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[31])) ^ rk_arr[29];

    //round 18
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[24])) ^ rk_arr[25];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[26])) ^ rk_arr[25];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[27])) ^ rk_arr[25];

    //round 19
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[20])) ^ rk_arr[21];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[22])) ^ rk_arr[21];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[23])) ^ rk_arr[21];

    //round 20
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[16])) ^ rk_arr[17];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[18])) ^ rk_arr[17];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[19])) ^ rk_arr[17];

    //round 21
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[12])) ^ rk_arr[13];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[14])) ^ rk_arr[13];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[15])) ^ rk_arr[13];


    //round 22
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[8])) ^ rk_arr[9];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[10])) ^ rk_arr[9];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[11])) ^ rk_arr[9];

    //round 23
    xi0 = x3;
    xi1 = (rotateRightBy9(x0) - (xi0 ^ rk_arr[4])) ^ rk_arr[5];
    xi2 = (rotateLeftBy5(x1) - (xi1 ^ rk_arr[6])) ^ rk_arr[5];
    xi3 = (rotateLeftBy3(x2) - (xi2 ^ rk_arr[7])) ^ rk_arr[5];

    //round 24
    x0 = xi3;
    x1 = (rotateRightBy9(xi0) - (x0 ^ rk_arr[0])) ^ rk_arr[1];
    x2 = (rotateLeftBy5(xi1) - (x1 ^ rk_arr[2])) ^ rk_arr[1];
    x3 = (rotateLeftBy3(xi2) - (x2 ^ rk_arr[3])) ^ rk_arr[1];

    memcpy(buffer, &x0, sizeof(uint32_t));
    memcpy(buffer + sizeof(uint32_t), &x1, sizeof(uint32_t));
    memcpy(buffer + 2 * sizeof(uint32_t), &x2, sizeof(uint32_t));
    memcpy(buffer + 3 * sizeof(uint32_t), &x3, sizeof(uint32_t));

    endian_conversion(x0);
    endian_conversion(x1);
    endian_conversion(x2);
    endian_conversion(x3);

}
