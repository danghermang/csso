# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "D:\Programe\Instalate\CLion 2017.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programe\Instalate\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tema2_part2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tema2_part2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tema2_part2.dir/flags.make

CMakeFiles/Tema2_part2.dir/main.cpp.obj: CMakeFiles/Tema2_part2.dir/flags.make
CMakeFiles/Tema2_part2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tema2_part2.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tema2_part2.dir\main.cpp.obj -c "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\main.cpp"

CMakeFiles/Tema2_part2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tema2_part2.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\main.cpp" > CMakeFiles\Tema2_part2.dir\main.cpp.i

CMakeFiles/Tema2_part2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tema2_part2.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\main.cpp" -o CMakeFiles\Tema2_part2.dir\main.cpp.s

CMakeFiles/Tema2_part2.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Tema2_part2.dir/main.cpp.obj.requires

CMakeFiles/Tema2_part2.dir/main.cpp.obj.provides: CMakeFiles/Tema2_part2.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Tema2_part2.dir\build.make CMakeFiles/Tema2_part2.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Tema2_part2.dir/main.cpp.obj.provides

CMakeFiles/Tema2_part2.dir/main.cpp.obj.provides.build: CMakeFiles/Tema2_part2.dir/main.cpp.obj


# Object files for target Tema2_part2
Tema2_part2_OBJECTS = \
"CMakeFiles/Tema2_part2.dir/main.cpp.obj"

# External object files for target Tema2_part2
Tema2_part2_EXTERNAL_OBJECTS =

Tema2_part2.exe: CMakeFiles/Tema2_part2.dir/main.cpp.obj
Tema2_part2.exe: CMakeFiles/Tema2_part2.dir/build.make
Tema2_part2.exe: CMakeFiles/Tema2_part2.dir/linklibs.rsp
Tema2_part2.exe: CMakeFiles/Tema2_part2.dir/objects1.rsp
Tema2_part2.exe: CMakeFiles/Tema2_part2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tema2_part2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tema2_part2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tema2_part2.dir/build: Tema2_part2.exe

.PHONY : CMakeFiles/Tema2_part2.dir/build

CMakeFiles/Tema2_part2.dir/requires: CMakeFiles/Tema2_part2.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Tema2_part2.dir/requires

CMakeFiles/Tema2_part2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tema2_part2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tema2_part2.dir/clean

CMakeFiles/Tema2_part2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2" "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2" "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\cmake-build-debug" "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\cmake-build-debug" "D:\Facultate\an 3 sem 1\CSSO\Tema2_part2\cmake-build-debug\CMakeFiles\Tema2_part2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tema2_part2.dir/depend
