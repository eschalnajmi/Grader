
int winGame( Game *game, char symbol, int gridsize, int winlen );

int drawGame( Game *game );

int diagwin(Game *game, char space, char symbol, int winlen, int dlen, int i, int j);
int rdiagwin(Game *game, char space, char symbol, int winlen, int dlen, int i, int j);
