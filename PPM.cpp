#include <fstream>
#include <iostream>
#include <string>

//A helper function that hard codes the first 5 lines of the patten accross the width, colors a (5 * width) rectangle of pixels
void colorBlock(std::ofstream& file, int width){
    for(int i = 0; i < width; i+=5){ //repeats the first line of the pattern accross the canvas width
        file << 242 << " " << 114 << " " << 55 << " \n"; //dark orange
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange
        file << 242 << " " << 114 << " " << 55 << " \n"; //dark orange
    }
    
    for(int i = 0; i < width; i+=5){ //repeats the second line of the pattern accross the canvas width
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
        file << 236 << " " << 124 << " " << 190 << " \n"; //purple
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange
    }

    for(int i = 0; i < width; i+=5){ //repeats the third line of the pattern accross the canvas width
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
        file << 236 << " " << 124 << " " << 190 << " \n"; //purple
        file << 241 << " " << 97 << " " << 70 << " \n"; //red
        file << 236 << " " << 124 << " " << 190 << " \n"; //purple
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
    }

    for(int i = 0; i < width; i+=5){
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
        file << 236 << " " << 124 << " " << 190 << " \n"; //purple
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange 
    }

    for(int i = 0; i < width; i+=5){
        file << 242 << " " << 114 << " " << 55 << " \n"; //dark orange
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange
        file << 161 << " " << 209 << " " << 210 << " \n"; //blue
        file << 233 << " " << 159 << " " << 66 << " \n"; //light orange
        file << 242 << " " << 114 << " " << 55 << " \n"; //dark orange
    }
}

//main function, gets a file from cammand line and writes to a ppm file of the same name
int main(int argc, const char * argv[]){

    //get filename as input from command line, error otherwise
    if(argc < 2){
        std::cerr << "Please provide a file name as an argument" << std::endl;
        return -1;
    }
    std::string filename = argv[1];

    //open the input file stream, check for error
    std::ifstream inputFile(filename);
    if(!inputFile.is_open()){
        std::cerr << "Error: unable to open file: " << filename << std::endl;
        return -1;
    }

    //set up variables for the data to be read from the file
    std::string keyWord;
    int width;
    int height;

    //open the output file stream, set the output file name as input filename.ppm
    std::string newFilename = filename.erase(filename.length() - 4, 4);
    std::ofstream fout(newFilename + ".ppm"); 
    if(fout.fail()) return -1; //error opening file

    //make sure the input file is in the correct format, then write the header to the output file
    if(!(inputFile >> keyWord >> width >> height)){
        std::cerr << "Error: file must be in format 'imsize width height'\n" << std::endl;
        return -1;
    }else if((width < 0) || (height < 0)){
        std::cerr << "Error: Please make width and height positive integer values\n" << std::endl;
        return -1;
    }else if((width % 5 != 0) || (height % 5 != 0)){ //Has to be multiples of 5 for the pattern to show up correctly
        std::cerr << "Error: Please make width and height a multiple of 5\n" << std::endl;
        return -1;
    }else{ 
        if(keyWord != "imsize"){ //make sure the input file uses the keyword
            std::cerr << "Error: file must start with keyword 'imsize'\n" << std::endl;
            return -1;
        }//use the input width and height to write the header to the output file
        fout << "P3\n";
        fout << width << " # image width\n" << height << " # image height\n";
        fout << "255\n";
    }

    //repeats the first 5 lines of color created by colorBlock over height of the canvas
    for(int i = 0; i < (height/5); i++){
        colorBlock(fout, width);
    }
    
    inputFile.close();
    fout.close();
    return 0; //no error
}
