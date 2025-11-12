#! /bin/bash

file_wordcnt() {
    word_count=$(wc -w < "$1")
    echo "$1 파일의 단어는 ${word_count}개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt "$FILE"
