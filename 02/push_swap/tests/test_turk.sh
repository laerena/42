#!/bin/bash

SIZE=500
RANGE=10000
CHECKER=./checker

# Build project (default algorithm = turk)
echo "Building push_swap (default)..."
make >/dev/null || exit 1

# Check binary exists
if [ ! -x ./push_swap ]; then
    echo "Error: push_swap not built"
    exit 1
fi

if command -v jot >/dev/null 2>&1; then
    ARG=$(jot $RANGE 0 | sort -R | head -n $SIZE | tr '\n' ' ')
else
    ARG=$(shuf -i 0-$RANGE -n $SIZE | tr '\n' ' ')
fi

echo "Input size: $SIZE"
echo "---------------------"

if [ "$1" = "vg" ]; then
	TMP_OUT=$(mktemp)
	TMP_VG=$(mktemp)
	valgrind --leak-check=full --show-leak-kinds=all \
		./push_swap $ARG >"$TMP_OUT" 2>"$TMP_VG"
	COUNT=$(wc -l <"$TMP_OUT" | tr -d ' ')
	RES=$($CHECKER $ARG <"$TMP_OUT")
	echo "Operations: $COUNT"
	echo "Checker:    $RES"
	grep -E "definitely lost|indirectly lost|possibly lost|still reachable" "$TMP_VG"
	rm -f "$TMP_OUT" "$TMP_VG"
else
	# Run push_swap
	OUT=$(./push_swap $ARG)
	# Count operations
	COUNT=$(echo "$OUT" | wc -l | tr -d ' ')
	# Verify correctness
	RES=$(echo "$OUT" | $CHECKER $ARG)
	echo "Operations: $COUNT"
	echo "Checker:    $RES"
fi
