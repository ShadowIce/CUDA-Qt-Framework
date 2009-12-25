#include <cuda.h>

// Kernel definition
__global__ void VecAdd(int n, float* v1, float* v2, float* v3) {
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (i < n) v3[i] = v1[i] + v2[i];
}

// exported function, usable in the C++ part
extern "C" void RunVecAdd(int n, float* v1, float* v2, float* v3) {
	size_t size = n * sizeof(float);
	
	float* d_v1;
	float* d_v2;
	float* d_v3;

	cudaMalloc((void**)&d_v1, size);
	cudaMalloc((void**)&d_v2, size);
	cudaMalloc((void**)&d_v3, size);

	cudaMemcpy(d_v1, v1, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_v2, v2, size, cudaMemcpyHostToDevice);

	int threadsPerBlock = 256;
	int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
	
	VecAdd<<<blocksPerGrid, threadsPerBlock>>>(n, d_v1, d_v2, d_v3);

	cudaMemcpy(v3, d_v3, size, cudaMemcpyDeviceToHost);
	
	cudaFree(d_v1);
	cudaFree(d_v2);
	cudaFree(d_v3);
}
