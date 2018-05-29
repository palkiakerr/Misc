#!/bin/bash

for i in {1..1000}
do
	SEED=$(head -200 /dev/urandom | cksum | cut -f1 -d " ")
	./a.out $SEED
done
exit 0