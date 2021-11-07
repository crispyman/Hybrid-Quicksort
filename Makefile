# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /home/andrewiii/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/andrewiii/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrewiii/CLionProjects/Hybrid-Quicksort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrewiii/CLionProjects/Hybrid-Quicksort

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/andrewiii/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/andrewiii/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andrewiii/CLionProjects/Hybrid-Quicksort/CMakeFiles /home/andrewiii/CLionProjects/Hybrid-Quicksort//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/andrewiii/CLionProjects/Hybrid-Quicksort/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Hybrid_Quicksort

# Build rule for target.
Hybrid_Quicksort: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Hybrid_Quicksort
.PHONY : Hybrid_Quicksort

# fast build rule for target.
Hybrid_Quicksort/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/build
.PHONY : Hybrid_Quicksort/fast

Main.o: Main.cpp.o
.PHONY : Main.o

# target to build an object file
Main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/Main.cpp.o
.PHONY : Main.cpp.o

Main.i: Main.cpp.i
.PHONY : Main.i

# target to preprocess a source file
Main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/Main.cpp.i
.PHONY : Main.cpp.i

Main.s: Main.cpp.s
.PHONY : Main.s

# target to generate assembly for a file
Main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/Main.cpp.s
.PHONY : Main.cpp.s

hf.o: hf.cpp.o
.PHONY : hf.o

# target to build an object file
hf.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/hf.cpp.o
.PHONY : hf.cpp.o

hf.i: hf.cpp.i
.PHONY : hf.i

# target to preprocess a source file
hf.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/hf.cpp.i
.PHONY : hf.cpp.i

hf.s: hf.cpp.s
.PHONY : hf.s

# target to generate assembly for a file
hf.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/hf.cpp.s
.PHONY : hf.cpp.s

hoare.o: hoare.cpp.o
.PHONY : hoare.o

# target to build an object file
hoare.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/hoare.cpp.o
.PHONY : hoare.cpp.o

hoare.i: hoare.cpp.i
.PHONY : hoare.i

# target to preprocess a source file
hoare.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/hoare.cpp.i
.PHONY : hoare.cpp.i

hoare.s: hoare.cpp.s
.PHONY : hoare.s

# target to generate assembly for a file
hoare.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/hoare.cpp.s
.PHONY : hoare.cpp.s

lomuto.o: lomuto.cpp.o
.PHONY : lomuto.o

# target to build an object file
lomuto.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/lomuto.cpp.o
.PHONY : lomuto.cpp.o

lomuto.i: lomuto.cpp.i
.PHONY : lomuto.i

# target to preprocess a source file
lomuto.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/lomuto.cpp.i
.PHONY : lomuto.cpp.i

lomuto.s: lomuto.cpp.s
.PHONY : lomuto.s

# target to generate assembly for a file
lomuto.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/lomuto.cpp.s
.PHONY : lomuto.cpp.s

m5.o: m5.cpp.o
.PHONY : m5.o

# target to build an object file
m5.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/m5.cpp.o
.PHONY : m5.cpp.o

m5.i: m5.cpp.i
.PHONY : m5.i

# target to preprocess a source file
m5.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/m5.cpp.i
.PHONY : m5.cpp.i

m5.s: m5.cpp.s
.PHONY : m5.s

# target to generate assembly for a file
m5.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/m5.cpp.s
.PHONY : m5.cpp.s

shell.o: shell.cpp.o
.PHONY : shell.o

# target to build an object file
shell.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/shell.cpp.o
.PHONY : shell.cpp.o

shell.i: shell.cpp.i
.PHONY : shell.i

# target to preprocess a source file
shell.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/shell.cpp.i
.PHONY : shell.cpp.i

shell.s: shell.cpp.s
.PHONY : shell.s

# target to generate assembly for a file
shell.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Hybrid_Quicksort.dir/build.make CMakeFiles/Hybrid_Quicksort.dir/shell.cpp.s
.PHONY : shell.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Hybrid_Quicksort"
	@echo "... Main.o"
	@echo "... Main.i"
	@echo "... Main.s"
	@echo "... hf.o"
	@echo "... hf.i"
	@echo "... hf.s"
	@echo "... hoare.o"
	@echo "... hoare.i"
	@echo "... hoare.s"
	@echo "... lomuto.o"
	@echo "... lomuto.i"
	@echo "... lomuto.s"
	@echo "... m5.o"
	@echo "... m5.i"
	@echo "... m5.s"
	@echo "... shell.o"
	@echo "... shell.i"
	@echo "... shell.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

