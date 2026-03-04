#!/bin/bash

# 1) generate 20 unique numbers between 0 and 99
ARG=$(jot 100 0 | sort -R | head -n 20 | tr '\n' ' ')

echo "Input:"
echo "$ARG"
echo "--------------------"

# 2) run push_swap once and store operations
OPS=$(./push_swap $ARG)

# 3) count operations (each line is one op)
COUNT=$(echo "$OPS" | wc -l)

# 4) check correctness
RESULT=$(echo "$OPS" | ./checker $ARG)

echo "Checker: $RESULT"
echo "Ops: $COUNT"