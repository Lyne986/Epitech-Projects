#!/bin/bash

rougefonce='\e[0;31m'
vertfonce='\e[0;32m'
jaune='\e[0;33m'
blue='\e[1;36m'
neutre='\e[0;m'

nb=0
nb_passed=0

rm trace &> /dev/null
rm ./tests/corewar &> /dev/null
cp ./corewar/corewar ./tests/ &> /dev/null

make_error_args_tests() {
    ./corewar/corewar ${1} &> ./mycorewar
    my_return=$?
    ./tests/corewar_binaries/corewar/./corewar ${1} &> corewarref
    real_return=$?
    if [ $real_return = 1 ]  && [ $my_return = 84 ] || [ $my_return = $real_return ]
            then
                echo -ne "${vertfonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${vertfonce} OK${neutre}\n"
                let 'nb_passed=nb_passed+1'
            else
                echo -ne "${rougefonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${rougefonce} KO${neutre}\n"
                echo -ne "----------> ${nb} <----------\n" >> trace
                echo -n "==> [${1}] <==" >> trace
                echo -ne "\nreal_corewar: return $real_return \n" >> trace
                cat tests/real_corewar >> trace
                echo -ne "\my_corewar: return $my_return\n" >> trace
                cat tests/my_asm >> trace
                echo -ne "\n\n" >> trace
                echo -ne "diff:\n $Test\n\n\n" >> trace
            fi
    let 'nb=nb+1'
    echo -ne "\n"
}

make_test() {
    rm ./file_test &> /dev/null
    ./tests/corewar_binaries/corewar/corewar ${1} &> tests/real_corewar
    real_return=$?
    rm ./file_test &> /dev/null
    ./bonus/corewar/corewar ${1} &> tests/my_corewar
    my_return=$?
    if [ $real_return = 84 ]
        then
            Test=""
        else
            Test=$(diff tests/my_corewar tests/real_corewar)
        fi
    if [ "$Test" = "" ] && [ $real_return = $my_return ]
            then
                echo -ne "${vertfonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${vertfonce} OK${neutre}\n"
                let 'nb_passed=nb_passed+1'
            else
                echo -ne "${rougefonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${rougefonce} KO${neutre}\n"
                echo -ne "----------> ${nb} <----------\n" >> trace
                echo -n "==> [${1}] <==" >> trace
                echo -ne "\nreal_corewar: return $real_return \n" >> trace
                cat tests/real_corewar >> trace
                echo -ne "\nmy_corewar: return $my_return\n" >> trace
                cat tests/my_corewar >> trace
                echo -ne "\n\n" >> trace
                echo -ne "diff:\n $Test\n\n\n" >> trace
            fi
    let 'nb=nb+1'
    echo -ne "\n"
}

echo -e "${jaune}1 - COREWAR ERROR CASES${neutre}\n"
make_error_args_tests "e"
make_error_args_tests "tests/corewar_errors/abl.cor tests/corewar_errors/abel.cor"
make_error_args_tests "-a 4 -n 4 tests/corewar_errors/abel.cor tests/corewar_errors/abel.cor"
make_error_args_tests "-n 2 -a 1 tests/corewar_errors/abel.cor -n 3 -a 1000 tests/corewar_errors/abel.cor"
make_error_args_tests "-dump 1 tests/corewar_errors/abel.cor tests/corewar_errors/abel.cor"
make_error_args_tests "-dup 4 tests/corewar_errors/abel.cor tests/corewar_errors/abel.cor"

echo -e "${jaune}1 - COREWAR ERROR CASES${neutre}\n"
make_test "-dump 1500 -n 1 tests/corewar_champions/abel.cor -n 2 tests/corewar_champions/abel.cor"
make_test "-dump 1500 -n 1 tests/corewar_champions/42.cor -n 2 tests/corewar_champions/abel.cor"

echo -ne "TESTS PASSED: $nb_passed / $nb\n\n"
rm ./tests/corewar &> /dev/null
rm ./file_test &> /dev/null