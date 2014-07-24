This algorithm is very simple it does not take care of:


Better for FPGA:


-Branching

-performance per Watt

-unrolling of loops inside a work-item



Better for GPU:

-different clockrates (the algorithm assumes that the clockrate of the FPGA is 4 times slower than the one of the GPU)
