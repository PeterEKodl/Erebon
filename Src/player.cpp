#include "player.hpp"
#include "chunk_manager.hpp"
#include "chunk.hpp"
#include "game_data.hpp"

inline void correct_position(abs_pos& player_position, abs_pos& new_player_position){
    
    /* This function positions the player correctly e.g. if they are inside a block their position will be moved upwards or 
    if they're standing on air they will be moved downwards until they reach the ground.
    */

   // All blocks with an id greater than that of lava are solid and have different behaviour.
   if ( Blocks::get_ID( gameData.chunkManager.get_block_absolute(new_player_position)) > static_cast<blockID_t>(Blocks::ID::Lava) ){
       // The player will only climb if their height is 254 and below, limiting their height to 255
       if (player_position.y < Chunk::height-1){
           // The two blocks above the player must be free.
           if (Blocks::get_ID(gameData.chunkManager.get_block_absolute(abs_pos {player_position.x, player_position.y+1, player_position.z})) == static_cast<blockID_t>(Blocks::ID::Air) &&
              Blocks::get_ID(gameData.chunkManager.get_block_absolute(abs_pos {new_player_position.x, new_player_position.y+1, new_player_position.z})) == static_cast<blockID_t>(Blocks::ID::Air))
              {
                  ++new_player_position.y;
              } else {
                  new_player_position = player_position;
              }
       } else {
           new_player_position = player_position;
       }
       
   } else if ( Blocks::get_ID( gameData.chunkManager.get_block_absolute(abs_pos {new_player_position.x, new_player_position.y-1, new_player_position.z})) == static_cast<blockID_t>(Blocks::ID::Air) ){
       while (Blocks::get_ID( gameData.chunkManager.get_block_absolute(abs_pos {new_player_position.x, new_player_position.y-1, new_player_position.z})) == static_cast<blockID_t>(Blocks::ID::Air))
       {
           --new_player_position.y;
       }

   }

}

Player::Player(abs_pos position,
    int32_t health, int32_t stamina, int32_t saturation, int32_t max_health, int32_t max_stamina, int32_t max_saturation): 
    position{position}, health{health}, max_health{max_health}, stamina{stamina},
    max_stamina{max_stamina}, saturation{saturation}, max_saturation{max_saturation}, placement_level{0} {}

Player::Player(abs_pos position): Player::Player(position, 20, 20, 20, 20, 20, 20){}

void Player::move(Player::Direction direction){

    abs_pos new_position {position};
    switch (direction){

    case Direction::Up:
        --new_position.z;
        break;

    case Direction::Down:
        ++new_position.z;
        break;

    case Direction::Right:
        ++new_position.x;
        break;

    case Direction::Left:
        --new_position.x;
        break;

    }



    correct_position(position, new_position);
    
    if (transform::chunk_position(new_position) != transform::chunk_position(position)){
        gameData.chunkManager.load_in_range(chunk_key_t {transform::chunk_position(new_position), transform::region_position(new_position)});
    }
    position = new_position;

}

void Player::place_block(Direction direction){

    abs_pos new_block_position = position;
    switch (direction)
    {
    
    case Direction::Up:
        --new_block_position.z;
        break;

    case Direction::Down:
        ++new_block_position.z;
        break;

    case Direction::Right:
        ++new_block_position.x;
        break;

    case Direction::Left:
        --new_block_position.x;
        break;

    }

    new_block_position.y += placement_level;
    if (gameData.chunkManager.get_block_absolute(new_block_position) == static_cast<blockID_t>(Blocks::ID::Air)){
        gameData.chunkManager.set_block_absolute(new_block_position, Blocks::make_block(Blocks::ID::Wood, 0));
    }

}

void Player::place_top_bottom(){
    if (placement_level != 0){
        abs_pos new_block_position = position;

        new_block_position.y += placement_level;

        if (gameData.chunkManager.get_block_absolute(new_block_position) == static_cast<blockID_t>(Blocks::ID::Air)){
            gameData.chunkManager.set_block_absolute(new_block_position, Blocks::make_block(Blocks::ID::Wood, 0));
        }
    }
}

void Player::change_placement_level(){
    ++placement_level;
    if (placement_level == 2) placement_level = -1;
    
}

void Player::remove_block(Direction direction){
    abs_pos new_block_position = position;
    switch (direction)
    {
    
    case Direction::Up:
        --new_block_position.z;
        break;

    case Direction::Down:
        ++new_block_position.z;
        break;

    case Direction::Right:
        ++new_block_position.x;
        break;

    case Direction::Left:
        --new_block_position.x;
        break;

    }

    new_block_position.y += placement_level;
}

void Player::remove_top_bottom(){

}
