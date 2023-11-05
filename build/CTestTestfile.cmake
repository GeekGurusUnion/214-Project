# CMake generated Testfile for 
# Source directory: /mnt/c/Users/User-Pc/Documents/GitHub/214-Project
# Build directory: /mnt/c/Users/User-Pc/Documents/GitHub/214-Project/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[runTestsValgrind]=] "valgrind" "--leak-check=full" "--error-exitcode=1" "./runTests")
set_tests_properties([=[runTestsValgrind]=] PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/Users/User-Pc/Documents/GitHub/214-Project/CMakeLists.txt;68;add_test;/mnt/c/Users/User-Pc/Documents/GitHub/214-Project/CMakeLists.txt;0;")
