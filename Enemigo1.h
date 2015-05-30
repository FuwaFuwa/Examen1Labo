    #ifndef ENEMIGO1_H
    #define ENEMIGO1_H

    #include "Personaje.h"
    #include <vector>
    #include <list>
    #include <iostream>

    using namespace std;

    class Enemigo1 : public Personaje
    {
        public:

            list<Personaje*>*personajes;
            int velocidad;
            int velocidad_bala;



            void dibujar();
            void logica(bool *ase);

            Enemigo1(SDL_Renderer *renderer,list<Personaje*>*personajes);
            virtual ~Enemigo1();
        protected:
        private:
    };

    #endif // ENEMIGO1_H
