# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /work/CSCI-104/hw6/avlbst/hw6_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/CSCI-104/hw6/avlbst/hw6_tests

# Include any dependencies generated for this target.
include bst_tests/CMakeFiles/bst_runtime_tests.dir/depend.make

# Include the progress variables for this target.
include bst_tests/CMakeFiles/bst_runtime_tests.dir/progress.make

# Include the compile flags for this target's objects.
include bst_tests/CMakeFiles/bst_runtime_tests.dir/flags.make

bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o: bst_tests/CMakeFiles/bst_runtime_tests.dir/flags.make
bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o: bst_tests/bst_runtime_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/CSCI-104/hw6/avlbst/hw6_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o"
	cd /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o -c /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests/bst_runtime_tests.cpp

bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.i"
	cd /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests/bst_runtime_tests.cpp > CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.i

bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.s"
	cd /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests/bst_runtime_tests.cpp -o CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.s

bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.requires:

.PHONY : bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.requires

bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.provides: bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.requires
	$(MAKE) -f bst_tests/CMakeFiles/bst_runtime_tests.dir/build.make bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.provides.build
.PHONY : bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.provides

bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.provides.build: bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o


# Object files for target bst_runtime_tests
bst_runtime_tests_OBJECTS = \
"CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o"

# External object files for target bst_runtime_tests
bst_runtime_tests_EXTERNAL_OBJECTS =

bst_tests/bst_runtime_tests: bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o
bst_tests/bst_runtime_tests: bst_tests/CMakeFiles/bst_runtime_tests.dir/build.make
bst_tests/bst_runtime_tests: testing_utils/libtesting_utils.a
bst_tests/bst_runtime_tests: /usr/lib/libgtest_main.a
bst_tests/bst_runtime_tests: /usr/lib/libgtest.a
bst_tests/bst_runtime_tests: testing_utils/kwsys/libkwsys.a
bst_tests/bst_runtime_tests: testing_utils/libperf/libperf.a
bst_tests/bst_runtime_tests: bst_tests/CMakeFiles/bst_runtime_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/CSCI-104/hw6/avlbst/hw6_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bst_runtime_tests"
	cd /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bst_runtime_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bst_tests/CMakeFiles/bst_runtime_tests.dir/build: bst_tests/bst_runtime_tests

.PHONY : bst_tests/CMakeFiles/bst_runtime_tests.dir/build

bst_tests/CMakeFiles/bst_runtime_tests.dir/requires: bst_tests/CMakeFiles/bst_runtime_tests.dir/bst_runtime_tests.cpp.o.requires

.PHONY : bst_tests/CMakeFiles/bst_runtime_tests.dir/requires

bst_tests/CMakeFiles/bst_runtime_tests.dir/clean:
	cd /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests && $(CMAKE_COMMAND) -P CMakeFiles/bst_runtime_tests.dir/cmake_clean.cmake
.PHONY : bst_tests/CMakeFiles/bst_runtime_tests.dir/clean

bst_tests/CMakeFiles/bst_runtime_tests.dir/depend:
	cd /work/CSCI-104/hw6/avlbst/hw6_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/CSCI-104/hw6/avlbst/hw6_tests /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests /work/CSCI-104/hw6/avlbst/hw6_tests /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests/CMakeFiles/bst_runtime_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bst_tests/CMakeFiles/bst_runtime_tests.dir/depend
