# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rconzc/cs4520/a2/a2_c_refresher_rconzc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rconzc/cs4520/a2/a2_c_refresher_rconzc

# Include any dependencies generated for this target.
include arrays/CMakeFiles/arrays_test.dir/depend.make

# Include the progress variables for this target.
include arrays/CMakeFiles/arrays_test.dir/progress.make

# Include the compile flags for this target's objects.
include arrays/CMakeFiles/arrays_test.dir/flags.make

arrays/CMakeFiles/arrays_test.dir/test/tests.cpp.o: arrays/CMakeFiles/arrays_test.dir/flags.make
arrays/CMakeFiles/arrays_test.dir/test/tests.cpp.o: arrays/test/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rconzc/cs4520/a2/a2_c_refresher_rconzc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object arrays/CMakeFiles/arrays_test.dir/test/tests.cpp.o"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arrays_test.dir/test/tests.cpp.o -c /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays/test/tests.cpp

arrays/CMakeFiles/arrays_test.dir/test/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrays_test.dir/test/tests.cpp.i"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays/test/tests.cpp > CMakeFiles/arrays_test.dir/test/tests.cpp.i

arrays/CMakeFiles/arrays_test.dir/test/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrays_test.dir/test/tests.cpp.s"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays/test/tests.cpp -o CMakeFiles/arrays_test.dir/test/tests.cpp.s

arrays/CMakeFiles/arrays_test.dir/src/arrays.c.o: arrays/CMakeFiles/arrays_test.dir/flags.make
arrays/CMakeFiles/arrays_test.dir/src/arrays.c.o: arrays/src/arrays.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rconzc/cs4520/a2/a2_c_refresher_rconzc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object arrays/CMakeFiles/arrays_test.dir/src/arrays.c.o"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arrays_test.dir/src/arrays.c.o   -c /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays/src/arrays.c

arrays/CMakeFiles/arrays_test.dir/src/arrays.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arrays_test.dir/src/arrays.c.i"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays/src/arrays.c > CMakeFiles/arrays_test.dir/src/arrays.c.i

arrays/CMakeFiles/arrays_test.dir/src/arrays.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arrays_test.dir/src/arrays.c.s"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays/src/arrays.c -o CMakeFiles/arrays_test.dir/src/arrays.c.s

# Object files for target arrays_test
arrays_test_OBJECTS = \
"CMakeFiles/arrays_test.dir/test/tests.cpp.o" \
"CMakeFiles/arrays_test.dir/src/arrays.c.o"

# External object files for target arrays_test
arrays_test_EXTERNAL_OBJECTS =

arrays/arrays_test: arrays/CMakeFiles/arrays_test.dir/test/tests.cpp.o
arrays/arrays_test: arrays/CMakeFiles/arrays_test.dir/src/arrays.c.o
arrays/arrays_test: arrays/CMakeFiles/arrays_test.dir/build.make
arrays/arrays_test: arrays/CMakeFiles/arrays_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rconzc/cs4520/a2/a2_c_refresher_rconzc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable arrays_test"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arrays_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
arrays/CMakeFiles/arrays_test.dir/build: arrays/arrays_test

.PHONY : arrays/CMakeFiles/arrays_test.dir/build

arrays/CMakeFiles/arrays_test.dir/clean:
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays && $(CMAKE_COMMAND) -P CMakeFiles/arrays_test.dir/cmake_clean.cmake
.PHONY : arrays/CMakeFiles/arrays_test.dir/clean

arrays/CMakeFiles/arrays_test.dir/depend:
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rconzc/cs4520/a2/a2_c_refresher_rconzc /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays /home/rconzc/cs4520/a2/a2_c_refresher_rconzc /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/arrays/CMakeFiles/arrays_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : arrays/CMakeFiles/arrays_test.dir/depend

