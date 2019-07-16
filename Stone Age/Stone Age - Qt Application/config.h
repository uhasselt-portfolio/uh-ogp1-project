#ifndef CONFIG_H
#define CONFIG_H

// 1 for 1080p, 2 for 4K
const int SCALE{1};

// Game.h
const int PLAYERS_IN_GAME{4};
const int TOTAL_SCORE{100};
const int TOTAL_PHASES{3};
const int TOTAL_ROUNDS{PLAYERS_IN_GAME};

// Seeder.h
const int INFINITE{-1};

// GameButtonView.h
const int PADDING{5*SCALE};

// PlaceView.h
const bool HIDE_BORDER{true};

// Worker.h
const int MAXIMUM_WORKERS_CAPACITY{10};

// PlayerBoardView.h
const int WOOD_RESOURCE{0};
const int BRICK_RESOURCE{1};
const int STONE_RESOURCE{2};
const int GOLD_RESOURCE{3};
const int AMOUNT_RESOURCE_TYPES{4};

const int CLAYPIT_RESOURCE_RETURN{4};
const int FOREST_RESOURCE_RETURN{3};
const int QUARRY_RESOURCE_RETURN{5};
const int RIVER_RESOURCE_RETURN{6};

const int CARD_AMOUNT_ON_BOARD{4};
const int BUILDING_CARDS_ON_STACK{7};
const int CIVILISATION_CARDS_TOTAL{21};



#endif // CONFIG_H
