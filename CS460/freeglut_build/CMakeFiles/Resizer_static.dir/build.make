# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\antonrasmussen\Desktop\freeglut-3.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\antonrasmussen\Desktop\freeglut_build

# Include any dependencies generated for this target.
include CMakeFiles/Resizer_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Resizer_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Resizer_static.dir/flags.make

CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.obj: CMakeFiles/Resizer_static.dir/flags.make
CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.obj: CMakeFiles/Resizer_static.dir/includes_CXX.rsp
CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.obj: C:/Users/antonrasmussen/Desktop/freeglut-3.0.0/progs/demos/Resizer/Resizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\antonrasmussen\Desktop\freeglut_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.obj"
	C:\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Resizer_static.dir\progs\demos\Resizer\Resizer.cpp.obj -c C:\Users\antonrasmussen\Desktop\freeglut-3.0.0\progs\demos\Resizer\Resizer.cpp

CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.i"
	C:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\antonrasmussen\Desktop\freeglut-3.0.0\progs\demos\Resizer\Resizer.cpp > CMakeFiles\Resizer_static.dir\progs\demos\Resizer\Resizer.cpp.i

CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.s"
	C:\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\antonrasmussen\Desktop\freeglut-3.0.0\progs\demos\Resizer\Resizer.cpp -o CMakeFiles\Resizer_static.dir\progs\demos\Resizer\Resizer.cpp.s

# Object files for target Resizer_static
Resizer_static_OBJECTS = \
"CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.obj"

# External object files for target Resizer_static
Resizer_static_EXTERNAL_OBJECTS =

bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/progs/demos/Resizer/Resizer.cpp.obj
bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/build.make
bin/Resizer_static.exe: lib/libfreeglut_static.a
bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/linklibs.rsp
bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/objects1.rsp
bin/Resizer_static.exe: CMakeFiles/Resizer_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\antonrasmussen\Desktop\freeglut_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\Resizer_static.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Resizer_static.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Resizer_static.dir/build: bin/Resizer_static.exe

.PHONY : CMakeFiles/Resizer_static.dir/build

CMakeFiles/Resizer_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Resizer_static.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Resizer_static.dir/clean

CMakeFiles/Resizer_static.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\antonrasmussen\Desktop\freeglut-3.0.0 C:\Users\antonrasmussen\Desktop\freeglut-3.0.0 C:\Users\antonrasmussen\Desktop\freeglut_build C:\Users\antonrasmussen\Desktop\freeglut_build C:\Users\antonrasmussen\Desktop\freeglut_build\CMakeFiles\Resizer_static.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Resizer_static.dir/depend

