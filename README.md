![Vectors](https://i.ibb.co/xsp03mw/Vectors.png)

# Points, Vectors, Lines, Segments, Triangles
The user can choose between five types of Inputs.
For each class there is an interactive menu which lists
all the available options which can be used
as of now. There are parametric equations,
normals, planes, line intersections and
a lot more. I might do updates on this little project in the future adding an interactive UI and new types of geometrical objects.

# All Available Operations:

## Point:
- Check if two Points are the same

## Vector:
- Addition of Vectors
- Substraction of Vectors
- Multiplication of a Vector and a number
- Dot Product of Vectors
- Cross Product of Vectors
- Combined Multiplication
- Check if a Vector is the Zero Vector
- Check if two Vectors are Parallel
- Check if two Vectors are Perpendicular
- Projection of a Vector onto another Vector
- Length of a Vector
- Direction of a Vector

## Line:
- Find a normal Vector to the Parametrical definition of the Line
- Direction of the Line
- Shortest Distance between a Line and a Point
- Shortest Distance between two Lines
- Angle between two Lines
- Check if two Lines are Parallel
- Check if two Lines Match
- Check if two Lines Intersect
- Check if two Lines never Intersect
- Check if two Lines are Perpendicular(orthogonal to be more precise)

## Segment:
- Length of the Segment
- Find the middle of the Segment
- Check if a Point lies on the Segment

## Triangle:
- Type of the Triangle (iscocles and etc.)
- Perimeter of the Triangle
- Area of the Triangle
- Centre of the Triangle
- Check if Sides are properly inputted
- Find if a Point is on the Plane of the Triangle and inside it
- Find if a Point is on the Plane of the Triangle and outside it
- Find if a Point lies on a side of the Triangle

## //Note:
- Points, Vectors, Lines, Segments and Triangles can be set in different ways.

		Example: 
			Line can be set with a Point and a Point, but also with a Point and a Vector. 
			Segments can have different intervals and etc.
- There are user-defined Exception classes which help for easier debugging and error-finding.


##				Input from a File(Input.txt):

	First Line is always the figure:
 	[x]:
		1 - Point
		2 - Vector
		3 - Line
		4 - Segment
		5 - Triangle

	Example:
		1
		1 2 3
		will create a Point with values (1,2,3)
	
	- Point:
	[x][x][x] 		- values of the Point

	- Vector:
	[x][x][x]		- values of the Vector 
	[x]			- operation
	[x][x][x] / [x]		- second Vector or Scalar
	[x][x][x]		- third Vector if needed 

	- Line:
	[x]			- way of creation (1: with Point and a Point; 2: with Point and Vector)
	[x][x][x]		- values of the Point
	[x][x][x]		- values of the Point/Vector
	[x]			- operation
	[x]/[x][x][x]  		- way of creation of a line for the operation or creation of a Point with three values
	[x][x][x]		- values for the Point of the Second Line depending on the previous choice 
	[x][x][x]		- values for the Point/Vector of the Second Line

	- Segment:
	[x]			- way of creation
	[x][x][x]		- values for the Point of the Segment
	[x][x][x]		- values for the Vector/Point of the Segment
	[x]			- interval minimum
	[x]			- interval maximum
	[x]			- operation
	[x][x][x]		- Point values for the operation if needed

	- Triangle:
	[x][x][x]		- values for the Point A
	[x][x][x]		- values for the Point B
	[x][x][x]		- values for the Point C
	[x]			- operation
	[x][x][x]		- values of the Point for the selected operation if needed


## Output into a File:
Outputs all the operations, created objects and their values into a single Document(Data.txt).
