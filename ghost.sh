#! /bin/bash

tool_name="ghost"

CheckCmdStatus () {

    if [ $1 -ne 0 ]
    then
        echo "=========FAILED!!"
        exit -1
    fi
}

Clean () {

    echo "=========CLEANING..."
    rm -rf $1/bin ; CheckCmdStatus $?

    echo "=========DONE!!"
    return 0
}

Compile () {

    mode=$1
    dir=$2
    debug=""

    if [ $mode == "debug" ]
    then
       debug=-g
    fi  
    
    echo "=========Creating bin directory"
    mkdir -p ${dir}/bin ; CheckCmdStatus $?

    echo "=========IN ${mode} MODE..."

    echo "=========COMPILING..."
    g++ -o ${dir}/bin/output.exe -Wall -I library ${dir}/src/*.cpp $debug ; CheckCmdStatus $?

    echo "=========SUCCESS!!"

    if [ $mode == "debug" ]
    then
       echo "=========OPENING DEBUGGER..."
       gdbgui ${dir}/bin/output.exe ; CheckCmdStatus $?
    fi  

    return 0
}

Create () {

    echo "=========CREATING PROJECT.."
    mkdir -p $1 ; CheckCmdStatus $?
    mkdir -p $1/src ; CheckCmdStatus $?
    touch $1/src/main.cpp ; CheckCmdStatus $?
    cat templates/main_cpp.cpp > $1/src/main.cpp ; CheckCmdStatus $?
    
    echo "=========DONE!!"
    return 0
}

Delete () {

    echo "=========DELETING PROJECT.."
    rm -rf $1 ; CheckCmdStatus $?
    
    echo "=========DONE!!"
    return 0
}

Help () {

    echo "=========COMPILE"
    echo "About: Compiles a project"
    echo "Usage: $tool_name compile project_name"
    echo "=========CLEAN"
    echo "About: Cleans the project"
    echo "Usage: $tool_name clean project_name"
    echo "=========CREATE"
    echo "About: Creates a project"
    echo "Usage: $tool_name create project_name"
    echo "=========DELETE"
    echo "About: Deletes a project"
    echo "Usage: $tool_name delete project_name"
    echo "=========HELP"
    echo "About: What $tool_name can do"
    echo "Usage: $tool_name help"
    return 0
}

if [ $1 == "compile" ]
then
    Compile $2 $3
    exit $?
fi

if [ $1 == "clean" ]
then
    Clean $2
    exit $?
fi

if [ $1 == "create" ]
then
    Create $2
    exit $?
fi

if [ $1 == "delete" ]
then
    Delete $2
    exit $?
fi

if [ $1 == "help" ]
then
    Help
    exit $?
fi
