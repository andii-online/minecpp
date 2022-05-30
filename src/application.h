#ifndef APPLICATION_H
#define APPLICATION_H

#if defined(LINUX) || defined(MINGW) 
   #include <SDL2/SDL.h>
#else
   #include <SDL.h>
#endif

#include <glad/glad.h>

class Application {
   public:
      // Instantiates the application.
      Application();
      // Application destructor.
      ~Application();
      // Runs the main game loop.
      void loop();
   private:
      // Renders the screen
      void render();
      SDL_Window* m_window;
      SDL_GLContext m_openGLContext;
      GLint m_screenWidth = 720;
      GLint m_screenHeight = 480;
};

#endif // APPLICATION_H
