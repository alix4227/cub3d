// ========== ÉTAPE 1: INITIALISATION DES DIRECTIONS ==========

// Position du joueur (coordonnées réelles, pas de grille)
double posX = player.x; 
double posY = player.y;  

// Direction de la caméra (vecteur directeur)
double dirX = player.dirX;
double dirY = player.dirY;

// Plan de la caméra (perpendiculaire à la direction, pour le FOV)
double planeX = player.planeX;
double planeY = player.planeY; 

// Pour chaque colonne x de l'écran (de 0 à screenWidth-1)
int x = ;

// Coordonnée x dans l'espace caméra (de -1 à +1)
double cameraX = 2 * x / (double)screenWidth - 1;

// Direction du rayon pour cette colonne
double rayDirX = dirX + planeX * cameraX;
double rayDirY = dirY + planeY * cameraX;

// ========== ÉTAPE 2: CALCUL DES DELTA DISTANCES ==========

// Distance que le rayon doit parcourir pour traverser 1 case entière
// Si rayDirX = 0, on met une valeur très grande (1e30)
double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

// // ========== ÉTAPE 3: CALCUL DES PREMIÈRES SIDE DISTANCES ET STEPS ==========

// int mapX = (int)posX;
// int mapY = (int)posY;

// double sideDistX, sideDistY;
// int stepX, stepY;

// if (rayDirX < 0) 
// {
//     stepX = -1;  
//     sideDistX = (posX - mapX) * deltaDistX;
// } else {
//     stepX = 1;
//     sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// }

// if (rayDirY < 0) {
//     stepY = -1;  // On va vers le haut
//     sideDistY = (posY - mapY) * deltaDistY;
// } 
// else 
// {
// 	stepY = 1;
//     sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// }

/* EXPLICATION sideDistX:
 * C'est la distance du point de départ jusqu'à la prochaine ligne verticale de la grille
 * Si on est à la position 22.3 et qu'on va vers la droite (stepX = 1),
 * la prochaine ligne verticale est à x = 23
 * Donc la distance fractionnaire est (23 - 22.3) = 0.7
 * Et sideDistX = 0.7 * deltaDistX
 */


void drawColumn(int x, int lineHeight, t_data *game) 
{
	int y;
	int drawStart;
	int drawEnd;
	
	drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	y = 0;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (drawEnd >= SCREEN_HEIGHT) 
		drawEnd = SCREEN_HEIGHT - 1;
    // Dessiner le PLAFOND (du haut jusqu'au mur)
	while (y < drawStart)
	{
		putPixel(x, y, game->color_c, game);
		y++;
	}
    // Dessiner le MUR
	y = drawStart;
	while (y < drawEnd) 
	{
		// Dessiner un pixel du mur à la position (x, y)
    // La couleur dépend du type de mur (worldMap[mapX][mapY])
    // et du côté touché (side) pour les ombres
		// int color = getWallColor(worldMap[mapX][mapY], side);
		putPixel(x, y, choose_color(game, y), game);
		y++;
	}
    // Dessiner le SOL (du mur jusqu'au bas)
	y = drawEnd;
	while (y < SCREEN_HEIGHT) 
	{
		putPixel(x, y, game->color_f, game);
		y++;
	}
}

void	get_position_and_distance(t_ray player, double rayDirX, double rayDirY)
{
	player.deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
	player.deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
	player.mapX = player.(int)posX;
	player.mapY = player.(int)posY;
	if (rayDirX < 0) 
	{
		player.stepX = -1;
		player.sideDistX = (player.posX - player.mapX) * player.deltaDistX;
	} 
	else
	{
		player.stepX = 1;
		player.sideDistX = (player.mapX + 1.0 - player.posX) * player.deltaDistX;
	}
	if (rayDirY < 0)
	{
		player.stepY = -1;
		player.sideDistY = (player.posY - player.mapY) * player.deltaDistY;
	} 
	else
	{
		player.stepY = 1;
		player.sideDistY = (player.mapY + 1.0 - player.posY) * player.deltaDistY;
	}
}

void	performDDA(double rayDirX, double rayDirY, t_ray player)
{
	int hit;
	int side;

	hit = 0;
	get_position_and_distance(player, rayDirX, rayDirY);
	while (hit == 0) 
	{
		if (player.sideDistX < player.sideDistY) 
		{
			player.sideDistX += player.deltaDistX;
			player.mapX += player.stepX;
			side = 0;
		}
		else
		{
			player.sideDistY += player.deltaDistY;
			player.mapY += player.stepY;
			side = 1;
		}
		if (game->pars[player.mapX][player.mapY] > 0)
			hit = 1;
	}
	if (side == 0) 
		player.perpWallDist = (player.mapX - player.posX + (1 - player.stepX) / 2) / rayDirX;
	else 
		player.perpWallDist = (player.mapY - player.posY + (1 - player.stepY) / 2) / rayDirY;

}

void renderFrame(t_data *game, t_ray player)
{
	int x;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int lineHeight;

	x = 0;
	while (x < SCREEN_WIDTH) 
	{
		cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		performDDA(rayDirX, rayDirY, t_ray player);
		lineHeight = (int)(SCREEN_HEIGHT / player.perpWallDist);
		drawColumn(x, lineHeight, game);
		x++;
	}
}