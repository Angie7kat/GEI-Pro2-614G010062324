# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/clases_lista_dinamica.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/clases_lista_dinamica.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clases_lista_dinamica.dir/flags.make

CMakeFiles/clases_lista_dinamica.dir/main.c.obj: CMakeFiles/clases_lista_dinamica.dir/flags.make
CMakeFiles/clases_lista_dinamica.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/clases_lista_dinamica.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\clases_lista_dinamica.dir\main.c.obj -c C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\main.c

CMakeFiles/clases_lista_dinamica.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clases_lista_dinamica.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\main.c > CMakeFiles\clases_lista_dinamica.dir\main.c.i

CMakeFiles/clases_lista_dinamica.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clases_lista_dinamica.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\main.c -o CMakeFiles\clases_lista_dinamica.dir\main.c.s

CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.obj: CMakeFiles/clases_lista_dinamica.dir/flags.make
CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.obj: ../listas_punteros.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\clases_lista_dinamica.dir\listas_punteros.c.obj -c C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\listas_punteros.c

CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\listas_punteros.c > CMakeFiles\clases_lista_dinamica.dir\listas_punteros.c.i

CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\listas_punteros.c -o CMakeFiles\clases_lista_dinamica.dir\listas_punteros.c.s

# Object files for target clases_lista_dinamica
clases_lista_dinamica_OBJECTS = \
"CMakeFiles/clases_lista_dinamica.dir/main.c.obj" \
"CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.obj"

# External object files for target clases_lista_dinamica
clases_lista_dinamica_EXTERNAL_OBJECTS =

clases_lista_dinamica.exe: CMakeFiles/clases_lista_dinamica.dir/main.c.obj
clases_lista_dinamica.exe: CMakeFiles/clases_lista_dinamica.dir/listas_punteros.c.obj
clases_lista_dinamica.exe: CMakeFiles/clases_lista_dinamica.dir/build.make
clases_lista_dinamica.exe: CMakeFiles/clases_lista_dinamica.dir/linklibs.rsp
clases_lista_dinamica.exe: CMakeFiles/clases_lista_dinamica.dir/objects1.rsp
clases_lista_dinamica.exe: CMakeFiles/clases_lista_dinamica.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable clases_lista_dinamica.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\clases_lista_dinamica.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clases_lista_dinamica.dir/build: clases_lista_dinamica.exe
.PHONY : CMakeFiles/clases_lista_dinamica.dir/build

CMakeFiles/clases_lista_dinamica.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\clases_lista_dinamica.dir\cmake_clean.cmake
.PHONY : CMakeFiles/clases_lista_dinamica.dir/clean

CMakeFiles/clases_lista_dinamica.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\cmake-build-debug C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\cmake-build-debug C:\Users\Usuario\CLionProjects\PRO2-2324\clases_lista_dinamica\cmake-build-debug\CMakeFiles\clases_lista_dinamica.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clases_lista_dinamica.dir/depend

