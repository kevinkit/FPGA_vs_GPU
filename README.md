Simply run the makefile in the the folder where you store the program.


This algorithm is very simple it does not take care of:


Better for FPGA:


-Branching

-performance per Watt

-unrolling of loops inside a work-item

-The FPGA is programmed resource saving. If you would have an infinite amount of resources you would have less clockzycles but only has many as you have operations in your Kernel.

Better for GPU:

-different clockrates (the algorithm assumes that the clockrate of the FPGA is 4 times slower than the one of the GPU)
