    #ifndef PERSONAJE_H
    #define PERSONAJE_H
    #include<vector>
    #include<SDL2/SDL.h>
    #include<SDL2/SDL_image.h>
    using namespace std;
    class Personaje
    {
        public:
            SDL_Texture *textura, *textura_bala;
            SDL_Rect rect_textura, rect_bala;
            SDL_Renderer *renderer;
            vector<SDL_Rect> rect_balas;

            int frame;
            Personaje();
            virtual void logica(bool *ase)=0;
            virtual void dibujar()=0;
            virtual ~Personaje();
        protected:
        private:
    };

    #endif // PERSONAJE_H
