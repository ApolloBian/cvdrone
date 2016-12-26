-----------------------------------------------------------------
 CV Drone (= OpenCV + AR.Drone)
 Copyright (C) 2016 puku0x
 https://github.com/puku0x/cvdrone
-----------------------------------------------------------------

INTRODUCTION
    This project is modified from [CV_Drone](https://github.com/puku0x/cvdrone) and is for my own personal purpose.
    I managed to convert it to a ready to import clion project, and you can manage to hack it a little bit and build it with cmake
    The original project uses VS, let me try to make it work under Mac.



HOW TO USE
  1. Open \build\vs20xx\test.sln
  2. Press F7 to build.
  3. Press F5 (or Ctrl+F5) to run.
  4. You can play around with OpenCV. Sample codes are in "src\samples".

FOR AR.DRONE 1.0 USERS
  Please update your AR.Drone's firmware to 1.11.5.

FOR AR.DRONE 2.0 USERS
  Please update your AR.Drone's firmware to 2.4.8.

FOR VS2010 USERS
  You can not build CV Drone by VS2010 after you installed VS2012.
  To build VS2010, 
    1) You should install "Visual Studio 2010 SP1".  [Recommended]
    or,
    2) You should uninstall ".Net Framework 4.5" and re-install "4.0".

LIBRARY DEPENDENCIES
  CV Drone uses following libraries.
  - OpenCV 3.1.0 <3-clause BSD license>
    http://opencv.org/
  - FFmpeg 2.2.3 <LGPL v2.1 license>
    http://www.ffmpeg.org/
  - stdint.h/inttypes.h for Microsoft Visual Studio r26 <BSD license>
    https://code.google.com/p/msinttypes/
  - POSIX Threads for Win32 2.9.1 <LGPL v2.1 license>
    http://www.sourceware.org/pthreads-win32/

  Marker-based AR sample uses following libraries adding to the above.
  - GLUT for Win32 3.7.6
    http://user.xmission.com/~nate/glut.html
  - MarkerDetector
    https://github.com/MasteringOpenCV/code/tree/master/Chapter2_iPhoneAR/Example_MarkerBasedAR/Example_MarkerBasedAR

  License files for each library can be found in the 'licenses' folder.

Thank you.