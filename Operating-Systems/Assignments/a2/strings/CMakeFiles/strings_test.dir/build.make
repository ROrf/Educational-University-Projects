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
include strings/CMakeFiles/strings_test.dir/depend.make

# Include the progress variables for this target.
include strings/CMakeFiles/strings_test.dir/progress.make

# Include the compile flags for this target's objects.
include strings/CMakeFiles/strings_test.dir/flags.make

strings/CMakeFiles/strings_test.dir/test/tests.cpp.o: strings/CMakeFiles/strings_test.dir/flags.make
strings/CMakeFiles/strings_test.dir/test/tests.cpp.o: strings/test/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rconzc/cs4520/a2/a2_c_refresher_rconzc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object strings/CMakeFiles/strings_test.dir/test/tests.cpp.o"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/strings_test.dir/test/tests.cpp.o -c /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings/test/tests.cpp

strings/CMakeFiles/strings_test.dir/test/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/strings_test.dir/test/tests.cpp.i"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings/test/tests.cpp > CMakeFiles/strings_test.dir/test/tests.cpp.i

strings/CMakeFiles/strings_test.dir/test/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/strings_test.dir/test/tests.cpp.s"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings/test/tests.cpp -o CMakeFiles/strings_test.dir/test/tests.cpp.s

strings/CMakeFiles/strings_test.dir/src/sstring.c.o: strings/CMakeFiles/strings_test.dir/flags.make
strings/CMakeFiles/strings_test.dir/src/sstring.c.o: strings/src/sstring.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rconzc/cs4520/a2/a2_c_refresher_rconzc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object strings/CMakeFiles/strings_test.dir/src/sstring.c.o"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strings_test.dir/src/sstring.c.o   -c /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings/src/sstring.c

strings/CMakeFiles/strings_test.dir/src/sstring.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strings_test.dir/src/sstring.c.i"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings/src/sstring.c > CMakeFiles/strings_test.dir/src/sstring.c.i

strings/CMakeFiles/strings_test.dir/src/sstring.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strings_test.dir/src/sstring.c.s"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings/src/sstring.c -o CMakeFiles/strings_test.dir/src/sstring.c.s

# Object files for target strings_test
strings_test_OBJECTS = \
"CMakeFiles/strings_test.dir/test/tests.cpp.o" \
"CMakeFiles/strings_test.dir/src/sstring.c.o"

# External object files for target strings_test
strings_test_EXTERNAL_OBJECTS =

strings/strings_test: strings/CMakeFiles/strings_test.dir/test/tests.cpp.o
strings/strings_test: strings/CMakeFiles/strings_test.dir/src/sstring.c.o
strings/strings_test: strings/CMakeFiles/strings_test.dir/build.make
strings/strings_test: strings/CMakeFiles/strings_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rconzc/cs4520/a2/a2_c_refresher_rconzc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable strings_test"
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strings_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
strings/CMakeFiles/strings_test.dir/build: strings/strings_test

.PHONY : strings/CMakeFiles/strings_test.dir/build

strings/CMakeFiles/strings_test.dir/clean:
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings && $(CMAKE_COMMAND) -P CMakeFiles/strings_test.dir/cmake_clean.cmake
.PHONY : strings/CMakeFiles/strings_test.dir/clean

strings/CMakeFiles/strings_test.dir/depend:
	cd /home/rconzc/cs4520/a2/a2_c_refresher_rconzc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rconzc/cs4520/a2/a2_c_refresher_rconzc /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings /home/rconzc/cs4520/a2/a2_c_refresher_rconzc /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings /home/rconzc/cs4520/a2/a2_c_refresher_rconzc/strings/CMakeFiles/strings_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : strings/CMakeFiles/strings_test.dir/depend
