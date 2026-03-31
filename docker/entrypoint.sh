#!/usr/bin/env bash

# Cache the ownership status of the build directory,
# before Docker starts messing with it
DIR_OWNERSHIP="$(stat -c '%u:%g' build)"

# Populate the Windows path inside of the wineprefix
# TODO: This is in here because writing to the registry seems
# to fail when performed in the Dockerfile itself; investigate
wine reg ADD 'HKCU\Environment' /v PATH /d 'C:\msvc\bin;C:\msvc\bin\winnt;C:\cmake\bin;C:\windows\system32' /f
wine reg ADD 'HKCU\Environment' /v INCLUDE /d 'C:\msvc\include;C:\msvc\mfc\include' /f
wine reg ADD 'HKCU\Environment' /v LIB /d 'C:\msvc\lib;C:\msvc\mfc\lib' /f
wine reg ADD 'HKCU\Environment' /v TMP /d 'Z:\build' /f
wine reg ADD 'HKCU\Environment' /v TEMP /d 'Z:\build' /f

# Configure build with CMake
wine cmake -B build isle -G "NMake Makefiles" $CMAKE_FLAGS

# Start compiling LEGO Island
wine cmake --build build

# Restore build directory ownership
chown -R "$DIR_OWNERSHIP" build
