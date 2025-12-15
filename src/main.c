#define SDL_MAIN_USE_CALLBACKS 1 // Use the callbacks instead of main()
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>

// We will use this renderer to draw into this window every frame
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

// This function runs once at startup
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    const char *title = "Load PNG image (SDL3 / C)";
    if (!SDL_CreateWindowAndRenderer(title, 350, 350, 0, &window, &renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_SetRenderVSync(renderer, 1);

    // --- Print SDL versions ---
    printf("Compiled SDL3 version: %d.%d.%d\n",
        SDL_MAJOR_VERSION,
        SDL_MINOR_VERSION,
        SDL_MICRO_VERSION);
    // Get the version of the SDL library linked at runtime
    int v = SDL_GetVersion();
    printf("Linked SDL3 version:   %d.%d.%d\n", SDL_VERSIONNUM_MAJOR(v),
        SDL_VERSIONNUM_MINOR(v), SDL_VERSIONNUM_MICRO(v));

    // --- SDL3_image version ---
    v = IMG_Version();
    int major = SDL_VERSIONNUM_MAJOR(v);
    int minor = SDL_VERSIONNUM_MINOR(v);
    int micro = SDL_VERSIONNUM_MICRO(v);
    printf("SDL3_image version:    %d.%d.%d\n", major, minor, micro);

    const char *texturePath = "./assets/textures/crate.png";
    texture = IMG_LoadTexture(renderer, texturePath);
    if (!texture)
    {
        SDL_Log("Couldn't load %s: %s\n", texturePath, SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

// This function runs when a new event (mouse input, keypresses, etc) occurs
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS; // End the program, reporting success to the OS
    }
    return SDL_APP_CONTINUE;
}

// This function runs once per frame, and is the heart of the program
SDL_AppResult SDL_AppIterate(void *appstate)
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 245, 245, 220, 255); // Warm beige
    SDL_RenderClear(renderer);

    float w, h;
    SDL_GetTextureSize(texture, &w, &h);

    SDL_FRect dst = {
        50.0f,
        50.0f,
        w * 0.5f,
        h * 0.5f
    };

    SDL_RenderTexture(renderer, texture, NULL, &dst);

    // Update the screen
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

// This function runs once at shutdown
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }

    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }

    SDL_Quit();
}
