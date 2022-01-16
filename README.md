# BSQ - Final project of the School21 piscine


## The aim of this project is to find the biggest square on a map, avoiding obstacles.

### ***Map's information:***
+ The first line of the map contains information on how to read the map :
  + The number of lines on the map;
  + The "empty" character;
  + The "obstacle" character;
  + The "full" character.
+ The map is made up of "empty" characters, lines and "obstacle" characters.
+ The aim of the program is to replace ’"empty" characters’ by ’"full" characters’ in order to represent the biggest square possible.
+ In the case that more than one solution exists, we’ll choose to represent the square that’s closest to the top of the map, then the one that’s most to the left.

### ***Definition of a valid map:***
+ All lines must have the same length.
+ There’s at least one line of at least one box.
+ At each end of line, there’s a line break.
+ The characters on the map can only be those introduced in the first line.

> In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map.

### ***Example:***
```
%>cat example_file
10.ox
..o..............o.....o.
.........o..o............
....o....................
.............o......o....
..o.....o................
......o..........o....o..
..........o.......o..oo..
...............oo.o....o.
.............o...........
o.......................o
%>./a.out Test/t0
..o..............o.....o.
.........o..o............
....o....................
.............o......o....
..o.....o................
.xxxxxo..........o....o..
.xxxxx....o.......o..oo..
.xxxxx.........oo.o....o.
.xxxxx.......o...........
oxxxxx..................o
%>
```
> It is a square indeed. Even though it might not look like it visually.

___


### ***You can generate your own the map with generator.pl:***
```
%>perl generator.pl 5 8 2
8.ox
..o..
.o...
.....
..o.o
o....
...o.
.....
o.o..
%>
```
> * ***5*** - width
> * ***8*** - length
> * ***2*** - density of obstacle

