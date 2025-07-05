# Implement colors!
Determine a maximum and a minimum

# Add a perspective matrix (along with a sphere view and conic)


# Pre-compute neighbour pairs for better cache prediction and eliminate branching
(This will probably change with perspective matrix)
But the slope of the line should be preseved when clamping
If all points are outside of the draw region, no-op
Total number of pairs = (rows - 1) * cols + (cols - 1) * rows = 2 rows*cols - rows - cols

# Implement anti-aliasing
Could do a simple 3x3 kernel convolution with a gaussian filter

# Implement motion smoothing
Would require something to measure time
