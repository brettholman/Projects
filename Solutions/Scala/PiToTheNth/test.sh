#/bin/bash

# Recompiles the file "E.cpp" and runs test suite.

make clean > /dev/null 2>&1

make > /dev/null

# Test input for numbers
for i in {-10..20}
do
	echo "scala Pi " $i
	scala Pi $i
	echo
done

# Test inputs for other values

# Will not work
echo "scala Pi " 19ff
scala Pi 19ff
echo

# Does not work
echo "scala Pi " ff19
scala Pi ff19
echo

echo End of Tests
