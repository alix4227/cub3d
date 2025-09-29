void draw_strips(t_player *p, int x, double top_pxl)
{
	double	y;             // Décalage vertical par rapport au haut du mur
	int		next;          // Bord droit de la bande (strip) à dessiner
	double	tmp_top_pxl;   // Valeur initiale de top_pxl (pour recalculer après chaque pixel)

	y = 0;
	next = x + WALL_STRIP_L;   // On va dessiner une bande de largeur WALL_STRIP_L
	tmp_top_pxl = top_pxl;

	// On dessine colonne par colonne, de x jusqu’à next
	while (x < next)
	{
		y = 0;
		
		// Si le "haut" du mur est au-dessus de la fenêtre,
		// on avance y jusqu’à rentrer dans la zone visible (>= 0)
		while (top_pxl < 0)
		{
			top_pxl = tmp_top_pxl + y++;
		}

		// On dessine pixel par pixel jusqu’en bas de la fenêtre ou jusqu’à la fin du mur
		while (top_pxl < WIN_H)
		{
			// Dessine un pixel de la bande murale
			my_mlx_pixel_put(p->cub->image, x, top_pxl,
				choose_color(&p->r[x], y));

			// On passe au pixel suivant du mur (verticalement)
			y += 1;
			top_pxl = tmp_top_pxl + y;

			// Si on a dessiné toute la hauteur du mur, on arrête
			if (y > p->r[x].wall_height)
				break;
		}
		// On passe à la colonne suivante de la bande
		x++;
	}
}
