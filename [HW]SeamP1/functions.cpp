#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;


Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row].r = 0;
      image[col][row].g = 0;
      image[col][row].b = 0;

    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
    int* seam = new int[length];
    return seam;
}

void deleteSeam(int* seam) {
    delete[] seam;
}


bool loadImage(string filename, Pixel** image, int width, int height) {
  ifstream ifs (filename);
  if(!ifs.is_open())
  {
      cout << "Error: failed to open input file - " << filename << endl; 
      return false;
  }
  string type;
  ifs >> type;
  if(type != "P3")
  {
      cout << "Error: type is " << type << " instead of P3" << endl;
      return false;
  }
  int inputWidth = 0;
  int inputHeight = 0;
  ifs >> inputWidth >> inputHeight;
  if(ifs.fail())
  {
      cout << "Error: read non-integer value" << endl;
      return false;
  }
  if(inputHeight != height)
  {
      cout << "Error: input height (" << height << ") does not match value in file (" << inputHeight << ")" << endl;
      exit(0);
  }
  if(inputWidth != width)
  {
      cout << "Error: input width (" << width << ") does not match value in file (" << inputWidth << ")" << endl;
      exit(0);
  }
  int maxColorValue = 0;
  ifs >> maxColorValue;
  if (maxColorValue < 0 || maxColorValue > 255)
  {
      cout << "Error: invalid color value " << maxColorValue << endl;
      exit(0);
  }
  int num = -1;
  int maxPixels = width* height;
  int count = 0;
  while(ifs >> num)
  {
    if(count >= maxPixels * 3)
    {
          cout << "Error: too many color values" << endl;
          return false;
    }
      if (num < 0 || num > 255)
      {
          cout << "Error: invalid color value " << num << endl;
          return false;
      }
      int tempCount = count / 3;
      if(count % 3 == 0)
      {
        image[tempCount%width][tempCount/width].r = num;
      }
      else if(count % 3 == 1)
      {
        image[tempCount % width][tempCount / width].g = num;
      }
      else
      {
        image[tempCount % width][tempCount / width].b = num;
      }
      count++;
      num = -1;
  }
  if(ifs.eof() && count != maxPixels * 3)
  {
      cout << "Error: not enough color values" << endl;
      return false;
  }
  else if(!ifs.eof())
  {
      cout << "Error: read non-integer value" << endl;
      return false;
  }

  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
  // TODO(student): declare/define and open output file stream
  ofstream ofs(filename);
  //check if output stream opened successfully
   if(ofs.is_open())
   {
        //output preamble
      ofs << "P3" << endl;
      ofs << width << " " << height << endl;
      ofs << 255 << endl;
        //  output pixels
      for(int i = 0; i < height; i++)
      {
          for(int j = 0; j < width; j++)
          {
              ofs << image[j][i].r << endl;
              ofs << image[j][i].g << endl;
              ofs << image[j][i].b << endl;
          }
      }
   }
   else
   {
       cout << "Error: failed to open output file " << filename << endl;
       return false;
   }
   return true;
}

