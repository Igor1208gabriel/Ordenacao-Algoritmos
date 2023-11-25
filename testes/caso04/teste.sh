#!/usr/bin/bash
for j in exemplo*.txt
do
    echo "testando: $j"
    ./ordenacaoi < $j 2>> tabelai.csv
    ./ordenacaos < $j 2>> tabelas.csv
    ./ordenacaom < $j 2>> tabelam.csv
done