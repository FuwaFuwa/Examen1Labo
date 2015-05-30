        #include "Jugador.h"

        Jugador::Jugador(SDL_Renderer *renderer,list<Personaje*>*personajes)
        {
            this->renderer = renderer;
            this->personajes = personajes;
            int w,h;
            textura = IMG_LoadTexture(renderer, "personaje.png");
            SDL_QueryTexture(textura, NULL, NULL, &w, &h);
            rect_textura.x = 0;
            rect_textura.y = 100;
            rect_textura.w = w;
            rect_textura.h = h;

            textura_bala = IMG_LoadTexture(renderer, "balapj.png");
            SDL_QueryTexture(textura_bala, NULL, NULL, &w, &h);
            rect_bala.x = 0;
            rect_bala.y = 100;
            rect_bala.w = w;
            rect_bala.h = h;

            velocidad=3;
            velocidad_bala=10;
        }

        void Jugador::dibujar()
        {
            SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
            for(int i=0;i<rect_balas.size();i++)
                SDL_RenderCopy(renderer, textura_bala, NULL, &rect_balas[i]);
        }

        void Jugador::logica(bool *ase)
        {
            for(int i=0;i<rect_balas.size();i++)
                rect_balas[i].x+=velocidad_bala;

                const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
                if(estaPresionada[ SDL_SCANCODE_A])
                {
                    rect_textura.x-=11;;
                }
                if(estaPresionada[ SDL_SCANCODE_D])
                {
                    rect_textura.x+=11;
                }
                if(estaPresionada[ SDL_SCANCODE_W])
                {
                    rect_textura.y-=11;
                }
                if(estaPresionada[ SDL_SCANCODE_S])
                {
                    rect_textura.y+=11;
                }
                if(estaPresionada[ SDL_SCANCODE_SPACE])
                {
                    if(frame%5==0)
                    {
                    SDL_Rect temp;
                    temp.x=rect_textura.x;
                    temp.y=rect_textura.y;
                    temp.w=rect_bala.w;
                    temp.h=rect_bala.h;
                    rect_balas.push_back(temp);
                }
            }
            for(list<Personaje*>::iterator i=personajes->begin();
                i!=personajes->end();
                i++
                )
            {
                if(*i==this)
                    continue;
                for(int j=0;j<rect_balas.size();j++)
                {




                    SDL_Rect rect_one = rect_balas[j];
                    SDL_Rect rect_two = (*i)->rect_textura;
                    if((rect_one.x+rect_one.w<rect_two.x)==false/*Muy izq*/&& (rect_one.x>rect_two.x+rect_two.w)==false/*Muy der*/&& (rect_one.y+rect_one.h<rect_two.y)==false/*Muy arriba*/&& (rect_one.y>rect_two.y+rect_two.h)==false)//Muy abajo)
                   {

                        personajes->erase(i);
                        *ase =true;
                        return;
                    }
                }
            }
            frame++;
        }








        Jugador::~Jugador()
        {
            //dtor
        }
