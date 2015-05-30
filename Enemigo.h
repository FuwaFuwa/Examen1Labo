#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Enemigo : public Personaje
{
    public:
        vector<SDL_Rect> rect_balas;
        list<Personaje*>*personajes;
        int velocidad;
        int velocidad_bala;

        void dibujar();
        void logica();

        Enemigo(SDL_Renderer *renderer,list<Personaje*>*personajes);
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
