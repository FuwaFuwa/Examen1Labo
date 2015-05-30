#ifndef ENEMIGO3_H
#define ENEMIGO3_H

#include "Personaje.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Enemigo3 : public Personaje
{
    public:

        list<Personaje*>*personajes;
        int velocidad;
        int velocidad_bala;

        void dibujar();
        void logica(bool *ase);

        Enemigo3(SDL_Renderer *renderer,list<Personaje*>*personajes);
        virtual ~Enemigo3();
    protected:
    private:
};

#endif // ENEMIGO3_H
