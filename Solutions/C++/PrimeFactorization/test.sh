#/bin/bash

# Recompiles the file "Pi.cpp" and runs test suite.

make clean > /dev/null 2>&1

make > /dev/null

# Test input for numbers
for i in {-10..47}
do
	echo "./prime " $i
	./prime $i
	echo
done

# Test inputs for other values

# Works, considered to be 19
echo "./prime " 19ff
./prime 19ff
echo

# Does not work
echo "./prime " ff19
./prime ff19
echo

echo End of Tests
