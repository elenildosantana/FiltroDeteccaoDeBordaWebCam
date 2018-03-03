#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "FiltroPassaAlta.h"

using namespace std;

int main()
{
   cv::VideoCapture cap(0);
   if(!cap.isOpened()){
        std::cout << "Não é possivel utilizar a câmera!" << std::endl;
        return -1;
   }
   cv::Mat quadro;
   cv::Mat quadroCinza;
   FiltroPassaAlta fpa;

   while(1){
        cap >> quadro;
        bool existeQuadro = cap.read(quadro);
        if(!existeQuadro){
                std::cout << "Não é possivel ler o quadro!" << std::endl;
                break;
        }
        cv::cvtColor(quadro, quadroCinza, cv::COLOR_BGR2GRAY);
        fpa.operadorDeSobel(quadroCinza);
        // tecla ESC para sair
        if(cv::waitKey(30)==27){
                break;
        }
   }
    return 0;
}
