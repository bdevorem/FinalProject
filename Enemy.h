// This is a tentative sketch for the abstract enemy class.

class Enemy  {

  public:
    Enemy(); // non-default constructor used because all enemies will be initialized from the same spot on the screen
    bool touchTop(); // will return a true value when the player hits the top of the enemy
    bool touchSide(); // wil return a true value when any object or the player touches the enemy on either side
    virtual void moveEnemy() = 0;  // will describe the motion of each of the enemies in derived classes
    virtual int DeadState() = 0;  // will be used to determine if the enemy is dead and should leave the screen or is in another state
  
  private:
    int xpos;  // private data members for storing the location of the enemy
    int ypos;
    
}
