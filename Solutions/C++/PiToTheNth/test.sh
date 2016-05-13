#/bin/bash

# Recompiles the file "Pi.cpp" and runs test suite.
	
make clean > /dev/null 2>&1

make > /dev/null

# Test input for numbers 
for i in {-10..47}
do
	echo "./pi " $i
	./pi $i
	echo
done

# Test inputs for other values

# Works, considered to be 19
echo "./pi " 19ff
./pi 19ff
echo

# Does not work
echo "./pi " ff19
./pi ff19
echo

echo End of Tests


