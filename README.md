**What is this?**

This is a memory access visualisation library for C++ which 'paints' N-dimensional arrays in QWidget windows. These windows run in separate threads. 
To launch a window, create a visualisation job by creating an ArrayVizJob object. This will create a new thread and launch two windows; one containing
the full array printout, and a zoomed 'cursor' which highlights the co-ordinates of interest. 

    a->visualiseArrayWorker(argc, argv, matVals, matDims, coords, cursor);

'A': the visualisation object, a pointer.
argc, argv: main function args, provide as int main params
matVals: 1 dimensional list of all matrix values by column and then row
matDims: absolute value of matrix dimensions, not 0-indexed
coords: 3+D coordinate 'slice' of higher dimensional matrix to display. I.e. to show 3rd slice of 3d matrix, provide {0,0,2}
Cursor: 2D co-ords to focus cursor at. 

Thread will run until the user closes all windows launched by it. 

**Installation**

This is a bit tricky (I dev'd this on windows instead of linux, oops). First, check and install all requirements. Helps if dev'ing in QTCreator. 

Either build and install yourself using CMAKE or Ninja, or build in QTCreator/VS to create DLL and Lib files. Move DLL, Libs, and all headers into a
'lib/include' folder in your C++ project. 

Then #include "arrayvizjob.h" and create a new viz object, then invoke where needed. E.g.

```
#include "arrayvizjob.h"

int main(int argc, char *argv[])
{
    ArrayVizJob *a = new ArrayVizJob();
    std::vector<std::string> matVals = {"1","2","3","4"};
    std::vector<int> matDims = {2,2};
    std::vector<int> coords = {0,0};
    std::vector<int> cursor = {0,0};
    a->visualiseArrayWorker(argc, argv, matVals, matDims, coords, cursor);
    return 1;
}
```

**REQUIRES**

https://github.com/erenon/binlog
CMAKE v. 3.14 or above.
QT Widgets V5 or above. 

Ta. 
