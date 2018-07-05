#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <stdbool.h>
#include "PointSet.cpp"

// Screen dimensions
const int WIDTH = 700;
const int HEIGHT = 500;
 

void renderPointSet(PointSet ps,SDL_Renderer* renderer){
  vector<Point> points = *(ps.getPoints());
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  for (int i = 0; i < points.size(); i++){    
    int x = points.at(i).getX();
    int y = points.at(i).getY();
    // cout << i << endl;
    // cout << "X: " << x << endl;
    // cout << "Y: " << y << endl;
    if (filledCircleRGBA( renderer, x, y, 3, 0, 0, 255, 255 ) != 0) {
      printf( "A circle was not rendered! SDL_Error: %s\n", SDL_GetError() );
    }
  }
}


int main( int argc, char* args[] )
{
  // The window we'll be rendering to
  SDL_Window* window = NULL;
  
  // The window renderer
  SDL_Renderer* renderer = NULL;
  
  // Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  }
  else {
    // Create window
    // SDL_WINDOW_OPENGL flag for a window usable with OPENGL
    window = SDL_CreateWindow( "Convex Hull", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL );

    // Create the renderer for the window
    // (-1) the index of the rendering driver to initialize -1 corresponds to initialize
    // the first one supporting the request flags
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if( window == NULL ) {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else if( renderer == NULL ) {
      printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else {
      bool running = true;
      SDL_Event event;
      while (running) {
	while(SDL_PollEvent(&event)){
	  if (event.type == SDL_QUIT) {
	    running = false;
	    break;
	  }
	}
	
	// Prints the white background and the blue points
	//	PointSet genPos(5, WIDTH, HEIGHT);
	PointSet genPos(1);
	
	renderPointSet(genPos, renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay( 1000 );	  
	cout << "First Delay: Points + white\n";

	// Gets the min point and turns it red
	Point m = genPos.getMin();
	
	if (filledCircleRGBA( renderer, m.getX(), m.getY(), 3, 255, 0, 0, 255 ) != 0) {
	  printf( "A circle was not rendered! SDL_Error: %s\n", SDL_GetError() );
	}
	SDL_RenderPresent(renderer);
	SDL_Delay( 1000 );	  
	cout << "Second Delay: Min Point to Red\n";
	
	// Get a copy of the PointSet
	vector<Point> setcopy(*(genPos.getPoints()));
	vector<Point>* a = genPos.getConvexHull(&setcopy);

        Point init = genPos.getMin();
	int x1 = init.getX();
	int y1 = init.getY();
	
	cout << "GGGG" << "\n\n";
	for(int i = 0; i < (*a).size(); i++){
	  cout << "GGGG2" << "\n\n";
	  int x2 = (*a).at(i).getX();
	  int y2 = (*a).at(i).getY();
	  cout << "GGGG3" << "\n\n";
	  if (lineRGBA( renderer, x1, y1, x2, y2, 0,0,0, 255 ) != 0) {
	    printf( "A line was not rendered! SDL_Error: %s\n", SDL_GetError() );
	  }
	  SDL_RenderPresent(renderer);
	  SDL_Delay( 500 );
	  cout << i << " -esima Espera: Raya negra\n";	  
	}
	
	// if (filledCircleRGBA( renderer, 500, 400, 3, 255, 0, 0, 255 ) != 0) {
	//   printf( "A circle was not rendered! SDL_Error: %s\n", SDL_GetError() );
	  
	// }
	
	// Show what was drawn
	SDL_RenderPresent(renderer);
	
	// Wait two seconds
	SDL_Delay( 7000 );
      }
    }
  }
  
  //Destroy window
  SDL_DestroyRenderer( renderer );
  SDL_DestroyWindow( window );

  
  //Quit SDL subsystems
  SDL_Quit();
  
  return 0;
}
