# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = G:\Jetbrains\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = G:\Jetbrains\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\GitHub\Ceebles Quest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\GitHub\Ceebles Quest\cmake-build-debug"

# Utility rule file for Build_ROM.

# Include any custom commands dependencies for this target.
include CMakeFiles/Build_ROM.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Build_ROM.dir/progress.make

CMakeFiles/Build_ROM: D:/GitHub/Ceebles\ Quest/build/game.gb

D:/GitHub/Ceebles\ Quest/build/game.gb: D:/GitHub/Ceebles\ Quest/src/*.c
D:/GitHub/Ceebles\ Quest/build/game.gb: D:/GitHub/Ceebles\ Quest/src/core/*.c
D:/GitHub/Ceebles\ Quest/build/game.gb: D:/GitHub/Ceebles\ Quest/src/data/*.c
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="D:\GitHub\Ceebles Quest\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building game.gb with lcc"
	G:\gbdk\bin\lcc -IG:/gbdk/include "-ID:/GitHub/Ceebles Quest/include" -debug -o "D:/GitHub/Ceebles Quest/build/game.gb" "D:/GitHub/Ceebles Quest/src/*.c" "D:/GitHub/Ceebles Quest/src/core/*.c" "D:/GitHub/Ceebles Quest/src/data/*.c"

Build_ROM: D:/GitHub/Ceebles\ Quest/build/game.gb
Build_ROM: CMakeFiles/Build_ROM
Build_ROM: CMakeFiles/Build_ROM.dir/build.make
.PHONY : Build_ROM

# Rule to build all files generated by this target.
CMakeFiles/Build_ROM.dir/build: Build_ROM
.PHONY : CMakeFiles/Build_ROM.dir/build

CMakeFiles/Build_ROM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Build_ROM.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Build_ROM.dir/clean

CMakeFiles/Build_ROM.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\GitHub\Ceebles Quest" "D:\GitHub\Ceebles Quest" "D:\GitHub\Ceebles Quest\cmake-build-debug" "D:\GitHub\Ceebles Quest\cmake-build-debug" "D:\GitHub\Ceebles Quest\cmake-build-debug\CMakeFiles\Build_ROM.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Build_ROM.dir/depend
