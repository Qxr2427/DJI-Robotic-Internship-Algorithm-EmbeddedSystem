# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robomaster/robomaster/homework/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robomaster/robomaster/homework/src/cmake-build-debug

# Include any dependencies generated for this target.
include practice/CMakeFiles/practice.dir/depend.make

# Include the progress variables for this target.
include practice/CMakeFiles/practice.dir/progress.make

# Include the compile flags for this target's objects.
include practice/CMakeFiles/practice.dir/flags.make

practice/CMakeFiles/practice.dir/make_a_move.cpp.o: practice/CMakeFiles/practice.dir/flags.make
practice/CMakeFiles/practice.dir/make_a_move.cpp.o: ../practice/make_a_move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robomaster/robomaster/homework/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object practice/CMakeFiles/practice.dir/make_a_move.cpp.o"
	cd /home/robomaster/robomaster/homework/src/cmake-build-debug/practice && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practice.dir/make_a_move.cpp.o -c /home/robomaster/robomaster/homework/src/practice/make_a_move.cpp

practice/CMakeFiles/practice.dir/make_a_move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practice.dir/make_a_move.cpp.i"
	cd /home/robomaster/robomaster/homework/src/cmake-build-debug/practice && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robomaster/robomaster/homework/src/practice/make_a_move.cpp > CMakeFiles/practice.dir/make_a_move.cpp.i

practice/CMakeFiles/practice.dir/make_a_move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practice.dir/make_a_move.cpp.s"
	cd /home/robomaster/robomaster/homework/src/cmake-build-debug/practice && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robomaster/robomaster/homework/src/practice/make_a_move.cpp -o CMakeFiles/practice.dir/make_a_move.cpp.s

# Object files for target practice
practice_OBJECTS = \
"CMakeFiles/practice.dir/make_a_move.cpp.o"

# External object files for target practice
practice_EXTERNAL_OBJECTS =

devel/lib/practice/practice: practice/CMakeFiles/practice.dir/make_a_move.cpp.o
devel/lib/practice/practice: practice/CMakeFiles/practice.dir/build.make
devel/lib/practice/practice: /opt/ros/kinetic/lib/libtf.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libtf2_ros.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libactionlib.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libmessage_filters.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libroscpp.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_signals.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libxmlrpcpp.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libtf2.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libroscpp_serialization.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/librosconsole.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/librostime.so
devel/lib/practice/practice: /opt/ros/kinetic/lib/libcpp_common.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/practice/practice: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
devel/lib/practice/practice: practice/CMakeFiles/practice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robomaster/robomaster/homework/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../devel/lib/practice/practice"
	cd /home/robomaster/robomaster/homework/src/cmake-build-debug/practice && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
practice/CMakeFiles/practice.dir/build: devel/lib/practice/practice

.PHONY : practice/CMakeFiles/practice.dir/build

practice/CMakeFiles/practice.dir/clean:
	cd /home/robomaster/robomaster/homework/src/cmake-build-debug/practice && $(CMAKE_COMMAND) -P CMakeFiles/practice.dir/cmake_clean.cmake
.PHONY : practice/CMakeFiles/practice.dir/clean

practice/CMakeFiles/practice.dir/depend:
	cd /home/robomaster/robomaster/homework/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robomaster/robomaster/homework/src /home/robomaster/robomaster/homework/src/practice /home/robomaster/robomaster/homework/src/cmake-build-debug /home/robomaster/robomaster/homework/src/cmake-build-debug/practice /home/robomaster/robomaster/homework/src/cmake-build-debug/practice/CMakeFiles/practice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : practice/CMakeFiles/practice.dir/depend

