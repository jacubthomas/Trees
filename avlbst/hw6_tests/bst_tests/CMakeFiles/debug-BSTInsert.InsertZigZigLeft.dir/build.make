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

# Utility rule file for debug-BSTInsert.InsertZigZigLeft.

# Include the progress variables for this target.
include bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/progress.make

bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/work/CSCI-104/hw6/avlbst/hw6_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging BSTInsert.InsertZigZigLeft with GDB..."
	cd /work/CSCI-104/hw6/avlbst && gdb --args /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests/bst_tests --gtest_filter=BSTInsert.InsertZigZigLeft

debug-BSTInsert.InsertZigZigLeft: bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft
debug-BSTInsert.InsertZigZigLeft: bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/build.make

.PHONY : debug-BSTInsert.InsertZigZigLeft

# Rule to build all files generated by this target.
bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/build: debug-BSTInsert.InsertZigZigLeft

.PHONY : bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/build

bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/clean:
	cd /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/cmake_clean.cmake
.PHONY : bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/clean

bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/depend:
	cd /work/CSCI-104/hw6/avlbst/hw6_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/CSCI-104/hw6/avlbst/hw6_tests /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests /work/CSCI-104/hw6/avlbst/hw6_tests /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests /work/CSCI-104/hw6/avlbst/hw6_tests/bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bst_tests/CMakeFiles/debug-BSTInsert.InsertZigZigLeft.dir/depend

