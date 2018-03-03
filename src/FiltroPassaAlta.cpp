#include "FiltroPassaAlta.h"

FiltroPassaAlta::FiltroPassaAlta()
{
    //ctor
}

FiltroPassaAlta::~FiltroPassaAlta()
{
    //dtor
}

void FiltroPassaAlta::operadorDeSobel(cv::Mat quadro){
    cv::Mat imagemComOpSobel = quadro.clone();
    int gX[] = {-1, -2, -1,
                 0,  0,  0,
                 1,  2,  1
               };

    int gY[] = {-1,  0,  1,
                -2,  0,  2,
                -1,  0,  1
               };

    for(int i=1; i<quadro.rows - 1; i++){
        for(int j=1; j<quadro.cols - 1; j++){
            int contador = 0;
            int somaGX = 0;
            int somaGY = 0;

            for(int l=i-1; l<=i+1; l++){
                for(int c=j-1; c<=j+1; c++){
                    int pixel = quadro.at<uchar>(l,c);
                    somaGX = (gX[contador] * pixel) + somaGX;
                    somaGY = (gY[contador] * pixel) + somaGY;
                    contador = contador + 1;
                }
            }

            int novoValorPixel = std::pow(std::pow(somaGX, 2) + std::pow(somaGY, 2),1/2.0);

            if(novoValorPixel<0){
                imagemComOpSobel.at<uchar>(i,j) = 0;
            }else if(novoValorPixel>255){
                imagemComOpSobel.at<uchar>(i,j) = 255;
            }else{
                imagemComOpSobel.at<uchar>(i,j) = novoValorPixel;
            }
        }
    }
    cv::imshow("Sobel", imagemComOpSobel);
}

void FiltroPassaAlta::operadorDeRoberts(cv::Mat quadro){
    cv::Mat imagemComOpRoberts = quadro.clone();
    int gX[] = {1,  0,
                0, -1
               };

    int gY[] = {0,  1,
                -1,  0
               };

    for(int i=0; i<quadro.rows - 1; i++){
        for(int j=0; j<quadro.cols - 1; j++){
            int contador = 0;
            int somaGX = 0;
            int somaGY = 0;

            for(int l=i; l<=i+1; l++){
                for(int c=j; c<=j+1; c++){
                    int pixel = quadro.at<uchar>(l,c);
                    somaGX = (gX[contador] * pixel) + somaGX;
                    somaGY = (gY[contador] * pixel) + somaGY;
                    contador = contador + 1;
                }
            }

            int novoValorPixel = std::pow(std::pow(somaGX, 2) + std::pow(somaGY, 2),1/2.0);
            if(novoValorPixel<0){
                imagemComOpRoberts.at<uchar>(i,j) = 0;
            }else if(novoValorPixel>255){
                imagemComOpRoberts.at<uchar>(i,j) = 255;
            }else{
                imagemComOpRoberts.at<uchar>(i,j) = novoValorPixel;
            }
        }
    }

    cv::imshow("Roberts", imagemComOpRoberts);
}

