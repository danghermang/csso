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
CMAKE_SOURCE_DIR = "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tema2Clion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tema2Clion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tema2Clion.dir/flags.make

CMakeFiles/Tema2Clion.dir/Part1.cpp.obj: CMakeFiles/Tema2Clion.dir/flags.make
CMakeFiles/Tema2Clion.dir/Part1.cpp.obj: ../Part1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tema2Clion.dir/Part1.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tema2Clion.dir\Part1.cpp.obj -c "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\Part1.cpp"

CMakeFiles/Tema2Clion.dir/Part1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tema2Clion.dir/Part1.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\Part1.cpp" > CMakeFiles\Tema2Clion.dir\Part1.cpp.i

CMakeFiles/Tema2Clion.dir/Part1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tema2Clion.dir/Part1.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\Part1.cpp" -o CMakeFiles\Tema2Clion.dir\Part1.cpp.s

CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.requires:

.PHONY : CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.requires

CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.provides: CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Tema2Clion.dir\build.make CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.provides.build
.PHONY : CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.provides

CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.provides.build: CMakeFiles/Tema2Clion.dir/Part1.cpp.obj


# Object files for target Tema2Clion
Tema2Clion_OBJECTS = \
"CMakeFiles/Tema2Clion.dir/Part1.cpp.obj"

# External object files for target Tema2Clion
Tema2Clion_EXTERNAL_OBJECTS =

Tema2Clion.exe: CMakeFiles/Tema2Clion.dir/Part1.cpp.obj
Tema2Clion.exe: CMakeFiles/Tema2Clion.dir/build.make
Tema2Clion.exe: CMakeFiles/Tema2Clion.dir/linklibs.rsp
Tema2Clion.exe: CMakeFiles/Tema2Clion.dir/objects1.rsp
Tema2Clion.exe: CMakeFiles/Tema2Clion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tema2Clion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tema2Clion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tema2Clion.dir/build: Tema2Clion.exe

.PHONY : CMakeFiles/Tema2Clion.dir/build

CMakeFiles/Tema2Clion.dir/requires: CMakeFiles/Tema2Clion.dir/Part1.cpp.obj.requires

.PHONY : CMakeFiles/Tema2Clion.dir/requires

CMakeFiles/Tema2Clion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tema2Clion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tema2Clion.dir/clean

CMakeFiles/Tema2Clion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion" "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion" "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\cmake-build-debug" "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\cmake-build-debug" "D:\Facultate\an 3 sem 1\CSSO\Tema2Clion\cmake-build-debug\CMakeFiles\Tema2Clion.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tema2Clion.dir/depend
