#/bin/bash

# Recompiles the file "E.cpp" and runs test suite.
	
make clean > /dev/null 2>&1

make > /dev/null

# Test input for numbers 
for i in {-10..47}
do
	echo "./e " $i
	./e $i
	echo
done

# Test inputs for other values

# Works, considered to be 19
echo "./e " 19ff
./e 19ff
echo

# Does not work
echo "./e " ff19
./e ff19
echo

echo End of Tests


