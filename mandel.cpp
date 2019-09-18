#include <iostream>
#include <fstream>
#include <complex>

using namespace std;


float width = 600;
float height = 600;
int mandelVal(int x, int y);
int main() {

  ofstream image("mandelbrot2.ppm");
  if(image.is_open()){
    image << "P3\n" << width << " " << height << " 255\n";
    for(int i = 0; i < width;i++){
      for(int j = 0;j < height;j++){
	int num = mandelVal(i, j);
	image << num << ' ' << 0 << ' ' << 0 << "\n";
      }
    }
    image.close();
  }else{
    cout << "Could not open the file" << endl;
  }

  
  return 0;
}


int mandelVal(int x, int y){
  complex<float> point((float)x/width-1.5,(float)y/height-0.5);
  //divide by image dimensions to get values smaller than 1
  //then apply a transition.
  complex<float> z(0,0);
  unsigned int nb_iter = 0;
  while((abs(z) < 2) && (nb_iter <= 34)){
    z = z * z + point;
    nb_iter++;
  }
  if(nb_iter < 34)
    return 255;
  else
    return 0;
  
}
