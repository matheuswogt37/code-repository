//* VIEW CONSTS
const unsigned VIEW_SIZE_X = 256;
const unsigned VIEW_SIZE_Y = 208;

//* MOVE CONSTS
const unsigned MAX_SPEED = 10.0f;

//* enums to state

enum STATES {
    S_IDLE,
    S_WALKING,
    S_JUMP,
    S_FALL,
    S_ATTACK,
    S_DAMAGE
};

typedef struct {
    bool mLeft, mRight, mDown, mJump;
} E_MOV;

// //* enum to handle movement player
// enum PLAYER_MOV {
//     P_LEFT,
//     P_RIGHT
// };