This is an extension for marmalade to use the felix programming language to write programs 
on the marmalade platform.

You'll have to get felix built, then copy build\release into this folder as a folder
named "felix-dist".

To compile the felix runtime library for use in marmalade, run:

    C:\marmalade\6.0\extensions\felix\felix.mkb --make -n --x86

Create src/main.flx like this:

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

    hello.mkb --make -n --x86 --debug

Now you should be more or less good to go.

Run hello.mkb for more information about the different ways to launch the project, it can launch
the Visual Studio IDE for you or just build and run the project from the command line.

  

