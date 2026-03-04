#!/bin/bash

# How many tests to run
NTESTS=50

# Range of numbers will be 0..(RANGE-1)
RANGE=100

# How many numbers in each test
SIZE=20

# Path to checker
CHECKER=./checker

for i in $(seq 1 $NTESTS)
do
  # Generate unique random numbers on macOS:
  # 1) jot makes 0..(RANGE-1)
  # 2) sort -R shuffles
  # 3) head takes SIZE numbers
  # 4) tr makes it one line
  ARG=$(jot $RANGE 0 | sort -R | head -n $SIZE | tr '\n' ' ')
  # for linux: ARG=$(shuf -i 0-$((RANGE-1)) -n $SIZE | tr '\n' ' ')

  OPS=$(./push_swap $ARG)

  # If push_swap printed Error, fail immediately
  if echo "$OPS" | grep -q "^Error$"; then
    echo "FAIL (push_swap printed Error on a generated unique test) test#$i"
    echo "Input: $ARG"
    exit 1
  fi

  RES=$(echo "$OPS" | $CHECKER $ARG)
  COUNT=$(echo "$OPS" | wc -l)

  if [ "$RES" != "OK" ]; then
    echo "FAIL test#$i"
    echo "Input: $ARG"
    echo "Checker: $RES"
    echo "Ops: $COUNT"
    exit 1
  fi

  echo "OK test#$i  ops=$COUNT"
done

echo "All $NTESTS tests OK"