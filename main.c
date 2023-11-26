#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <x86intrin.h>
#include <time.h>

#include "lea/lea.h"

#define endian_conversion(x) __asm__ volatile ("bswap %0" : "+r" (x))

#define MFENCE _mm_mfence();
#define LFENCE _mm_lfence();


static uint8_t read_file_remove_padding(char *input_p, char *output_p, uint8_t mode) {
    uint64_t fileSize;
    FILE *input, *output;
    uint8_t buffer[16];
    input = fopen(input_p, "rb");
    if (input == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    output = fopen(output_p, "wb");
    if (output == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    /*fseek(input, 0, SEEK_END);
    fileSize = ftell(input);
    fseek(input, 0, SEEK_SET);

    printf("Filesize: %zu\n", fileSize);*/

    while (fread(buffer, 1, 16, input) > 0) {
        if (mode == 1) {
            lea_decrypt(buffer);
        }
        if (buffer[15] == 0x1) {
            fwrite(buffer, sizeof(buffer) - 0x1, 1, output);
        } else {
            fwrite(buffer, 16 - buffer[15], 1, output);
        }
    }
    fclose(input);
    fclose(output);

    //printf("Output filename:  %s\n", output_p);
    return EXIT_SUCCESS;
}


static uint8_t read_file_add_padding(char *input_p, char *output_p, uint8_t mode) {
    FILE *input, *output;
    uint64_t fileSize;
    uint8_t buffer[16], bytesRead;
    input = fopen(input_p, "rb");
    if (input == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    output = fopen(output_p, "wb");
    if (output == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /*
    fseek(input, 0, SEEK_END);
    fileSize = ftell(input);
    fseek(input, 0, SEEK_SET);

    printf("Filesize: %zu\n", fileSize);*/

    while ((bytesRead = fread(buffer, 1, 15, input)) > 0) {
        uint8_t missing_bytes = ((uint8_t) sizeof(buffer)) - bytesRead;
        for (size_t i = bytesRead; i < sizeof(buffer); i++) {
            buffer[i] = missing_bytes;
        }

        if (mode == 1) {
            lea_encrypt(buffer);
        }

        fwrite(buffer, sizeof(buffer), 1, output);
    }

    fclose(input);
    fclose(output);

    //printf("Output filename:  %s\n", output_p);
    return EXIT_SUCCESS;
}


/**
 * File input reading with padding defined in RFC5652
 * as: trailing to end:
 * 1024 bytes = 1kibibyte
 * e.g. ./main 1GB 1GB.ap -a
 * e.g. ./main 1GB.ap 1GB.np -r
 * e.g. ./main 1GB 1GB.ap -ea
 * e.g. ./main 1GB.ap 1GB.np -dr
 * @param argc input arguments count
 * @param argv input shall define in and output filename as well as the mode of operation
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc != 4) return EXIT_FAILURE;
    uint8_t mode;
    if (strcmp(argv[3], "-a") == 0) {
        //add padding without encryption
        mode = 1;
    } else if (strcmp(argv[3], "-r") == 0) {
        //remove padding without encryption
        mode = 2;
    } else if (strcmp(argv[3], "-ea") == 0) {
        //add padding and encrypt
        mode = 3;
    } else if (strcmp(argv[3], "-dr") == 0) {
        //decrypt and remove padding
        mode = 4;
    } else {
        printf("Program input is not as needed.\n");
        return EXIT_FAILURE;
    }

    uint64_t start, end;
    uint32_t ui, ret = 0;
    struct timespec start_t, end_t, start_cpu, end_cpu;
    clock_gettime(CLOCK_MONOTONIC, &start_t);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_cpu);

    MFENCE
    start = __rdtscp(&ui);
    LFENCE

    switch (mode) {
        case 1:
            ret = read_file_add_padding(argv[1], argv[2], 0);
            break;
        case 2:
            ret = read_file_remove_padding(argv[1], argv[2], 0);
            break;
        case 3:
            ret = read_file_add_padding(argv[1], argv[2], 1);
            break;
        case 4:
            ret = read_file_remove_padding(argv[1], argv[2], 1);
            break;
        default:
            break;
    }

    MFENCE
    end = __rdtscp(&ui);
    LFENCE
    printf("Cycles: %lu, Returncode: %u\n", (end - start), ret);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_cpu);
    clock_gettime(CLOCK_MONOTONIC, &end_t);
    //conversion from nano to microseconds/milli/s
    printf("Time: %f s\n", (double)(end_t.tv_sec - start_t.tv_sec) + (double)(end_t.tv_nsec - start_t.tv_nsec) / 1000000000.0);
    printf("CPU Time: %f s\n",
           (double)(end_cpu.tv_sec - start_cpu.tv_sec) + (double)(end_cpu.tv_nsec - start_cpu.tv_nsec) / 1000000000.0);


    if (ret != 0) {
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}
