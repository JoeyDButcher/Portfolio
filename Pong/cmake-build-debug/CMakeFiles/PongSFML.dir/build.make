# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\joeyb\AppData\Local\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\joeyb\AppData\Local\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PongSFML.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PongSFML.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PongSFML.dir/flags.make

CMakeFiles/PongSFML.dir/src/main.cpp.obj: CMakeFiles/PongSFML.dir/flags.make
CMakeFiles/PongSFML.dir/src/main.cpp.obj: CMakeFiles/PongSFML.dir/includes_CXX.rsp
CMakeFiles/PongSFML.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PongSFML.dir/src/main.cpp.obj"
	C:\NOTAVI~1\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PongSFML.dir\src\main.cpp.obj -c "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\src\main.cpp"

CMakeFiles/PongSFML.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongSFML.dir/src/main.cpp.i"
	C:\NOTAVI~1\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\src\main.cpp" > CMakeFiles\PongSFML.dir\src\main.cpp.i

CMakeFiles/PongSFML.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongSFML.dir/src/main.cpp.s"
	C:\NOTAVI~1\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\src\main.cpp" -o CMakeFiles\PongSFML.dir\src\main.cpp.s

CMakeFiles/PongSFML.dir/src/Game.cpp.obj: CMakeFiles/PongSFML.dir/flags.make
CMakeFiles/PongSFML.dir/src/Game.cpp.obj: CMakeFiles/PongSFML.dir/includes_CXX.rsp
CMakeFiles/PongSFML.dir/src/Game.cpp.obj: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PongSFML.dir/src/Game.cpp.obj"
	C:\NOTAVI~1\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PongSFML.dir\src\Game.cpp.obj -c "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\src\Game.cpp"

CMakeFiles/PongSFML.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PongSFML.dir/src/Game.cpp.i"
	C:\NOTAVI~1\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\src\Game.cpp" > CMakeFiles\PongSFML.dir\src\Game.cpp.i

CMakeFiles/PongSFML.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PongSFML.dir/src/Game.cpp.s"
	C:\NOTAVI~1\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\src\Game.cpp" -o CMakeFiles\PongSFML.dir\src\Game.cpp.s

# Object files for target PongSFML
PongSFML_OBJECTS = \
"CMakeFiles/PongSFML.dir/src/main.cpp.obj" \
"CMakeFiles/PongSFML.dir/src/Game.cpp.obj"

# External object files for target PongSFML
PongSFML_EXTERNAL_OBJECTS =

PongSFML.exe: CMakeFiles/PongSFML.dir/src/main.cpp.obj
PongSFML.exe: CMakeFiles/PongSFML.dir/src/Game.cpp.obj
PongSFML.exe: CMakeFiles/PongSFML.dir/build.make
PongSFML.exe: C:/SFML-2.5.1/lib/libsfml-graphics-s-d.a
PongSFML.exe: C:/SFML-2.5.1/lib/libsfml-window-s-d.a
PongSFML.exe: C:/SFML-2.5.1/lib/libsfml-system-s-d.a
PongSFML.exe: C:/SFML-2.5.1/lib/libsfml-network-s-d.a
PongSFML.exe: C:/SFML-2.5.1/lib/libsfml-audio-s-d.a
PongSFML.exe: C:/SFML-2.5.1/lib/libfreetype.a
PongSFML.exe: C:/SFML-2.5.1/lib/libsfml-system-s-d.a
PongSFML.exe: C:/SFML-2.5.1/lib/libopenal32.a
PongSFML.exe: C:/SFML-2.5.1/lib/libvorbisfile.a
PongSFML.exe: C:/SFML-2.5.1/lib/libvorbisenc.a
PongSFML.exe: C:/SFML-2.5.1/lib/libvorbis.a
PongSFML.exe: C:/SFML-2.5.1/lib/libogg.a
PongSFML.exe: C:/SFML-2.5.1/lib/libFLAC.a
PongSFML.exe: CMakeFiles/PongSFML.dir/linklibs.rsp
PongSFML.exe: CMakeFiles/PongSFML.dir/objects1.rsp
PongSFML.exe: CMakeFiles/PongSFML.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PongSFML.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PongSFML.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PongSFML.dir/build: PongSFML.exe

.PHONY : CMakeFiles/PongSFML.dir/build

CMakeFiles/PongSFML.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PongSFML.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PongSFML.dir/clean

CMakeFiles/PongSFML.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro" "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro" "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\cmake-build-debug" "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\cmake-build-debug" "C:\Users\joeyb\Documents\uni repos\pong-2020-CTRLRetro\cmake-build-debug\CMakeFiles\PongSFML.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PongSFML.dir/depend

