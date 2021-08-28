#!/bin/bash

# Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

# For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

# What is the total of all the name scores in the file?

cat p022_names.txt | tr "," "\n" | tr -d "\"" | sort >p022_names_sorted.txt

OUT=0

declare -A DICT=(
  ["A"]=1 ["B"]=2 ["C"]=3 ["D"]=4 ["E"]=5 ["F"]=6 ["G"]=7 ["H"]=8 ["I"]=9 ["J"]=10 ["K"]=11 ["L"]=12 ["M"]=13 ["N"]=14 ["O"]=15 ["P"]=16 ["Q"]=17 ["R"]=18 ["S"]=19 ["T"]=20 ["U"]=21 ["V"]=22 ["W"]=23 ["X"]=24 ["Y"]=25 ["Z"]=26
)

LINE_NUMBER=1
while read line; do
  SUM_OF_LETTERS=0
  for ((i = 0; i < ${#line}; i++)); do
    ((SUM_OF_LETTERS += ${DICT[${line:$i:1}]}))
  done
  WORD_VALUE=$((SUM_OF_LETTERS * LINE_NUMBER))
  ((OUT += WORD_VALUE))
  ((LINE_NUMBER++))

done \
  <<<$(cat p022_names_sorted.txt)

echo "The total of all the name scores in the file is ${OUT}"
