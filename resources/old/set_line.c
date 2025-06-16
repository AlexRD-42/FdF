static inline
void	set_vline(t_img *img, uint32_t index, uint32_t argb)
{
	size_t	i;

	i = 0;
	while (i < HEIGHT)
		((uint32_t (*)[img->width])img->data)[i++][index] = argb;
}

static inline
void	set_hline(t_img *img, uint32_t index, uint32_t argb)
{
	size_t	i;

	i = 0;
	while (i < WIDTH)
		((uint32_t (*)[img->width])img->data)[index][i++] = argb;
}

// Linspace
void	draw_grid(t_img *img)
{

	size_t	i;

	i = 0;
	while (i < WIDTH)
	{
		set_vline(img, i, 0x00FFFFFF);
		i += 8;
	}
	i = 0;
	while (i < HEIGHT)
	{
		set_hline(img, i, 0x00FFFFFF);
		i += 8;
	}
}