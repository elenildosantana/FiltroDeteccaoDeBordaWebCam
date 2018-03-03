#ifndef FILTROPASSAALTA_H
#define FILTROPASSAALTA_H
#include <opencv2/opencv.hpp>

class FiltroPassaAlta
{
    public:
        FiltroPassaAlta();
        virtual ~FiltroPassaAlta();
        void operadorDeSobel(cv::Mat quadro);
        void operadorDeRoberts(cv::Mat quadro);
    protected:

    private:
};

#endif // FILTROPASSAALTA_H
