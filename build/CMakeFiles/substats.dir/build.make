# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/user/code/subrating

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/code/subrating/build

# Include any dependencies generated for this target.
include CMakeFiles/substats.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/substats.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/substats.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/substats.dir/flags.make

CMakeFiles/substats.dir/codegen:
.PHONY : CMakeFiles/substats.dir/codegen

CMakeFiles/substats.dir/src/main.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/main.cc.o: /home/user/code/subrating/src/main.cc
CMakeFiles/substats.dir/src/main.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/substats.dir/src/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/main.cc.o -MF CMakeFiles/substats.dir/src/main.cc.o.d -o CMakeFiles/substats.dir/src/main.cc.o -c /home/user/code/subrating/src/main.cc

CMakeFiles/substats.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/main.cc > CMakeFiles/substats.dir/src/main.cc.i

CMakeFiles/substats.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/main.cc -o CMakeFiles/substats.dir/src/main.cc.s

CMakeFiles/substats.dir/src/models/subscriber.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/models/subscriber.cc.o: /home/user/code/subrating/src/models/subscriber.cc
CMakeFiles/substats.dir/src/models/subscriber.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/substats.dir/src/models/subscriber.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/models/subscriber.cc.o -MF CMakeFiles/substats.dir/src/models/subscriber.cc.o.d -o CMakeFiles/substats.dir/src/models/subscriber.cc.o -c /home/user/code/subrating/src/models/subscriber.cc

CMakeFiles/substats.dir/src/models/subscriber.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/models/subscriber.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/models/subscriber.cc > CMakeFiles/substats.dir/src/models/subscriber.cc.i

CMakeFiles/substats.dir/src/models/subscriber.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/models/subscriber.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/models/subscriber.cc -o CMakeFiles/substats.dir/src/models/subscriber.cc.s

CMakeFiles/substats.dir/src/services/convert.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/services/convert.cc.o: /home/user/code/subrating/src/services/convert.cc
CMakeFiles/substats.dir/src/services/convert.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/substats.dir/src/services/convert.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/services/convert.cc.o -MF CMakeFiles/substats.dir/src/services/convert.cc.o.d -o CMakeFiles/substats.dir/src/services/convert.cc.o -c /home/user/code/subrating/src/services/convert.cc

CMakeFiles/substats.dir/src/services/convert.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/services/convert.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/services/convert.cc > CMakeFiles/substats.dir/src/services/convert.cc.i

CMakeFiles/substats.dir/src/services/convert.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/services/convert.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/services/convert.cc -o CMakeFiles/substats.dir/src/services/convert.cc.s

CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o: /home/user/code/subrating/src/services/subscriber_manager.cc
CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o -MF CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o.d -o CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o -c /home/user/code/subrating/src/services/subscriber_manager.cc

CMakeFiles/substats.dir/src/services/subscriber_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/services/subscriber_manager.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/services/subscriber_manager.cc > CMakeFiles/substats.dir/src/services/subscriber_manager.cc.i

CMakeFiles/substats.dir/src/services/subscriber_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/services/subscriber_manager.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/services/subscriber_manager.cc -o CMakeFiles/substats.dir/src/services/subscriber_manager.cc.s

CMakeFiles/substats.dir/src/ui/header_window.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/header_window.cc.o: /home/user/code/subrating/src/ui/header_window.cc
CMakeFiles/substats.dir/src/ui/header_window.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/substats.dir/src/ui/header_window.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/header_window.cc.o -MF CMakeFiles/substats.dir/src/ui/header_window.cc.o.d -o CMakeFiles/substats.dir/src/ui/header_window.cc.o -c /home/user/code/subrating/src/ui/header_window.cc

CMakeFiles/substats.dir/src/ui/header_window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/header_window.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/header_window.cc > CMakeFiles/substats.dir/src/ui/header_window.cc.i

CMakeFiles/substats.dir/src/ui/header_window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/header_window.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/header_window.cc -o CMakeFiles/substats.dir/src/ui/header_window.cc.s

CMakeFiles/substats.dir/src/ui/input_manager.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/input_manager.cc.o: /home/user/code/subrating/src/ui/input_manager.cc
CMakeFiles/substats.dir/src/ui/input_manager.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/substats.dir/src/ui/input_manager.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/input_manager.cc.o -MF CMakeFiles/substats.dir/src/ui/input_manager.cc.o.d -o CMakeFiles/substats.dir/src/ui/input_manager.cc.o -c /home/user/code/subrating/src/ui/input_manager.cc

CMakeFiles/substats.dir/src/ui/input_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/input_manager.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/input_manager.cc > CMakeFiles/substats.dir/src/ui/input_manager.cc.i

CMakeFiles/substats.dir/src/ui/input_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/input_manager.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/input_manager.cc -o CMakeFiles/substats.dir/src/ui/input_manager.cc.s

