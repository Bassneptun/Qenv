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
include CMakeFiles/utils_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/utils_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/utils_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/utils_test.dir/flags.make

CMakeFiles/utils_test.dir/tests/utils.cpp.o: CMakeFiles/utils_test.dir/flags.make
CMakeFiles/utils_test.dir/tests/utils.cpp.o: /home/jeremy/qtest_env/tests/utils.cpp
CMakeFiles/utils_test.dir/tests/utils.cpp.o: CMakeFiles/utils_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremy/qtest_env/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/utils_test.dir/tests/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/utils_test.dir/tests/utils.cpp.o -MF CMakeFiles/utils_test.dir/tests/utils.cpp.o.d -o CMakeFiles/utils_test.dir/tests/utils.cpp.o -c /home/jeremy/qtest_env/tests/utils.cpp

CMakeFiles/utils_test.dir/tests/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils_test.dir/tests/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremy/qtest_env/tests/utils.cpp > CMakeFiles/utils_test.dir/tests/utils.cpp.i

CMakeFiles/utils_test.dir/tests/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils_test.dir/tests/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremy/qtest_env/tests/utils.cpp -o CMakeFiles/utils_test.dir/tests/utils.cpp.s

# Object files for target utils_test
utils_test_OBJECTS = \
"CMakeFiles/utils_test.dir/tests/utils.cpp.o"

# External object files for target utils_test
utils_test_EXTERNAL_OBJECTS =

utils_test: CMakeFiles/utils_test.dir/tests/utils.cpp.o
utils_test: CMakeFiles/utils_test.dir/build.make
utils_test: libqenv.a
utils_test: /usr/lib/libarmadillo.so
utils_test: /usr/lib/x86_64-linux-gnu/libgtest_main.a
utils_test: /usr/lib/x86_64-linux-gnu/libgtest.a
utils_test: CMakeFiles/utils_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremy/qtest_env/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable utils_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/utils_test.dir/build: utils_test
.PHONY : CMakeFiles/utils_test.dir/build

CMakeFiles/utils_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/utils_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/utils_test.dir/clean

CMakeFiles/utils_test.dir/depend:
	cd /home/jeremy/qtest_env/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremy/qtest_env /home/jeremy/qtest_env /home/jeremy/qtest_env/build /home/jeremy/qtest_env/build /home/jeremy/qtest_env/build/CMakeFiles/utils_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/utils_test.dir/depend

