# Create a cmlx hook and integrate controls

# Figure out zoom and fitting
Probably involves having the coordinates be set up as a float and interpolating between min/max
Maybe also involves the normalization vector

# Implement colors!
Add a default color if unspecified (could be white or equal to the negative of the average)
Linearly interpolate colors between vtx p0 and vtx p1 in draw lines

# Pre-compute neighbour pairs for better cache prediction and eliminate branching
But the slope of the line should be preseved when clamping
If all points are outside of the draw region, no-op

# Implement anti-aliasing
# Implement motion smoothing


Pipeline is:

1) File is read and saved as a vertex struct, which contains xyz integer coordinates and argb color
2) A perspective matrix is generated using the params struct which contains (DX DY DZ RX RY RZ)
3) This matrix is then applied to every vertex (integers converted to floats)
4) An image is returned

Problems:
- There is no detection to see if and XY coordinate is out of bounds
- There is no normalization, so the reference point is shifted every time

Proper procedure:
1) File is read and saved as a struct that contains two uint32_t values: A 1D index and ARGB color pair
2) This struct is then converted to a vec3 struct, where all values are normalized to be ranging from -1 to 1
3) This vector is now used for all matrix calculations, and I need to make sure that the results still range from -1 to 1
4) Values are only converted to integers when a line is being drawn, because then the following can be done:
	- Scaling
	- Zoom
	- Clamping
