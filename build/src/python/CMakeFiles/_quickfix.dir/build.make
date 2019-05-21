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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ervinbosenbacher/workspace/research/quickfix_barclays

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build

# Include any dependencies generated for this target.
include src/python/CMakeFiles/_quickfix.dir/depend.make

# Include the progress variables for this target.
include src/python/CMakeFiles/_quickfix.dir/progress.make

# Include the compile flags for this target's objects.
include src/python/CMakeFiles/_quickfix.dir/flags.make

src/python/CMakeFiles/_quickfix.dir/QuickfixPython.cpp.o: src/python/CMakeFiles/_quickfix.dir/flags.make
src/python/CMakeFiles/_quickfix.dir/QuickfixPython.cpp.o: ../src/python/QuickfixPython.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/python/CMakeFiles/_quickfix.dir/QuickfixPython.cpp.o"
	cd /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_quickfix.dir/QuickfixPython.cpp.o -c /Users/ervinbosenbacher/workspace/research/quickfix_barclays/src/python/QuickfixPython.cpp

src/python/CMakeFiles/_quickfix.dir/QuickfixPython.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_quickfix.dir/QuickfixPython.cpp.i"
	cd /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ervinbosenbacher/workspace/research/quickfix_barclays/src/python/QuickfixPython.cpp > CMakeFiles/_quickfix.dir/QuickfixPython.cpp.i

src/python/CMakeFiles/_quickfix.dir/QuickfixPython.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_quickfix.dir/QuickfixPython.cpp.s"
	cd /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ervinbosenbacher/workspace/research/quickfix_barclays/src/python/QuickfixPython.cpp -o CMakeFiles/_quickfix.dir/QuickfixPython.cpp.s

# Object files for target _quickfix
_quickfix_OBJECTS = \
"CMakeFiles/_quickfix.dir/QuickfixPython.cpp.o"

# External object files for target _quickfix
_quickfix_EXTERNAL_OBJECTS =

src/python/_quickfix.16.0.1.dylib: src/python/CMakeFiles/_quickfix.dir/QuickfixPython.cpp.o
src/python/_quickfix.16.0.1.dylib: src/python/CMakeFiles/_quickfix.dir/build.make
src/python/_quickfix.16.0.1.dylib: src/C++/libquickfix.16.0.1.dylib
src/python/_quickfix.16.0.1.dylib: /Library/Frameworks/Python.framework/Versions/3.7/lib/libpython3.7m.dylib
src/python/_quickfix.16.0.1.dylib: src/python/CMakeFiles/_quickfix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library _quickfix.dylib"
	cd /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_quickfix.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python && $(CMAKE_COMMAND) -E cmake_symlink_library _quickfix.16.0.1.dylib _quickfix.16.dylib _quickfix.dylib

src/python/_quickfix.16.dylib: src/python/_quickfix.16.0.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate src/python/_quickfix.16.dylib

src/python/_quickfix.dylib: src/python/_quickfix.16.0.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate src/python/_quickfix.dylib

# Rule to build all files generated by this target.
src/python/CMakeFiles/_quickfix.dir/build: src/python/_quickfix.dylib

.PHONY : src/python/CMakeFiles/_quickfix.dir/build

src/python/CMakeFiles/_quickfix.dir/clean:
	cd /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python && $(CMAKE_COMMAND) -P CMakeFiles/_quickfix.dir/cmake_clean.cmake
.PHONY : src/python/CMakeFiles/_quickfix.dir/clean

src/python/CMakeFiles/_quickfix.dir/depend:
	cd /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ervinbosenbacher/workspace/research/quickfix_barclays /Users/ervinbosenbacher/workspace/research/quickfix_barclays/src/python /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python /Users/ervinbosenbacher/workspace/research/quickfix_barclays/build/src/python/CMakeFiles/_quickfix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/python/CMakeFiles/_quickfix.dir/depend

