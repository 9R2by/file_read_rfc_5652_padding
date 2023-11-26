#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define endian_conversion(x) __asm__ volatile ("bswap %0" : "+r" (x))

/**
 * File input reading with padding defined in RFC5652
 * as: trailing to end:
 * 1024 bytes = 1kibibyte
 * input = fopen("253B", "rb");
 * output = fopen("253B.bin", "wb");
 * e.g. ./main 253B 253B.bin
 * @param argc input arguments count
 * @param argv input shall define in and output filename
 * @return
 */
int main(int argc, char* argv[]) {
    if(argc != 3) return EXIT_FAILURE;
    FILE *input, *output;
    uint32_t x0, x1, x2, x3;
    unsigned char buffer[16];
    unsigned char b0[4], b1[4], b2[4], b3[4];
    uint8_t bytesRead;

    input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        if (bytesRead < sizeof(buffer)) {
            uint8_t missing_bytes = ((uint8_t) sizeof(buffer)) - ((uint8_t) bytesRead);
            for(size_t i = bytesRead; i < sizeof(buffer); i++){
                buffer[i] = missing_bytes;
            }
        }
        memcpy(b0, buffer, 4);
        memcpy(b1, buffer + 4, 4);
        memcpy(b2, buffer + 8, 4);
        memcpy(b3, buffer + 12, 4);

        x0 = (b0[0] << 24)  | (b0[1] << 16) | (b0[2] << 8) | b0[3];
        x1 = (b1[0] << 24)  | (b1[1] << 16) | (b1[2] << 8) | b1[3];
        x2 = (b2[0] << 24)  | (b2[1] << 16) | (b2[2] << 8) | b2[3];
        x3 = (b3[0] << 24)  | (b3[1] << 16) | (b3[2] << 8) | b3[3];



        //add your algorithm here




        endian_conversion(x0);
        endian_conversion(x1);
        endian_conversion(x2);
        endian_conversion(x3);

        fwrite(&x0, sizeof(uint32_t), 1, output);
        fwrite(&x1, sizeof(uint32_t), 1, output);
        fwrite(&x2, sizeof(uint32_t), 1, output);
        fwrite(&x3, sizeof(uint32_t), 1, output);
    }
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}
