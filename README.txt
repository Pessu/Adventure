Author Miika Pakarinen 1001136

Files are precompiled for every submission so no need to compile this, comes with an exe

HOW TO COMPILE IF NEEDED:
1. Compile the .o files "g++ *.cpp -c"
4. Compile the program the exe "g++ -o adventure.exe *.o"

Module 5 changes:
Added vectors in game and room classes
Added another vector to monsterroomm (i like vectors)
Fixed a bug from gold class

Module 4 changes:
- Added a few template functions in IRenderer that can render any parameter types
- Used once in player.cpp to render string, int, string

Module 3 changes:
- Moved to a new repository due to problems with the previous one
- Removed goldlib since I had to rework the gold files which were in the library to begin with
- Added an overloaded addition operator for Gold class (used in GoldFactory)
- Added friend class Dungeon for Room class.
- Dungeon class prints "This place feels familiar if the room is already visited"

Module 2 changes:
- Moved all files into same folder for the repository, less trouble compiling (I use a bit more
complicated folder layout in my IDE.
- Added Load & SaveCommand classes for handling respective commands (save & load)
- Added Utilities class for common tool functions and file handling
- Added a generic "file not found" exception in globals which calls an runtime error