/**
 * 2023
 * 9R2by
 * @htwsaar
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <x86intrin.h>
#include <time.h>
#include <unistd.h>

#define THOUSAND 1000
#define endian_conversion(x) __asm__ volatile ("bswap %0" : "+r" (x))

#define MFENCE _mm_mfence();
#define LFENCE _mm_lfence();


static uint8_t read_file_remove_padding(char *input_p, char *output_p) {
    uint64_t fileSize;
    FILE *input, *output;
    uint32_t a0, a1, a2, a3;
    uint8_t buffer[16], b0[4], b1[4], b2[4], b3[4];
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
    fseek(input, 0, SEEK_END);
    fileSize = ftell(input);
    fseek(input, 0, SEEK_SET);

    printf("Filesize: %zu\n", fileSize);

    while (fread(buffer, 1, 16, input) > 0) {
        memcpy(b0, buffer, 4);
        memcpy(b1, buffer + 4, 4);
        memcpy(b2, buffer + 8, 4);
        memcpy(b3, buffer + 12, 4);

        a0 = (b0[0] << 24) | (b0[1] << 16) | (b0[2] << 8) | b0[3];
        a1 = (b1[0] << 24) | (b1[1] << 16) | (b1[2] << 8) | b1[3];
        a2 = (b2[0] << 24) | (b2[1] << 16) | (b2[2] << 8) | b2[3];
        a3 = (b3[0] << 24) | (b3[1] << 16) | (b3[2] << 8) | b3[3];

        //add your algorithm here



        b0[0] = (a0 >> 24) & 0xFF;
        b0[1] = (a0 >> 16) & 0xFF;
        b0[2] = (a0 >> 8) & 0xFF;
        b0[3] = a0 & 0xFF;

        b1[0] = (a1 >> 24) & 0xFF;
        b1[1] = (a1 >> 16) & 0xFF;
        b1[2] = (a1 >> 8) & 0xFF;
        b1[3] = a1 & 0xFF;

        b2[0] = (a2 >> 24) & 0xFF;
        b2[1] = (a2 >> 16) & 0xFF;
        b2[2] = (a2 >> 8) & 0xFF;
        b2[3] = a2 & 0xFF;

        b3[0] = (a3 >> 24) & 0xFF;
        b3[1] = (a3 >> 16) & 0xFF;
        b3[2] = (a3 >> 8) & 0xFF;
        b3[3] = a3 & 0xFF;


        uint8_t last_byte = a3 & 0x0000000F;
        if (last_byte == 0x1) {
            endian_conversion(a0);
            endian_conversion(a1);
            endian_conversion(a2);
            endian_conversion(a3);
            fwrite(buffer, sizeof(buffer) - 0x1, 1, output);
        } else {
            uint8_t arr[16];
            memcpy(arr + 0, buffer, 4);
            memcpy(arr + 4, buffer + 4, 4);
            memcpy(arr + 8, buffer + 8, 4);
            memcpy(arr + 12, buffer + 12, 4);
            fwrite(buffer, 16 - last_byte, 1, output);
        }
    }


    fclose(input);
    fclose(output);

    printf("Output filename:  %s\n", output_p);
    return EXIT_SUCCESS;
}


static uint8_t read_file_add_padding(char *input_p, char *output_p) {
    FILE *input, *output;
    uint64_t fileSize;
    uint32_t a0, a1, a2, a3;
    uint8_t buffer[16], b0[4], b1[4], b2[4], b3[4], bytesRead;
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

    fseek(input, 0, SEEK_END);
    fileSize = ftell(input);
    fseek(input, 0, SEEK_SET);

    printf("Filesize: %zu\n", fileSize);

    while ((bytesRead = fread(buffer, 1, 15, input)) > 0) {
        if (bytesRead < sizeof(buffer)) {
            uint8_t missing_bytes = ((uint8_t) sizeof(buffer)) - bytesRead;
            for (size_t i = bytesRead; i < sizeof(buffer); i++) {
                buffer[i] = missing_bytes;
            }
        }
        memcpy(b0, buffer, 4);
        memcpy(b1, buffer + 4, 4);
        memcpy(b2, buffer + 8, 4);
        memcpy(b3, buffer + 12, 4);

        a0 = (b0[0] << 24) | (b0[1] << 16) | (b0[2] << 8) | b0[3];
        a1 = (b1[0] << 24) | (b1[1] << 16) | (b1[2] << 8) | b1[3];
        a2 = (b2[0] << 24) | (b2[1] << 16) | (b2[2] << 8) | b2[3];
        a3 = (b3[0] << 24) | (b3[1] << 16) | (b3[2] << 8) | b3[3];

        //add your algorithm here

        endian_conversion(a0);
        endian_conversion(a1);
        endian_conversion(a2);
        endian_conversion(a3);

        fwrite(&a0, sizeof(uint32_t), 1, output);
        fwrite(&a1, sizeof(uint32_t), 1, output);
        fwrite(&a2, sizeof(uint32_t), 1, output);
        fwrite(&a3, sizeof(uint32_t), 1, output);
    }

    fclose(input);
    fclose(output);

    printf("Output filename:  %s\n", output_p);
    return EXIT_SUCCESS;
}


/**
 * File input reading with padding defined in RFC5652
 * as: trailing to end:
 * 1024 bytes = 1kibibyte
 * e.g. ./main 253B 253B.out -a
 * e.g. ./main 253B.out 253B.clean -r
 * @param argc input arguments count
 * @param argv input shall define in and output filename as well as the mode of operation
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc != 4) return EXIT_FAILURE;
    uint8_t mode = 0;
    if (strcmp(argv[3], "-a") == 0) {
        mode = 1;
    } else if (strcmp(argv[3], "-r") == 0) {
        mode = 2;
    } else {
        printf("Program input is not as needed.\n");
        return EXIT_FAILURE;
    }

    uint64_t start, end;
    uint32_t ui, ret = 0;
    struct timespec start_t, end_t, start_cpu, end_cpu, ts1, ts2;
    clock_gettime(CLOCK_MONOTONIC, &start_t);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_cpu);
    timespec_get(&ts1, TIME_UTC);

    MFENCE
    start = __rdtscp(&ui);
    LFENCE

    switch (mode) {
        case 1:
            ret = read_file_add_padding(argv[1], argv[2]);
            break;
        case 2:
            ret = read_file_remove_padding(argv[1], argv[2]);
            break;
        default:
            break;
    }

    sleep(3);

    MFENCE
    end = __rdtscp(&ui);
    LFENCE
    printf("Cycles: %lu, Returncode: %u\n", (end - start), ret);
    clock_gettime(CLOCK_MONOTONIC, &end_t);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_cpu);
    timespec_get(&ts2, TIME_UTC);


    //conversion from nano to microseconds
    printf("Time: %lu μs\n", end_t.tv_nsec / THOUSAND - start_t.tv_nsec / THOUSAND);
    printf("Time: %f s\n", (end_t.tv_sec - start_t.tv_sec) + (end_t.tv_nsec - start_t.tv_nsec)/1000000000.0);
    printf("Timespec: %ld s\n", ts2.tv_nsec / THOUSAND - ts1.tv_nsec/THOUSAND);
    printf("Timespec: %f s\n", (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec)/1000000000.0);
    printf("CPU Time: %lu μs\n", end_cpu.tv_nsec / THOUSAND - start_cpu.tv_nsec / THOUSAND);
    printf("CPU Time: %f s\n", (end_cpu.tv_sec - start_cpu.tv_sec) + (end_cpu.tv_nsec - start_cpu.tv_nsec)/1000000000.0);


    if (ret != 0) {
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}