CMakeFiles/substats.dir/src/ui/layout_manager.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/layout_manager.cc.o: /home/user/code/subrating/src/ui/layout_manager.cc
CMakeFiles/substats.dir/src/ui/layout_manager.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/substats.dir/src/ui/layout_manager.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/layout_manager.cc.o -MF CMakeFiles/substats.dir/src/ui/layout_manager.cc.o.d -o CMakeFiles/substats.dir/src/ui/layout_manager.cc.o -c /home/user/code/subrating/src/ui/layout_manager.cc

CMakeFiles/substats.dir/src/ui/layout_manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/layout_manager.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/layout_manager.cc > CMakeFiles/substats.dir/src/ui/layout_manager.cc.i

CMakeFiles/substats.dir/src/ui/layout_manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/layout_manager.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/layout_manager.cc -o CMakeFiles/substats.dir/src/ui/layout_manager.cc.s

CMakeFiles/substats.dir/src/ui/logo_window.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/logo_window.cc.o: /home/user/code/subrating/src/ui/logo_window.cc
CMakeFiles/substats.dir/src/ui/logo_window.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/substats.dir/src/ui/logo_window.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/logo_window.cc.o -MF CMakeFiles/substats.dir/src/ui/logo_window.cc.o.d -o CMakeFiles/substats.dir/src/ui/logo_window.cc.o -c /home/user/code/subrating/src/ui/logo_window.cc

CMakeFiles/substats.dir/src/ui/logo_window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/logo_window.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/logo_window.cc > CMakeFiles/substats.dir/src/ui/logo_window.cc.i

CMakeFiles/substats.dir/src/ui/logo_window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/logo_window.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/logo_window.cc -o CMakeFiles/substats.dir/src/ui/logo_window.cc.s

CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o: /home/user/code/subrating/src/ui/sub_form_window.cc
CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o -MF CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o.d -o CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o -c /home/user/code/subrating/src/ui/sub_form_window.cc

CMakeFiles/substats.dir/src/ui/sub_form_window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/sub_form_window.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/sub_form_window.cc > CMakeFiles/substats.dir/src/ui/sub_form_window.cc.i

CMakeFiles/substats.dir/src/ui/sub_form_window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/sub_form_window.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/sub_form_window.cc -o CMakeFiles/substats.dir/src/ui/sub_form_window.cc.s

CMakeFiles/substats.dir/src/ui/ui.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/ui.cc.o: /home/user/code/subrating/src/ui/ui.cc
CMakeFiles/substats.dir/src/ui/ui.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/substats.dir/src/ui/ui.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/ui.cc.o -MF CMakeFiles/substats.dir/src/ui/ui.cc.o.d -o CMakeFiles/substats.dir/src/ui/ui.cc.o -c /home/user/code/subrating/src/ui/ui.cc

CMakeFiles/substats.dir/src/ui/ui.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/ui.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/ui.cc > CMakeFiles/substats.dir/src/ui/ui.cc.i

CMakeFiles/substats.dir/src/ui/ui.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/ui.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/ui.cc -o CMakeFiles/substats.dir/src/ui/ui.cc.s

CMakeFiles/substats.dir/src/ui/view_window.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/view_window.cc.o: /home/user/code/subrating/src/ui/view_window.cc
CMakeFiles/substats.dir/src/ui/view_window.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/substats.dir/src/ui/view_window.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/view_window.cc.o -MF CMakeFiles/substats.dir/src/ui/view_window.cc.o.d -o CMakeFiles/substats.dir/src/ui/view_window.cc.o -c /home/user/code/subrating/src/ui/view_window.cc

CMakeFiles/substats.dir/src/ui/view_window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/view_window.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/view_window.cc > CMakeFiles/substats.dir/src/ui/view_window.cc.i

CMakeFiles/substats.dir/src/ui/view_window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/view_window.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/view_window.cc -o CMakeFiles/substats.dir/src/ui/view_window.cc.s

CMakeFiles/substats.dir/src/ui/window.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/window.cc.o: /home/user/code/subrating/src/ui/window.cc
CMakeFiles/substats.dir/src/ui/window.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/substats.dir/src/ui/window.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/window.cc.o -MF CMakeFiles/substats.dir/src/ui/window.cc.o.d -o CMakeFiles/substats.dir/src/ui/window.cc.o -c /home/user/code/subrating/src/ui/window.cc

CMakeFiles/substats.dir/src/ui/window.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/window.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/window.cc > CMakeFiles/substats.dir/src/ui/window.cc.i

CMakeFiles/substats.dir/src/ui/window.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/window.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/window.cc -o CMakeFiles/substats.dir/src/ui/window.cc.s

