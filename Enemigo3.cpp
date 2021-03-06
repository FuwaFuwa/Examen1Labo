    #include "Enemigo3.h"

    Enemigo3::Enemigo3(SDL_Renderer *renderer,list<Personaje*>*personajes)
    {
        this->renderer = renderer;
        this->personajes = personajes;
        int w,h;
        textura = IMG_LoadTexture(renderer, "The_Stick.png");
        SDL_QueryTexture(textura, NULL, NULL, &w, &h);
        rect_textura.x = 0;
        rect_textura.y = 0;
        rect_textura.w = w;
        rect_textura.h = h;

        textura_bala = IMG_LoadTexture(renderer, "bala3.png");
        SDL_QueryTexture(textura_bala, NULL, NULL, &w, &h);
        rect_bala.x = 300;
        rect_bala.y = 300;
        rect_bala.w = w;
        rect_bala.h = h;

        velocidad=3;
        velocidad_bala=7;
    }

    void Enemigo3::dibujar()
    {
        SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
        for(int i=0;i<rect_balas.size();i++)
            SDL_RenderCopy(renderer, textura_bala, NULL, &rect_balas[i]);
    }

    void Enemigo3::logica(bool *ase)
    {
        for(int i=0;i<rect_balas.size();i++)
        {
            rect_balas[i].y+=velocidad_bala;
            rect_balas[i].x+=velocidad_bala;
        }

        if(frame%50==0)
            {
                SDL_Rect temp;
                temp.x=rect_textura.x;
                temp.y=rect_textura.y;
                temp.w=rect_bala.w;
                temp.h=rect_bala.h;
                rect_balas.push_back(temp);
            }

        list<Personaje*>::iterator i=personajes->begin();
        for(int j=0; j<rect_balas.size();j++)
        {
                if(this==*i)
                continue;
                SDL_Rect rect_one = rect_balas[j];
                SDL_Rect rect_two = (*i)->rect_textura;
                if((rect_one.x+rect_one.w<rect_two.x)==false/*Muy izq*/&& (rect_one.x>rect_two.x+rect_two.w)==false/*Muy der*/&& (rect_one.y+rect_one.h<rect_two.y)==false/*Muy arriba*/&& (rect_one.y>rect_two.y+rect_two.h)==false)//Muy abajo)
                {

                    personajes->erase(i);
                    rect_balas.erase(rect_balas.begin()+j);
                    *ase=true;
                    return;
                }
                if(rect_balas[j].y>=480)
                {
                    rect_balas.erase(rect_balas.begin()+j);
                    break;
                }
            }
        frame++;

        rect_textura.x+=3;
        rect_textura.y+=3;

        if(rect_textura.y==480)
        {
            rect_textura.x=0;
            rect_textura.y=0;
        }
    }

    Enemigo3::~Enemigo3()
    {
        //dtor
    }
