#!/bin/bash
# ./hello.sh        Take_input
# ./hello.sh git    Take_input and call_github

varname=""

Take_Input() {
    # ask the user for their Problem
    echo Hello, What Is The Problem Name?
    read varname
    varname="${varname// /_}".cpp
    touch ./$varname
    echo $varname
    vi ./$varname
}

Call_Github() {
    git add .
    git status
    git commit -m $varname
    git push
}

Nums="0 1"

for var in $Nums
do
    if [ $var -eq 0 ]
    then
        Take_Input
    else
        if [[ $1 && $1 == "git" ]]
        then
            Call_Github
        fi
    fi
done