CMakeFiles/substats.dir/src/ui/window_helpers.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/ui/window_helpers.cc.o: /home/user/code/subrating/src/ui/window_helpers.cc
CMakeFiles/substats.dir/src/ui/window_helpers.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/substats.dir/src/ui/window_helpers.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/ui/window_helpers.cc.o -MF CMakeFiles/substats.dir/src/ui/window_helpers.cc.o.d -o CMakeFiles/substats.dir/src/ui/window_helpers.cc.o -c /home/user/code/subrating/src/ui/window_helpers.cc

CMakeFiles/substats.dir/src/ui/window_helpers.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/ui/window_helpers.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/ui/window_helpers.cc > CMakeFiles/substats.dir/src/ui/window_helpers.cc.i

CMakeFiles/substats.dir/src/ui/window_helpers.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/ui/window_helpers.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/ui/window_helpers.cc -o CMakeFiles/substats.dir/src/ui/window_helpers.cc.s

CMakeFiles/substats.dir/src/utils/file_utils.cc.o: CMakeFiles/substats.dir/flags.make
CMakeFiles/substats.dir/src/utils/file_utils.cc.o: /home/user/code/subrating/src/utils/file_utils.cc
CMakeFiles/substats.dir/src/utils/file_utils.cc.o: CMakeFiles/substats.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/substats.dir/src/utils/file_utils.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/substats.dir/src/utils/file_utils.cc.o -MF CMakeFiles/substats.dir/src/utils/file_utils.cc.o.d -o CMakeFiles/substats.dir/src/utils/file_utils.cc.o -c /home/user/code/subrating/src/utils/file_utils.cc

CMakeFiles/substats.dir/src/utils/file_utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/substats.dir/src/utils/file_utils.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/code/subrating/src/utils/file_utils.cc > CMakeFiles/substats.dir/src/utils/file_utils.cc.i

CMakeFiles/substats.dir/src/utils/file_utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/substats.dir/src/utils/file_utils.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/code/subrating/src/utils/file_utils.cc -o CMakeFiles/substats.dir/src/utils/file_utils.cc.s

# Object files for target substats
substats_OBJECTS = \
"CMakeFiles/substats.dir/src/main.cc.o" \
"CMakeFiles/substats.dir/src/models/subscriber.cc.o" \
"CMakeFiles/substats.dir/src/services/convert.cc.o" \
"CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o" \
"CMakeFiles/substats.dir/src/ui/header_window.cc.o" \
"CMakeFiles/substats.dir/src/ui/input_manager.cc.o" \
"CMakeFiles/substats.dir/src/ui/layout_manager.cc.o" \
"CMakeFiles/substats.dir/src/ui/logo_window.cc.o" \
"CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o" \
"CMakeFiles/substats.dir/src/ui/ui.cc.o" \
"CMakeFiles/substats.dir/src/ui/view_window.cc.o" \
"CMakeFiles/substats.dir/src/ui/window.cc.o" \
"CMakeFiles/substats.dir/src/ui/window_helpers.cc.o" \
"CMakeFiles/substats.dir/src/utils/file_utils.cc.o"

# External object files for target substats
substats_EXTERNAL_OBJECTS =

substats: CMakeFiles/substats.dir/src/main.cc.o
substats: CMakeFiles/substats.dir/src/models/subscriber.cc.o
substats: CMakeFiles/substats.dir/src/services/convert.cc.o
substats: CMakeFiles/substats.dir/src/services/subscriber_manager.cc.o
substats: CMakeFiles/substats.dir/src/ui/header_window.cc.o
substats: CMakeFiles/substats.dir/src/ui/input_manager.cc.o
substats: CMakeFiles/substats.dir/src/ui/layout_manager.cc.o
substats: CMakeFiles/substats.dir/src/ui/logo_window.cc.o
substats: CMakeFiles/substats.dir/src/ui/sub_form_window.cc.o
substats: CMakeFiles/substats.dir/src/ui/ui.cc.o
substats: CMakeFiles/substats.dir/src/ui/view_window.cc.o
substats: CMakeFiles/substats.dir/src/ui/window.cc.o
substats: CMakeFiles/substats.dir/src/ui/window_helpers.cc.o
substats: CMakeFiles/substats.dir/src/utils/file_utils.cc.o
substats: CMakeFiles/substats.dir/build.make
substats: CMakeFiles/substats.dir/compiler_depend.ts
substats: /usr/lib/libcurses.so
substats: /usr/lib/libform.so
substats: CMakeFiles/substats.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/user/code/subrating/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable substats"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/substats.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/substats.dir/build: substats
.PHONY : CMakeFiles/substats.dir/build

CMakeFiles/substats.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/substats.dir/cmake_clean.cmake
.PHONY : CMakeFiles/substats.dir/clean

CMakeFiles/substats.dir/depend:
	cd /home/user/code/subrating/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/code/subrating /home/user/code/subrating /home/user/code/subrating/build /home/user/code/subrating/build /home/user/code/subrating/build/CMakeFiles/substats.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/substats.dir/depend

