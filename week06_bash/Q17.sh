#!/bin/bash

file_wordcnt() {
    files=$(ls *.txt 2>/dev/null)  # 현재 디렉토리의 .txt 파일 목록
    if [ -z "$files" ]; then       # 파일이 하나도 없을 경우 예외 처리
        echo ".txt 파일이 존재하지 않습니다."
        return 1
    fi

    for file in $files; do
        result=$(wc -w < "$file")
        echo "$file 파일의 단어는 $result 개 입니다."
    done
}

file_wordcnt
