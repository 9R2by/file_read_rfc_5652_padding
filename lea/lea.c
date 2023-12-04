#include "lea.h"


/**
 *
 * @param uint8_t buffer 16
 */
void lea_encryption(uint8_t buffer[16]) {
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


    printf("Before encryption. %X %X %X %X\n", x0, x1, x2, x3);

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


    endian_conversion(x0);
    endian_conversion(x1);
    endian_conversion(x2);
    endian_conversion(x3);

    printf("After encryption. %X %X %X %X\n", x0, x1, x2, x3);


    memcpy(buffer, &x0, sizeof(uint32_t));
    memcpy(buffer + sizeof(uint32_t), &x1, sizeof(uint32_t));
    memcpy(buffer + 2 * sizeof(uint32_t), &x2, sizeof(uint32_t));
    memcpy(buffer + 3 * sizeof(uint32_t), &x3, sizeof(uint32_t));


    //endian converted by memcpy
    printf("Buffer:\n");
    for(int i = 0; i < 16; i++){
        printf("%02X", buffer[i]);
    }
    printf("\n");


    /*   memcpy(b0, buffer, 4);
       memcpy(b1, buffer + 4, 4);
       memcpy(b2, buffer + 8, 4);
       memcpy(b3, buffer + 12, 4);*/


    /*
    &a0 = x0;
    &a1 = x1;
    &a2 = &x2;
    &a3 = &x3;

    memcpy endian converts the input data already, not need for endian conversion
    memcpy(l_star, &x0, sizeof(uint32_t));
    memcpy(l_star + sizeof(uint32_t), &x1, sizeof(uint32_t));
    memcpy(l_star + 2 * sizeof(uint32_t), &x2, sizeof(uint32_t));
    memcpy(l_star + 3 * sizeof(uint32_t), &x3, sizeof(uint32_t));
     */
}
