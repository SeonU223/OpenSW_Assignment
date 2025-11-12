#!/bin/bash

# 함수 정의
print_param() {
    echo "script name: $0"
    echo "first param: $1"
    echo "second param: $2"
    echo "all params: $@"
    echo "the number of params: $#"
}

# 함수 호출 (인자 전달)
print_param "Hello" "World" "!"