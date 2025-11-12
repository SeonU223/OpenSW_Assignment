#!/bin/bash

factorial() {
    num=$1
    result=1

    # 1부터 num까지 반복하면서 곱하기
    for (( i=1; i<=num; i++ ))
    do
        result=$((result * i))
    done

    echo "Factorial of $num is $result"
}

read -p "Enter a number: " NUM
factorial $NUM
