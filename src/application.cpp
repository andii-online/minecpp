#include "Application.h"

#include "stdexcept"
#include "string"

#include "WorldGen/Block.h"

Application::Application() {
   // Initialize SDL
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      throw std::runtime_error(std::string("SDL2 Failed to Initialize: ") + SDL_GetError());
   } 

   // Use opengl 4.6
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
   SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
   // We want to request a double buffer for smooth updating.
   SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
   SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

   // Create the window
   m_window = SDL_CreateWindow("minecpp", 
      SDL_WINDOWPOS_CENTERED, 
      SDL_WINDOWPOS_CENTERED, 
      m_screenWidth, 
      m_screenHeight, 
      SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

   // If window failed to instantiate, error
   if(m_window == nullptr) {
      throw std::runtime_error(std::string("Window failed to initialize: ") + SDL_GetError());
   }

   // Create an OpenGL Graphics Context
   m_openGLContext = SDL_GL_CreateContext(m_window);
   if (m_openGLContext == nullptr) {
      throw std::runtime_error(std::string("OpenGL Context failed to initialize") + SDL_GetError());
   }

   // Initialize GLAD Library
   if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){
      throw std::runtime_error(std::string("glad failed to initialize") + SDL_GetError());
   }

   SDL_Log("Application::application - No SDL, GLAD, or OpenGL errors detected during instantiation\n");
}

Application::~Application() {
   //Destroy the window
   SDL_DestroyWindow(m_window);
   m_window = nullptr;
   // Quit the SDL subsytem
   SDL_Quit();
}

void Application::render() {
   glViewport(0,0, m_screenWidth, m_screenHeight);
   glClearColor(0,0,0,0); 
   glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Application::loop() {
   bool quit = false;
   SDL_Event e;

   Block block();

   while(!quit) {
      while(SDL_PollEvent(&e) != 0) {
         if (e.type == SDL_QUIT) {
            quit = true;
         }
      }

      render();

      SDL_GL_SwapWindow(m_window);
   }
}
