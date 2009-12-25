DISCLAIMER: This project is a work in progress. Use it at your own risk.

Required Software
===================
 - CMake 2.8
 - Qt4
 - CUDA SDK, Toolkit and Drivers (NVidia)

If you want to use CMake 2.6 you probably have to install findCUDA manually.

Creating project files/Makefiles
=================================

Windows/Visual Studio 2008
--------------------------
Run CMake GUI and select the project directory (the one this file is in) as
source. Select a second directory for building the binaries. This one should
be different than the first directory. That way you can create multiple
configuration (e.g. for 32bit/64bit) in different directories but with the same
source code files.

After that click on "Configure" and you will get a list of possible generators.
For VS2008 there are two possible generators, one for 32bit and the other for
64bit applications. You will need a matching version of CUDA and Qt4. For CUDA
you can create 32bit applications with the 64bit CUDA SDK/Toolkit.

If everything went well you will now see a list of changed variables. You will
have to click configure multiple times until no variable changes. After that
you can create the VS2008 project files by clicking on "Generate".

On Windows you will probably get some variables with NOTFOUND for QTMOTIF. You
can safely ignore this.

Windows/mingw
--------------

Linux/Makefiles
----------------

Compiling/Installing
=====================

Qt doesn't install any DLL files into the system32 directory for Windows. If
you get any errors about missing DLL files this is probably because the Qt bin
directory is not in your PATH variable. You can either add it or copy the
missing DLL files into the application directory.
The same applies for CUDA (e.g. cudart.dll). If you have the 64bit version of
the SDK