#/bin/bash

# Recompiles the file "E.cpp" and runs test suite.

make clean > /dev/null 2>&1

make > /dev/null

# Test input for numbers
for i in {-10..20}
do
	echo "scala E " $i
	scala E $i
	echo
done

# Test inputs for other values

# Will not work
echo "scala E " 19ff
scala E 19ff
echo

# Does not work
echo "scala E " ff19
scala E ff19
echo

echo End of Tests
