#!/bin/bash

# How many numbers?
SIZE=500

# Generate random unique numbers (mac version)
ARG=$(jot 1000 0 | sort -R | head -n $SIZE | tr '\n' ' ')

echo "Input:"
echo $ARG
echo "---------------------"

# Run radix
R_OUT=$(./push_swap_radix $ARG)
R_COUNT=$(echo "$R_OUT" | wc -l)

# Run chunk
C_OUT=$(./push_swap_chunk $ARG)
C_COUNT=$(echo "$C_OUT" | wc -l)

echo "Radix ops: $R_COUNT"
echo "Chunk ops: $C_COUNT"

# Check correctness
echo "$R_OUT" | ./checker $ARG
echo "$C_OUT" | ./checker $ARG