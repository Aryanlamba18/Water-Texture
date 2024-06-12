#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>


int main(int args,char* argv[]){

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    window = SDL_CreateWindow("yes",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    // SDL_Surface *screensurface = SDL_GetWindowSurface(window);
    SDL_Surface *surface = IMG_Load("seamlesswater.jpg");
    // texture going vertically
    SDL_Texture *textureh= SDL_CreateTextureFromSurface(renderer,surface);
    // texture going horizontally
    SDL_Texture *texturev= SDL_CreateTextureFromSurface(renderer,surface);

    SDL_Rect rect1 = {0,0,640,480};
    SDL_Rect rect2 = {-639,0,640,480};
    SDL_Rect rect3 = {0,0,640,480};
    SDL_Rect rect4 = {0,-480,640,480};



    bool running = true;

    while(running){
        SDL_Event e;

        while(SDL_PollEvent(&e)){

            if (e.type==SDL_QUIT)
            {
                running = false;
            }

            if (e.type==SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button==SDL_BUTTON_LEFT)
                {
                    SDL_SetTextureBlendMode(texturev,SDL_BLENDMODE_BLEND);
                }

                else if (e.button.button==SDL_BUTTON_RIGHT)
                {
                    SDL_SetTextureBlendMode(texturev,SDL_BLENDMODE_MOD);
                }
                
                
            }
            
            
        }

        int w,h;
        SDL_QueryTexture(texturev,nullptr,nullptr,&w,&w);
        SDL_Delay(20);

        rect1.x++;
        if (rect1.x>639)
        {
            rect1.x=-639;
        }

        rect2.x++;
        if (rect2.x>639)
        {
            rect2.x=-639;
        }

        rect3.y++;
        if (rect3.y>479)
        {
            rect3.y=-480;
        }

        rect4.y++;
        if (rect4.y>479)
        {
            rect4.y=-480;
        }

        SDL_SetTextureBlendMode(textureh,SDL_BLENDMODE_NONE);
        SDL_RenderCopy(renderer,textureh,nullptr,&rect1);
        SDL_RenderCopy(renderer,textureh,nullptr,&rect2);
        SDL_RenderCopy(renderer,texturev,nullptr,&rect3);
        SDL_RenderCopy(renderer,texturev,nullptr,&rect4);

        SDL_RenderPresent(renderer);




        
        
    }
    
    }