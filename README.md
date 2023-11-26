# File read of 16 byte blocks with RFC5652 padding

Takes as input the input and output filenames:
./main 253B 253B.out

dd if=/dev/urandom of=1K bs=1K count=1
dd if=/dev/urandom of=1M bs=1M count=1
dd if=/dev/urandom of=253B bs=253 count=1
dd if=/dev/urandom of=256B bs=256 count=1
dd if=/dev/urandom of=257B bs=257 count=1  

compare sha256sums *
