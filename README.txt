My PPM.cpp program creates a 5 by 5 pattern of pixels that is repeated across the canvas of given width and height. 
Because this pattern is 5X5, the input width and height must be multiples of 5. 

The program functions like so:
- Takes a text file as imput from the command line
- The text file must be structured: "imsize width height" where width and height are positive integers and multiples of 5
- An output file is created with the same name as the input file, ending in ppm
- each bit is written to the output file starting with the first 5 lines of the pattern repeated across the width,
then repeating those 5 lines down the height. 
- The output ppm file can be opened to show the pattern