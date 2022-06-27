
#include "header.h"

void	debug_print_map_info(t_map *map)
{
	printf("w: %i\nh: %i\no: %c\ne: %c\nf: %c\n", map->width, map->height, map->obs, map->emp, map->full);
}

void	debug_print_map(t_map *map)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%c", map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

#if 0
int	main(void)
{
	t_map *map;
	char *filename = "map.txt";

	map = parsing(filename);
	debug_print_map_info(map);
	debug_print_map(map);

	return (0);
}
#endif