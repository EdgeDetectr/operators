#include "../../include/gradient/sobel_cuda.cuh"

#include <iostream>

__global__ void helloFromGPU() {
    printf("Hello from the GPU!\n");
}

int main() {
    helloFromGPU<<<1, 1>>>();
    cudaDeviceSynchronize();
    return 0;
}