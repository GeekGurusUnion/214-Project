# CMake generated Testfile for 
# Source directory: /mnt/c/Users/dawie/OneDrive/Documents/GitHub/214-PA5/kitchen
# Build directory: /mnt/c/Users/dawie/OneDrive/Documents/GitHub/214-PA5/kitchen/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(runTestsValgrind "valgrind" "--leak-check=full" "--error-exitcode=1" "./runTests")
set_tests_properties(runTestsValgrind PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/Users/dawie/OneDrive/Documents/GitHub/214-PA5/kitchen/CMakeLists.txt;21;add_test;/mnt/c/Users/dawie/OneDrive/Documents/GitHub/214-PA5/kitchen/CMakeLists.txt;0;")
