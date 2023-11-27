# File read of 16 byte blocks with RFC5652 padding

Takes as input the input and output filenames:   
Padding is applied:   
./file_read 253B 253B.out   
No Padding is applied:   
./file_read 256B 256B.out   


The hash of the in and output files shall be the same,   
if no further algorithm is applied and no padding is done.   
The execution was not successful on any exit code else than 0.   

dd if=/dev/urandom of=1K bs=1K count=1   
dd if=/dev/urandom of=1M bs=1M count=1   
dd if=/dev/urandom of=253B bs=253 count=1  
dd if=/dev/urandom of=256B bs=256 count=1  
dd if=/dev/urandom of=257B bs=257 count=1   

compare sha256sums *  
