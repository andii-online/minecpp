#ifndef BLOCK_H
#define BLOCK_H

#include "../Core/Vector.h"

// Represent the different types of blocks in the game.
enum BlockType {
   GRASS,
   STONE,
};

class Block {
   public:
      Block();
      ~Block();
   private:
      Vec3 m_position;
      BlockType m_blockType;    
};

#endif // BLOCK_H
