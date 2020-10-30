#!/bin/bash

function compiling
{
  single=$1/
  for d in `ls -d */ | sort -n`; do
    if [ $single = / ] || [ $d = $single ]; then
      pushd $d >> /dev/null
      files=(`find . -iname "*.cpp"`)
      if [ ! -z ${files[0]} ];then
        echo compiling $d$(basename ${files[0]})
        g++ -I ../include/ -std=c++11 ${files[0]} -o ${files[0]%%.cpp}
        if [ $? != 0 ]; then
          echo ${f} compile failed!!
          exit
        fi
      fi
      files=(`find . -iname "*.c"`)
      if [ ! -z ${files[0]} ];then
        echo compiling $d$(basename ${files[0]})
        gcc ${files[0]} -o ${files[0]%%.c}
        if [ $? != 0 ]; then
          echo ${f} compile failed!!
          exit
        fi
      fi
      popd > /dev/null
    fi
  done
}


function testing
{
  for d in `ls -d */ | sort -n`; do
    pushd $d >> /dev/null

    files=(`find . -iname "*.cpp"`)
    f=${files[0]%%.cpp}
    if [ ! -z ${f} ];then
      echo executing $d$(basename ${f})
      ${f}
      echo ""
    fi

    files=(`find . -iname "*.c"`)
    f=${files[0]%%.c}
    if [ ! -z ${f} ]; then
      echo executing $d$(basename ${f})
      ${f}
      echo ""
    fi

    files=(`find . -iname "*.py"`)
    if [ ! -z ${files[0]} ]; then
      echo python3 $d$(basename ${files[0]})
      python3 ${files[0]}
      echo ""
    fi

    popd > /dev/null
  done
}


function cleaning
{
  for d in `ls -d */ | sort -n`; do
    pushd $d >> /dev/null
    files=(`find . -iname "*.cpp"`)
    if [[ ! -z ${files[0]%%.cpp} && -f ${files[0]%%.cpp} ]];then
      rm ${files[0]%%.cpp}
    fi
    files=(`find . -iname "*.c"`)
    if [[ ! -z ${files[0]%.c} && -f ${files[0]%%.c} ]]; then
      rm ${files[0]%%.c}
    fi
    popd > /dev/null
  done
}
