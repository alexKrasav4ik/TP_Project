# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/krasav4ik/TP_Project/TP_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krasav4ik/TP_Project/TP_Project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/field_builder.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/field_builder.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/field_builder.dir/flags.make

src/CMakeFiles/field_builder.dir/Field_builder.cpp.o: src/CMakeFiles/field_builder.dir/flags.make
src/CMakeFiles/field_builder.dir/Field_builder.cpp.o: ../src/Field_builder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krasav4ik/TP_Project/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/field_builder.dir/Field_builder.cpp.o"
	cd /home/krasav4ik/TP_Project/TP_Project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/field_builder.dir/Field_builder.cpp.o -c /home/krasav4ik/TP_Project/TP_Project/src/Field_builder.cpp

src/CMakeFiles/field_builder.dir/Field_builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/field_builder.dir/Field_builder.cpp.i"
	cd /home/krasav4ik/TP_Project/TP_Project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krasav4ik/TP_Project/TP_Project/src/Field_builder.cpp > CMakeFiles/field_builder.dir/Field_builder.cpp.i

src/CMakeFiles/field_builder.dir/Field_builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/field_builder.dir/Field_builder.cpp.s"
	cd /home/krasav4ik/TP_Project/TP_Project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krasav4ik/TP_Project/TP_Project/src/Field_builder.cpp -o CMakeFiles/field_builder.dir/Field_builder.cpp.s

# Object files for target field_builder
field_builder_OBJECTS = \
"CMakeFiles/field_builder.dir/Field_builder.cpp.o"

# External object files for target field_builder
field_builder_EXTERNAL_OBJECTS =

../lib/libfield_builder.so: src/CMakeFiles/field_builder.dir/Field_builder.cpp.o
../lib/libfield_builder.so: src/CMakeFiles/field_builder.dir/build.make
../lib/libfield_builder.so: ../lib/libfield.so
../lib/libfield_builder.so: ../lib/libship.so
../lib/libfield_builder.so: src/CMakeFiles/field_builder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krasav4ik/TP_Project/TP_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libfield_builder.so"
	cd /home/krasav4ik/TP_Project/TP_Project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/field_builder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/field_builder.dir/build: ../lib/libfield_builder.so

.PHONY : src/CMakeFiles/field_builder.dir/build

src/CMakeFiles/field_builder.dir/clean:
	cd /home/krasav4ik/TP_Project/TP_Project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/field_builder.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/field_builder.dir/clean

src/CMakeFiles/field_builder.dir/depend:
	cd /home/krasav4ik/TP_Project/TP_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krasav4ik/TP_Project/TP_Project /home/krasav4ik/TP_Project/TP_Project/src /home/krasav4ik/TP_Project/TP_Project/build /home/krasav4ik/TP_Project/TP_Project/build/src /home/krasav4ik/TP_Project/TP_Project/build/src/CMakeFiles/field_builder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/field_builder.dir/depend

