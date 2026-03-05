#!/bin/bash

SIZE=500
RANGE=10000
CHECKER=./checker

# Build project (default algorithm = turk)
echo "Building push_swap_radix..."
make radix >/dev/null || exit 1

# Check binary exists
if [ ! -x ./push_swap_radix ]; then
    echo "Error: push_swap_radix not built"
    exit 1
fi

# Generate random input (macOS)
ARG=$(jot $RANGE 0 | sort -R | head -n $SIZE | tr '\n' ' ')

echo "Input size: $SIZE"
echo "---------------------"

# Run push_swap
OUT=$(./push_swap_radix $ARG)

# Count operations
COUNT=$(echo "$OUT" | wc -l | tr -d ' ')

# Verify correctness
RES=$(echo "$OUT" | $CHECKER $ARG)

echo "Operations: $COUNT"
echo "Checker:    $RES"