This is an extension for marmalade to use the felix programming language to write programs 
on the Marmalade platform.  Visit http://www.madewithmarmalade.com to learn more about that.

Prerequisites 
-------------

* Working Build of Felix
* Marmalade

Status
------

There are a few working examples, but most of the library has not been made available in Felix.  There
are plenty of rough edges, and felix itself is still a moving target.  So ... using this may not be for 
the faint at heart!

Still, the rewards may be great enough, for those who make the attempt.

Setup
-----

You'll have to get felix built, then copy build\release into this folder as a folder
named "felix-dist".

To compile the felix runtime library for use in marmalade, run (in Windows):

    C:\marmalade\6.0\extensions\felix\felix.mkb --make -n --x86

Usage
-----

Create a new folder for your project. 

In there, create src/main.flx like this:

    include "s3e";
    
    // Wait for a quit request from the host OS
    
    while s3eDeviceCheckQuitRequest() == false do
      // Fill background blue
      s3eSurfaceClear(200, 200, 255);
    
      // Print a line of debug text to the screen at top left (0,0)
      // Starting the text with the ` (backtick) char followed by 'x' and a hex value
      // determines the colour of the text.
      s3eDebugPrint(120, 150, c"`xffffffHello, World!", false);
    
      // Flip the surface buffer to screen
      if failed(s3eSurfaceShow()) do
        println$ "s3eSurfaceShow failed!";
      done
      
      // Sleep for 0ms to allow the OS to process events etc.
      val ignore = s3eDeviceYield();
    done

Create a folder "gen" and an empty file in there called main.cpp.

Then create your mkb file, for example you might call it hello.mkb:

    #!/usr/bin/env mkb
    
    commands
    {
       "$MARMALADE_ROOT/extensions/felix/flx.cmd src\\main"
    }
    
    # files specifies all files to build
    files
    {
      ["src"]
      (src)
      main.flx
    
      ["gen"]
      (gen)
      main.cpp
    }
    
    subprojects
    {
      felix
    }
  
And run the build:

    hello.mkb --make --launch -n --x86 --debug

Now you should be seeing it run your "hello, world!" example.
  

