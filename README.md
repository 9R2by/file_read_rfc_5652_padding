# File read of 16 byte blocks with RFC5652 padding

Takes as input the input and output filenames:     
Padding is applied:     
./padding 33 33.ap -a  
Padding is removed:   
./padding 33.ap 33.np -r  

sha256sum(33) == sha256sum(33.np)   
If the hashes are not equal, something went wrong.

Due to the nature of the RFC5652 specified algorithm, 
the padding will always be added.


The hash of the in and output files shall be the same,   
after adding and removal of the padding.   
The execution was not successful on any exit code different than 0.   

dd if=/dev/urandom of=1K bs=1K count=1   
dd if=/dev/urandom of=1M bs=1M count=1   
dd if=/dev/urandom of=253B bs=253 count=1  
dd if=/dev/urandom of=256B bs=256 count=1  
dd if=/dev/urandom of=257B bs=257 count=1   

compare sha256sums *  
