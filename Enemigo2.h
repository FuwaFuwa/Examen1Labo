    #ifndef ENEMIGO2_H
    #define ENEMIGO2_H

    #include "Personaje.h"
    #include <vector>
    #include <list>
    #include <iostream>

    using namespace std;

    class Enemigo2 : public Personaje
    {
        public:

            list<Personaje*>*personajes;
            int velocidad;
            int velocidad_bala;


            void dibujar();
            void logica(bool *ase);

            Enemigo2(SDL_Renderer *renderer,list<Personaje*>*personajes);
            virtual ~Enemigo2();
        protected:
        private:
    };

    #endif // ENEMIGO2_H
