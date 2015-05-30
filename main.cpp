
    #include<SDL2/SDL.h>
    #include<SDL2/SDL_image.h>
    #include<iostream>
    #include<list>
    #include "Jugador.h"
    #include "Enemigo.h"
    #include "Enemigo1.h"
    #include "Enemigo2.h"
    #include "Enemigo3.h"

    #include <SDL2/SDL_mixer.h>

    using namespace std;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event Event;
    SDL_Texture *background;
    SDL_Rect rect_background;
    Mix_Music *gMusic = NULL;





    void juego()
    {
        //Init textures
        int w=0,h=0;
        background = IMG_LoadTexture(renderer,"fondo.png");
        SDL_QueryTexture(background, NULL, NULL, &w, &h);
        rect_background.x = 0;
        rect_background.y = 0;
        rect_background.w = w;
        rect_background.h = h;

        float enemigo_y = 0;

                    //Initialize SDL_mixer
                    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                    {
                        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                        bool success = false;
                    }
                    //Load music
                    gMusic = Mix_LoadMUS( "musica.mp3" );
                    if( gMusic == NULL )
                    {
                        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
                        bool success = false;
                    }

        //Main Loop
        float personaje_x = 100;
        float personaje_y = 100;
        list<SDL_Rect*>balas;

        unsigned int frame_anterior = SDL_GetTicks();

        list<Personaje*>personajes;
    //    personajes.push_back(new Enemigo(renderer,&personajes));
          personajes.push_back(new Jugador(renderer,&personajes));
          personajes.push_back(new Enemigo1(renderer,&personajes));
          personajes.push_back(new Enemigo2(renderer,&personajes));
          personajes.push_back(new Enemigo3(renderer,&personajes));


        int frame=0;

        while(true)
        {
            while(SDL_PollEvent(&Event))
            {
                if(Event.type == SDL_QUIT)
                {
                    return;
                }
                if(Event.type == SDL_KEYDOWN)
                {
                    if(Event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        return;
                    }
                                                                            }
            }

            if( Mix_PlayingMusic() == 0 )
               {
                    //Play the music
                    Mix_PlayMusic( gMusic, -1 );
                }




            if(frame%150==0)
            {
                personajes.push_back(new Enemigo1(renderer,&personajes));
                personajes.push_back(new Enemigo2(renderer,&personajes));

            }
            if(frame%200==0)
            {
                personajes.push_back(new Enemigo1(renderer,&personajes));
                personajes.push_back(new Enemigo2(renderer,&personajes));
                personajes.push_back(new Enemigo3(renderer,&personajes));

            }
            if(frame%250==0)
            {
                personajes.push_back(new Enemigo1(renderer,&personajes));
                personajes.push_back(new Enemigo2(renderer,&personajes));
                personajes.push_back(new Enemigo3(renderer,&personajes));

            }


            bool death=false;
            for(list<Personaje*>::iterator i=personajes.begin();
                i!=personajes.end();
                i++)
                {
                    (*i)->logica(&death);
                    if(death)
                    break;
                }

            SDL_RenderCopy(renderer, background, NULL, &rect_background);

            for(list<Personaje*>::iterator i=personajes.begin();
                i!=personajes.end();
                i++)
                (*i)->dibujar();

            if((SDL_GetTicks()-frame_anterior)<17)
                SDL_Delay(17-(SDL_GetTicks()-frame_anterior));
            frame_anterior=SDL_GetTicks();

            SDL_RenderPresent(renderer);
            frame++;
        }
    }

    void menu()
    {
        int w,h;
        SDL_Texture* background_menu = IMG_LoadTexture(renderer,"pause.png");
        SDL_QueryTexture(background_menu, NULL, NULL, &w, &h);
        rect_background.x = 0;
        rect_background.y = 0;
        rect_background.w = w;
        rect_background.h = h;

        while(true)
        {
            while(SDL_PollEvent(&Event))
            {
                if(Event.type == SDL_QUIT)
                {
                    return;
                }
                if(Event.type == SDL_KEYDOWN)
                {
                    if(Event.key.keysym.sym == SDLK_RETURN)
                    {
                        juego();
                    }
                }
            }
            SDL_RenderCopy(renderer, background_menu, NULL, &rect_background);
            SDL_RenderPresent(renderer);
        }
    }

 int main( int argc, char* args[] )
    {
        //Init SDL
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            return 10;
        }
        //Creates a SDL Window
        if((window = SDL_CreateWindow("Image Loading", 100, 100, 640/*WIDTH*/, 480/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
        {
            return 20;
        }
        //SDL Renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
        if (renderer == NULL)
        {
            std::cout << SDL_GetError() << std::endl;
            return 30;
        }

        menu();

        return 0;
    }



