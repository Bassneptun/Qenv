# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeremy/qtest_env

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeremy/qtest_env/build

# Include any dependencies generated for this target.
include CMakeFiles/alloc_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/alloc_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/alloc_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alloc_test.dir/flags.make

CMakeFiles/alloc_test.dir/tests/alloc.cpp.o: CMakeFiles/alloc_test.dir/flags.make
CMakeFiles/alloc_test.dir/tests/alloc.cpp.o: /home/jeremy/qtest_env/tests/alloc.cpp
CMakeFiles/alloc_test.dir/tests/alloc.cpp.o: CMakeFiles/alloc_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremy/qtest_env/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alloc_test.dir/tests/alloc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/alloc_test.dir/tests/alloc.cpp.o -MF CMakeFiles/alloc_test.dir/tests/alloc.cpp.o.d -o CMakeFiles/alloc_test.dir/tests/alloc.cpp.o -c /home/jeremy/qtest_env/tests/alloc.cpp

CMakeFiles/alloc_test.dir/tests/alloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alloc_test.dir/tests/alloc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremy/qtest_env/tests/alloc.cpp > CMakeFiles/alloc_test.dir/tests/alloc.cpp.i

CMakeFiles/alloc_test.dir/tests/alloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alloc_test.dir/tests/alloc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremy/qtest_env/tests/alloc.cpp -o CMakeFiles/alloc_test.dir/tests/alloc.cpp.s

# Object files for target alloc_test
alloc_test_OBJECTS = \
"CMakeFiles/alloc_test.dir/tests/alloc.cpp.o"

# External object files for target alloc_test
alloc_test_EXTERNAL_OBJECTS =

alloc_test: CMakeFiles/alloc_test.dir/tests/alloc.cpp.o
alloc_test: CMakeFiles/alloc_test.dir/build.make
alloc_test: libqenv.a
alloc_test: /usr/lib/libarmadillo.so
alloc_test: /usr/lib/x86_64-linux-gnu/libgtest_main.a
alloc_test: /usr/lib/x86_64-linux-gnu/libgtest.a
alloc_test: CMakeFiles/alloc_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremy/qtest_env/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable alloc_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alloc_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alloc_test.dir/build: alloc_test
.PHONY : CMakeFiles/alloc_test.dir/build

CMakeFiles/alloc_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alloc_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alloc_test.dir/clean

CMakeFiles/alloc_test.dir/depend:
	cd /home/jeremy/qtest_env/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremy/qtest_env /home/jeremy/qtest_env /home/jeremy/qtest_env/build /home/jeremy/qtest_env/build /home/jeremy/qtest_env/build/CMakeFiles/alloc_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alloc_test.dir/depend