int energy(Pixel** image, int x, int y, int width, int height) { 
    //non border pixel
    int xGradient = 0;
    int yGradient = 0;

    if(x == 0 && y == 0) //top left corner
    {
        xGradient = pow(image[1][y].r - image[width-1][y].r,2) + pow(image[1][y].g - image[width-1][y].g,2) + pow(image[1][y].b - image[width-1][y].b,2);
        yGradient = pow(image[x][1].r - image[x][height-1].r,2) + pow(image[x][1].g - image[x][height-1].g,2) + pow(image[x][1].b - image[x][height-1].b,2);
    }
    else if(x == width-1 && y == 0) //bottom right corner
    {
        xGradient = pow(image[0][y].r - image[width-2][y].r,2) + pow(image[0][y].g - image[width-2][y].g,2) + pow(image[0][y].b - image[width-2][y].b,2);
        yGradient = pow(image[x][1].r - image[x][height-1].r,2) + pow(image[x][1].g - image[x][height-1].g,2) + pow(image[x][1].b - image[x][height-1].b,2);
    }
    else if(x == 0 && y == height-1) //bottom left corner
    {
        xGradient = pow(image[1][y].r - image[width-1][y].r,2) + pow(image[1][y].g - image[width-1][y].g,2) + pow(image[1][y].b - image[width-1][y].b,2);
        yGradient = pow(image[x][0].r - image[x][height-2].r,2) + pow(image[x][0].g - image[x][height-2].g,2) + pow(image[x][0].b - image[x][height-2].b,2);
    }

    else if(x == width-1 && y == height-1) //bottom right corner
    {
        xGradient = pow(image[0][y].r - image[width-2][y].r,2) + pow(image[0][y].g - image[width-2][y].g,2) + pow(image[0][y].b - image[width-2][y].b,2);
        yGradient = pow(image[x][0].r - image[x][height-2].r,2) + pow(image[x][0].g - image[x][height-2].g,2) + pow(image[x][0].b - image[x][height-2].b,2);
    }
    else if(x == 0 && y!= 0){ //first column
        xGradient = pow(image[1][y].r - image[width-1][y].r,2) + pow(image[1][y].g - image[width-1][y].g,2) + pow(image[1][y].b - image[width-1][y].b,2);
        yGradient = pow(abs(image[x][y-1].r - image[x][y+1].r),2) + pow(abs(image[x][y-1].g - image[x][y+1].g),2) + pow(abs(image[x][y-1].b - image[x][y+1].b),2);
    }
    else if(x!= 0 && y ==0)// first row
    {
        xGradient = pow(image[x-1][y].r - image[x+1][y].r,2) + pow(image[x-1][y].g - image[x+1][y].g,2) + pow(image[x-1][y].b - image[x+1][y].b,2);
        yGradient = pow(image[x][1].r - image[x][height-1].r,2) + pow(image[x][1].g - image[x][height-1].g,2) + pow(image[x][1].b - image[x][height-1].b,2);
    }  
    else if(x == width-1 && y != height-1) //right column
    {
        xGradient = pow(image[0][y].r - image[width-2][y].r,2) + pow(image[0][y].g - image[width-2][y].g,2) + pow(image[0][y].b - image[width-2][y].b,2);
        yGradient = pow(image[x][y-1].r - image[x][y+1].r,2) + pow(image[x][y-1].g - image[x][y+1].g,2) + pow(image[x][y-1].b - image[x][y+1].b,2);
    }
    else if(x != width-1 && y == height-1) //bottom row
    {
        xGradient = pow(image[x-1][y].r - image[x+1][y].r,2) + pow(image[x-1][y].g - image[x+1][y].g,2) + pow(image[x-1][y].b - image[x+1][y].b,2);
        yGradient = pow(image[x][0].r - image[x][height-2].r,2) + pow(image[x][0].g - image[x][height-2].g,2) + pow(image[x][0].b - image[x][height-2].b,2);
    }
    else //middle
    {
        xGradient = pow(image[x-1][y].r - image[x+1][y].r,2) + pow(image[x-1][y].g - image[x+1][y].g,2) + pow(image[x-1][y].b - image[x+1][y].b,2);
        yGradient = pow(image[x][y-1].r - image[x][y+1].r,2) + pow(image[x][y-1].g - image[x][y+1].g,2) + pow(image[x][y-1].b - image[x][y+1].b,2);
    }
    
  return xGradient + yGradient; 
}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
    seam[0] = start_col;
    int totalEnergy = energy(image,start_col,0,width,height);
    for(int row = 1; row < height; row++)
    {
        int energyDown = energy(image,start_col,row,width,height);
        int energyDiagLeft = 10000000;
        int energyDiagRight = 10000000;
        if(start_col != 0)
        {
            energyDiagLeft = energy(image,start_col-1,row,width,height);
        }
        if(start_col != width-1)
        {
            energyDiagRight = energy(image,start_col+1,row,width,height);
        }
        if(energyDown > energyDiagRight && energyDiagRight < energyDiagLeft)
        {
            start_col +=1;
            seam[row] = start_col;
            totalEnergy += energyDiagRight;
        }
        else if(energyDiagLeft < energyDown && energyDiagLeft < energyDiagRight)
        {
            start_col -= 1;
            seam[row] = start_col;
            totalEnergy += energyDiagLeft;
        }
        else if(energyDown < energyDiagLeft && energyDiagRight > energyDown)
        {
            totalEnergy += energyDown;
            seam[row] = start_col; 
        }
        else
        {
            if(energyDown == energyDiagLeft || energyDown == energyDiagRight)
            {
                totalEnergy += energyDown;
                seam[row] = start_col; 
            }
            else
            {
                start_col += 1;
                seam[row] = start_col;
                totalEnergy += energyDiagRight;
            }
            
        }
    }
  return totalEnergy;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
    seam[0] = start_row;
    int totalEnergy = energy(image,start_row,0,width,height);
    for(int column = 1; column < width; column++)
    {
        int energyRight = energy(image,start_row,column,width,height);
        int energyDiagUp = 10000000;
        int energyDiagDown = 10000000;
        if(start_row != 0)
        {
            energyDiagUp = energy(image,start_row-1,column,width,height);
        }
        if(start_row != height-1)
        {
            energyDiagDown = energy(image,start_row+1,column,width,height);
        }
        if(energyRight > energyDiagDown && energyDiagUp > energyDiagDown)
        {
            start_row +=1;
            seam[column] = start_row;
            totalEnergy += energyDiagDown;
        }
        else if(energyDiagUp < energyRight && energyDiagUp < energyDiagDown)
        {
            start_row -= 1;
            seam[column] = start_row;
            totalEnergy += energyDiagUp;
        }
        else if(energyRight < energyDiagUp && energyDiagDown > energyRight)
        {
            totalEnergy += energyRight;
            seam[column] = start_row; 
        }
        else
        {
            if(energyRight == energyDiagUp || energyRight == energyDiagDown)
            {
                totalEnergy += energyRight;
                seam[column] = start_row; 
            }
            else
            {
                start_row -= 1;
                seam[column] = start_row;
                totalEnergy += energyDiagDown;
            }
            
        }


        
    }
  return totalEnergy;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
    int* seam = createSeam(width);
    int index = 0;
    int minEnergy = loadVerticalSeam(image,0,width,height,seam);
    for(int i = 1; i < width; i++)
    {
        int currentEnergy = loadVerticalSeam(image,i,width,height,seam);
        if(currentEnergy < minEnergy)
        {
            index = i;
            minEnergy = currentEnergy;
        }
    }
    loadVerticalSeam(image,index,width,height,seam);
    return seam;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
    cout << image << width << height;
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
    for(int i = 0; i < height; i++)
    {
        for(int j = verticalSeam[i]; j < width-1; j++)
        {
            image[j][i] = image[j+1][i];
        }
    }
}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
    cout << image << width << height << horizontalSeam;
}
