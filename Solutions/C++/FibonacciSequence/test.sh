#/bin/bash

# Recompiles the file "Fib.cpp" and runs test suite.
	
make clean > /dev/null 2>&1

make > /dev/null

# Test input for numbers 
values=(a b)

for i in "${values[@]}"
do
    for j in {-2..47}
    do
        echo "./fib " $i $j
        ./fib $i $j
        echo
    done
done

# Test inputs for other values

# Works, considered to be 19
echo "./fib " a 19ff
./fib a 19ff
echo

# Works, considered to be 19
echo "./fib " b 19ff
./fib b 19ff
echo

# Does not work
echo "./fib " s f19
./fib s ff19
echo

# Does not work 
echo "./fib " a f19
./fib a f19
echo 

echo End of Tests

#Cleaning up after the tests. 
make clean > /dev/null 2>&1
